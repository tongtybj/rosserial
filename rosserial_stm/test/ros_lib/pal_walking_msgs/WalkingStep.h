#ifndef _ROS_pal_walking_msgs_WalkingStep_h
#define _ROS_pal_walking_msgs_WalkingStep_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "humanoid_nav_msgs/StepTarget.h"
#include "std_msgs/Duration.h"

namespace pal_walking_msgs
{

  class WalkingStep : public ros::Msg
  {
    public:
      std_msgs::Header header;
      humanoid_nav_msgs::StepTarget step_target;
      std_msgs::Duration step_duration;
      int32_t step_list_size;

    WalkingStep():
      header(),
      step_target(),
      step_duration(),
      step_list_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->step_target.serialize(outbuffer + offset);
      offset += this->step_duration.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_step_list_size;
      u_step_list_size.real = this->step_list_size;
      *(outbuffer + offset + 0) = (u_step_list_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step_list_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step_list_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step_list_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->step_list_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->step_target.deserialize(inbuffer + offset);
      offset += this->step_duration.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_step_list_size;
      u_step_list_size.base = 0;
      u_step_list_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step_list_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step_list_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step_list_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->step_list_size = u_step_list_size.real;
      offset += sizeof(this->step_list_size);
     return offset;
    }

    const char * getType(){ return "pal_walking_msgs/WalkingStep"; };
    const char * getMD5(){ return "71c9b6abe3794dbf1d1e8705aadecb82"; };

  };

}
#endif