//jshint esversion

const express = require("express");
const app = express();

app.get("/",function(request,response){
    //console.log(request);
    // response.send("Hello");
    response.send("<h1>Hello, World</h1>")
})

app.get("/contact",function(req,res){
    res.send("Contact me at: mannchandarana@gmail.com")
})
app.get("/about",function(req,res){
    res.send("My name is Mann Chandarana")
})

app.listen(3000,function(){
    console.log("Server started on port 3000");
});