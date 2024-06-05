#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define DHTPIN 27  
#define DHTTYPE DHT11
#define SOIL_MOISTURE_PIN 26  
#define MOTOR_PIN 25

const char* ssid = "Robotics";
const char* password = "12345678";

const char* firebaseHost = "https://advance-farming-default-rtdb.firebaseio.com/"; // Include the full URL
const char* firebaseAuth = "AIzaSyC-SnWAKTQcd7uFopizutiz0_W0w948pVE";
const char* firebasePath = "/sensorData"; // Specify the path

DHT dht(DHTPIN, DHTTYPE);

HTTPClient http; // Declare HTTPClient object globally

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  dht.begin();
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

    String pumpStatus = "OFF";

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.print(" %, Soil Moisture: ");
    Serial.print(soilMoistureValue);
    Serial.print(", Pump Status: ");

    if (soilMoistureValue < 1500) {
      digitalWrite(MOTOR_PIN, HIGH);
      pumpStatus = "ON";
    } else {
      digitalWrite(MOTOR_PIN, LOW);
      pumpStatus = "OFF";
    }

    Serial.println(pumpStatus);

    String jsonData = "{\"temperature\": " + String(temperature) + ", \"humidity\": " + String(humidity) + ", \"soil_moisture\": " + String(soilMoistureValue) + ", \"pump_status\": \"" + pumpStatus + "\"}";

    String url = String(firebaseHost) + firebasePath + ".json?auth=" + String(firebaseAuth); // Ensure URL is correct and ends with .json
    http.begin(url);
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.PUT(jsonData); // Use PUT method to create or replace data

    if (httpCode > 0) {
      Serial.printf("[HTTP] PUT request to Firebase successful, status code: %d\n", httpCode);
    } else {
      Serial.printf("[HTTP] PUT request to Firebase failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();

    delay(5000);
  } else {
    Serial.println("WiFi Disconnected");
  }
}
