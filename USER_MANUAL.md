# User Manual

## Overview

Ink-watch is an Arduino-based smartwatch with an e-ink display that features:
- Real-time clock with date display
- Snake game
- Pong game
- Settings menu
- Low power consumption

## Button Controls

The watch has 4 buttons:
- **SELECT**: Confirm/Select options
- **UP**: Navigate up or move up in games
- **DOWN**: Navigate down or move down in games
- **BACK**: Return to previous screen or exit

## Using the Watch

### Clock Mode (Default)

When you start the watch, it displays:
- Current time (large digits)
- Day of week
- Date (DD/MM/YYYY)
- Instructions to access menu

Press **SELECT** to open the main menu.

### Main Menu

Navigate through menu items using **UP** and **DOWN** buttons:
1. Clock - Return to clock display
2. Snake Game - Play Snake
3. Pong Game - Play Pong
4. Settings - View settings

Press **SELECT** to choose an option.
Press **BACK** to return to clock.

## Games

### Snake Game

**Objective**: Eat food to grow longer without hitting walls or yourself

**Controls**:
- **UP**: Change direction to up (unless moving down)
- **DOWN**: Change direction to down (unless moving up)
- **SELECT**: Rotate direction clockwise (alternative control)
- **BACK**: Exit to menu

**Gameplay**:
- Snake moves continuously in current direction
- Eat the outlined square (food) to grow and score points
- Game ends if you hit a wall or yourself
- Press **SELECT** after game over to restart

**Scoring**: +10 points per food item

### Pong Game

**Objective**: Keep the ball in play as long as possible

**Controls**:
- **UP**: Move paddle up
- **DOWN**: Move paddle down
- **SELECT**: Restart after game over
- **BACK**: Exit to menu

**Gameplay**:
- Ball bounces off paddle, top, and bottom walls
- Ball speeds up each time you hit it
- Game ends if ball passes your paddle on the left
- Press **SELECT** after game over to restart

**Scoring**: +10 points per successful paddle hit

### Settings

View system information:
- Time configuration note
- Display type
- Firmware version

Press **BACK** to return to menu.

## Tips and Tricks

### Battery Life
- E-ink displays consume almost no power when static
- Clock updates once per minute to save power
- Turn off watch when not in use
- Games consume more power due to frequent updates

### Best Practices
- Let display fully refresh to avoid ghosting
- Avoid rapid button presses (debouncing built-in)
- Set correct time after battery replacement
- Keep firmware updated

### Display Care
- E-ink displays are fragile - handle with care
- Avoid pressing directly on the screen
- Keep away from extreme temperatures
- Don't bend or flex the display

## Customization

You can customize the watch by editing the source code:

### Change Update Intervals
Edit `config.h`:
- `CLOCK_UPDATE_INTERVAL` - How often clock updates (default: 60 seconds)
- `GAME_UPDATE_INTERVAL` - Game speed (default: 200ms)

### Modify Game Difficulty
Edit `games.cpp`:
- Snake speed: Adjust `GAME_UPDATE_INTERVAL`
- Pong ball speed: Modify `ballDX` and `ballDY` initial values
- Snake length limit: Change `SNAKE_MAX_LENGTH` in config.h

### Add New Features
The modular code structure makes it easy to add:
- New games
- Stopwatch/timer
- Alarm functionality
- Step counter (with accelerometer)
- Temperature display (with sensor)

## Troubleshooting

**Display not updating**:
- Check battery level
- Verify display connections
- Reset the watch

**Time is wrong**:
- Time resets when power is lost
- Install RTC battery (CR2032)
- Set time in Settings (future feature)

**Buttons not working**:
- Check button connections
- Verify pull-up resistors are enabled
- Clean button contacts

**Games too fast/slow**:
- Adjust `GAME_UPDATE_INTERVAL` in config.h
- Re-upload sketch after changes

## Technical Specifications

- **Display**: E-ink, 128x250 pixels (configurable)
- **Processor**: ATmega328P @ 16MHz (Arduino Nano/Uno)
- **Power**: 3.7V LiPo battery
- **Battery Life**: Several days to weeks (depending on usage)
- **Update Rate**: 
  - Clock: 1 minute
  - Games: ~5 FPS
- **Memory**: 
  - Flash: 32KB (program)
  - SRAM: 2KB (variables)
  - EEPROM: 1KB (settings storage - future use)

## Future Features

Planned additions:
- [ ] Time setting via buttons
- [ ] Alarms and notifications
- [ ] More games (Tetris, Breakout)
- [ ] Stopwatch and timer
- [ ] Customizable watch faces
- [ ] Bluetooth connectivity (ESP32)
- [ ] Sleep tracking
- [ ] Weather display

## Support

For issues, suggestions, or contributions:
- GitHub: https://github.com/Arvindtechguy/Ink-watch
- Open an issue for bugs or feature requests
- Pull requests welcome!

## License

See LICENSE file for details.

---

**Enjoy your Ink-watch!** 🕐
