/*Implementation of macro functions*/
#define MICRO_SECONDS_TO_CM(X) X / 29.4118 / 2
#define inPin 7
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
double distance = 0;
void loop() {
  // put your main code here, to run repeatedly:
  /* the ultrasonic is triggered by a HIGH pulse of 2 or more microseconds 
   so give a short LOW pulse beforehand to ensure a clean HIGH pulse*/
  pinMode(inPin, OUTPUT);
  
  digitalWrite(inPin, LOW);
  delayMicroseconds(3);
  digitalWrite(inPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(inPin, LOW);

  /* read the signal from the sensor*/
  pinMode(inPin, INPUT);

  double duration = pulseIn(inPin, HIGH, 1000);

  /* convert micro-seconds to centimeters*/
  distance = MICRO_SECONDS_TO_CM(duration);
  Serial.print("distance: ");
  Serial.println(distance);
//  delay(100);
}
