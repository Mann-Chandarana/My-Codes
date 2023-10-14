// getting-started.js
const mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/test', {useNewUrlParser: true,useUnifiedTopology:true});

var db = mongoose.connection;
db.on('error',console.error.bind(console,'connection:error:'));

db.once('open',function(){
    // We' re connected !
    console.log("We are connected bro/sis ...");
})

const kittySchema = new mongoose.Schema({
    name: String
});

var kitten = mongoose.model('Kitten',kittySchema);

var harrykitten= new Kitten({ name: 'harryKitty' });
console.log(harrykitty.name); // 'Silence'
harrykitten.speak();


kittySchema.methods.speak = function () {
    var greeting = this.name
    console.log(greeting);
  }

harrykitty.save(function (err, harrykitty) 
{
    if (err) return console.error(err);
    harrykitty.speak();
});

harrykitty.save(function (err, k) 
{
    if (err) return console.error(err);
    k.speak();
});

