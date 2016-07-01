#ifndef _ROS_pal_detection_msgs_FaceDetections_h
#define _ROS_pal_detection_msgs_FaceDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_detection_msgs/FaceDetection.h"
#include "geometry_msgs/TransformStamped.h"

namespace pal_detection_msgs
{

  class FaceDetections : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t faces_length;
      pal_detection_msgs::FaceDetection st_faces;
      pal_detection_msgs::FaceDetection * faces;
      geometry_msgs::TransformStamped camera_pose;

    FaceDetections():
      header(),
      faces_length(0), faces(NULL),
      camera_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = faces_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->faces[i].serialize(outbuffer + offset);
      }
      offset += this->camera_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t faces_lengthT = *(inbuffer + offset++);
      if(faces_lengthT > faces_length)
        this->faces = (pal_detection_msgs::FaceDetection*)realloc(this->faces, faces_lengthT * sizeof(pal_detection_msgs::FaceDetection));
      offset += 3;
      faces_length = faces_lengthT;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->st_faces.deserialize(inbuffer + offset);
        memcpy( &(this->faces[i]), &(this->st_faces), sizeof(pal_detection_msgs::FaceDetection));
      }
      offset += this->camera_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/FaceDetections"; };
    const char * getMD5(){ return "9c3803fd595086c10ea04606f667cfc6"; };

  };

}
#endif