#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_getGoPosFootstepsSequence_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_getGoPosFootstepsSequence_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footsteps.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GETGOPOSFOOTSTEPSSEQUENCE[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_getGoPosFootstepsSequence";

  class OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceRequest : public ros::Msg
  {
    public:
      double x;
      double y;
      double th;

    OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceRequest():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETGOPOSFOOTSTEPSSEQUENCE; };
    const char * getMD5(){ return "000e435776f4fd6ba555d25d7a61ed8f"; };

  };

  class OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceResponse : public ros::Msg
  {
    public:
      bool operation_return;
      uint8_t o_footstep_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps st_o_footstep;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps * o_footstep;

    OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceResponse():
      operation_return(0),
      o_footstep_length(0), o_footstep(NULL)
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
      *(outbuffer + offset++) = o_footstep_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < o_footstep_length; i++){
      offset += this->o_footstep[i].serialize(outbuffer + offset);
      }
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
      uint8_t o_footstep_lengthT = *(inbuffer + offset++);
      if(o_footstep_lengthT > o_footstep_length)
        this->o_footstep = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps*)realloc(this->o_footstep, o_footstep_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps));
      offset += 3;
      o_footstep_length = o_footstep_lengthT;
      for( uint8_t i = 0; i < o_footstep_length; i++){
      offset += this->st_o_footstep.deserialize(inbuffer + offset);
        memcpy( &(this->o_footstep[i]), &(this->st_o_footstep), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETGOPOSFOOTSTEPSSEQUENCE; };
    const char * getMD5(){ return "cc0ef1a114b5c814d73c3153a686b820"; };

  };

  class OpenHRP_AutoBalancerService_getGoPosFootstepsSequence {
    public:
    typedef OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceRequest Request;
    typedef OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceResponse Response;
  };

}
#endif
