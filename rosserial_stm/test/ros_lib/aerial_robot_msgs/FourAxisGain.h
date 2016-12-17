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
      uint8_t pos_p_gain_throttle_length;
      float st_pos_p_gain_throttle;
      float * pos_p_gain_throttle;
      uint8_t pos_i_gain_throttle_length;
      float st_pos_i_gain_throttle;
      float * pos_i_gain_throttle;
      uint8_t pos_d_gain_throttle_length;
      float st_pos_d_gain_throttle;
      float * pos_d_gain_throttle;
      uint8_t pos_p_gain_yaw_length;
      float st_pos_p_gain_yaw;
      float * pos_p_gain_yaw;
      uint8_t pos_i_gain_yaw_length;
      float st_pos_i_gain_yaw;
      float * pos_i_gain_yaw;
      uint8_t pos_d_gain_yaw_length;
      float st_pos_d_gain_yaw;
      float * pos_d_gain_yaw;
      uint8_t ff_roll_vec_length;
      float st_ff_roll_vec;
      float * ff_roll_vec;
      uint8_t ff_pitch_vec_length;
      float st_ff_pitch_vec;
      float * ff_pitch_vec;
      uint8_t ff_yaw_vec_length;
      float st_ff_yaw_vec;
      float * ff_yaw_vec;

    FourAxisGain():
      motor_num(0),
      pos_p_gain_pitch_length(0), pos_p_gain_pitch(NULL),
      pos_i_gain_pitch_length(0), pos_i_gain_pitch(NULL),
      pos_d_gain_pitch_length(0), pos_d_gain_pitch(NULL),
      pos_p_gain_roll_length(0), pos_p_gain_roll(NULL),
      pos_i_gain_roll_length(0), pos_i_gain_roll(NULL),
      pos_d_gain_roll_length(0), pos_d_gain_roll(NULL),
      pos_p_gain_throttle_length(0), pos_p_gain_throttle(NULL),
      pos_i_gain_throttle_length(0), pos_i_gain_throttle(NULL),
      pos_d_gain_throttle_length(0), pos_d_gain_throttle(NULL),
      pos_p_gain_yaw_length(0), pos_p_gain_yaw(NULL),
      pos_i_gain_yaw_length(0), pos_i_gain_yaw(NULL),
      pos_d_gain_yaw_length(0), pos_d_gain_yaw(NULL),
      ff_roll_vec_length(0), ff_roll_vec(NULL),
      ff_pitch_vec_length(0), ff_pitch_vec(NULL),
      ff_yaw_vec_length(0), ff_yaw_vec(NULL)
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
      *(outbuffer + offset++) = pos_p_gain_throttle_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_p_gain_throttle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_p_gain_throttlei;
      u_pos_p_gain_throttlei.real = this->pos_p_gain_throttle[i];
      *(outbuffer + offset + 0) = (u_pos_p_gain_throttlei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_p_gain_throttlei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_p_gain_throttlei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_p_gain_throttlei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_p_gain_throttle[i]);
      }
      *(outbuffer + offset++) = pos_i_gain_throttle_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_i_gain_throttle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_i_gain_throttlei;
      u_pos_i_gain_throttlei.real = this->pos_i_gain_throttle[i];
      *(outbuffer + offset + 0) = (u_pos_i_gain_throttlei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_i_gain_throttlei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_i_gain_throttlei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_i_gain_throttlei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_i_gain_throttle[i]);
      }
      *(outbuffer + offset++) = pos_d_gain_throttle_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pos_d_gain_throttle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_pos_d_gain_throttlei;
      u_pos_d_gain_throttlei.real = this->pos_d_gain_throttle[i];
      *(outbuffer + offset + 0) = (u_pos_d_gain_throttlei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_d_gain_throttlei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_d_gain_throttlei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_d_gain_throttlei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos_d_gain_throttle[i]);
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
      *(outbuffer + offset++) = ff_roll_vec_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ff_roll_vec_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ff_roll_veci;
      u_ff_roll_veci.real = this->ff_roll_vec[i];
      *(outbuffer + offset + 0) = (u_ff_roll_veci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ff_roll_veci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ff_roll_veci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ff_roll_veci.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ff_roll_vec[i]);
      }
      *(outbuffer + offset++) = ff_pitch_vec_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ff_pitch_vec_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ff_pitch_veci;
      u_ff_pitch_veci.real = this->ff_pitch_vec[i];
      *(outbuffer + offset + 0) = (u_ff_pitch_veci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ff_pitch_veci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ff_pitch_veci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ff_pitch_veci.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ff_pitch_vec[i]);
      }
      *(outbuffer + offset++) = ff_yaw_vec_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ff_yaw_vec_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ff_yaw_veci;
      u_ff_yaw_veci.real = this->ff_yaw_vec[i];
      *(outbuffer + offset + 0) = (u_ff_yaw_veci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ff_yaw_veci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ff_yaw_veci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ff_yaw_veci.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ff_yaw_vec[i]);
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
      uint8_t pos_p_gain_throttle_lengthT = *(inbuffer + offset++);
      if(pos_p_gain_throttle_lengthT > pos_p_gain_throttle_length)
        this->pos_p_gain_throttle = (float*)realloc(this->pos_p_gain_throttle, pos_p_gain_throttle_lengthT * sizeof(float));
      offset += 3;
      pos_p_gain_throttle_length = pos_p_gain_throttle_lengthT;
      for( uint8_t i = 0; i < pos_p_gain_throttle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_p_gain_throttle;
      u_st_pos_p_gain_throttle.base = 0;
      u_st_pos_p_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_p_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_p_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_p_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_p_gain_throttle = u_st_pos_p_gain_throttle.real;
      offset += sizeof(this->st_pos_p_gain_throttle);
        memcpy( &(this->pos_p_gain_throttle[i]), &(this->st_pos_p_gain_throttle), sizeof(float));
      }
      uint8_t pos_i_gain_throttle_lengthT = *(inbuffer + offset++);
      if(pos_i_gain_throttle_lengthT > pos_i_gain_throttle_length)
        this->pos_i_gain_throttle = (float*)realloc(this->pos_i_gain_throttle, pos_i_gain_throttle_lengthT * sizeof(float));
      offset += 3;
      pos_i_gain_throttle_length = pos_i_gain_throttle_lengthT;
      for( uint8_t i = 0; i < pos_i_gain_throttle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_i_gain_throttle;
      u_st_pos_i_gain_throttle.base = 0;
      u_st_pos_i_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_i_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_i_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_i_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_i_gain_throttle = u_st_pos_i_gain_throttle.real;
      offset += sizeof(this->st_pos_i_gain_throttle);
        memcpy( &(this->pos_i_gain_throttle[i]), &(this->st_pos_i_gain_throttle), sizeof(float));
      }
      uint8_t pos_d_gain_throttle_lengthT = *(inbuffer + offset++);
      if(pos_d_gain_throttle_lengthT > pos_d_gain_throttle_length)
        this->pos_d_gain_throttle = (float*)realloc(this->pos_d_gain_throttle, pos_d_gain_throttle_lengthT * sizeof(float));
      offset += 3;
      pos_d_gain_throttle_length = pos_d_gain_throttle_lengthT;
      for( uint8_t i = 0; i < pos_d_gain_throttle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_pos_d_gain_throttle;
      u_st_pos_d_gain_throttle.base = 0;
      u_st_pos_d_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_pos_d_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_pos_d_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_pos_d_gain_throttle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_pos_d_gain_throttle = u_st_pos_d_gain_throttle.real;
      offset += sizeof(this->st_pos_d_gain_throttle);
        memcpy( &(this->pos_d_gain_throttle[i]), &(this->st_pos_d_gain_throttle), sizeof(float));
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
      uint8_t ff_roll_vec_lengthT = *(inbuffer + offset++);
      if(ff_roll_vec_lengthT > ff_roll_vec_length)
        this->ff_roll_vec = (float*)realloc(this->ff_roll_vec, ff_roll_vec_lengthT * sizeof(float));
      offset += 3;
      ff_roll_vec_length = ff_roll_vec_lengthT;
      for( uint8_t i = 0; i < ff_roll_vec_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_ff_roll_vec;
      u_st_ff_roll_vec.base = 0;
      u_st_ff_roll_vec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ff_roll_vec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ff_roll_vec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ff_roll_vec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ff_roll_vec = u_st_ff_roll_vec.real;
      offset += sizeof(this->st_ff_roll_vec);
        memcpy( &(this->ff_roll_vec[i]), &(this->st_ff_roll_vec), sizeof(float));
      }
      uint8_t ff_pitch_vec_lengthT = *(inbuffer + offset++);
      if(ff_pitch_vec_lengthT > ff_pitch_vec_length)
        this->ff_pitch_vec = (float*)realloc(this->ff_pitch_vec, ff_pitch_vec_lengthT * sizeof(float));
      offset += 3;
      ff_pitch_vec_length = ff_pitch_vec_lengthT;
      for( uint8_t i = 0; i < ff_pitch_vec_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_ff_pitch_vec;
      u_st_ff_pitch_vec.base = 0;
      u_st_ff_pitch_vec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ff_pitch_vec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ff_pitch_vec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ff_pitch_vec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ff_pitch_vec = u_st_ff_pitch_vec.real;
      offset += sizeof(this->st_ff_pitch_vec);
        memcpy( &(this->ff_pitch_vec[i]), &(this->st_ff_pitch_vec), sizeof(float));
      }
      uint8_t ff_yaw_vec_lengthT = *(inbuffer + offset++);
      if(ff_yaw_vec_lengthT > ff_yaw_vec_length)
        this->ff_yaw_vec = (float*)realloc(this->ff_yaw_vec, ff_yaw_vec_lengthT * sizeof(float));
      offset += 3;
      ff_yaw_vec_length = ff_yaw_vec_lengthT;
      for( uint8_t i = 0; i < ff_yaw_vec_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_ff_yaw_vec;
      u_st_ff_yaw_vec.base = 0;
      u_st_ff_yaw_vec.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ff_yaw_vec.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ff_yaw_vec.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ff_yaw_vec.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ff_yaw_vec = u_st_ff_yaw_vec.real;
      offset += sizeof(this->st_ff_yaw_vec);
        memcpy( &(this->ff_yaw_vec[i]), &(this->st_ff_yaw_vec), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/FourAxisGain"; };
    const char * getMD5(){ return "1840ea4d1ee99a7e1da84e5d4d4c1ba6"; };

  };

}
#endif