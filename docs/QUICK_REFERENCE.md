# Quick Reference Guide

## Pin Quick Reference

### E-Ink Display (SPI)
| Display | Arduino Pin |
|---------|-------------|
| VCC     | 3.3V        |
| GND     | GND         |
| DIN     | D11 (MOSI)  |
| CLK     | D13 (SCK)   |
| CS      | D10         |
| DC      | D9          |
| RST     | D8          |
| BUSY    | D7          |

### RTC Module (I2C)
| RTC     | Arduino Pin |
|---------|-------------|
| VCC     | 5V or 3.3V  |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

### Buttons
| Button  | Pin |
|---------|-----|
| UP      | D2  |
| DOWN    | D3  |
| SELECT  | D4  |
| BACK    | D5  |

### Battery
| Function | Connection |
|----------|------------|
| Monitor  | A0 (via voltage divider) |
| Power    | Via TP4056 to VIN/5V |

## Button Controls

### Main Menu
- **UP/DOWN**: Navigate menu
- **SELECT**: Enter selected menu
- **BACK**: Return to clock

### Snake Game
- **UP/DOWN**: Change direction
- **BACK**: Exit game
- **SELECT**: Restart (when game over)

### Pong Game
- **UP**: Move paddle up
- **DOWN**: Move paddle down
- **BACK**: Exit game
- **SELECT**: Restart (when game over)

## Menu Structure

```
Main Clock Display
  ↓ UP/DOWN
┌─────────────┐
│ > Clock     │ ← Default view
│   Games     │
│   Settings  │
│   Battery   │
└─────────────┘
      ↓ SELECT on Games
┌─────────────┐
│ Games Menu  │
│ 1. Snake    │
│ 2. Pong     │
└─────────────┘
```

## Common Commands

### Arduino IDE
```
Verify:  Ctrl+R / Cmd+R
Upload:  Ctrl+U / Cmd+U
Monitor: Ctrl+Shift+M / Cmd+Shift+M
```

### Serial Monitor
- Baud Rate: **9600**
- Shows debug output and game state

## Configuration Quick Edits

### Change Button Pins
Edit `Ink-watch.ino`:
```cpp
#define BUTTON_UP 2      // Change these
#define BUTTON_DOWN 3
#define BUTTON_SELECT 4
#define BUTTON_BACK 5
```

### Change Display Size
Edit `eink_display.h`:
```cpp
#define DISPLAY_WIDTH 200   // Your display width
#define DISPLAY_HEIGHT 200  // Your display height
```

### Adjust Game Speed
Edit `snake_game.h`:
```cpp
#define SNAKE_SPEED 300  // Lower = faster
```

Edit `pong_game.h`:
```cpp
#define AI_DIFFICULTY 3  // Higher = easier
```

## Troubleshooting Quick Fixes

| Problem | Quick Fix |
|---------|-----------|
| Won't upload | Try "Old Bootloader" in Tools menu |
| Display blank | Check 3.3V power, verify SPI pins |
| Buttons don't work | Check GND connections |
| Time resets | Need RTC module |
| Battery drains fast | Implement sleep mode |
| Compile error | Install Wire & SPI libraries |

## Power Consumption Guide

| State | Current | Duration (500mAh) |
|-------|---------|-------------------|
| Active with display refresh | ~40mA | ~12 hours |
| Active, no refresh | ~20mA | ~25 hours |
| Sleep mode | ~6mA | ~3 days |

## File Structure Quick Guide

```
Ink-watch/
├── Ink-watch/
│   ├── Ink-watch.ino       ← Main code (start here)
│   ├── snake_game.h        ← Snake game
│   ├── pong_game.h         ← Pong game
│   ├── eink_display.h      ← Display driver
│   └── config_template.h   ← Configuration options
├── examples/               ← Test examples
├── hardware/               ← Circuit diagrams, BOM
└── docs/                   ← Documentation
```

## Important Constants

### Clock
```cpp
hours   = 0-23  (24-hour format)
minutes = 0-59
seconds = 0-59
```

### Display
```cpp
DISPLAY_WIDTH  = 200 pixels (typical)
DISPLAY_HEIGHT = 200 pixels (typical)
```

### Games
```cpp
SNAKE_GRID_SIZE = 20x20
PONG_WIDTH      = 40
PONG_HEIGHT     = 20
```

## Voltage Reference

| Component | Voltage | Notes |
|-----------|---------|-------|
| Arduino Nano | 5V | Can regulate to 3.3V |
| E-Ink Display | 3.3V | **Important: not 5V!** |
| RTC Module | 5V or 3.3V | Check your module |
| Li-Po Battery | 3.7V nominal | 3.3-4.2V range |

## Default Settings

```cpp
DEBOUNCE_DELAY = 200ms
SLEEP_TIMEOUT = 30000ms (30s)
DEBUG_BAUD = 9600
BATTERY_MIN = 3.3V
BATTERY_MAX = 4.2V
```

## Useful Links Quick Access

- **Repository**: github.com/Arvindtechguy/Ink-watch
- **Issues**: github.com/Arvindtechguy/Ink-watch/issues
- **Arduino Reference**: arduino.cc/reference
- **Getting Started**: [docs/GETTING_STARTED.md](GETTING_STARTED.md)
- **FAQ**: [docs/FAQ.md](FAQ.md)

## Emergency Contacts

### If Something Goes Wrong

1. **Upload fails**: Reset board, try again
2. **Smoke/heat**: DISCONNECT POWER IMMEDIATELY
3. **Battery swells**: Safely dispose, don't puncture
4. **Confused**: Check FAQ.md or create GitHub issue

## Quick Component Test

### Test Display
```cpp
// In setup()
display.init();
display.clearBuffer();
display.drawRect(0, 0, 50, 50, true, false);
display.update();
```

### Test Buttons
Upload `examples/TestButtons/TestButtons.ino`

### Test Clock
Upload `examples/BasicClock/BasicClock.ino`

### Test Snake
Upload `examples/SnakeDemo/SnakeDemo.ino`

## Version Info

- **Current Version**: 0.1.0
- **Last Updated**: 2025-10-28
- **Arduino IDE**: 1.8.x or newer
- **License**: MIT

---

**💡 Tip**: Keep this guide handy during assembly and programming!

**🔧 Quick Start**: Upload `examples/TestButtons` first to verify your hardware!
