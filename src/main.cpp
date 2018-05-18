#include <Arduino.h>
#include <L298N.h>

const long BAUD_RATE = 250000;

#define ledPin 13

// motor one
#define ENA 10
#define IN1 9
#define IN2 8
// motor two
#define ENB 5
#define IN3 7
#define IN4 6

L298N frontLeft(ENA, IN1, IN2);
L298N frontRight(ENB, IN3, IN4);

float  joystick_val = 0; 
float    pwmOutput = 255;
char   command[20];

float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {

  pinMode(ledPin, OUTPUT);
 
  Serial.begin( BAUD_RATE );
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  
}

void loop() {
  
  // Read data only when available.
  if (Serial.available() > 0) {
      
    Serial.readBytesUntil(':',command, 8); // First read command.
    joystick_val = Serial.parseFloat(); // Then the command value.
    pwmOutput = mapf(joystick_val, 0.0, 1.0, 0.0, 255.0); // Convert to PWM value.
    
    Serial.print( command );
    Serial.print( ":" );
    Serial.println( pwmOutput );

   }

   if(strcmp(command, "x1")  == 0){
    analogWrite(ledPin, pwmOutput);
    frontLeft.setSpeed( pwmOutput );
   }else if(strcmp(command, "x2")  == 0){
    frontRight.setSpeed( pwmOutput );
   }

}