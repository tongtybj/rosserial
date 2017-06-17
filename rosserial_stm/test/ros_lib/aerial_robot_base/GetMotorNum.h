#ifndef _ROS_SERVICE_GetMotorNum_h
#define _ROS_SERVICE_GetMotorNum_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_base
{

static const char GETMOTORNUM[] = "aerial_robot_base/GetMotorNum";

  class GetMotorNumRequest : public ros::Msg
  {
    public:

    GetMotorNumRequest()
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

    const char * getType(){ return GETMOTORNUM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetMotorNumResponse : public ros::Msg
  {
    public:
      uint8_t number;

    GetMotorNumResponse():
      number(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->number >> (8 * 0)) & 0xFF;
      offset += sizeof(this->number);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->number =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->number);
     return offset;
    }

    const char * getType(){ return GETMOTORNUM; };
    const char * getMD5(){ return "29e94f7568510a2f9241abcc8f191b4f"; };

  };

  class GetMotorNum {
    public:
    typedef GetMotorNumRequest Request;
    typedef GetMotorNumResponse Response;
  };

}
#endif
