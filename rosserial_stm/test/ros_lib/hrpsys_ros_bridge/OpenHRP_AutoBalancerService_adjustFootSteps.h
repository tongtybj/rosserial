#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_adjustFootSteps_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_adjustFootSteps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_ADJUSTFOOTSTEPS[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_adjustFootSteps";

  class OpenHRP_AutoBalancerService_adjustFootStepsRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep rfootstep;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep lfootstep;

    OpenHRP_AutoBalancerService_adjustFootStepsRequest():
      rfootstep(),
      lfootstep()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->rfootstep.serialize(outbuffer + offset);
      offset += this->lfootstep.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->rfootstep.deserialize(inbuffer + offset);
      offset += this->lfootstep.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_ADJUSTFOOTSTEPS; };
    const char * getMD5(){ return "c111057b099edd71e194aace8fd84daa"; };

  };

  class OpenHRP_AutoBalancerService_adjustFootStepsResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_AutoBalancerService_adjustFootStepsResponse():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_ADJUSTFOOTSTEPS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_adjustFootSteps {
    public:
    typedef OpenHRP_AutoBalancerService_adjustFootStepsRequest Request;
    typedef OpenHRP_AutoBalancerService_adjustFootStepsResponse Response;
  };

}
#endif
