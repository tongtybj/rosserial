#ifndef _ROS_pal_navigation_msgs_TabletPOI_h
#define _ROS_pal_navigation_msgs_TabletPOI_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/String.h"

namespace pal_navigation_msgs
{

  class TabletPOI : public ros::Msg
  {
    public:
      uint8_t POIs_length;
      geometry_msgs::Point st_POIs;
      geometry_msgs::Point * POIs;
      uint8_t IDs_length;
      std_msgs::String st_IDs;
      std_msgs::String * IDs;
      std_msgs::String map_id;

    TabletPOI():
      POIs_length(0), POIs(NULL),
      IDs_length(0), IDs(NULL),
      map_id()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = POIs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < POIs_length; i++){
      offset += this->POIs[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = IDs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < IDs_length; i++){
      offset += this->IDs[i].serialize(outbuffer + offset);
      }
      offset += this->map_id.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t POIs_lengthT = *(inbuffer + offset++);
      if(POIs_lengthT > POIs_length)
        this->POIs = (geometry_msgs::Point*)realloc(this->POIs, POIs_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      POIs_length = POIs_lengthT;
      for( uint8_t i = 0; i < POIs_length; i++){
      offset += this->st_POIs.deserialize(inbuffer + offset);
        memcpy( &(this->POIs[i]), &(this->st_POIs), sizeof(geometry_msgs::Point));
      }
      uint8_t IDs_lengthT = *(inbuffer + offset++);
      if(IDs_lengthT > IDs_length)
        this->IDs = (std_msgs::String*)realloc(this->IDs, IDs_lengthT * sizeof(std_msgs::String));
      offset += 3;
      IDs_length = IDs_lengthT;
      for( uint8_t i = 0; i < IDs_length; i++){
      offset += this->st_IDs.deserialize(inbuffer + offset);
        memcpy( &(this->IDs[i]), &(this->st_IDs), sizeof(std_msgs::String));
      }
      offset += this->map_id.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/TabletPOI"; };
    const char * getMD5(){ return "2ec4b22e981d882e9e77e8562cb8c5fe"; };

  };

}
#endif