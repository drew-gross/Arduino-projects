#include <Servo.h> 

// create servo object to control a servo 
#include "WProgram.h"
void setup();
void loop();
void waitForCommand();
Servo Xservo;
Servo Yservo;
int XservoPin = 3;
int YservoPin = 5;
int XservoVal = 0;
int YservoVal = 0;
boolean val = false;

static int sweepDelay = 100;
static int serialDelay = 300;
static int maxServo = 180;

void setup() { 
  Serial.begin(9600);
  Xservo.attach(XservoPin);
  Yservo.attach(YservoPin);
  pinMode(13, OUTPUT);
} 

void loop() {
  waitForCommand();
  XservoVal = Serial.read();
  YservoVal = Serial.read();
  Xservo.write(XservoVal);
  Yservo.write(YservoVal);
  delay(sweepDelay);
} 

void waitForCommand() {
  while (Serial.available() <= 1) {
    Serial.print(0, DEC);
    delay(serialDelay);
  }
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

