"use strict"

var name = 0
var tab_place = 0
/*------------------------------------*\
    jquery
\*------------------------------------*/
// les variable globale :
var print_room = false
var liaison = false
var start = false
var end = false
var tab_link = []

var room_1 = false
var room_2 = false
var CANVAS


const teste = (tab) => {
  let test_tab = tab.split("\n");
  console.log(test_tab)
  console.log("dfa")
}

const set_input = () => {
  document.getElementById('file').onchange = function(){
	var file = this.files[0];
	var reader = new FileReader();
	reader.onload = function(){
	  // Entire file
	  teste(this.result);
	};
	reader.readAsText(file);
  };

}

// function qui set les button
const jq = () =>
{
  // validate
  $("#validate").click((e) =>
  {
	print_all_that_shit()
  })

  // room
  $("#btn__room").click(() =>
  {
	if (liaison === true)
	  $("#btn_liaison").trigger("click")

	print_room = !print_room
	print_room ? $("#btn__room").text("faire des rooms") : $("#btn__room").text("pas faire des rooms")
	print_room ? $("#btn__room").css("background", "green") : $("#btn__room").css("background", "grey")
  })

  // liaison
  $("#btn_liaison").click((e) =>
  {
	if (print_room === true)
	  $("#btn__room").trigger("click")
	liaison = !liaison
	liaison ? $("#btn_liaison").text("faire des liaison") : $("#btn_liaison").text("pas faire des liaison")
	liaison ? $("#btn_liaison").css("background", "red") : $("#btn_liaison").css("background", "grey")

  })

  // start
  $("#btn_start").click((e) =>
  {
	if (print_room === true)
	  $("#btn__room").trigger("click")
	if (liaison === true)
	  $("#btn_liaison").trigger("click")

	if (start != -1)
	  start = true
	$("#btn_start").text("start done")
  })

  // end
  $("#btn_end").click((e) =>
  {
	if (print_room === true)
	  $("#btn__room").trigger("click")
	if (liaison === true)
	  $("#btn_liaison").trigger("click")

	if (end != -1)
	  end = true
	$("#btn_end").text("end done")
  })
}

const make_connection = (rect, canvas) =>
{
  if (liaison)
  {
	if (room_1 === false)
	{
	  room_1 = rect
	}
	else if (rect != room_1)
	{
	  room_2 = rect
	  line(canvas)
	  room_1 = false
	  room_2 = false
	}
  }
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

const room = (x, y, canvas) =>
{
  var rect = new fabric.Rect({
	left         : x,
	top          : y,
	width        : 50,
	height       : 50,
	stroke       : "green",
	fill         : "white",
	strokeWidth  : 5,
	lockMovementX: true,
	lockMovementY: true,
	hasControls  : false
  })
  rect.my = parseInt(name)
  rect.TYPE = true
  rect.on("selected", function ()
  {
	if (start === true)
	  make_start(rect)
	if (end === true)
	  make_end(rect)
	if (liaison) {
	  make_connection(rect, canvas)
	}
  })
  canvas.add(rect)

  var text = new fabric.Text(name, {
	left: x, top: y, selectable: false
  })
  canvas.add(text)
  name = parseInt(name) + 1
  tab_place = parseInt(tab_place) + 2
}

const line = (canvas) =>
{
  // console.log(room_1, room_2)
  // console.log(canvas.item(room_1).getCenterPoint().x,
  // canvas.item(room_1).getCenterPoint().y,
  // canvas.item(room_2).getCenterPoint().x,
  // canvas.item(room_2).getCenterPoint().y,
  // room_1, room_2)
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
  let tab_check = tab_link.filter((el) => {
	let split = el.substring(0, el.length - 1).split("-")
	if (
	  (parseInt(split[0]) === room_1.my || parseInt(split[0]) === room_2.my)
	  &&
	  (parseInt(split[1]) === room_1.my || parseInt(split[1]) === room_2.my)
	)
	return (true)
  })
  if (tab_check.length === 0)
	tab_link.push(`${room_1.my}-${room_2.my}\n`)
  console.log(tab_check)
  console.log(tab_link)
}

window.onload = function ()
{
  // jquery
  // jq()
  set_input()

  let canvas = new fabric.Canvas("mon_canvas")
  canvas.on("mouse:down", function (event)
  {
	if (print_room === true)
	{
	  room(event.e.clientX - 35, event.e.clientY - 50, canvas)
	}
  })

  CANVAS = canvas
  room(500, 500, canvas)
  room(250, 500, canvas)

}