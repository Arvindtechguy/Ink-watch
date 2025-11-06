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
  static unsigned long lastDebounceTime = 0;
  
  unsigned long currentTime = millis();
  
  // Only check buttons after debounce period
  if (currentTime - lastDebounceTime < 200) {
    return;
  }
  
  // Read current button states
  bool btnSelect = digitalRead(BTN_SELECT);
  bool btnUp = digitalRead(BTN_UP);
  bool btnDown = digitalRead(BTN_DOWN);
  bool btnBack = digitalRead(BTN_BACK);
  
  // Detect button press (transition from HIGH to LOW)
  if (btnSelect == LOW && lastSelect == HIGH) {
    Serial.println("SELECT button pressed!");
    lastDebounceTime = currentTime;
  }
  
  if (btnUp == LOW && lastUp == HIGH) {
    Serial.println("UP button pressed!");
    lastDebounceTime = currentTime;
  }
  
  if (btnDown == LOW && lastDown == HIGH) {
    Serial.println("DOWN button pressed!");
    lastDebounceTime = currentTime;
  }
  
  if (btnBack == LOW && lastBack == HIGH) {
    Serial.println("BACK button pressed!");
    lastDebounceTime = currentTime;
  }
  
  // Save states
  lastSelect = btnSelect;
  lastUp = btnUp;
  lastDown = btnDown;
  lastBack = btnBack;
  
  delay(10);
}
