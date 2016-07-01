#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_DetectorMode_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_DetectorMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ImpedanceControllerService_DetectorMode : public ros::Msg
  {
    public:
      enum { MODE_DETECTOR_IDLE = 0 };
      enum { MODE_STARTED = 1 };
      enum { MODE_DETECTED = 2 };
      enum { MODE_MAX_TIME = 3 };

    OpenHRP_ImpedanceControllerService_DetectorMode()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_DetectorMode"; };
    const char * getMD5(){ return "dc29fa6d96a23a2fd78531b16c5d41bd"; };

  };

}
#endif