import demo_module from "./test"
import * as $ from 'jquery';
import * as scrollTo from "scroll-to"
import * as _ from "lodash";


let dada = new demo_module("llala");

_.padStart("Hello TypeScript!", 20, " ");


scrollTo(500, 0, {
  ease: 'out-bounce',
  duration: 1500
});

$(".demo").click(function (eventObject) {

})