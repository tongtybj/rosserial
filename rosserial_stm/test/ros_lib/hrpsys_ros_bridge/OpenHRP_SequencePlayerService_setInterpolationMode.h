#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setInterpolationMode_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setInterpolationMode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETINTERPOLATIONMODE[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setInterpolationMode";

  class OpenHRP_SequencePlayerService_setInterpolationModeRequest : public ros::Msg
  {
    public:
      int64_t i_mode_;

    OpenHRP_SequencePlayerService_setInterpolationModeRequest():
      i_mode_(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_i_mode_;
      u_i_mode_.real = this->i_mode_;
      *(outbuffer + offset + 0) = (u_i_mode_.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i_mode_.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i_mode_.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i_mode_.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_i_mode_.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_i_mode_.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_i_mode_.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_i_mode_.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->i_mode_);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_i_mode_;
      u_i_mode_.base = 0;
      u_i_mode_.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i_mode_.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i_mode_.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i_mode_.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_i_mode_.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_i_mode_.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_i_mode_.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_i_mode_.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->i_mode_ = u_i_mode_.real;
      offset += sizeof(this->i_mode_);
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETINTERPOLATIONMODE; };
    const char * getMD5(){ return "89ba981e2dde5f400303b5ab135813eb"; };

  };

  class OpenHRP_SequencePlayerService_setInterpolationModeResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_SequencePlayerService_setInterpolationModeResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETINTERPOLATIONMODE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setInterpolationMode {
    public:
    typedef OpenHRP_SequencePlayerService_setInterpolationModeRequest Request;
    typedef OpenHRP_SequencePlayerService_setInterpolationModeResponse Response;
  };

}
#endif
