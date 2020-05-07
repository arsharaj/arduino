#include <SoftwareSerial.h>
SoftwareSerial bt(0, 1); // RX, TX

#define LM1 4 // left motor M1a
#define LM2 5 // left motor M2a
#define RM1 6 // right motor M2a
#define RM2 7 // right motor M2b

void setup()
{
  Serial.begin(9600);
  bt.begin(9600);
  delay(100);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop()
{
  String comm = "";

  while (!bt.available() > 0);
  while (bt.available())
  {
    comm += char(bt.read());
    delay(2);
  }
  comm.trim();
  Serial.println(comm);

  if (comm == "A")
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  else if (comm == "B")
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  else if (comm == "C")
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  else if (comm == "D")
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  else if (comm == "E")
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  comm = "";
}
