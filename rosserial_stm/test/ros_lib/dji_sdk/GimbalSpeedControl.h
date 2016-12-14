#ifndef _ROS_SERVICE_GimbalSpeedControl_h
#define _ROS_SERVICE_GimbalSpeedControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char GIMBALSPEEDCONTROL[] = "dji_sdk/GimbalSpeedControl";

  class GimbalSpeedControlRequest : public ros::Msg
  {
    public:
      int16_t yaw_rate;
      int16_t roll_rate;
      int16_t pitch_rate;

    GimbalSpeedControlRequest():
      yaw_rate(0),
      roll_rate(0),
      pitch_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_rate;
      u_yaw_rate.real = this->yaw_rate;
      *(outbuffer + offset + 0) = (u_yaw_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_rate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_rate);
      union {
        int16_t real;
        uint16_t base;
      } u_roll_rate;
      u_roll_rate.real = this->roll_rate;
      *(outbuffer + offset + 0) = (u_roll_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_rate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll_rate);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_rate;
      u_pitch_rate.real = this->pitch_rate;
      *(outbuffer + offset + 0) = (u_pitch_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_rate.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_rate;
      u_yaw_rate.base = 0;
      u_yaw_rate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_rate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw_rate = u_yaw_rate.real;
      offset += sizeof(this->yaw_rate);
      union {
        int16_t real;
        uint16_t base;
      } u_roll_rate;
      u_roll_rate.base = 0;
      u_roll_rate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_rate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll_rate = u_roll_rate.real;
      offset += sizeof(this->roll_rate);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_rate;
      u_pitch_rate.base = 0;
      u_pitch_rate.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_rate.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch_rate = u_pitch_rate.real;
      offset += sizeof(this->pitch_rate);
     return offset;
    }

    const char * getType(){ return GIMBALSPEEDCONTROL; };
    const char * getMD5(){ return "e7e08b9aa20908d19435cff07f74cf49"; };

  };

  class GimbalSpeedControlResponse : public ros::Msg
  {
    public:
      bool result;

    GimbalSpeedControlResponse():
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

    const char * getType(){ return GIMBALSPEEDCONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class GimbalSpeedControl {
    public:
    typedef GimbalSpeedControlRequest Request;
    typedef GimbalSpeedControlResponse Response;
  };

}
#endif
