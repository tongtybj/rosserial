#ifndef _ROS_SERVICE_OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetection_h
#define _ROS_SERVICE_OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_IMPEDANCECONTROLLERSERVICE_CHECKOBJECTTURNAROUNDDETECTION[] = "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetection";

  class OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetectionRequest : public ros::Msg
  {
    public:

    OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetectionRequest()
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

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_CHECKOBJECTTURNAROUNDDETECTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetectionResponse : public ros::Msg
  {
    public:
      int64_t operation_return;

    OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetectionResponse():
      operation_return(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_operation_return.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_operation_return.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_operation_return.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_operation_return.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_operation_return.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_operation_return.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_operation_return.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_CHECKOBJECTTURNAROUNDDETECTION; };
    const char * getMD5(){ return "82ded91c1a3e10db0e5768f3931d83ed"; };

  };

  class OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetection {
    public:
    typedef OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetectionRequest Request;
    typedef OpenHRP_ImpedanceControllerService_checkObjectTurnaroundDetectionResponse Response;
  };

}
#endif
