#ifndef _ROS_SERVICE_OpenHRP_EmergencyStopperService_getEmergencyStopperParam_h
#define _ROS_SERVICE_OpenHRP_EmergencyStopperService_getEmergencyStopperParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_EmergencyStopperService_EmergencyStopperParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_EMERGENCYSTOPPERSERVICE_GETEMERGENCYSTOPPERPARAM[] = "hrpsys_ros_bridge/OpenHRP_EmergencyStopperService_getEmergencyStopperParam";

  class OpenHRP_EmergencyStopperService_getEmergencyStopperParamRequest : public ros::Msg
  {
    public:

    OpenHRP_EmergencyStopperService_getEmergencyStopperParamRequest()
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

    const char * getType(){ return OPENHRP_EMERGENCYSTOPPERSERVICE_GETEMERGENCYSTOPPERPARAM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_EmergencyStopperService_getEmergencyStopperParamResponse : public ros::Msg
  {
    public:
      bool operation_return;
      hrpsys_ros_bridge::OpenHRP_EmergencyStopperService_EmergencyStopperParam i_param;

    OpenHRP_EmergencyStopperService_getEmergencyStopperParamResponse():
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

    const char * getType(){ return OPENHRP_EMERGENCYSTOPPERSERVICE_GETEMERGENCYSTOPPERPARAM; };
    const char * getMD5(){ return "3abbde98c26f34c678a37396aa1892f3"; };

  };

  class OpenHRP_EmergencyStopperService_getEmergencyStopperParam {
    public:
    typedef OpenHRP_EmergencyStopperService_getEmergencyStopperParamRequest Request;
    typedef OpenHRP_EmergencyStopperService_getEmergencyStopperParamResponse Response;
  };

}
#endif
