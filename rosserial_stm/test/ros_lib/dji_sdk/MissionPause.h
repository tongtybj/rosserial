#ifndef _ROS_SERVICE_MissionPause_h
#define _ROS_SERVICE_MissionPause_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char MISSIONPAUSE[] = "dji_sdk/MissionPause";

  class MissionPauseRequest : public ros::Msg
  {
    public:
      uint8_t pause;

    MissionPauseRequest():
      pause(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pause >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pause);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->pause =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pause);
     return offset;
    }

    const char * getType(){ return MISSIONPAUSE; };
    const char * getMD5(){ return "6228bf1c5f353cff5a346033e9aff938"; };

  };

  class MissionPauseResponse : public ros::Msg
  {
    public:
      bool result;

    MissionPauseResponse():
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

    const char * getType(){ return MISSIONPAUSE; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class MissionPause {
    public:
    typedef MissionPauseRequest Request;
    typedef MissionPauseResponse Response;
  };

}
#endif
