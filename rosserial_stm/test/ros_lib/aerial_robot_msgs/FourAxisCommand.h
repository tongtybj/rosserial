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
      uint8_t base_throttle_length;
      float st_base_throttle;
      float * base_throttle;

    FourAxisCommand():
      angles(),
      base_throttle_length(0), base_throttle(NULL)
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
      *(outbuffer + offset++) = base_throttle_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < base_throttle_length; i++){
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
      uint8_t base_throttle_lengthT = *(inbuffer + offset++);
      if(base_throttle_lengthT > base_throttle_length)
        this->base_throttle = (float*)realloc(this->base_throttle, base_throttle_lengthT * sizeof(float));
      offset += 3;
      base_throttle_length = base_throttle_lengthT;
      for( uint8_t i = 0; i < base_throttle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_base_throttle;
      u_st_base_throttle.base = 0;
      u_st_base_throttle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_base_throttle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_base_throttle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_base_throttle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_base_throttle = u_st_base_throttle.real;
      offset += sizeof(this->st_base_throttle);
        memcpy( &(this->base_throttle[i]), &(this->st_base_throttle), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/FourAxisCommand"; };
    const char * getMD5(){ return "7358e7c9be3cfaa92377f4a91a2f3751"; };

  };

}
#endif