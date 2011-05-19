const int buttonPin = 2;
const int ledPin = 13;

int ledState = HIGH;
int buttonStatePostDebounce = 0;
int buttonStatePreDebounce = 0;
int lastButtonState = 0;

long lastDebounceTime = 0;
long debounceDelay = 0;

void setup () {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop () {
  int buttonStatePreDebounce = digitalRead(buttonPin);
  if (lastButtonState != buttonStatePreDebounce) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    buttonStatePostDebounce = buttonStatePreDebounce;
  }
  digitalWrite(ledPin, buttonStatePostDebounce);
  lastButtonState = buttonStatePreDebounce;
}
