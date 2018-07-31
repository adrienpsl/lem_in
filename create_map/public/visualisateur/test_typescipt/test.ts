let a: string

a = "lala"
let b = 456

const dd = (a: number, b: string): boolean => {
  return true
}

function truc(): void {

}


function is_pair(nb: number, callback: (number: number) => void): boolean {
  return (nb % 2 === 0);
}

const param = (a: number | string, b?: string): number => {
  if (typeof a !== "number")
    a = parseInt(<string> a, 10)
  return (<number>a);
};

is_pair(3, function (reste) {
    console.log(reste)
  }
)

class Demo {

  public el_public: number
  public el_privat: number
  public el_protec: number
  private lala: string

  constructor() {
    this.el_public = 2
  }

  private methode_private() {

  }

  static split() {
    console.log("spif")
  }

  set el(value: string) {
    this.lala = value
  }
}

// une interface est un objet type que j'attend
interface first_interface {
  n: number,
  b: string,
  c: (a: number) => void
}

class test_interface {
  private options: first_interface

  constructor(option: first_interface) {
    this.options = option
  }
}

// les name spaces
namespace grafik {
  export class nameSpace_demo {
    private lala:string

    constructor(option: string)
    {
      this.lala  = option
    }
  }}

let d = new grafik.nameSpace_demo("lala")

export default class demo_module {
  private lala:string
  constructor(option: string)
  {
    this.lala  = option
  }
}

