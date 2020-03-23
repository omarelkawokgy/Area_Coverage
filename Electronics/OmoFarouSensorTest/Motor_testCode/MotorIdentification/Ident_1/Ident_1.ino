//Macros definition
#define E_PIN A0
#define DELTA_T 10000
#define DELTA_TICKS 15000
#define MOTOR_1_RIGHT 9
#define MOTOR_2_RIGHT 10
#define PWM_VLOW 50
#define PWM_LOW 100
#define PWM_MED 150
#define PWM_HIGH 200
#define PWM_VHIG 250

//Global variables declaration
unsigned short counter = 0;
unsigned short enRead;
float tempTimer = 0;

//local function declaration
void counterIncrement(void);
void SpeedTimerRoutine(int pwm);

void setup() {
  // put your setup code here, to run once:
  pinMode(E_PIN, INPUT);
  pinMode( MOTOR_1_RIGHT, OUTPUT);
  pinMode( MOTOR_2_RIGHT, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  SpeedTimerRoutine(PWM_VLOW);
  SpeedTimerRoutine(PWM_LOW);
  SpeedTimerRoutine(PWM_MED);
  SpeedTimerRoutine(PWM_HIGH);
  SpeedTimerRoutine(PWM_VHIG);
}

void SpeedTimerRoutine(int pwm)
{
    delay(100);
  // right forward
  analogWrite(MOTOR_1_RIGHT, LOW);
  analogWrite(MOTOR_2_RIGHT, pwm);
  tempTimer = millis();
  while ((counter) < DELTA_TICKS)
  {
    counterIncrement();
    //    Serial.println(counter);
  }
  // right stop
  analogWrite(MOTOR_1_RIGHT, LOW);
  analogWrite(MOTOR_2_RIGHT, LOW);
  Serial.println((millis() - tempTimer));
  counter = 0;
}

void counterIncrement(void)
{
  static int oldEnRead = enRead;

  enRead = analogRead(E_PIN);
  //  Serial.print("encoder reading: ");
  //    Serial.println(enRead);
  if (((enRead > 100) && (oldEnRead < 100)))
    //|| ((enRead < 100) && (oldEnRead > 100)))
  {
    counter++;
    //
  }
  oldEnRead = enRead;
}

