let a;
a = "lala";
let b = 456;
const dd = (a, b) => {
    return true;
};
function truc() {
}
function is_pair(nb, callback) {
    return (nb % 2 === 0);
}
const param = (a, b) => {
    if (typeof a !== "number")
        a = parseInt(a, 10);
    return a;
};
is_pair(3, function (reste) {
    console.log(reste);
});
class Demo {
    constructor() {
        this.el_public = 2;
    }
    methode_private() {
    }
    static split() {
        console.log("spif");
    }
    set el(value) {
        this.lala = value;
    }
}
class test_interface {
    constructor(option) {
        this.options = option;
    }
}
// les name spaces
var grafik;
(function (grafik) {
    class nameSpace_demo {
        constructor(option) {
            this.lala = option;
        }
    }
    grafik.nameSpace_demo = nameSpace_demo;
})(grafik || (grafik = {}));
let d = new grafik.nameSpace_demo("lala");
export default class demo_module {
    constructor(option) {
        this.lala = option;
    }
}
//# sourceMappingURL=test.js.map