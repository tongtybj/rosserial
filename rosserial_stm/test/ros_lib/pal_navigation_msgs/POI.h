#ifndef _ROS_pal_navigation_msgs_POI_h
#define _ROS_pal_navigation_msgs_POI_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud.h"
#include "std_msgs/String.h"

namespace pal_navigation_msgs
{

  class POI : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud points;
      uint8_t ids_length;
      std_msgs::String st_ids;
      std_msgs::String * ids;
      std_msgs::String map_id;

    POI():
      points(),
      ids_length(0), ids(NULL),
      map_id()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->points.serialize(outbuffer + offset);
      *(outbuffer + offset++) = ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ids_length; i++){
      offset += this->ids[i].serialize(outbuffer + offset);
      }
      offset += this->map_id.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->points.deserialize(inbuffer + offset);
      uint8_t ids_lengthT = *(inbuffer + offset++);
      if(ids_lengthT > ids_length)
        this->ids = (std_msgs::String*)realloc(this->ids, ids_lengthT * sizeof(std_msgs::String));
      offset += 3;
      ids_length = ids_lengthT;
      for( uint8_t i = 0; i < ids_length; i++){
      offset += this->st_ids.deserialize(inbuffer + offset);
        memcpy( &(this->ids[i]), &(this->st_ids), sizeof(std_msgs::String));
      }
      offset += this->map_id.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/POI"; };
    const char * getMD5(){ return "accd8dd07484c01aa4180821c83d7d4f"; };

  };

}
#endif