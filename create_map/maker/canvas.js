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

const make_connection = (rect, canvas) => {
  if (liaison) {
    if (room_1 === false) {
      room_1 = rect
    }
    else if (rect != room_1) {
      room_2 = rect
      line(canvas)
      room_1 = false
      room_2 = false
    }
  }
}


const line = (canvas) => {
  let LINE = new fabric.Line([
    room_1.getCenterPoint().x,
    room_1.getCenterPoint().y,
    room_2.getCenterPoint().x,
    room_2.getCenterPoint().y
  ], {
    stroke: "red",
    strokeWidth: 0.9,
    selectable: false
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

window.onload = function () {
  // jquery
  jq()

  let canvas = new fabric.Canvas("mon_canvas")
  canvas.on("mouse:down", function (event) {
    if (print_room === true) {
      room(event.e.clientX - 35, event.e.clientY - 50, canvas)
    }
  })

  CANVAS = canvas
  room(500, 500, canvas)
  room(250, 500, canvas)

}