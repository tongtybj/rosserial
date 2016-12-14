#ifndef _ROS_dji_sdk_MissionStatusWaypoint_h
#define _ROS_dji_sdk_MissionStatusWaypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionStatusWaypoint : public ros::Msg
  {
    public:
      uint8_t mission_type;
      uint8_t target_waypoint;
      uint8_t current_status;
      uint8_t error_code;

    MissionStatusWaypoint():
      mission_type(0),
      target_waypoint(0),
      current_status(0),
      error_code(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mission_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mission_type);
      *(outbuffer + offset + 0) = (this->target_waypoint >> (8 * 0)) & 0xFF;
      offset += sizeof(this->target_waypoint);
      *(outbuffer + offset + 0) = (this->current_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_status);
      *(outbuffer + offset + 0) = (this->error_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_code);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mission_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mission_type);
      this->target_waypoint =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->target_waypoint);
      this->current_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->current_status);
      this->error_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error_code);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionStatusWaypoint"; };
    const char * getMD5(){ return "4f2b7b1e7f32be55abc541c1b7552d41"; };

  };

}
#endif