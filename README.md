# 🤖 ROBOT_COOK

**ROBOT_COOK** is a PlatformIO-powered robotics system built on the ESP32 that autonomously assembles and delivers burgers using servos, reflectance sensors, and custom drive algorithms. Developed for the UBC Engineering Physics Robotics Competition, the project showcases real-time autonomous control, object manipulation, and line-based navigation using modular embedded C++.

---

## 🧠 Project Summary

- ⚙️ Built on the [ESP32](https://www.espressif.com/en/products/socs/esp32) microcontroller using the Arduino framework  
- 📀 Modular architecture with reusable C++ components  
- 🚧 Designed for an obstacle course where two robots coordinate to:
  - Navigate using line-following
  - Pick up bottom buns, patties, and top buns
  - Assemble burgers via servo-actuated claws
  - Deliver burgers to target locations

---

## 📆 Folder Structure

```
ROBOT_COOK/
├── include/            # Header files (modular interfaces)
│   ├── config.h        # Pins, calibrated values, servo angles
│   ├── drive.h         # Directional motor driving logic
│   ├── movement.h      # Full sequence tasks like burger2()
│   ├── sensors.h       # Reflectance-based navigation logic
│   ├── servos.h        # Claw + actuator servo functions
│   └── utilities.h     # Wall detection, line skipping, high-level moves
│
├── src/                # Main source files
│   ├── main.cpp        # Setup, loop, entry point for task
│   ├── config.cpp      # Definition of all global parameters
│   ├── drive.cpp       # Implementation of drive functions
│   ├── movement.cpp    # Autonomous sequences and actions
│   ├── sensors.cpp     # Reflectance detection logic
│   ├── servos.cpp      # Servo control pulse generation
│   ├── utilities.cpp   # Skipping lines, stopping at walls, transitions
│   └── instructions.cpp# Archived early state-machine logic
│
├── lib/                # Reserved for reusable libraries (currently empty)
│
├── test/               # Functional test sketches
│   ├── drivetest.cpp           # Motor testing
│   ├── servotest.cpp           # Servo angle sweep test
│   ├── reflectancetest.cpp     # Sensor calibration
│   ├── reflectancedrivetest.cpp# Sensor-guided drive test
│   └── microswitchtest.cpp     # Microswitch trigger test
│
├── .vscode/            # PlatformIO IDE config
├── platformio.ini      # Project settings: board, dependencies, port
└── README.md           # You're reading it!
```

---

## 🎮 Features

- **Autonomous Navigation**  
  Navigate an arena using analog reflectance sensors and dynamic directional correction.

- **Object Manipulation**  
  Servo-based claw system precisely grabs and drops buns, patties, and top buns.

- **Scripted Task Execution**  
  Sequences like `burger2()` autonomously carry out full assembly and delivery operations.

- **Modular Architecture**  
  Clean separation between config, hardware control, sensing, and logic layers.

- **Hardware-in-the-loop Testing**  
  Subsystem test sketches available for drive, servo, and sensor validation.

---

## ⚙️ Hardware Requirements

| Component             | Description                            |
|----------------------|----------------------------------------|
| 🧠 ESP32              | Target microcontroller (e.g., WROOM)   |
| 🔌 4 DC Motors        | Differential drive w/ PWM speed control|
| 🎚 Reflectance Sensors| 2 analog reflectance sensors (front/back) |
| 🤖 3 Servos           | Big claw, small claw, and actuator     |
| 🔋 Power Source       | Sufficient current for motors + servos |
| 🧱 Course             | Black tape line, stations, physical burger parts |

---

## 🔧 Setup & Usage

### 🔨 Build & Upload

1. **Install [VS Code](https://code.visualstudio.com/) and PlatformIO.**
2. **Clone this repo:**
   ```bash
   git clone https://github.com/joshbermel/ROBOT_COOK.git
   cd ROBOT_COOK
   ```
3. **Open the folder in VSCode. PlatformIO will auto-detect the environment.**
4. **Connect your ESP32 and upload:**
   ```bash
   pio run --target upload
   ```

### 💽 Monitor Output

```bash
pio device monitor
```

### ↻ Run the Robot

- The `main.cpp` loop runs `burger2()`, which:
  - Picks up a patty
  - Drops it at the cooktop
  - Retrieves and places buns
  - Repeats the sequence for multiple burgers

---

## 🧪 Testing Subsystems

To verify hardware:

- Open one of the test files from `/test` (e.g., `drivetest.cpp`)
- Flash it using:
  ```bash
  pio run --target upload --environment esp32dev
  ```
- Use serial monitor to view debug output.

Subsystem test files include:

| Test File | Purpose |
|-----------|---------|
| `drivetest.cpp` | Test motor movement and rotation |
| `servotest.cpp` | Sweep servo angles to validate range |
| `reflectancetest.cpp` | Report reflectance sensor behavior |
| `reflectancedrivetest.cpp` | Center robot dynamically on line |
| `microswitchtest.cpp` | Test digital inputs for obstacle contact |

---

## ⚙️ platformio.ini

```ini
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
lib_deps = 
    ESP32Servo
upload_port = COM18
```

> Change `upload_port` as needed to match your system’s port for the ESP32 device.

---

## 🧠 Key Functions & Architecture

### ↻ Movement Sequences

```cpp
burger2(); // Called in main loop for automated execution
```

### 🚗 Drive Commands

- `driveForwardLeft(speed)`
- `driveBackwardRight(speed)`
- `rotate180(speed, time)`
- `skipLinesAndStop(lines, speed, direction, side)`

### 🤖 Servo Functions

- `grabPatty()`, `dropbunClaw()`, `openClaw()`, `raiseClaw()`

### 🎯 Sensor Logic

- `determineDirection(front, back)` → `LEFT`, `RIGHT`, `CENTERED`, or `NOT_ON_LINE`
- `isOnLine()` → bool

---

## 📈 Future Improvements

- Sensor-driven wall stop (currently timed)
- Dynamic burger order selection
- Inter-robot communication via ESP-NOW
- State-machine or event-driven architecture
- Replace hardcoded delays with feedback loops

---

## 🧑‍💻 Author

Josh Bermel  
🎓 Engineering Physics @ UBC  
🔗 [LinkedIn](https://www.linkedin.com/in/josh-bermel-920877234/) | [GitHub](https://github.com/joshbermel)

---

## 📜 License

This project is licensed under the MIT License. See `LICENSE` for more details.
