#include <DHTesp.h>
DHTesp dhtSensor;
#include "WiFi.h"
#include <HTTPClient.h>
const char* ssid = "Wokwi-GUEST";
const char* password = ""; 
const String url = "https://api.thingspeak.com/update?api_key=0OOTEQH9IUW733XE&";
HTTPClient http;
void setup() {
  Serial.begin(115200);
  Serial.println("iniciando setup");
  // leds will be start turned off
  digitalWrite(23, LOW);
  digitalWrite(22, LOW);

  dhtSensor.setup(13, DHTesp::DHT22);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  WiFi.begin(ssid, password);
 

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("Conecting to WiFi");
  }


  Serial.println("Finalizando setup");


}

void loop() {
 
  delay(1000);
  // get temperature and humidity
  float temperatura = dhtSensor.getTemperature();
  float umidade = dhtSensor.getHumidity();
  Serial.println("Temperatura:" + String(temperatura) + "°" + " Umidade:" + String(umidade)+"%");
  
  // Post temperature and humidity to api
  String path = url + "field1=" + String(temperatura) + "&field2=" + String(umidade);
  http.begin(path);
  int httpCode = http.GET();
  String payload = http.getString();

  Serial.println("HttpCode:" + String(httpCode));
  Serial.println("Payload:" + payload);


 
//  if  the request return a status 404 or other error, then the red led will turn on
  if(httpCode =! 200 ){
    digitalWrite(23, HIGH);
    digitalWrite(22, LOW);
  }

  // if  the request return a  status 200  or other error, then the green led will turn on
  else{
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
  }

 

  
  
}
  
