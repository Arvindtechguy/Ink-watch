# Frequently Asked Questions (FAQ)

## General Questions

### What is Ink-watch?
Ink-watch is an open-source DIY smartwatch project featuring an e-ink display and Arduino microcontroller. It includes a clock, games, and a menu-driven interface, designed for low power consumption and visibility in sunlight.

### Why e-ink display?
E-ink displays:
- Consume very little power (only during refresh)
- Are easily readable in bright sunlight
- Retain image without power
- Have a unique retro aesthetic
- Are perfect for battery-powered devices

### What can I do with Ink-watch?
- Tell time with a digital clock
- Play classic games (Snake, Pong)
- Monitor battery level
- Customize and add features
- Learn about Arduino programming
- Build a wearable device

## Hardware Questions

### What Arduino board should I use?
**Recommended options:**
1. **Arduino Nano** - Best balance of size and features
2. **Arduino Pro Mini** (3.3V) - Smaller, more compact
3. **ESP32** - If you want WiFi/Bluetooth (future features)

### Which e-ink display is best?
**Popular choices:**
- **Waveshare 1.54" V2** (200x200) - Best tested, good size
- **Waveshare 2.13" V2** (250x122) - Wider, good for wrist
- **Adafruit 1.54"** - Better support, but more expensive

### Do I need an RTC module?
Not required to start, but highly recommended. Without RTC:
- Time resets when powered off
- Manual time adjustment needed

With RTC (DS3231/DS1307):
- Keeps accurate time
- Battery backup (CR2032)
- Wake from sleep support

### How long does the battery last?
Depends on usage:
- **Active use**: 10-14 hours (500mAh battery)
- **With sleep mode**: 2-5 days
- **Standby**: 1-2 weeks

Tips to extend battery life:
- Implement sleep modes
- Reduce display refresh rate
- Use partial refresh when possible
- Disable unused features

### Can I use rechargeable batteries?
Yes! The design uses:
- 3.7V Li-Po rechargeable battery
- TP4056 charging module
- Charge via USB while wearing

### What's the total cost?
- **Minimum build**: $25-35 (basic components)
- **Full build**: $35-50 (with optional features)
- **With enclosure**: +$5-15 (3D printed case)

See [BOM.md](hardware/BOM.md) for detailed pricing.

## Software Questions

### What programming experience do I need?
- **Beginner**: Can upload and use as-is
- **Intermediate**: Can customize settings and features
- **Advanced**: Can add new games and functionality

Basic Arduino knowledge helpful but not required.

### Which Arduino IDE version?
- Arduino IDE 1.8.x or newer
- Arduino IDE 2.x also works
- Arduino CLI for command-line enthusiasts

### What libraries do I need?
**Built-in (included with Arduino):**
- Wire (I2C)
- SPI

**Optional (install if needed):**
- RTClib (for RTC support)
- Adafruit_GFX (for graphics)
- Display-specific library (depends on your e-ink module)

### Can I customize the code?
Absolutely! The code is:
- Open source (MIT License)
- Well-commented
- Modular design
- Easy to extend

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

### How do I add more games?
1. Create a new `.h` file for your game
2. Implement standard game interface:
   ```cpp
   class YourGame {
     void reset();
     void update(unsigned long currentTime);
     void handleInput(int button);
     void draw();
   };
   ```
3. Add to menu system
4. Test and enjoy!

## Assembly Questions

### Can I build this on a breadboard first?
Yes! Highly recommended:
- Test components individually
- Verify connections
- Debug issues easily
- Make changes without desoldering

### Do I need soldering skills?
- **Breadboard prototype**: No soldering needed
- **Permanent build**: Basic soldering required
- **Advanced build**: SMD soldering for compact design

### What tools do I need?
**Essential:**
- Soldering iron
- Wire cutters/strippers
- Multimeter
- USB cable

**Nice to have:**
- Helping hands
- 3D printer (for case)
- Heat gun (for heat shrink)

### Is this suitable for beginners?
Yes, with some patience:
- Start with breadboard
- Follow step-by-step guide
- Test each component
- Ask for help in issues/forums

## Display Questions

### Why isn't my display working?
**Common issues:**
1. **Wrong voltage** - Most e-ink displays need 3.3V, not 5V
2. **Incorrect wiring** - Double-check SPI connections
3. **Wrong display type** - Configure correct model in code
4. **Busy pin** - Some displays need BUSY pin connected

