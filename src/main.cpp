#include <Arduino.h>
#include <Helpers.h>
#include <L298N.h>
#include <PinMap.h>

#define JOYSTICK_MIN 0.0
#define JOYSTICK_MAX 1.0
#define PWM_MIN 0.0
#define PWM_MAX 255.0

const long BAUD_RATE = 250000;

L298N backRight(ENA, IN1, IN2);
L298N frontRight(ENB, IN3, IN4);
L298N frontLeft(ENC, IN5, IN4);
L298N backLeft(END, IN7, IN8);

float  joystick_val = 0; 
float  pwmOutput    = PWM_MIN;
char   command[20];

void setup() {

  pinMode(ledPin, OUTPUT);
 
  Serial.begin( BAUD_RATE );
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  
  frontLeft.setSpeed( PWM_MIN );
  backLeft.setSpeed( PWM_MIN );
  frontRight.setSpeed( PWM_MIN );
  backRight.setSpeed( PWM_MIN );
  
}

void loop() {
  
  // Read data only when available.
  /*if (Serial.available() > 0) {
   
    Serial.println( 'BAR' );
    
    Serial.readBytesUntil(':',command, 8); // First read command.
    joystick_val = Serial.parseFloat(); // Then the command value.
    pwmOutput = mapf(joystick_val, JOYSTICK_MIN, JOYSTICK_MAX, PWM_MIN, PWM_MAX); // Convert to PWM value.
    
    Serial.print( command );
    Serial.print( ":" );
    Serial.println( pwmOutput );

   }

   if(strcmp(command, "x1")  == 0){
    analogWrite(ledPin, pwmOutput);
    frontLeft.setSpeed( pwmOutput );
   }else if(strcmp(command, "x2")  == 0){
    frontRight.setSpeed( pwmOutput );
  }*/

}