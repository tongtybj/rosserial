#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_goVelocity_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_goVelocity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GOVELOCITY[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_goVelocity";

  class OpenHRP_AutoBalancerService_goVelocityRequest : public ros::Msg
  {
    public:
      double vx;
      double vy;
      double vth;

    OpenHRP_AutoBalancerService_goVelocityRequest():
      vx(0),
      vy(0),
      vth(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_vx;
      u_vx.real = this->vx;
      *(outbuffer + offset + 0) = (u_vx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vx.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vx.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vx.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vx.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vx.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vx);
      union {
        double real;
        uint64_t base;
      } u_vy;
      u_vy.real = this->vy;
      *(outbuffer + offset + 0) = (u_vy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vy.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vy.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vy.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vy.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vy.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vy);
      union {
        double real;
        uint64_t base;
      } u_vth;
      u_vth.real = this->vth;
      *(outbuffer + offset + 0) = (u_vth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vth.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vth.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vth.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vth.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vth.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->vth);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_vx;
      u_vx.base = 0;
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vx.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vx = u_vx.real;
      offset += sizeof(this->vx);
      union {
        double real;
        uint64_t base;
      } u_vy;
      u_vy.base = 0;
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vy.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vy = u_vy.real;
      offset += sizeof(this->vy);
      union {
        double real;
        uint64_t base;
      } u_vth;
      u_vth.base = 0;
      u_vth.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vth.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vth.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vth.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_vth.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_vth.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_vth.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_vth.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->vth = u_vth.real;
      offset += sizeof(this->vth);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GOVELOCITY; };
    const char * getMD5(){ return "14e82c5776916d6989ea54aa7b04632c"; };

  };

  class OpenHRP_AutoBalancerService_goVelocityResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_AutoBalancerService_goVelocityResponse():
      operation_return(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GOVELOCITY; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_goVelocity {
    public:
    typedef OpenHRP_AutoBalancerService_goVelocityRequest Request;
    typedef OpenHRP_AutoBalancerService_goVelocityResponse Response;
  };

}
#endif
