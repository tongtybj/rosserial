#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_setGaitGeneratorParam_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_setGaitGeneratorParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_GaitGeneratorParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_SETGAITGENERATORPARAM[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_setGaitGeneratorParam";

  class OpenHRP_AutoBalancerService_setGaitGeneratorParamRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_GaitGeneratorParam i_param;

    OpenHRP_AutoBalancerService_setGaitGeneratorParamRequest():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_SETGAITGENERATORPARAM; };
    const char * getMD5(){ return "dbc0354f7043927c66c0859bf934b704"; };

  };

  class OpenHRP_AutoBalancerService_setGaitGeneratorParamResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_AutoBalancerService_setGaitGeneratorParamResponse():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_SETGAITGENERATORPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_setGaitGeneratorParam {
    public:
    typedef OpenHRP_AutoBalancerService_setGaitGeneratorParamRequest Request;
    typedef OpenHRP_AutoBalancerService_setGaitGeneratorParamResponse Response;
  };

}
#endif
