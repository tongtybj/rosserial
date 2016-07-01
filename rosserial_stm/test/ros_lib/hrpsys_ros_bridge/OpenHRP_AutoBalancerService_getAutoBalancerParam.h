#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_getAutoBalancerParam_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_getAutoBalancerParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_AutoBalancerParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GETAUTOBALANCERPARAM[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_getAutoBalancerParam";

  class OpenHRP_AutoBalancerService_getAutoBalancerParamRequest : public ros::Msg
  {
    public:

    OpenHRP_AutoBalancerService_getAutoBalancerParamRequest()
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETAUTOBALANCERPARAM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_AutoBalancerService_getAutoBalancerParamResponse : public ros::Msg
  {
    public:
      bool operation_return;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_AutoBalancerParam i_param;

    OpenHRP_AutoBalancerService_getAutoBalancerParamResponse():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETAUTOBALANCERPARAM; };
    const char * getMD5(){ return "d803f6888e8496070e0cec0b958beb65"; };

  };

  class OpenHRP_AutoBalancerService_getAutoBalancerParam {
    public:
    typedef OpenHRP_AutoBalancerService_getAutoBalancerParamRequest Request;
    typedef OpenHRP_AutoBalancerService_getAutoBalancerParamResponse Response;
  };

}
#endif
