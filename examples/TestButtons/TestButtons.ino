/*
 * Example: Button Test
 * 
 * This example helps you test all four buttons
 * and verify they are wired correctly.
 */

#define BUTTON_UP 2
#define BUTTON_DOWN 3
#define BUTTON_SELECT 4
#define BUTTON_BACK 5

void setup() {
  Serial.begin(9600);
  
  // Initialize all buttons
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_BACK, INPUT_PULLUP);
  
  Serial.println("=== Button Test ===");
  Serial.println("Press any button to test...");
  Serial.println("UP = Pin 2");
  Serial.println("DOWN = Pin 3");
  Serial.println("SELECT = Pin 4");
  Serial.println("BACK = Pin 5");
  Serial.println();
}

void loop() {
  // Check each button
  if (digitalRead(BUTTON_UP) == LOW) {
    Serial.println("UP button pressed!");
    delay(300);
  }
  
  if (digitalRead(BUTTON_DOWN) == LOW) {
    Serial.println("DOWN button pressed!");
    delay(300);
  }
  
  if (digitalRead(BUTTON_SELECT) == LOW) {
    Serial.println("SELECT button pressed!");
    delay(300);
  }
  
  if (digitalRead(BUTTON_BACK) == LOW) {
    Serial.println("BACK button pressed!");
    delay(300);
  }
  
  delay(50);
}
