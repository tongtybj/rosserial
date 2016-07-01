#ifndef _ROS_jsk_footstep_controller_GroundContactState_h
#define _ROS_jsk_footstep_controller_GroundContactState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_footstep_controller
{

  class GroundContactState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t contact_state;
      double error_pitch_angle;
      double error_roll_angle;
      double error_yaw_angle;
      double error_z;
      enum { CONTACT_BOTH_GROUND = 1 };
      enum { CONTACT_AIR = 2 };
      enum { CONTACT_LLEG_GROUND = 3 };
      enum { CONTACT_RLEG_GROUND = 4 };
      enum { CONTACT_UNSTABLE = 5 };

    GroundContactState():
      header(),
      contact_state(0),
      error_pitch_angle(0),
      error_roll_angle(0),
      error_yaw_angle(0),
      error_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contact_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact_state);
      union {
        double real;
        uint64_t base;
      } u_error_pitch_angle;
      u_error_pitch_angle.real = this->error_pitch_angle;
      *(outbuffer + offset + 0) = (u_error_pitch_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_pitch_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_pitch_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_pitch_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_error_pitch_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_error_pitch_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_error_pitch_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_error_pitch_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->error_pitch_angle);
      union {
        double real;
        uint64_t base;
      } u_error_roll_angle;
      u_error_roll_angle.real = this->error_roll_angle;
      *(outbuffer + offset + 0) = (u_error_roll_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_roll_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_roll_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_roll_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_error_roll_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_error_roll_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_error_roll_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_error_roll_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->error_roll_angle);
      union {
        double real;
        uint64_t base;
      } u_error_yaw_angle;
      u_error_yaw_angle.real = this->error_yaw_angle;
      *(outbuffer + offset + 0) = (u_error_yaw_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_yaw_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_yaw_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_yaw_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_error_yaw_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_error_yaw_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_error_yaw_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_error_yaw_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->error_yaw_angle);
      union {
        double real;
        uint64_t base;
      } u_error_z;
      u_error_z.real = this->error_z;
      *(outbuffer + offset + 0) = (u_error_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_error_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_error_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_error_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_error_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->error_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->contact_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->contact_state);
      union {
        double real;
        uint64_t base;
      } u_error_pitch_angle;
      u_error_pitch_angle.base = 0;
      u_error_pitch_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_pitch_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_pitch_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_pitch_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_error_pitch_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_error_pitch_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_error_pitch_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_error_pitch_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->error_pitch_angle = u_error_pitch_angle.real;
      offset += sizeof(this->error_pitch_angle);
      union {
        double real;
        uint64_t base;
      } u_error_roll_angle;
      u_error_roll_angle.base = 0;
      u_error_roll_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_roll_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_roll_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_roll_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_error_roll_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_error_roll_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_error_roll_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_error_roll_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->error_roll_angle = u_error_roll_angle.real;
      offset += sizeof(this->error_roll_angle);
      union {
        double real;
        uint64_t base;
      } u_error_yaw_angle;
      u_error_yaw_angle.base = 0;
      u_error_yaw_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_yaw_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_yaw_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_yaw_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_error_yaw_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_error_yaw_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_error_yaw_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_error_yaw_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->error_yaw_angle = u_error_yaw_angle.real;
      offset += sizeof(this->error_yaw_angle);
      union {
        double real;
        uint64_t base;
      } u_error_z;
      u_error_z.base = 0;
      u_error_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_error_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_error_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_error_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_error_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->error_z = u_error_z.real;
      offset += sizeof(this->error_z);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_controller/GroundContactState"; };
    const char * getMD5(){ return "da0f3906e0a6eafe324ba582440493ea"; };

  };

}
#endif