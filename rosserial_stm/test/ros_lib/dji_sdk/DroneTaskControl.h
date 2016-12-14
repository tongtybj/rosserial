#ifndef _ROS_SERVICE_DroneTaskControl_h
#define _ROS_SERVICE_DroneTaskControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char DRONETASKCONTROL[] = "dji_sdk/DroneTaskControl";

  class DroneTaskControlRequest : public ros::Msg
  {
    public:
      uint8_t task;

    DroneTaskControlRequest():
      task(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->task >> (8 * 0)) & 0xFF;
      offset += sizeof(this->task);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->task =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->task);
     return offset;
    }

    const char * getType(){ return DRONETASKCONTROL; };
    const char * getMD5(){ return "cfae433ef22bd8313f92bc5cad00c264"; };

  };

  class DroneTaskControlResponse : public ros::Msg
  {
    public:
      bool result;

    DroneTaskControlResponse():
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

    const char * getType(){ return DRONETASKCONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class DroneTaskControl {
    public:
    typedef DroneTaskControlRequest Request;
    typedef DroneTaskControlResponse Response;
  };

}
#endif
