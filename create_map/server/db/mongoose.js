"use strict";

let mongoose = require("mongoose");

// without this mongo don't do promise
mongoose.Promise = global.Promise;
mongoose.connect(process.env.MONGODB_MINE)

module.exports = {
	mongoose
}