#ifndef _ROS_aerial_robot_msgs_PwmInfo_h
#define _ROS_aerial_robot_msgs_PwmInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "aerial_robot_msgs/MotorInfo.h"

namespace aerial_robot_msgs
{

  class PwmInfo : public ros::Msg
  {
    public:
      float min_thrust;
      float max_thrust;
      float abs_max_pwm;
      float force_landing_thrust;
      uint8_t pwm_conversion_mode;
      uint8_t motor_info_length;
      aerial_robot_msgs::MotorInfo st_motor_info;
      aerial_robot_msgs::MotorInfo * motor_info;

    PwmInfo():
      min_thrust(0),
      max_thrust(0),
      abs_max_pwm(0),
      force_landing_thrust(0),
      pwm_conversion_mode(0),
      motor_info_length(0), motor_info(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_min_thrust;
      u_min_thrust.real = this->min_thrust;
      *(outbuffer + offset + 0) = (u_min_thrust.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_thrust.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_thrust.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_thrust.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_thrust);
      union {
        float real;
        uint32_t base;
      } u_max_thrust;
      u_max_thrust.real = this->max_thrust;
      *(outbuffer + offset + 0) = (u_max_thrust.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_thrust.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_thrust.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_thrust.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_thrust);
      union {
        float real;
        uint32_t base;
      } u_abs_max_pwm;
      u_abs_max_pwm.real = this->abs_max_pwm;
      *(outbuffer + offset + 0) = (u_abs_max_pwm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_abs_max_pwm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_abs_max_pwm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_abs_max_pwm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->abs_max_pwm);
      union {
        float real;
        uint32_t base;
      } u_force_landing_thrust;
      u_force_landing_thrust.real = this->force_landing_thrust;
      *(outbuffer + offset + 0) = (u_force_landing_thrust.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_landing_thrust.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force_landing_thrust.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force_landing_thrust.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->force_landing_thrust);
      *(outbuffer + offset + 0) = (this->pwm_conversion_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm_conversion_mode);
      *(outbuffer + offset++) = motor_info_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motor_info_length; i++){
      offset += this->motor_info[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_min_thrust;
      u_min_thrust.base = 0;
      u_min_thrust.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_thrust.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_thrust.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_thrust.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_thrust = u_min_thrust.real;
      offset += sizeof(this->min_thrust);
      union {
        float real;
        uint32_t base;
      } u_max_thrust;
      u_max_thrust.base = 0;
      u_max_thrust.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_thrust.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_thrust.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_thrust.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_thrust = u_max_thrust.real;
      offset += sizeof(this->max_thrust);
      union {
        float real;
        uint32_t base;
      } u_abs_max_pwm;
      u_abs_max_pwm.base = 0;
      u_abs_max_pwm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_abs_max_pwm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_abs_max_pwm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_abs_max_pwm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->abs_max_pwm = u_abs_max_pwm.real;
      offset += sizeof(this->abs_max_pwm);
      union {
        float real;
        uint32_t base;
      } u_force_landing_thrust;
      u_force_landing_thrust.base = 0;
      u_force_landing_thrust.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force_landing_thrust.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force_landing_thrust.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force_landing_thrust.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->force_landing_thrust = u_force_landing_thrust.real;
      offset += sizeof(this->force_landing_thrust);
      this->pwm_conversion_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pwm_conversion_mode);
      uint8_t motor_info_lengthT = *(inbuffer + offset++);
      if(motor_info_lengthT > motor_info_length)
        this->motor_info = (aerial_robot_msgs::MotorInfo*)realloc(this->motor_info, motor_info_lengthT * sizeof(aerial_robot_msgs::MotorInfo));
      offset += 3;
      motor_info_length = motor_info_lengthT;
      for( uint8_t i = 0; i < motor_info_length; i++){
      offset += this->st_motor_info.deserialize(inbuffer + offset);
        memcpy( &(this->motor_info[i]), &(this->st_motor_info), sizeof(aerial_robot_msgs::MotorInfo));
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/PwmInfo"; };
    const char * getMD5(){ return "4952c7bf6220f4619676d14a2e9d87d8"; };

  };

}
#endif