#ifndef _ROS_pal_vision_msgs_LegDetections_h
#define _ROS_pal_vision_msgs_LegDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace pal_vision_msgs
{

  class LegDetections : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t position3D_length;
      geometry_msgs::Point st_position3D;
      geometry_msgs::Point * position3D;

    LegDetections():
      header(),
      position3D_length(0), position3D(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = position3D_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < position3D_length; i++){
      offset += this->position3D[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t position3D_lengthT = *(inbuffer + offset++);
      if(position3D_lengthT > position3D_length)
        this->position3D = (geometry_msgs::Point*)realloc(this->position3D, position3D_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      position3D_length = position3D_lengthT;
      for( uint8_t i = 0; i < position3D_length; i++){
      offset += this->st_position3D.deserialize(inbuffer + offset);
        memcpy( &(this->position3D[i]), &(this->st_position3D), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/LegDetections"; };
    const char * getMD5(){ return "817c989208cff6eff51aae475bf50d0f"; };

  };

}
#endif