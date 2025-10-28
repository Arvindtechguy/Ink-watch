# Visual Interface Guide

This document shows what the Ink-watch interface looks like on the display.

## Main Clock Display

```
┌────────────────────────┐
│                        │
│                        │
│       12:34:56         │
│                        │
│                        │
│    [Press any key      │
│     for menu]          │
│                        │
│                        │
│  Battery: ████░░ 80%   │
└────────────────────────┘
```

## Main Menu

```
┌────────────────────────┐
│    MAIN MENU           │
│                        │
│  > Clock               │
│    Games               │
│    Settings            │
│    Battery             │
│                        │
│                        │
│  UP/DOWN: Navigate     │
│  SELECT: Choose        │
└────────────────────────┘
```

## Games Menu

```
┌────────────────────────┐
│    GAMES               │
│                        │
│  1. Snake              │
│     Classic snake      │
│     with scoring       │
│                        │
│  2. Pong               │
│     Play vs AI         │
│                        │
│  BACK: Return to menu  │
└────────────────────────┘
```

## Snake Game

```
┌────────────────────────┐
│  SNAKE    Score: 120   │
│ ╔══════════════════╗   │
│ ║..........*.......║   │
│ ║..................║   │
│ ║.....@oooo.......║   │
│ ║..................║   │
│ ║..................║   │
│ ║..................║   │
│ ║..................║   │
│ ║..................║   │
│ ╚══════════════════╝   │
│                        │
│  @=Head  o=Body  *=Food│
└────────────────────────┘
```

Legend:
- `@` - Snake head
- `o` - Snake body
- `*` - Food
- `.` - Empty space

## Pong Game

```
┌────────────────────────┐
│  PONG   YOU: 3  AI: 2  │
│ ────────────────────── │
│ |                    | │
│ |        O           | │
│ |                    | │
│ |                    | │
│ |                    | │
│ |                    | │
│ |                    | │
│ ────────────────────── │
│                        │
│  UP/DOWN: Move paddle  │
└────────────────────────┘
```

Legend:
- `|` - Paddles (left=player, right=AI)
- `O` - Ball
- `─` - Top/bottom walls

## Settings Menu

```
┌────────────────────────┐
│    SETTINGS            │
│                        │
│  Time Format:  24h     │
│  Display Mode: Normal  │
│  Auto Sleep:   30s     │
│  Brightness:   Medium  │
│                        │
│                        │
│  SELECT: Toggle        │
│  BACK: Save & Exit     │
└────────────────────────┘
```

## Battery Info

```
┌────────────────────────┐
│    BATTERY INFO        │
│                        │
│  ████████████░░░       │
│                        │
│  Voltage:   3.85V      │
│  Level:     78%        │
│  Status:    Discharging│
│                        │
│  Est. Runtime: 18h     │
│                        │
│  BACK: Return          │
└────────────────────────┘
```

## Button Layout (Physical)

```
      ┌─────────────┐
      │             │
      │   E-INK     │
      │  DISPLAY    │
   ▲  │   200x200   │  ▲
  [UP]│             │[SELECT]
   │  │             │  │
   ▼  │             │  ▼
[DOWN] └─────────────┘[BACK]
```

Button Positions:
- **LEFT SIDE**: UP (top), DOWN (bottom)
- **RIGHT SIDE**: SELECT (top), BACK (bottom)

## Typical User Flow

```
Power On
   │
   ▼
┌─────────┐
│  CLOCK  │◄────────┐
└────┬────┘         │
     │              │
   [UP/DOWN]        │
     │              │
     ▼              │
┌─────────┐         │
│  MENU   │         │
└────┬────┘         │
     │              │
  [SELECT]          │
     │              │
     ├──────► GAMES ──[SELECT]──► Snake
     │              │                │
     ├──────► SETTINGS              │
     │              │              [BACK]
     ├──────► BATTERY               │
     │                              │
   [BACK]                           │
     │                              │
     └──────────────────────────────┘
```

## Display States

### Idle State
- Shows clock
- Updates every second
- Low power consumption

### Active State
- User navigating menus
- Buttons responsive
- Display updates on change

### Game State
- Game running
- Continuous updates
- Higher power consumption

### Sleep State (Future)
- Display off or static
- Very low power
- Wake on button press

## E-Ink Display Characteristics

```
Full Refresh (2-3 seconds):
┌────────┐     ┌────────┐     ┌────────┐
│ BLACK  │ ──► │  GREY  │ ──► │ WHITE  │
│ IMAGE  │     │ FLASH  │     │  NEW   │
│        │     │        │     │ IMAGE  │
└────────┘     └────────┘     └────────┘

Partial Refresh (faster, if supported):
┌────────┐     ┌────────┐
│  OLD   │ ──► │  NEW   │
│ IMAGE  │     │ IMAGE  │
│ 12:34  │     │ 12:35  │
└────────┘     └────────┘
```

## Size Comparisons

### Display Size Options

```
1.54" (200x200)          2.13" (250x122)
┌─────────────┐          ┌──────────────────┐
│   SQUARE    │          │    RECTANGULAR   │
│   DISPLAY   │          │     DISPLAY      │
│             │          │                  │
│   200x200   │          │     250x122      │
│             │          │                  │
└─────────────┘          └──────────────────┘
```

### Watch Size Reference

```
Side View:
  ┌───────────────┐ ◄── E-Ink Display (3-5mm)
  ├───────────────┤ ◄── Arduino Nano (1.8mm)
  ├───────────────┤ ◄── Battery (6-8mm)
  └───────────────┘
Total Thickness: ~15-20mm
```

## Serial Monitor Output

When testing with Serial Monitor (9600 baud), you'll see:

```
Ink-watch initialized!
Display initialized
=== MAIN MENU ===
> Clock
  Games
  Settings
  Battery

Time: 12:34:56
UP
DOWN
SELECT

=== SNAKE GAME ===
Score: 30
....................
..........*.........
....................
....@ooooo..........
....................
```

## Icons and Symbols (Future Enhancement)

```
Clock:      🕐  Battery:    🔋
Games:      🎮  Settings:   ⚙️
Warning:    ⚠️  Charging:   ⚡
Sleep:      💤  WiFi:       📶
Bluetooth:  📱  Alarm:      ⏰
```

## Display Optimization Tips

1. **Minimize Refreshes**: E-ink is slow
2. **Use Partial Updates**: When supported
3. **Static Content**: E-ink holds image without power
4. **High Contrast**: Black and white work best
5. **Simple Graphics**: Complex images slow down refresh

## Recommended Viewing

```
Optimal:           Not Ideal:
   👁️                  👁️
   │                   /
   │                 /
   ▼               ▼
┌──────┐        ┌──────┐
│      │        │      │
└──────┘        └──────┘
 90° angle      <45° angle
```

E-ink displays work best when viewed straight on.

---

**Note**: These are ASCII representations. Actual display will show proper graphics based on the e-ink display capabilities and the graphics library used.

## Building Your Own Interface

To customize the display:

1. Edit `eink_display.h` for graphics primitives
2. Modify `Ink-watch.ino` for layout
3. Add custom fonts for better text
4. Create your own watch faces
5. Design icons for menu items

See [CONTRIBUTING.md](../CONTRIBUTING.md) for guidelines on adding features.
