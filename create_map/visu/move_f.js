
const test_fu = (searched, name_f) => {
  let super_room

  let all_el = CANVAS.getObjects()

  super_room = all_el.find((searched_room) => {
    return searched_room.my === parseInt(searched)
  })

  var tri = new fabric.Triangle({
    left: super_room.getCenterPoint().x - 15,
    top: super_room.getCenterPoint().y,
    width: 30,
    height: 25,
    stroke: "#FF0080",
    fill: "#FF0080",
    strokeWidth: 5,
    lockMovementX: true,
    lockMovementY: true,
    hasControls: false
  })
  CANVAS.add(tri)
  foufou.push(tri)

  var text = new fabric.Text(name_f, {
    left: super_room.getCenterPoint().x - 7,
    top: super_room.getCenterPoint().y + 10,
    selectable: false,
    fontSize: 20
  })
  CANVAS.add(text)
  foufou.push(text)
}

let foufou = [];
const mouve_f = (tour) => {

  foufou.map((el) => {
      CANVAS.remove(el)
  })

  let tab_split = data.result[tour]

    let tab_f = tab_split.split(' ')
    tab_f.pop()
    console.log(tab_f)


      tab_f.map((el_split) => {

        el_split = el_split.split("-")

        let F = el_split[1]
        let R = el_split[0].substr(1)
        test_fu(F, R)
      })


}

