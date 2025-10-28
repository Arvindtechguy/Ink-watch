# Examples

This folder contains test sketches to help you verify individual components before uploading the full Ink-watch sketch.

## Available Examples

### 1. DisplayTest
**Purpose**: Test e-ink display connection  
**What it does**: Initializes display pins and monitors BUSY pin  
**Use when**: First connecting your e-ink display  

**How to use**:
1. Open `DisplayTest/DisplayTest.ino` in Arduino IDE
2. Adjust pin definitions if needed
3. Upload to Arduino
4. Open Serial Monitor (9600 baud)
5. Check BUSY pin state changes

### 2. ButtonTest
**Purpose**: Test button connections  
**What it does**: Detects and reports button presses  
**Use when**: Wiring up buttons  

**How to use**:
1. Open `ButtonTest/ButtonTest.ino` in Arduino IDE
2. Adjust pin definitions if needed
3. Upload to Arduino
4. Open Serial Monitor (9600 baud)
5. Press each button and verify it's detected

### 3. RTCTest
**Purpose**: Test RTC module I2C connection  
**What it does**: Scans I2C bus for RTC module  
**Use when**: Connecting RTC module  

**How to use**:
1. Open `RTCTest/RTCTest.ino` in Arduino IDE
2. Upload to Arduino
3. Open Serial Monitor (9600 baud)
4. Verify RTC is found at address 0x68

## Testing Order

For best results, test components in this order:

1. **Buttons** (ButtonTest)
   - Simplest to test
   - No external libraries needed
   - Verifies basic I/O

2. **RTC** (RTCTest)
   - Tests I2C communication
   - Verifies Wire library works
   - Confirms RTC addressing

3. **Display** (DisplayTest)
   - Most complex component
   - Tests SPI communication
   - May need library installation

4. **Full Watch** (InkWatch)
   - After all components verified
   - Upload main sketch
   - Enjoy your watch!

## Troubleshooting

### Button Test Issues
- **No response**: Check GND connections
- **Always pressed**: Check pull-up resistors enabled
- **Random presses**: Add physical debouncing (capacitor)

### RTC Test Issues
- **Device not found**: 
  - Verify I2C connections (A4/A5)
  - Check power connections
  - Try different I2C address
- **Wrong address**: Some modules use 0x57

### Display Test Issues
- **BUSY always HIGH/LOW**: 
  - Check display power
  - Verify BUSY pin connection
  - Consult display datasheet
- **No response**: 
  - Check SPI connections
  - Verify display model
  - Check voltage levels (3.3V vs 5V)

## Next Steps

After all tests pass:
1. Review main sketch configuration in `InkWatch/config.h`
2. Adjust any pin definitions that differ
3. Upload `InkWatch/InkWatch.ino`
4. Set the time (see USER_MANUAL.md)
5. Enjoy your Ink-watch!

## Additional Resources

- [HARDWARE_SETUP.md](../HARDWARE_SETUP.md) - Full assembly guide
- [WIRING.md](../WIRING.md) - Detailed wiring diagrams
- [USER_MANUAL.md](../USER_MANUAL.md) - How to use the watch
