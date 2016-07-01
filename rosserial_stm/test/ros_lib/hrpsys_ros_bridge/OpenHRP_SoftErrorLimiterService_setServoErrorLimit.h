#ifndef _ROS_SERVICE_OpenHRP_SoftErrorLimiterService_setServoErrorLimit_h
#define _ROS_SERVICE_OpenHRP_SoftErrorLimiterService_setServoErrorLimit_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SOFTERRORLIMITERSERVICE_SETSERVOERRORLIMIT[] = "hrpsys_ros_bridge/OpenHRP_SoftErrorLimiterService_setServoErrorLimit";

  class OpenHRP_SoftErrorLimiterService_setServoErrorLimitRequest : public ros::Msg
  {
    public:
      const char* name;
      double limit;

    OpenHRP_SoftErrorLimiterService_setServoErrorLimitRequest():
      name(""),
      limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        double real;
        uint64_t base;
      } u_limit;
      u_limit.real = this->limit;
      *(outbuffer + offset + 0) = (u_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_limit.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_limit.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_limit.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_limit.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_limit.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        double real;
        uint64_t base;
      } u_limit;
      u_limit.base = 0;
      u_limit.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_limit.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_limit.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_limit.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_limit.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_limit.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_limit.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_limit.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->limit = u_limit.real;
      offset += sizeof(this->limit);
     return offset;
    }

    const char * getType(){ return OPENHRP_SOFTERRORLIMITERSERVICE_SETSERVOERRORLIMIT; };
    const char * getMD5(){ return "d662ce8bf785722c53b242dac4a01f11"; };

  };

  class OpenHRP_SoftErrorLimiterService_setServoErrorLimitResponse : public ros::Msg
  {
    public:

    OpenHRP_SoftErrorLimiterService_setServoErrorLimitResponse()
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

    const char * getType(){ return OPENHRP_SOFTERRORLIMITERSERVICE_SETSERVOERRORLIMIT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SoftErrorLimiterService_setServoErrorLimit {
    public:
    typedef OpenHRP_SoftErrorLimiterService_setServoErrorLimitRequest Request;
    typedef OpenHRP_SoftErrorLimiterService_setServoErrorLimitResponse Response;
  };

}
#endif
