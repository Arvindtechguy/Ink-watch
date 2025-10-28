# Contributing to Ink-watch

Thank you for your interest in contributing to Ink-watch! This document provides guidelines and instructions for contributing.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [How Can I Contribute?](#how-can-i-contribute)
- [Development Setup](#development-setup)
- [Coding Standards](#coding-standards)
- [Pull Request Process](#pull-request-process)

## Code of Conduct

### Our Pledge

We are committed to providing a welcoming and inspiring community for all. Please be respectful and constructive in your interactions.

### Expected Behavior

- Be respectful and inclusive
- Welcome newcomers and help them learn
- Focus on what is best for the community
- Show empathy towards other community members

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check existing issues. When you create a bug report, include:

- **Clear title and description**
- **Steps to reproduce**
- **Expected vs actual behavior**
- **Hardware details** (Arduino model, display type, etc.)
- **Software versions** (Arduino IDE, libraries)
- **Photos or serial output** if relevant

### Suggesting Features

Feature requests are welcome! Please provide:

- **Clear use case** - Why is this feature needed?
- **Detailed description** - How should it work?
- **Alternatives considered** - What other solutions did you think about?
- **Implementation ideas** - How might this be implemented?

### Code Contributions

We accept contributions for:

- Bug fixes
- New features
- Performance improvements
- Documentation improvements
- New games or watch faces
- Display driver support
- Power optimization
- Test coverage

## Development Setup

### Prerequisites

1. Arduino IDE 1.8.x or newer
2. Git for version control
3. Text editor or IDE (VS Code, Arduino IDE, etc.)
4. Hardware for testing (optional but recommended)

### Setting Up Development Environment

1. **Fork the repository**
   ```bash
   # Click "Fork" on GitHub, then:
   git clone https://github.com/YOUR-USERNAME/Ink-watch.git
   cd Ink-watch
   git remote add upstream https://github.com/Arvindtechguy/Ink-watch.git
   ```

2. **Create a branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make your changes**
   - Follow coding standards below
   - Test your changes thoroughly
   - Update documentation as needed

4. **Commit your changes**
   ```bash
   git add .
   git commit -m "Add feature: description of your changes"
   ```

5. **Push to your fork**
   ```bash
   git push origin feature/your-feature-name
   ```

6. **Create Pull Request**
   - Go to GitHub and create PR from your fork
   - Fill in the PR template
   - Link any related issues

## Coding Standards

### General Guidelines

- **Keep it simple** - Prefer clarity over cleverness
- **Comment when needed** - Explain why, not what
- **Minimal changes** - Make focused, atomic commits
- **Test your code** - Verify it works on actual hardware if possible

### Arduino/C++ Style

Follow standard Arduino coding style:

```cpp
// Constants in UPPER_CASE
#define LED_PIN 13
const int BUTTON_PIN = 2;

// Variables in camelCase
int buttonState = 0;
unsigned long lastPressTime = 0;

// Functions in camelCase
void updateDisplay() {
  // Function body
}

// Classes in PascalCase
class DisplayDriver {
  // Class implementation
};
```

### Formatting

- **Indentation**: 2 spaces (no tabs)
- **Braces**: Opening brace on same line
- **Line length**: Max 100 characters when possible
- **Whitespace**: One blank line between functions

### Documentation

- Add file headers describing purpose
- Document all public functions
- Include usage examples for complex features
- Update README.md when adding features

### Example Well-Commented Code

```cpp
/*
 * Update the clock display
 * 
 * This function increments the time by one second and
 * refreshes the e-ink display. To minimize power consumption,
 * it only updates changed digits.
 * 
 * @param forceUpdate - Force full display refresh
 * @return true if display was updated
 */
bool updateClock(bool forceUpdate = false) {
  seconds++;
  
  if (seconds >= 60) {
    seconds = 0;
    minutes++;
    
    if (minutes >= 60) {
      minutes = 0;
      hours = (hours + 1) % 24;
    }
  }
  
  // Only update display if needed
  if (forceUpdate || seconds == 0) {
    displayTime();
    return true;
  }
  
  return false;
}
```

## Pull Request Process

### Before Submitting

- [ ] Code follows the style guidelines
- [ ] Comments are added where needed
- [ ] Documentation is updated
- [ ] Changes are tested on hardware (if possible)
- [ ] No unnecessary files are included
- [ ] Commit messages are clear and descriptive

### PR Template

When creating a PR, include:

```markdown
## Description
Brief description of what this PR does

## Type of Change
- [ ] Bug fix
- [ ] New feature
- [ ] Documentation update
- [ ] Performance improvement
- [ ] Code refactoring

## Testing
Describe how you tested this:
- Hardware used:
- Test scenarios:
- Results:

## Checklist
- [ ] Code follows style guidelines
- [ ] Self-reviewed the code
- [ ] Commented complex code
- [ ] Updated documentation
- [ ] No breaking changes (or documented if unavoidable)

## Screenshots
If applicable, add screenshots or serial output
```

### Review Process

1. Maintainers will review your PR
2. Address any requested changes
3. Once approved, PR will be merged
4. Your contribution will be credited

## Feature Development Guidelines

### Adding a New Game

1. Create header file: `game_name.h`
2. Implement game class with standard interface:
   ```cpp
   class GameName {
   public:
     void reset();
     void update(unsigned long currentTime);
     void handleInput(int button);
     void draw();
     bool isGameOver();
   };
   ```
3. Add game to menu in `Ink-watch.ino`
4. Create standalone example in `examples/`
5. Update README.md with game controls

### Adding Display Support

1. Create display driver in `eink_display.h` or separate file
2. Implement standard interface:
   ```cpp
   void init();
   void clearBuffer();
   void setPixel(int x, int y, bool black);
   void update();
   ```
3. Add configuration in `config_template.h`
4. Document pin connections in `hardware/HARDWARE.md`
5. Test with actual hardware

### Adding a Sensor/Module

1. Add pin definitions to main sketch
2. Create initialization function
3. Add to `setup()`
4. Document wiring in hardware docs
5. Update BOM with component

## Testing

### Hardware Testing Checklist

- [ ] Upload code successfully
- [ ] All buttons respond correctly
- [ ] Display updates properly
- [ ] Clock keeps accurate time
- [ ] Games are playable
- [ ] Battery monitor works
- [ ] No excessive power consumption
- [ ] No overheating

### Software Testing

- [ ] Code compiles without warnings
- [ ] Serial output is correct
- [ ] No memory leaks (check with tools)
- [ ] Edge cases handled

## Documentation

### What to Document

- New features and how to use them
- Hardware changes (wiring, components)
- Configuration options
- Breaking changes
- Troubleshooting tips

### Where to Document

- `README.md` - Overview and features
- `docs/GETTING_STARTED.md` - Setup instructions
- `hardware/HARDWARE.md` - Hardware specs
- Code comments - Implementation details
- GitHub Wiki - Extended tutorials

## Questions?

If you have questions about contributing:

1. Check existing documentation
2. Search closed issues
3. Ask in GitHub Discussions
4. Create an issue with "Question" label

## Recognition

Contributors will be:

- Listed in commit history
- Mentioned in release notes (for significant contributions)
- Added to CONTRIBUTORS.md (coming soon)

Thank you for contributing to Ink-watch! 🎉

## License

By contributing, you agree that your contributions will be licensed under the MIT License.
