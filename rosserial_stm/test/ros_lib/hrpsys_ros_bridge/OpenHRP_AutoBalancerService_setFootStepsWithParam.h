#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_setFootStepsWithParam_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_setFootStepsWithParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footsteps.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_StepParams.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPSWITHPARAM[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_setFootStepsWithParam";

  class OpenHRP_AutoBalancerService_setFootStepsWithParamRequest : public ros::Msg
  {
    public:
      uint8_t fss_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps st_fss;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps * fss;
      uint8_t spss_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParams st_spss;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParams * spss;
      int32_t overwrite_fs_idx;

    OpenHRP_AutoBalancerService_setFootStepsWithParamRequest():
      fss_length(0), fss(NULL),
      spss_length(0), spss(NULL),
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
      *(outbuffer + offset++) = spss_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < spss_length; i++){
      offset += this->spss[i].serialize(outbuffer + offset);
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
      uint8_t spss_lengthT = *(inbuffer + offset++);
      if(spss_lengthT > spss_length)
        this->spss = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParams*)realloc(this->spss, spss_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParams));
      offset += 3;
      spss_length = spss_lengthT;
      for( uint8_t i = 0; i < spss_length; i++){
      offset += this->st_spss.deserialize(inbuffer + offset);
        memcpy( &(this->spss[i]), &(this->st_spss), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_StepParams));
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPSWITHPARAM; };
    const char * getMD5(){ return "fa8a78c7e782f767eaa39a6ab67b7fd5"; };

  };

  class OpenHRP_AutoBalancerService_setFootStepsWithParamResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_AutoBalancerService_setFootStepsWithParamResponse():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_SETFOOTSTEPSWITHPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_setFootStepsWithParam {
    public:
    typedef OpenHRP_AutoBalancerService_setFootStepsWithParamRequest Request;
    typedef OpenHRP_AutoBalancerService_setFootStepsWithParamResponse Response;
  };

}
#endif
