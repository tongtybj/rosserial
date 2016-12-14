#ifndef _ROS_roseus_remote_RawCommand_h
#define _ROS_roseus_remote_RawCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace roseus_remote
{

  class RawCommand : public ros::Msg
  {
    public:
      uint8_t data[1024];

    RawCommand():
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 1024; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 1024; i++){
      this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data[i]);
      }
     return offset;
    }

    const char * getType(){ return "roseus_remote/RawCommand"; };
    const char * getMD5(){ return "3a98047919201ddd4c818d061ad4865b"; };

  };

}
#endif