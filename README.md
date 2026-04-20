# IoT Smart Environmental Monitor 🌡️

A real-time climate monitoring system developed with **ESP32** and **DHT11** sensor. This project bridges the gap between hardware and software by collecting environmental data and sending instant telemetry reports to a smartphone.

## 🚀 Features
* **Real-time Monitoring:** Tracks temperature and humidity.
* **Instant Alerts:** Integrated with **Telegram Bot API** for mobile notifications.
* **Secure Connectivity:** Uses encrypted Wi-Fi communication.

## 🛠️ Tech Stack
* **Hardware:** ESP32 Microcontroller, DHT11 Sensor.
* **Software:** C++, Arduino IDE.
* **Connectivity:** WiFiClientSecure, Telegram API.

## 📋 How it works
The system initializes the Wi-Fi connection and the DHT11 sensor. Every 30 seconds, it reads the temperature and humidity levels and pushes a structured report directly to the user's Telegram chat.