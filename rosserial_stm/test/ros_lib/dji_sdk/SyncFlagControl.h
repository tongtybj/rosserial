#ifndef _ROS_SERVICE_SyncFlagControl_h
#define _ROS_SERVICE_SyncFlagControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char SYNCFLAGCONTROL[] = "dji_sdk/SyncFlagControl";

  class SyncFlagControlRequest : public ros::Msg
  {
    public:
      uint32_t frequency;

    SyncFlagControlRequest():
      frequency(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->frequency >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frequency >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frequency >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frequency >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->frequency =  ((uint32_t) (*(inbuffer + offset)));
      this->frequency |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->frequency |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->frequency |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->frequency);
     return offset;
    }

    const char * getType(){ return SYNCFLAGCONTROL; };
    const char * getMD5(){ return "73ffa65309f649b8b694f03ce8799567"; };

  };

  class SyncFlagControlResponse : public ros::Msg
  {
    public:
      bool result;

    SyncFlagControlResponse():
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

    const char * getType(){ return SYNCFLAGCONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class SyncFlagControl {
    public:
    typedef SyncFlagControlRequest Request;
    typedef SyncFlagControlResponse Response;
  };

}
#endif
