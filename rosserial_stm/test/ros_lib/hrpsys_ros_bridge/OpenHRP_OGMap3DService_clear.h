#ifndef _ROS_SERVICE_OpenHRP_OGMap3DService_clear_h
#define _ROS_SERVICE_OpenHRP_OGMap3DService_clear_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_OGMAP3DSERVICE_CLEAR[] = "hrpsys_ros_bridge/OpenHRP_OGMap3DService_clear";

  class OpenHRP_OGMap3DService_clearRequest : public ros::Msg
  {
    public:

    OpenHRP_OGMap3DService_clearRequest()
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

    const char * getType(){ return OPENHRP_OGMAP3DSERVICE_CLEAR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_OGMap3DService_clearResponse : public ros::Msg
  {
    public:

    OpenHRP_OGMap3DService_clearResponse()
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

    const char * getType(){ return OPENHRP_OGMAP3DSERVICE_CLEAR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_OGMap3DService_clear {
    public:
    typedef OpenHRP_OGMap3DService_clearRequest Request;
    typedef OpenHRP_OGMap3DService_clearResponse Response;
  };

}
#endif
