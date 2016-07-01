#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_goPos_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_goPos_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GOPOS[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_goPos";

  class OpenHRP_AutoBalancerService_goPosRequest : public ros::Msg
  {
    public:
      double x;
      double y;
      double th;

    OpenHRP_AutoBalancerService_goPosRequest():
      x(0),
      y(0),
      th(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_th;
      u_th.real = this->th;
      *(outbuffer + offset + 0) = (u_th.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_th.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_th.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_th.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_th.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_th.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_th.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_th.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->th);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_th;
      u_th.base = 0;
      u_th.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_th.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_th.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_th.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_th.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_th.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_th.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_th.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->th = u_th.real;
      offset += sizeof(this->th);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GOPOS; };
    const char * getMD5(){ return "000e435776f4fd6ba555d25d7a61ed8f"; };

  };

  class OpenHRP_AutoBalancerService_goPosResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_AutoBalancerService_goPosResponse():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GOPOS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_goPos {
    public:
    typedef OpenHRP_AutoBalancerService_goPosRequest Request;
    typedef OpenHRP_AutoBalancerService_goPosResponse Response;
  };

}
#endif
