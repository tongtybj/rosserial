#ifndef _ROS_jsk_2013_04_pr2_610_geometry_vectors_h
#define _ROS_jsk_2013_04_pr2_610_geometry_vectors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace jsk_2013_04_pr2_610
{

  class geometry_vectors : public ros::Msg
  {
    public:
      uint8_t vectors_length;
      geometry_msgs::Vector3 st_vectors;
      geometry_msgs::Vector3 * vectors;

    geometry_vectors():
      vectors_length(0), vectors(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = vectors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < vectors_length; i++){
      offset += this->vectors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t vectors_lengthT = *(inbuffer + offset++);
      if(vectors_lengthT > vectors_length)
        this->vectors = (geometry_msgs::Vector3*)realloc(this->vectors, vectors_lengthT * sizeof(geometry_msgs::Vector3));
      offset += 3;
      vectors_length = vectors_lengthT;
      for( uint8_t i = 0; i < vectors_length; i++){
      offset += this->st_vectors.deserialize(inbuffer + offset);
        memcpy( &(this->vectors[i]), &(this->st_vectors), sizeof(geometry_msgs::Vector3));
      }
     return offset;
    }

    const char * getType(){ return "jsk_2013_04_pr2_610/geometry_vectors"; };
    const char * getMD5(){ return "0e70d69b80b6619295db7fb48376314f"; };

  };

}
#endif