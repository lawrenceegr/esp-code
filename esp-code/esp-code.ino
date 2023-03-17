#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include "DHT.h"
#include <ESPAsyncTCP.h>
#include "webPageCode.h"
#include <SoftwareSerial.h>
#define DHTPIN D4
// Replace with your network credentials
const char* ssid = "Larry-windows";
const char* password = "012345678";

SoftwareSerial arduino (4,5); // RX, TX pins
// Uncomment the type of sensor in use:
DHT dht(DHTPIN, DHT11);

// current temperature & humidity, this will be updated in loop function
float t = 0.0;//temperature
float h = 0.0;//humidity
float s = 0.0;//speed
float d = 0.0 ;//direction

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

unsigned long previousMillis = 0; //stoe last time DHT was updated
const long interval = 1000; // Updates DHT readings every 1 seconds



void setup(){
// Serial port for debugging purposes
Serial.begin(115200);
  arduino.begin(115200);
// Connect to Wi-Fi
WiFi.begin(ssid, password);
Serial.println("Connecting to WiFi");
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.println(".");
}

  Serial.println(WiFi.localIP());
  
  // Route for root / web page
      server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", index_html);
      });
      server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", String(t).c_str());
      });

      server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", String(h).c_str());
      });
       server.on("/speed", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", String(s).c_str());
      });

      server.on("/direction", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", String(d).c_str());
      });
    
      server.begin();

}
void loop(){ 
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {

  previousMillis = currentMillis;
  h =  dht.readTemperature();  
  t =  dht.readHumidity();  
  s = getWindSpeed();
  d = getWindDirection(); 



}
 String data = arduino.readStringUntil('\n');
}


