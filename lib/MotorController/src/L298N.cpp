#include "MotorController.h"
#include "L298N.h"


L298N::L298N(uint8_t pinEnable, uint8_t pinIN1, uint8_t pinIN2){
  _pinEnable = pinEnable;
  _pinIN1 = pinIN1;
  _pinIN2 = pinIN2;
  _velocity = 100;
  _isMoving = false;

  pinMode(_pinEnable, OUTPUT);
  pinMode(_pinIN1, OUTPUT);
  pinMode(_pinIN2, OUTPUT);
}

void L298N::setDirection(){
  _direction = ( signbit( _velocity ) ? BACKWARD : FORWARD );
  if( _direction == FORWARD){
    digitalWrite(_pinIN1, HIGH);
    digitalWrite(_pinIN2, LOW);
  }
  else{
    digitalWrite(_pinIN1, LOW);
    digitalWrite(_pinIN2, HIGH);
  }
}

void L298N::setSpeed(){
  _pwmVal = this->mapf( abs( _velocity ), VELOCITY_MIN, VELOCITY_MAX, PWM_MIN, PWM_MAX); // Convert joystick val to PWM value.
  analogWrite(_pinEnable, _pwmVal);
}

void L298N::move( float velocity ){
  _velocity = velocity;

  this->setDirection();
  this->setSpeed();
  
  _isMoving = true;
}

float L298N::getVelocity(){
  return _velocity;
}

void L298N::stop(){
  digitalWrite(_pinIN1, LOW);
  digitalWrite(_pinIN2, LOW);

  analogWrite(_pinEnable, PWM_MIN );
  
  _isMoving = false;
}


boolean L298N::isMoving(){
  return _isMoving;
}