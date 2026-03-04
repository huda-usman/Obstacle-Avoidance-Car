<div align="center">

<!-- HEADER -->
<img src="https://capsule-render.vercel.app/api?type=soft&color=0:0a0000,100:cc0000&height=160&text=Obstacle%20Avoidance%20Car&fontSize=38&fontColor=ffffff&fontAlignY=55&desc=The%20Maze-Solver-Car%20%7C%20RoboCUST%202024%20%F0%9F%8F%86%201st%20Place&descAlignY=75&descSize=14" width="100%"/>

<br/>

<!-- BADGES -->
![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![Language](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge&logo=cplusplus)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)
![Competition](https://img.shields.io/badge/RoboCUST_2024-1st_Place_🏆-gold?style=for-the-badge)
![DLD](https://img.shields.io/badge/Semester_Project-Digital_Logic_Design-purple?style=for-the-badge)

<br/>

> ### 🏆 1st Position — Robo Maze Category
> **RoboCUST Robotics Competition**
> Organized by SEEK & IEEE at Capital University of Science and Technology, Islamabad
> 📅 March 2nd, 2024

<br/>

[📷 Gallery](#-the-car-in-action) • [🧠 How It Works](#-how-it-works) • [🛠️ Hardware](#️-hardware-used) • [🚀 Getting Started](#-getting-started) • [🏅 Achievement](#-competition-achievement)

</div>

---

## 🎓 About This Project

> An autonomous robot car that detects obstacles using an ultrasonic sensor and steers around them in real-time — **battle-tested by winning a live robotics maze competition!**

This car was built as a **semester project for Digital Logic Design (DLD)** and later competed in the **RoboCUST 2024 Robotics Competition** where it won **1st place** in the Robo Maze category. It operates fully autonomously — no remote control, no pre-programmed path — using real-time ultrasonic sensing to navigate through obstacles.

---

## 📷 The Car in Action

<div align="center">

<img src="./photo.png" width="500" style="border-radius:12px"/>

*The Maze-Solver-Car alongside its 1st place shield from RoboCUST 2024* 🏆

</div>

---

## 🧠 How It Works

<div align="center">

| Step | Action | Description |
|:----:|:------:|:------------|
| 1️⃣ | **Measure** | HC-SR04 ultrasonic sensor continuously reads distance ahead |
| 2️⃣ | **React** | Stops, reverses, and scans left & right when obstacle is within 15cm |
| 3️⃣ | **Decide** | Turns toward whichever side has more open space |
| 4️⃣ | **Continue** | Drives forward with smooth speed ramp-up to protect battery |

</div>

---

## 🛠️ Hardware Used

<div align="center">

| # | Component | Details |
|:---:|-----------|---------|
| 1 | **Microcontroller** | Arduino Uno |
| 2 | **Motor Driver** | Adafruit Motor Shield v1 |
| 3 | **Drive Motors** | DC Gear Motors (x4) |
| 4 | **Steering** | SG90 Servo Motor |
| 5 | **Distance Sensor** | HC-SR04 Ultrasonic Sensor |
| 6 | **Wheels** | Rubber wheels compatible with TT gear motors |
| 7 | **Power Supply** | 18650 Li-ion Battery |
| 8 | **Wiring** | Male & Female Jumper Wires |

</div>

---

## 📦 Libraries Required

Install all three via **Sketch → Include Library → Add .ZIP File**:

<div align="center">

| Library | Purpose | Download |
|---------|---------|---------|
| **AFMotor** | Controls DC motors via Motor Shield | [adafruit.com](https://learn.adafruit.com/adafruit-motor-shield/library-install) |
| **NewPing** | Reads HC-SR04 ultrasonic sensor | [GitHub](https://github.com/livetronic/Arduino-NewPing) |
| **Servo** | Controls servo motor direction | [GitHub](https://github.com/arduino-libraries/Servo.git) |

</div>

---

## 🔌 Wiring / Pin Connections

<div align="center">

| Component | Arduino Pin |
|-----------|------------|
| HC-SR04 TRIG | A0 |
| HC-SR04 ECHO | A1 |
| Servo Signal | D10 |
| Motor 1 & 2 | Motor Shield Port 1 & 2 |
| Motor 3 & 4 | Motor Shield Port 3 & 4 |

</div>

> 💡 Motors are controlled through the **Motor Driver Shield** — connect them to the shield's screw terminals, not directly to Arduino pins. The **18650 battery** powers the motors via the shield's power input.

---

## ⚙️ Configuration

Tweak these values at the top of the sketch to tune your car's behavior:

```cpp
#define MAX_DISTANCE     200   // Maximum sonar range (cm)
#define MAX_SPEED        190   // Motor top speed (0–255)
#define MAX_SPEED_OFFSET  20   // Speed offset between motors
```

---

## 🚀 Getting Started

```bash
# 1. Clone this repository
git clone https://github.com/huda-usman/Obstacle-Avoidance-Car.git

# 2. Open in Arduino IDE
#    File → Open → ObstacleAvoidanceCar/ObstacleAvoidanceCar.ino

# 3. Install the three required libraries (see above)

# 4. Select board: Tools → Board → Arduino Uno

# 5. Upload and watch it go! 🚗
```

---

## 📁 Repository Structure

```
Obstacle-Avoidance-Car/
├── ObstacleAvoidanceCar.ino   # Main Arduino sketch
├── photo.png                  # The Maze-Solver-Car + shield photo
├── .gitignore                 # Git ignore rules
└── README.md                  # This file
```

---

## 🏅 Competition Achievement

<div align="center">

| | |
|:---:|:---|
| 🏆 **Event** | RoboCUST Robotics Competition 2024 |
| 📌 **Category** | Robo Maze |
| 🥇 **Result** | **1st Position** |
| 🏛️ **Venue** | Capital University of Science and Technology, Islamabad |
| 👥 **Organizers** | SEEK & IEEE CUST Student Branch |
| 📅 **Date** | March 2nd, 2024 |

</div>

The car navigated a physical maze **entirely autonomously** using only ultrasonic sensing — no pre-programmed path, no mapping, pure real-time obstacle avoidance — and took **1st place** among all competing teams.

---

## 📄 License

This project is open-source under the [MIT License](LICENSE).

---

## 🙌 Acknowledgements

- [Adafruit](https://www.adafruit.com/) for the Motor Shield library
- [Tim Eckel](https://github.com/livetronic) for the NewPing library
- SEEK & IEEE CUST for organizing RoboCUST 2024

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=soft&color=0:cc0000,100:0a0000&height=100&section=footer" width="100%"/>

### 👩‍💻 About the Author

**Huda Usman** — Hardware & Software Developer

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Huda%20Usman-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/hudausman010)

Built in Islamabad, Pakistan 🇵🇰

</div>
