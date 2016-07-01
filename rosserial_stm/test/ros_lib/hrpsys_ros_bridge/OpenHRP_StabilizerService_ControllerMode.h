#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_ControllerMode_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_ControllerMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_ControllerMode : public ros::Msg
  {
    public:
      enum { MODE_IDLE = 0 };
      enum { MODE_AIR = 1 };
      enum { MODE_ST = 2 };
      enum { MODE_SYNC_TO_IDLE = 3 };
      enum { MODE_SYNC_TO_AIR = 4 };

    OpenHRP_StabilizerService_ControllerMode()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_ControllerMode"; };
    const char * getMD5(){ return "7ae2dc5217a78ec643e03486132c0113"; };

  };

}
#endif