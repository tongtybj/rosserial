#ifndef _ROS_SERVICE_OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffset_h
#define _ROS_SERVICE_OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_VIRTUALFORCESENSORSERVICE_REMOVEVIRTUALFORCESENSOROFFSET[] = "hrpsys_ros_bridge/OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffset";

  class OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffsetRequest : public ros::Msg
  {
    public:
      const char* sensorName;

    OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffsetRequest():
      sensorName("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_sensorName = strlen(this->sensorName);
      memcpy(outbuffer + offset, &length_sensorName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->sensorName, length_sensorName);
      offset += length_sensorName;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_sensorName;
      memcpy(&length_sensorName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sensorName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sensorName-1]=0;
      this->sensorName = (char *)(inbuffer + offset-1);
      offset += length_sensorName;
     return offset;
    }

    const char * getType(){ return OPENHRP_VIRTUALFORCESENSORSERVICE_REMOVEVIRTUALFORCESENSOROFFSET; };
    const char * getMD5(){ return "a6af3a13aa2aee48c9c9f719b4e3274d"; };

  };

  class OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffsetResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffsetResponse():
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

    const char * getType(){ return OPENHRP_VIRTUALFORCESENSORSERVICE_REMOVEVIRTUALFORCESENSOROFFSET; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffset {
    public:
    typedef OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffsetRequest Request;
    typedef OpenHRP_VirtualForceSensorService_removeVirtualForceSensorOffsetResponse Response;
  };

}
#endif
