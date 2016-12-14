#ifndef _ROS_pal_vision_msgs_FaceDetections_h
#define _ROS_pal_vision_msgs_FaceDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_vision_msgs/FaceDetection.h"

namespace pal_vision_msgs
{

  class FaceDetections : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t imgID;
      uint8_t faces_length;
      pal_vision_msgs::FaceDetection st_faces;
      pal_vision_msgs::FaceDetection * faces;

    FaceDetections():
      header(),
      imgID(0),
      faces_length(0), faces(NULL)
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
      *(outbuffer + offset++) = faces_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->faces[i].serialize(outbuffer + offset);
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
      uint8_t faces_lengthT = *(inbuffer + offset++);
      if(faces_lengthT > faces_length)
        this->faces = (pal_vision_msgs::FaceDetection*)realloc(this->faces, faces_lengthT * sizeof(pal_vision_msgs::FaceDetection));
      offset += 3;
      faces_length = faces_lengthT;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->st_faces.deserialize(inbuffer + offset);
        memcpy( &(this->faces[i]), &(this->st_faces), sizeof(pal_vision_msgs::FaceDetection));
      }
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/FaceDetections"; };
    const char * getMD5(){ return "d5cd88065d95055a47408f1591427874"; };

  };

}
#endif