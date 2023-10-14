const express = require("express");
const bodyParser = require("body-parser");

const app = express();

let items = [];
let workItems = [];
app.set(bodyParser.urlencoded({extended:true}))

app.use('view engine', 'ejs'); // To tell server that we are using ejs
app.use(express.static("public"));

app.get("/",function(req,res){
    // res.send("Hello");
    // var today = new Date();
    // var currentDay = today.getDay();
    // var day = "";
    let options = {
        weekday: "long",
        day:"numeric",
        month:"long"
    }

    let day = today.toLocaleDateString("en-us",options);
    // res.render("list",{kindOfDay:day});
    res.render("list",{kindOfDay:day,newListItems:items});
    })

app.post("/",function(req,res){
    item = req.body.newItems;

    if (req.body.list=="work") 
    {
        workItems.push(item);
        res.redirect("/work");
    }
    else
    {
       // console.log(item);
          items.push(item);

          res.redirect("/");
    }
    
})

app.get("/work",function(req,res){
    res.render("list",{listTitle:"Work list",newListItems:items})
})

app.post("/work",function(req,res){
    let item = req.body.newItems;
    workItems.push(item);
    res.redirect("/work");
})

app.listen(3000,function(){
    console.log("Server started on port 3000");
})

// if (today.getDay() == 6 || today.getDay()==0) 
    // {
    //     // res.send("<h1>Yay it's the weekend</h1>");
    //     day = "Weekend";
    // }
    // else
    // {
    //     // res.write("<p>It is not a weekend</p>")
    //     // res.write("Boo! I have to work");
    //     // res.send();
    //     day = "weekday";
    // }
    // res.render("list",{kindOfDay:day});

// switch (currentDay) {
//     case 0:
//         day = "Sunday";
//         break;
//     case 1:
//         day = "Monday";
//         break;
//         case 2:
//             day = "Tuesday";
//             break;
//     case 3:
//         day = "Wednesday";
//         break;
//         case 4:
//         day = "Thursday";
//         break;
//         case 5:
//             day = "Friday";
//             break;
//     case 6:
//         day = "Saturday";
//         break;
        
//         default:
//             console.log("Error : current day is equal to: " + currentDay);
//         }