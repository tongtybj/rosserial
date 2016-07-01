#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_DetectorTotalWrench_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_DetectorTotalWrench_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ImpedanceControllerService_DetectorTotalWrench : public ros::Msg
  {
    public:
      enum { TOTAL_FORCE = 0 };
      enum { TOTAL_MOMENT = 1 };

    OpenHRP_ImpedanceControllerService_DetectorTotalWrench()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_DetectorTotalWrench"; };
    const char * getMD5(){ return "00df7a71edfc06e6a4fb9a90c75fbe13"; };

  };

}
#endif