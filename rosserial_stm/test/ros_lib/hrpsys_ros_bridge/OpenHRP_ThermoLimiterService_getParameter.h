#ifndef _ROS_SERVICE_OpenHRP_ThermoLimiterService_getParameter_h
#define _ROS_SERVICE_OpenHRP_ThermoLimiterService_getParameter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ThermoLimiterService_tlParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_THERMOLIMITERSERVICE_GETPARAMETER[] = "hrpsys_ros_bridge/OpenHRP_ThermoLimiterService_getParameter";

  class OpenHRP_ThermoLimiterService_getParameterRequest : public ros::Msg
  {
    public:

    OpenHRP_ThermoLimiterService_getParameterRequest()
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

    const char * getType(){ return OPENHRP_THERMOLIMITERSERVICE_GETPARAMETER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ThermoLimiterService_getParameterResponse : public ros::Msg
  {
    public:
      bool operation_return;
      hrpsys_ros_bridge::OpenHRP_ThermoLimiterService_tlParam i_param;

    OpenHRP_ThermoLimiterService_getParameterResponse():
      operation_return(0),
      i_param()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      offset += this->i_param.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_THERMOLIMITERSERVICE_GETPARAMETER; };
    const char * getMD5(){ return "88b23adb1cc98d44542da7ca74135c3d"; };

  };

  class OpenHRP_ThermoLimiterService_getParameter {
    public:
    typedef OpenHRP_ThermoLimiterService_getParameterRequest Request;
    typedef OpenHRP_ThermoLimiterService_getParameterResponse Response;
  };

}
#endif
