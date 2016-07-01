#ifndef _ROS_hrpsys_ros_bridge_RTC_Size3D_h
#define _ROS_hrpsys_ros_bridge_RTC_Size3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class RTC_Size3D : public ros::Msg
  {
    public:
      double l;
      double w;
      double h;

    RTC_Size3D():
      l(0),
      w(0),
      h(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_l;
      u_l.real = this->l;
      *(outbuffer + offset + 0) = (u_l.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l);
      union {
        double real;
        uint64_t base;
      } u_w;
      u_w.real = this->w;
      *(outbuffer + offset + 0) = (u_w.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_w.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_w.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_w.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_w.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_w.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_w.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_w.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->w);
      union {
        double real;
        uint64_t base;
      } u_h;
      u_h.real = this->h;
      *(outbuffer + offset + 0) = (u_h.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_h.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_h.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_h.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_h.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_h.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_h.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_h.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->h);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_l;
      u_l.base = 0;
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l = u_l.real;
      offset += sizeof(this->l);
      union {
        double real;
        uint64_t base;
      } u_w;
      u_w.base = 0;
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->w = u_w.real;
      offset += sizeof(this->w);
      union {
        double real;
        uint64_t base;
      } u_h;
      u_h.base = 0;
      u_h.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_h.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_h.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_h.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_h.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_h.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_h.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_h.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->h = u_h.real;
      offset += sizeof(this->h);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/RTC_Size3D"; };
    const char * getMD5(){ return "09ee73e9959cb322594a7a11cdaf6fce"; };

  };

}
#endif