#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H
 
#include "MotorController.h"
 
class MotorController {
public:
    typedef enum
    {
        FORWARD  = 0,
        BACKWARD = 1
    } Direction;
    /**
     * Set the velocity of the motor.
     * @param velocity The velocity to be set. Accepts any float value between -1 and 1.
     */
    virtual void move( float velocity ) = 0;
    /**
     * Stop motor.
     */
    virtual void stop() = 0;
    /**
     * Get current motor speed.
     * @return [description]
     */
    virtual float getVelocity() = 0;
    
    /**
     * Is motor moving?
     * 
     * @return true if motor is currently moving.
     */
    virtual bool isMoving() = 0;
protected:
  static const int VELOCITY_MIN;
  static const int VELOCITY_MAX;
  bool _isMoving;
  float _velocity;
  float mapf(float x, float in_min, float in_max, float out_min, float out_max)
  {
       return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
};
 
#endif
