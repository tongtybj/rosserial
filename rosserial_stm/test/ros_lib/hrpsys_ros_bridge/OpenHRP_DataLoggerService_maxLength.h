#ifndef _ROS_SERVICE_OpenHRP_DataLoggerService_maxLength_h
#define _ROS_SERVICE_OpenHRP_DataLoggerService_maxLength_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_DATALOGGERSERVICE_MAXLENGTH[] = "hrpsys_ros_bridge/OpenHRP_DataLoggerService_maxLength";

  class OpenHRP_DataLoggerService_maxLengthRequest : public ros::Msg
  {
    public:
      uint32_t len;

    OpenHRP_DataLoggerService_maxLengthRequest():
      len(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->len >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->len >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->len >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->len >> (8 * 3)) & 0xFF;
      offset += sizeof(this->len);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->len =  ((uint32_t) (*(inbuffer + offset)));
      this->len |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->len |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->len |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->len);
     return offset;
    }

    const char * getType(){ return OPENHRP_DATALOGGERSERVICE_MAXLENGTH; };
    const char * getMD5(){ return "063309fa8bfb14a7ffd445203b5e32f2"; };

  };

  class OpenHRP_DataLoggerService_maxLengthResponse : public ros::Msg
  {
    public:

    OpenHRP_DataLoggerService_maxLengthResponse()
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

    const char * getType(){ return OPENHRP_DATALOGGERSERVICE_MAXLENGTH; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_DataLoggerService_maxLength {
    public:
    typedef OpenHRP_DataLoggerService_maxLengthRequest Request;
    typedef OpenHRP_DataLoggerService_maxLengthResponse Response;
  };

}
#endif
