const int ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println(Serial.read(), DEC);
    delay(1000);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
