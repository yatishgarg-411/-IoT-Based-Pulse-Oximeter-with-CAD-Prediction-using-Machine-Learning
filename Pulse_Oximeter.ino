#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include "BluetoothSerial.h"

#define REPORTING_PERIOD_MS 1000
#define MEASUREMENT_DURATION_MS 20000  // Set measurement duration to 20 seconds

//LiquidCrystal_I2C lcd(0x3F, 16, 2);
BluetoothSerial SerialBT;
PulseOximeter pox;

uint32_t tsLastReport = 0;
uint32_t measurementStartTime = 0;
bool isMeasuring = false;

void onBeatDetected() {
  Serial.println("Beat!!!");
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32");
//  lcd.init();
//  lcd.backlight();
//  lcd.print("Welcome");
//  lcd.setCursor(0, 1);
//  lcd.print("Place your finger on the sensor");
  
  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;);
  } else {
    Serial.println("SUCCESS");
  }

  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
  pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  pox.update();
  
  // Start measuring when valid readings are detected and no measurement is in progress
  if (!isMeasuring) {
    float bpm = pox.getHeartRate();
    float spo2 = pox.getSpO2();
    
    if (bpm > 40 && spo2 > 90) {  // Example thresholds for detecting presence
//      lcd.setCursor(0, 1);
//      lcd.print("Person detected. Starting measurement...");
      Serial.println("Person detected. Starting measurement...");
      isMeasuring = true;
      measurementStartTime = millis();
      tsLastReport = millis();  // Reset report time
    }
  } else {
    // Display and record data during measurement
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
      float bpm = pox.getHeartRate();
      float spo2 = pox.getSpO2();

//      lcd.clear();
//      lcd.setCursor(0, 0);
//      lcd.print("BPM: ");
//      lcd.print(bpm);
//      lcd.setCursor(0, 1);
//      lcd.print("SpO2: ");
//      lcd.print(spo2);
//      lcd.print("%");

      if (bpm > 0 && spo2 > 0) {
        String data = "BPM: " + String(bpm) + " SpO2: " + String(spo2) + "%";
        SerialBT.println(data);
        Serial.print("Sent: ");
        Serial.println(data);
      }
      
      tsLastReport = millis();
    }

    // End measurement after the set duration
    if (millis() - measurementStartTime >= MEASUREMENT_DURATION_MS) {
      Serial.println("Measurement complete.");
      isMeasuring = false;
      
      // Display final reading or reset for next person
//      lcd.clear();
//      lcd.setCursor(0, 0);
//      lcd.print("Measurement done");
    }
  }
}
