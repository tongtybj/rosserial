#ifndef _ROS_dji_sdk_MissionStatusOther_h
#define _ROS_dji_sdk_MissionStatusOther_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionStatusOther : public ros::Msg
  {
    public:
      uint8_t mission_type;
      uint8_t last_mission_type;
      uint8_t is_broken;
      uint8_t error_code;

    MissionStatusOther():
      mission_type(0),
      last_mission_type(0),
      is_broken(0),
      error_code(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mission_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mission_type);
      *(outbuffer + offset + 0) = (this->last_mission_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->last_mission_type);
      *(outbuffer + offset + 0) = (this->is_broken >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_broken);
      *(outbuffer + offset + 0) = (this->error_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_code);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mission_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mission_type);
      this->last_mission_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->last_mission_type);
      this->is_broken =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->is_broken);
      this->error_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error_code);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionStatusOther"; };
    const char * getMD5(){ return "a0261ae1eb980895a8685db930ec1a68"; };

  };

}
#endif