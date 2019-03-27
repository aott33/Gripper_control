/*  Kuka Gripper
 *  Author: Andrew Ott
 *  Date:   03-26-2019
 *  
 *  This program controls a 3D printed gripper for a kuka robot arm.
 *  The servo is able to open and close the gripper and a feedback
 *  loop is made with the use of force sensing resistors.
 *  
 *  Analog value for gripper(cup): 750
 */

#include <Servo.h>

//creates servo object to control a servo
Servo servo;

//pins 10 and 11 control servo operation
int gripClose= 7;
int gripOpen= 11;

//pin states
int ipClose=0;
int ipOpen=0;

//force sensor connected to pin 9
int fsrIn= 8;
int fsrReading;

void setup() 
{
  Serial.begin(9600);

  //attaches servo connected at pin 2 to the servo object
  servo.attach(2);

  //sets gripClose(pin 8) to be a digital input
  pinMode(gripClose, INPUT);

  //sets gripOpen(pin 10) to be a digital input
  pinMode(gripOpen, INPUT);

  digitalWrite (gripClose, HIGH);
  digitalWrite (gripOpen, HIGH);
}

void loop() 
{  
  //initializes fsrReading
  fsrReading = analogRead(fsrIn);
  ipClose = digitalRead(gripClose);
  ipOpen = digitalRead(gripOpen);

  //prints analog values of fsr
  Serial.print ("Analog reading= ");
  Serial.println (fsrReading);

  //prints states of digital inputs
  Serial.print("Close Command: ");
  Serial.println (ipClose);
  Serial.print("Open Command: ");
  Serial.println (ipOpen);
  
  
  //closes gripper if a high is received to gripClose(pin 8)
  if (ipClose == HIGH && fsrReading < 750)
  {
    servo.writeMicroseconds(1700);
  }
  
  //opens gripper once if a high is received to gripOpen(pin 10)
  else if (ipOpen == HIGH)
  {
    servo.writeMicroseconds(1300);
  }
  
  else
  {
    servo.writeMicroseconds(1510);
  }
  
  delay (100);  
}
