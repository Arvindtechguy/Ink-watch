# Bill of Materials (BOM)

## Components List for Ink-watch

### Core Electronics

| Component | Specification | Quantity | Est. Price (USD) | Notes |
|-----------|--------------|----------|------------------|-------|
| Arduino Nano | ATmega328P, 5V/16MHz | 1 | $3-5 | Or compatible clone |
| E-Ink Display | 1.54" 200x200, SPI | 1 | $10-15 | Waveshare or compatible |
| RTC Module | DS3231, I2C | 1 | $1-3 | With CR2032 battery |
| Li-Po Battery | 3.7V 500mAh | 1 | $3-5 | JST connector |
| TP4056 Module | Li-Po charging | 1 | $0.50-1 | With protection |
| Voltage Regulator | AMS1117-3.3 | 1 | $0.20-0.50 | If needed for 3.3V |

### Input Components

| Component | Specification | Quantity | Est. Price (USD) | Notes |
|-----------|--------------|----------|------------------|-------|
| Tactile Buttons | 6x6mm, 4-pin | 4 | $0.10 each | Total: $0.40 |
| Resistors | 10kΩ, 1/4W | 6 | $0.01 each | Pull-ups and divider |
| Schottky Diode | 1N5817 | 1 | $0.10 | Power protection |

### Optional Components

| Component | Specification | Quantity | Est. Price (USD) | Notes |
|-----------|--------------|----------|------------------|-------|
| Vibration Motor | 3V coin type | 1 | $1-2 | For notifications |
| Buzzer | Piezo 5V | 1 | $0.50 | For alarms/sounds |
| Accelerometer | MPU6050, I2C | 1 | $2-4 | For gestures |
| Switch | Slide/Toggle SPDT | 1 | $0.50 | Power switch |

### Mechanical & Misc

| Component | Specification | Quantity | Est. Price (USD) | Notes |
|-----------|--------------|----------|------------------|-------|
| PCB | Custom or prototype board | 1 | $2-5 | Or breadboard initially |
| Wire | 28-30 AWG | As needed | $2-3 | Multiple colors |
| Heat Shrink Tubing | Assorted sizes | As needed | $1-2 | For wire protection |
| Screws & Standoffs | M2 or M2.5 | 4-8 | $1-2 | Case assembly |
| Acrylic Sheet | 2mm clear | 1 piece | $2-3 | Display cover |

## Total Cost Estimate

- **Minimum Build** (without optional components): ~$25-35
- **Full Build** (with all optional components): ~$35-50
- **Enclosure** (3D printed or custom): $5-15 additional

## Where to Buy

### Online Retailers
- **AliExpress**: Best prices, longer shipping
- **Amazon**: Fast shipping, higher prices
- **eBay**: Mixed, good for finding deals
- **Adafruit/SparkFun**: Quality components, US-based
- **Mouser/DigiKey**: Professional components

### Local Options
- Electronics hobby stores
- University electronics labs
- Maker spaces and hackerspaces

## Alternative Components

### Microcontroller Options
1. **Arduino Pro Mini** (3.3V version) - More compact
2. **ESP32** - WiFi/Bluetooth capability
3. **ESP8266** - WiFi only, cheaper
4. **Teensy** - More powerful, smaller

### Display Options
1. **Waveshare 1.54" V2** (200x200) - Best balance
2. **Waveshare 2.13" V2** (250x122) - Wider display
3. **Adafruit 1.54"** - Better support, higher price
4. **Good Display** - Various sizes

### RTC Options
1. **DS3231** - ±2ppm accuracy, temperature compensated
2. **DS1307** - Basic, ±1min/month drift
3. **PCF8523** - Low power alternative

### Battery Options
1. **500mAh** - Best for compact build
2. **1000mAh** - Longer runtime
3. **400mAh** - Ultra-compact
4. **18650 Li-Ion** - Much longer runtime, larger size

## Tools Needed

### Essential
- Soldering iron (temperature controlled)
- Solder (lead-free or 60/40)
- Wire strippers
- Side cutters
- Multimeter
- USB cable (for Arduino)

### Recommended
- Helping hands/PCB holder
- Desoldering pump or wick
- Hot glue gun
- Heat gun (for heat shrink)
- 3D printer (for case)

### Software
- Arduino IDE (free)
- Fritzing (circuit diagrams, optional)
- Fusion 360 or FreeCAD (case design, optional)

## Assembly Time

- **Breadboard Prototype**: 2-4 hours
- **Soldered Assembly**: 4-8 hours
- **Case Design & 3D Printing**: 4-12 hours
- **Software Setup & Testing**: 2-4 hours
- **Total Project Time**: 12-28 hours

## Notes

1. Prices are approximate and vary by region and supplier
2. Buy extra components for mistakes/testing
3. Consider starter kits if new to Arduino
4. Check component compatibility before ordering
5. Verify pin voltages (3.3V vs 5V) for your setup
6. Some components may have minimum order quantities

## Power Budget

| Component | Active Current | Sleep Current |
|-----------|---------------|---------------|
| Arduino Nano | ~20mA | ~5mA |
| E-Ink Display | ~10mA (refresh) | <0.1mA |
| RTC Module | ~0.5mA | ~0.5mA |
| LED (if used) | ~5-20mA | 0mA |
| **Total** | ~35-50mA | ~6mA |

With a 500mAh battery:
- **Active use**: ~10-14 hours
- **Sleep mode**: ~3-4 days
- **Mixed use**: ~1-2 days

## Sustainability Notes

- Consider rechargeable batteries
- Recycle electronic components properly
- Use lead-free solder when possible
- 3D print with recyclable materials (PLA)
- Reuse components from old electronics
