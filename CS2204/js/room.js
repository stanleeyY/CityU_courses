function loadname() {
    var nametag=document.querySelector("#NAME");
    var url_info=window.location.href;
    var values=url_info.split("%27",2);
    nametag.innerHTML=(values[1]);
    window.localStorage.setItem("hotelname",values[1]);
}
function changepic(n) {
    var picid="#pc"+n;
    var picsrc=document.querySelector(picid).src;
    document.querySelector(".top").src=picsrc;
}
function book(n) {
    var person = prompt("Please enter your name", "Dr. CHAN");
    if (person != null) {
        window.localStorage.setItem("clientname",person);
        var pr=n*window.localStorage.getItem("noroom");
        window.localStorage.setItem("price",pr);
        
    }
}
function getreferenceno() {
    var str="";
    var hotelname=window.localStorage.getItem("hotelname");
    str+=hotelname[0];
    str+=hotelname[1];
    var date=new Date();
    var yy=date.getFullYear()%100;
    var mm=date.getMonth();
    var dd=date.getUTCDate();
    var hh=date.getHours();
    var min=date.getMinutes();
    var ss=date.getSeconds();
    if (1) {
    if (yy>9) {
        str+=yy;
    }
    else{
        str+="0";str+=yy;
    }
    if (mm>9) {
        str+=mm;
    }
    else{
        str+="0";str+=mm;
    }
    if (dd>9) {
        str+=dd;
    }
    else{
        str+="0";str+=dd;
    }
    if (hh>9) {
        str+=hh;
    }
    else{
        str+="0";str+=hh;
    }
    if (min>9) {
        str+=min;
    }
    else{
        str+="0";str+=min;
    }
    if (ss>9) {
        str+=ss;
    }
    else{
        str+="0";str+=ss;
    }
    }
    str+="-";
    var cli=window.localStorage.getItem("clientname");
    str+=cli[0];
    str+=cli[cli.length-1];
    document.querySelector("#referenceno").innerHTML=str;
    document.querySelector("#client").innerHTML=window.localStorage.getItem("clientname");
    document.querySelector("#hotelname").innerHTML=window.localStorage.getItem("hotelname");
    document.querySelector("#rmprice").innerHTML=window.localStorage.getItem("price");
}
function adjustpic() {
    document.querySelector("#pc1").onmouseover=function () {
        var picid="#pc1"
        var picsrc=document.querySelector(picid).src;
        document.querySelector(".top").src=picsrc;
    };
    document.querySelector("#pc2").onmouseover=function () {
        var picid="#pc2"
        var picsrc=document.querySelector(picid).src;
        document.querySelector(".top").src=picsrc;
    };
    document.querySelector("#pc3").onmouseover=function () {
        var picid="#pc3";
        var picsrc=document.querySelector(picid).src;
        document.querySelector(".top").src=picsrc;
    };
}