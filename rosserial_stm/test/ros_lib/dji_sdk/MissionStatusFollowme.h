#ifndef _ROS_dji_sdk_MissionStatusFollowme_h
#define _ROS_dji_sdk_MissionStatusFollowme_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionStatusFollowme : public ros::Msg
  {
    public:
      uint8_t mission_type;

    MissionStatusFollowme():
      mission_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mission_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mission_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mission_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mission_type);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionStatusFollowme"; };
    const char * getMD5(){ return "917010b744881889ec912637e401b269"; };

  };

}
#endif