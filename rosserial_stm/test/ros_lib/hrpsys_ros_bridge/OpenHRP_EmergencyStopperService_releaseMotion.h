#ifndef _ROS_SERVICE_OpenHRP_EmergencyStopperService_releaseMotion_h
#define _ROS_SERVICE_OpenHRP_EmergencyStopperService_releaseMotion_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_EMERGENCYSTOPPERSERVICE_RELEASEMOTION[] = "hrpsys_ros_bridge/OpenHRP_EmergencyStopperService_releaseMotion";

  class OpenHRP_EmergencyStopperService_releaseMotionRequest : public ros::Msg
  {
    public:

    OpenHRP_EmergencyStopperService_releaseMotionRequest()
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

    const char * getType(){ return OPENHRP_EMERGENCYSTOPPERSERVICE_RELEASEMOTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_EmergencyStopperService_releaseMotionResponse : public ros::Msg
  {
    public:

    OpenHRP_EmergencyStopperService_releaseMotionResponse()
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

    const char * getType(){ return OPENHRP_EMERGENCYSTOPPERSERVICE_RELEASEMOTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_EmergencyStopperService_releaseMotion {
    public:
    typedef OpenHRP_EmergencyStopperService_releaseMotionRequest Request;
    typedef OpenHRP_EmergencyStopperService_releaseMotionResponse Response;
  };

}
#endif
