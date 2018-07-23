"use strict";

// pour savoir en quel mode de dev je suis en ce moment
let env = process.env.NODE_ENV || 'development';
console.log("env ******", env);

//je stock tout dams un JSON config que je ne vais jamais envoyer sur git
// pour etre sur que je ne vais jamais laisser mes configs sur le wb car c'est dangereux


if (env === 'development' || env === 'test') {
	// je parce direct mon fichier config dans un obj
	const config = require("./config.json");
	// permet de set up en fonction de env
	const envConfig = config[env];
	// Ojects.key return each key of my json object
	Object.keys(envConfig).forEach((key) => {
	    process.env[key] = envConfig[key] 
	})
}

// // set up the good database and other option
// if (env === "development") {
// 	process.env.PORT = 3000;
// 	process.env.MONGODB_URI = 'mongodb://localhost:27017/todos-dev'
// }
// else if (env === "test") {
// 	process.env.PORT = 3001;
// 	process.env.MONGODB_URI = 'mongodb://localhost:27017/todos-test'
// }