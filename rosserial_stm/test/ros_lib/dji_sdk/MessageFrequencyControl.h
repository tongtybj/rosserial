#ifndef _ROS_SERVICE_MessageFrequencyControl_h
#define _ROS_SERVICE_MessageFrequencyControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char MESSAGEFREQUENCYCONTROL[] = "dji_sdk/MessageFrequencyControl";

  class MessageFrequencyControlRequest : public ros::Msg
  {
    public:
      uint8_t frequency[16];

    MessageFrequencyControlRequest():
      frequency()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      *(outbuffer + offset + 0) = (this->frequency[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->frequency[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      this->frequency[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->frequency[i]);
      }
     return offset;
    }

    const char * getType(){ return MESSAGEFREQUENCYCONTROL; };
    const char * getMD5(){ return "6f27a0697a2efd8da664f239ba301c7c"; };

  };

  class MessageFrequencyControlResponse : public ros::Msg
  {
    public:
      bool result;

    MessageFrequencyControlResponse():
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

    const char * getType(){ return MESSAGEFREQUENCYCONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class MessageFrequencyControl {
    public:
    typedef MessageFrequencyControlRequest Request;
    typedef MessageFrequencyControlResponse Response;
  };

}
#endif
