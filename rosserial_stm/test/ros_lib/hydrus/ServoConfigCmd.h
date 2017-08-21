#ifndef _ROS_hydrus_ServoConfigCmd_h
#define _ROS_hydrus_ServoConfigCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus
{

  class ServoConfigCmd : public ros::Msg
  {
    public:
      uint8_t command;
      uint8_t servo_index;
      int32_t data;

    ServoConfigCmd():
      command(0),
      servo_index(0),
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      *(outbuffer + offset + 0) = (this->servo_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->servo_index);
      union {
        int32_t real;
        uint32_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      this->servo_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->servo_index);
      union {
        int32_t real;
        uint32_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->data = u_data.real;
      offset += sizeof(this->data);
     return offset;
    }

    const char * getType(){ return "hydrus/ServoConfigCmd"; };
    const char * getMD5(){ return "3bfa4ac647a9e3545b003b56ead67a39"; };

  };

}
#endif