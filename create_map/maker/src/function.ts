export const generate_file = (CANVAS) => {

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

    var blob = new Blob([`${parseInt($("#nb_f").val()) }\n`, ...new_tab, ...tab_link], {type: "text/plain;charset=utf-8"})
    saveAs(blob, "map")
}

export const manage_UX = () => {
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