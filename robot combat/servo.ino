#include <Servo.h>

// Déclaration des broches utilisées pour les moteurs à courant continu
const int MOTOR_LEFT_EN = 5;
const int MOTOR_LEFT_IN1 = 6;
const int MOTOR_LEFT_IN2 = 7;
const int MOTOR_RIGHT_EN = 10;
const int MOTOR_RIGHT_IN1 = 9;
const int MOTOR_RIGHT_IN2 = 8;

// Déclaration de la broche utilisée pour le servomoteur
const int SERVO_PIN = 3;

// Création d'un objet Servo pour contrôler le servomoteur
Servo servo;

// Fonction pour activer le servomoteur à un angle donné
void setServoAngle(int angle) {
  servo.write(angle);
}

// Fonction pour faire tourner le robot à gauche
void turnLeft() {
  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, HIGH);
  analogWrite(MOTOR_LEFT_EN, 255);
  digitalWrite(MOTOR_RIGHT_IN1, HIGH);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
  analogWrite(MOTOR_RIGHT_EN, 255);
}

// Fonction pour faire tourner le robot à droite
void turnRight() {
  digitalWrite(MOTOR_LEFT_IN1, HIGH);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  analogWrite(MOTOR_LEFT_EN, 255);
  digitalWrite(MOTOR_RIGHT_IN1, LOW);
  digitalWrite(MOTOR_RIGHT_IN2, HIGH);
  analogWrite(MOTOR_RIGHT_EN, 255);
}

// Fonction pour faire avancer le robot
void goForward() {
  digitalWrite(MOTOR_LEFT_IN1, HIGH);
  digitalWrite(MOTOR_LEFT_IN2, LOW);
  analogWrite(MOTOR_LEFT_EN, 255);
  digitalWrite(MOTOR_RIGHT_IN1, HIGH);
  digitalWrite(MOTOR_RIGHT_IN2, LOW);
  analogWrite(MOTOR_RIGHT_EN, 255);
}

// Fonction pour faire reculer le robot
void goBackward() {
  digitalWrite(MOTOR_LEFT_IN1, LOW);
  digitalWrite(MOTOR_LEFT_IN2, HIGH);
  analogWrite(MOTOR_LEFT_EN, 255);
  digitalWrite(MOTOR_RIGHT_IN1, LOW);
  digitalWrite(MOTOR_RIGHT_IN2, HIGH);
  analogWrite(MOTOR_RIGHT_EN, 255);
}

void setup() {
  // Configuration des broches utilisées pour les moteurs à courant continu en sortie
  pinMode(MOTOR_LEFT_EN, OUTPUT);
  pinMode(MOTOR_LEFT_IN1, OUTPUT);
  pinMode(MOTOR_LEFT_IN2, OUTPUT);
  pinMode(MOTOR_RIGHT_EN, OUTPUT);
  pinMode(MOTOR_RIGHT_IN1, OUTPUT);
  pinMode(MOTOR_RIGHT_IN2, OUTPUT);

  // Attachement de la broche utilisée pour le servomoteur
  servo.attach(SERVO_PIN);
}

void loop() {
  // Faire tourner le robot à gauche pendant 1 seconde
  turnLeft();
  delay(1000);

  // Faire tourner le robot à droite pendant 1 seconde
  turnRight();
  delay(1000);

  // Faire avancer le robot pendant 1 seconde
  goForward();
  delay(1000);

  // Faire reculer le robot pendant 1 seconde
  goBackward();
  delay(1000);
}