"use strict"

let test_str = "550\n" +
  "0 528 528\n" +
  "1 278 528\n" +
  "2 185 179\n" +
  "3 544 182\n" +
  "4 704 392\n" +
  "5 953 242\n" +
  "##end \n" +
  "6 1106 645\n" +
  "7 673 773\n" +
  "8 287 795\n" +
  "9 86 571\n" +
  "10 371 400\n" +
  "##start \n" +
  "11 424 183\n" +
  "2-10\n" +
  "11-10\n" +
  "11-2\n" +
  "1-2\n" +
  "9-1\n" +
  "9-8\n" +
  "7-8\n" +
  "7-0\n" +
  "6-0\n" +
  "6-5\n" +
  "6-4\n" +
  "6-3\n" +
  "0-3\n" +
  "0-4\n" +
  "5-4\n" +
  "5-3\n" +
  "11-3\n" +
  "11-8\n" +
  "0-8\n" +
  "0-2\n" +
  "10-5\n" +
  "4-7\n"

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
  let tab_data = new_data.split("\n")
  let i = 1
  data.nb_f = parseInt(tab_data[0])

  while (tab_data[i].split(" ").length === 3 || tab_data[i][0] === "#") {
    let room
    room = tab_data[i]
    if (tab_data[i] === "##start ") {
      count_start = 1
      i++
      continue
    }
    if (tab_data[i] === "##end ") {
      count_end = 1
      i++
      continue
    }
    if (count_start) {
      room = room + " s"
      count_start = false
    }
    if (count_end) {
      room = room + " e"
      count_end = false
    }
    data.tab_room.push(room)
    ++i
  }

  while (tab_data[i].split("-").length === 2 && tab_data[i][0] !== "F") {
    data.tab_connection.push(tab_data[i])
    i++
  }

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
    left: x,
    top: y,
    width: 50,
    height: 50,
    stroke: "green",
    fill: "white",
    strokeWidth: 5,
    lockMovementX: true,
    lockMovementY: true,
    hasControls: false
  })
  canvas.add(rect)

  // le name de la room
  name = parseInt(tab[0])
  rect.my = parseInt(name)

  var text = new fabric.Text(name, {
    left: x, top: y, selectable: false
  })
  if (tab.length == 4) {
    if (tab[3] == 's')
      make_start(rect)
    if (tab[3] == 'e')
      make_end(rect);
  }
  canvas.add(text)
}

/*------------------------------------*\
    trace les connections
\*------------------------------------*/
const draw_line_visu = (canvas) => {
  console.log(room_1, room_2)
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
    stroke: "red",
    strokeWidth: 0.9,
    selectable: false
  })
  canvas.add(LINE)

}

const make_connection = (rect, canvas) => {
  if (liaison) {
    if (room_1 === false) {
      room_1 = rect
    }
    else if (rect != room_1) {
      room_2 = rect
      draw_line_visu(canvas)
      room_1 = false
      room_2 = false
    }
  }
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
    // console.log(room_1, room_2)
    console.log(tab_line[0], tab_line[1])
    draw_line_visu(CANVAS)
  })
}

window.onload = function () {

  let canvas = new fabric.StaticCanvas("mon_canvas")

  set_input()
  // get_data()

  CANVAS = canvas
  // setTimeout(draw_map(), 500)

}