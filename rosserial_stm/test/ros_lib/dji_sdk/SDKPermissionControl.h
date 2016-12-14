#ifndef _ROS_SERVICE_SDKPermissionControl_h
#define _ROS_SERVICE_SDKPermissionControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char SDKPERMISSIONCONTROL[] = "dji_sdk/SDKPermissionControl";

  class SDKPermissionControlRequest : public ros::Msg
  {
    public:
      uint8_t control_enable;

    SDKPermissionControlRequest():
      control_enable(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->control_enable >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_enable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->control_enable =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_enable);
     return offset;
    }

    const char * getType(){ return SDKPERMISSIONCONTROL; };
    const char * getMD5(){ return "d62981e022c80f2b67e97d9e17fffd9a"; };

  };

  class SDKPermissionControlResponse : public ros::Msg
  {
    public:
      bool result;

    SDKPermissionControlResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return SDKPERMISSIONCONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SDKPermissionControl {
    public:
    typedef SDKPermissionControlRequest Request;
    typedef SDKPermissionControlResponse Response;
  };

}
#endif
