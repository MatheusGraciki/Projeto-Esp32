#include <DHTesp.h>
DHTesp dhtSensor;
#include "WiFi.h"
#include "PubSubClient.h"
#include <Arduino_JSON.h>

// setting the Wifi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Mqtt config
WiFiClient espClient;
PubSubClient mqttClient(espClient);

int port = 1883;
const char* server = "broker.hivemq.com";
const char* topic = "temperature";


// JSON config

JSONVar data;

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
    delay(1000);
    Serial.println("Connecting to WiFi");
  }
  Serial.println("Connected to WiFi");


  // Connecting to broker
  mqttClient.setServer(server, port); 
  char* clientId = "Client_for_test_of_sa03";
  mqttClient.connect(clientId);
  mqttClient.subscribe(topic);

  while(!mqttClient.connected()){
    delay(500);
    Serial.println("Connecting to broker...");
  }
  Serial.println("Connected to broker");


}

void loop() {
 
  delay(1000);
  // Get temperature and humidity
  float temperature = dhtSensor.getTemperature();
  float humidity = dhtSensor.getHumidity();
  Serial.println("Temperature:" + String(temperature) + "°" + " Humidity:" + String(humidity)+"%");

  // Transform json data in string 
  data["temperatura"] = temperature;
  data["umidade"] = humidity;
  String jsonString = JSON.stringify(data);

  // sending the temperature and humidity to broker
  boolean msg = ("empty");
  msg = mqttClient.publish(topic, jsonString.c_str());
  

  // validation of msg status
  if(!msg){
    Serial.println("Ocorreu um erro durante o envio da mensagem");
    digitalWrite(22, HIGH);
    delay(500);
    digitalWrite(22, LOW);
  }
  else{
    Serial.println("Mensagem enviada com sucesso");
    digitalWrite(23, HIGH);
    delay(500);
    digitalWrite(23, LOW);
  }
  delay(500);
 
}
