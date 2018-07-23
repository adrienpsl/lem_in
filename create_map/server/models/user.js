"use strict";

let mongoose = require("mongoose");
let validator = require("validator");
let jwt = require('jsonwebtoken');
let _ = require("lodash");
const bcrypt = require("bcryptjs");

let UserShema = new mongoose.Schema({
	email: {
		type: "String",
		required: true,
		minLength: 4,
		trim: true,
		unique: true,
		validate: {
			validator: validator.isEmail,
			message: "{VALUE} is not a valid email"
		}
	}, password: {
		type: String,
		required: true,
		minLength: 6
	}, tokens: [{
		access: {
			type: String,
			required: true
		},
		token: {
			type: String,
			required: true
		}
	}]
}, {usePushEach: true});

UserShema.methods.toJSON = function () {
	let user = this;
	let obj_user = user.toObject();

	return _.pick(obj_user, ['_id', "email"]);
};

UserShema.methods.generateAutoToken = function () {
	let user = this;
	let access = "auth";
	let token = jwt.sign({
		_id: user._id.toHexString(),
		access
	}, process.env.JWT_SECRET).toString();
	let ob = {token, access};

	user.tokens.push({token, access});

	return user.save().then((r) => {
		return token;
	});
};

UserShema.methods.removeToken = function (token) {
	return this.update({
		$pull: {
			tokens: {
				token
			}
		}
	});
};

UserShema.statics.findByToken = function (token) {
	let decoded;

	try {
		decoded = jwt.verify(token, process.env.JWT_SECRET);
	}
	catch (e) {
		return Promise.reject();
	}

	return User.findOne({
		_id: decoded._id,
		"tokens.token": token,
		"tokens.access": "auth"
	});

};

UserShema.pre("save", function (next) {
	let user = this;

	if (user.isModified("password")) {
		bcrypt.genSalt(10, (err, salt) => {
			bcrypt.hash(user.password, salt, (e, hash) => {
				user.password = hash;
				console.log(hash);
				console.log(user.password);
				next();
			});
		});
	}
	else
		next();
});

UserShema.statics.findByCredentials = function (email, password) {

	return this.findOne({email})
		.then((user) => {
			console.log(user);
			if (!user)
				return Promise.reject();
			return new Promise((resolve, reject) => {
				bcrypt.compare(password, user.password)
					.then((res) => {
						if (res)
							return resolve(user);
						else
							return (reject());
					})
					.catch((e) => {
						return reject();
					});

			});
		});
};

let User = mongoose.model("Users", UserShema);

module.exports = {
	User
};