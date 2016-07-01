#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_playPattern_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_playPattern_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_playPattern";

  class OpenHRP_SequencePlayerService_playPatternRequest : public ros::Msg
  {
    public:
      std_msgs::Float64MultiArray pos;
      std_msgs::Float64MultiArray rpy;
      std_msgs::Float64MultiArray zmp;
      uint8_t tm_length;
      double st_tm;
      double * tm;

    OpenHRP_SequencePlayerService_playPatternRequest():
      pos(),
      rpy(),
      zmp(),
      tm_length(0), tm(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pos.serialize(outbuffer + offset);
      offset += this->rpy.serialize(outbuffer + offset);
      offset += this->zmp.serialize(outbuffer + offset);
      *(outbuffer + offset++) = tm_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tm_length; i++){
      union {
        double real;
        uint64_t base;
      } u_tmi;
      u_tmi.real = this->tm[i];
      *(outbuffer + offset + 0) = (u_tmi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tmi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tmi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tmi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tmi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tmi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tmi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tmi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tm[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pos.deserialize(inbuffer + offset);
      offset += this->rpy.deserialize(inbuffer + offset);
      offset += this->zmp.deserialize(inbuffer + offset);
      uint8_t tm_lengthT = *(inbuffer + offset++);
      if(tm_lengthT > tm_length)
        this->tm = (double*)realloc(this->tm, tm_lengthT * sizeof(double));
      offset += 3;
      tm_length = tm_lengthT;
      for( uint8_t i = 0; i < tm_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_tm;
      u_st_tm.base = 0;
      u_st_tm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_tm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_tm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_tm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_tm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_tm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_tm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_tm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_tm = u_st_tm.real;
      offset += sizeof(this->st_tm);
        memcpy( &(this->tm[i]), &(this->st_tm), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN; };
    const char * getMD5(){ return "337f00a6e3b068d4dfdc1cc7b8dd965c"; };

  };

  class OpenHRP_SequencePlayerService_playPatternResponse : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_playPatternResponse()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_PLAYPATTERN; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_playPattern {
    public:
    typedef OpenHRP_SequencePlayerService_playPatternRequest Request;
    typedef OpenHRP_SequencePlayerService_playPatternResponse Response;
  };

}
#endif
