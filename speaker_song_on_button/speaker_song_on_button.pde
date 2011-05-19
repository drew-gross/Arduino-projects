//pinouts
const int speakerPin = 8;
const int buttonPin = 2;
const int potentiometerPin = 0;
//LEDs
const int ledBlinkPin = 13;
const int ledFadePin = 9;
//tempo and frequency related stuff
const int length = 14;
const char notes[] = "ccggaagffeeddc";
const int beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};
const int tempo = 300;
//constant max/min values
#define MAX_ANALOG_OUT 255
#define MIN_ANALOG_OUT 0
#define MAX_ANALOG_IN 1023
#define MIN_ANALOG_IN 0
//state machine
int state = 0;
#define IDLE_STATE 0
#define MUSIC_STATE 1
//sensor reading storge
int potentiometerValue = 0;
//timer data
long timeSinceChange = 0;
long lastChangeTime = 0;

void playTone(int tone, int length) {
  timeSinceChange = 0;
  lastChangeTime = millis();
  while (timeSinceChange < potentiometerValue * length ) {
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
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledBlinkPin, OUTPUT);
}

void loop() {
  if (state == MUSIC_STATE) {
    for (int i = 0; i < length; i++) {
      potentiometerValue = analogRead(potentiometerPin);
      if (notes[i] == ' ') {
        delay(beats[i] * potentiometerValue);
      } else {
        playNote(notes[i], beats[i]);
      }
      delay(potentiometerValue/2);
    }
    state = IDLE_STATE;
  } else if (state == IDLE_STATE) {
    analogWrite(ledFadePin, 0);
    if (digitalRead(buttonPin) == HIGH) {
      state = MUSIC_STATE;
    }
  }
}
