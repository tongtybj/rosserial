#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_waitFootStepsEarly_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_waitFootStepsEarly_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_WAITFOOTSTEPSEARLY[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_waitFootStepsEarly";

  class OpenHRP_AutoBalancerService_waitFootStepsEarlyRequest : public ros::Msg
  {
    public:
      double tm;

    OpenHRP_AutoBalancerService_waitFootStepsEarlyRequest():
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_tm;
      u_tm.real = this->tm;
      *(outbuffer + offset + 0) = (u_tm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tm.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tm.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tm.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tm.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tm.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_tm;
      u_tm.base = 0;
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->tm = u_tm.real;
      offset += sizeof(this->tm);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_WAITFOOTSTEPSEARLY; };
    const char * getMD5(){ return "965b531338cd158d383ca8bc28ad9e18"; };

  };

  class OpenHRP_AutoBalancerService_waitFootStepsEarlyResponse : public ros::Msg
  {
    public:

    OpenHRP_AutoBalancerService_waitFootStepsEarlyResponse()
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_WAITFOOTSTEPSEARLY; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_AutoBalancerService_waitFootStepsEarly {
    public:
    typedef OpenHRP_AutoBalancerService_waitFootStepsEarlyRequest Request;
    typedef OpenHRP_AutoBalancerService_waitFootStepsEarlyResponse Response;
  };

}
#endif
