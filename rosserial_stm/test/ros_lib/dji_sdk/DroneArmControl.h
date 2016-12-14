#ifndef _ROS_SERVICE_DroneArmControl_h
#define _ROS_SERVICE_DroneArmControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char DRONEARMCONTROL[] = "dji_sdk/DroneArmControl";

  class DroneArmControlRequest : public ros::Msg
  {
    public:
      uint8_t arm;

    DroneArmControlRequest():
      arm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->arm >> (8 * 0)) & 0xFF;
      offset += sizeof(this->arm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->arm =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->arm);
     return offset;
    }

    const char * getType(){ return DRONEARMCONTROL; };
    const char * getMD5(){ return "e21c483c8d5b2db4fad7ea96e4e9cd5f"; };

  };

  class DroneArmControlResponse : public ros::Msg
  {
    public:
      bool result;

    DroneArmControlResponse():
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

    const char * getType(){ return DRONEARMCONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class DroneArmControl {
    public:
    typedef DroneArmControlRequest Request;
    typedef DroneArmControlResponse Response;
  };

}
#endif
