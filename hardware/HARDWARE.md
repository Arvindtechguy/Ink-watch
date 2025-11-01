# Ink-watch Hardware Configuration

## Required Components

### Core Components
1. **Microcontroller**: Arduino Nano / Pro Mini / ESP32
   - Recommended: Arduino Nano (ATmega328P) for basic version
   - Alternative: ESP32 for Bluetooth/WiFi features

2. **E-Ink Display**: 1.54" - 2.13" E-Paper Display
   - Waveshare 1.54" e-Paper Module (200x200)
   - Waveshare 2.13" e-Paper Module (250x122)
   - Adafruit 1.54" Monochrome eInk Display

3. **Real-Time Clock (RTC)**: DS3231 or DS1307
   - DS3231: Higher accuracy, built-in temperature sensor
   - DS1307: Basic RTC functionality

4. **Battery**: 3.7V Li-Po Battery (400-1000mAh)
   - Recommended: 500mAh for compact size

5. **Power Management**:
   - TP4056 Li-Po Charging Module
   - AMS1117-3.3 Voltage Regulator (if using 5V Arduino)
   - Schottky diode for power switching

### Input Components
6. **Buttons**: 4x Tactile Push Buttons
   - Up, Down, Select, Back navigation

7. **Battery Monitoring**: Voltage divider circuit
   - 2x 10kΩ resistors for voltage sensing

### Optional Components
8. **Vibration Motor**: For notifications/alarms
9. **Buzzer**: Piezo buzzer for sound
10. **Accelerometer**: For gesture control (MPU6050)

## Pin Connections

### E-Ink Display (SPI)
```
Display Pin  -> Arduino Pin
VCC         -> 3.3V
GND         -> GND
DIN (MOSI)  -> D11 (MOSI)
CLK (SCK)   -> D13 (SCK)
CS          -> D10
DC          -> D9
RST         -> D8
BUSY        -> D7
```

### RTC Module (I2C)
```
RTC Pin     -> Arduino Pin
VCC         -> 5V (or 3.3V for DS3231)
GND         -> GND
SDA         -> A4 (SDA)
SCL         -> A5 (SCL)
```

### Control Buttons
```
Button      -> Arduino Pin
UP          -> D2 (with 10kΩ pull-up)
DOWN        -> D3 (with 10kΩ pull-up)
SELECT      -> D4 (with 10kΩ pull-up)
BACK        -> D5 (with 10kΩ pull-up)
```

### Battery Monitor
```
Battery +   -> Voltage Divider -> A0
(through 2x 10kΩ resistors to measure voltage)
```

## Power Specifications

- **Operating Voltage**: 3.3V - 5V (depending on Arduino model)
- **Display Power**: ~5-15mA during refresh, <1mA sleep
- **Arduino Power**: ~20mA active, ~5mA sleep
- **Total Active**: ~40-60mA
- **Sleep Mode**: <10mA
- **Expected Battery Life**: 
  - 500mAh battery: ~12-24 hours active use
  - With proper sleep mode: 2-5 days

## Circuit Diagram

```
                    +----------------+
                    |   Li-Po 3.7V   |
                    |    Battery     |
                    +-------+--------+
                            |
                    +-------v--------+
                    |    TP4056      |
                    | Charge Module  |
                    +-------+--------+
                            |
                    +-------v--------+
                    |   AMS1117-3.3  |
                    | (if needed)    |
                    +-------+--------+
                            |
                    +-------v--------+
                    |   Arduino      |
                    |   Nano/Pro     |
                    +-------+--------+
                            |
          +-----------------+-----------------+
          |                 |                 |
    +-----v-----+     +-----v-----+     +-----v-----+
    | E-Ink     |     | RTC       |     | Buttons   |
    | Display   |     | DS3231    |     | x4        |
    | (SPI)     |     | (I2C)     |     |           |
    +-----------+     +-----------+     +-----------+
```

## Assembly Tips

1. **Solder Headers**: Use low-profile headers to minimize thickness
2. **Wire Management**: Use thin flexible wires (28-30 AWG)
3. **Case Design**: 3D print a case or use a project box
4. **Display Protection**: Add an acrylic or glass front cover
5. **Battery Placement**: Position battery on the back for balance

## Power Optimization

1. Use `LowPower.h` library for sleep modes
2. Update display only when necessary (e-ink retains image without power)
3. Disable unused peripherals
4. Use RTC interrupt for waking from sleep
5. Implement auto-sleep after inactivity

## Safety Notes

⚠️ **Important Safety Information**:
- Always use proper Li-Po battery handling procedures
- Include overcurrent/overvoltage protection
- Never leave charging batteries unattended
- Use appropriate fuses and protection circuits
- Test all connections before connecting battery

## Firmware Upload

1. Connect Arduino via USB
2. Select correct board in Arduino IDE
3. Upload Ink-watch.ino sketch
4. Disconnect USB and connect battery
5. Watch should start automatically

## Troubleshooting

**Display not working**:
- Check SPI connections
- Verify 3.3V power supply
- Check display module compatibility

**Time not keeping**:
- Replace RTC battery (CR2032)
- Check I2C connections
- Verify RTC module is powered

**Battery draining quickly**:
- Enable sleep modes
- Reduce display refresh rate
- Check for power leaks in circuit
