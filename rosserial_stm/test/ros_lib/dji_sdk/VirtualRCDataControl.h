#ifndef _ROS_SERVICE_VirtualRCDataControl_h
#define _ROS_SERVICE_VirtualRCDataControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char VIRTUALRCDATACONTROL[] = "dji_sdk/VirtualRCDataControl";

  class VirtualRCDataControlRequest : public ros::Msg
  {
    public:
      uint32_t channel_data[16];

    VirtualRCDataControlRequest():
      channel_data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      *(outbuffer + offset + 0) = (this->channel_data[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channel_data[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channel_data[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channel_data[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channel_data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      this->channel_data[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->channel_data[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->channel_data[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->channel_data[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->channel_data[i]);
      }
     return offset;
    }

    const char * getType(){ return VIRTUALRCDATACONTROL; };
    const char * getMD5(){ return "a5dc9e9c055cbd8bb34a920ab9e508c6"; };

  };

  class VirtualRCDataControlResponse : public ros::Msg
  {
    public:
      bool result;

    VirtualRCDataControlResponse():
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

    const char * getType(){ return VIRTUALRCDATACONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class VirtualRCDataControl {
    public:
    typedef VirtualRCDataControlRequest Request;
    typedef VirtualRCDataControlResponse Response;
  };

}
#endif
