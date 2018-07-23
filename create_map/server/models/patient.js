"use strict";

const mongoose = require("mongoose");

var PatientShema = new mongoose.Schema({
	patient: "String"
});

let Patient = mongoose.model("Patient_2", PatientShema);

module.exports = {Patient};