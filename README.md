# Ink-watch ⌚

A smartwatch project featuring an e-ink display and Arduino integration. Low power consumption, high visibility in sunlight, and a retro gaming experience on your wrist!

![Status](https://img.shields.io/badge/status-work%20in%20progress-yellow)
![License](https://img.shields.io/badge/license-MIT-blue)
![Arduino](https://img.shields.io/badge/arduino-compatible-green)

## ✨ Features

### 🕐 Clock Functions
- Real-time clock display (hours, minutes, seconds)
- 12/24 hour format support
- RTC module integration (DS3231/DS1307)
- Battery-backed timekeeping

### 🎮 Games
- **Snake**: Classic snake game with score tracking
- **Pong**: Single-player pong against AI opponent
- Optimized for e-ink display refresh rates

### 📱 Additional Features
- Battery level monitoring
- Low power sleep modes
- Menu-driven navigation
- Button-based controls (Up, Down, Select, Back)
- Expandable architecture for future features

### 🔋 Power Management
- E-ink display for ultra-low power consumption
- Sleep mode support
- Battery monitoring
- Expected battery life: 2-5 days with proper sleep modes

## 🛠️ Hardware Requirements

### Essential Components
- Arduino Nano/Pro Mini or ESP32
- E-ink Display (1.54" - 2.13")
  - Waveshare e-Paper Module (recommended)
  - Adafruit eInk Display
- DS3231 or DS1307 RTC Module
- 3.7V Li-Po Battery (400-1000mAh)
- TP4056 Charging Module
- 4x Tactile Push Buttons
- AMS1117-3.3 Voltage Regulator (if needed)

### Optional Components
- Vibration motor for notifications
- Piezo buzzer
- MPU6050 accelerometer for gestures

See [Hardware Documentation](hardware/HARDWARE.md) for detailed wiring diagrams and assembly instructions.

## 📦 Installation

### Prerequisites
- Arduino IDE 1.8.x or newer
- Required Libraries (install via Library Manager):
  - Wire (built-in)
  - SPI (built-in)
  - Optional: RTClib, Adafruit_GFX, specific display library

### Upload Instructions

1. **Clone this repository**:
   ```bash
   git clone https://github.com/Arvindtechguy/Ink-watch.git
   cd Ink-watch
   ```

2. **Open the sketch**:
   - Open `Ink-watch/Ink-watch.ino` in Arduino IDE

3. **Configure for your display**:
   - Edit `eink_display.h` to match your display model
   - Uncomment the appropriate display definition

4. **Select your board**:
   - Tools → Board → Arduino Nano (or your board)
   - Tools → Port → Select your Arduino port

5. **Upload**:
   - Click Upload button or Ctrl+U
   - Wait for compilation and upload to complete

6. **Test**:
   - Open Serial Monitor (9600 baud) to see debug output
   - Use buttons to navigate menus

## 🎯 Usage

### Button Controls
- **UP**: Navigate up in menus / Move paddle up in Pong
- **DOWN**: Navigate down in menus / Move paddle down in Pong
- **SELECT**: Select menu item / Confirm action
- **BACK**: Return to main menu / Exit game

### Main Menu
1. **Clock**: View current time
2. **Games**: Access game menu
3. **Settings**: Configure watch settings
4. **Battery**: Check battery level

### Playing Games

#### Snake
- Use UP/DOWN/LEFT/RIGHT to control snake direction
- Eat food (*) to grow and score points
- Avoid walls and your own body
- Press BACK to exit

#### Pong
- Use UP/DOWN to move your paddle
- First to 5 points wins
- Press BACK to exit

## 🔧 Configuration

### Pin Configuration
Edit the pin definitions in `Ink-watch.ino`:
```cpp
#define BUTTON_UP 2
#define BUTTON_DOWN 3
#define BUTTON_SELECT 4
#define BUTTON_BACK 5
#define BATTERY_PIN A0
```

### Display Configuration
Edit `eink_display.h` for your specific display:
```cpp
#define DISPLAY_WIDTH 200
#define DISPLAY_HEIGHT 200
```

## 📁 Project Structure

```
Ink-watch/
├── Ink-watch/
│   ├── Ink-watch.ino       # Main Arduino sketch
│   ├── snake_game.h        # Snake game implementation
│   ├── pong_game.h         # Pong game implementation
│   └── eink_display.h      # E-ink display driver
├── hardware/
│   └── HARDWARE.md         # Hardware documentation
├── docs/
│   └── API.md              # API documentation (future)
├── examples/
│   └── ...                 # Example sketches (future)
├── LICENSE
└── README.md
```

## 🚀 Future Enhancements

- [ ] Weather display (with WiFi module)
- [ ] Notification support (Bluetooth)
- [ ] More games (Tetris, Breakout)
- [ ] Alarm and timer functions
- [ ] Step counter (with accelerometer)
- [ ] Custom watch faces
- [ ] Data logging
- [ ] OTA updates (ESP32)

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- E-ink display drivers inspired by Waveshare and Adafruit libraries
- Game implementations based on classic arcade games
- Arduino community for support and inspiration

## 📧 Contact

Project Link: [https://github.com/Arvindtechguy/Ink-watch](https://github.com/Arvindtechguy/Ink-watch)

## ⚠️ Disclaimer

This is a DIY project. Always follow proper safety procedures when working with electronics and batteries. The authors are not responsible for any damage or injury resulting from building or using this project.

---

**Status**: Work in Progress 🚧

This project is actively being developed. Features and documentation will be updated regularly.
