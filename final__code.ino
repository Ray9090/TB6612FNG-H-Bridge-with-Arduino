#define mp1 9  // Motor's one pin connected to Arduino PWM pin 9
#define mp2 10  // Motor's another pin connected to Arduino PWM pin 10

const int led1 = 2;  // Forward LED connect to Arduno pin 2
const int led2 = 3;  // Backward LED connect to Arduno pin 2

const int TRIG_PIN = 6; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 7; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int DISTANCE_THRESHOLD = 50; // centimeters

float duration_us, distance_cm;

void setup() {
Serial.begin (9600);
pinMode(mp1, OUTPUT);
pinMode(mp2, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
}
void forward(){
    analogWrite (mp1, 255);
    analogWrite (mp2, 0);
    digitalWrite (led1, HIGH);
    digitalWrite (led2, LOW);
  }
void backward(){
    delay(3000);
    analogWrite (mp1, 0);
    analogWrite (mp2, 150);
    digitalWrite (led1, LOW);
    digitalWrite (led2, HIGH);
  }

void loop ()
{ // generate pulse in TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration_us = pulseIn(ECHO_PIN, HIGH);
  distance_cm = 0.017 * duration_us; // calculate distance in cm

  if(distance_cm > DISTANCE_THRESHOLD)
    forward();
  else
    backward();

 Serial.print("distance: ");
 Serial.print(distance_cm);
 Serial.println(" cm");      
  }
