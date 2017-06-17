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
      uint8_t angles_length;
      uint16_t st_angles;
      uint16_t * angles;

    ServoControl():
      angles_length(0), angles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = angles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < angles_length; i++){
      *(outbuffer + offset + 0) = (this->angles[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angles[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->angles[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t angles_lengthT = *(inbuffer + offset++);
      if(angles_lengthT > angles_length)
        this->angles = (uint16_t*)realloc(this->angles, angles_lengthT * sizeof(uint16_t));
      offset += 3;
      angles_length = angles_lengthT;
      for( uint8_t i = 0; i < angles_length; i++){
      this->st_angles =  ((uint16_t) (*(inbuffer + offset)));
      this->st_angles |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_angles);
        memcpy( &(this->angles[i]), &(this->st_angles), sizeof(uint16_t));
      }
     return offset;
    }

    const char * getType(){ return "hydrus_transform_control/ServoControl"; };
    const char * getMD5(){ return "95544a90697a1b7211173559621536dd"; };

  };

}
#endif