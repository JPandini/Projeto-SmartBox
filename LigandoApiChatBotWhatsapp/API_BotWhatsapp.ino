#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>
#include <string>


const char* ssid = "Messi";
const char* password = "12345678";

// +international_country_code + phone number
// Portugal +351, example: +351912345678
String receiverId = "88969616";
String apiKey = "69a6d8bb-d433-4ef4-aa84-1a4a4bb58834";

void sendMessage(String message){

  // Data to send with HTTP POST
  String url = "https://backend.botconversa.com.br/api/v1/webhook/subscriber/88969616/send_flow/" + receiverId + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;
  HTTPClient http;
  http.begin(client, url);

  // Specify content-type header
  //"application/x-www-form-urlencoded"
  //
  
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "69a6d8bb-d433-4ef4-aa84-1a4a4bb58834");

  String msg = "{'value': '634725'}";
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  // Send Message to WhatsAPP
  sendMessage("Hello from ESP8266!");
}

void loop() {
}
