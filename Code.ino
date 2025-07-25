// --- BLYNK CREDENTIALS ---
// Replace with your actual credentials from the Blynk app.
#define BLYNK_TEMPLATE_ID "aaaaaaaaaaaa"
#define BLYNK_TEMPLATE_NAME "aaaaaaaaaaaaaaaaaa"
#define BLYNK_AUTH_TOKEN "aaaaaaaaaaaaaaaa"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "Hotspot Name";
char pass[] = "Passwowrd";

#define SOIL_PIN_DEEPER 32
#define SOIL_PIN_MID    35
#define SOIL_PIN_UPPER  34
#define DHT_PIN         4
#define RELAY_PIN       5

#define DHT_TYPE DHT22
DHT dht(DHT_PIN, DHT_TYPE);

BlynkTimer timer;

BLYNK_WRITE(V6) {
  int pinValue = param.asInt();
  digitalWrite(RELAY_PIN, pinValue);
  Serial.print("Blynk set Pump to: ");
  Serial.println(pinValue);
}

void sendSensorData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  int moistureUpper = map(analogRead(SOIL_PIN_UPPER), 4095, 1000, 0, 100);
  int moistureMid = map(analogRead(SOIL_PIN_MID), 4095, 1000, 0, 100);
  int moistureDeeper = map(analogRead(SOIL_PIN_DEEPER), 4095, 1000, 0, 100);
  int avgMoisture = (moistureUpper + moistureMid + moistureDeeper) / 3;

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, moistureUpper);
  Blynk.virtualWrite(V3, moistureMid);
  Blynk.virtualWrite(V4, moistureDeeper);
  Blynk.virtualWrite(V5, avgMoisture);

  Serial.println("Sensor data sent to Blynk.");
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(10000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
