#ifndef _ROS_dji_sdk_PowerStatus_h
#define _ROS_dji_sdk_PowerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class PowerStatus : public ros::Msg
  {
    public:
      uint8_t percentage;

    PowerStatus():
      percentage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->percentage >> (8 * 0)) & 0xFF;
      offset += sizeof(this->percentage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->percentage =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->percentage);
     return offset;
    }

    const char * getType(){ return "dji_sdk/PowerStatus"; };
    const char * getMD5(){ return "0a5e877bf2d8a1641c4f5265662bc268"; };

  };

}
#endif