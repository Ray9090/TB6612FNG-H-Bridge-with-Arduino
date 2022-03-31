#define mp1 8
#define mp2 9

const int led1 = 6;
const int led2 = 7;

void setup() {
Serial.begin (9600);
pinMode(mp1, OUTPUT);
pinMode(mp2, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);

}


void loop ()
{
  digitalWrite (mp1, HIGH);
  digitalWrite (mp2, LOW);
  digitalWrite (led1, HIGH);
  digitalWrite (led2, LOW);

  delay (5000);

  digitalWrite (mp1, LOW);
  digitalWrite (mp2, LOW);
  digitalWrite (led1, LOW);
  digitalWrite (led2, LOW);

  delay (5000);

  digitalWrite (mp1, LOW);
  digitalWrite (mp2, HIGH);
  digitalWrite (led1, LOW);
  digitalWrite (led2, HIGH);

  delay (5000);
  }
