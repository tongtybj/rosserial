#ifndef _ROS_SERVICE_GimbalAngleControl_h
#define _ROS_SERVICE_GimbalAngleControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char GIMBALANGLECONTROL[] = "dji_sdk/GimbalAngleControl";

  class GimbalAngleControlRequest : public ros::Msg
  {
    public:
      int16_t yaw;
      int16_t roll;
      int16_t pitch;
      int16_t duration;
      bool absolute_or_incremental;
      bool yaw_cmd_ignore;
      bool roll_cmd_ignore;
      bool pitch_cmd_ignore;

    GimbalAngleControlRequest():
      yaw(0),
      roll(0),
      pitch(0),
      duration(0),
      absolute_or_incremental(0),
      yaw_cmd_ignore(0),
      roll_cmd_ignore(0),
      pitch_cmd_ignore(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_duration;
      u_duration.real = this->duration;
      *(outbuffer + offset + 0) = (u_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duration.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->duration);
      union {
        bool real;
        uint8_t base;
      } u_absolute_or_incremental;
      u_absolute_or_incremental.real = this->absolute_or_incremental;
      *(outbuffer + offset + 0) = (u_absolute_or_incremental.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->absolute_or_incremental);
      union {
        bool real;
        uint8_t base;
      } u_yaw_cmd_ignore;
      u_yaw_cmd_ignore.real = this->yaw_cmd_ignore;
      *(outbuffer + offset + 0) = (u_yaw_cmd_ignore.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yaw_cmd_ignore);
      union {
        bool real;
        uint8_t base;
      } u_roll_cmd_ignore;
      u_roll_cmd_ignore.real = this->roll_cmd_ignore;
      *(outbuffer + offset + 0) = (u_roll_cmd_ignore.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->roll_cmd_ignore);
      union {
        bool real;
        uint8_t base;
      } u_pitch_cmd_ignore;
      u_pitch_cmd_ignore.real = this->pitch_cmd_ignore;
      *(outbuffer + offset + 0) = (u_pitch_cmd_ignore.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pitch_cmd_ignore);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        int16_t real;
        uint16_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        int16_t real;
        uint16_t base;
      } u_duration;
      u_duration.base = 0;
      u_duration.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duration.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration = u_duration.real;
      offset += sizeof(this->duration);
      union {
        bool real;
        uint8_t base;
      } u_absolute_or_incremental;
      u_absolute_or_incremental.base = 0;
      u_absolute_or_incremental.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->absolute_or_incremental = u_absolute_or_incremental.real;
      offset += sizeof(this->absolute_or_incremental);
      union {
        bool real;
        uint8_t base;
      } u_yaw_cmd_ignore;
      u_yaw_cmd_ignore.base = 0;
      u_yaw_cmd_ignore.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->yaw_cmd_ignore = u_yaw_cmd_ignore.real;
      offset += sizeof(this->yaw_cmd_ignore);
      union {
        bool real;
        uint8_t base;
      } u_roll_cmd_ignore;
      u_roll_cmd_ignore.base = 0;
      u_roll_cmd_ignore.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->roll_cmd_ignore = u_roll_cmd_ignore.real;
      offset += sizeof(this->roll_cmd_ignore);
      union {
        bool real;
        uint8_t base;
      } u_pitch_cmd_ignore;
      u_pitch_cmd_ignore.base = 0;
      u_pitch_cmd_ignore.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pitch_cmd_ignore = u_pitch_cmd_ignore.real;
      offset += sizeof(this->pitch_cmd_ignore);
     return offset;
    }

    const char * getType(){ return GIMBALANGLECONTROL; };
    const char * getMD5(){ return "3ada515ce6b45dc1f09c576bfab01d4a"; };

  };

  class GimbalAngleControlResponse : public ros::Msg
  {
    public:
      bool result;

    GimbalAngleControlResponse():
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

    const char * getType(){ return GIMBALANGLECONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class GimbalAngleControl {
    public:
    typedef GimbalAngleControlRequest Request;
    typedef GimbalAngleControlResponse Response;
  };

}
#endif
