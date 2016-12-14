#ifndef _ROS_pal_detection_msgs_TexturedObjectDetection_h
#define _ROS_pal_detection_msgs_TexturedObjectDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/CompressedImage.h"
#include "pal_detection_msgs/RotatedDetection2d.h"

namespace pal_detection_msgs
{

  class TexturedObjectDetection : public ros::Msg
  {
    public:
      std_msgs::Header header;
      sensor_msgs::CompressedImage img;
      pal_detection_msgs::RotatedDetection2d roi;

    TexturedObjectDetection():
      header(),
      img(),
      roi()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->img.serialize(outbuffer + offset);
      offset += this->roi.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->img.deserialize(inbuffer + offset);
      offset += this->roi.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/TexturedObjectDetection"; };
    const char * getMD5(){ return "cb7f0068423d23f481cd8a23473b3e42"; };

  };

}
#endif