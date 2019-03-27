/*  Kuka Gripper
 *  Author: Andrew Ott
 *  Date:   03-26-2019
 *  
 *  This program controls a 3D printed gripper for a kuka robot arm.
 *  The servo is able to open and close the gripper and a feedback
 *  loop is made with the use of force sensing resistors.
 */

#include <servo.h>

//creates servo object to control a servo
Servo servo;

//servo signal connect to digital pin 8
int gripClose= 8;

//force sensor connected to pin 9
int fsrIn= 9;
int fsrReading;

int gripOpen= 10;

void setup() 
{
  Serial.begin(9600);
  
  //attaches servo connected at pin 2 to the servo object
  servo.attach(2);

  //sets gripClose(pin 8) to be a digital input
  pinMode(gripClose, INPUT);

  //sets gripOpen(pin 10) to be a digital input
  pinMode(gripOpen, INPUT);
}

void loop() 
{
  //initializes fsrReading
  fsrReading = analogRead(fsrIn);

  //prints analog values of fsr
  Serial.print ("Analog reading= ");
  Serial.print (fsrReading);
  
  //closes gripper if a high is received to gripClose(pin 8)
  if (gripClose == HIGH)
  {
    servo.write(1300);
  }

  //stops closing gripper once a certain level of force is achieved
  else if (fsrReading >= 500)
  {
    servo.write(1450);
  }

  //opens gripper once if a high is received to gripOpen(pin 10)
  else if (gripOpen == HIGH)
  {
    servo.write(1700);
  }
  
  delay (100);  
}
