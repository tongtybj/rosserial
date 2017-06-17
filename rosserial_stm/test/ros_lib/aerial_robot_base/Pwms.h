#ifndef _ROS_aerial_robot_base_Pwms_h
#define _ROS_aerial_robot_base_Pwms_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_base
{

  class Pwms : public ros::Msg
  {
    public:
      uint8_t motor_value_length;
      uint16_t st_motor_value;
      uint16_t * motor_value;

    Pwms():
      motor_value_length(0), motor_value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = motor_value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motor_value_length; i++){
      *(outbuffer + offset + 0) = (this->motor_value[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_value[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t motor_value_lengthT = *(inbuffer + offset++);
      if(motor_value_lengthT > motor_value_length)
        this->motor_value = (uint16_t*)realloc(this->motor_value, motor_value_lengthT * sizeof(uint16_t));
      offset += 3;
      motor_value_length = motor_value_lengthT;
      for( uint8_t i = 0; i < motor_value_length; i++){
      this->st_motor_value =  ((uint16_t) (*(inbuffer + offset)));
      this->st_motor_value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_motor_value);
        memcpy( &(this->motor_value[i]), &(this->st_motor_value), sizeof(uint16_t));
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_base/Pwms"; };
    const char * getMD5(){ return "2c8c334b8b8efa66767058af395f7c74"; };

  };

}
#endif