let randomNum = Math.floor(Math.random() * 100) + 1
let attemps = 0;

const guess = document.getElementById("guess");
const submit = document.getElementById("submit");
const hints = document.getElementById("hints");
const attempts = document.getElementById("attempts");

submit.addEventListener("click", checkGuess);

function checkGuess(){
    const userValue = Number(guess.value);
    attemps++;

    if (userValue === randomNum){
        hints.textContent = "Congratulations, you guessed it";
    }
    else if (userValue < randomNum){
        hints.textContent = "your guess: " + userValue + ", was too low, try again";
    }
    else{
        hints.textContent = "your guess: " + userValue + ", was too high, try again";
    }
    attemps.textContent = "Attempts: " + attempts;
}