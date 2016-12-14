#ifndef _ROS_SERVICE_BoolFlag_h
#define _ROS_SERVICE_BoolFlag_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_msgs
{

static const char BOOLFLAG[] = "aerial_robot_msgs/BoolFlag";

  class BoolFlagRequest : public ros::Msg
  {
    public:
      bool flag;

    BoolFlagRequest():
      flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_flag;
      u_flag.real = this->flag;
      *(outbuffer + offset + 0) = (u_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_flag;
      u_flag.base = 0;
      u_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->flag = u_flag.real;
      offset += sizeof(this->flag);
     return offset;
    }

    const char * getType(){ return BOOLFLAG; };
    const char * getMD5(){ return "24842bc754e0f5cc982338eca1269251"; };

  };

  class BoolFlagResponse : public ros::Msg
  {
    public:

    BoolFlagResponse()
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

    const char * getType(){ return BOOLFLAG; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class BoolFlag {
    public:
    typedef BoolFlagRequest Request;
    typedef BoolFlagResponse Response;
  };

}
#endif
