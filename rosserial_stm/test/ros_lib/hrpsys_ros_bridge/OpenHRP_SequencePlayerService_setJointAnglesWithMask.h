#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesWithMask_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesWithMask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESWITHMASK[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setJointAnglesWithMask";

  class OpenHRP_SequencePlayerService_setJointAnglesWithMaskRequest : public ros::Msg
  {
    public:
      uint8_t jvs_length;
      double st_jvs;
      double * jvs;
      uint8_t mask_length;
      bool st_mask;
      bool * mask;
      double tm;

    OpenHRP_SequencePlayerService_setJointAnglesWithMaskRequest():
      jvs_length(0), jvs(NULL),
      mask_length(0), mask(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = jvs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < jvs_length; i++){
      union {
        double real;
        uint64_t base;
      } u_jvsi;
      u_jvsi.real = this->jvs[i];
      *(outbuffer + offset + 0) = (u_jvsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jvsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jvsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jvsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_jvsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_jvsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_jvsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_jvsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->jvs[i]);
      }
      *(outbuffer + offset++) = mask_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < mask_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_maski;
      u_maski.real = this->mask[i];
      *(outbuffer + offset + 0) = (u_maski.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mask[i]);
      }
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
      uint8_t jvs_lengthT = *(inbuffer + offset++);
      if(jvs_lengthT > jvs_length)
        this->jvs = (double*)realloc(this->jvs, jvs_lengthT * sizeof(double));
      offset += 3;
      jvs_length = jvs_lengthT;
      for( uint8_t i = 0; i < jvs_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_jvs;
      u_st_jvs.base = 0;
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_jvs = u_st_jvs.real;
      offset += sizeof(this->st_jvs);
        memcpy( &(this->jvs[i]), &(this->st_jvs), sizeof(double));
      }
      uint8_t mask_lengthT = *(inbuffer + offset++);
      if(mask_lengthT > mask_length)
        this->mask = (bool*)realloc(this->mask, mask_lengthT * sizeof(bool));
      offset += 3;
      mask_length = mask_lengthT;
      for( uint8_t i = 0; i < mask_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_mask;
      u_st_mask.base = 0;
      u_st_mask.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_mask = u_st_mask.real;
      offset += sizeof(this->st_mask);
        memcpy( &(this->mask[i]), &(this->st_mask), sizeof(bool));
      }
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESWITHMASK; };
    const char * getMD5(){ return "a788e7cc25ea1d7b0b6609203dd3c4d3"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesWithMaskResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_SequencePlayerService_setJointAnglesWithMaskResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESWITHMASK; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesWithMask {
    public:
    typedef OpenHRP_SequencePlayerService_setJointAnglesWithMaskRequest Request;
    typedef OpenHRP_SequencePlayerService_setJointAnglesWithMaskResponse Response;
  };

}
#endif
