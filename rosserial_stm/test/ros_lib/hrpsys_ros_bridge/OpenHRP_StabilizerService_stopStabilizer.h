#ifndef _ROS_SERVICE_OpenHRP_StabilizerService_stopStabilizer_h
#define _ROS_SERVICE_OpenHRP_StabilizerService_stopStabilizer_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_STABILIZERSERVICE_STOPSTABILIZER[] = "hrpsys_ros_bridge/OpenHRP_StabilizerService_stopStabilizer";

  class OpenHRP_StabilizerService_stopStabilizerRequest : public ros::Msg
  {
    public:

    OpenHRP_StabilizerService_stopStabilizerRequest()
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

    const char * getType(){ return OPENHRP_STABILIZERSERVICE_STOPSTABILIZER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StabilizerService_stopStabilizerResponse : public ros::Msg
  {
    public:

    OpenHRP_StabilizerService_stopStabilizerResponse()
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

    const char * getType(){ return OPENHRP_STABILIZERSERVICE_STOPSTABILIZER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StabilizerService_stopStabilizer {
    public:
    typedef OpenHRP_StabilizerService_stopStabilizerRequest Request;
    typedef OpenHRP_StabilizerService_stopStabilizerResponse Response;
  };

}
#endif
