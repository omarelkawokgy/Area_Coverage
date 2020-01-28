#define ENABLE_LEFT_PIN 12
#define ENABLE_RIGHT_PIN 13
#define MOTOR_1_LEFT 5
#define MOTOR_2_LEFT 6
#define MOTOR_1_RIGHT 9
#define MOTOR_2_RIGHT 10

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode( ENABLE_LEFT_PIN, OUTPUT);
pinMode( ENABLE_RIGHT_PIN, OUTPUT);
pinMode( MOTOR_1_LEFT, OUTPUT);
pinMode( MOTOR_2_LEFT, OUTPUT);
pinMode( MOTOR_1_RIGHT, OUTPUT);
pinMode( MOTOR_2_RIGHT, OUTPUT);
digitalWrite(ENABLE_LEFT_PIN, HIGH);
digitalWrite(ENABLE_RIGHT_PIN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(MOTOR_2_LEFT, LOW);
  //increase Speed Gradually forward
  analogWrite(MOTOR_1_LEFT, 10);
  delay(1000);
  analogWrite(MOTOR_1_LEFT, 70);
  delay(1000);
  analogWrite(MOTOR_1_LEFT, 150);
  delay(1000);
  analogWrite(MOTOR_1_LEFT, 200);
  delay(1000);
  analogWrite(MOTOR_1_LEFT, 254);
  delay(1000);
  analogWrite(MOTOR_1_LEFT, LOW);
  //increase speed gradually backward
  analogWrite(MOTOR_2_LEFT, 10);
  delay(1000);
  analogWrite(MOTOR_2_LEFT, 70);
  delay(1000);
  analogWrite(MOTOR_2_LEFT, 150);
  delay(1000);
  analogWrite(MOTOR_2_LEFT, 200);
  delay(1000);
  analogWrite(MOTOR_2_LEFT, 254);
  delay(1000);

    analogWrite(MOTOR_2_RIGHT, LOW);
  //increase Speed Gradually forward
  analogWrite(MOTOR_1_RIGHT, 10);
  delay(1000);
  analogWrite(MOTOR_1_RIGHT, 70);
  delay(1000);
  analogWrite(MOTOR_1_RIGHT, 150);
  delay(1000);
  analogWrite(MOTOR_1_RIGHT, 200);
  delay(1000);
  analogWrite(MOTOR_1_RIGHT, 254);
  delay(1000);
  analogWrite(MOTOR_1_RIGHT, LOW);
  //increase speed gradually backward
  analogWrite(MOTOR_2_RIGHT, 10);
  delay(1000);
  analogWrite(MOTOR_2_RIGHT, 70);
  delay(1000);
  analogWrite(MOTOR_2_RIGHT, 150);
  delay(1000);
  analogWrite(MOTOR_2_RIGHT, 200);
  delay(1000);
  analogWrite(MOTOR_2_RIGHT, 254);
  delay(1000);
  delay(5);
}
