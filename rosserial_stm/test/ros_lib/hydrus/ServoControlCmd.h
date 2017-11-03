#ifndef _ROS_hydrus_ServoControlCmd_h
#define _ROS_hydrus_ServoControlCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus
{

  class ServoControlCmd : public ros::Msg
  {
    public:
      uint8_t index_length;
      uint8_t st_index;
      uint8_t * index;
      uint8_t angles_length;
      uint16_t st_angles;
      uint16_t * angles;

    ServoControlCmd():
      index_length(0), index(NULL),
      angles_length(0), angles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = index_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < index_length; i++){
      *(outbuffer + offset + 0) = (this->index[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index[i]);
      }
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
      uint8_t index_lengthT = *(inbuffer + offset++);
      if(index_lengthT > index_length)
        this->index = (uint8_t*)realloc(this->index, index_lengthT * sizeof(uint8_t));
      offset += 3;
      index_length = index_lengthT;
      for( uint8_t i = 0; i < index_length; i++){
      this->st_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_index);
        memcpy( &(this->index[i]), &(this->st_index), sizeof(uint8_t));
      }
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

    const char * getType(){ return "hydrus/ServoControlCmd"; };
    const char * getMD5(){ return "43c65031eacc80fd6b5892b2e27c4273"; };

  };

}
#endif