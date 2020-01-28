#define ENABLE_LEFT_PIN 12
#define ENABLE_RIGHT_PIN 13
#define MOTOR_1_LEFT 5
#define MOTOR_2_LEFT 6
#define MOTOR_1_RIGHT 9
#define MOTOR_2_RIGHT 10
#define PWM 190

void counterIncrement(void);

void setup() {
  // put your setup code here, to run once:
Serial.begin(250000);
pinMode(A0, INPUT);
//Turn On Motor Forward to calculate 1 step
pinMode( ENABLE_LEFT_PIN, OUTPUT);
pinMode( ENABLE_RIGHT_PIN, OUTPUT);
pinMode( MOTOR_1_LEFT, OUTPUT);
pinMode( MOTOR_2_LEFT, OUTPUT);
pinMode( MOTOR_1_RIGHT, OUTPUT);
pinMode( MOTOR_2_RIGHT, OUTPUT);
digitalWrite(ENABLE_LEFT_PIN, HIGH);
digitalWrite(ENABLE_RIGHT_PIN, HIGH);

}

int counter = 0;
int enRead = 0;
unsigned long oldTimer = 0;
unsigned long currentMicros = 0;
unsigned long currentTime = 0;
static unsigned long StartTime = 0;
static bool flag = true;
static bool show = true;
void loop() {
  
  if(flag)
  {
        // Left forward
    analogWrite(MOTOR_1_LEFT, LOW);
    analogWrite(MOTOR_2_LEFT, PWM);
    // right forward
    analogWrite(MOTOR_1_RIGHT, LOW);
    analogWrite(MOTOR_2_RIGHT, PWM);
    StartTime = millis();
    flag = false;
  }
//          Serial.print("delta Time: ");
// 750 represents 30cm because R = 25 ticks/cm
  if((counter) <= 750)
  {

    counterIncrement();
  }
  else
  {
    currentTime = millis();
    currentMicros = micros();
    // Left forward
    analogWrite(MOTOR_1_LEFT, LOW);
    analogWrite(MOTOR_2_LEFT, LOW);
    // right forward
    analogWrite(MOTOR_1_RIGHT, LOW);
    analogWrite(MOTOR_2_RIGHT, LOW);
    if(show)
    {
      Serial.print("encoder Counter: ");
      Serial.println(counter);
      Serial.print("Total Time Elapsed: ");
      Serial.println(currentTime - StartTime);
      Serial.print("Sample Time: ");
      Serial.println(currentMicros - oldTimer);
      show = false;
    }
  }
  oldTimer = micros();
  delayMicroseconds(500);
}

void counterIncrement(void)
{
    static int oldEnRead = enRead;
   
  enRead = analogRead(A0);
//  Serial.print("encoder Counter: ");
//    Serial.println(enRead);
  if(((enRead > 135) && (oldEnRead < 135)) 
|| ((enRead < 135) && (oldEnRead > 135)))
  {
    counter++;
   
  }
  oldEnRead = enRead;
}

