#ifndef _ROS_SERVICE_SaveMap_h
#define _ROS_SERVICE_SaveMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char SAVEMAP[] = "pal_navigation_msgs/SaveMap";

  class SaveMapRequest : public ros::Msg
  {
    public:
      const char* directory;

    SaveMapRequest():
      directory("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_directory = strlen(this->directory);
      memcpy(outbuffer + offset, &length_directory, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->directory, length_directory);
      offset += length_directory;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_directory;
      memcpy(&length_directory, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_directory; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_directory-1]=0;
      this->directory = (char *)(inbuffer + offset-1);
      offset += length_directory;
     return offset;
    }

    const char * getType(){ return SAVEMAP; };
    const char * getMD5(){ return "310e138069b8368226f05a8c4e7bb107"; };

  };

  class SaveMapResponse : public ros::Msg
  {
    public:
      bool success;
      const char* name;
      const char* full_path;
      const char* message;

    SaveMapResponse():
      success(0),
      name(""),
      full_path(""),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_full_path = strlen(this->full_path);
      memcpy(outbuffer + offset, &length_full_path, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->full_path, length_full_path);
      offset += length_full_path;
      uint32_t length_message = strlen(this->message);
      memcpy(outbuffer + offset, &length_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_full_path;
      memcpy(&length_full_path, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_full_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_full_path-1]=0;
      this->full_path = (char *)(inbuffer + offset-1);
      offset += length_full_path;
      uint32_t length_message;
      memcpy(&length_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return SAVEMAP; };
    const char * getMD5(){ return "0cbfca185576cdac677b2dbfe46084ca"; };

  };

  class SaveMap {
    public:
    typedef SaveMapRequest Request;
    typedef SaveMapResponse Response;
  };

}
#endif
