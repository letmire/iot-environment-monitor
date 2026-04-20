#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include "DHT.h"

// --- 1. CONFIGURATION (REMOVED SECRETS FOR SECURITY) ---
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
#define BOTtoken "YOUR_TELEGRAM_BOT_TOKEN"
#define CHAT_ID "YOUR_CHAT_ID"

// --- 2. DHT11 SENSOR SETUP ---
#define DHTPIN 4     
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

void setup() {
  Serial.begin(115200);
  dht.begin(); 
  
  WiFi.begin(ssid, password);
  client.setInsecure(); 

  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected!");
  // Translated greeting message
  bot.sendMessage(CHAT_ID, "System Online! 🌡️ Incoming environmental data...", "");
}

void loop() {
  float h = dht.readHumidity();    
  float t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) {
    Serial.println("Error: Failed to read from DHT sensor!");
  } else {
    // Translated Report
    String mensagem = "📊 Environmental Report:\n";
    mensagem += "Temperature: " + String(t) + "°C\n";
    mensagem += "Humidity: " + String(h) + "%";
    
    bot.sendMessage(CHAT_ID, mensagem, "");
    Serial.println("Telemetry data sent!");
  }
  
  delay(30000); 
}