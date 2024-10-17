function helloWorld(){
    var b = document.getElementById("hello").innerHTML === "Dit is een test!";
    
    if (b){
        document.getElementById("hello").innerHTML = "Hello World!";
    }
    else{
        document.getElementById("hello").innerHTML = "Dit is een test!";
    }
}

function darkLight(){
    var element = document.body;
    var datum = new Date();
    var tijd = datum.getHours();

    if (tijd < 20){
        element.classList.toggle("light-mode");
    }
    else{
        element.classList.toggle("dark-mode");
    }

    //doorzoekt classes die gelinkt kunnen worden aan body
    //indien dark-mode niet is toegepast, zet hem aan, anders zet hem uit.
}

function kleurInvert(){
    document.getElementById("HW").style.filter = "invert(1)";
}

function kleurNormaal(){
    document.getElementById("HW").style.filter = "invert(0)";
}

function saveInputPrintOutput(){
    var n = document.getElementById("naam").value;
    var p = document.getElementById("pword").value;
    document.getElementById("output").innerHTML = "Naam: " + n + " Wachtwoord: " + p;
}


function forLoop(){
    var som = 0;
    var getal = document.getElementById("n").value;
    for (i = 0; i <= getal; i++){
        som += i; //som = som + i
    }

    document.getElementById("outputSom").innerHTML = som;
}

function datum(){
    var datum = new Date();
    var vandaag = datum.getDate() + "/" + (datum.getMonth()+1) + "/" + datum.getFullYear();
    document.getElementById("vandaag").innerHTML = vandaag;
}