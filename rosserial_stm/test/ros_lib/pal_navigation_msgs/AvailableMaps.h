#ifndef _ROS_pal_navigation_msgs_AvailableMaps_h
#define _ROS_pal_navigation_msgs_AvailableMaps_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace pal_navigation_msgs
{

  class AvailableMaps : public ros::Msg
  {
    public:
      uint8_t map_names_length;
      std_msgs::String st_map_names;
      std_msgs::String * map_names;

    AvailableMaps():
      map_names_length(0), map_names(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = map_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < map_names_length; i++){
      offset += this->map_names[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t map_names_lengthT = *(inbuffer + offset++);
      if(map_names_lengthT > map_names_length)
        this->map_names = (std_msgs::String*)realloc(this->map_names, map_names_lengthT * sizeof(std_msgs::String));
      offset += 3;
      map_names_length = map_names_lengthT;
      for( uint8_t i = 0; i < map_names_length; i++){
      offset += this->st_map_names.deserialize(inbuffer + offset);
        memcpy( &(this->map_names[i]), &(this->st_map_names), sizeof(std_msgs::String));
      }
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/AvailableMaps"; };
    const char * getMD5(){ return "9db0e90f3d30f37c0bc8af001416200d"; };

  };

}
#endif