#ifndef _ROS_SERVICE_OpenHRP_DataLoggerService_save_h
#define _ROS_SERVICE_OpenHRP_DataLoggerService_save_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_DATALOGGERSERVICE_SAVE[] = "hrpsys_ros_bridge/OpenHRP_DataLoggerService_save";

  class OpenHRP_DataLoggerService_saveRequest : public ros::Msg
  {
    public:
      const char* basename;

    OpenHRP_DataLoggerService_saveRequest():
      basename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_basename = strlen(this->basename);
      memcpy(outbuffer + offset, &length_basename, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->basename, length_basename);
      offset += length_basename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_basename;
      memcpy(&length_basename, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_basename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_basename-1]=0;
      this->basename = (char *)(inbuffer + offset-1);
      offset += length_basename;
     return offset;
    }

    const char * getType(){ return OPENHRP_DATALOGGERSERVICE_SAVE; };
    const char * getMD5(){ return "40b073e0ee30f487726abfbc3c94fd42"; };

  };

  class OpenHRP_DataLoggerService_saveResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_DataLoggerService_saveResponse():
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

    const char * getType(){ return OPENHRP_DATALOGGERSERVICE_SAVE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_DataLoggerService_save {
    public:
    typedef OpenHRP_DataLoggerService_saveRequest Request;
    typedef OpenHRP_DataLoggerService_saveResponse Response;
  };

}
#endif
