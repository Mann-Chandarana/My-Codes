/* By using arrow function we can use lexical this mean this from the pareent function*/

const sayHello = name => {
    console.log("greeting" + " " + name)
    console.log("hi")
}

const x = {
    name: "Harry",
    role: "Js Developer",
    exp: 30,
    show: function () {
        // let that = this
        // console.log(this)
        setTimeout(() => {
            console.log(`The name is ${this.name}\nThe role is ${this.role}`)
        }, 2000)
    }
}
sayHello("Harry", "Good Afternoon")
  // console.log(x.name, x.exp)
  // x.show()

// const y = {
//     name: "Harry",
//     role: "Js Developer",
//     exp: 30,
//     show: function () {
//         function hello() {
//             console.log(`${this.name} is ${this.role}`)
//         }
//         hello()
//     }
// }

// y.show()

