#ifndef _ROS_leap_motion_leap_h
#define _ROS_leap_motion_leap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace leap_motion
{

  class leap : public ros::Msg
  {
    public:
      std_msgs::Header header;
      double hand_direction[3];
      double hand_normal[3];
      double hand_palm_pos[3];
      double hand_pitch;
      double hand_roll;
      double hand_yaw;

    leap():
      header(),
      hand_direction(),
      hand_normal(),
      hand_palm_pos(),
      hand_pitch(0),
      hand_roll(0),
      hand_yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_hand_directioni;
      u_hand_directioni.real = this->hand_direction[i];
      *(outbuffer + offset + 0) = (u_hand_directioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_directioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_directioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_directioni.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hand_directioni.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hand_directioni.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hand_directioni.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hand_directioni.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hand_direction[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_hand_normali;
      u_hand_normali.real = this->hand_normal[i];
      *(outbuffer + offset + 0) = (u_hand_normali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_normali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_normali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_normali.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hand_normali.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hand_normali.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hand_normali.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hand_normali.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hand_normal[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_hand_palm_posi;
      u_hand_palm_posi.real = this->hand_palm_pos[i];
      *(outbuffer + offset + 0) = (u_hand_palm_posi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_palm_posi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_palm_posi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_palm_posi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hand_palm_posi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hand_palm_posi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hand_palm_posi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hand_palm_posi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hand_palm_pos[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_hand_pitch;
      u_hand_pitch.real = this->hand_pitch;
      *(outbuffer + offset + 0) = (u_hand_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_pitch.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hand_pitch.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hand_pitch.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hand_pitch.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hand_pitch.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hand_pitch);
      union {
        double real;
        uint64_t base;
      } u_hand_roll;
      u_hand_roll.real = this->hand_roll;
      *(outbuffer + offset + 0) = (u_hand_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_roll.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hand_roll.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hand_roll.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hand_roll.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hand_roll.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hand_roll);
      union {
        double real;
        uint64_t base;
      } u_hand_yaw;
      u_hand_yaw.real = this->hand_yaw;
      *(outbuffer + offset + 0) = (u_hand_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hand_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hand_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hand_yaw.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hand_yaw.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hand_yaw.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hand_yaw.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hand_yaw.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hand_yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_hand_directioni;
      u_hand_directioni.base = 0;
      u_hand_directioni.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_directioni.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_directioni.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_directioni.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hand_directioni.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hand_directioni.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hand_directioni.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hand_directioni.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hand_direction[i] = u_hand_directioni.real;
      offset += sizeof(this->hand_direction[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_hand_normali;
      u_hand_normali.base = 0;
      u_hand_normali.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_normali.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_normali.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_normali.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hand_normali.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hand_normali.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hand_normali.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hand_normali.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hand_normal[i] = u_hand_normali.real;
      offset += sizeof(this->hand_normal[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_hand_palm_posi;
      u_hand_palm_posi.base = 0;
      u_hand_palm_posi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_palm_posi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_palm_posi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_palm_posi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hand_palm_posi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hand_palm_posi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hand_palm_posi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hand_palm_posi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hand_palm_pos[i] = u_hand_palm_posi.real;
      offset += sizeof(this->hand_palm_pos[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_hand_pitch;
      u_hand_pitch.base = 0;
      u_hand_pitch.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_pitch.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_pitch.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_pitch.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hand_pitch.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hand_pitch.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hand_pitch.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hand_pitch.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hand_pitch = u_hand_pitch.real;
      offset += sizeof(this->hand_pitch);
      union {
        double real;
        uint64_t base;
      } u_hand_roll;
      u_hand_roll.base = 0;
      u_hand_roll.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_roll.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_roll.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_roll.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hand_roll.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hand_roll.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hand_roll.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hand_roll.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hand_roll = u_hand_roll.real;
      offset += sizeof(this->hand_roll);
      union {
        double real;
        uint64_t base;
      } u_hand_yaw;
      u_hand_yaw.base = 0;
      u_hand_yaw.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hand_yaw.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hand_yaw.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hand_yaw.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hand_yaw.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hand_yaw.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hand_yaw.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hand_yaw.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hand_yaw = u_hand_yaw.real;
      offset += sizeof(this->hand_yaw);
     return offset;
    }

    const char * getType(){ return "leap_motion/leap"; };
    const char * getMD5(){ return "3e9a0dc7fd1a98f1d7489e9011c78807"; };

  };

}
#endif