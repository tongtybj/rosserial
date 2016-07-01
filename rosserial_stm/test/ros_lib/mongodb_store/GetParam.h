#ifndef _ROS_SERVICE_GetParam_h
#define _ROS_SERVICE_GetParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mongodb_store
{

static const char GETPARAM[] = "mongodb_store/GetParam";

  class GetParamRequest : public ros::Msg
  {
    public:
      const char* param_name;

    GetParamRequest():
      param_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_param_name = strlen(this->param_name);
      memcpy(outbuffer + offset, &length_param_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->param_name, length_param_name);
      offset += length_param_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_param_name;
      memcpy(&length_param_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_param_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_param_name-1]=0;
      this->param_name = (char *)(inbuffer + offset-1);
      offset += length_param_name;
     return offset;
    }

    const char * getType(){ return GETPARAM; };
    const char * getMD5(){ return "b381fd4edcffd7ff5b5a7e1630491a17"; };

  };

  class GetParamResponse : public ros::Msg
  {
    public:
      bool success;
      const char* param_value;

    GetParamResponse():
      success(0),
      param_value("")
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
      uint32_t length_param_value = strlen(this->param_value);
      memcpy(outbuffer + offset, &length_param_value, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->param_value, length_param_value);
      offset += length_param_value;
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
      uint32_t length_param_value;
      memcpy(&length_param_value, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_param_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_param_value-1]=0;
      this->param_value = (char *)(inbuffer + offset-1);
      offset += length_param_value;
     return offset;
    }

    const char * getType(){ return GETPARAM; };
    const char * getMD5(){ return "bfcec4af20d6b267ef6ee8d3934547c3"; };

  };

  class GetParam {
    public:
    typedef GetParamRequest Request;
    typedef GetParamResponse Response;
  };

}
#endif
