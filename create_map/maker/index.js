let name = 0
let tab_place = 0
/*------------------------------------*\
    jquery
\*------------------------------------*/
// les letiable globale :


let tab_link = []

let room_1 = false
let room_2 = false
let CANVAS


const generate_file = () => {

  let new_tab = []
  let nb_fourmis = $("#nb_f").val()
  let new_el

  CANVAS.getObjects().filter((el) => {
    if (el.TYPE) {
      new_el = `${el.my} ${Math.round(el.getCenterPoint().x)} ${Math.round(el.getCenterPoint().y)}\n`
      if (el.start)
        new_el = `##start \n${new_el}`
      if (el.end)
        new_el = `##end \n${new_el}`
      new_tab.push(new_el)
    }
  })

  let blob = new Blob([`${parseInt($("#nb_f").val()) }\n`, ...new_tab, ...tab_link], {type: "text/plain;charset=utf-8"})
  saveAs(blob, "map")
}

/*------------------------------------*\
    Ux and glob letiable
\*------------------------------------*/
let print_room = false
let liaison = false
const manage_UX = () => {
  // validate
  $("#validate").click((e) => {
    generate_file()
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


/*------------------------------------*\
    make start and end
\*------------------------------------*/
let start = false
let end = false
const make_start = (rect) => {
  start = false
  rect.start = true
  rect.set({
    fill: "red"
  })
}

const make_end = (rect) => {
  end = false
  rect.end = true
  rect.set({
    fill: "blue"
  })
}

/*------------------------------------*\
    biuld and draw room
\*------------------------------------*/
const room = (x, y) => {
  // build le rectangle
  let rect = new fabric.Rect({
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

  // add name, listner pour connection et start // end
  rect.my = name
  rect.TYPE = true
  rect.on("selected", function () {
    if (start === true)
      make_start(rect)
    if (end === true)
      make_end(rect)
    if (liaison) {
      make_connection(rect, CANVAS)
    }
  })

  // l'ajout a mon CANVAS
  CANVAS.add(rect)

  // set et ajoute le text
  let text = new fabric.Text(`${name}`, {
    left: x, top: y, selectable: false
  })
  CANVAS.add(text)
  name++;
}

/*------------------------------------*\
    biuld and draw ine
\*------------------------------------*/
const line = () => {
  // build line
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
  CANVAS.add(LINE)

  // verifie que pas deja faite avant de l'ajoute au tab
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
}

/*------------------------------------*\
    build and drow connection
\*------------------------------------*/
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

window.onload = function () {
  // jquery
  manage_UX()

  let canvas = new fabric.Canvas("mon_canvas")
  canvas.on("mouse:down", function (event) {
    if (print_room === true) {
      room(event.e.clientX - 35, event.e.clientY - 50, canvas)
    }
  })

  CANVAS = canvas
  // room(500, 500, canvas)
  // room(250, 500, canvas)

}