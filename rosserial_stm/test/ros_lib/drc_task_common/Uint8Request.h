#ifndef _ROS_SERVICE_Uint8Request_h
#define _ROS_SERVICE_Uint8Request_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_task_common
{

static const char UINT8REQUEST[] = "drc_task_common/Uint8Request";

  class Uint8RequestRequest : public ros::Msg
  {
    public:
      uint8_t type;

    Uint8RequestRequest():
      type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
     return offset;
    }

    const char * getType(){ return UINT8REQUEST; };
    const char * getMD5(){ return "3958533281df6e9cc0a725a386f3b5df"; };

  };

  class Uint8RequestResponse : public ros::Msg
  {
    public:

    Uint8RequestResponse()
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

    const char * getType(){ return UINT8REQUEST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Uint8Request {
    public:
    typedef Uint8RequestRequest Request;
    typedef Uint8RequestResponse Response;
  };

}
#endif
