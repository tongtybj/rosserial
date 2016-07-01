#ifndef _ROS_SERVICE_OpenHRP_ExecutionProfileService_resetProfile_h
#define _ROS_SERVICE_OpenHRP_ExecutionProfileService_resetProfile_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_EXECUTIONPROFILESERVICE_RESETPROFILE[] = "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_resetProfile";

  class OpenHRP_ExecutionProfileService_resetProfileRequest : public ros::Msg
  {
    public:

    OpenHRP_ExecutionProfileService_resetProfileRequest()
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

    const char * getType(){ return OPENHRP_EXECUTIONPROFILESERVICE_RESETPROFILE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ExecutionProfileService_resetProfileResponse : public ros::Msg
  {
    public:

    OpenHRP_ExecutionProfileService_resetProfileResponse()
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

    const char * getType(){ return OPENHRP_EXECUTIONPROFILESERVICE_RESETPROFILE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ExecutionProfileService_resetProfile {
    public:
    typedef OpenHRP_ExecutionProfileService_resetProfileRequest Request;
    typedef OpenHRP_ExecutionProfileService_resetProfileResponse Response;
  };

}
#endif
