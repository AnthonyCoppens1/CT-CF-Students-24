function saveinputPrintOutPut(){
    var name = document.getElementById("name").value;
    var password = document.getElementById("pword").value;
    document.getElementById("output").innerHTML = "Name: " + name + "<br>Password: " + password;
}

function darkLight(){
    var element = document.body;
    element.classList.toggle("dark-mode"); //toggle either the dark mode in css on or off
}

function helloWorld(){
    var b = document.getElementById("hello").innerHTML === "This is a test";
    if (b){
        document.getElementById("hello").innerHTML = "Hello World.";
    }
    else{
        document.getElementById("hello").innerHTML = "This is a test";
    }
  }

function colorInvert(){
    document.getElementById("doggo").style.filter = "invert(1)";
}

function colorNormal(){
    document.getElementById("doggo").style.filter = "invert(0)";
}

function forLoopCount(){
    var sum = 0;

    for (i = 0; i < 5; i++){
        sum += i;
    }

    document.getElementById("outputSum").innerHTML = sum;
}

function howOld(){
    var date = new Date();
    var today = date.getDay() + " / " + date.getMonth() + " / " + date.getFullYear();
    document.getElementById("future").innerHTML = today;
}


function messageDay(){
    var time = (new Date()).getHours();
    var greeting = "";
    
    if (time < 10){
        greeting = "Good morning";
    }
    else{
        greeting = "Good day";
    }
    
    document.getElementById("message").innerHTML = greeting;
}








function guessingGame(){
    var guess = document.getElementById("nr").value;
    var number = Math.floor(Math.random() * 20);
    var count = 1;

    while (number != guess){
        guess = document.getElementById("nr").value;
        count++;
    }
    
    document.write("Found! (in " + count + "time)");
}



