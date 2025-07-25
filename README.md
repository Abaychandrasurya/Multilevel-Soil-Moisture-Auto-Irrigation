# 🌱 ESP32 Smart Irrigation System with Multilevel Sensing and Blynk

This project is a smart irrigation system built using an ESP32, soil moisture sensors at three depths, a DHT22 temperature/humidity sensor, and a water pump controlled via a relay. The system sends sensor data to the Blynk IoT platform, allowing you to monitor and control irrigation remotely.

---

## 🚀 Features

-   Reads temperature and humidity using a **DHT22** sensor.
-   Measures soil moisture at three levels (upper, mid, deeper) using analog sensors.
-   Calculates average soil moisture.
-   Displays all data on the **Blynk** app (via virtual pins V0–V5).
-   Manual pump control via Blynk (V6).
-   Automatically uploads data to Blynk every 10 seconds.

---

## 🛠️ Hardware Required

-   ESP32 board
-   DHT22 sensor
-   3x Soil moisture sensors (analog)
-   1x Relay module
-   Water pump
-   Jumper wires and breadboard
-   Wi-Fi connection (e.g., mobile hotspot)

---
### 📷 Hardware Setup
![Hardware Setup](images/hardware-setup.jpg)

## 📲 Blynk Setup

1.  Create a Blynk account and start a new project.
2.  Note your:
    -   **Template ID**
    -   **Template Name**
    -   **Auth Token**
3.  Add the following virtual pins to your Blynk project dashboard:
    -   `V0` – Temperature (°C)
    -   `V1` – Humidity (%)
    -   `V2` – Upper soil moisture
    -   `V3` – Mid soil moisture
    -   `V4` – Deeper soil moisture
    -   `V5` – Average moisture
    -   `V6` – Pump control (Button: 0 = OFF, 1 = ON)

---

## 📄 Code Overview

Add your Blynk and Wi-Fi credentials to the code:

```cpp
#define BLYNK_TEMPLATE_ID   "your-template-id"
#define BLYNK_TEMPLATE_NAME "your-template-name"
#define BLYNK_AUTH_TOKEN    "your-auth-token"

char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";
```

## 📦 Libraries Required
Install these libraries via the Arduino IDE Library Manager:
-   `Blynk`
-   `DHT sensor library`
-   `Adafruit Unified Sensor (dependency for DHT)`
-   `WiFi (built-in for ESP32)`

## 🧠 How It Works
-   Every 10 seconds, the ESP32 reads data from the DHT22 and the three soil moisture sensors.
-   Raw analog moisture values are mapped to a user-friendly percentage scale.
-   All sensor data is sent to the corresponding Blynk virtual pins.
-   You can toggle the water pump manually at any time using the button widget connected to V6 in the Blynk app.

## ✅ Future Improvements
-   Add automatic pump control based on soil moisture.
-   Integrate weather forecast API to optimize irrigation.
-   Store data using Blynk history or external databases (like Firebase or ThingsBoard).
