#include <PS2X_lib.h>
#include <Servo.h>

// PS2 Controller Connections
#define PS2_DAT    A1
#define PS2_CMD    A0
#define PS2_SEL    A2
#define PS2_CLK    A3

// Motor Connections
#define M1 6
#define M2 7

// Servo Pin
#define SERVO_PIN 9

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
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT);
  
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
      digitalWrite(M1, HIGH);
      digitalWrite(M2, HIGH);
      analogWrite(M1, leftspeed);
      analogWrite(M2, rightspeed);
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
      myservo.write(180);
      Serial.println("L1 button pressed");
    }
    else {
      myservo.write(0);
    }
  }
}
