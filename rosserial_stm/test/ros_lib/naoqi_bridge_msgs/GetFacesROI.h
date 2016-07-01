#ifndef _ROS_SERVICE_GetFacesROI_h
#define _ROS_SERVICE_GetFacesROI_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/FaceROI.h"

namespace naoqi_bridge_msgs
{

static const char GETFACESROI[] = "naoqi_bridge_msgs/GetFacesROI";

  class GetFacesROIRequest : public ros::Msg
  {
    public:

    GetFacesROIRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETFACESROI; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetFacesROIResponse : public ros::Msg
  {
    public:
      uint8_t faces_length;
      naoqi_bridge_msgs::FaceROI st_faces;
      naoqi_bridge_msgs::FaceROI * faces;

    GetFacesROIResponse():
      faces_length(0), faces(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      uint8_t faces_lengthT = *(inbuffer + offset++);
      if(faces_lengthT > faces_length)
        this->faces = (naoqi_bridge_msgs::FaceROI*)realloc(this->faces, faces_lengthT * sizeof(naoqi_bridge_msgs::FaceROI));
      offset += 3;
      faces_length = faces_lengthT;
      for( uint8_t i = 0; i < faces_length; i++){
      offset += this->st_faces.deserialize(inbuffer + offset);
        memcpy( &(this->faces[i]), &(this->st_faces), sizeof(naoqi_bridge_msgs::FaceROI));
      }
     return offset;
    }

    const char * getType(){ return GETFACESROI; };
    const char * getMD5(){ return "7123975ed3d5d1cde8b35e6736592769"; };

  };

  class GetFacesROI {
    public:
    typedef GetFacesROIRequest Request;
    typedef GetFacesROIResponse Response;
  };

}
#endif
