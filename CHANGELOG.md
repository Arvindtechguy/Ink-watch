# Changelog

All notable changes to the Ink-watch project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Planned Features
- Button-based time setting interface
- Alarm and notification system
- Additional games (Tetris, Breakout)
- Stopwatch and timer functions
- Custom watch faces
- Bluetooth connectivity (ESP32 version)
- Step counter with accelerometer
- Temperature and weather display
- Sleep mode for power optimization

## [1.0.0] - 2025-10-28

### Added
- Initial release of Ink-watch
- Core watch functionality with Arduino support
- E-ink display driver with basic graphics primitives
  - Pixel, line, rectangle drawing
  - Character and string rendering
  - 5x7 bitmap font
  - Frame buffer management
- Real-time clock (RTC) support
  - Time and date display
  - Day of week tracking
  - Simulated timekeeping (for testing without RTC)
- Menu navigation system
  - 4-item menu with selection
  - Keyboard navigation support
  - Visual feedback for selected items
- Snake game
  - Classic snake gameplay
  - Food collection and scoring
  - Self-collision and wall detection
  - Game over and restart
- Pong game
  - Single-player paddle game
  - Ball physics and bouncing
  - Progressive difficulty
  - Score tracking
- Settings screen
  - System information display
  - Version information
- Button input handling
  - 4-button interface (SELECT, UP, DOWN, BACK)
  - Software debouncing
  - Pull-up resistor support
- Configuration system
  - Centralized pin definitions
  - Adjustable timing constants
  - Display dimension settings
- Comprehensive documentation
  - README with project overview
  - Hardware setup guide
  - Wiring diagrams and schematics
  - User manual
  - Contributing guidelines
- Example sketches
  - Display test
  - Button test
  - RTC I2C scanner
- Power management considerations
  - Optimized update intervals
  - Low-power friendly design

### Technical Details
- Display buffer: 4000 bytes (128x250 @ 1bpp)
- Update intervals:
  - Clock: 60 seconds
  - Menu: 100ms
  - Games: 200ms
- Button debounce: 200ms
- Supported boards: Arduino Nano, Uno, ESP32
- Interfaces: SPI (display), I2C (RTC), GPIO (buttons)

### Known Limitations
- Time must be set via code modification (no UI yet)
- Display driver is generic (may need tuning for specific models)
- Games optimized for 128x250 display only
- No actual e-ink controller communication (requires library integration)
- Simulated RTC (needs RTClib for actual hardware)

## Version History

### Version Numbering
- **Major version** (X.0.0): Breaking changes, major new features
- **Minor version** (0.X.0): New features, backwards compatible
- **Patch version** (0.0.X): Bug fixes, small improvements

---

[Unreleased]: https://github.com/Arvindtechguy/Ink-watch/compare/v1.0.0...HEAD
[1.0.0]: https://github.com/Arvindtechguy/Ink-watch/releases/tag/v1.0.0
