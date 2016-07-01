#ifndef _ROS_SERVICE_OpenHRP_StabilizerService_startStabilizer_h
#define _ROS_SERVICE_OpenHRP_StabilizerService_startStabilizer_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_STABILIZERSERVICE_STARTSTABILIZER[] = "hrpsys_ros_bridge/OpenHRP_StabilizerService_startStabilizer";

  class OpenHRP_StabilizerService_startStabilizerRequest : public ros::Msg
  {
    public:

    OpenHRP_StabilizerService_startStabilizerRequest()
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

    const char * getType(){ return OPENHRP_STABILIZERSERVICE_STARTSTABILIZER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StabilizerService_startStabilizerResponse : public ros::Msg
  {
    public:

    OpenHRP_StabilizerService_startStabilizerResponse()
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

    const char * getType(){ return OPENHRP_STABILIZERSERVICE_STARTSTABILIZER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StabilizerService_startStabilizer {
    public:
    typedef OpenHRP_StabilizerService_startStabilizerRequest Request;
    typedef OpenHRP_StabilizerService_startStabilizerResponse Response;
  };

}
#endif
