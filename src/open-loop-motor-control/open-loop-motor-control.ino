#define FIRMWARE_VERSION "v1.0.0"

#define UART_BAUDRATE 9600

#define MOTOR_L1_PIN 5
#define MOTOR_L2_PIN 6
#define MOTOR_R1_PIN 9
#define MOTOR_R2_PIN 10

#define UPDATE_PERIOD_MS 500

#define PWM_VALUE_MAX 255
#define PWM_VALUE_MIN -255

#define MOTOR_L_PWM_INITIAL_VALUE 230 //Adjusted value for straight line
#define MOTOR_R_PWM_INITIAL_VALUE 200

#define MOTOR_PWM_DECREMENT_VALUE 20

#define VARIABLE_SPEED_ENABLE 0

// Compile-time check of initial PWM values
#if ((MOTOR_L_PWM_INITIAL_VALUE < PWM_VALUE_MIN) || (MOTOR_L_PWM_INITIAL_VALUE > PWM_VALUE_MAX))
  #error "MOTOR_L_PWM_INITIAL_VALUE is out of range"
#endif

#if ((MOTOR_R_PWM_INITIAL_VALUE < PWM_VALUE_MIN) || (MOTOR_R_PWM_INITIAL_VALUE > PWM_VALUE_MAX))
  #error "MOTOR_R_PWM_INITIAL_VALUE is out of range"
#endif

// Function to Set Motor Control Parameters
void SetMotorControlParameters(int PWMValue,
                               unsigned int HBridgeControlPinA,
                               unsigned int HBridgeControlPinB)
{
  if (PWMValue >= 0)
  {
    analogWrite(HBridgeControlPinB, PWMValue);
    digitalWrite(HBridgeControlPinA, LOW);
  }
  else
  {
    analogWrite(HBridgeControlPinA, -PWMValue);
    digitalWrite(HBridgeControlPinB, LOW);
  }
}

// Function to Update Motor Speed
void UpdateMotorSpeed(int LeftMotorPWMValue,
                      int RightMotorPWMValue,
                      unsigned long DurationMilliseconds)
{
  // Set Left Motor Control Parameters
  SetMotorControlParameters(LeftMotorPWMValue,
                            MOTOR_L1_PIN,
                            MOTOR_L2_PIN);
  
  // Set Right Motor Control Parameters
  SetMotorControlParameters(RightMotorPWMValue,
                            MOTOR_R1_PIN,
                            MOTOR_R2_PIN);
  
  // Add blocking delay (in ms)
  delay(DurationMilliseconds);
}

// Setup function runs once when board is powered up or reset
void setup()
{
  // Initialise UART
  Serial.begin(UART_BAUDRATE);
  
  // Configure GPIO pins
  pinMode(MOTOR_L1_PIN, OUTPUT);
  pinMode(MOTOR_L2_PIN, OUTPUT);
  pinMode(MOTOR_R1_PIN, OUTPUT);
  pinMode(MOTOR_R2_PIN, OUTPUT);
  
  // Set initial value for digital output pins
  digitalWrite(MOTOR_L1_PIN, LOW);
  digitalWrite(MOTOR_L2_PIN, LOW);
  digitalWrite(MOTOR_R1_PIN, LOW);
  digitalWrite(MOTOR_R2_PIN, LOW);
  
  // Output message to console
  Serial.println("B37VB Motor Control Basics Demonstration");
  Serial.print("Version: ");
  Serial.println(FIRMWARE_VERSION);

  #if VARIABLE_SPEED_ENABLE
    Serial.println("Variable Motor Speed Enabled");
  #endif
}

// Loop function runs over and over again forever
void loop()
{
  static int LeftMotorPWMValue  = MOTOR_L_PWM_INITIAL_VALUE;
  static int RightMotorPWMValue = MOTOR_R_PWM_INITIAL_VALUE;
  
  UpdateMotorSpeed(LeftMotorPWMValue,
                   RightMotorPWMValue,
                   UPDATE_PERIOD_MS);

  #if VARIABLE_SPEED_ENABLE
    if (LeftMotorPWMValue >= MOTOR_PWM_DECREMENT_VALUE)
    {
      LeftMotorPWMValue  -= MOTOR_PWM_DECREMENT_VALUE;
      RightMotorPWMValue -= MOTOR_PWM_DECREMENT_VALUE;
    }
    else
    {
      LeftMotorPWMValue  = MOTOR_L_PWM_INITIAL_VALUE;
      RightMotorPWMValue = MOTOR_R_PWM_INITIAL_VALUE;
    }
  #endif
}
