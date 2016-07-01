#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_ControllerMode_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_ControllerMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_ControllerMode : public ros::Msg
  {
    public:
      enum { MODE_IDLE = 0 };
      enum { MODE_ABC = 1 };
      enum { MODE_SYNC_TO_IDLE = 2 };
      enum { MODE_SYNC_TO_ABC = 3 };

    OpenHRP_AutoBalancerService_ControllerMode()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_ControllerMode"; };
    const char * getMD5(){ return "e623afd21baf5de167b120c90632660b"; };

  };

}
#endif