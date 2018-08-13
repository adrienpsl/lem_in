const generate_all_rec = (nb_room, distance, size_line, tab, fullitute = 2) => {
  // magane rec
  let rec
  let name_room = 1
  let x = 0
  let y = 0

  // je set start et end
  start = Math.floor(Math.random() * (nb_room - 1))
  end = Math.floor(Math.random() * (nb_room - 1))
  if (start === end)
	start = Math.floor(Math.random() * (nb_room - 1))

  for (let i = 0; i < nb_room; ++i)
  {

	if (Math.floor(Math.random() * (10)) >= fullitute)
	{
	  rec = print_room_visu(`${name_room} ${x} ${y}`, CANVAS)
	  if (i >= start)
	  {
		make_start(rec)
		start = nb_room + 1
	  }
	  if (i >= end)
	  {
		make_end(rec)
		end = nb_room + 1
	  }
	  tab.push(rec)
	  name_room++
	}

	x += distance
	if (x >= size_line)
	{
	  y += distance
	  x = 0
	}
  }
}


const generate_all_rec_hard = (nb_room, distance, size_line, tab) => {
  // magane rec
  let rec
  let name_room = 1
  let x = 0
  let y = 0

  // je set start et end
  start = Math.floor(Math.random() * (nb_room - 1))
  end = Math.floor(Math.random() * (nb_room - 1))
  if (start === end)
	start = Math.floor(Math.random() * (nb_room - 1))

  for (let i = 0; i < nb_room; ++i)
  {

	rec = print_room_visu(`${name_room} ${x} ${y}`, CANVAS)
	if (i >= start)
	{
	  make_start(rec)
	  start = nb_room + 1
	}
	if (i >= end)
	{
	  make_end(rec)
	  end = nb_room + 1
	}
	tab.push(rec)
	name_room++

	x += distance
	if (x >= size_line)
	{
	  y += distance
	  x = 0
	}
  }
}


const generate_tab = (nb_room    = 100,
					  distance   = 200,
					  mode_rec   = false,
					  connection = 1,
					  hard       = 2
) =>
{
  let size_line = 5000
  // je set la taille des lignes

  if (mode_rec)
	size_line = Math.sqrt(nb_room) * distance
  if (size_line > 5000)
	size_line = 5000


  let tab = []


  let tab_connec = []
  let conenction_print = []

  if (hard === 0)
  {
	generate_all_rec_hard(7968, 50, 4800, tab)

	let size_ligne_hard = 96
	for (let i = 0; i < 82; ++i)
	{
	  for (let y = 0; y < size_ligne_hard - 1; ++y)
	  {
		room_1 = tab[y + i * size_ligne_hard]
		room_2 = tab[y + 1 + i * size_ligne_hard]
		tab_connec.push(draw_line_visu(CANVAS))

		if (room_1.my > room_2.my)
		  conenction_print.push(`${room_1.my}-${room_2.my}\n`)
		else
		  conenction_print.push(`${room_2.my}-${room_1.my}\n`)

		room_2 = tab[y + (i + 1) * size_ligne_hard]
		tab_connec.push(draw_line_visu(CANVAS))

		if (room_1.my > room_2.my)
		  conenction_print.push(`${room_1.my}-${room_2.my}\n`)
		else
		  conenction_print.push(`${room_2.my}-${room_1.my}\n`)
	  }
	}
  }


  else {
	generate_all_rec(nb_room, distance, size_line, tab, hard)
	let max = tab.length
	nb_room *= connection
	for (let i = 0; i < nb_room; ++i)
	{
	  room_1 = tab[Math.floor(Math.random() * max)]
	  room_2 = tab[Math.floor(Math.random() * max)]
	  if (room_1 === room_2)
		continue
	  let tab_check = conenction_print.filter((el) => {
		let split = el.split("-")
		if (split.length > 1)
		  if (
			(parseInt(split[0]) === room_1.my || parseInt(split[0]) === room_2.my)
			&&
			(parseInt(split[1]) === room_1.my || parseInt(split[1]) === room_2.my)
		  )
			return (true)
	  })
	  if (tab_check.length === 0)
	  {
		tab_connec.push(draw_line_visu(CANVAS))
		if (room_1.my > room_2.my)
		  conenction_print.push(`${room_1.my}-${room_2.my}\n`)
		else
		  conenction_print.push(`${room_2.my}-${room_1.my}\n`)
	  }
	}
  }
  console.log(conenction_print)
  generate_file(conenction_print)

}


let col_path3 = () =>
{
  room_1 = room_2 = false
  CANVAS.getObjects().filter((el) => {
	if (el.my === 17)
	  room_1 = el
	if (el.my == 231)
	  room_2 = el
  })
  if (room_1 && room_2)
	console.log(draw_line_visu_blue(CANVAS))
}


const generate_file = (conenction_print) => {

  let new_tab = []
  let nb_fourmis = $("#nb_f").val()
  let new_el
  CANVAS.getObjects().filter((el) => {
	if (el.TYPE) {
	  if (el.start)
		new_el = `##start\n${el.my}`
	  else if (el.end)
		new_el = `##end\n${el.my}`
	  else
		new_el = `${el.my}`
	  new_el = `${new_el} ${Math.round(el.getCenterPoint().x)} ${Math.round(el.getCenterPoint().y)}\n`

	  new_tab.push(new_el)
	}
  })
  console.log(new_tab)
  let blob = new Blob([`10\n`, ...new_tab, ...conenction_print], {type: "text/plain;charset=ascii"})
  saveAs(blob, "map")
}

