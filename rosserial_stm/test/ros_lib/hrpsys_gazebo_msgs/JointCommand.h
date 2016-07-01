#ifndef _ROS_hrpsys_gazebo_msgs_JointCommand_h
#define _ROS_hrpsys_gazebo_msgs_JointCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace hrpsys_gazebo_msgs
{

  class JointCommand : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t position_length;
      double st_position;
      double * position;
      uint8_t velocity_length;
      double st_velocity;
      double * velocity;
      uint8_t effort_length;
      double st_effort;
      double * effort;
      uint8_t kp_position_length;
      float st_kp_position;
      float * kp_position;
      uint8_t ki_position_length;
      float st_ki_position;
      float * ki_position;
      uint8_t kd_position_length;
      float st_kd_position;
      float * kd_position;
      uint8_t kp_velocity_length;
      float st_kp_velocity;
      float * kp_velocity;
      uint8_t i_effort_min_length;
      float st_i_effort_min;
      float * i_effort_min;
      uint8_t i_effort_max_length;
      float st_i_effort_max;
      float * i_effort_max;
      uint8_t kpv_position_length;
      float st_kpv_position;
      float * kpv_position;
      uint8_t kpv_velocity_length;
      float st_kpv_velocity;
      float * kpv_velocity;
      uint8_t desired_controller_period_ms;

    JointCommand():
      header(),
      position_length(0), position(NULL),
      velocity_length(0), velocity(NULL),
      effort_length(0), effort(NULL),
      kp_position_length(0), kp_position(NULL),
      ki_position_length(0), ki_position(NULL),
      kd_position_length(0), kd_position(NULL),
      kp_velocity_length(0), kp_velocity(NULL),
      i_effort_min_length(0), i_effort_min(NULL),
      i_effort_max_length(0), i_effort_max(NULL),
      kpv_position_length(0), kpv_position(NULL),
      kpv_velocity_length(0), kpv_velocity(NULL),
      desired_controller_period_ms(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < position_length; i++){
      union {
        double real;
        uint64_t base;
      } u_positioni;
      u_positioni.real = this->position[i];
      *(outbuffer + offset + 0) = (u_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_positioni.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_positioni.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_positioni.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_positioni.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_positioni.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->position[i]);
      }
      *(outbuffer + offset++) = velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < velocity_length; i++){
      union {
        double real;
        uint64_t base;
      } u_velocityi;
      u_velocityi.real = this->velocity[i];
      *(outbuffer + offset + 0) = (u_velocityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocityi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_velocityi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_velocityi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_velocityi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_velocityi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->velocity[i]);
      }
      *(outbuffer + offset++) = effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_efforti;
      u_efforti.real = this->effort[i];
      *(outbuffer + offset + 0) = (u_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->effort[i]);
      }
      *(outbuffer + offset++) = kp_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < kp_position_length; i++){
      union {
        float real;
        uint32_t base;
      } u_kp_positioni;
      u_kp_positioni.real = this->kp_position[i];
      *(outbuffer + offset + 0) = (u_kp_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kp_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kp_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kp_positioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kp_position[i]);
      }
      *(outbuffer + offset++) = ki_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ki_position_length; i++){
      union {
        float real;
        uint32_t base;
      } u_ki_positioni;
      u_ki_positioni.real = this->ki_position[i];
      *(outbuffer + offset + 0) = (u_ki_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ki_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ki_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ki_positioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ki_position[i]);
      }
      *(outbuffer + offset++) = kd_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < kd_position_length; i++){
      union {
        float real;
        uint32_t base;
      } u_kd_positioni;
      u_kd_positioni.real = this->kd_position[i];
      *(outbuffer + offset + 0) = (u_kd_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kd_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kd_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kd_positioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kd_position[i]);
      }
      *(outbuffer + offset++) = kp_velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < kp_velocity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_kp_velocityi;
      u_kp_velocityi.real = this->kp_velocity[i];
      *(outbuffer + offset + 0) = (u_kp_velocityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kp_velocityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kp_velocityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kp_velocityi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kp_velocity[i]);
      }
      *(outbuffer + offset++) = i_effort_min_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < i_effort_min_length; i++){
      union {
        float real;
        uint32_t base;
      } u_i_effort_mini;
      u_i_effort_mini.real = this->i_effort_min[i];
      *(outbuffer + offset + 0) = (u_i_effort_mini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i_effort_mini.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i_effort_mini.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i_effort_mini.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i_effort_min[i]);
      }
      *(outbuffer + offset++) = i_effort_max_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < i_effort_max_length; i++){
      union {
        float real;
        uint32_t base;
      } u_i_effort_maxi;
      u_i_effort_maxi.real = this->i_effort_max[i];
      *(outbuffer + offset + 0) = (u_i_effort_maxi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i_effort_maxi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i_effort_maxi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i_effort_maxi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i_effort_max[i]);
      }
      *(outbuffer + offset++) = kpv_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < kpv_position_length; i++){
      union {
        float real;
        uint32_t base;
      } u_kpv_positioni;
      u_kpv_positioni.real = this->kpv_position[i];
      *(outbuffer + offset + 0) = (u_kpv_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kpv_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kpv_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kpv_positioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kpv_position[i]);
      }
      *(outbuffer + offset++) = kpv_velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < kpv_velocity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_kpv_velocityi;
      u_kpv_velocityi.real = this->kpv_velocity[i];
      *(outbuffer + offset + 0) = (u_kpv_velocityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kpv_velocityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kpv_velocityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kpv_velocityi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kpv_velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->desired_controller_period_ms >> (8 * 0)) & 0xFF;
      offset += sizeof(this->desired_controller_period_ms);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t position_lengthT = *(inbuffer + offset++);
      if(position_lengthT > position_length)
        this->position = (double*)realloc(this->position, position_lengthT * sizeof(double));
      offset += 3;
      position_length = position_lengthT;
      for( uint8_t i = 0; i < position_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_position;
      u_st_position.base = 0;
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_position = u_st_position.real;
      offset += sizeof(this->st_position);
        memcpy( &(this->position[i]), &(this->st_position), sizeof(double));
      }
      uint8_t velocity_lengthT = *(inbuffer + offset++);
      if(velocity_lengthT > velocity_length)
        this->velocity = (double*)realloc(this->velocity, velocity_lengthT * sizeof(double));
      offset += 3;
      velocity_length = velocity_lengthT;
      for( uint8_t i = 0; i < velocity_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_velocity;
      u_st_velocity.base = 0;
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_velocity = u_st_velocity.real;
      offset += sizeof(this->st_velocity);
        memcpy( &(this->velocity[i]), &(this->st_velocity), sizeof(double));
      }
      uint8_t effort_lengthT = *(inbuffer + offset++);
      if(effort_lengthT > effort_length)
        this->effort = (double*)realloc(this->effort, effort_lengthT * sizeof(double));
      offset += 3;
      effort_length = effort_lengthT;
      for( uint8_t i = 0; i < effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_effort;
      u_st_effort.base = 0;
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_effort = u_st_effort.real;
      offset += sizeof(this->st_effort);
        memcpy( &(this->effort[i]), &(this->st_effort), sizeof(double));
      }
      uint8_t kp_position_lengthT = *(inbuffer + offset++);
      if(kp_position_lengthT > kp_position_length)
        this->kp_position = (float*)realloc(this->kp_position, kp_position_lengthT * sizeof(float));
      offset += 3;
      kp_position_length = kp_position_lengthT;
      for( uint8_t i = 0; i < kp_position_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_kp_position;
      u_st_kp_position.base = 0;
      u_st_kp_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_kp_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_kp_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_kp_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_kp_position = u_st_kp_position.real;
      offset += sizeof(this->st_kp_position);
        memcpy( &(this->kp_position[i]), &(this->st_kp_position), sizeof(float));
      }
      uint8_t ki_position_lengthT = *(inbuffer + offset++);
      if(ki_position_lengthT > ki_position_length)
        this->ki_position = (float*)realloc(this->ki_position, ki_position_lengthT * sizeof(float));
      offset += 3;
      ki_position_length = ki_position_lengthT;
      for( uint8_t i = 0; i < ki_position_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_ki_position;
      u_st_ki_position.base = 0;
      u_st_ki_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ki_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ki_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ki_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_ki_position = u_st_ki_position.real;
      offset += sizeof(this->st_ki_position);
        memcpy( &(this->ki_position[i]), &(this->st_ki_position), sizeof(float));
      }
      uint8_t kd_position_lengthT = *(inbuffer + offset++);
      if(kd_position_lengthT > kd_position_length)
        this->kd_position = (float*)realloc(this->kd_position, kd_position_lengthT * sizeof(float));
      offset += 3;
      kd_position_length = kd_position_lengthT;
      for( uint8_t i = 0; i < kd_position_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_kd_position;
      u_st_kd_position.base = 0;
      u_st_kd_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_kd_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_kd_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_kd_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_kd_position = u_st_kd_position.real;
      offset += sizeof(this->st_kd_position);
        memcpy( &(this->kd_position[i]), &(this->st_kd_position), sizeof(float));
      }
      uint8_t kp_velocity_lengthT = *(inbuffer + offset++);
      if(kp_velocity_lengthT > kp_velocity_length)
        this->kp_velocity = (float*)realloc(this->kp_velocity, kp_velocity_lengthT * sizeof(float));
      offset += 3;
      kp_velocity_length = kp_velocity_lengthT;
      for( uint8_t i = 0; i < kp_velocity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_kp_velocity;
      u_st_kp_velocity.base = 0;
      u_st_kp_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_kp_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_kp_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_kp_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_kp_velocity = u_st_kp_velocity.real;
      offset += sizeof(this->st_kp_velocity);
        memcpy( &(this->kp_velocity[i]), &(this->st_kp_velocity), sizeof(float));
      }
      uint8_t i_effort_min_lengthT = *(inbuffer + offset++);
      if(i_effort_min_lengthT > i_effort_min_length)
        this->i_effort_min = (float*)realloc(this->i_effort_min, i_effort_min_lengthT * sizeof(float));
      offset += 3;
      i_effort_min_length = i_effort_min_lengthT;
      for( uint8_t i = 0; i < i_effort_min_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_i_effort_min;
      u_st_i_effort_min.base = 0;
      u_st_i_effort_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_i_effort_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_i_effort_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_i_effort_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_i_effort_min = u_st_i_effort_min.real;
      offset += sizeof(this->st_i_effort_min);
        memcpy( &(this->i_effort_min[i]), &(this->st_i_effort_min), sizeof(float));
      }
      uint8_t i_effort_max_lengthT = *(inbuffer + offset++);
      if(i_effort_max_lengthT > i_effort_max_length)
        this->i_effort_max = (float*)realloc(this->i_effort_max, i_effort_max_lengthT * sizeof(float));
      offset += 3;
      i_effort_max_length = i_effort_max_lengthT;
      for( uint8_t i = 0; i < i_effort_max_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_i_effort_max;
      u_st_i_effort_max.base = 0;
      u_st_i_effort_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_i_effort_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_i_effort_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_i_effort_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_i_effort_max = u_st_i_effort_max.real;
      offset += sizeof(this->st_i_effort_max);
        memcpy( &(this->i_effort_max[i]), &(this->st_i_effort_max), sizeof(float));
      }
      uint8_t kpv_position_lengthT = *(inbuffer + offset++);
      if(kpv_position_lengthT > kpv_position_length)
        this->kpv_position = (float*)realloc(this->kpv_position, kpv_position_lengthT * sizeof(float));
      offset += 3;
      kpv_position_length = kpv_position_lengthT;
      for( uint8_t i = 0; i < kpv_position_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_kpv_position;
      u_st_kpv_position.base = 0;
      u_st_kpv_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_kpv_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_kpv_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_kpv_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_kpv_position = u_st_kpv_position.real;
      offset += sizeof(this->st_kpv_position);
        memcpy( &(this->kpv_position[i]), &(this->st_kpv_position), sizeof(float));
      }
      uint8_t kpv_velocity_lengthT = *(inbuffer + offset++);
      if(kpv_velocity_lengthT > kpv_velocity_length)
        this->kpv_velocity = (float*)realloc(this->kpv_velocity, kpv_velocity_lengthT * sizeof(float));
      offset += 3;
      kpv_velocity_length = kpv_velocity_lengthT;
      for( uint8_t i = 0; i < kpv_velocity_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_kpv_velocity;
      u_st_kpv_velocity.base = 0;
      u_st_kpv_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_kpv_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_kpv_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_kpv_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_kpv_velocity = u_st_kpv_velocity.real;
      offset += sizeof(this->st_kpv_velocity);
        memcpy( &(this->kpv_velocity[i]), &(this->st_kpv_velocity), sizeof(float));
      }
      this->desired_controller_period_ms =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->desired_controller_period_ms);
     return offset;
    }

    const char * getType(){ return "hrpsys_gazebo_msgs/JointCommand"; };
    const char * getMD5(){ return "dae507ff7b5dde0eef1b06094d875eaa"; };

  };

}
#endif