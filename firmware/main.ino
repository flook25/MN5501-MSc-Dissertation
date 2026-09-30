/*
 * Dissertation Project: 4-Channel VL6180X ToF Sensor Array
 * Microcontroller: Arduino Mega 2560
 * Description: Dynamic I2C address assignment using hardware EN (XSHUT) pins
 * to bypass external I2C multiplexers.
 */

#include <Wire.h>
#include <Adafruit_VL6180X.h>

// Define hardware Enable (EN/XSHUT) pins on Arduino Mega 2560
#define EN_PIN_1 32
#define EN_PIN_2 33
#define EN_PIN_3 34
#define EN_PIN_4 35

// Define new I2C operational addresses
#define ADDRESS_1 0x30
#define ADDRESS_2 0x31
#define ADDRESS_3 0x32
// Sensor 4 will retain the default address: 0x29

Adafruit_VL6180X sensor1 = Adafruit_VL6180X();
Adafruit_VL6180X sensor2 = Adafruit_VL6180X();
Adafruit_VL6180X sensor3 = Adafruit_VL6180X();
Adafruit_VL6180X sensor4 = Adafruit_VL6180X();

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // Step 1: Set all EN pins as OUTPUT and pull LOW to put sensors in standby
  pinMode(EN_PIN_1, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);
  pinMode(EN_PIN_3, OUTPUT);
  pinMode(EN_PIN_4, OUTPUT);
  
  digitalWrite(EN_PIN_1, LOW);
  digitalWrite(EN_PIN_2, LOW);
  digitalWrite(EN_PIN_3, LOW);
  digitalWrite(EN_PIN_4, LOW);
  delay(10);

  // Step 2: Initialize Sensor 1 and reassign address
  digitalWrite(EN_PIN_1, HIGH);
  delay(50);
  sensor1.begin();
  sensor1.setAddress(ADDRESS_1);

  // Step 3: Initialize Sensor 2 and reassign address
  digitalWrite(EN_PIN_2, HIGH);
  delay(50);
  sensor2.begin();
  sensor2.setAddress(ADDRESS_2);

  // Step 4: Initialize Sensor 3 and reassign address
  digitalWrite(EN_PIN_3, HIGH);
  delay(50);
  sensor3.begin();
  sensor3.setAddress(ADDRESS_3);

  // Step 5: Initialize Sensor 4 (Retains default 0x29)
  digitalWrite(EN_PIN_4, HIGH);
  delay(50);
  sensor4.begin();
  
  Serial.println("All ToF sensors initialized successfully.");
}

void loop() {
  // Read distance from all 4 sensors
  uint8_t l1 = sensor1.readRange();
  uint8_t l2 = sensor2.readRange();
  uint8_t l3 = sensor3.readRange();
  uint8_t l4 = sensor4.readRange();

  // Transmit raw distance data via serial for Excel Data Streamer
  Serial.print(l1); Serial.print(",");
  Serial.print(l2); Serial.print(",");
  Serial.print(l3); Serial.print(",");
  Serial.println(l4);

  delay(100); // 10Hz sampling rate
}