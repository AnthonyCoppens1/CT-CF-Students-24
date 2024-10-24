var randomNum = Math.floor(Math.random() * 100) + 1;
var attempts = 0;

const guess = document.getElementById("guess");
const submit = document.getElementById("submit");
const hints = document.getElementById("hint");
const attemptsText = document.getElementById("attempts");

submit.addEventListener("click", checkGuess);
function checkGuess(){
    const userValue = Number(guess.value);
    attempts;
    if (userValue === randomNum){
        hints.textContent = "Congratulations, you guessed it!";
    }
    else if (userValue < randomNum){
        hints.textContent = "Your guess: " + userValue + ", was too low, try again";
    }
    else{
        hints.textContent = "Your guess: " + userValue + ", was too high, try again";
    }
    attempts.textContent = "Attempts: " + attempts;
}
