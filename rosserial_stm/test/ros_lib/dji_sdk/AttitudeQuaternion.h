#ifndef _ROS_dji_sdk_AttitudeQuaternion_h
#define _ROS_dji_sdk_AttitudeQuaternion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace dji_sdk
{

  class AttitudeQuaternion : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t ts;
      float q0;
      float q1;
      float q2;
      float q3;
      float wx;
      float wy;
      float wz;

    AttitudeQuaternion():
      header(),
      ts(0),
      q0(0),
      q1(0),
      q2(0),
      q3(0),
      wx(0),
      wy(0),
      wz(0)
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
      } u_q0;
      u_q0.real = this->q0;
      *(outbuffer + offset + 0) = (u_q0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q0.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q0);
      union {
        float real;
        uint32_t base;
      } u_q1;
      u_q1.real = this->q1;
      *(outbuffer + offset + 0) = (u_q1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q1);
      union {
        float real;
        uint32_t base;
      } u_q2;
      u_q2.real = this->q2;
      *(outbuffer + offset + 0) = (u_q2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q2);
      union {
        float real;
        uint32_t base;
      } u_q3;
      u_q3.real = this->q3;
      *(outbuffer + offset + 0) = (u_q3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_q3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_q3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_q3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->q3);
      union {
        float real;
        uint32_t base;
      } u_wx;
      u_wx.real = this->wx;
      *(outbuffer + offset + 0) = (u_wx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wx);
      union {
        float real;
        uint32_t base;
      } u_wy;
      u_wy.real = this->wy;
      *(outbuffer + offset + 0) = (u_wy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wy);
      union {
        float real;
        uint32_t base;
      } u_wz;
      u_wz.real = this->wz;
      *(outbuffer + offset + 0) = (u_wz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wz);
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
      } u_q0;
      u_q0.base = 0;
      u_q0.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q0.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q0.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q0.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q0 = u_q0.real;
      offset += sizeof(this->q0);
      union {
        float real;
        uint32_t base;
      } u_q1;
      u_q1.base = 0;
      u_q1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q1 = u_q1.real;
      offset += sizeof(this->q1);
      union {
        float real;
        uint32_t base;
      } u_q2;
      u_q2.base = 0;
      u_q2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q2 = u_q2.real;
      offset += sizeof(this->q2);
      union {
        float real;
        uint32_t base;
      } u_q3;
      u_q3.base = 0;
      u_q3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_q3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_q3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_q3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->q3 = u_q3.real;
      offset += sizeof(this->q3);
      union {
        float real;
        uint32_t base;
      } u_wx;
      u_wx.base = 0;
      u_wx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wx = u_wx.real;
      offset += sizeof(this->wx);
      union {
        float real;
        uint32_t base;
      } u_wy;
      u_wy.base = 0;
      u_wy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wy = u_wy.real;
      offset += sizeof(this->wy);
      union {
        float real;
        uint32_t base;
      } u_wz;
      u_wz.base = 0;
      u_wz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wz = u_wz.real;
      offset += sizeof(this->wz);
     return offset;
    }

    const char * getType(){ return "dji_sdk/AttitudeQuaternion"; };
    const char * getMD5(){ return "999d24c7cb273aa4f2c6044f85cac84c"; };

  };

}
#endif