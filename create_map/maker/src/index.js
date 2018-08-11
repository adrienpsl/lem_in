var name = 0;
var tab_place = 0;
/*------------------------------------*\
    jquery
\*------------------------------------*/
// les letiable globale :
var tab_link = [];
var room_1 = false;
var room_2 = false;
var CANVAS;
var generate_file = function () {
    var new_tab = [];
    var nb_fourmis = $("#nb_f").val();
    var new_el;
    CANVAS.getObjects().filter(function (el) {
        if (el.TYPE) {
            new_el = el.my + " " + Math.round(el.getCenterPoint().x) + " " + Math.round(el.getCenterPoint().y) + "\n";
            if (el.start)
                new_el = "##start \n" + new_el;
            if (el.end)
                new_el = "##end \n" + new_el;
            new_tab.push(new_el);
        }
    });
    var blob = new Blob([parseInt($("#nb_f").val()) + "\n"].concat(new_tab, tab_link), { type: "text/plain;charset=utf-8" });
    saveAs(blob, "map");
};
/*------------------------------------*\
    Ux and glob letiable
\*------------------------------------*/
var print_room = false;
var liaison = false;
var manage_UX = function () {
    // validate
    $("#validate").click(function (e) {
        generate_file();
    });
    // print_room_visu
    $("#btn__room").click(function () {
        if (liaison === true)
            $("#btn_liaison").trigger("click");
        print_room = !print_room;
        print_room ? $("#btn__room").text("faire des rooms") : $("#btn__room").text("pas faire des rooms");
        print_room ? $("#btn__room").css("background", "green") : $("#btn__room").css("background", "grey");
    });
    // liaison
    $("#btn_liaison").click(function (e) {
        if (print_room === true)
            $("#btn__room").trigger("click");
        liaison = !liaison;
        liaison ? $("#btn_liaison").text("faire des liaison") : $("#btn_liaison").text("pas faire des liaison");
        liaison ? $("#btn_liaison").css("background", "red") : $("#btn_liaison").css("background", "grey");
    });
    // start
    $("#btn_start").click(function (e) {
        if (print_room === true)
            $("#btn__room").trigger("click");
        if (liaison === true)
            $("#btn_liaison").trigger("click");
        if (start != -1)
            start = true;
        $("#btn_start").text("start done");
    });
    // end
    $("#btn_end").click(function (e) {
        if (print_room === true)
            $("#btn__room").trigger("click");
        if (liaison === true)
            $("#btn_liaison").trigger("click");
        if (end != -1)
            end = true;
        $("#btn_end").text("end done");
    });
};
/*------------------------------------*\
    make start and end
\*------------------------------------*/
var start = false;
var end = false;
var make_start = function (rect) {
    start = false;
    rect.start = true;
    rect.set({
        fill: "red"
    });
};
var make_end = function (rect) {
    end = false;
    rect.end = true;
    rect.set({
        fill: "blue"
    });
};
/*------------------------------------*\
    biuld and draw room
\*------------------------------------*/
var room = function (x, y) {
    // build le rectangle
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
    });
    // add name, listner pour connection et start // end
    rect.my = name;
    rect.TYPE = true;
    rect.on("selected", function () {
        if (start === true)
            make_start(rect);
        if (end === true)
            make_end(rect);
        if (liaison) {
            make_connection(rect, CANVAS);
        }
    });
    // l'ajout a mon CANVAS
    CANVAS.add(rect);
    // set et ajoute le text
    var text = new fabric.Text("" + name, {
        left: x, top: y, selectable: false
    });
    CANVAS.add(text);
    name++;
};
/*------------------------------------*\
    biuld and draw ine
\*------------------------------------*/
var line = function () {
    // build line
    var LINE = new fabric.Line([
        room_1.getCenterPoint().x,
        room_1.getCenterPoint().y,
        room_2.getCenterPoint().x,
        room_2.getCenterPoint().y
    ], {
        stroke: "red",
        strokeWidth: 0.9,
        selectable: false
    });
    CANVAS.add(LINE);
    // verifie que pas deja faite avant de l'ajoute au tab
    var tab_check = tab_link.filter(function (el) {
        var split = el.substring(0, el.length - 1).split("-");
        if ((parseInt(split[0]) === room_1.my || parseInt(split[0]) === room_2.my)
            &&
                (parseInt(split[1]) === room_1.my || parseInt(split[1]) === room_2.my))
            return (true);
    });
    if (tab_check.length === 0)
        tab_link.push(room_1.my + "-" + room_2.my + "\n");
};
/*------------------------------------*\
    build and drow connection
\*------------------------------------*/
var make_connection = function (rect, canvas) {
    if (liaison) {
        if (room_1 === false) {
            room_1 = rect;
        }
        else if (rect != room_1) {
            room_2 = rect;
            line(canvas);
            room_1 = false;
            room_2 = false;
        }
    }
};
window.onload = function () {
    // jquery
    manage_UX();
    var canvas = new fabric.Canvas("mon_canvas");
    canvas.on("mouse:down", function (event) {
        if (print_room === true) {
            room(event.e.clientX - 35, event.e.clientY - 50, canvas);
        }
    });
    CANVAS = canvas;
    room(500, 500, canvas);
    room(250, 500, canvas);
};
