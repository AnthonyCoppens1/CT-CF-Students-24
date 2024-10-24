function helloWorld(){
    //I want this to be a boolean, not just the pure text inside of the tag.
    var b = document.getElementById("hello").innerHTML === "This is a test";
    if (b){
        document.getElementById("hello").innerHTML = "Hello World!";
    }
    else{
        document.getElementById("hello").innerHTML = "This is a test";
    }
}


function darkLight(){
    var element = document.body;
    element.classList.toggle("dark-mode");
    //looks for class dark-mode in list of all classes
    //turns on this style if it's currently off, turns it off it it is currently used.
}

function saveInputPrintOutput(){
    var name = document.getElementById("name").value;
    var password = document.getElementById("pword").value;

    document.getElementById("output").innerHTML = "Name: " + name + " Password: " + password;
}

function colorInvert(){
    document.getElementById("HW").style.filter = "invert(1)";
}

function colorNormal(){
    document.getElementById("HW").style.filter = "invert(0)";
}

function forLoop(){
    var sum = 0;
    for (i = 0; i < 5; i++){
        sum += i;
    }
    document.getElementById("sum").innerHTML = sum; //returns the sum into the element
}

function date(){
    var date = new Date();
    var today = date.getDay() + " / " + date.getMonth() + " / " + date.getFullYear();
    document.getElementById("today").innerHTML = today;
}

function messageDay(){
    var time = (new Date()).getHours();
    var greeting = "";
    if (time < 12){
        greeting = "Good morning!";
    }
    else{
        greeting = "Good day!";
    }
    document.getElementById("message").innerHTML = greeting;
}