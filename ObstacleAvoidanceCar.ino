// ============================================================
//            ARDUINO OBSTACLE AVOIDING CAR
// ============================================================
// Required Libraries:
//  - AFMotor:  https://learn.adafruit.com/adafruit-motor-shield/library-install
//  - NewPing:  https://github.com/livetronic/Arduino-NewPing
//  - Servo:    https://github.com/arduino-libraries/Servo.git
//
// Install via: Sketch >> Include Library >> Add .ZIP File
// ============================================================

#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

// ── Pin Definitions ──────────────────────────────────────────
#define TRIG_PIN        A0
#define ECHO_PIN        A1
#define MAX_DISTANCE   200    // Maximum sonar range (cm)

// ── Motor Speed Settings ─────────────────────────────────────
#define MAX_SPEED       190   // Top speed for DC motors (0–255)
#define MAX_SPEED_OFFSET 20

// ── Sensor & Motor Initialisation ───────────────────────────
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo myservo;

// ── State Variables ──────────────────────────────────────────
boolean goesForward = false;
int distance  = 100;
int speedSet  = 0;

// ============================================================
//  SETUP
// ============================================================
void setup() {
  myservo.attach(10);
  myservo.write(115);       // Centre servo (forward-facing)
  delay(2000);

  // Take 4 warm-up readings for stable initial distance
  for (int i = 0; i < 4; i++) {
    distance = readPing();
    delay(100);
  }
}

// ============================================================
//  MAIN LOOP
// ============================================================
void loop() {
  int distanceR = 0;
  int distanceL = 0;
  delay(40);

  if (distance <= 15) {
    // Obstacle detected — stop, back up, then decide direction
    moveStop();
    delay(100);
    moveBackward();
    delay(300);
    moveStop();
    delay(200);

    distanceR = lookRight();
    delay(200);
    distanceL = lookLeft();
    delay(200);

    if (distanceR >= distanceL) {
      turnRight();
    } else {
      turnLeft();
    }
    moveStop();

  } else {
    moveForward();
  }

  distance = readPing();
}

// ============================================================
//  SENSOR FUNCTIONS
// ============================================================

/** Sweep servo right (50°), measure distance, return to centre. */
int lookRight() {
  myservo.write(50);
  delay(500);
  int d = readPing();
  delay(100);
  myservo.write(115);
  return d;
}

/** Sweep servo left (170°), measure distance, return to centre. */
int lookLeft() {
  myservo.write(170);
  delay(500);
  int d = readPing();
  delay(100);
  myservo.write(115);
  return d;
}

/** Read distance in cm from HC-SR04. Returns 250 if no echo. */
int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  return (cm == 0) ? 250 : cm;
}

// ============================================================
//  MOVEMENT FUNCTIONS
// ============================================================

void moveStop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    // Ramp up speed gradually to protect battery
    for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
      motor1.setSpeed(speedSet);
      motor2.setSpeed(speedSet);
      motor3.setSpeed(speedSet);
      motor4.setSpeed(speedSet);
      delay(5);
    }
  }
}

void moveBackward() {
  goesForward = false;
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  // Ramp up speed gradually
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet += 2) {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}

void turnRight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(500);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void turnLeft() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(500);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
