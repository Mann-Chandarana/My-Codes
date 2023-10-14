const express = require("express");
const https = require("https"); // To create https module for requesting data from the external data
const bodyParser = require("body-parser");

const app = express();

app.use(bodyParser.urlencoded({extended:true}))

app.get("/",function(req,res){
    res.sendFile(__dirname+"/index.html");
})

app.post("/",function(req,res){

    const query = req.body.cityName;
    const api_key = "5c0986174d0f261c45fbc7dfb40005d5";
    const unit = "metric";

    const url = "https://api.openweathermap.org/data/2.5/weather?q="+query+"&units="+unit+"&appid="+api_key;
    
    https.get(url,function(response){
        // console.log(response);
        console.log(response.status);

        response.on("data",function(data)
        {
            // console.log(data); -> to get data
            const weatherData = JSON.parse(data);
            // console.log(weatherData); // To convert the data into javascript object
            // const object = {
            //     name:"Mann",
            //     favouritFood :"Ramen",
            // }

            // console.log(JSON.stringify(object));// to convert the object into string(type) used in API
             const temp = weatherData.main.temp; // to get value of temp consant inside main object
             console.log(temp);
             const icon = weatherData.weather[0].icon;
             const imageURl = "http://openweather.org/img/wn/"+icon+"@2x.png"
            // const temp = weatherData.weather[0].description; // to get value of temp consant inside main object
            // console.log(temp);
            res.write("<p>The weather is currently "+ weatherData.weather[0].description+"</p>");
            res.write("<h1>The temperature in "+query+" is "+temp+" degree celcius</h1>");
            res.write("<img src="+imageURl+">")
            res.send();

        })
    })
    // res.send("Server is up and running.") 
})



app.listen(3000,function(){
    console.log("Server is running on port 3000");
})