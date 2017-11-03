#ifndef _ROS_hydrus_ServoTorqueCmd_h
#define _ROS_hydrus_ServoTorqueCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus
{

  class ServoTorqueCmd : public ros::Msg
  {
    public:
      uint8_t index_length;
      uint8_t st_index;
      uint8_t * index;
      uint8_t torque_enable_length;
      uint8_t st_torque_enable;
      uint8_t * torque_enable;

    ServoTorqueCmd():
      index_length(0), index(NULL),
      torque_enable_length(0), torque_enable(NULL)
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
      *(outbuffer + offset++) = torque_enable_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < torque_enable_length; i++){
      *(outbuffer + offset + 0) = (this->torque_enable[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->torque_enable[i]);
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
      uint8_t torque_enable_lengthT = *(inbuffer + offset++);
      if(torque_enable_lengthT > torque_enable_length)
        this->torque_enable = (uint8_t*)realloc(this->torque_enable, torque_enable_lengthT * sizeof(uint8_t));
      offset += 3;
      torque_enable_length = torque_enable_lengthT;
      for( uint8_t i = 0; i < torque_enable_length; i++){
      this->st_torque_enable =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_torque_enable);
        memcpy( &(this->torque_enable[i]), &(this->st_torque_enable), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "hydrus/ServoTorqueCmd"; };
    const char * getMD5(){ return "3bf69950d8290f79f2ce423f967a9338"; };

  };

}
#endif