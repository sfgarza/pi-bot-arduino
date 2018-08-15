#include "MotorController.h"
#include "RevSpark.h"

RevSpark::RevSpark(uint8_t pinEnable){
  _pinEnable = pinEnable;
  _velocity = 100;
  _isMoving = false;
  
  _servo.attach(_pinEnable);
}

void RevSpark::setDirection(){
  _direction = ( signbit( _velocity ) ? BACKWARD : FORWARD );
}

void RevSpark::setSpeed(){
  _pwmVal = this->mapf( _velocity, VELOCITY_MIN, VELOCITY_MAX, PWM_MIN, PWM_MAX); // Convert joystick val to PWM value.
  _servo.writeMicroseconds( _pwmVal );
}

void RevSpark::move( float velocity ){
  _velocity = velocity;

  this->setDirection();
  this->setSpeed();
  
  _isMoving = true;
}

float RevSpark::getVelocity(){
  return _velocity;
}

void RevSpark::stop(){
  _servo.writeMicroseconds(PWM_STOP);
  _isMoving = false;
}


boolean RevSpark::isMoving(){
  return _isMoving;
}