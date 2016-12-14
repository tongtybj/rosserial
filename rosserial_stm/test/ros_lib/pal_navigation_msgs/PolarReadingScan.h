#ifndef _ROS_pal_navigation_msgs_PolarReadingScan_h
#define _ROS_pal_navigation_msgs_PolarReadingScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_navigation_msgs/PolarReading.h"

namespace pal_navigation_msgs
{

  class PolarReadingScan : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t readings_length;
      pal_navigation_msgs::PolarReading st_readings;
      pal_navigation_msgs::PolarReading * readings;

    PolarReadingScan():
      header(),
      readings_length(0), readings(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = readings_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < readings_length; i++){
      offset += this->readings[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t readings_lengthT = *(inbuffer + offset++);
      if(readings_lengthT > readings_length)
        this->readings = (pal_navigation_msgs::PolarReading*)realloc(this->readings, readings_lengthT * sizeof(pal_navigation_msgs::PolarReading));
      offset += 3;
      readings_length = readings_lengthT;
      for( uint8_t i = 0; i < readings_length; i++){
      offset += this->st_readings.deserialize(inbuffer + offset);
        memcpy( &(this->readings[i]), &(this->st_readings), sizeof(pal_navigation_msgs::PolarReading));
      }
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/PolarReadingScan"; };
    const char * getMD5(){ return "31bf8adf3389c9066eb83f63abcbe26f"; };

  };

}
#endif