"use strict"

let find_path = (start, end) => {
  let data = "F1-11 F2-3 F3-2 F4-6 \n" +
	"F2-12 F3-5 F4-13 F5-11 F6-3 F7-2 F8-6 \n" +
	"F2-11 F6-12 F3-18 F7-5 F4-8 F8-13 F9-11 F10-3 F11-2 F12-6 \n" +
	"F6-11 F10-12 F3-11 F7-18 F11-5 F4-11 F8-8 F12-13 F13-11 \n" +
	"F10-11 F7-11 F11-18 F8-11 F12-8 F14-11 \n" +
	"F11-11 F12-11 F15-11"


  data = data.split("\n")
  let tmp
  let tab_split = []
  let nb_f_running
  let fourmis = []

  data.map((el) => {
	tmp = el.split(" ")
	tmp.pop()
	tab_split.push(tmp)
  })

  function Fourmi(name)
  {
	this.name = name
	this.path = [parseInt(start)]
  }

  Fourmi.prototype.add_path = function (path) {
	this.path.push(parseInt(path))
	// console.log(this.path[path.length -1], end)
  }

  tab_split[0].map((el) => {
	fourmis.push(new Fourmi(el.split("-")[0]))
  })

  tab_split.map((tab_split_el) => {
	tab_split_el.map((el) => {

	  let split = el.split("-")
	  fourmis.map((f) => {
		if (f.name === split[0])
		{
		  f.add_path(split[1])
		}
	  })
	})
  })
	fourmis.map((el) => {
	    console.log(el.path) 
	})
  // console.log(tab_split)
  // console.log(fourmis)
}