//Global Variables
var cincout=true;

//(1)
function getData() {
    var getRegion=document.querySelector("#region").value;
    var getDestination=document.querySelector("#destination").value;
    var data=new Array(getRegion,getDestination);
    window.localStorage.setItem("vector",data);
}

//(2)
function initRegion() {
    document.querySelector("#SGP").selected=true;
    document.querySelector("#city1").selected=true;
}
//(3)
function getCity() {
    var x = document.querySelector("#region").selectedIndex;
    if (x==0) {
        document.querySelector("#city1").innerHTML="Beijing";
        document.querySelector("#city2").innerHTML="Shanghai";
        document.querySelector("#city1").value="Beijing";
        document.querySelector("#city2").value="Shanghai";
    }
    else if (x==1) {
        document.querySelector("#city1").innerHTML="Bangkok";
        document.querySelector("#city2").innerHTML="Phuket";
        document.querySelector("#city1").value="Bangkok";
        document.querySelector("#city2").value="Phuket";
    }
    else{
        document.querySelector("#city1").innerHTML="Singapore";
        document.querySelector("#city2").innerHTML="Sentosa";
        document.querySelector("#city1").value="Singapore";
        document.querySelector("#city2").value="Sentosa";
    }
}

//(4)

function hideCal() {
    document.querySelector(".calendar").style.visibility="hidden";
}
function showCal() {
    document.querySelector(".calendar").style.visibility="visible";
}


//(5)

function getDate(i) {
    var gotdate="2016/05/";
    if (i<=9) {
        gotdate+="0";
        gotdate+=i;
    }
    else {
        gotdate+=i;
    }
    if (cincout==true) {
        document.querySelector("#checkin").value=gotdate;
    }
    else {
        document.querySelector("#checkout").value=gotdate;
    }
}

// (6)
function checkSubmit() {
    if ((document.querySelector("#number_of_room").value)>=1) {
        getInfo();
        return true;
    }
    alert("Information Error");
    return false;
}

//3
function getHotel(checkin,checkout,noroom) {
    //3.1
    var info=new Array(3);
    info[0] = {
        "name":"InterContinental Hong Kong",
        "photo":"../img/hk1.jpg",
        "url":"http://www.ihg.com/intercontinental/hotels/gb/en/hong-kong/hkghc/hoteldetail"
    };
    info[1] = {
        "name":"Banyan Tree Hotel",
        "photo":"../img/bk1.jpg",
        "url":"http://www.banyantree.com/en"
    }
    info[2] = {
        "name":"Marina Bay Sands",
        "photo":"../img/sgp1.jpg",
        "url":"http://www.marinabaysands.com/"
    }
    //3.2
    var numofhotel=Math.floor(Math.random()*4);
    if (numofhotel==1) {
        document.querySelector("#hk1").style.display="none";
        document.querySelector("#recommended1").style.display="none";
        document.querySelector("#bk1").style.display="none";
        document.querySelector("#recommended2").style.display="none";
        document.querySelector("#sgp1").style.display="block";
        document.querySelector("#recommended3").style.display="block";
        document.querySelector("#noHotelFound").style.display="none";
    }
    else if (numofhotel==2) {
        document.querySelector("#hk1").style.display="none";
        document.querySelector("#recommended1").style.display="none";
        document.querySelector("#bk1").style.display="block";
        document.querySelector("#recommended2").style.display="block";
        document.querySelector("#sgp1").style.display="block";
        document.querySelector("#recommended3").style.display="none";
        document.querySelector("#noHotelFound").style.display="none";
    }
    else if (numofhotel==3) {
        document.querySelector("#hk1").style.display="block";
        document.querySelector("#recommended1").style.display="block";
        document.querySelector("#bk1").style.display="block";
        document.querySelector("#recommended2").style.display="none";
        document.querySelector("#sgp1").style.display="block";
        document.querySelector("#recommended3").style.display="none";
        document.querySelector("#noHotelFound").style.display="none";
    }
    else {
        document.querySelector("#hk1").style.display="none";
        document.querySelector("#bk1").style.display="none";
        document.querySelector("#sgp1").style.display="none";
        document.querySelector(".recommended").style.display="none";
        document.querySelector("#noHotelFound").style.display="block";
    }
}
//3.3
function getInfo() {
    window.localStorage.setItem("checkin",document.querySelector("#checkin").value);
    window.localStorage.setItem("checkout",document.querySelector("#checkout").value);
    window.localStorage.setItem("noroom",document.querySelector("#number_of_room").value);
}
function init_hotel() {
    x=document.querySelector("#checkin");
    x.value=window.localStorage.getItem("checkin");
    x=document.querySelector("#checkout");
    x.value=window.localStorage.getItem("checkout");
    x=document.querySelector("#number_of_room");
    x.value=window.localStorage.getItem("noroom");
}



















