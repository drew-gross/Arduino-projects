#define motor1_1 5  //remember to change these pin values to the ones you used!
#define motor1_2 6
#define motor2_1 9
#define motor2_2 10
#define light1 4
#define light2 5
#define button 8
#define SLEEP 1500

void setup()
{
   pinMode(motor1_1, OUTPUT);
   pinMode(motor1_2, OUTPUT);
   pinMode(motor2_1, OUTPUT);
   pinMode(motor2_2, OUTPUT);
   digitalWrite(motor1_1, LOW);
   digitalWrite(motor1_2, LOW);
   
   //digitalWrite(PIN_IN2, HIGH);
   
   Serial.begin(9600);
   
}

void loop()
{

 for(int i = 0; i <= 255; i += 25)
  {
     Serial.println(float(255 / float(255/5)));
     Serial.println(analogRead(light1));
     Serial.println(analogRead(light2));
     Serial.println(analogRead(button));
     analogWrite(motor1_1, 255);  //PWM power, we need to step this to whatever we give the motor...
     analogWrite(motor2_1, 255);
     delay(SLEEP);
  } 
  
}

