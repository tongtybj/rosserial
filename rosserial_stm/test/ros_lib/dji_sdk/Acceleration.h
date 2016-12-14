#ifndef _ROS_dji_sdk_Acceleration_h
#define _ROS_dji_sdk_Acceleration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace dji_sdk
{

  class Acceleration : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t ts;
      float ax;
      float ay;
      float az;

    Acceleration():
      header(),
      ts(0),
      ax(0),
      ay(0),
      az(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_ts;
      u_ts.real = this->ts;
      *(outbuffer + offset + 0) = (u_ts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ts);
      union {
        float real;
        uint32_t base;
      } u_ax;
      u_ax.real = this->ax;
      *(outbuffer + offset + 0) = (u_ax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ax);
      union {
        float real;
        uint32_t base;
      } u_ay;
      u_ay.real = this->ay;
      *(outbuffer + offset + 0) = (u_ay.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ay.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ay.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ay.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ay);
      union {
        float real;
        uint32_t base;
      } u_az;
      u_az.real = this->az;
      *(outbuffer + offset + 0) = (u_az.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_az.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_az.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_az.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->az);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_ts;
      u_ts.base = 0;
      u_ts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ts = u_ts.real;
      offset += sizeof(this->ts);
      union {
        float real;
        uint32_t base;
      } u_ax;
      u_ax.base = 0;
      u_ax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ax = u_ax.real;
      offset += sizeof(this->ax);
      union {
        float real;
        uint32_t base;
      } u_ay;
      u_ay.base = 0;
      u_ay.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ay.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ay.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ay.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ay = u_ay.real;
      offset += sizeof(this->ay);
      union {
        float real;
        uint32_t base;
      } u_az;
      u_az.base = 0;
      u_az.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_az.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_az.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_az.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->az = u_az.real;
      offset += sizeof(this->az);
     return offset;
    }

    const char * getType(){ return "dji_sdk/Acceleration"; };
    const char * getMD5(){ return "5de5cfee671950d30a03b944f0d1555c"; };

  };

}
#endif