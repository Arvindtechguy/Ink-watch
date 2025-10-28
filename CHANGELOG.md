# Changelog

All notable changes to the Ink-watch project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Future Features
- RTC library integration for accurate timekeeping
- Alarm and timer functionality
- Multiple watch faces
- Weather display (with WiFi module)
- Bluetooth notifications
- Step counter with accelerometer
- More games (Tetris, Breakout)
- OTA updates for ESP32
- Custom font support
- Power saving optimizations

## [0.1.0] - 2025-10-28

### Added
- Initial project structure
- Main Arduino sketch (`Ink-watch.ino`)
- E-ink display driver abstraction (`eink_display.h`)
- Snake game implementation (`snake_game.h`)
- Pong game implementation (`pong_game.h`)
- Menu system with navigation
- Basic clock functionality
- Battery monitoring
- Button input handling with debouncing
- Configuration template system
- Hardware documentation
  - Circuit diagrams
  - Pin connections
  - Bill of Materials (BOM)
  - Component specifications
- Comprehensive README
- Getting Started guide
- Example sketches:
  - BasicClock - Minimal clock example
  - TestButtons - Button testing utility
  - SnakeDemo - Standalone Snake game
- Contributing guidelines
- MIT License
- .gitignore for Arduino projects

### Features

#### Clock
- 24-hour time display
- Software-based timekeeping
- Serial monitor output
- Menu navigation

#### Games
- **Snake**: Classic snake game with score tracking
  - Grid-based movement
  - Food collection
  - Collision detection
  - Score system
- **Pong**: Single-player pong vs AI
  - Paddle control
  - AI opponent with adjustable difficulty
  - Score tracking
  - Ball physics

#### Display
- E-ink display support framework
- Basic graphics primitives
  - Pixel drawing
  - Line drawing
  - Rectangle drawing
  - Circle drawing
- Frame buffer management
- Display sleep mode for power saving

#### Power Management
- Battery voltage monitoring
- Sleep mode framework
- Low power design considerations

#### User Interface
- Four-button navigation (Up, Down, Select, Back)
- Menu system with multiple screens
- Button debouncing
- State machine for screen management

### Documentation
- Detailed hardware assembly guide
- Component list with pricing
- Pin connection diagrams
- Power specifications
- Troubleshooting guide
- Example code
- API reference (basic)

### Hardware Support
- Arduino Nano/Pro Mini
- ESP32 (compatible)
- Waveshare e-Paper displays
- Adafruit eInk displays
- DS3231/DS1307 RTC modules
- Li-Po battery with charging circuit

## [0.0.1] - 2025-10-28

### Added
- Repository initialization
- Basic README
- MIT License

---

## Version History Summary

- **0.1.0** - First functional release with core features
- **0.0.1** - Initial repository setup

## Notes

### Known Issues
- Display driver is a placeholder and needs specific library integration
- RTC functionality requires RTClib or similar library
- No actual hardware testing yet (requires physical components)
- Games display only on serial monitor (need display integration)
- Time doesn't persist across power cycles (needs RTC)

### Breaking Changes
None yet - first release

### Deprecations
None yet

### Security
No known security issues

## Links
- [Repository](https://github.com/Arvindtechguy/Ink-watch)
- [Issues](https://github.com/Arvindtechguy/Ink-watch/issues)
- [Pull Requests](https://github.com/Arvindtechguy/Ink-watch/pulls)

---

**Legend:**
- `Added` - New features
- `Changed` - Changes in existing functionality
- `Deprecated` - Soon-to-be removed features
- `Removed` - Removed features
- `Fixed` - Bug fixes
- `Security` - Security fixes
