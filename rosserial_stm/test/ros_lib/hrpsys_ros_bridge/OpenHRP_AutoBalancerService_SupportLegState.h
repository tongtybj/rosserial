#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_SupportLegState_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_SupportLegState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_SupportLegState : public ros::Msg
  {
    public:
      enum { RLEG = 0 };
      enum { LLEG = 1 };
      enum { BOTH = 2 };

    OpenHRP_AutoBalancerService_SupportLegState()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_SupportLegState"; };
    const char * getMD5(){ return "e9dfb4200f2be09aee126a0f7c5a6308"; };

  };

}
#endif