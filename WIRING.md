# Wiring Diagram

## Connection Overview

```
                                    ┌─────────────────┐
                                    │   ARDUINO NANO  │
                                    │      /UNO       │
                                    └─────────────────┘
                                            │
        ┌───────────────────────────────────┼───────────────────────────────────┐
        │                                   │                                   │
        │                                   │                                   │
┌───────▼────────┐              ┌───────────▼────────┐              ┌──────────▼──────┐
│  E-INK DISPLAY │              │    RTC MODULE      │              │     BUTTONS     │
│   (SPI Mode)   │              │   (I2C - DS3231)   │              │                 │
├────────────────┤              ├────────────────────┤              ├─────────────────┤
│ VCC → 3.3V     │              │ VCC → 5V           │              │ SELECT → D2     │
│ GND → GND      │              │ GND → GND          │              │ UP     → D3     │
│ DIN → D11      │              │ SDA → A4           │              │ DOWN   → D4     │
│ CLK → D13      │              │ SCL → A5           │              │ BACK   → D5     │
│ CS  → D10      │              └────────────────────┘              │                 │
│ DC  → D9       │                                                  │ (All buttons    │
│ RST → D8       │                                                  │  connect to     │
│ BUSY→ D7       │                                                  │  GND on other   │
└────────────────┘                                                  │  terminal)      │
                                                                    └─────────────────┘

                        ┌──────────────────────┐
                        │   POWER MANAGEMENT   │
                        ├──────────────────────┤
                        │ 3.7V LiPo Battery    │
                        │        ↓             │
                        │   TP4056 Module      │
                        │        ↓             │
                        │   Power Switch       │
                        │        ↓             │
                        │   Arduino VIN/5V     │
                        └──────────────────────┘
```

## Detailed Pin Mapping

### Arduino Digital Pins
```
D2  - Button SELECT (INPUT_PULLUP)
D3  - Button UP (INPUT_PULLUP)
D4  - Button DOWN (INPUT_PULLUP)
D5  - Button BACK (INPUT_PULLUP)
D7  - E-ink BUSY (INPUT)
D8  - E-ink RST (OUTPUT)
D9  - E-ink DC (OUTPUT)
D10 - E-ink CS (OUTPUT)
D11 - E-ink DIN/MOSI (OUTPUT - SPI)
D13 - E-ink CLK/SCK (OUTPUT - SPI)
```

### Arduino Analog Pins
```
A4  - RTC SDA (I2C)
A5  - RTC SCL (I2C)
```

### Power Connections
```
VIN/5V - From battery management (5V regulated)
3.3V   - To e-ink display VCC
GND    - Common ground for all components
```

## Component Details

### E-ink Display Module
- **Type**: 2.9" or 2.13" SPI e-ink display
- **Resolution**: 128x250 or similar
- **Interface**: 4-wire SPI
- **Voltage**: 3.3V logic (use level shifter if needed with 5V Arduino)
- **Pins**: VCC, GND, DIN, CLK, CS, DC, RST, BUSY

### RTC Module (DS3231)
- **Interface**: I2C
- **Address**: 0x68 (default)
- **Voltage**: 3.3V - 5V
- **Battery**: CR2032 for backup
- **Accuracy**: ±2ppm (very accurate)

### Buttons
- **Type**: Tactile push buttons
- **Configuration**: Active LOW with internal pull-up
- **Quantity**: 4 (SELECT, UP, DOWN, BACK)
- **Debouncing**: Software-based (200ms)

### Power Supply
- **Battery**: 3.7V LiPo (500-1000mAh recommended)
- **Charger**: TP4056 USB charging module
- **Switch**: SPST toggle or slide switch
- **Voltage**: 3.7V battery → 5V regulated for Arduino

## Assembly Notes

### Critical Connections
1. **Common Ground**: Ensure all GND connections share a common ground
2. **Power Voltage**: E-ink display typically requires 3.3V (check datasheet)
3. **Pull-ups**: Buttons use internal pull-up resistors in code
4. **I2C Pull-ups**: RTC module usually has built-in pull-up resistors

### Level Shifting
If using 5V Arduino with 3.3V e-ink display:
- Use bidirectional level shifter for SPI signals
- Or use 3.3V Arduino (Pro Mini, ESP32)

### Power Considerations
- Arduino 3.3V pin has limited current (~50mA)
- Use external 3.3V regulator for display if needed
- Battery life depends on update frequency

## Testing Procedure

1. **Power Test**: 
   - Connect power without other components
   - Verify voltage levels with multimeter

2. **Display Test**:
   - Connect display
   - Upload basic display test sketch
   - Verify image appears on screen

3. **RTC Test**:
   - Connect RTC
   - Run I2C scanner to find device
   - Test time reading

4. **Button Test**:
   - Connect buttons one at a time
   - Use Serial monitor to verify readings
   - Test debouncing

5. **Integration Test**:
   - Connect all components
   - Upload full sketch
   - Test all features

## Troubleshooting Quick Reference

| Issue | Check |
|-------|-------|
| Display blank | Power voltage, SPI connections, RST pin |
| Display garbled | SPI clock speed, CS timing, display model |
| RTC not found | I2C connections (A4/A5), I2C address |
| Wrong time | RTC battery, I2C communication |
| Buttons stuck | Pull-up enabled, GND connection |
| No button response | Pin definitions in config.h, debounce delay |
| Short battery life | Update intervals, sleep mode, power circuit |

## Recommended Wire Gauges

- Power lines (VCC/GND): 22-24 AWG
- Signal lines (SPI/I2C/Buttons): 26-28 AWG
- Short connections (<10cm): 28-30 AWG

## Safety Checklist

- [ ] Battery has protection circuit
- [ ] No short circuits present
- [ ] Polarity correct on all components
- [ ] Voltage levels verified
- [ ] Proper insulation on exposed contacts
- [ ] Power switch functional
- [ ] Charging circuit tested

---

*Refer to individual component datasheets for specific details*