### Display shows garbage or nothing?
- Verify SPI connections (MOSI, SCK, CS, DC, RST)
- Check power supply (stable 3.3V)
- Confirm display type in `eink_display.h`
- Try display manufacturer's test code

### How do I speed up the display?
E-ink displays are inherently slow:
- Full refresh: 2-3 seconds
- Partial refresh: faster but limited (if supported)
- Update only when necessary
- Use static displays when possible

### Can I use OLED instead of e-ink?
Yes, but you'll lose e-ink benefits:
- Much higher power consumption
- Poor sunlight visibility
- Needs constant power for display

Code modifications needed for OLED libraries.

## Power Questions

### How do I charge the battery?
1. Connect USB to TP4056 module
2. Red LED indicates charging
3. Blue/Green LED indicates full
4. Disconnect when charged

**Safety:** Use proper Li-Po charging practices.

### Why is my battery draining fast?
Possible causes:
- Sleep mode not implemented
- Display refreshing too often
- Power-hungry components
- Battery worn out

### Can I use AA batteries?
Possible but not recommended:
- Need 3x AA for ~4.5V
- Bulkier design
- No recharging (unless rechargeable AA)
- Better: Li-Po for compact design

## Troubleshooting

### Code won't compile
- Install required libraries
- Check Arduino IDE version
- Verify board selection
- Check for typos in modifications

### Buttons don't work
- Check wiring (buttons to GND)
- Verify INPUT_PULLUP is set
- Test with multimeter
- Check pin numbers in code

### Time doesn't keep
- Need RTC module
- RTC battery (CR2032) may be dead
- Check I2C connections (SDA/SCL)

### Upload fails
- Wrong COM port selected
- USB cable is power-only (needs data lines)
- Try "Old Bootloader" option
- Press reset button before upload

## Customization

### Can I change button functions?
Yes! Edit the button handling code in `Ink-watch.ino`:
```cpp
void handleUpButton() {
  // Your custom code
}
```

### Can I add WiFi?
Yes, if using ESP32:
- Weather data
- Time sync (NTP)
- Notifications
- OTA updates

### Can I add Bluetooth?
Yes, with ESP32 or separate BT module:
- Phone notifications
- Music control
- Remote configuration

### Can I make it smaller?
Yes:
- Use Arduino Pro Mini (smaller)
- Compact battery (400mAh)
- Custom PCB design
- Smaller display

## Safety

### Is it safe to wear?
Generally yes, but:
- Use proper Li-Po battery protection
- Don't overheat battery
- Ensure no exposed wires/solder
- Use proper case/enclosure

### Can it get wet?
Not by default (not waterproof):
- Keep away from water
- For water resistance: need proper sealing
- Consider conformal coating for PCB

### Battery safety?
**Important:**
- Never puncture Li-Po battery
- Don't short circuit
- Use protection circuit (TP4056 has it)
- Monitor for swelling
- Dispose properly if damaged

## Support

### Where can I get help?
1. Read [GETTING_STARTED.md](docs/GETTING_STARTED.md)
2. Check this FAQ
3. Search existing [GitHub Issues](https://github.com/Arvindtechguy/Ink-watch/issues)
4. Create new issue with details
5. Arduino forums for general Arduino questions

### How can I contribute?
See [CONTRIBUTING.md](CONTRIBUTING.md) for:
- Code contributions
- Bug reports
- Feature requests
- Documentation improvements

### Where can I share my build?
- GitHub Issues (show and tell)
- Arduino forums
- Reddit (r/arduino, r/DIY)
- Hackaday.io
- Social media with #Inkwatch

## Future Features

### What's planned?
See [CHANGELOG.md](CHANGELOG.md) for roadmap:
- Alarms and timers
- Weather display
- Notifications
- More games
- Custom watch faces
- Better power management

### Can I request features?
Yes! Create a GitHub issue:
- Describe the feature
- Explain use case
- Suggest implementation

### Will this support [X] display?
Probably! The code is designed to be modular. Most e-ink displays can be supported with appropriate driver implementation.

---

**Still have questions?**

Open an issue on GitHub with the "question" label, and we'll add it to this FAQ!
