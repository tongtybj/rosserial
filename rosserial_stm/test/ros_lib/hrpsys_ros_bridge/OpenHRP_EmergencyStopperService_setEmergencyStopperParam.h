#ifndef _ROS_SERVICE_OpenHRP_EmergencyStopperService_setEmergencyStopperParam_h
#define _ROS_SERVICE_OpenHRP_EmergencyStopperService_setEmergencyStopperParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_EmergencyStopperService_EmergencyStopperParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_EMERGENCYSTOPPERSERVICE_SETEMERGENCYSTOPPERPARAM[] = "hrpsys_ros_bridge/OpenHRP_EmergencyStopperService_setEmergencyStopperParam";

  class OpenHRP_EmergencyStopperService_setEmergencyStopperParamRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_EmergencyStopperService_EmergencyStopperParam i_param;

    OpenHRP_EmergencyStopperService_setEmergencyStopperParamRequest():
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

    const char * getType(){ return OPENHRP_EMERGENCYSTOPPERSERVICE_SETEMERGENCYSTOPPERPARAM; };
    const char * getMD5(){ return "052a5fa1be6224de174fb8044af3a8eb"; };

  };

  class OpenHRP_EmergencyStopperService_setEmergencyStopperParamResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_EmergencyStopperService_setEmergencyStopperParamResponse():
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

    const char * getType(){ return OPENHRP_EMERGENCYSTOPPERSERVICE_SETEMERGENCYSTOPPERPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_EmergencyStopperService_setEmergencyStopperParam {
    public:
    typedef OpenHRP_EmergencyStopperService_setEmergencyStopperParamRequest Request;
    typedef OpenHRP_EmergencyStopperService_setEmergencyStopperParamResponse Response;
  };

}
#endif
