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
var tab_lianson = []

var room_1 = false
var room_2 = false


// function qui set les button
const jq = () =>
{

  // room
  $("#btn__room").click((e) =>
  {
	print_room = !print_room

	print_room ? $("#btn__room").text("faire des rooms") : $("#btn__room").text("pas faire des rooms")
  })

  // liaison
  $("#btn_liaison").click((e) =>
  {
	liaison = !liaison
	liaison ? $("#btn_liaison").text("faire des liaison") : $("#btn_liaison").text("pas faire des liaison")
  })

  // start
  $("#btn_start").click((e) =>
  {
	start = !start
	start ? $("#btn_start").text("faire start") : $("#btn_start").text("pas faire start")
  })

  // end
  $("#btn_end").click((e) =>
  {
	end = !end
	end ? $("#btn_end").text("faire end") : $("#btn_end").text("pas faire end")
  })
}

const fill_room = (nb, canvas) =>
{
  if (liaison)
  {
	if (room_1 === false)
	{
	  room_1 = Number(nb)
	  console.log(room_1)
	  // console.log(canvas.item(room_1).getCenterPoint())
	}
	else if (nb != room_1)
	{
	  room_2 = Number(nb)
	  line(canvas)
	  room_1 = false
	  room_2 = false
	  console.log(tab_lianson)
	}
  }
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
  rect.link = parseInt(tab_place)
  rect.TYPE = true
  rect.on("selected", function ()
  {

	if (print_room) {
	  fill_room(rect.link, canvas)
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
  console.log(room_1, room_2)
  console.log(canvas.item(room_1).getCenterPoint().x,
	canvas.item(room_1).getCenterPoint().y,
	canvas.item(room_2).getCenterPoint().x,
	canvas.item(room_2).getCenterPoint().y,
	room_1, room_2)
  let LINE = new fabric.Line([
	canvas.item(room_1).getCenterPoint().x,
	canvas.item(room_1).getCenterPoint().y,
	canvas.item(room_2).getCenterPoint().x,
	canvas.item(room_2).getCenterPoint().y
  ], {
	stroke     : "red",
	strokeWidth: 0.9,
	selectable : false
  })
  canvas.add(LINE)
  tab_lianson.push(`${room_1}-${room_2}`)

  console.log(canvas.getObjects().filter((el) =>
  {
	if (el.TYPE)
	{
	  return el
	}
  }))
}
window.onload = function ()
{
  // jquery
  jq()

  let canvas = new fabric.Canvas("mon_canvas")
  canvas.on("mouse:down", function (event)
  {
	if (print_room === true)
	{
	  room(event.e.clientX - 35, event.e.clientY - 50, canvas)
	}
  })

  room(500, 500, canvas)
  room(250, 500, canvas)


  //C'est ici que l'on placera tout le code servant à nos dessins.
}