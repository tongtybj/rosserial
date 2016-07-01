#ifndef _ROS_SERVICE_OpenHRP_StateHolderService_goActual_h
#define _ROS_SERVICE_OpenHRP_StateHolderService_goActual_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_STATEHOLDERSERVICE_GOACTUAL[] = "hrpsys_ros_bridge/OpenHRP_StateHolderService_goActual";

  class OpenHRP_StateHolderService_goActualRequest : public ros::Msg
  {
    public:

    OpenHRP_StateHolderService_goActualRequest()
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

    const char * getType(){ return OPENHRP_STATEHOLDERSERVICE_GOACTUAL; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StateHolderService_goActualResponse : public ros::Msg
  {
    public:

    OpenHRP_StateHolderService_goActualResponse()
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

    const char * getType(){ return OPENHRP_STATEHOLDERSERVICE_GOACTUAL; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StateHolderService_goActual {
    public:
    typedef OpenHRP_StateHolderService_goActualRequest Request;
    typedef OpenHRP_StateHolderService_goActualResponse Response;
  };

}
#endif
