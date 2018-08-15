#ifndef L298N_h
#define L298N_h

#include "Arduino.h"
#include "MotorController.h"

class L298N: public MotorController{
   public:
      L298N(uint8_t pinEnable, uint8_t pinIN1, uint8_t pinIN2);
      void move(float velocity);
      float getVelocity();
      void stop();
      boolean isMoving();
   protected:
     static const int VELOCITY_MIN = 0;
     static const int VELOCITY_MAX = 1;
   private:
      byte _pinEnable;
      byte _pinIN1;
      byte _pinIN2;
      byte _pwmVal;
      static const byte PWM_MIN = 0;
      static const byte PWM_MAX = 255;
      float _velocity;
      Direction _direction;
      bool _isMoving;
      void setDirection();
      void setSpeed();
};

#endif