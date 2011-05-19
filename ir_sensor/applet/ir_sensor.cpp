#define PIN_L1 5

#include "WProgram.h"
void setup();
void loop();
void setup()
{
 Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(PIN_L1));
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

