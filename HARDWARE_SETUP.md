# Hardware Setup Guide

## Required Components

### Main Components
1. **Microcontroller**: Arduino Nano, Uno, or ESP32
2. **E-ink Display**: 
   - 2.9" or 2.13" e-ink display module
   - SPI interface
   - Examples: Waveshare 2.9" or GDEW029T5
3. **Real-Time Clock (RTC)**: 
   - DS3231 or DS1307 module
   - I2C interface
   - CR2032 battery for timekeeping
4. **Input Buttons**: 4 tactile push buttons
5. **Power Supply**:
   - 3.7V LiPo battery (500-1000mAh)
   - TP4056 charging module
   - Power switch

### Optional Components
- Boost/Buck converter for voltage regulation
- Vibration motor for notifications
- Buzzer for alarms

## Pin Connections

### E-ink Display (SPI)
```
Display Pin  ->  Arduino Pin
VCC          ->  3.3V
GND          ->  GND
DIN (MOSI)   ->  D11 (or hardware SPI MOSI)
CLK (SCK)    ->  D13 (or hardware SPI SCK)
CS           ->  D10
DC           ->  D9
RST          ->  D8
BUSY         ->  D7
```

### RTC Module (I2C)
```
RTC Pin      ->  Arduino Pin
VCC          ->  5V (or 3.3V depending on module)
GND          ->  GND
SDA          ->  A4 (or hardware I2C SDA)
SCL          ->  A5 (or hardware I2C SCL)
```

### Buttons
```
Button       ->  Arduino Pin
SELECT       ->  D2
UP           ->  D3
DOWN         ->  D4
BACK         ->  D5

Note: All buttons use internal pull-up resistors
Connect one side to the pin, other side to GND
```

## Assembly Instructions

1. **Solder Headers**: Attach headers to Arduino and modules
2. **Connect Display**: Wire the e-ink display following the pinout above
3. **Connect RTC**: Wire the RTC module using I2C pins
4. **Connect Buttons**: Wire buttons with one terminal to the designated pins and other to GND
5. **Power Circuit**: 
   - Connect battery to TP4056 charging module
   - Connect output to Arduino VIN or 5V pin
   - Add power switch in series
6. **Test**: Upload the sketch and verify all components work

## Software Setup

### Required Libraries
Install these libraries through Arduino IDE Library Manager:
- Adafruit GFX Library (for graphics primitives)
- Adafruit EPD (for e-ink display support)
- RTClib (for RTC support)

### Configuration
Edit `config.h` to match your hardware:
- Adjust pin definitions if you used different pins
- Set display dimensions for your specific e-ink screen
- Modify timing constants as needed

### Upload Sketch
1. Open `InkWatch.ino` in Arduino IDE
2. Select your board type (Tools > Board)
3. Select the correct COM port (Tools > Port)
4. Click Upload

## Troubleshooting

### Display Not Working
- Verify SPI connections
- Check voltage levels (most e-ink displays need 3.3V logic)
- Ensure CS, DC, RST, and BUSY pins are correctly connected
- Add level shifters if using 5V Arduino with 3.3V display

### RTC Not Keeping Time
- Check I2C connections (SDA and SCL)
- Verify RTC battery is installed and has charge
- Run I2C scanner sketch to verify address

### Buttons Not Responding
- Check that pull-up resistors are enabled in code
- Verify button connections to GND
- Test with multimeter in continuity mode

### Power Issues
- Ensure battery voltage is adequate (>3.5V for LiPo)
- Check all GND connections are common
- Verify voltage regulator output

## Power Optimization

For maximum battery life:
- E-ink displays only consume power during updates
- Use deep sleep mode between updates
- Reduce clock update frequency
- Optimize game refresh rates

## Next Steps

Once hardware is assembled and working:
1. Set the correct time using the Settings menu
2. Customize game difficulty in `games.cpp`
3. Add your own features and apps
4. Design and 3D print a case

## Safety Notes

⚠️ **Important Safety Guidelines**:
- Never short-circuit the battery
- Use appropriate fuse/protection
- Don't overcharge LiPo batteries
- Handle batteries with care
- Disconnect power when modifying circuit
