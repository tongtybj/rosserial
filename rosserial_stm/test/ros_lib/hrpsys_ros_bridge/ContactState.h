#ifndef _ROS_hrpsys_ros_bridge_ContactState_h
#define _ROS_hrpsys_ros_bridge_ContactState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class ContactState : public ros::Msg
  {
    public:
      uint8_t state;
      double remaining_time;
      enum { OFF = 0 };
      enum { ON = 1 };

    ContactState():
      state(0),
      remaining_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      union {
        double real;
        uint64_t base;
      } u_remaining_time;
      u_remaining_time.real = this->remaining_time;
      *(outbuffer + offset + 0) = (u_remaining_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remaining_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remaining_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remaining_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_remaining_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_remaining_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_remaining_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_remaining_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->remaining_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
      union {
        double real;
        uint64_t base;
      } u_remaining_time;
      u_remaining_time.base = 0;
      u_remaining_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remaining_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remaining_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remaining_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_remaining_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_remaining_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_remaining_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_remaining_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->remaining_time = u_remaining_time.real;
      offset += sizeof(this->remaining_time);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/ContactState"; };
    const char * getMD5(){ return "fb79aca4abc1c93c62c57fb11cb443a0"; };

  };

}
#endif