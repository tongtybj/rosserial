#ifndef _ROS_dji_sdk_MissionEventWpReach_h
#define _ROS_dji_sdk_MissionEventWpReach_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionEventWpReach : public ros::Msg
  {
    public:
      uint8_t incident_type;
      uint8_t waypoint_index;
      uint8_t current_status;

    MissionEventWpReach():
      incident_type(0),
      waypoint_index(0),
      current_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->incident_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->incident_type);
      *(outbuffer + offset + 0) = (this->waypoint_index >> (8 * 0)) & 0xFF;
      offset += sizeof(this->waypoint_index);
      *(outbuffer + offset + 0) = (this->current_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->incident_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->incident_type);
      this->waypoint_index =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->waypoint_index);
      this->current_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->current_status);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionEventWpReach"; };
    const char * getMD5(){ return "887664b69cd341b8a21df490bb79afea"; };

  };

}
#endif