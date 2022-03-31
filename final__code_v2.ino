#include <SparkFun_TB6612.h>

#define AIN1 3
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 9

const int offsetA = 1;
const int offsetB = 1;

const int led1 = 2;  // Forward LED connect to Arduno pin 2
const int led2 = 3;  // Backward LED connect to Arduno pin 3

const int TRIG_PIN = 6; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 7; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int DISTANCE_THRESHOLD = 50; // centimeters

float duration_us, distance_cm;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup() {
Serial.begin (9600);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
}

void m_forward (){
  forward(motor1, motor2, 150);
  }

void m_backward (){
  back(motor1, motor2, -150);
  }
void loop ()
{ // generate pulse in TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration_us = pulseIn(ECHO_PIN, HIGH);
  distance_cm = 0.017 * duration_us; // calculate distance in cm

  if(distance_cm > DISTANCE_THRESHOLD)
    m_forward();
  else
    m_backward();

 Serial.print("distance: ");
 Serial.print(distance_cm);
 Serial.println(" cm");      
  }
