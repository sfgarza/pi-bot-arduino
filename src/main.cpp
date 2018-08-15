#include <Arduino.h>
#include <Servo.h>
#include <Helpers.h>
#include <L298N.h>
#include <PinMap.h>

// Serial communication baud rate set to the highest rate an arduino mega can handle.
const long BAUD_RATE = 250000;

// Initialize your motors. Pin Constants can be defined in lib/PinMap/src/PinMap.h
L298N backRight(ENA, IN1, IN2);
L298N frontRight(ENB, IN3, IN4);
L298N frontLeft(ENC, IN5, IN6);
L298N backLeft(END, IN7, IN8);

float  joystick_val = 0; 
String command, value;

void setup() {

  pinMode(ledPin, OUTPUT);
 
  Serial.begin( BAUD_RATE );
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  
  frontLeft.stop();
  backLeft.stop();
  frontRight.stop();
  backRight.stop();
  
}

void loop() {
  
  // Read data only when available.
  if ( Serial.available() > 0 ) {
    
    // Parse Commands.
    command = Serial.readStringUntil(':'); // First read command.
    value   = Serial.readStringUntil(';'); // Then read value.
    joystick_val = value.toFloat();
    
    //i.e. j1:0.23;
    if(command.equals( "j1" )  == 0){ 
      frontLeft.move( joystick_val );
      backLeft.move( joystick_val );
    //i.e. j2:-1.00;
    }else if( command.equals( "j2" )  == 0){
      frontRight.move( joystick_val );
      backRight.move( joystick_val );
    }
   }
   
}