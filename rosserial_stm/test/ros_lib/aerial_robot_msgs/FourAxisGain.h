#ifndef _ROS_aerial_robot_msgs_FourAxisGain_h
#define _ROS_aerial_robot_msgs_FourAxisGain_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_msgs
{

  class FourAxisGain : public ros::Msg
  {
    public:
      int32_t motor_num;
      uint8_t pos_p_gain_pitch_length;
      float st_pos_p_gain_pitch;
      float * pos_p_gain_pitch;
      uint8_t pos_i_gain_pitch_length;
      float st_pos_i_gain_pitch;
      float * pos_i_gain_pitch;
      uint8_t pos_d_gain_pitch_length;
      float st_pos_d_gain_pitch;
      float * pos_d_gain_pitch;
      uint8_t pos_p_gain_roll_length;
      float st_pos_p_gain_roll;
      float * pos_p_gain_roll;
      uint8_t pos_i_gain_roll_length;
      float st_pos_i_gain_roll;
      float * pos_i_gain_roll;
      uint8_t pos_d_gain_roll_length;
      float st_pos_d_gain_roll;
      float * pos_d_gain_roll;
      uint8_t pos_p_gain_alt_length;
      float st_pos_p_gain_alt;
      float * pos_p_gain_alt;
      uint8_t pos_i_gain_alt_length;
      float st_pos_i_gain_alt;
      float * pos_i_gain_alt;
      uint8_t pos_d_gain_alt_length;
      float st_pos_d_gain_alt;
      float * pos_d_gain_alt;
      uint8_t pos_p_gain_yaw_length;
      float st_pos_p_gain_yaw;
      float * pos_p_gain_yaw;
      uint8_t pos_i_gain_yaw_length;
      float st_pos_i_gain_yaw;
      float * pos_i_gain_yaw;
      uint8_t pos_d_gain_yaw_length;
      float st_pos_d_gain_yaw;
      float * pos_d_gain_yaw;

    FourAxisGain():
      motor_num(0),
      pos_p_gain_pitch_length(0), pos_p_gain_pitch(NULL),
      pos_i_gain_pitch_length(0), pos_i_gain_pitch(NULL),
      pos_d_gain_pitch_length(0), pos_d_gain_pitch(NULL),
      pos_p_gain_roll_length(0), pos_p_gain_roll(NULL),
      pos_i_gain_roll_length(0), pos_i_gain_roll(NULL),
      pos_d_gain_roll_length(0), pos_d_gain_roll(NULL),
      pos_p_gain_alt_length(0), pos_p_gain_alt(NULL),
      pos_i_gain_alt_length(0), pos_i_gain_alt(NULL),
      pos_d_gain_alt_length(0), pos_d_gain_alt(NULL),
      pos_p_gain_yaw_length(0), pos_p_gain_yaw(NULL),
      pos_i_gain_yaw_length(0), pos_i_gain_yaw(NULL),
      pos_d_gain_yaw_length(0), pos_d_gain_yaw(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_motor_num;
      u_motor_num.real = this->motor_num;
      *(outbuffer + offset + 0) = (u_motor_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_num);
      *(outbuffer + offset++) = pos_p_gain_pitch_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_p_gain_pitch_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_p_gain_pitchi;
      u_pos_p_gain_pitchi.real = this->pos_p_gain_pitch[i];
      *(outbuffer + offset + 0) = (u_pos_p_gain_pitchi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_p_gain_pitchi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_p_gain_pitchi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_p_gain_pitchi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_p_gain_pitch[i]);
      }
      *(outbuffer + offset++) = pos_i_gain_pitch_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_i_gain_pitch_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_i_gain_pitchi;
      u_pos_i_gain_pitchi.real = this->pos_i_gain_pitch[i];
      *(outbuffer + offset + 0) = (u_pos_i_gain_pitchi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_i_gain_pitchi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_i_gain_pitchi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_i_gain_pitchi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_i_gain_pitch[i]);
      }
      *(outbuffer + offset++) = pos_d_gain_pitch_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_d_gain_pitch_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_d_gain_pitchi;
      u_pos_d_gain_pitchi.real = this->pos_d_gain_pitch[i];
      *(outbuffer + offset + 0) = (u_pos_d_gain_pitchi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_d_gain_pitchi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_d_gain_pitchi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_d_gain_pitchi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_d_gain_pitch[i]);
      }
      *(outbuffer + offset++) = pos_p_gain_roll_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_p_gain_roll_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_p_gain_rolli;
      u_pos_p_gain_rolli.real = this->pos_p_gain_roll[i];
      *(outbuffer + offset + 0) = (u_pos_p_gain_rolli.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_p_gain_rolli.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_p_gain_rolli.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_p_gain_rolli.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_p_gain_roll[i]);
      }
      *(outbuffer + offset++) = pos_i_gain_roll_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_i_gain_roll_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_i_gain_rolli;
      u_pos_i_gain_rolli.real = this->pos_i_gain_roll[i];
      *(outbuffer + offset + 0) = (u_pos_i_gain_rolli.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_i_gain_rolli.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_i_gain_rolli.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_i_gain_rolli.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_i_gain_roll[i]);
      }
      *(outbuffer + offset++) = pos_d_gain_roll_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_d_gain_roll_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_d_gain_rolli;
      u_pos_d_gain_rolli.real = this->pos_d_gain_roll[i];
      *(outbuffer + offset + 0) = (u_pos_d_gain_rolli.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_d_gain_rolli.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_d_gain_rolli.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_d_gain_rolli.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_d_gain_roll[i]);
      }
      *(outbuffer + offset++) = pos_p_gain_alt_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_p_gain_alt_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_p_gain_alti;
      u_pos_p_gain_alti.real = this->pos_p_gain_alt[i];
      *(outbuffer + offset + 0) = (u_pos_p_gain_alti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_p_gain_alti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_p_gain_alti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_p_gain_alti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_p_gain_alt[i]);
      }
      *(outbuffer + offset++) = pos_i_gain_alt_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_i_gain_alt_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_i_gain_alti;
      u_pos_i_gain_alti.real = this->pos_i_gain_alt[i];
      *(outbuffer + offset + 0) = (u_pos_i_gain_alti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_i_gain_alti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_i_gain_alti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_i_gain_alti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_i_gain_alt[i]);
      }
      *(outbuffer + offset++) = pos_d_gain_alt_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_d_gain_alt_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_d_gain_alti;
      u_pos_d_gain_alti.real = this->pos_d_gain_alt[i];
      *(outbuffer + offset + 0) = (u_pos_d_gain_alti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_d_gain_alti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_d_gain_alti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_d_gain_alti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_d_gain_alt[i]);
      }
      *(outbuffer + offset++) = pos_p_gain_yaw_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_p_gain_yaw_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_p_gain_yawi;
      u_pos_p_gain_yawi.real = this->pos_p_gain_yaw[i];
      *(outbuffer + offset + 0) = (u_pos_p_gain_yawi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_p_gain_yawi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_p_gain_yawi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_p_gain_yawi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_p_gain_yaw[i]);
      }
      *(outbuffer + offset++) = pos_i_gain_yaw_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_i_gain_yaw_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_i_gain_yawi;
      u_pos_i_gain_yawi.real = this->pos_i_gain_yaw[i];
      *(outbuffer + offset + 0) = (u_pos_i_gain_yawi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_i_gain_yawi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_i_gain_yawi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_i_gain_yawi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_i_gain_yaw[i]);
      }
      *(outbuffer + offset++) = pos_d_gain_yaw_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_d_gain_yaw_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_d_gain_yawi;
      u_pos_d_gain_yawi.real = this->pos_d_gain_yaw[i];
      *(outbuffer + offset + 0) = (u_pos_d_gain_yawi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_d_gain_yawi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_d_gain_yawi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_d_gain_yawi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_d_gain_yaw[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_motor_num;
      u_motor_num.base = 0;
      u_motor_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor_num = u_motor_num.real;
      offset += sizeof(this->motor_num);
      uint8_t pos_p_gain_pitch_lengthT = *(inbuffer + offset++);
      if(pos_p_gain_pitch_lengthT > pos_p_gain_pitch_length)
        this->pos_p_gain_pitch = (float*)realloc(this->pos_p_gain_pitch, pos_p_gain_pitch_lengthT * sizeof(float));
      offset += 3;
      pos_p_gain_pitch_length = pos_p_gain_pitch_lengthT;
      for( uint8_t i = 0; i < pos_p_gain_pitch_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_p_gain_pitch;
      u_st_pos_p_gain_pitch.base = 0;
      u_st_pos_p_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_p_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_p_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_p_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_p_gain_pitch = u_st_pos_p_gain_pitch.real;
      offset += sizeof(this->st_pos_p_gain_pitch);
        memcpy( &(this->pos_p_gain_pitch[i]), &(this->st_pos_p_gain_pitch), sizeof(float));
      }
      uint8_t pos_i_gain_pitch_lengthT = *(inbuffer + offset++);
      if(pos_i_gain_pitch_lengthT > pos_i_gain_pitch_length)
        this->pos_i_gain_pitch = (float*)realloc(this->pos_i_gain_pitch, pos_i_gain_pitch_lengthT * sizeof(float));
      offset += 3;
      pos_i_gain_pitch_length = pos_i_gain_pitch_lengthT;
      for( uint8_t i = 0; i < pos_i_gain_pitch_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_i_gain_pitch;
      u_st_pos_i_gain_pitch.base = 0;
      u_st_pos_i_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_i_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_i_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_i_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_i_gain_pitch = u_st_pos_i_gain_pitch.real;
      offset += sizeof(this->st_pos_i_gain_pitch);
        memcpy( &(this->pos_i_gain_pitch[i]), &(this->st_pos_i_gain_pitch), sizeof(float));
      }
      uint8_t pos_d_gain_pitch_lengthT = *(inbuffer + offset++);
      if(pos_d_gain_pitch_lengthT > pos_d_gain_pitch_length)
        this->pos_d_gain_pitch = (float*)realloc(this->pos_d_gain_pitch, pos_d_gain_pitch_lengthT * sizeof(float));
      offset += 3;
      pos_d_gain_pitch_length = pos_d_gain_pitch_lengthT;
      for( uint8_t i = 0; i < pos_d_gain_pitch_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_d_gain_pitch;
      u_st_pos_d_gain_pitch.base = 0;
      u_st_pos_d_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_d_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_d_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_d_gain_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_d_gain_pitch = u_st_pos_d_gain_pitch.real;
      offset += sizeof(this->st_pos_d_gain_pitch);
        memcpy( &(this->pos_d_gain_pitch[i]), &(this->st_pos_d_gain_pitch), sizeof(float));
      }
      uint8_t pos_p_gain_roll_lengthT = *(inbuffer + offset++);
      if(pos_p_gain_roll_lengthT > pos_p_gain_roll_length)
        this->pos_p_gain_roll = (float*)realloc(this->pos_p_gain_roll, pos_p_gain_roll_lengthT * sizeof(float));
      offset += 3;
      pos_p_gain_roll_length = pos_p_gain_roll_lengthT;
      for( uint8_t i = 0; i < pos_p_gain_roll_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_p_gain_roll;
      u_st_pos_p_gain_roll.base = 0;
      u_st_pos_p_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_p_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_p_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_p_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_p_gain_roll = u_st_pos_p_gain_roll.real;
      offset += sizeof(this->st_pos_p_gain_roll);
        memcpy( &(this->pos_p_gain_roll[i]), &(this->st_pos_p_gain_roll), sizeof(float));
      }
      uint8_t pos_i_gain_roll_lengthT = *(inbuffer + offset++);
      if(pos_i_gain_roll_lengthT > pos_i_gain_roll_length)
        this->pos_i_gain_roll = (float*)realloc(this->pos_i_gain_roll, pos_i_gain_roll_lengthT * sizeof(float));
      offset += 3;
      pos_i_gain_roll_length = pos_i_gain_roll_lengthT;
      for( uint8_t i = 0; i < pos_i_gain_roll_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_i_gain_roll;
      u_st_pos_i_gain_roll.base = 0;
      u_st_pos_i_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_i_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_i_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_i_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_i_gain_roll = u_st_pos_i_gain_roll.real;
      offset += sizeof(this->st_pos_i_gain_roll);
        memcpy( &(this->pos_i_gain_roll[i]), &(this->st_pos_i_gain_roll), sizeof(float));
      }
      uint8_t pos_d_gain_roll_lengthT = *(inbuffer + offset++);
      if(pos_d_gain_roll_lengthT > pos_d_gain_roll_length)
        this->pos_d_gain_roll = (float*)realloc(this->pos_d_gain_roll, pos_d_gain_roll_lengthT * sizeof(float));
      offset += 3;
      pos_d_gain_roll_length = pos_d_gain_roll_lengthT;
      for( uint8_t i = 0; i < pos_d_gain_roll_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_d_gain_roll;
      u_st_pos_d_gain_roll.base = 0;
      u_st_pos_d_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_d_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_d_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_d_gain_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_d_gain_roll = u_st_pos_d_gain_roll.real;
      offset += sizeof(this->st_pos_d_gain_roll);
        memcpy( &(this->pos_d_gain_roll[i]), &(this->st_pos_d_gain_roll), sizeof(float));
      }
      uint8_t pos_p_gain_alt_lengthT = *(inbuffer + offset++);
      if(pos_p_gain_alt_lengthT > pos_p_gain_alt_length)
        this->pos_p_gain_alt = (float*)realloc(this->pos_p_gain_alt, pos_p_gain_alt_lengthT * sizeof(float));
      offset += 3;
      pos_p_gain_alt_length = pos_p_gain_alt_lengthT;
      for( uint8_t i = 0; i < pos_p_gain_alt_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_p_gain_alt;
      u_st_pos_p_gain_alt.base = 0;
      u_st_pos_p_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_p_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_p_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_p_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_p_gain_alt = u_st_pos_p_gain_alt.real;
      offset += sizeof(this->st_pos_p_gain_alt);
        memcpy( &(this->pos_p_gain_alt[i]), &(this->st_pos_p_gain_alt), sizeof(float));
      }
      uint8_t pos_i_gain_alt_lengthT = *(inbuffer + offset++);
      if(pos_i_gain_alt_lengthT > pos_i_gain_alt_length)
        this->pos_i_gain_alt = (float*)realloc(this->pos_i_gain_alt, pos_i_gain_alt_lengthT * sizeof(float));
      offset += 3;
      pos_i_gain_alt_length = pos_i_gain_alt_lengthT;
      for( uint8_t i = 0; i < pos_i_gain_alt_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_i_gain_alt;
      u_st_pos_i_gain_alt.base = 0;
      u_st_pos_i_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_i_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_i_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_i_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_i_gain_alt = u_st_pos_i_gain_alt.real;
      offset += sizeof(this->st_pos_i_gain_alt);
        memcpy( &(this->pos_i_gain_alt[i]), &(this->st_pos_i_gain_alt), sizeof(float));
      }
      uint8_t pos_d_gain_alt_lengthT = *(inbuffer + offset++);
      if(pos_d_gain_alt_lengthT > pos_d_gain_alt_length)
        this->pos_d_gain_alt = (float*)realloc(this->pos_d_gain_alt, pos_d_gain_alt_lengthT * sizeof(float));
      offset += 3;
      pos_d_gain_alt_length = pos_d_gain_alt_lengthT;
      for( uint8_t i = 0; i < pos_d_gain_alt_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_d_gain_alt;
      u_st_pos_d_gain_alt.base = 0;
      u_st_pos_d_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_d_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_d_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_d_gain_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_d_gain_alt = u_st_pos_d_gain_alt.real;
      offset += sizeof(this->st_pos_d_gain_alt);
        memcpy( &(this->pos_d_gain_alt[i]), &(this->st_pos_d_gain_alt), sizeof(float));
      }
      uint8_t pos_p_gain_yaw_lengthT = *(inbuffer + offset++);
      if(pos_p_gain_yaw_lengthT > pos_p_gain_yaw_length)
        this->pos_p_gain_yaw = (float*)realloc(this->pos_p_gain_yaw, pos_p_gain_yaw_lengthT * sizeof(float));
      offset += 3;
      pos_p_gain_yaw_length = pos_p_gain_yaw_lengthT;
      for( uint8_t i = 0; i < pos_p_gain_yaw_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_p_gain_yaw;
      u_st_pos_p_gain_yaw.base = 0;
      u_st_pos_p_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_p_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_p_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_p_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_p_gain_yaw = u_st_pos_p_gain_yaw.real;
      offset += sizeof(this->st_pos_p_gain_yaw);
        memcpy( &(this->pos_p_gain_yaw[i]), &(this->st_pos_p_gain_yaw), sizeof(float));
      }
      uint8_t pos_i_gain_yaw_lengthT = *(inbuffer + offset++);
      if(pos_i_gain_yaw_lengthT > pos_i_gain_yaw_length)
        this->pos_i_gain_yaw = (float*)realloc(this->pos_i_gain_yaw, pos_i_gain_yaw_lengthT * sizeof(float));
      offset += 3;
      pos_i_gain_yaw_length = pos_i_gain_yaw_lengthT;
      for( uint8_t i = 0; i < pos_i_gain_yaw_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_i_gain_yaw;
      u_st_pos_i_gain_yaw.base = 0;
      u_st_pos_i_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_i_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_i_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_i_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_i_gain_yaw = u_st_pos_i_gain_yaw.real;
      offset += sizeof(this->st_pos_i_gain_yaw);
        memcpy( &(this->pos_i_gain_yaw[i]), &(this->st_pos_i_gain_yaw), sizeof(float));
      }
      uint8_t pos_d_gain_yaw_lengthT = *(inbuffer + offset++);
      if(pos_d_gain_yaw_lengthT > pos_d_gain_yaw_length)
        this->pos_d_gain_yaw = (float*)realloc(this->pos_d_gain_yaw, pos_d_gain_yaw_lengthT * sizeof(float));
      offset += 3;
      pos_d_gain_yaw_length = pos_d_gain_yaw_lengthT;
      for( uint8_t i = 0; i < pos_d_gain_yaw_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_d_gain_yaw;
      u_st_pos_d_gain_yaw.base = 0;
      u_st_pos_d_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_d_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_d_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_d_gain_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_d_gain_yaw = u_st_pos_d_gain_yaw.real;
      offset += sizeof(this->st_pos_d_gain_yaw);
        memcpy( &(this->pos_d_gain_yaw[i]), &(this->st_pos_d_gain_yaw), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/FourAxisGain"; };
    const char * getMD5(){ return "8a216c3333d3e89fce96aaf8e582ac56"; };

  };

}
#endif