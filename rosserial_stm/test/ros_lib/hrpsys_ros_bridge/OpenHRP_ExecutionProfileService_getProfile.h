#ifndef _ROS_SERVICE_OpenHRP_ExecutionProfileService_getProfile_h
#define _ROS_SERVICE_OpenHRP_ExecutionProfileService_getProfile_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_Profile.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_EXECUTIONPROFILESERVICE_GETPROFILE[] = "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_getProfile";

  class OpenHRP_ExecutionProfileService_getProfileRequest : public ros::Msg
  {
    public:

    OpenHRP_ExecutionProfileService_getProfileRequest()
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

    const char * getType(){ return OPENHRP_EXECUTIONPROFILESERVICE_GETPROFILE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ExecutionProfileService_getProfileResponse : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_Profile operation_return;

    OpenHRP_ExecutionProfileService_getProfileResponse():
      operation_return()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->operation_return.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->operation_return.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_EXECUTIONPROFILESERVICE_GETPROFILE; };
    const char * getMD5(){ return "049f21f14a7401a18923d1eeb49db968"; };

  };

  class OpenHRP_ExecutionProfileService_getProfile {
    public:
    typedef OpenHRP_ExecutionProfileService_getProfileRequest Request;
    typedef OpenHRP_ExecutionProfileService_getProfileResponse Response;
  };

}
#endif
