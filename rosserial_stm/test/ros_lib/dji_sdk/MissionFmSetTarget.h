#ifndef _ROS_SERVICE_MissionFmSetTarget_h
#define _ROS_SERVICE_MissionFmSetTarget_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/MissionFollowmeTarget.h"

namespace dji_sdk
{

static const char MISSIONFMSETTARGET[] = "dji_sdk/MissionFmSetTarget";

  class MissionFmSetTargetRequest : public ros::Msg
  {
    public:
      dji_sdk::MissionFollowmeTarget followme_target;

    MissionFmSetTargetRequest():
      followme_target()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->followme_target.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->followme_target.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MISSIONFMSETTARGET; };
    const char * getMD5(){ return "186e8eaac8caf1c8852b2a15c50454d5"; };

  };

  class MissionFmSetTargetResponse : public ros::Msg
  {
    public:
      bool result;

    MissionFmSetTargetResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return MISSIONFMSETTARGET; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class MissionFmSetTarget {
    public:
    typedef MissionFmSetTargetRequest Request;
    typedef MissionFmSetTargetResponse Response;
  };

}
#endif
