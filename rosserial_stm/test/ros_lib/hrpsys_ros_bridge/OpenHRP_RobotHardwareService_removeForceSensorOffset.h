#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_removeForceSensorOffset_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_removeForceSensorOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_REMOVEFORCESENSOROFFSET[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_removeForceSensorOffset";

  class OpenHRP_RobotHardwareService_removeForceSensorOffsetRequest : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_removeForceSensorOffsetRequest()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_REMOVEFORCESENSOROFFSET; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_removeForceSensorOffsetResponse : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_removeForceSensorOffsetResponse()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_REMOVEFORCESENSOROFFSET; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_removeForceSensorOffset {
    public:
    typedef OpenHRP_RobotHardwareService_removeForceSensorOffsetRequest Request;
    typedef OpenHRP_RobotHardwareService_removeForceSensorOffsetResponse Response;
  };

}
#endif
