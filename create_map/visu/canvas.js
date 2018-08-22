"use strict"

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

  while (tab_data[i].split("-").length === 2 && tab_data[i][0] !== "L") {
    data.tab_connection.push(tab_data[i])
    i++
  }

  i++;
  while (i < tab_data.length) {
    data.result.push(tab_data[i])
    i++
  }
  if (data.result.length)
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

      /*------------------------------------*\
          manage file
      \*------------------------------------*/
      get_data(this.result)
      draw_map()
      draw_path(data.path)
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
    fill: "yellow"
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
    width: 25,
    height: 25,
    stroke: "green",
    fill: "white",
    strokeWidth: 2,
    lockMovementX: true,
    lockMovementY: true,
    hasControls: false
  })
  canvas.add(rect)
  rect.TYPE = true
  // le name de la room
  name = parseInt(tab[0])
  rect.my = parseInt(name)

  var text = new fabric.Text(name, {
    left: x + 5, top: y, selectable: false, fontSize: 20
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
    stroke: "red",
    strokeWidth: 0.9,
    selectable: false
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
    stroke: color,
    strokeWidth: 4,
    selectable: false
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


const color = [{color: "blue", marge: 10}, {color: "green", marge: 10},
  {color: "orange", marge: 10}, {color: "purple", marge: 10}]

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
        left: room_1.getCenterPoint().x - 15,
        top: room_1.getCenterPoint().y - 16,
        width: 25,
        height: 25,
        stroke: color[index].color,
        fill: "transparent",
        strokeWidth: 5,
        lockMovementX: true,
        lockMovementY: true,
        hasControls: false
      })
      CANVAS.add(rect)

      draw_line_visu_color(CANVAS, color[index].color, color[index].marge)
      room_1 = room_2
      ii++
    }


  })
}

window.onload = function () {

  const trace_training = () => {

    get_data()
    draw_map()
    draw_path(data.path)
  }


  let canvas = new fabric.StaticCanvas("mon_canvas", {preserveObjectStacking: true})

  CANVAS = canvas
  set_input()
  // trace_training()
  let i = 0;

  $("#btn_start").click(() => {
    mouve_f(i++)
  })


  // generate_tab(50, 120, true, 0.5, 8)

  // setTimeout(draw_map(), 500)

}

