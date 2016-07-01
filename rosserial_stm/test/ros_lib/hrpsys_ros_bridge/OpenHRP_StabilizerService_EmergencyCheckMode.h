#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_EmergencyCheckMode_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_EmergencyCheckMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_EmergencyCheckMode : public ros::Msg
  {
    public:
      enum { NO_CHECK = 0 };
      enum { COP = 1 };
      enum { CP = 2 };
      enum { TILT = 3 };

    OpenHRP_StabilizerService_EmergencyCheckMode()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_EmergencyCheckMode"; };
    const char * getMD5(){ return "f2a9fcd43d6779b4a1e0d9a9c9f496fb"; };

  };

}
#endif