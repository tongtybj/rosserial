#ifndef _ROS_SERVICE_AddExtraModule_h
#define _ROS_SERVICE_AddExtraModule_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus
{

static const char ADDEXTRAMODULE[] = "hydrus/AddExtraModule";

  class AddExtraModuleRequest : public ros::Msg
  {
    public:
      uint8_t extra_module_link;
      float extra_module_mass;
      float extra_module_offset;

    AddExtraModuleRequest():
      extra_module_link(0),
      extra_module_mass(0),
      extra_module_offset(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->extra_module_link >> (8 * 0)) & 0xFF;
      offset += sizeof(this->extra_module_link);
      union {
        float real;
        uint32_t base;
      } u_extra_module_mass;
      u_extra_module_mass.real = this->extra_module_mass;
      *(outbuffer + offset + 0) = (u_extra_module_mass.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_extra_module_mass.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_extra_module_mass.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_extra_module_mass.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extra_module_mass);
      union {
        float real;
        uint32_t base;
      } u_extra_module_offset;
      u_extra_module_offset.real = this->extra_module_offset;
      *(outbuffer + offset + 0) = (u_extra_module_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_extra_module_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_extra_module_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_extra_module_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extra_module_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->extra_module_link =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->extra_module_link);
      union {
        float real;
        uint32_t base;
      } u_extra_module_mass;
      u_extra_module_mass.base = 0;
      u_extra_module_mass.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_extra_module_mass.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_extra_module_mass.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_extra_module_mass.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->extra_module_mass = u_extra_module_mass.real;
      offset += sizeof(this->extra_module_mass);
      union {
        float real;
        uint32_t base;
      } u_extra_module_offset;
      u_extra_module_offset.base = 0;
      u_extra_module_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_extra_module_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_extra_module_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_extra_module_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->extra_module_offset = u_extra_module_offset.real;
      offset += sizeof(this->extra_module_offset);
     return offset;
    }

    const char * getType(){ return ADDEXTRAMODULE; };
    const char * getMD5(){ return "4b4693ffd53a07651fa2f6bb472badbd"; };

  };

  class AddExtraModuleResponse : public ros::Msg
  {
    public:
      bool status;

    AddExtraModuleResponse():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return ADDEXTRAMODULE; };
    const char * getMD5(){ return "3a1255d4d998bd4d6585c64639b5ee9a"; };

  };

  class AddExtraModule {
    public:
    typedef AddExtraModuleRequest Request;
    typedef AddExtraModuleResponse Response;
  };

}
#endif
