#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setWrenches_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setWrenches_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setWrenches";

  class OpenHRP_SequencePlayerService_setWrenchesRequest : public ros::Msg
  {
    public:
      uint8_t wrenches_length;
      double st_wrenches;
      double * wrenches;
      double tm;

    OpenHRP_SequencePlayerService_setWrenchesRequest():
      wrenches_length(0), wrenches(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = wrenches_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < wrenches_length; i++){
      union {
        double real;
        uint64_t base;
      } u_wrenchesi;
      u_wrenchesi.real = this->wrenches[i];
      *(outbuffer + offset + 0) = (u_wrenchesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wrenchesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wrenchesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wrenchesi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_wrenchesi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_wrenchesi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_wrenchesi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_wrenchesi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->wrenches[i]);
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
      uint8_t wrenches_lengthT = *(inbuffer + offset++);
      if(wrenches_lengthT > wrenches_length)
        this->wrenches = (double*)realloc(this->wrenches, wrenches_lengthT * sizeof(double));
      offset += 3;
      wrenches_length = wrenches_lengthT;
      for( uint8_t i = 0; i < wrenches_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_wrenches;
      u_st_wrenches.base = 0;
      u_st_wrenches.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_wrenches.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_wrenches.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_wrenches.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_wrenches.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_wrenches.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_wrenches.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_wrenches.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_wrenches = u_st_wrenches.real;
      offset += sizeof(this->st_wrenches);
        memcpy( &(this->wrenches[i]), &(this->st_wrenches), sizeof(double));
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES; };
    const char * getMD5(){ return "8278cb0b6641cad755b5b691fb73ac22"; };

  };

  class OpenHRP_SequencePlayerService_setWrenchesResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_SequencePlayerService_setWrenchesResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETWRENCHES; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setWrenches {
    public:
    typedef OpenHRP_SequencePlayerService_setWrenchesRequest Request;
    typedef OpenHRP_SequencePlayerService_setWrenchesResponse Response;
  };

}
#endif
