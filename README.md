# 🚗 Obstacle Avoidance Car — *The Maze-Solver-Car*

> 🏆 **1st Position — Robo Maze Category**  
> RoboCUST Robotics Competition, organized by SEEK & IEEE  
> Capital University of Science and Technology, Islamabad — March 2nd, 2024

An autonomous robot car that detects obstacles using an ultrasonic sensor and steers around them in real-time — battle-tested by winning a live robotics maze competition!

---

## 📷 The Car in Action

![Maze-Solver-Car with 1st Position Certificate](./photo.jpg)

*The Maze-Solver-Car alongside its 1st place certificate from RoboCUST 2024.*

---

## 🧠 How It Works

1. **Measure** – The HC-SR04 ultrasonic sensor continuously reads the distance ahead.
2. **Obstacle detected** (`≤ 15 cm`) – The car:
   - Stops immediately
   - Reverses for 300 ms
   - Looks **right** (servo at 50°) and measures distance
   - Looks **left** (servo at 170°) and measures distance
   - Turns toward whichever side has **more space**
3. **Clear path** – Drives forward with a gradual speed ramp-up to protect the battery.

---

## 🛠️ Hardware Used

| Component | Details |
|---|---|
| **Microcontroller** | Arduino Uno |
| **Motor Driver** | Adafruit Motor Shield v1 |
| **Drive Motors** | DC Gear Motors (x4) |
| **Steering** | SG90 Servo Motor |
| **Distance Sensor** | HC-SR04 Ultrasonic Sensor |
| **Wheels** | Rubber wheels compatible with TT gear motors |
| **Power Supply** | 18650 Li-ion Battery |
| **Wiring** | Jumper wires |

---

## 📦 Libraries Required

Install all three via **Sketch → Include Library → Add .ZIP File**:

| Library | Download |
|---|---|
| **AFMotor** (Adafruit Motor Shield) | [adafruit.com](https://learn.adafruit.com/adafruit-motor-shield/library-install) |
| **NewPing** | [GitHub](https://github.com/livetronic/Arduino-NewPing) |
| **Servo** | [GitHub](https://github.com/arduino-libraries/Servo.git) |

---

## 🔌 Wiring / Pin Connections

| Component | Arduino Pin |
|---|---|
| HC-SR04 TRIG | A0 |
| HC-SR04 ECHO | A1 |
| Servo Signal | D10 |
| Motor 1 & 2 | Motor Shield Port 1 & 2 |
| Motor 3 & 4 | Motor Shield Port 3 & 4 |

> Motors are controlled through the **Motor Driver Shield** — connect them to the shield's screw terminals, not directly to Arduino pins. The **18650 battery** powers the motors via the shield's power input.

---

## ⚙️ Configuration

```cpp
#define MAX_DISTANCE    200   // Max sonar range in cm
#define MAX_SPEED       190   // Motor top speed (0–255)
#define MAX_SPEED_OFFSET 20
```

---

## 🚀 Getting Started

```bash
# 1. Clone this repository
git clone https://github.com/YOUR_USERNAME/Obstacle-Avoidance-Car.git

# 2. Open in Arduino IDE
#    File → Open → ObstacleAvoidanceCar/ObstacleAvoidanceCar.ino

# 3. Install the three required libraries (see above)

# 4. Select board: Tools → Board → Arduino Uno

# 5. Upload!
```

---

## 📁 Repository Structure

```
Obstacle-Avoidance-Car/
├── ObstacleAvoidanceCar.ino   # Main Arduino sketch
├── photo.jpg                  # The Maze-Solver-Car + trophy photo
└── README.md                  # This file
```

---

## 🏅 Competition Achievement

This car competed in the **Robo Maze** category at **RoboCUST 2024**, a robotics competition organized by SEEK and IEEE at CUST, Islamabad. It navigated a physical maze entirely autonomously using only ultrasonic sensing — no pre-programmed path, pure real-time obstacle avoidance — and took **1st place**.

---

## 📄 License

This project is open-source under the [MIT License](LICENSE).

---

## 🙌 Acknowledgements

- [Adafruit](https://www.adafruit.com/) for the Motor Shield library
- [Tim Eckel](https://github.com/livetronic) for the NewPing library
- SEEK & IEEE CUST for organizing RoboCUST 2024
