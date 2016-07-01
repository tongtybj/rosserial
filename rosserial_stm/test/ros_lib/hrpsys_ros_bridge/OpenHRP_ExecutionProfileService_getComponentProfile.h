#ifndef _ROS_SERVICE_OpenHRP_ExecutionProfileService_getComponentProfile_h
#define _ROS_SERVICE_OpenHRP_ExecutionProfileService_getComponentProfile_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_ComponentProfile.h"
#include "hrpsys_ros_bridge/RTC_LightweightRTObject.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_EXECUTIONPROFILESERVICE_GETCOMPONENTPROFILE[] = "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_getComponentProfile";

  class OpenHRP_ExecutionProfileService_getComponentProfileRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::RTC_LightweightRTObject obj;

    OpenHRP_ExecutionProfileService_getComponentProfileRequest():
      obj()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->obj.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->obj.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_EXECUTIONPROFILESERVICE_GETCOMPONENTPROFILE; };
    const char * getMD5(){ return "07cea1f055c3bf0af852092409ccaccf"; };

  };

  class OpenHRP_ExecutionProfileService_getComponentProfileResponse : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile operation_return;

    OpenHRP_ExecutionProfileService_getComponentProfileResponse():
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

    const char * getType(){ return OPENHRP_EXECUTIONPROFILESERVICE_GETCOMPONENTPROFILE; };
    const char * getMD5(){ return "d9ae1b1c1f6b91aab001e05ad7b9179e"; };

  };

  class OpenHRP_ExecutionProfileService_getComponentProfile {
    public:
    typedef OpenHRP_ExecutionProfileService_getComponentProfileRequest Request;
    typedef OpenHRP_ExecutionProfileService_getComponentProfileResponse Response;
  };

}
#endif
