#ifndef _ROS_jsk_demo_common_FunctionEvent_h
#define _ROS_jsk_demo_common_FunctionEvent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_demo_common/EventHeader.h"

namespace jsk_demo_common
{

  class FunctionEvent : public ros::Msg
  {
    public:
      jsk_demo_common::EventHeader header;
      const char* name;
      uint8_t args_length;
      char* st_args;
      char* * args;

    FunctionEvent():
      header(),
      name(""),
      args_length(0), args(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset++) = args_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < args_length; i++){
      uint32_t length_argsi = strlen(this->args[i]);
      memcpy(outbuffer + offset, &length_argsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->args[i], length_argsi);
      offset += length_argsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint8_t args_lengthT = *(inbuffer + offset++);
      if(args_lengthT > args_length)
        this->args = (char**)realloc(this->args, args_lengthT * sizeof(char*));
      offset += 3;
      args_length = args_lengthT;
      for( uint8_t i = 0; i < args_length; i++){
      uint32_t length_st_args;
      memcpy(&length_st_args, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_args; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_args-1]=0;
      this->st_args = (char *)(inbuffer + offset-1);
      offset += length_st_args;
        memcpy( &(this->args[i]), &(this->st_args), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "jsk_demo_common/FunctionEvent"; };
    const char * getMD5(){ return "bf47da6bc395a1b9e19d62c19624bc57"; };

  };

}
#endif