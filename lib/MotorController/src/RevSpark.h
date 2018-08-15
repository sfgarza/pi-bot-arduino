#ifndef REVSPARK_h
#define REVSPARK_h

#include "Arduino.h"
#include "Servo.h"
#include "MotorController.h"

class RevSpark: public MotorController{
   public:
      RevSpark(uint8_t pinEnable);
      void move(float velocity);
      float getVelocity();
      void stop();
      boolean isMoving();
  protected:
    static const int VELOCITY_MIN = -1;
    static const int VELOCITY_MAX = 1;
   private:
      byte _pinEnable;
      Servo _servo;
      byte _pinIN1;
      byte _pinIN2;
      byte _pwmVal;
      float _velocity;
      Direction _direction;
      bool _isMoving;
      static const int PWM_MIN = 1000;
      static const int PWM_MAX = 2000;
      static const int PWM_STOP = 1500;
      void setDirection();
      void setSpeed();
};

#endif