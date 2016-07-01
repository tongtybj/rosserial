#ifndef _ROS_drc_task_common_Int8Float64_h
#define _ROS_drc_task_common_Int8Float64_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_task_common
{

  class Int8Float64 : public ros::Msg
  {
    public:
      int8_t index;
      double data;

    Int8Float64():
      index(0),
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index);
      union {
        double real;
        uint64_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_data.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_data.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_data.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_data.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->index = u_index.real;
      offset += sizeof(this->index);
      union {
        double real;
        uint64_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "drc_task_common/Int8Float64"; };
    const char * getMD5(){ return "25622f0482051b34e5de63403ff3ea50"; };

  };

}
#endif