"use strict"

let test_str = "15\n" +
  "1 14 14\n" +
  "2 414 14\n" +
  "3 814 14\n" +
  "4 1214 14\n" +
  "5 1614 14\n" +
  "6 14 414\n" +
  "7 414 414\n" +
  "8 814 414\n" +
  "9 1214 414\n" +
  "10 1614 414\n" +
  "##end\n" +
  "11 14 814\n" +
  "12 414 814\n" +
  "13 814 814\n" +
  "##start\n" +
  "14 1614 814\n" +
  "15 14 1214\n" +
  "16 414 1214\n" +
  "17 814 1214\n" +
  "18 1214 1214\n" +
  "19 1614 1214\n" +
  "9-4\n" +
  "15-3\n" +
  "13-10\n" +
  "14-3\n" +
  "12-1\n" +
  "9-3\n" +
  "16-9\n" +
  "16-10\n" +
  "16-8\n" +
  "19-16\n" +
  "7-2\n" +
  "5-2\n" +
  "15-13\n" +
  "8-7\n" +
  "14-2\n" +
  "18-11\n" +
  "7-1\n" +
  "13-8\n" +
  "15-2\n" +
  "4-3\n" +
  "18-3\n" +
  "10-4\n" +
  "11-8\n" +
  "6-4\n" +
  "12-3\n" +
  "7-3\n" +
  "16-15\n" +
  "14-6\n" +
  "18-15\n" +
  "19-10\n" +
  "15-9\n" +
  "17-15\n" +
  "9-5\n" +
  "9-7\n" +
  "13-1\n" +
  "18-10\n" +
  "19-8\n" +
  "10-2\n" +
  "12-10\n" +
  "19-2\n" +
  "12-11\n" +
  "17-1\n" +
  "13-9\n" +
  "17-13\n" +
  "18-5\n" +
  "14-11\n" +
  "13-6\n" +
  "F1-11 F2-3 F3-2 F4-6 \n" +
  "F2-12 F3-5 F4-13 F5-11 F6-3 F7-2 F8-6 \n" +
  "F2-11 F6-12 F3-18 F7-5 F4-8 F8-13 F9-11 F10-3 F11-2 F12-6 \n" +
  "F6-11 F10-12 F3-11 F7-18 F11-5 F4-11 F8-8 F12-13 F13-11 \n" +
  "F10-11 F7-11 F11-18 F8-11 F12-8 F14-11 \n" +
  "F11-11 F12-11 F15-11"

var name = 0
var tab_place = 0
/*------------------------------------*\
    jquery
\*------------------------------------*/
// les variable globale :
var liaison = false
var start = false
var end = false
var tab_link = []

var room_1
var room_2
var CANVAS


let data = {}

/*------------------------------------*\
    get les datas
\*------------------------------------*/
const get_data = (new_data = test_str) => {
  let count_start = 0
  let count_end = 0

  data.tab_room = []
  data.tab_connection = []
  data.result = []
  data.path = []

  let tab_data = new_data.split("\n")
  let i = 1
  data.nb_f = parseInt(tab_data[0])

  while (tab_data[i].split(" ").length === 3 || tab_data[i][0] === "#") {
	let room
	room = tab_data[i]
	if (tab_data[i] === "##start") {
	  count_start = 1
	  i++
	  continue
	}
	if (tab_data[i] === "##end") {
	  count_end = 1
	  i++
	  continue
	}
	if (count_start) {
	  room = room + " s"
	  count_start = false
	  data.start = parseInt(room.split(" ")[0])
	}
	if (count_end) {
	  room = room + " e"
	  count_end = false
	  data.end = parseInt(room.split(" ")[0])

	}
	data.tab_room.push(room)
	++i
  }

  while (tab_data[i].split("-").length === 2 && tab_data[i][0] !== "F") {
	data.tab_connection.push(tab_data[i])
	i++
  }

  while (i < tab_data.length)
  {
	data.result.push(tab_data[i])
	i++
  }
  data.path = find_path(data.result, data.start, data.end)
  console.log(data)
}

/*------------------------------------*\
    read le file
\*------------------------------------*/
const set_input = () => {
  document.getElementById("file").onchange = function () {
	var file = this.files[0]
	var reader = new FileReader()
	reader.onload = function () {
	  // Entire file
	  get_data(this.result)
	  draw_map()

	}
	reader.readAsText(file)
  }

}

/*------------------------------------*\
    UX
\*------------------------------------*/
const manage_UX = () => {
  // validate
  $("#validate").click((e) => {
	print_all_that_shit()
  })

  // print_room_visu
  $("#btn__room").click(() => {
	if (liaison === true)
	  $("#btn_liaison").trigger("click")

	print_room = !print_room
	print_room ? $("#btn__room").text("faire des rooms") : $("#btn__room").text("pas faire des rooms")
	print_room ? $("#btn__room").css("background", "green") : $("#btn__room").css("background", "grey")
  })

  // liaison
  $("#btn_liaison").click((e) => {
	if (print_room === true)
	  $("#btn__room").trigger("click")
	liaison = !liaison
	liaison ? $("#btn_liaison").text("faire des liaison") : $("#btn_liaison").text("pas faire des liaison")
	liaison ? $("#btn_liaison").css("background", "red") : $("#btn_liaison").css("background", "grey")

  })

  // start
  $("#btn_start").click((e) => {
	if (print_room === true)
	  $("#btn__room").trigger("click")
	if (liaison === true)
	  $("#btn_liaison").trigger("click")

	if (start != -1)
	  start = true
	$("#btn_start").text("start done")
  })

  // end
  $("#btn_end").click((e) => {
	if (print_room === true)
	  $("#btn__room").trigger("click")
	if (liaison === true)
	  $("#btn_liaison").trigger("click")

	if (end != -1)
	  end = true
	$("#btn_end").text("end done")
  })
}

