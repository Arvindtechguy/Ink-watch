# Getting Started with Ink-watch

This guide will help you build and program your Ink-watch from scratch.

## Table of Contents

1. [Hardware Assembly](#hardware-assembly)
2. [Software Setup](#software-setup)
3. [First Upload](#first-upload)
4. [Testing](#testing)
5. [Troubleshooting](#troubleshooting)

## Hardware Assembly

### Step 1: Gather Components

Refer to [BOM.md](../hardware/BOM.md) for the complete parts list.

### Step 2: Breadboard Prototype (Recommended First)

Before soldering, test everything on a breadboard:

1. **Power Setup**:
   - Connect Arduino to USB for power during testing
   - Battery will be added later

2. **E-Ink Display** (SPI connections):
   ```
   Display → Arduino
   VCC → 3.3V
   GND → GND
   DIN → D11 (MOSI)
   CLK → D13 (SCK)
   CS  → D10
   DC  → D9
   RST → D8
   BUSY → D7
   ```

3. **RTC Module** (I2C connections):
   ```
   RTC → Arduino
   VCC → 5V (or 3.3V for DS3231)
   GND → GND
   SDA → A4
   SCL → A5
   ```

4. **Buttons**:
   ```
   Each button:
   - One side to Arduino pin (2,3,4,5)
   - Other side to GND
   - Arduino pins set to INPUT_PULLUP
   ```

5. **Battery Monitor**:
   ```
   Battery + → 10kΩ → A0 → 10kΩ → GND
   ```

### Step 3: Initial Testing

Before connecting everything:

1. **Test Arduino**: Upload Blink example
2. **Test Display**: Run display test sketch
3. **Test Buttons**: Upload TestButtons example
4. **Test RTC**: Use RTClib examples

### Step 4: Final Assembly

Once breadboard works:

1. Design or use provided PCB layout
2. Solder components carefully
3. Double-check all connections
4. Test each component after soldering

## Software Setup

### Prerequisites

1. **Arduino IDE**:
   - Download from [arduino.cc](https://www.arduino.cc/en/software)
   - Install version 1.8.x or newer

2. **USB Drivers**:
   - Windows: Install CH340 driver if using clone Arduino
   - Mac/Linux: Usually works out of the box

### Installing Required Libraries

Open Arduino IDE and go to **Sketch → Include Library → Manage Libraries**:

Required (built-in, no installation needed):
- Wire
- SPI

Optional (install if using these features):
- **RTClib** by Adafruit (for RTC functionality)
- **Adafruit_GFX** (for graphics, if using Adafruit display)
- **GxEPD2** (for Waveshare displays, alternative)

### Downloading Ink-watch Code

**Option 1: Git Clone**
```bash
git clone https://github.com/Arvindtechguy/Ink-watch.git
cd Ink-watch
```

**Option 2: Download ZIP**
- Go to GitHub repository
- Click "Code" → "Download ZIP"
- Extract to your Arduino folder

## First Upload

### Step 1: Configure for Your Hardware

1. Open `Ink-watch/Ink-watch.ino` in Arduino IDE

2. **Verify Pin Definitions** (lines 17-21):
   ```cpp
   #define BUTTON_UP 2      // Change if using different pins
   #define BUTTON_DOWN 3
   #define BUTTON_SELECT 4
   #define BUTTON_BACK 5
   #define BATTERY_PIN A0
   ```

3. **Configure Display** in `eink_display.h`:
   ```cpp
   // Uncomment your display type:
   // #define WAVESHARE_1_54_V2
   // #define WAVESHARE_2_13_V2
   
   #define DISPLAY_WIDTH 200   // Adjust for your display
   #define DISPLAY_HEIGHT 200
   ```

### Step 2: Select Board and Port

1. **Tools → Board → Arduino Nano** (or your board)
2. **Tools → Processor → ATmega328P** (or ATmega328P Old Bootloader)
3. **Tools → Port → COMx** (Windows) or **/dev/ttyUSBx** (Linux/Mac)

### Step 3: Compile and Upload

1. Click **Verify** button (checkmark) to compile
2. Fix any errors (usually missing libraries)
3. Click **Upload** button (arrow) to program
4. Wait for "Done uploading" message

### Step 4: Monitor Serial Output

1. Open **Tools → Serial Monitor**
2. Set baud rate to **9600**
3. You should see:
   ```
   Ink-watch initialized!
   Display initialized
   Time: 12:00:00
   ```

## Testing

### Test 1: Buttons

1. Press each button
2. Serial monitor should show:
   - UP button: "UP"
   - DOWN button: "DOWN"
   - SELECT button: "SELECT"
   - BACK button: "BACK"

### Test 2: Clock

1. Watch serial monitor
2. Time should increment every second
3. Use UP/DOWN to navigate menu

### Test 3: Games

1. Press DOWN to navigate to "Games"
2. Press SELECT to enter game menu
3. Test Snake or Pong
4. Press BACK to return

### Test 4: Battery Monitor

1. Navigate to "Battery" menu
2. Check voltage reading
3. Should show approximately battery voltage

### Test 5: Display Update

1. If display is connected, it should show:
   - Clock face
   - Menu items
   - Game graphics
2. E-ink updates slowly (2-3 seconds)

## Troubleshooting

### Upload Fails

**Error: "avrdude: stk500_recv(): programmer is not responding"**

Solutions:
- Try other Processor option (Old Bootloader)
- Check USB cable (needs data lines, not just power)
- Press reset button just before upload starts
- Check COM port is correct

**Error: "Access denied" or "Permission denied"**

Solutions:
- Close other programs using the port
- Run Arduino IDE as administrator (Windows)
- Add user to dialout group (Linux): `sudo usermod -a -G dialout $USER`

### Display Issues

**Display stays blank:**
- Check power (3.3V, not 5V on some displays)
- Verify SPI connections
- Check CS/DC/RST pins match code
- Try display test example first

**Display shows garbage:**
- Wrong display type selected in code
- Incorrect SPI mode or speed
- Check data line connections

### Button Problems

**Buttons don't respond:**
- Check ground connections
- Verify pin numbers in code
- Test with multimeter in continuity mode
- May need external pull-up resistors

**Multiple buttons trigger:**
- Debouncing issue - already handled in code
- Check for shorts between button pins
- Verify ground connection

### RTC Issues

**Time not keeping:**
- RTC battery (CR2032) may be dead
- Check I2C connections (SDA/SCL)
- Run I2C scanner to detect RTC
- Install RTClib and set time

**Time wrong after power cycle:**
- Need to set RTC time initially
- Use RTClib examples to set time
- RTC should maintain time with coin battery

### Battery Problems

**Battery not charging:**
- Check TP4056 LED indicators
- Verify battery polarity
- Check USB power input
- TP4056 may be faulty

**Voltage reading incorrect:**
- Check voltage divider resistors (should be equal)
- Verify A0 connection
- Calibrate in code if needed

### General Debugging

1. **Use Serial Monitor**: Add Serial.println() for debugging
2. **Check Connections**: Verify each wire with multimeter
3. **Simplify**: Test components individually
4. **Power Issues**: Measure voltages at each component
5. **Ask for Help**: Post on Arduino forums with details

## Next Steps

Once everything works:

1. **Customize**: Modify clock faces, add features
2. **Optimize**: Implement sleep modes for battery life
3. **Enclosure**: Design and 3D print a case
4. **Enhance**: Add more games, weather, notifications

## Useful Commands

### Arduino CLI (optional)

```bash
# Compile
arduino-cli compile --fqbn arduino:avr:nano Ink-watch

# Upload
arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:nano Ink-watch

# Monitor
arduino-cli monitor -p /dev/ttyUSB0 -c baudrate=9600
```

## Resources

- [Arduino Reference](https://www.arduino.cc/reference/en/)
- [Waveshare Wiki](https://www.waveshare.com/wiki/Main_Page)
- [Adafruit Learning System](https://learn.adafruit.com/)
- [Arduino Forum](https://forum.arduino.cc/)

## Support

If you encounter issues not covered here:

1. Check existing GitHub Issues
2. Create new issue with:
   - Hardware details
   - Error messages
   - What you've tried
   - Photos if relevant

---

**Happy Making! 🎉**
