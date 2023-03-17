const char index_html[] PROGMEM = R"=====( 
<!DOCTYPE HTML>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<script src="https://code.highcharts.com/8.0/highcharts.js"></script>
<style>
body {

color: #fff;

margin: 0 auto;
padding-left: 20px;
padding-right: 20px;
/* background-image: url('https://th.bing.com/th/id/OIP.QpCc_IyfFX21Tfw12A5jEgAAAA?w=115&h=180&c=7&r=0&o=5&pid=1.7'); */
background-color: rgb(20, 8, 71);
background-repeat: repeat;
background-size: cover;
background-size: contain;
}

.heading {
font-family: Arial;
font-size: 2.5rem;
text-align: center;
padding: 4px;
transform: skew(20deg);
background-color: green;
border-radius: 5px;
}

img{
  height: 100px;
  width: 100px;
  border-radius: 10px;
}
.data{
 
  margin-bottom: 30px;
  font-size:x-large ;
  font-weight: bolder;
  display: flex;
  gap: 10px;
  padding-left: 30%;
  text-align: start;
}
.label{
 
  width: 200px;
}
.value{
  text-align: center;
   width: 100px;
  height: 50px;
  padding: 5px;
  background-color: darkgreen;
  color: #fff;
}
@media only screen and  (max-width:600px){
   .heading{
    font-size: large;
   }
img{
  height: 50px;
  width: 50px;
  border-radius: 10px;
}
.data{
 
  margin-bottom: 30px;
  font-size:medium ;
  font-weight: bolder;
  display: flex;
  gap: 10px;
  padding-left: 10%;

}
.label{
  width: 100px;
}
.value{
  width: auto;
  height: auto;
}
.unit{
  font-size: 1.2rem;
}
}
</style>
<title>Web server</title>
</head>
<body>
<h2 class="heading">Station 1 weather data </h2>



<div id ="windSpeed" class="data temperature">
  <img src="https://th.bing.com/th/id/OIP.w1IJfSY7YeSsniKTqfndbAHaFj?w=215&h=180&c=7&r=0&o=5&pid=1.7" alt="">
  <p class="label">Temperature:</p> <p class="value" id="temperature">0.00</p> <p class="unit"><sup ">&deg;</sup>C</p>
</div>
<div class="data humidity">
  <img src="https://th.bing.com/th/id/OIP.Um9JWJUOP-GSP40dEt6n2wHaJv?w=137&h=180&c=7&r=0&o=5&pid=1.7" alt="">
  <p class="label">Humidity: </p><p class="value" id="humidity">0.00</p> <p class="unit">%</p>
</div>
<div class="data speed">
  <img src="https://th.bing.com/th?q=Wind+Icon+Green&w=120&h=120&c=1&rs=1&qlt=90&cb=1&pid=InlineBlock&mkt=en-WW&cc=KE&setlang=en&adlt=moderate&t=1&mw=247" alt="">
  <p class="label">Wind Speed :</p> <p class="value" id="speed">0.00</p> <p class="unit">km/hr</p>
</div>
<div class="data direction">
  <img src="https://th.bing.com/th/id/OIP.kPl0UKRogT2pwYZVTPSjpwHaHa?w=155&h=180&c=7&r=0&o=5&pid=1.7" alt="">
  <p class="label">Wind Direction :</p> <p class="value" id="direction">Unknown</p> <p class="unit"></p>
 </div>


</body>
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("temperature").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/temperature", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("humidity").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/humidity", true);
  xhttp.send();
}, 10000 ) ;
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("speed").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/speed", true);
  xhttp.send();
}, 10000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("direction").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/direction", true);
  xhttp.send();
}, 10000 ) ;

  
</script>
</html>
 )====="; 