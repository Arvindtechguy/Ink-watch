# Contributing to Ink-watch

Thank you for your interest in contributing to Ink-watch! This document provides guidelines for contributing to the project.

## Ways to Contribute

- 🐛 Report bugs
- ✨ Suggest new features
- 📝 Improve documentation
- 🎮 Add new games
- 🔧 Optimize code
- 🧪 Test on different hardware
- 💻 Submit code improvements

## Getting Started

1. **Fork the Repository**
   ```bash
   # Click the "Fork" button on GitHub
   git clone https://github.com/YOUR-USERNAME/Ink-watch.git
   cd Ink-watch
   ```

2. **Create a Branch**
   ```bash
   git checkout -b feature/your-feature-name
   # or
   git checkout -b bugfix/issue-description
   ```

3. **Make Your Changes**
   - Follow the coding style of the existing code
   - Test your changes thoroughly
   - Update documentation if needed

4. **Commit Your Changes**
   ```bash
   git add .
   git commit -m "Description of your changes"
   ```

5. **Push and Create Pull Request**
   ```bash
   git push origin feature/your-feature-name
   # Then create a Pull Request on GitHub
   ```

## Code Style Guidelines

### General Principles
- Write clear, readable code
- Add comments for complex logic
- Use descriptive variable names
- Keep functions focused and small

### Arduino/C++ Style
```cpp
// Use camelCase for variables and functions
int buttonState;
void updateDisplay();

// Use UPPER_CASE for constants
#define MAX_BUFFER_SIZE 100

// Use descriptive names
// Good
int snakeHeadX;
// Bad
int x;

// Add header comments for files
/*
 * Filename - Brief description
 */

// Add function comments for public functions
// Update the game state and redraw
void updateGame() {
  // Implementation
}
```

### File Organization
- Header files (.h): Declarations and interfaces
- Implementation files (.cpp): Function implementations
- Main sketch (.ino): Setup and main loop

## Adding New Features

### Adding a New Game

1. **Declare in games.h**
   ```cpp
   // Game state variables
   extern int myGameScore;
   
   // Game functions
   void initMyGame();
   void updateMyGame();
   void handleMyGameInput(bool up, bool down, bool select, bool back);
   ```

2. **Implement in games.cpp**
   ```cpp
   int myGameScore = 0;
   
   void initMyGame() {
     myGameScore = 0;
     // Initialize game state
   }
   
   void updateMyGame() {
     // Game logic and rendering
   }
   
   void handleMyGameInput(bool up, bool down, bool select, bool back) {
     // Handle user input
   }
   ```

3. **Add to Menu System**
   - Update `MENU_ITEMS` in config.h
   - Add menu item to `menuItems` array
   - Add case to `menuSelect()` in menu.cpp
   - Add case to `updateDisplay()` in InkWatch.ino

4. **Add State Enum**
   - Add `STATE_GAME_MYGAME` to SystemState enum in config.h

### Adding a New Feature

1. Create appropriate header and implementation files
2. Include in main sketch
3. Update documentation
4. Test thoroughly
5. Submit pull request

## Testing Guidelines

### Before Submitting
- [ ] Code compiles without errors or warnings
- [ ] Tested on actual hardware (if possible)
- [ ] Tested with Arduino IDE compiler
- [ ] No regression in existing features
- [ ] Documentation updated
- [ ] Code follows style guidelines

### Hardware Testing
If you have the hardware:
- Test all button combinations
- Verify display updates correctly
- Check timing and performance
- Test power consumption
- Verify no crashes or hangs

### Simulation Testing
If you don't have hardware:
- Verify code compiles
- Check logic flow
- Test calculations and algorithms
- Verify constants and bounds

## Documentation

When adding features, update:
- **README.md** - If it's a major feature
- **USER_MANUAL.md** - For user-facing features
- **HARDWARE_SETUP.md** - For hardware changes
- **Code comments** - For complex logic

## Reporting Bugs

### Bug Report Template

```markdown
**Description**
Clear description of the bug

**Steps to Reproduce**
1. Step 1
2. Step 2
3. See error

**Expected Behavior**
What should happen

**Actual Behavior**
What actually happens

**Hardware**
- Arduino board: [e.g., Nano, Uno, ESP32]
- Display: [e.g., Waveshare 2.9"]
- RTC: [e.g., DS3231]

**Software**
- Arduino IDE version: [e.g., 1.8.19]
- Sketch version: [e.g., commit hash]

**Additional Context**
Any other relevant information
```

## Suggesting Features

### Feature Request Template

```markdown
**Feature Description**
Clear description of the feature

**Use Case**
Why is this feature useful?

**Proposed Implementation**
How could this be implemented? (optional)

**Alternatives Considered**
Other approaches you've thought about (optional)

**Additional Context**
Mockups, examples, references (optional)
```

## Code Review Process

1. **Automated Checks**
   - Code must compile
   - Basic style checks pass

2. **Manual Review**
   - Code quality assessment
   - Feature completeness check
   - Documentation review

3. **Testing**
   - Functionality verification
   - No regressions

4. **Approval and Merge**
   - At least one maintainer approval
   - All discussions resolved

## Communication

- **Issues**: For bugs and feature requests
- **Pull Requests**: For code contributions
- **Discussions**: For general questions and ideas

## License

By contributing, you agree that your contributions will be licensed under the same license as the project (MIT License).

## Questions?

If you have questions about contributing:
1. Check existing issues and documentation
2. Open a new issue with the "question" label
3. Be specific about what you need help with

## Recognition

Contributors will be recognized in:
- Git commit history
- GitHub contributors page
- Special thanks in README (for significant contributions)

---

**Thank you for contributing to Ink-watch!** 🎉
