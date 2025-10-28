# Ink-watch ⌚

An Arduino-based smartwatch with e-ink display featuring a real-time clock, games, and low power consumption!

## Features ✨

- **🕐 Real-Time Clock**: Digital clock with date display
- **🎮 Games**: 
  - Snake - Classic snake game with scoring
  - Pong - Single-player paddle game
- **⚡ Low Power**: E-ink display for minimal battery consumption
- **🎛️ Menu System**: Easy navigation with 4 buttons
- **📱 Settings**: Configuration and system information

## Project Status

🚧 **Work in Progress** - This is an active development project!

Current status:
- ✅ Core functionality implemented
- ✅ Clock display with RTC support
- ✅ Two playable games (Snake & Pong)
- ✅ Menu navigation system
- ✅ Basic display driver
- 🔄 Hardware integration testing in progress
- 📝 Time setting UI (planned)
- 📝 Additional games (planned)

## Quick Start

### Hardware Requirements

- Arduino board (Nano/Uno/ESP32)
- E-ink display module (2.9" recommended)
- RTC module (DS3231 or DS1307)
- 4 push buttons
- 3.7V LiPo battery + TP4056 charger
- Connecting wires

See [HARDWARE_SETUP.md](HARDWARE_SETUP.md) for detailed assembly instructions.

### Software Setup

1. **Install Arduino IDE** (1.8.x or newer)

2. **Install Required Libraries**:
   - Adafruit GFX Library
   - Adafruit EPD
   - RTClib

3. **Upload the Sketch**:
   ```bash
   # Open InkWatch/InkWatch.ino in Arduino IDE
   # Select your board and port
   # Click Upload
   ```

4. **Configure Hardware**:
   - Edit `InkWatch/config.h` to match your pin connections
   - Adjust display dimensions if needed

## Documentation

- **[Hardware Setup Guide](HARDWARE_SETUP.md)** - Assembly instructions and wiring diagrams
- **[User Manual](USER_MANUAL.md)** - How to use the watch and play games

## File Structure

```
Ink-watch/
├── InkWatch/              # Arduino sketch folder
│   ├── InkWatch.ino       # Main sketch file
│   ├── config.h           # Hardware and system configuration
│   ├── display.h/cpp      # E-ink display driver
│   ├── rtc_time.h/cpp     # Real-time clock functions
│   ├── menu.h/cpp         # Menu navigation system
│   └── games.h/cpp        # Snake and Pong games
├── HARDWARE_SETUP.md      # Hardware assembly guide
├── USER_MANUAL.md         # User instructions
├── LICENSE                # License information
└── README.md              # This file
```

## Screenshots

*Note: E-ink displays show crisp black & white graphics with no backlight*

**Clock Display**: Shows time, date, and day of week  
**Menu**: Navigate between Clock, Games, and Settings  
**Snake Game**: Classic snake gameplay on e-ink  
**Pong Game**: Single-player pong with scoring  

## Customization

The modular code structure makes it easy to customize:

- **Add new games**: Implement in `games.cpp`
- **Modify display**: Edit graphics in `display.cpp`
- **Change timing**: Adjust intervals in `config.h`
- **Add features**: Extend the menu system in `menu.cpp`

## Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## Future Roadmap

- [ ] Button-based time setting
- [ ] Alarm and notification system
- [ ] Additional games (Tetris, Breakout)
- [ ] Stopwatch and timer functions
- [ ] Custom watch faces
- [ ] Bluetooth connectivity (ESP32 version)
- [ ] Step counter with accelerometer
- [ ] Temperature and weather display

## Known Issues

- Time setting currently requires code modification
- Display driver is generic (may need adjustment for specific e-ink models)
- Games optimized for 128x250 display (adjust for other sizes)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Arduino community for extensive libraries and support
- E-ink display manufacturers for documentation
- Contributors and testers

## Contact

For questions, suggestions, or issues:
- Open an issue on GitHub
- Submit a pull request
- Check existing documentation

---

**Made with ❤️ for the maker community**

*Enjoy your Ink-watch!*
