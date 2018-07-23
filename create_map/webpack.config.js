"use strict";

const path = require("path");
const ExtractTextPlugin = require("extract-text-webpack-plugin");
module.exports = (env) => {
	const isProdution = env === "production";
	const cssExtract = new ExtractTextPlugin("style.css");

	return ({
		entry: "./src/app.js",
		// entry: "./src/playground/redux.js",
		output: {
			path: path.join(__dirname, "/public", "dist"),
			filename: "bundle.js"
		},
		module: {
			rules: [{
				loader: "babel-loader",
				test: /\.js$/,
				exclude: /node_modules/
			}, {
				test: [/\.sass$/,
					/\.css$/
				],
				use: cssExtract.extract({
					use: [
						{
							loader: 'css-loader',
							options: {
								sourceMap: true
							}
						},
						{
							loader: "sass-loader",
							options: {
								sourceMap: true
							}
						}
					]
				})
			}]
		},
		plugins: [
			cssExtract
		],
		devtool: isProdution ? "source-map" : "inline-source-map",
		devServer: {
			contentBase: path.join(__dirname, "/public"),
			historyApiFallback: true,
			publicPath: '/dist/'
		}
	});
};