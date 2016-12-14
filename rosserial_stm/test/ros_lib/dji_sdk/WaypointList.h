#ifndef _ROS_dji_sdk_WaypointList_h
#define _ROS_dji_sdk_WaypointList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/Waypoint.h"

namespace dji_sdk
{

  class WaypointList : public ros::Msg
  {
    public:
      uint8_t waypoint_list_length;
      dji_sdk::Waypoint st_waypoint_list;
      dji_sdk::Waypoint * waypoint_list;

    WaypointList():
      waypoint_list_length(0), waypoint_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = waypoint_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < waypoint_list_length; i++){
      offset += this->waypoint_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t waypoint_list_lengthT = *(inbuffer + offset++);
      if(waypoint_list_lengthT > waypoint_list_length)
        this->waypoint_list = (dji_sdk::Waypoint*)realloc(this->waypoint_list, waypoint_list_lengthT * sizeof(dji_sdk::Waypoint));
      offset += 3;
      waypoint_list_length = waypoint_list_lengthT;
      for( uint8_t i = 0; i < waypoint_list_length; i++){
      offset += this->st_waypoint_list.deserialize(inbuffer + offset);
        memcpy( &(this->waypoint_list[i]), &(this->st_waypoint_list), sizeof(dji_sdk::Waypoint));
      }
     return offset;
    }

    const char * getType(){ return "dji_sdk/WaypointList"; };
    const char * getMD5(){ return "284386e6fe0f355bdea1db93ead90084"; };

  };

}
#endif