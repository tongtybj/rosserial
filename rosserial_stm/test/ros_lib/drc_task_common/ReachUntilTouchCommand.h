#ifndef _ROS_SERVICE_ReachUntilTouchCommand_h
#define _ROS_SERVICE_ReachUntilTouchCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace drc_task_common
{

static const char REACHUNTILTOUCHCOMMAND[] = "drc_task_common/ReachUntilTouchCommand";

  class ReachUntilTouchCommandRequest : public ros::Msg
  {
    public:
      uint8_t arm_side;
      geometry_msgs::Vector3 direction;
      float thre;
      float max_dist;
      float dist_step;
      float time_step;
      bool rotation_axis;
      enum { LARM = 1 };
      enum { RARM = 2 };

    ReachUntilTouchCommandRequest():
      arm_side(0),
      direction(),
      thre(0),
      max_dist(0),
      dist_step(0),
      time_step(0),
      rotation_axis(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->arm_side >> (8 * 0)) & 0xFF;
      offset += sizeof(this->arm_side);
      offset += this->direction.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_thre;
      u_thre.real = this->thre;
      *(outbuffer + offset + 0) = (u_thre.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_thre.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_thre.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_thre.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->thre);
      union {
        float real;
        uint32_t base;
      } u_max_dist;
      u_max_dist.real = this->max_dist;
      *(outbuffer + offset + 0) = (u_max_dist.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_dist.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_dist.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_dist.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_dist);
      union {
        float real;
        uint32_t base;
      } u_dist_step;
      u_dist_step.real = this->dist_step;
      *(outbuffer + offset + 0) = (u_dist_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dist_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dist_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dist_step.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dist_step);
      union {
        float real;
        uint32_t base;
      } u_time_step;
      u_time_step.real = this->time_step;
      *(outbuffer + offset + 0) = (u_time_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_step.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_step);
      union {
        bool real;
        uint8_t base;
      } u_rotation_axis;
      u_rotation_axis.real = this->rotation_axis;
      *(outbuffer + offset + 0) = (u_rotation_axis.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rotation_axis);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->arm_side =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->arm_side);
      offset += this->direction.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_thre;
      u_thre.base = 0;
      u_thre.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_thre.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_thre.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_thre.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->thre = u_thre.real;
      offset += sizeof(this->thre);
      union {
        float real;
        uint32_t base;
      } u_max_dist;
      u_max_dist.base = 0;
      u_max_dist.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_dist.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_dist.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_dist.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_dist = u_max_dist.real;
      offset += sizeof(this->max_dist);
      union {
        float real;
        uint32_t base;
      } u_dist_step;
      u_dist_step.base = 0;
      u_dist_step.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dist_step.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dist_step.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dist_step.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dist_step = u_dist_step.real;
      offset += sizeof(this->dist_step);
      union {
        float real;
        uint32_t base;
      } u_time_step;
      u_time_step.base = 0;
      u_time_step.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_step.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_step.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_step.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time_step = u_time_step.real;
      offset += sizeof(this->time_step);
      union {
        bool real;
        uint8_t base;
      } u_rotation_axis;
      u_rotation_axis.base = 0;
      u_rotation_axis.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rotation_axis = u_rotation_axis.real;
      offset += sizeof(this->rotation_axis);
     return offset;
    }

    const char * getType(){ return REACHUNTILTOUCHCOMMAND; };
    const char * getMD5(){ return "571f06eb2d695d11a24af02f90a01d1b"; };

  };

  class ReachUntilTouchCommandResponse : public ros::Msg
  {
    public:

    ReachUntilTouchCommandResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return REACHUNTILTOUCHCOMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ReachUntilTouchCommand {
    public:
    typedef ReachUntilTouchCommandRequest Request;
    typedef ReachUntilTouchCommandResponse Response;
  };

}
#endif
