#ifndef _ROS_SERVICE_ListCameras_h
#define _ROS_SERVICE_ListCameras_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace baxter_core_msgs
{

static const char LISTCAMERAS[] = "baxter_core_msgs/ListCameras";

  class ListCamerasRequest : public ros::Msg
  {
    public:

    ListCamerasRequest()
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

    const char * getType(){ return LISTCAMERAS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListCamerasResponse : public ros::Msg
  {
    public:
      uint8_t cameras_length;
      char* st_cameras;
      char* * cameras;

    ListCamerasResponse():
      cameras_length(0), cameras(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = cameras_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cameras_length; i++){
      uint32_t length_camerasi = strlen(this->cameras[i]);
      memcpy(outbuffer + offset, &length_camerasi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->cameras[i], length_camerasi);
      offset += length_camerasi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t cameras_lengthT = *(inbuffer + offset++);
      if(cameras_lengthT > cameras_length)
        this->cameras = (char**)realloc(this->cameras, cameras_lengthT * sizeof(char*));
      offset += 3;
      cameras_length = cameras_lengthT;
      for( uint8_t i = 0; i < cameras_length; i++){
      uint32_t length_st_cameras;
      memcpy(&length_st_cameras, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_cameras; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_cameras-1]=0;
      this->st_cameras = (char *)(inbuffer + offset-1);
      offset += length_st_cameras;
        memcpy( &(this->cameras[i]), &(this->st_cameras), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return LISTCAMERAS; };
    const char * getMD5(){ return "855b31192ab61744e7deb992d94db7ff"; };

  };

  class ListCameras {
    public:
    typedef ListCamerasRequest Request;
    typedef ListCamerasResponse Response;
  };

}
#endif
