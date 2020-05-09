// Testing DHT11 humidity/temperature sensor


#include "DHT.h"
#define DHTPIN A0     // Digital pin on mkrwifi1010 connected to the DHT sensor pin 2
#define DHTTYPE DHT11   // DHT11

// Initialize the DHT11 sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Check if any readings failed.
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT11 sensor"));
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(hic);
  Serial.println(F("°C "));
}
