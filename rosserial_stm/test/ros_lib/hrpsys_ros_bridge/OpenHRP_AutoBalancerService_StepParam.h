#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_StepParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_StepParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_StepParam : public ros::Msg
  {
    public:
      double step_height;
      double step_time;
      double toe_angle;
      double heel_angle;

    OpenHRP_AutoBalancerService_StepParam():
      step_height(0),
      step_time(0),
      toe_angle(0),
      heel_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_step_height;
      u_step_height.real = this->step_height;
      *(outbuffer + offset + 0) = (u_step_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_step_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_step_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_step_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_step_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->step_height);
      union {
        double real;
        uint64_t base;
      } u_step_time;
      u_step_time.real = this->step_time;
      *(outbuffer + offset + 0) = (u_step_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_step_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_step_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_step_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_step_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->step_time);
      union {
        double real;
        uint64_t base;
      } u_toe_angle;
      u_toe_angle.real = this->toe_angle;
      *(outbuffer + offset + 0) = (u_toe_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_toe_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_toe_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_toe_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_toe_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_toe_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_toe_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_toe_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->toe_angle);
      union {
        double real;
        uint64_t base;
      } u_heel_angle;
      u_heel_angle.real = this->heel_angle;
      *(outbuffer + offset + 0) = (u_heel_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heel_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heel_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heel_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heel_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heel_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heel_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heel_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heel_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_step_height;
      u_step_height.base = 0;
      u_step_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_step_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_step_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_step_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_step_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->step_height = u_step_height.real;
      offset += sizeof(this->step_height);
      union {
        double real;
        uint64_t base;
      } u_step_time;
      u_step_time.base = 0;
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->step_time = u_step_time.real;
      offset += sizeof(this->step_time);
      union {
        double real;
        uint64_t base;
      } u_toe_angle;
      u_toe_angle.base = 0;
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->toe_angle = u_toe_angle.real;
      offset += sizeof(this->toe_angle);
      union {
        double real;
        uint64_t base;
      } u_heel_angle;
      u_heel_angle.base = 0;
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heel_angle = u_heel_angle.real;
      offset += sizeof(this->heel_angle);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_StepParam"; };
    const char * getMD5(){ return "e5cf9e499f1e01973e9491c2d02ea815"; };

  };

}
#endif