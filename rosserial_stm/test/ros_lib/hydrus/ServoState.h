#ifndef _ROS_hydrus_ServoState_h
#define _ROS_hydrus_ServoState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus
{

  class ServoState : public ros::Msg
  {
    public:
      uint8_t index;
      uint16_t angle;
      uint8_t temp;
      int16_t load;
      uint8_t error;

    ServoState():
      index(0),
      angle(0),
      temp(0),
      load(0),
      error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index);
      *(outbuffer + offset + 0) = (this->angle >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angle >> (8 * 1)) & 0xFF;
      offset += sizeof(this->angle);
      *(outbuffer + offset + 0) = (this->temp >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temp);
      union {
        int16_t real;
        uint16_t base;
      } u_load;
      u_load.real = this->load;
      *(outbuffer + offset + 0) = (u_load.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_load.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->load);
      *(outbuffer + offset + 0) = (this->error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->index);
      this->angle =  ((uint16_t) (*(inbuffer + offset)));
      this->angle |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->angle);
      this->temp =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->temp);
      union {
        int16_t real;
        uint16_t base;
      } u_load;
      u_load.base = 0;
      u_load.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_load.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->load = u_load.real;
      offset += sizeof(this->load);
      this->error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error);
     return offset;
    }

    const char * getType(){ return "hydrus/ServoState"; };
    const char * getMD5(){ return "be7ff99a68441fad6fcb1762168ca85d"; };

  };

}
#endif