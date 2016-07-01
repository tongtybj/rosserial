#ifndef _ROS_SERVICE_OpenHRP_ThermoLimiterService_setParameter_h
#define _ROS_SERVICE_OpenHRP_ThermoLimiterService_setParameter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ThermoLimiterService_tlParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_THERMOLIMITERSERVICE_SETPARAMETER[] = "hrpsys_ros_bridge/OpenHRP_ThermoLimiterService_setParameter";

  class OpenHRP_ThermoLimiterService_setParameterRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_ThermoLimiterService_tlParam i_param;

    OpenHRP_ThermoLimiterService_setParameterRequest():
      i_param()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->i_param.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_THERMOLIMITERSERVICE_SETPARAMETER; };
    const char * getMD5(){ return "1510c439fd42aa5a21f60c6c170dcca4"; };

  };

  class OpenHRP_ThermoLimiterService_setParameterResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_ThermoLimiterService_setParameterResponse():
      operation_return(0)
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
     return offset;
    }

    const char * getType(){ return OPENHRP_THERMOLIMITERSERVICE_SETPARAMETER; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ThermoLimiterService_setParameter {
    public:
    typedef OpenHRP_ThermoLimiterService_setParameterRequest Request;
    typedef OpenHRP_ThermoLimiterService_setParameterResponse Response;
  };

}
#endif
