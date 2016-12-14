#ifndef _ROS_pal_vision_msgs_HogDetections_h
#define _ROS_pal_vision_msgs_HogDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_vision_msgs/HogDetection.h"

namespace pal_vision_msgs
{

  class HogDetections : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t imgID;
      uint8_t persons_length;
      pal_vision_msgs::HogDetection st_persons;
      pal_vision_msgs::HogDetection * persons;

    HogDetections():
      header(),
      imgID(0),
      persons_length(0), persons(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->imgID >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->imgID >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->imgID >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->imgID >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imgID);
      *(outbuffer + offset++) = persons_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < persons_length; i++){
      offset += this->persons[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->imgID =  ((uint32_t) (*(inbuffer + offset)));
      this->imgID |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imgID |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->imgID |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->imgID);
      uint8_t persons_lengthT = *(inbuffer + offset++);
      if(persons_lengthT > persons_length)
        this->persons = (pal_vision_msgs::HogDetection*)realloc(this->persons, persons_lengthT * sizeof(pal_vision_msgs::HogDetection));
      offset += 3;
      persons_length = persons_lengthT;
      for( uint8_t i = 0; i < persons_length; i++){
      offset += this->st_persons.deserialize(inbuffer + offset);
        memcpy( &(this->persons[i]), &(this->st_persons), sizeof(pal_vision_msgs::HogDetection));
      }
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/HogDetections"; };
    const char * getMD5(){ return "6a2b9c8c4c785ae7eec19468d16ba3c8"; };

  };

}
#endif