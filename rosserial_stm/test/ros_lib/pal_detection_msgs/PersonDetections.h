#ifndef _ROS_pal_detection_msgs_PersonDetections_h
#define _ROS_pal_detection_msgs_PersonDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_detection_msgs/PersonDetection.h"
#include "geometry_msgs/TransformStamped.h"

namespace pal_detection_msgs
{

  class PersonDetections : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t persons_length;
      pal_detection_msgs::PersonDetection st_persons;
      pal_detection_msgs::PersonDetection * persons;
      geometry_msgs::TransformStamped camera_pose;

    PersonDetections():
      header(),
      persons_length(0), persons(NULL),
      camera_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = persons_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < persons_length; i++){
      offset += this->persons[i].serialize(outbuffer + offset);
      }
      offset += this->camera_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t persons_lengthT = *(inbuffer + offset++);
      if(persons_lengthT > persons_length)
        this->persons = (pal_detection_msgs::PersonDetection*)realloc(this->persons, persons_lengthT * sizeof(pal_detection_msgs::PersonDetection));
      offset += 3;
      persons_length = persons_lengthT;
      for( uint8_t i = 0; i < persons_length; i++){
      offset += this->st_persons.deserialize(inbuffer + offset);
        memcpy( &(this->persons[i]), &(this->st_persons), sizeof(pal_detection_msgs::PersonDetection));
      }
      offset += this->camera_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/PersonDetections"; };
    const char * getMD5(){ return "b8526b10d4ba6d5b2201045a70a54f2f"; };

  };

}
#endif