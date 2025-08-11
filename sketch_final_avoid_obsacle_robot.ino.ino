#include <Servo.h>
#include <NewPing.h>

//motor drivers pins
const int LMF = 11; //LEFT MOTOR FORWARD IN4 5
const int LMB = 3; // LEFT MOTOr BACKWARD IN3 4 
const int RMF = 8; // right motor forward in2 3 
const int RMB = 9; // right motor backward in1 2


//sensors pins
#define trig_pin A2
#define echo_pin A5

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;


NewPing sonar(trig_pin, echo_pin, maximum_distance); 
Servo servo_motor;

void setup()
{
  pinMode(RMF, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);
  pinMode(RMB, OUTPUT);

  servo_motor.attach(12);

  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100); 

}

void loop()
{
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if(distance <= 20)
  {
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft)
    {
      turnRight();
      moveStop();
    }
    else
    {
      turnLeft();
      moveStop();
    }
  }
  else
  {
    moveForward();
  }

  distance = readPing();
}

int lookRight()
{
  servo_motor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft()
{
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing()
{
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm=250;
  }
  return cm;
}

void moveStop()
{
  digitalWrite(RMF, LOW);
  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);
  digitalWrite(LMB, LOW);
}

void moveForward()
{
  if(!goesForward)
  {
    goesForward=true;

    digitalWrite(LMF, HIGH);
    digitalWrite(RMF, HIGH);

    digitalWrite(LMB, LOW);
    digitalWrite(RMB, LOW);
  }
}

void moveBackward()
{
  goesForward=false;

  digitalWrite(LMB, HIGH);
  digitalWrite(RMB, HIGH);

  digitalWrite(LMF, LOW);
  digitalWrite(RMF, LOW);

}

void turnRight()
{
  digitalWrite(LMF, HIGH);
  digitalWrite(RMB, HIGH);

  digitalWrite(LMB, LOW);
  digitalWrite(RMF, LOW);

  delay(500);

  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);

  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);

}

void turnLeft()
{
  digitalWrite(LMB, HIGH);
  digitalWrite(RMF, HIGH);

  digitalWrite(LMF, LOW);
  digitalWrite(RMB, LOW);

  delay(500);

  digitalWrite(LMF, HIGH);
  digitalWrite(RMF, HIGH);

  digitalWrite(LMB, LOW);
  digitalWrite(RMB, LOW);
}