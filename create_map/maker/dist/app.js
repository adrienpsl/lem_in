(function(FuseBox){FuseBox.$fuse$=FuseBox;
FuseBox.target = "browser";
FuseBox.pkg("default", {}, function(___scope___){
___scope___.file("index.js", function(exports, require, module, __filename, __dirname){

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

});
return ___scope___.entry = "index.js";
});

FuseBox.import("default/index.js");
FuseBox.main("default/index.js");
})
(function(e){function r(e){var r=e.charCodeAt(0),n=e.charCodeAt(1);if((m||58!==n)&&(r>=97&&r<=122||64===r)){if(64===r){var t=e.split("/"),i=t.splice(2,t.length).join("/");return[t[0]+"/"+t[1],i||void 0]}var o=e.indexOf("/");if(o===-1)return[e];var a=e.substring(0,o),f=e.substring(o+1);return[a,f]}}function n(e){return e.substring(0,e.lastIndexOf("/"))||"./"}function t(){for(var e=[],r=0;r<arguments.length;r++)e[r]=arguments[r];for(var n=[],t=0,i=arguments.length;t<i;t++)n=n.concat(arguments[t].split("/"));for(var o=[],t=0,i=n.length;t<i;t++){var a=n[t];a&&"."!==a&&(".."===a?o.pop():o.push(a))}return""===n[0]&&o.unshift(""),o.join("/")||(o.length?"/":".")}function i(e){var r=e.match(/\.(\w{1,})$/);return r&&r[1]?e:e+".js"}function o(e){if(m){var r,n=document,t=n.getElementsByTagName("head")[0];/\.css$/.test(e)?(r=n.createElement("link"),r.rel="stylesheet",r.type="text/css",r.href=e):(r=n.createElement("script"),r.type="text/javascript",r.src=e,r.async=!0),t.insertBefore(r,t.firstChild)}}function a(e,r){for(var n in e)e.hasOwnProperty(n)&&r(n,e[n])}function f(e){return{server:require(e)}}function u(e,n){var o=n.path||"./",a=n.pkg||"default",u=r(e);if(u&&(o="./",a=u[0],n.v&&n.v[a]&&(a=a+"@"+n.v[a]),e=u[1]),e)if(126===e.charCodeAt(0))e=e.slice(2,e.length),o="./";else if(!m&&(47===e.charCodeAt(0)||58===e.charCodeAt(1)))return f(e);var s=x[a];if(!s){if(m&&"electron"!==_.target)throw"Package not found "+a;return f(a+(e?"/"+e:""))}e=e?e:"./"+s.s.entry;var l,d=t(o,e),c=i(d),p=s.f[c];return!p&&c.indexOf("*")>-1&&(l=c),p||l||(c=t(d,"/","index.js"),p=s.f[c],p||"."!==d||(c=s.s&&s.s.entry||"index.js",p=s.f[c]),p||(c=d+".js",p=s.f[c]),p||(p=s.f[d+".jsx"]),p||(c=d+"/index.jsx",p=s.f[c])),{file:p,wildcard:l,pkgName:a,versions:s.v,filePath:d,validPath:c}}function s(e,r,n){if(void 0===n&&(n={}),!m)return r(/\.(js|json)$/.test(e)?h.require(e):"");if(n&&n.ajaxed===e)return console.error(e,"does not provide a module");var i=new XMLHttpRequest;i.onreadystatechange=function(){if(4==i.readyState)if(200==i.status){var n=i.getResponseHeader("Content-Type"),o=i.responseText;/json/.test(n)?o="module.exports = "+o:/javascript/.test(n)||(o="module.exports = "+JSON.stringify(o));var a=t("./",e);_.dynamic(a,o),r(_.import(e,{ajaxed:e}))}else console.error(e,"not found on request"),r(void 0)},i.open("GET",e,!0),i.send()}function l(e,r){var n=y[e];if(n)for(var t in n){var i=n[t].apply(null,r);if(i===!1)return!1}}function d(e){if(null!==e&&["function","object","array"].indexOf(typeof e)!==-1&&!e.hasOwnProperty("default"))return Object.isFrozen(e)?void(e.default=e):void Object.defineProperty(e,"default",{value:e,writable:!0,enumerable:!1})}function c(e,r){if(void 0===r&&(r={}),58===e.charCodeAt(4)||58===e.charCodeAt(5))return o(e);var t=u(e,r);if(t.server)return t.server;var i=t.file;if(t.wildcard){var a=new RegExp(t.wildcard.replace(/\*/g,"@").replace(/[.?*+^$[\]\\(){}|-]/g,"\\$&").replace(/@@/g,".*").replace(/@/g,"[a-z0-9$_-]+"),"i"),f=x[t.pkgName];if(f){var p={};for(var v in f.f)a.test(v)&&(p[v]=c(t.pkgName+"/"+v));return p}}if(!i){var g="function"==typeof r,y=l("async",[e,r]);if(y===!1)return;return s(e,function(e){return g?r(e):null},r)}var w=t.pkgName;if(i.locals&&i.locals.module)return i.locals.module.exports;var b=i.locals={},j=n(t.validPath);b.exports={},b.module={exports:b.exports},b.require=function(e,r){var n=c(e,{pkg:w,path:j,v:t.versions});return _.sdep&&d(n),n},m||!h.require.main?b.require.main={filename:"./",paths:[]}:b.require.main=h.require.main;var k=[b.module.exports,b.require,b.module,t.validPath,j,w];return l("before-import",k),i.fn.apply(k[0],k),l("after-import",k),b.module.exports}if(e.FuseBox)return e.FuseBox;var p="undefined"!=typeof ServiceWorkerGlobalScope,v="undefined"!=typeof WorkerGlobalScope,m="undefined"!=typeof window&&"undefined"!=typeof window.navigator||v||p,h=m?v||p?{}:window:global;m&&(h.global=v||p?{}:window),e=m&&"undefined"==typeof __fbx__dnm__?e:module.exports;var g=m?v||p?{}:window.__fsbx__=window.__fsbx__||{}:h.$fsbx=h.$fsbx||{};m||(h.require=require);var x=g.p=g.p||{},y=g.e=g.e||{},_=function(){function r(){}return r.global=function(e,r){return void 0===r?h[e]:void(h[e]=r)},r.import=function(e,r){return c(e,r)},r.on=function(e,r){y[e]=y[e]||[],y[e].push(r)},r.exists=function(e){try{var r=u(e,{});return void 0!==r.file}catch(e){return!1}},r.remove=function(e){var r=u(e,{}),n=x[r.pkgName];n&&n.f[r.validPath]&&delete n.f[r.validPath]},r.main=function(e){return this.mainFile=e,r.import(e,{})},r.expose=function(r){var n=function(n){var t=r[n].alias,i=c(r[n].pkg);"*"===t?a(i,function(r,n){return e[r]=n}):"object"==typeof t?a(t,function(r,n){return e[n]=i[r]}):e[t]=i};for(var t in r)n(t)},r.dynamic=function(r,n,t){this.pkg(t&&t.pkg||"default",{},function(t){t.file(r,function(r,t,i,o,a){var f=new Function("__fbx__dnm__","exports","require","module","__filename","__dirname","__root__",n);f(!0,r,t,i,o,a,e)})})},r.flush=function(e){var r=x.default;for(var n in r.f)e&&!e(n)||delete r.f[n].locals},r.pkg=function(e,r,n){if(x[e])return n(x[e].s);var t=x[e]={};return t.f={},t.v=r,t.s={file:function(e,r){return t.f[e]={fn:r}}},n(t.s)},r.addPlugin=function(e){this.plugins.push(e)},r.packages=x,r.isBrowser=m,r.isServer=!m,r.plugins=[],r}();return m||(h.FuseBox=_),e.FuseBox=_}(this))