#ifndef _ROS_aerial_robot_msgs_FourAxisCommand_h
#define _ROS_aerial_robot_msgs_FourAxisCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_msgs
{

  class FourAxisCommand : public ros::Msg
  {
    public:
      float angles[3];
      float base_throttle[6];

    FourAxisCommand():
      angles(),
      base_throttle()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_anglesi;
      u_anglesi.real = this->angles[i];
      *(outbuffer + offset + 0) = (u_anglesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anglesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anglesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anglesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angles[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_base_throttlei;
      u_base_throttlei.real = this->base_throttle[i];
      *(outbuffer + offset + 0) = (u_base_throttlei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_base_throttlei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_base_throttlei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_base_throttlei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->base_throttle[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_anglesi;
      u_anglesi.base = 0;
      u_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angles[i] = u_anglesi.real;
      offset += sizeof(this->angles[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_base_throttlei;
      u_base_throttlei.base = 0;
      u_base_throttlei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_base_throttlei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_base_throttlei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_base_throttlei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->base_throttle[i] = u_base_throttlei.real;
      offset += sizeof(this->base_throttle[i]);
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/FourAxisCommand"; };
    const char * getMD5(){ return "d76f5497366bf918d240b8929e3c76af"; };

  };

}
#endif