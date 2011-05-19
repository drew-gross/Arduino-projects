//pinouts
#include "WProgram.h"
void playTone(int tone, int length);
void playNote(char note, int length);
void setup();
void loop();
const int speakerPin = 8;
const int buttonPin = 2;
const int potentiometerPin = 0;
//LEDs
const int ledBlinkPin = 13;
const int ledFadePin = 9;
//tempo and frequency related stuff
char note;
//constant max/min values
#define MAX_ANALOG_OUT 255
#define MIN_ANALOG_OUT 0
#define MAX_ANALOG_IN 1023
#define MIN_ANALOG_IN 0
//sensor reading storge
int potentiometerValue = 0;
//timer data
long timeSinceChange = 0;
long lastChangeTime = 0;

void playTone(int tone, int length) {
  timeSinceChange = 0;
  lastChangeTime = millis();
  while (timeSinceChange < potentiometerValue * length) {
    potentiometerValue = analogRead(potentiometerPin);
    analogWrite(ledFadePin, map(potentiometerValue, MIN_ANALOG_IN, MAX_ANALOG_IN, MIN_ANALOG_OUT, MAX_ANALOG_OUT));
    digitalWrite(speakerPin, HIGH);
    digitalWrite(ledBlinkPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    digitalWrite(ledBlinkPin, LOW);
    delayMicroseconds(tone);
    timeSinceChange = millis() - lastChangeTime;
  }
}

void playNote(char note, int length) {
  char names[] = {'c','d','e','f','g','a','b','C'};
  int tones[] = {1915,1700,1519,1432,1275,1136,1014,956};
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], length);
    }
  }
}

void setup() {
  //configure pins
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledBlinkPin, OUTPUT);
  //begin serial
  Serial.begin(9600);
  //initailize variables
  potentiometerValue = analogRead(potentiometerPin);
}

void loop() {
  if (Serial.available() > 0) {
    note = Serial.read();
    playNote(note, 1);
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

