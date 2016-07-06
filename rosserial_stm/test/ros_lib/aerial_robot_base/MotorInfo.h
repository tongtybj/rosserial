#ifndef _ROS_aerial_robot_base_MotorInfo_h
#define _ROS_aerial_robot_base_MotorInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_base
{

  class MotorInfo : public ros::Msg
  {
    public:
      float f_pwm_rate;
      float f_pwm_offset;
      float m_f_rate;
      float pwm_rate;

    MotorInfo():
      f_pwm_rate(0),
      f_pwm_offset(0),
      m_f_rate(0),
      pwm_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_f_pwm_rate;
      u_f_pwm_rate.real = this->f_pwm_rate;
      *(outbuffer + offset + 0) = (u_f_pwm_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f_pwm_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f_pwm_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f_pwm_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->f_pwm_rate);
      union {
        float real;
        uint32_t base;
      } u_f_pwm_offset;
      u_f_pwm_offset.real = this->f_pwm_offset;
      *(outbuffer + offset + 0) = (u_f_pwm_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f_pwm_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f_pwm_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f_pwm_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->f_pwm_offset);
      union {
        float real;
        uint32_t base;
      } u_m_f_rate;
      u_m_f_rate.real = this->m_f_rate;
      *(outbuffer + offset + 0) = (u_m_f_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_m_f_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_m_f_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_m_f_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->m_f_rate);
      union {
        float real;
        uint32_t base;
      } u_pwm_rate;
      u_pwm_rate.real = this->pwm_rate;
      *(outbuffer + offset + 0) = (u_pwm_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pwm_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pwm_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pwm_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pwm_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_f_pwm_rate;
      u_f_pwm_rate.base = 0;
      u_f_pwm_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f_pwm_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f_pwm_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f_pwm_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->f_pwm_rate = u_f_pwm_rate.real;
      offset += sizeof(this->f_pwm_rate);
      union {
        float real;
        uint32_t base;
      } u_f_pwm_offset;
      u_f_pwm_offset.base = 0;
      u_f_pwm_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f_pwm_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f_pwm_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f_pwm_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->f_pwm_offset = u_f_pwm_offset.real;
      offset += sizeof(this->f_pwm_offset);
      union {
        float real;
        uint32_t base;
      } u_m_f_rate;
      u_m_f_rate.base = 0;
      u_m_f_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_m_f_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_m_f_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_m_f_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->m_f_rate = u_m_f_rate.real;
      offset += sizeof(this->m_f_rate);
      union {
        float real;
        uint32_t base;
      } u_pwm_rate;
      u_pwm_rate.base = 0;
      u_pwm_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pwm_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pwm_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pwm_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pwm_rate = u_pwm_rate.real;
      offset += sizeof(this->pwm_rate);
     return offset;
    }

    const char * getType(){ return "aerial_robot_base/MotorInfo"; };
    const char * getMD5(){ return "0a32f33b9d1229250db1fed7eafb25f1"; };

  };

}
#endif