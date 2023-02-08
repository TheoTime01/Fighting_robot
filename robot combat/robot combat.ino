
/*
author : theotime Perrichet
date : 2019-05-06
description : robot combat
*/

ps2x.config_gamepad(9,7,6,8, true, true)

//bibliothèque
#include <PS2X_lib.h>
#include <Servo.h>

// PS2 Controller Connections
#define PS2_DAT    13
#define PS2_CMD    11
#define PS2_SEL    10
#define PS2_CLK    12

// Motor Connections
#define M1 6
#define M2 7

// Servo Pin
#define SERVO_PIN 9

//LED Pin
#define LED_PIN 2

// Speed of Motors
int leftspeed = 150;
int rightspeed = 150;

Servo myservo;
PS2X ps2x;

void setup() {
  // Start serial communication
  Serial.begin(115200);
  
  // Initialize Servo
  myservo.attach(SERVO_PIN);
  
  // Initialize the PS2 controller
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT,true,true); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  
  // Set motor pins as outputs
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop() {
  if (ps2x.read_gamepad()) {
    // Read button states
    int button = ps2x.ButtonDataByte();

    // Circle button - move forward
    if (ps2x.ButtonPressed(PSB_CIRCLE)) {
      digitalWrite(M1, HIGH); // Set motor 1 to forward
      digitalWrite(M2, HIGH); // Set motor 2 to forward
      analogWrite(M1, leftspeed); // Set motor 1 speed
      analogWrite(M2, rightspeed); // Set motor 2 speed
      Serial.println("Circle pressed - Forward");
    }

    // Square button - move backward
    if (ps2x.ButtonPressed(PSB_SQUARE)) {
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
      analogWrite(M1, leftspeed);
      analogWrite(M2, rightspeed);
      Serial.println("Square pressed - Backward");
    }

    // D-pad Right - turn right
    if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) {
      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);
      analogWrite(M1, 0);
      analogWrite(M2, rightspeed);
      Serial.println("Right pressed - Turn Right");
    }

    // D-pad Left - turn left
    if (ps2x.ButtonPressed(PSB_PAD_LEFT)) {
      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      analogWrite(M1, leftspeed);
      analogWrite(M2, 0);
      Serial.println("Left pressed - Turn Left");
    }

    // L1 or R1 buttons - activate servo motor
    if (ps2x.ButtonPressed(PSB_L1) || ps2x.ButtonPressed(PSB_R1)) {
      myservo.write(180); // Set servo to 180 degrees
      Serial.println("L1 button pressed");
    }
    else {
      myservo.write(0); // Set servo to 0 degrees
    }
  }
}
