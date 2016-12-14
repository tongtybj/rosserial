#ifndef _ROS_naoqi_bridge_msgs_MemoryList_h
#define _ROS_naoqi_bridge_msgs_MemoryList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "naoqi_bridge_msgs/MemoryPairString.h"
#include "naoqi_bridge_msgs/MemoryPairInt.h"
#include "naoqi_bridge_msgs/MemoryPairFloat.h"

namespace naoqi_bridge_msgs
{

  class MemoryList : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t strings_length;
      naoqi_bridge_msgs::MemoryPairString st_strings;
      naoqi_bridge_msgs::MemoryPairString * strings;
      uint8_t ints_length;
      naoqi_bridge_msgs::MemoryPairInt st_ints;
      naoqi_bridge_msgs::MemoryPairInt * ints;
      uint8_t floats_length;
      naoqi_bridge_msgs::MemoryPairFloat st_floats;
      naoqi_bridge_msgs::MemoryPairFloat * floats;

    MemoryList():
      header(),
      strings_length(0), strings(NULL),
      ints_length(0), ints(NULL),
      floats_length(0), floats(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = strings_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < strings_length; i++){
      offset += this->strings[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = ints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ints_length; i++){
      offset += this->ints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = floats_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < floats_length; i++){
      offset += this->floats[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t strings_lengthT = *(inbuffer + offset++);
      if(strings_lengthT > strings_length)
        this->strings = (naoqi_bridge_msgs::MemoryPairString*)realloc(this->strings, strings_lengthT * sizeof(naoqi_bridge_msgs::MemoryPairString));
      offset += 3;
      strings_length = strings_lengthT;
      for( uint8_t i = 0; i < strings_length; i++){
      offset += this->st_strings.deserialize(inbuffer + offset);
        memcpy( &(this->strings[i]), &(this->st_strings), sizeof(naoqi_bridge_msgs::MemoryPairString));
      }
      uint8_t ints_lengthT = *(inbuffer + offset++);
      if(ints_lengthT > ints_length)
        this->ints = (naoqi_bridge_msgs::MemoryPairInt*)realloc(this->ints, ints_lengthT * sizeof(naoqi_bridge_msgs::MemoryPairInt));
      offset += 3;
      ints_length = ints_lengthT;
      for( uint8_t i = 0; i < ints_length; i++){
      offset += this->st_ints.deserialize(inbuffer + offset);
        memcpy( &(this->ints[i]), &(this->st_ints), sizeof(naoqi_bridge_msgs::MemoryPairInt));
      }
      uint8_t floats_lengthT = *(inbuffer + offset++);
      if(floats_lengthT > floats_length)
        this->floats = (naoqi_bridge_msgs::MemoryPairFloat*)realloc(this->floats, floats_lengthT * sizeof(naoqi_bridge_msgs::MemoryPairFloat));
      offset += 3;
      floats_length = floats_lengthT;
      for( uint8_t i = 0; i < floats_length; i++){
      offset += this->st_floats.deserialize(inbuffer + offset);
        memcpy( &(this->floats[i]), &(this->st_floats), sizeof(naoqi_bridge_msgs::MemoryPairFloat));
      }
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/MemoryList"; };
    const char * getMD5(){ return "7222936d1c205b51fbfdb13e468998ad"; };

  };

}
#endif