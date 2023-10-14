// jshint version:6

const mongoose = require('mongoose');

// For connection
mongoose.connect("mongodb://localhost:27017/fruiotsDB",{useNewUrlParser: true});

const fruitSchema = new mongoose.Schema({
  // name: String,
  name:{
    type:String,
    required:[true,"Please check your data entry, no name specified!"]
  },
  // rating:Number,
  rating :{
    type:Number,
    min:1,
    max:10
  },
  review:String
});

const Fruit = mongoose.model("Fruit",fruitSchema);

const fruit = new Fruit({
  name :"Apple",
  rating:7,
  review:"Preety solid as a fruit."
});

// const Kiwi = new Fruit({
//   name :"Kiwi",
//   rating:8,
//   review:"The best fruit"
// });

// const banana = new Fruit({
//   name :"bamana",
//   rating:6,
//   review:"Preety good."
// });

// Fruit.insertMany([Kiwi,fruit,banana],function(err){
//   if(err)
//   {
//     console.log(err);
//   }
//   else
//   {
//     console.log("Successfully saved all the fruits");
//   }
// });



//  fruit.save();

const personSchema = new mongoose.Schema({
  name:String,
  age:Number,
  favouritefruits:fruitSchema
});

const Person = mongoose.model("Person",personSchema);

const pineapple = new Fruit({
  name:"Pineapple",
  score:9,
  review:"Great fruit"
});

pineapple.save();

const mango = new Fruit({
  name : "mango",
  score:6,
  review: "Decnet fruit."
})

mango.save();
Person.updateOne({name:"John"},{favouritefruits:mango},function(err){
  if (err) 
  {
    console.log(err);
  }
  else
  {
    console.log("Successfully updated the document");
  }
})
const person = new Person({
  name :"John",
  age :37,
  favouritefruits:pineapple
});

 person.save(function(err){
   console.log("Successfully added the data of all the person");
 });

 Fruit.find(function(err,fruits){
   if(err)
   {
     console.log(err);
   }
   else
   {
     console.log(fruits);
   }
 })

// Fruit.find(function(err,fruits){
//   if(err)
//   {
//     console.log(err);
//   }
//   else
//   {
//     mongoose.connection.close();
//     fruits.forEach(function(element){
//       console.log(element.name);
//     });
//   }
// })


///////// For Updating ///////////

Fruit.updateOne({_id: "6177e069dda7c5601d8b22d"},{name:"Peach"},function(err){
  if(err)
  {
    console.log(err);
  }
  else
  {
    console.log("Successfully updated everything");
  }
})

//////// For Deleting //////////

Fruit.deleteOne({name:"Peach"},function(err){
  if (err) 
  {
    console.log(err);
  }
  else
  {
    console.log("Successfully deleted the document");
  }
})

Person.deleteMany({name:"john"},function(err){
  if (err) 
  {
    console.log(err);
  }
  else
  {
    console.log("Successfully deleted all the element");
  }
})

