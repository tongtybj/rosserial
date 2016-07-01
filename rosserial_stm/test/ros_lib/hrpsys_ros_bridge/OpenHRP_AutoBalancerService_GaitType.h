#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_GaitType_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_GaitType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_GaitType : public ros::Msg
  {
    public:
      enum { BIPED = 0 };
      enum { TROT = 1 };
      enum { PACE = 2 };
      enum { CRAWL = 3 };
      enum { GALLOP = 4 };

    OpenHRP_AutoBalancerService_GaitType()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_GaitType"; };
    const char * getMD5(){ return "48725e4c281d7e38ffa2b76e2a96bc2c"; };

  };

}
#endif