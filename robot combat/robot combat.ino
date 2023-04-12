
/*
author : theotime Perrichet
date : 2019-05-06
description : robot combat
*/

//bibliothèque
#include <PS2X_lib.h>
#include <Servo.h>

// PS2 Controller Connections
#define PS2_DAT    13
#define PS2_CMD    11
#define PS2_SEL    10
#define PS2_CLK    12

// Motor Connections
#define borneENA        9      // On associe la borne "ENA" du L298N à la pin D10 de l'arduino moteur A
#define borneIN1        8       // On associe la borne "IN1" du L298N à la pin D9 de l'arduino moteur A
#define borneIN2        7       // On associe la borne "IN2" du L298N à la pin D8 de l'arduino moteur A
#define borneIN3        6       // On associe la borne "IN3" du L298N à la pin D7 de l'arduino moteur B
#define borneIN4        5       // On associe la borne "IN4" du L298N à la pin D6 de l'arduino moteur B
#define borneENB        4       // On associe la borne "ENB" du L298N à la pin D5 de l'arduino moteur B
// Servo Pin
#define SERVO_PIN 3

//LED Pin
#define LED_PIN 2

Servo myservo;
PS2X ps2x;

void setup() {
  // Start serial communication
  Serial.begin(115200);
  
  // Configuration de toutes les pins de l'Arduino en "sortie" (car elles attaquent les entrées du module L298N)
  pinMode(borneENA, OUTPUT);
  pinMode(borneIN1, OUTPUT);
  pinMode(borneIN2, OUTPUT);
  pinMode(borneIN3, OUTPUT);
  pinMode(borneIN4, OUTPUT);
  pinMode(borneENB, OUTPUT);

  // Initialize Servo
  myservo.attach(SERVO_PIN);
  
  // Initialize the PS2 controller
 error = ps2x.config_gamepad(9,7,6,8, true, true);
  
}

void loop() {
  if (error==1)
    return;

  else {

    ps2x.read_gamepad(false, vibrate);  
    // Read button states
    int button = ps2x.ButtonDataByte();

    // Circle button - move forward
    if (ps2x.Button(PSB_CIRCLE)) {
      Serial.println("Circle pressed - Forward");
      digitalWrite(2, HIGH);
      delay(500);              // Pause de 500 ms
      digitalWrite(2, LOW);   // Met la broche 13 au niveau bas = éteint la LED
      delay(500); 
    }

    // Square button - move backward
    if (ps2x.Button(PSB_SQUARE)) {
      Serial.println("Square pressed - Backward");
    }

    // D-pad Right - turn right
    if (ps2x.ButtonPressed(PSB_PAD_RIGHT)) {
      Serial.println("Right pressed - Turn Right");
    }

    // D-pad Left - turn left
    if (ps2x.ButtonPressed(PSB_PAD_LEFT)) {
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
