#ifndef _ROS_SERVICE_RvizMenuSelect_h
#define _ROS_SERVICE_RvizMenuSelect_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_task_common
{

static const char RVIZMENUSELECT[] = "drc_task_common/RvizMenuSelect";

  class RvizMenuSelectRequest : public ros::Msg
  {
    public:
      float variable;

    RvizMenuSelectRequest():
      variable(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_variable;
      u_variable.real = this->variable;
      *(outbuffer + offset + 0) = (u_variable.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variable.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variable.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variable.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_variable;
      u_variable.base = 0;
      u_variable.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variable.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variable.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variable.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->variable = u_variable.real;
      offset += sizeof(this->variable);
     return offset;
    }

    const char * getType(){ return RVIZMENUSELECT; };
    const char * getMD5(){ return "b231b1bd5d778ac856cf8c80a29de6de"; };

  };

  class RvizMenuSelectResponse : public ros::Msg
  {
    public:

    RvizMenuSelectResponse()
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

    const char * getType(){ return RVIZMENUSELECT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class RvizMenuSelect {
    public:
    typedef RvizMenuSelectRequest Request;
    typedef RvizMenuSelectResponse Response;
  };

}
#endif
