function helloWorld(){
    var b = document.getElementById("hello").innerHTML === "This is a test!";

    if (b){ //IF the given p-tag contains the text: This is a test!
        document.getElementById("hello").innerHTML = "Hello World!";
    } 
    else{
        document.getElementById("hello").innerHTML = "This is a test!";
    }
}

function darkLight(){
    var time = (new Date()).getHours();
    var element = document.body;
    if (time > 19 && time <= 24){
        element.classList.toggle("dark-mode");
    }
    else{
        element.classList.toggle("light-mode");
    }
    
    //checks all classes of body --> specifically dark-mode
    //if it doesn't contain the style/class dark-mode it adds it, otherwise removes it
}

function colorInvert(){
    document.getElementById("halloween").style.filter = "invert(1)";
}

function colorNormal(){
    document.getElementById("halloween").style.filter = "invert(0)";
}

function forLoop(){
    var number = document.getElementById("N").value; 
    var sum = 0;
    for (i = 0; i <= number; i++){
        sum += i;
    }

    document.getElementById("outputSum").innerHTML = sum;
}



function date(){
    var date = new Date();
    var today = date.getDay() + "/" + date.getMonth() + "/" + date.getFullYear();

    document.getElementById("today").innerHTML = today;
}