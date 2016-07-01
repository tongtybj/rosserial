#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_getRemainingFootstepSequence_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_getRemainingFootstepSequence_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GETREMAININGFOOTSTEPSEQUENCE[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_getRemainingFootstepSequence";

  class OpenHRP_AutoBalancerService_getRemainingFootstepSequenceRequest : public ros::Msg
  {
    public:

    OpenHRP_AutoBalancerService_getRemainingFootstepSequenceRequest()
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETREMAININGFOOTSTEPSEQUENCE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_AutoBalancerService_getRemainingFootstepSequenceResponse : public ros::Msg
  {
    public:
      bool operation_return;
      uint8_t o_footstep_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep st_o_footstep;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep * o_footstep;
      int32_t o_current_fs_idx;

    OpenHRP_AutoBalancerService_getRemainingFootstepSequenceResponse():
      operation_return(0),
      o_footstep_length(0), o_footstep(NULL),
      o_current_fs_idx(0)
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
      union {
        int32_t real;
        uint32_t base;
      } u_o_current_fs_idx;
      u_o_current_fs_idx.real = this->o_current_fs_idx;
      *(outbuffer + offset + 0) = (u_o_current_fs_idx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_o_current_fs_idx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_o_current_fs_idx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_o_current_fs_idx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->o_current_fs_idx);
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
        this->o_footstep = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep*)realloc(this->o_footstep, o_footstep_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      offset += 3;
      o_footstep_length = o_footstep_lengthT;
      for( uint8_t i = 0; i < o_footstep_length; i++){
      offset += this->st_o_footstep.deserialize(inbuffer + offset);
        memcpy( &(this->o_footstep[i]), &(this->st_o_footstep), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_o_current_fs_idx;
      u_o_current_fs_idx.base = 0;
      u_o_current_fs_idx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_o_current_fs_idx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_o_current_fs_idx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_o_current_fs_idx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->o_current_fs_idx = u_o_current_fs_idx.real;
      offset += sizeof(this->o_current_fs_idx);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETREMAININGFOOTSTEPSEQUENCE; };
    const char * getMD5(){ return "bf5be86b3e8b6132f58c78d4fb676340"; };

  };

  class OpenHRP_AutoBalancerService_getRemainingFootstepSequence {
    public:
    typedef OpenHRP_AutoBalancerService_getRemainingFootstepSequenceRequest Request;
    typedef OpenHRP_AutoBalancerService_getRemainingFootstepSequenceResponse Response;
  };

}
#endif
