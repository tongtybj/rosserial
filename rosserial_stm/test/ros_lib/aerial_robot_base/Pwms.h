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
      uint16_t motor_value[8];

    Pwms():
      motor_value()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 8; i++){
      *(outbuffer + offset + 0) = (this->motor_value[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_value[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 8; i++){
      this->motor_value[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->motor_value[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->motor_value[i]);
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_base/Pwms"; };
    const char * getMD5(){ return "3c9a5407a09a05386569f869c5a388b1"; };

  };

}
#endif