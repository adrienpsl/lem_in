"use strict"

let find_path = (data, start, end) => {

  console.log(data)
  let tmp
  let tab_split = []
  let nb_f_running
  let fourmis = []

  data.map((el) => {
    tmp = el.split(" ")
    tmp.pop()
    tab_split.push(tmp)
  })

  function Fourmi(name) {
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
        if (f.name === split[0]) {
          f.add_path(split[1])
        }
      })
    })
  })
  // console.log(tab_split)
  // console.log(fourmis)
  return fourmis;
}