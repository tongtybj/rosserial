#ifndef _ROS_jsk_laser_JskLaser_h
#define _ROS_jsk_laser_JskLaser_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_laser
{

  class JskLaser : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t distances_length;
      float st_distances;
      float * distances;

    JskLaser():
      header(),
      distances_length(0), distances(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = distances_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < distances_length; i++){
      union {
        float real;
        uint32_t base;
      } u_distancesi;
      u_distancesi.real = this->distances[i];
      *(outbuffer + offset + 0) = (u_distancesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distancesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distancesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distancesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distances[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t distances_lengthT = *(inbuffer + offset++);
      if(distances_lengthT > distances_length)
        this->distances = (float*)realloc(this->distances, distances_lengthT * sizeof(float));
      offset += 3;
      distances_length = distances_lengthT;
      for( uint8_t i = 0; i < distances_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_distances;
      u_st_distances.base = 0;
      u_st_distances.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_distances.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_distances.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_distances.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_distances = u_st_distances.real;
      offset += sizeof(this->st_distances);
        memcpy( &(this->distances[i]), &(this->st_distances), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_laser/JskLaser"; };
    const char * getMD5(){ return "65ad1624c42a7e474b9065b087ea80a5"; };

  };

}
#endif