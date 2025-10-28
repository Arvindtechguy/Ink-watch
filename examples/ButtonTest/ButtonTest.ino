/*
 * Button Test Example
 * 
 * Test your button connections
 * Open Serial Monitor to see button presses
 */

// Button pins - adjust to match your setup
#define BTN_SELECT 2
#define BTN_UP 3
#define BTN_DOWN 4
#define BTN_BACK 5

void setup() {
  Serial.begin(9600);
  Serial.println("Button Test");
  Serial.println("-----------");
  
  // Initialize button pins with internal pull-up
  pinMode(BTN_SELECT, INPUT_PULLUP);
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_BACK, INPUT_PULLUP);
  
  Serial.println("Buttons initialized");
  Serial.println("Press buttons to test...");
  Serial.println();
}

void loop() {
  static bool lastSelect = HIGH;
  static bool lastUp = HIGH;
  static bool lastDown = HIGH;
  static bool lastBack = HIGH;
  
  // Read current button states
  bool btnSelect = digitalRead(BTN_SELECT);
  bool btnUp = digitalRead(BTN_UP);
  bool btnDown = digitalRead(BTN_DOWN);
  bool btnBack = digitalRead(BTN_BACK);
  
  // Detect button press (transition from HIGH to LOW)
  if (btnSelect == LOW && lastSelect == HIGH) {
    Serial.println("SELECT button pressed!");
    delay(200); // Simple debounce
  }
  
  if (btnUp == LOW && lastUp == HIGH) {
    Serial.println("UP button pressed!");
    delay(200);
  }
  
  if (btnDown == LOW && lastDown == HIGH) {
    Serial.println("DOWN button pressed!");
    delay(200);
  }
  
  if (btnBack == LOW && lastBack == HIGH) {
    Serial.println("BACK button pressed!");
    delay(200);
  }
  
  // Save states
  lastSelect = btnSelect;
  lastUp = btnUp;
  lastDown = btnDown;
  lastBack = btnBack;
  
  delay(10);
}
