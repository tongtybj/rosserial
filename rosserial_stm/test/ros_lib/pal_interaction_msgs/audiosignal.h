#ifndef _ROS_pal_interaction_msgs_audiosignal_h
#define _ROS_pal_interaction_msgs_audiosignal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class audiosignal : public ros::Msg
  {
    public:
      uint8_t channel0_length;
      double st_channel0;
      double * channel0;
      uint8_t channel1_length;
      double st_channel1;
      double * channel1;

    audiosignal():
      channel0_length(0), channel0(NULL),
      channel1_length(0), channel1(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = channel0_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < channel0_length; i++){
      union {
        double real;
        uint64_t base;
      } u_channel0i;
      u_channel0i.real = this->channel0[i];
      *(outbuffer + offset + 0) = (u_channel0i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_channel0i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_channel0i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_channel0i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_channel0i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_channel0i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_channel0i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_channel0i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->channel0[i]);
      }
      *(outbuffer + offset++) = channel1_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < channel1_length; i++){
      union {
        double real;
        uint64_t base;
      } u_channel1i;
      u_channel1i.real = this->channel1[i];
      *(outbuffer + offset + 0) = (u_channel1i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_channel1i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_channel1i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_channel1i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_channel1i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_channel1i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_channel1i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_channel1i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->channel1[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t channel0_lengthT = *(inbuffer + offset++);
      if(channel0_lengthT > channel0_length)
        this->channel0 = (double*)realloc(this->channel0, channel0_lengthT * sizeof(double));
      offset += 3;
      channel0_length = channel0_lengthT;
      for( uint8_t i = 0; i < channel0_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_channel0;
      u_st_channel0.base = 0;
      u_st_channel0.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_channel0.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_channel0.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_channel0.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_channel0.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_channel0.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_channel0.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_channel0.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_channel0 = u_st_channel0.real;
      offset += sizeof(this->st_channel0);
        memcpy( &(this->channel0[i]), &(this->st_channel0), sizeof(double));
      }
      uint8_t channel1_lengthT = *(inbuffer + offset++);
      if(channel1_lengthT > channel1_length)
        this->channel1 = (double*)realloc(this->channel1, channel1_lengthT * sizeof(double));
      offset += 3;
      channel1_length = channel1_lengthT;
      for( uint8_t i = 0; i < channel1_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_channel1;
      u_st_channel1.base = 0;
      u_st_channel1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_channel1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_channel1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_channel1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_channel1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_channel1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_channel1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_channel1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_channel1 = u_st_channel1.real;
      offset += sizeof(this->st_channel1);
        memcpy( &(this->channel1[i]), &(this->st_channel1), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/audiosignal"; };
    const char * getMD5(){ return "9406f94b261ed2ebad808e7af5b61907"; };

  };

}
#endif