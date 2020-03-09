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
float tempTicks = 0;

//local function declaration
void counterIncrement(void);
void SpeedTimerRoutine(void);

void setup() {
  // put your setup code here, to run once:
  pinMode(E_PIN, INPUT);
  pinMode( MOTOR_1_RIGHT, OUTPUT);
  pinMode( MOTOR_2_RIGHT, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
//  SpeedTimerRoutine(PWM_VLOW);
//  SpeedTimerRoutine(PWM_LOW);

  static float Timer = 0;
  
  Timer = millis();
  analogWrite(MOTOR_1_RIGHT, PWM_MED);
  analogWrite(MOTOR_2_RIGHT, LOW);
  while((millis() - Timer) < 3000)
  {
    SpeedTimerRoutine();
  }
  
  Timer = millis();
  analogWrite(MOTOR_1_RIGHT, LOW);
  analogWrite(MOTOR_2_RIGHT, PWM_MED);
  while((millis() - Timer) < 3000)
  {
    SpeedTimerRoutine();
  }
  
  Timer = millis();
  analogWrite(MOTOR_1_RIGHT, PWM_VLOW);
  analogWrite(MOTOR_2_RIGHT, LOW);
  while((millis() - Timer) < 3000)
  {
    SpeedTimerRoutine();
  }
  
  Timer = millis();
  analogWrite(MOTOR_1_RIGHT, LOW);
  analogWrite(MOTOR_2_RIGHT, PWM_VLOW);
  while((millis() - Timer) < 3000)
  {
    SpeedTimerRoutine();
  }
  
  while(1)
  {
    analogWrite(MOTOR_1_RIGHT, LOW);
    analogWrite(MOTOR_2_RIGHT, LOW);
  }
//  SpeedTimerRoutine(PWM_HIGH);
//  SpeedTimerRoutine(PWM_VHIG);
}

void SpeedTimerRoutine()
{
  //delay(100);
  // right forward  
  tempTimer = millis();
  while ((millis() - tempTimer) < 10)
  {
    counterIncrement();
  }
  Serial.println(counter);
}

void counterIncrement(void)
{
  static int oldEnRead = enRead;

  enRead = analogRead(E_PIN);
  if (((enRead > 100) && (oldEnRead < 100)))
  {
    counter++;
  }
  oldEnRead = enRead;
}


