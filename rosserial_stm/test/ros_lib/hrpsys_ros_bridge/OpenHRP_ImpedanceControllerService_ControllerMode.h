#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_ControllerMode_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_ControllerMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ImpedanceControllerService_ControllerMode : public ros::Msg
  {
    public:
      enum { MODE_IDLE = 0 };
      enum { MODE_IMP = 1 };

    OpenHRP_ImpedanceControllerService_ControllerMode()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_ControllerMode"; };
    const char * getMD5(){ return "f82ea630afd133fa8e65c80708052551"; };

  };

}
#endif