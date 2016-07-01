#ifndef _ROS_pal_detection_msgs_Detections2d_h
#define _ROS_pal_detection_msgs_Detections2d_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_detection_msgs/Detection2d.h"
#include "geometry_msgs/TransformStamped.h"

namespace pal_detection_msgs
{

  class Detections2d : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t detections_length;
      pal_detection_msgs::Detection2d st_detections;
      pal_detection_msgs::Detection2d * detections;
      geometry_msgs::TransformStamped camera_pose;

    Detections2d():
      header(),
      detections_length(0), detections(NULL),
      camera_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = detections_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < detections_length; i++){
      offset += this->detections[i].serialize(outbuffer + offset);
      }
      offset += this->camera_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t detections_lengthT = *(inbuffer + offset++);
      if(detections_lengthT > detections_length)
        this->detections = (pal_detection_msgs::Detection2d*)realloc(this->detections, detections_lengthT * sizeof(pal_detection_msgs::Detection2d));
      offset += 3;
      detections_length = detections_lengthT;
      for( uint8_t i = 0; i < detections_length; i++){
      offset += this->st_detections.deserialize(inbuffer + offset);
        memcpy( &(this->detections[i]), &(this->st_detections), sizeof(pal_detection_msgs::Detection2d));
      }
      offset += this->camera_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/Detections2d"; };
    const char * getMD5(){ return "508e4e5ac7930673178d3ead64ba3f4b"; };

  };

}
#endif