#define PIN_L1 5

void setup()
{
 Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(PIN_L1));
}
