#ifndef _ROS_hydrus_transform_control_ServoControl_h
#define _ROS_hydrus_transform_control_ServoControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus_transform_control
{

  class ServoControl : public ros::Msg
  {
    public:
      uint16_t angle[6];

    ServoControl():
      angle()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 6; i++){
      *(outbuffer + offset + 0) = (this->angle[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angle[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->angle[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 6; i++){
      this->angle[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->angle[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->angle[i]);
      }
     return offset;
    }

    const char * getType(){ return "hydrus_transform_control/ServoControl"; };
    const char * getMD5(){ return "dc2b87ede9e06ac742cdfeb6126bda88"; };

  };

}
#endif