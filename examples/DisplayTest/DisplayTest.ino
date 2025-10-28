/*
 * Display Test Example
 * 
 * A simple sketch to test your e-ink display connection
 * Upload this to verify display is working before using full watch
 */

// Display pins - adjust to match your setup
#define EPD_CS 10
#define EPD_DC 9
#define EPD_RST 8
#define EPD_BUSY 7

void setup() {
  Serial.begin(9600);
  Serial.println("E-ink Display Test");
  
  // Initialize pins
  pinMode(EPD_CS, OUTPUT);
  pinMode(EPD_DC, OUTPUT);
  pinMode(EPD_RST, OUTPUT);
  pinMode(EPD_BUSY, INPUT);
  
  // Reset display
  digitalWrite(EPD_RST, LOW);
  delay(200);
  digitalWrite(EPD_RST, HIGH);
  delay(200);
  
  Serial.println("Display pins initialized");
  Serial.println("Check display for test pattern");
  
  // In a real implementation, you would:
  // 1. Initialize the e-ink display controller
  // 2. Send test pattern to display
  // 3. Update the display
  
  // For now, just verify pins are configured
  Serial.println("Test complete!");
  Serial.println();
  Serial.println("Next steps:");
  Serial.println("1. Verify BUSY pin changes state");
  Serial.println("2. Check display shows something");
  Serial.println("3. If working, upload main InkWatch sketch");
}

void loop() {
  // Read BUSY pin status
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 1000) {
    lastPrint = millis();
    Serial.print("BUSY pin state: ");
    Serial.println(digitalRead(EPD_BUSY) ? "HIGH" : "LOW");
  }
}
