"use strict";

let {User} = require("../models/user");

let authenticate = (req, res, next) => {

	// let token = req.header("x-auth") || req.cookies["x-auth"];

	let token = req.body.token
	console.log(token);
	User.findByToken(token)
		.then((user) => {
			if (!user)
			//va direct stop et aller au catch
			// c'est une methode static :)
				return Promise.reject();
			// je a request user pour l'utiliser dans mes autres routes
			req.user = user;
			req.token = token;
			next();
		})
		.catch((e) => {
			// le 401 c'est pour les err d'authentification
			res.status(401).send()
		});
};

module.exports = {authenticate};