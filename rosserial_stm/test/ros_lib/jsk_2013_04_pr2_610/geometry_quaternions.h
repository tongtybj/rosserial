#ifndef _ROS_jsk_2013_04_pr2_610_geometry_quaternions_h
#define _ROS_jsk_2013_04_pr2_610_geometry_quaternions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Quaternion.h"

namespace jsk_2013_04_pr2_610
{

  class geometry_quaternions : public ros::Msg
  {
    public:
      uint8_t quaternions_length;
      geometry_msgs::Quaternion st_quaternions;
      geometry_msgs::Quaternion * quaternions;

    geometry_quaternions():
      quaternions_length(0), quaternions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = quaternions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < quaternions_length; i++){
      offset += this->quaternions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t quaternions_lengthT = *(inbuffer + offset++);
      if(quaternions_lengthT > quaternions_length)
        this->quaternions = (geometry_msgs::Quaternion*)realloc(this->quaternions, quaternions_lengthT * sizeof(geometry_msgs::Quaternion));
      offset += 3;
      quaternions_length = quaternions_lengthT;
      for( uint8_t i = 0; i < quaternions_length; i++){
      offset += this->st_quaternions.deserialize(inbuffer + offset);
        memcpy( &(this->quaternions[i]), &(this->st_quaternions), sizeof(geometry_msgs::Quaternion));
      }
     return offset;
    }

    const char * getType(){ return "jsk_2013_04_pr2_610/geometry_quaternions"; };
    const char * getMD5(){ return "c666021c5a7330bd53d9827c2e91d9f6"; };

  };

}
#endif