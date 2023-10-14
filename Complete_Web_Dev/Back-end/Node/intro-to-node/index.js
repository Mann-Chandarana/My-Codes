////////////////////////// Lecture-01 /////////////////////////
//jshint esversion:6

// console.log("Hello,world!");
// const fs = require("fs");    // for including module

// fs.copyFileSync("file1.txt","file2.txt");

////////////////////////// Lecture-02 /////////////////////////

var superheroes = require("superheroes");
var superVillian = require("supervillains")

var myhero = superheroes.random();
var villian = superVillian.random();

console.log(myhero);
console.log(villian);
