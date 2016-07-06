#ifndef _ROS_kduino_KduinoServo_h
#define _ROS_kduino_KduinoServo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace kduino
{

  class KduinoServo : public ros::Msg
  {
    public:
      int16_t servo_id;
      int16_t servo_value;

    KduinoServo():
      servo_id(0),
      servo_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_servo_id;
      u_servo_id.real = this->servo_id;
      *(outbuffer + offset + 0) = (u_servo_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->servo_id);
      union {
        int16_t real;
        uint16_t base;
      } u_servo_value;
      u_servo_value.real = this->servo_value;
      *(outbuffer + offset + 0) = (u_servo_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_servo_value.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->servo_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_servo_id;
      u_servo_id.base = 0;
      u_servo_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_servo_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->servo_id = u_servo_id.real;
      offset += sizeof(this->servo_id);
      union {
        int16_t real;
        uint16_t base;
      } u_servo_value;
      u_servo_value.base = 0;
      u_servo_value.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_servo_value.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->servo_value = u_servo_value.real;
      offset += sizeof(this->servo_value);
     return offset;
    }

    const char * getType(){ return "kduino/KduinoServo"; };
    const char * getMD5(){ return "13f5474b0ceb1a33e62725e75dd4a3ac"; };

  };

}
#endif