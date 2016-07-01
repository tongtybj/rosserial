#ifndef _ROS_SERVICE_OpenHRP_EmergencyStopperService_stopMotion_h
#define _ROS_SERVICE_OpenHRP_EmergencyStopperService_stopMotion_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_EMERGENCYSTOPPERSERVICE_STOPMOTION[] = "hrpsys_ros_bridge/OpenHRP_EmergencyStopperService_stopMotion";

  class OpenHRP_EmergencyStopperService_stopMotionRequest : public ros::Msg
  {
    public:

    OpenHRP_EmergencyStopperService_stopMotionRequest()
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

    const char * getType(){ return OPENHRP_EMERGENCYSTOPPERSERVICE_STOPMOTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_EmergencyStopperService_stopMotionResponse : public ros::Msg
  {
    public:

    OpenHRP_EmergencyStopperService_stopMotionResponse()
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

    const char * getType(){ return OPENHRP_EMERGENCYSTOPPERSERVICE_STOPMOTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_EmergencyStopperService_stopMotion {
    public:
    typedef OpenHRP_EmergencyStopperService_stopMotionRequest Request;
    typedef OpenHRP_EmergencyStopperService_stopMotionResponse Response;
  };

}
#endif
