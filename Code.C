#include <DHTesp.h>
DHTesp dhtSensor;
#include "WiFi.h"
#include <HTTPClient.h>
// setting the Wifi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

const String url = "https://api.thingspeak.com/update?api_key=0OOTEQH9IUW733XE&";
HTTPClient http;
void setup() {
  Serial.begin(115200);
  Serial.println("starting setup");
  // Leds will be start turned off
  digitalWrite(23, LOW);
  digitalWrite(22, LOW);

  // Outputs pins, the energy will get out of this pins
  dhtSensor.setup(13, DHTesp::DHT22);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);

  // Connecting to Wifi
  WiFi.begin(ssid, password);
 

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("Connecting to WiFi");
  }


  Serial.println("finalizing setup");


}

void loop() {
 
  delay(1000);
  // Get temperature and humidity
  float temperature = dhtSensor.getTemperature();
  float humidity = dhtSensor.getHumidity();
  Serial.println("Temperature:" + String(temperature) + "°" + " Humidity:" + String(humidity)+"%");
  
  // Post temperature and humidity to api
  String path = url + "field1=" + String(temperature) + "&field2=" + String(humidity);
  http.begin(path);
  int httpCode = http.GET();
  String payload = http.getString();

  // Status of request send to API
    // Serial.println("HttpCode:" + String(httpCode));
    
  // the object recived of the API
    // Serial.println("Payload:" + payload);


 
//  If  the request return a status 404 or other error, then the red led will turn on
  if(httpCode != 200 ){
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
  }

  // If  the request return a  status 200, then the green led will turn on
  else{
    digitalWrite(23, HIGH);
    digitalWrite(22, LOW);
  }

 

  
  
}
  
