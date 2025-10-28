/*
 * RTC Test Example
 * 
 * Test I2C connection to RTC module
 * This example scans I2C bus and tests RTC communication
 * 
 * Note: This is a basic test. For actual RTC functionality,
 * install RTClib library and use proper RTC functions.
 */

#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Serial.println("RTC Test - I2C Scanner");
  Serial.println("----------------------");
  
  Wire.begin();
  
  Serial.println("Scanning I2C bus...");
  Serial.println();
  
  byte error, address;
  int nDevices = 0;
  
  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println();
      
      // Check if it's likely an RTC
      if (address == 0x68) {
        Serial.println("  -> This is likely a DS3231 or DS1307 RTC!");
      }
      
      nDevices++;
    }
  }
  
  Serial.println();
  if (nDevices == 0) {
    Serial.println("No I2C devices found!");
    Serial.println("Check connections:");
    Serial.println("- SDA to A4");
    Serial.println("- SCL to A5");
    Serial.println("- VCC and GND");
  } else {
    Serial.print("Found ");
    Serial.print(nDevices);
    Serial.println(" device(s)");
  }
  
  Serial.println();
  Serial.println("If RTC found at 0x68:");
  Serial.println("1. Install RTClib library");
  Serial.println("2. Use SetTime example to set time");
  Serial.println("3. Upload main InkWatch sketch");
}

void loop() {
  // Nothing to do here
  delay(1000);
}
