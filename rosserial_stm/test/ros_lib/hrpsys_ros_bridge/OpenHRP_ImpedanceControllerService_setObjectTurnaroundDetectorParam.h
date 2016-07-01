#ifndef _ROS_SERVICE_OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParam_h
#define _ROS_SERVICE_OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_objectTurnaroundDetectorParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_IMPEDANCECONTROLLERSERVICE_SETOBJECTTURNAROUNDDETECTORPARAM[] = "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParam";

  class OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParamRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_ImpedanceControllerService_objectTurnaroundDetectorParam i_param;

    OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParamRequest():
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

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_SETOBJECTTURNAROUNDDETECTORPARAM; };
    const char * getMD5(){ return "7e3b4e7cd5a290d03aa0f1fbb7a62da3"; };

  };

  class OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParamResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParamResponse():
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

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_SETOBJECTTURNAROUNDDETECTORPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParam {
    public:
    typedef OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParamRequest Request;
    typedef OpenHRP_ImpedanceControllerService_setObjectTurnaroundDetectorParamResponse Response;
  };

}
#endif
