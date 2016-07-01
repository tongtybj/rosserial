#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_waitFootSteps_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_waitFootSteps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_WAITFOOTSTEPS[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_waitFootSteps";

  class OpenHRP_AutoBalancerService_waitFootStepsRequest : public ros::Msg
  {
    public:

    OpenHRP_AutoBalancerService_waitFootStepsRequest()
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_WAITFOOTSTEPS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_AutoBalancerService_waitFootStepsResponse : public ros::Msg
  {
    public:

    OpenHRP_AutoBalancerService_waitFootStepsResponse()
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_WAITFOOTSTEPS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_AutoBalancerService_waitFootSteps {
    public:
    typedef OpenHRP_AutoBalancerService_waitFootStepsRequest Request;
    typedef OpenHRP_AutoBalancerService_waitFootStepsResponse Response;
  };

}
#endif
