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

## 🔌 Hardware Connections

**Important:** The ESP32's logic level is **3.3V**. Connect VCC pins to **3.3V** unless specified otherwise. Always connect **GND** first.

### 1. DHT22 Sensor (Temperature & Humidity)

| DHT22 Pin | ESP32 Pin | Notes                                    |
| :-------- | :-------- | :--------------------------------------- |
| `VCC` / `+` | `3.3V`      |                                          |
| `Data`      | `GPIO 4`  | Requires a 10kΩ pull-up resistor if not built-in |
| `GND` / `-` | `GND`       |                                          |

### 2. Soil Moisture Sensors

All three sensors share the same power connections. Their analog signal pins connect to unique ADC pins on the ESP32.

**Power Connections (for all 3 sensors):**
-   **VCC** → ESP32 **3.3V**
-   **GND** → ESP32 **GND**

**Signal Pin Connections:**

| Sensor Location | Sensor Pin | ESP32 Pin |
| :-------------- | :--------- | :-------- |
| Upper           | `A0`       | `GPIO 34` |
| Mid             | `A0`       | `GPIO 35` |
| Deeper          | `A0`       | `GPIO 32` |

### 3. Relay Module & Water Pump

The connection is split into two parts: controlling the relay with the ESP32, and the relay switching the high-voltage pump.

#### **Relay Control Connections**

| Relay Pin | ESP32 Pin | Notes                                 |
| :-------- | :-------- | :------------------------------------ |
| `VCC`     | `VIN`     | Provides 5V, required by most relays  |
| `IN`      | `GPIO 5`  | Signal pin to trigger the relay       |
| `GND`     | `GND`     |     
---

### 📷 Hardware Setup
![Hardware Setup](images/hardware-setup.jpg)

---

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
