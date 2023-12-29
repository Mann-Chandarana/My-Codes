let band:string[] = []

let myObj0

///// Rest parameters 

const total = (...nums:number[]):number=>{
    return nums.reduce((prev,curr)=> prev+curr)
}