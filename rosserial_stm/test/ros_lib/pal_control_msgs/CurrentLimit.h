#ifndef _ROS_SERVICE_CurrentLimit_h
#define _ROS_SERVICE_CurrentLimit_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_control_msgs
{

static const char CURRENTLIMIT[] = "pal_control_msgs/CurrentLimit";

  class CurrentLimitRequest : public ros::Msg
  {
    public:
      const char* actuator_name;
      double current_limit;

    CurrentLimitRequest():
      actuator_name(""),
      current_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_actuator_name = strlen(this->actuator_name);
      memcpy(outbuffer + offset, &length_actuator_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->actuator_name, length_actuator_name);
      offset += length_actuator_name;
      union {
        double real;
        uint64_t base;
      } u_current_limit;
      u_current_limit.real = this->current_limit;
      *(outbuffer + offset + 0) = (u_current_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_limit.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_current_limit.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_current_limit.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_current_limit.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_current_limit.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_actuator_name;
      memcpy(&length_actuator_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_actuator_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_actuator_name-1]=0;
      this->actuator_name = (char *)(inbuffer + offset-1);
      offset += length_actuator_name;
      union {
        double real;
        uint64_t base;
      } u_current_limit;
      u_current_limit.base = 0;
      u_current_limit.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_limit.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_limit.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_limit.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_current_limit.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_current_limit.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_current_limit.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_current_limit.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->current_limit = u_current_limit.real;
      offset += sizeof(this->current_limit);
     return offset;
    }

    const char * getType(){ return CURRENTLIMIT; };
    const char * getMD5(){ return "6d1326759cec3fceb10a88d2834f6fba"; };

  };

  class CurrentLimitResponse : public ros::Msg
  {
    public:
      const char* status;

    CurrentLimitResponse():
      status("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_status = strlen(this->status);
      memcpy(outbuffer + offset, &length_status, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_status;
      memcpy(&length_status, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
     return offset;
    }

    const char * getType(){ return CURRENTLIMIT; };
    const char * getMD5(){ return "4fe5af303955c287688e7347e9b00278"; };

  };

  class CurrentLimit {
    public:
    typedef CurrentLimitRequest Request;
    typedef CurrentLimitResponse Response;
  };

}
#endif
