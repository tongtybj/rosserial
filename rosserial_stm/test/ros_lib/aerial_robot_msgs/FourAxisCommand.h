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
      float angles[2];
      float yaw_pi_term[6];
      float throttle_pid_term[6];

    FourAxisCommand():
      angles(),
      yaw_pi_term(),
      throttle_pid_term()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 2; i++){
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
      } u_yaw_pi_termi;
      u_yaw_pi_termi.real = this->yaw_pi_term[i];
      *(outbuffer + offset + 0) = (u_yaw_pi_termi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_pi_termi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_pi_termi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_pi_termi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_pi_term[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_throttle_pid_termi;
      u_throttle_pid_termi.real = this->throttle_pid_term[i];
      *(outbuffer + offset + 0) = (u_throttle_pid_termi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle_pid_termi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle_pid_termi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle_pid_termi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle_pid_term[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 2; i++){
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
      } u_yaw_pi_termi;
      u_yaw_pi_termi.base = 0;
      u_yaw_pi_termi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_pi_termi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_pi_termi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_pi_termi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_pi_term[i] = u_yaw_pi_termi.real;
      offset += sizeof(this->yaw_pi_term[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_throttle_pid_termi;
      u_throttle_pid_termi.base = 0;
      u_throttle_pid_termi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle_pid_termi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle_pid_termi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle_pid_termi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle_pid_term[i] = u_throttle_pid_termi.real;
      offset += sizeof(this->throttle_pid_term[i]);
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/FourAxisCommand"; };
    const char * getMD5(){ return "b03945b198b8a4fe8338b2e81e4b191e"; };

  };

}
#endif