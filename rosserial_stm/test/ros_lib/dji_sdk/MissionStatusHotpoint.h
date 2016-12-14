#ifndef _ROS_dji_sdk_MissionStatusHotpoint_h
#define _ROS_dji_sdk_MissionStatusHotpoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionStatusHotpoint : public ros::Msg
  {
    public:
      uint8_t mission_type;
      uint8_t mission_status;
      uint16_t hotpoint_radius;
      uint8_t error_code;
      uint8_t hotpoint_velocity;

    MissionStatusHotpoint():
      mission_type(0),
      mission_status(0),
      hotpoint_radius(0),
      error_code(0),
      hotpoint_velocity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mission_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mission_type);
      *(outbuffer + offset + 0) = (this->mission_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mission_status);
      *(outbuffer + offset + 0) = (this->hotpoint_radius >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hotpoint_radius >> (8 * 1)) & 0xFF;
      offset += sizeof(this->hotpoint_radius);
      *(outbuffer + offset + 0) = (this->error_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_code);
      *(outbuffer + offset + 0) = (this->hotpoint_velocity >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hotpoint_velocity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mission_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mission_type);
      this->mission_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mission_status);
      this->hotpoint_radius =  ((uint16_t) (*(inbuffer + offset)));
      this->hotpoint_radius |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->hotpoint_radius);
      this->error_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error_code);
      this->hotpoint_velocity =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->hotpoint_velocity);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionStatusHotpoint"; };
    const char * getMD5(){ return "8139577a287bd3bb109446868782e2f7"; };

  };

}
#endif