const make_start = (rect) => {
  start = -1
  rect.start = true
  rect.set({
	fill: "red"
  })
}

const make_end = (rect) => {
  end = -1
  rect.end = true
  rect.set({
	fill: "blue"
  })
}

const print_room_visu = (element, canvas) => {
  let tab = element.split(" ")

  let x = parseInt(tab[1])
  let y = parseInt(tab[2])

  var rect = new fabric.Rect({
	left         : x,
	top          : y,
	width        : 25,
	height       : 25,
	stroke       : "green",
	fill         : "white",
	strokeWidth  : 2,
	lockMovementX: true,
	lockMovementY: true,
	hasControls  : false
  })
  canvas.add(rect)
  rect.TYPE = true
  // le name de la room
  name = parseInt(tab[0])
  rect.my = parseInt(name)

  var text = new fabric.Text(name, {
	left: x, top: y, selectable: false, fontSize: 20
  })
  if (tab.length == 4) {
	if (tab[3] == "s")
	  make_start(rect)
	if (tab[3] == "e")
	  make_end(rect)
  }
  canvas.add(text)
  return (rect)
}

/*------------------------------------*\
    trace les connections
\*------------------------------------*/
const draw_line_visu = (canvas) => {
  let LINE = new fabric.Line([
	room_1.getCenterPoint().x,
	room_1.getCenterPoint().y,
	room_2.getCenterPoint().x,
	room_2.getCenterPoint().y
  ], {
	stroke     : "red",
	strokeWidth: 0.9,
	selectable : false
  })
  canvas.add(LINE)
  return (LINE)
}


const draw_line_visu_color = (canvas, color, marge) => {
  let LINE = new fabric.Line([
	room_1.getCenterPoint().x + marge,
	room_1.getCenterPoint().y + marge,
	room_2.getCenterPoint().x + marge,
	room_2.getCenterPoint().y + marge
  ], {
	stroke     : color,
	strokeWidth: 4,
	selectable : false
  })
  canvas.add(LINE)
  return (LINE)
}

const draw_map = () => {
  data.tab_room.map((element) => {
	print_room_visu(element, CANVAS)
  })

  data.tab_connection.map((element) => {
	let tab_line = element.split("-")
	let all_el = CANVAS.getObjects()

	room_1 = all_el.find((el) => {
	  return el.my === parseInt(tab_line[0])
	})

	room_2 = all_el.find((el) => {
	  return el.my === parseInt(tab_line[1])
	})
	draw_line_visu(CANVAS)
  })
}


const color = [{color: "blue", marge: 5}, {color: "green", marge: -5},
  {color: "orange", marge: 10}, {color: "purple", marge: -10}]

const draw_path = (fourmis) => {
  let all_el = CANVAS.getObjects()
  let ii

  fourmis.map((FOURNIS, index) => {
	let path = FOURNIS.path
	ii = 1
	room_1 = all_el.find((room_el) => {
	  return room_el.my === parseInt(path[0])
	})

	while (ii < path.length) {
	  room_2 = all_el.find((room_el) => {
		return room_el.my === parseInt(path[ii])
	  })


	  var rect = new fabric.Rect({
	  left         : room_1.getCenterPoint().x - 15 ,
	  top          : room_1.getCenterPoint().y - 15,
	  width        : 25 +5,
	  height       : 25 +5,
	  stroke       : color[index].color,
	  fill         : "transparent",
	  strokeWidth  : 10,
	  lockMovementX: true,
	  lockMovementY: true,
	  hasControls  : false
	  })
	  CANVAS.add(rect)


	  // var text = new fabric.Text(name, {
		// left      : room_1.getCenterPoint().x - 15,
		// top       : room_1.getCenterPoint().x - 15,
		// selectable: false,
		// fontSize  : 20,
		// color     : color[index].color
	  // })
	  // CANVAS.add(text)


	  // var text = new fabric.Text(name, {
	  // left: x, top: y, selectable: false, fontSize: 20
	  // })

	  console.log(room_1, room_2)
	  draw_line_visu_color(CANVAS, color[index].color, color[index].marge)
	  room_1 = room_2
	  ii++
	}


  })
}


window.onload = function () {

  let canvas = new fabric.StaticCanvas("mon_canvas", {preserveObjectStacking: true})

  set_input()
  CANVAS = canvas

  get_data()
  draw_map()
  console.log(data.path)
  draw_path(data.path)
  // find_path(14, 11)
  // generate_tab(20, 400, true, 3)

  // setTimeout(draw_map(), 500)

}

