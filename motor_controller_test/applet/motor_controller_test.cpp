#define motor1_1 5  //remember to change these pin values to the ones you used!
#define motor1_2 6
#define motor2_1 9
#define motor2_2 10
#define light1 5
#define light2 4
#define button 8
#define SLEEP 1500

#include "WProgram.h"
void setup();
void loop();
void setup()
{
   pinMode(motor1_1, OUTPUT);
   pinMode(motor1_2, OUTPUT);
   pinMode(motor2_1, OUTPUT);
   pinMode(motor2_2, OUTPUT);
   pinMode(button, INPUT);
   digitalWrite(motor1_1, LOW);
   digitalWrite(motor1_2, LOW);
   
   //digitalWrite(PIN_IN2, HIGH);
   
   Serial.begin(9600);
   
}

void loop()
{

 while (true)
  {
     Serial.println(digitalRead(button));
    if (digitalRead(button)){
     analogWrite(motor1_1, 120);  //PWM power, we need to step this to whatever we give the motor...
     analogWrite(motor2_1, 80);
    } else {
     analogWrite(motor1_1, 0);  //PWM power, we need to step this to whatever we give the motor...
     analogWrite(motor2_1, 0);
    }
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

