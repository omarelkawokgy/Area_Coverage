#define PIN 2
#define LED_PIN 3
//Red and blue LEDs are together when using PIN3 digital.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(PIN, INPUT);
pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(PIN))
  {
Serial.print("Pumper reading: ");
Serial.println();
digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
delay(5);
}
