#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_FootstepParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_FootstepParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_FootstepParam : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep support_leg_coords;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep swing_leg_coords;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep swing_leg_src_coords;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep swing_leg_dst_coords;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep dst_foot_midcoords;
      int64_t support_leg;
      int64_t support_leg_with_both;

    OpenHRP_AutoBalancerService_FootstepParam():
      support_leg_coords(),
      swing_leg_coords(),
      swing_leg_src_coords(),
      swing_leg_dst_coords(),
      dst_foot_midcoords(),
      support_leg(0),
      support_leg_with_both(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->support_leg_coords.serialize(outbuffer + offset);
      offset += this->swing_leg_coords.serialize(outbuffer + offset);
      offset += this->swing_leg_src_coords.serialize(outbuffer + offset);
      offset += this->swing_leg_dst_coords.serialize(outbuffer + offset);
      offset += this->dst_foot_midcoords.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_support_leg;
      u_support_leg.real = this->support_leg;
      *(outbuffer + offset + 0) = (u_support_leg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_support_leg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_support_leg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_support_leg.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_support_leg.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_support_leg.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_support_leg.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_support_leg.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->support_leg);
      union {
        int64_t real;
        uint64_t base;
      } u_support_leg_with_both;
      u_support_leg_with_both.real = this->support_leg_with_both;
      *(outbuffer + offset + 0) = (u_support_leg_with_both.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_support_leg_with_both.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_support_leg_with_both.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_support_leg_with_both.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_support_leg_with_both.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_support_leg_with_both.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_support_leg_with_both.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_support_leg_with_both.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->support_leg_with_both);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->support_leg_coords.deserialize(inbuffer + offset);
      offset += this->swing_leg_coords.deserialize(inbuffer + offset);
      offset += this->swing_leg_src_coords.deserialize(inbuffer + offset);
      offset += this->swing_leg_dst_coords.deserialize(inbuffer + offset);
      offset += this->dst_foot_midcoords.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_support_leg;
      u_support_leg.base = 0;
      u_support_leg.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_support_leg.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_support_leg.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_support_leg.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_support_leg.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_support_leg.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_support_leg.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_support_leg.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->support_leg = u_support_leg.real;
      offset += sizeof(this->support_leg);
      union {
        int64_t real;
        uint64_t base;
      } u_support_leg_with_both;
      u_support_leg_with_both.base = 0;
      u_support_leg_with_both.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_support_leg_with_both.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_support_leg_with_both.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_support_leg_with_both.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_support_leg_with_both.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_support_leg_with_both.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_support_leg_with_both.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_support_leg_with_both.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->support_leg_with_both = u_support_leg_with_both.real;
      offset += sizeof(this->support_leg_with_both);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_FootstepParam"; };
    const char * getMD5(){ return "de665d6ef69950bb22fe43de9f539305"; };

  };

}
#endif