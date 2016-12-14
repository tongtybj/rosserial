#ifndef _ROS_SERVICE_VirtualRCEnableControl_h
#define _ROS_SERVICE_VirtualRCEnableControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char VIRTUALRCENABLECONTROL[] = "dji_sdk/VirtualRCEnableControl";

  class VirtualRCEnableControlRequest : public ros::Msg
  {
    public:
      uint8_t enable;
      uint8_t if_back_to_real;

    VirtualRCEnableControlRequest():
      enable(0),
      if_back_to_real(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->enable >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable);
      *(outbuffer + offset + 0) = (this->if_back_to_real >> (8 * 0)) & 0xFF;
      offset += sizeof(this->if_back_to_real);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->enable =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->enable);
      this->if_back_to_real =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->if_back_to_real);
     return offset;
    }

    const char * getType(){ return VIRTUALRCENABLECONTROL; };
    const char * getMD5(){ return "4ed79d2efd2ce23c729bcf82c65bbf2e"; };

  };

  class VirtualRCEnableControlResponse : public ros::Msg
  {
    public:
      bool result;

    VirtualRCEnableControlResponse():
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

    const char * getType(){ return VIRTUALRCENABLECONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class VirtualRCEnableControl {
    public:
    typedef VirtualRCEnableControlRequest Request;
    typedef VirtualRCEnableControlResponse Response;
  };

}
#endif
