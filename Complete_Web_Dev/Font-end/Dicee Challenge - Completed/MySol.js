var random1 = Math.floor(Math.random() * 6) + 1;
var random2 = Math.floor(Math.random() * 6) + 1;


document.querySelector(".img1").setAttribute("src", `images/dice${random1}.png`);
document.querySelector(".img2").setAttribute("src", `images/dice${random2}.png`);

if (random1 > random2) {
    document.querySelector("h1").textContent = "Player1 Wins!";
}
else if (random1 < random2) {
    document.querySelector("h1").textContent = "Player2 Wins!";
}
else
{
    document.querySelector("h1").textContent = "Draw!";
}
