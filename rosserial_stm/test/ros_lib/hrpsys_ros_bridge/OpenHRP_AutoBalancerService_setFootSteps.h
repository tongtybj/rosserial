#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_setFootSteps_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_setFootSteps_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footsteps.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPS[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_setFootSteps";

  class OpenHRP_AutoBalancerService_setFootStepsRequest : public ros::Msg
  {
    public:
      uint8_t fss_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps st_fss;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps * fss;
      int32_t overwrite_fs_idx;

    OpenHRP_AutoBalancerService_setFootStepsRequest():
      fss_length(0), fss(NULL),
      overwrite_fs_idx(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = fss_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fss_length; i++){
      offset += this->fss[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_overwrite_fs_idx;
      u_overwrite_fs_idx.real = this->overwrite_fs_idx;
      *(outbuffer + offset + 0) = (u_overwrite_fs_idx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_overwrite_fs_idx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_overwrite_fs_idx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_overwrite_fs_idx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->overwrite_fs_idx);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t fss_lengthT = *(inbuffer + offset++);
      if(fss_lengthT > fss_length)
        this->fss = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps*)realloc(this->fss, fss_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps));
      offset += 3;
      fss_length = fss_lengthT;
      for( uint8_t i = 0; i < fss_length; i++){
      offset += this->st_fss.deserialize(inbuffer + offset);
        memcpy( &(this->fss[i]), &(this->st_fss), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_overwrite_fs_idx;
      u_overwrite_fs_idx.base = 0;
      u_overwrite_fs_idx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_overwrite_fs_idx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_overwrite_fs_idx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_overwrite_fs_idx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->overwrite_fs_idx = u_overwrite_fs_idx.real;
      offset += sizeof(this->overwrite_fs_idx);
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPS; };
    const char * getMD5(){ return "74b040b32c92a8357016dae74c7384e4"; };

  };

  class OpenHRP_AutoBalancerService_setFootStepsResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_AutoBalancerService_setFootStepsResponse():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_setFootSteps {
    public:
    typedef OpenHRP_AutoBalancerService_setFootStepsRequest Request;
    typedef OpenHRP_AutoBalancerService_setFootStepsResponse Response;
  };

}
#endif
