#ifndef _ROS_pal_detection_msgs_PersonDetection_h
#define _ROS_pal_detection_msgs_PersonDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_detection_msgs/Detection2d.h"
#include "pal_detection_msgs/FaceDetection.h"
#include "pal_detection_msgs/LegDetections.h"
#include "geometry_msgs/PointStamped.h"

namespace pal_detection_msgs
{

  class PersonDetection : public ros::Msg
  {
    public:
      pal_detection_msgs::Detection2d full_body;
      pal_detection_msgs::FaceDetection face;
      pal_detection_msgs::LegDetections legs;
      geometry_msgs::PointStamped position3D;

    PersonDetection():
      full_body(),
      face(),
      legs(),
      position3D()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->full_body.serialize(outbuffer + offset);
      offset += this->face.serialize(outbuffer + offset);
      offset += this->legs.serialize(outbuffer + offset);
      offset += this->position3D.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->full_body.deserialize(inbuffer + offset);
      offset += this->face.deserialize(inbuffer + offset);
      offset += this->legs.deserialize(inbuffer + offset);
      offset += this->position3D.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/PersonDetection"; };
    const char * getMD5(){ return "e3c696a3e9a746473dc492f12e81a1f5"; };

  };

}
#endif