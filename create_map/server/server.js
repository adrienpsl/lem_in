"use strict"


// all config
const config = require("./config/config")

// all require
const path = require("path")
const express = require("express")


let app = express()



const publicPath = path.join(__dirname, "..", "public");
app.use(express.static(publicPath));

app.get("*", (req, res) => {
	res.sendFile(path.join(publicPath, 'index.html'))
});

app.listen(process.env.PORT);
// app.listen(process.env.PORT|| 3000)
