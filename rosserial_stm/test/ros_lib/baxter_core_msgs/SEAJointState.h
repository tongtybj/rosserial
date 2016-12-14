#ifndef _ROS_baxter_core_msgs_SEAJointState_h
#define _ROS_baxter_core_msgs_SEAJointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace baxter_core_msgs
{

  class SEAJointState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t name_length;
      char* st_name;
      char* * name;
      uint8_t commanded_position_length;
      double st_commanded_position;
      double * commanded_position;
      uint8_t commanded_velocity_length;
      double st_commanded_velocity;
      double * commanded_velocity;
      uint8_t commanded_acceleration_length;
      double st_commanded_acceleration;
      double * commanded_acceleration;
      uint8_t commanded_effort_length;
      double st_commanded_effort;
      double * commanded_effort;
      uint8_t actual_position_length;
      double st_actual_position;
      double * actual_position;
      uint8_t actual_velocity_length;
      double st_actual_velocity;
      double * actual_velocity;
      uint8_t actual_effort_length;
      double st_actual_effort;
      double * actual_effort;
      uint8_t gravity_model_effort_length;
      double st_gravity_model_effort;
      double * gravity_model_effort;
      uint8_t gravity_only_length;
      double st_gravity_only;
      double * gravity_only;
      uint8_t hysteresis_model_effort_length;
      double st_hysteresis_model_effort;
      double * hysteresis_model_effort;
      uint8_t crosstalk_model_effort_length;
      double st_crosstalk_model_effort;
      double * crosstalk_model_effort;
      double hystState;

    SEAJointState():
      header(),
      name_length(0), name(NULL),
      commanded_position_length(0), commanded_position(NULL),
      commanded_velocity_length(0), commanded_velocity(NULL),
      commanded_acceleration_length(0), commanded_acceleration(NULL),
      commanded_effort_length(0), commanded_effort(NULL),
      actual_position_length(0), actual_position(NULL),
      actual_velocity_length(0), actual_velocity(NULL),
      actual_effort_length(0), actual_effort(NULL),
      gravity_model_effort_length(0), gravity_model_effort(NULL),
      gravity_only_length(0), gravity_only(NULL),
      hysteresis_model_effort_length(0), hysteresis_model_effort(NULL),
      crosstalk_model_effort_length(0), crosstalk_model_effort(NULL),
      hystState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = name_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      memcpy(outbuffer + offset, &length_namei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset++) = commanded_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < commanded_position_length; i++){
      union {
        double real;
        uint64_t base;
      } u_commanded_positioni;
      u_commanded_positioni.real = this->commanded_position[i];
      *(outbuffer + offset + 0) = (u_commanded_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commanded_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commanded_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commanded_positioni.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_commanded_positioni.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_commanded_positioni.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_commanded_positioni.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_commanded_positioni.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->commanded_position[i]);
      }
      *(outbuffer + offset++) = commanded_velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < commanded_velocity_length; i++){
      union {
        double real;
        uint64_t base;
      } u_commanded_velocityi;
      u_commanded_velocityi.real = this->commanded_velocity[i];
      *(outbuffer + offset + 0) = (u_commanded_velocityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commanded_velocityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commanded_velocityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commanded_velocityi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_commanded_velocityi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_commanded_velocityi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_commanded_velocityi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_commanded_velocityi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->commanded_velocity[i]);
      }
      *(outbuffer + offset++) = commanded_acceleration_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < commanded_acceleration_length; i++){
      union {
        double real;
        uint64_t base;
      } u_commanded_accelerationi;
      u_commanded_accelerationi.real = this->commanded_acceleration[i];
      *(outbuffer + offset + 0) = (u_commanded_accelerationi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commanded_accelerationi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commanded_accelerationi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commanded_accelerationi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_commanded_accelerationi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_commanded_accelerationi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_commanded_accelerationi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_commanded_accelerationi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->commanded_acceleration[i]);
      }
      *(outbuffer + offset++) = commanded_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < commanded_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_commanded_efforti;
      u_commanded_efforti.real = this->commanded_effort[i];
      *(outbuffer + offset + 0) = (u_commanded_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commanded_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commanded_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commanded_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_commanded_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_commanded_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_commanded_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_commanded_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->commanded_effort[i]);
      }
      *(outbuffer + offset++) = actual_position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < actual_position_length; i++){
      union {
        double real;
        uint64_t base;
      } u_actual_positioni;
      u_actual_positioni.real = this->actual_position[i];
      *(outbuffer + offset + 0) = (u_actual_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actual_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_actual_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_actual_positioni.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_actual_positioni.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_actual_positioni.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_actual_positioni.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_actual_positioni.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->actual_position[i]);
      }
      *(outbuffer + offset++) = actual_velocity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < actual_velocity_length; i++){
      union {
        double real;
        uint64_t base;
      } u_actual_velocityi;
      u_actual_velocityi.real = this->actual_velocity[i];
      *(outbuffer + offset + 0) = (u_actual_velocityi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actual_velocityi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_actual_velocityi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_actual_velocityi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_actual_velocityi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_actual_velocityi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_actual_velocityi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_actual_velocityi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->actual_velocity[i]);
      }
      *(outbuffer + offset++) = actual_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < actual_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_actual_efforti;
      u_actual_efforti.real = this->actual_effort[i];
      *(outbuffer + offset + 0) = (u_actual_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actual_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_actual_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_actual_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_actual_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_actual_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_actual_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_actual_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->actual_effort[i]);
      }
      *(outbuffer + offset++) = gravity_model_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < gravity_model_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_gravity_model_efforti;
      u_gravity_model_efforti.real = this->gravity_model_effort[i];
      *(outbuffer + offset + 0) = (u_gravity_model_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gravity_model_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gravity_model_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gravity_model_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_gravity_model_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_gravity_model_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_gravity_model_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_gravity_model_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->gravity_model_effort[i]);
      }
      *(outbuffer + offset++) = gravity_only_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < gravity_only_length; i++){
      union {
        double real;
        uint64_t base;
      } u_gravity_onlyi;
      u_gravity_onlyi.real = this->gravity_only[i];
      *(outbuffer + offset + 0) = (u_gravity_onlyi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gravity_onlyi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gravity_onlyi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gravity_onlyi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_gravity_onlyi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_gravity_onlyi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_gravity_onlyi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_gravity_onlyi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->gravity_only[i]);
      }
      *(outbuffer + offset++) = hysteresis_model_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < hysteresis_model_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_hysteresis_model_efforti;
      u_hysteresis_model_efforti.real = this->hysteresis_model_effort[i];
      *(outbuffer + offset + 0) = (u_hysteresis_model_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hysteresis_model_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hysteresis_model_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hysteresis_model_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hysteresis_model_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hysteresis_model_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hysteresis_model_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hysteresis_model_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hysteresis_model_effort[i]);
      }
      *(outbuffer + offset++) = crosstalk_model_effort_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < crosstalk_model_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_crosstalk_model_efforti;
      u_crosstalk_model_efforti.real = this->crosstalk_model_effort[i];
      *(outbuffer + offset + 0) = (u_crosstalk_model_efforti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_crosstalk_model_efforti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_crosstalk_model_efforti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_crosstalk_model_efforti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_crosstalk_model_efforti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_crosstalk_model_efforti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_crosstalk_model_efforti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_crosstalk_model_efforti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->crosstalk_model_effort[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_hystState;
      u_hystState.real = this->hystState;
      *(outbuffer + offset + 0) = (u_hystState.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hystState.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hystState.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hystState.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_hystState.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_hystState.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_hystState.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_hystState.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->hystState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t name_lengthT = *(inbuffer + offset++);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      offset += 3;
      name_length = name_lengthT;
      for( uint8_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      memcpy(&length_st_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint8_t commanded_position_lengthT = *(inbuffer + offset++);
      if(commanded_position_lengthT > commanded_position_length)
        this->commanded_position = (double*)realloc(this->commanded_position, commanded_position_lengthT * sizeof(double));
      offset += 3;
      commanded_position_length = commanded_position_lengthT;
      for( uint8_t i = 0; i < commanded_position_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_commanded_position;
      u_st_commanded_position.base = 0;
      u_st_commanded_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_commanded_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_commanded_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_commanded_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_commanded_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_commanded_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_commanded_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_commanded_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_commanded_position = u_st_commanded_position.real;
      offset += sizeof(this->st_commanded_position);
        memcpy( &(this->commanded_position[i]), &(this->st_commanded_position), sizeof(double));
      }
      uint8_t commanded_velocity_lengthT = *(inbuffer + offset++);
      if(commanded_velocity_lengthT > commanded_velocity_length)
        this->commanded_velocity = (double*)realloc(this->commanded_velocity, commanded_velocity_lengthT * sizeof(double));
      offset += 3;
      commanded_velocity_length = commanded_velocity_lengthT;
      for( uint8_t i = 0; i < commanded_velocity_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_commanded_velocity;
      u_st_commanded_velocity.base = 0;
      u_st_commanded_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_commanded_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_commanded_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_commanded_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_commanded_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_commanded_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_commanded_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_commanded_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_commanded_velocity = u_st_commanded_velocity.real;
      offset += sizeof(this->st_commanded_velocity);
        memcpy( &(this->commanded_velocity[i]), &(this->st_commanded_velocity), sizeof(double));
      }
      uint8_t commanded_acceleration_lengthT = *(inbuffer + offset++);
      if(commanded_acceleration_lengthT > commanded_acceleration_length)
        this->commanded_acceleration = (double*)realloc(this->commanded_acceleration, commanded_acceleration_lengthT * sizeof(double));
      offset += 3;
      commanded_acceleration_length = commanded_acceleration_lengthT;
      for( uint8_t i = 0; i < commanded_acceleration_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_commanded_acceleration;
      u_st_commanded_acceleration.base = 0;
      u_st_commanded_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_commanded_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_commanded_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_commanded_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_commanded_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_commanded_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_commanded_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_commanded_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_commanded_acceleration = u_st_commanded_acceleration.real;
      offset += sizeof(this->st_commanded_acceleration);
        memcpy( &(this->commanded_acceleration[i]), &(this->st_commanded_acceleration), sizeof(double));
      }
      uint8_t commanded_effort_lengthT = *(inbuffer + offset++);
      if(commanded_effort_lengthT > commanded_effort_length)
        this->commanded_effort = (double*)realloc(this->commanded_effort, commanded_effort_lengthT * sizeof(double));
      offset += 3;
      commanded_effort_length = commanded_effort_lengthT;
      for( uint8_t i = 0; i < commanded_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_commanded_effort;
      u_st_commanded_effort.base = 0;
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_commanded_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_commanded_effort = u_st_commanded_effort.real;
      offset += sizeof(this->st_commanded_effort);
        memcpy( &(this->commanded_effort[i]), &(this->st_commanded_effort), sizeof(double));
      }
      uint8_t actual_position_lengthT = *(inbuffer + offset++);
      if(actual_position_lengthT > actual_position_length)
        this->actual_position = (double*)realloc(this->actual_position, actual_position_lengthT * sizeof(double));
      offset += 3;
      actual_position_length = actual_position_lengthT;
      for( uint8_t i = 0; i < actual_position_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_actual_position;
      u_st_actual_position.base = 0;
      u_st_actual_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_actual_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_actual_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_actual_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_actual_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_actual_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_actual_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_actual_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_actual_position = u_st_actual_position.real;
      offset += sizeof(this->st_actual_position);
        memcpy( &(this->actual_position[i]), &(this->st_actual_position), sizeof(double));
      }
      uint8_t actual_velocity_lengthT = *(inbuffer + offset++);
      if(actual_velocity_lengthT > actual_velocity_length)
        this->actual_velocity = (double*)realloc(this->actual_velocity, actual_velocity_lengthT * sizeof(double));
      offset += 3;
      actual_velocity_length = actual_velocity_lengthT;
      for( uint8_t i = 0; i < actual_velocity_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_actual_velocity;
      u_st_actual_velocity.base = 0;
      u_st_actual_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_actual_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_actual_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_actual_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_actual_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_actual_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_actual_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_actual_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_actual_velocity = u_st_actual_velocity.real;
      offset += sizeof(this->st_actual_velocity);
        memcpy( &(this->actual_velocity[i]), &(this->st_actual_velocity), sizeof(double));
      }
      uint8_t actual_effort_lengthT = *(inbuffer + offset++);
      if(actual_effort_lengthT > actual_effort_length)
        this->actual_effort = (double*)realloc(this->actual_effort, actual_effort_lengthT * sizeof(double));
      offset += 3;
      actual_effort_length = actual_effort_lengthT;
      for( uint8_t i = 0; i < actual_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_actual_effort;
      u_st_actual_effort.base = 0;
      u_st_actual_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_actual_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_actual_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_actual_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_actual_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_actual_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_actual_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_actual_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_actual_effort = u_st_actual_effort.real;
      offset += sizeof(this->st_actual_effort);
        memcpy( &(this->actual_effort[i]), &(this->st_actual_effort), sizeof(double));
      }
      uint8_t gravity_model_effort_lengthT = *(inbuffer + offset++);
      if(gravity_model_effort_lengthT > gravity_model_effort_length)
        this->gravity_model_effort = (double*)realloc(this->gravity_model_effort, gravity_model_effort_lengthT * sizeof(double));
      offset += 3;
      gravity_model_effort_length = gravity_model_effort_lengthT;
      for( uint8_t i = 0; i < gravity_model_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_gravity_model_effort;
      u_st_gravity_model_effort.base = 0;
      u_st_gravity_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_gravity_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_gravity_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_gravity_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_gravity_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_gravity_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_gravity_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_gravity_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_gravity_model_effort = u_st_gravity_model_effort.real;
      offset += sizeof(this->st_gravity_model_effort);
        memcpy( &(this->gravity_model_effort[i]), &(this->st_gravity_model_effort), sizeof(double));
      }
      uint8_t gravity_only_lengthT = *(inbuffer + offset++);
      if(gravity_only_lengthT > gravity_only_length)
        this->gravity_only = (double*)realloc(this->gravity_only, gravity_only_lengthT * sizeof(double));
      offset += 3;
      gravity_only_length = gravity_only_lengthT;
      for( uint8_t i = 0; i < gravity_only_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_gravity_only;
      u_st_gravity_only.base = 0;
      u_st_gravity_only.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_gravity_only.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_gravity_only.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_gravity_only.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_gravity_only.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_gravity_only.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_gravity_only.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_gravity_only.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_gravity_only = u_st_gravity_only.real;
      offset += sizeof(this->st_gravity_only);
        memcpy( &(this->gravity_only[i]), &(this->st_gravity_only), sizeof(double));
      }
      uint8_t hysteresis_model_effort_lengthT = *(inbuffer + offset++);
      if(hysteresis_model_effort_lengthT > hysteresis_model_effort_length)
        this->hysteresis_model_effort = (double*)realloc(this->hysteresis_model_effort, hysteresis_model_effort_lengthT * sizeof(double));
      offset += 3;
      hysteresis_model_effort_length = hysteresis_model_effort_lengthT;
      for( uint8_t i = 0; i < hysteresis_model_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_hysteresis_model_effort;
      u_st_hysteresis_model_effort.base = 0;
      u_st_hysteresis_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_hysteresis_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_hysteresis_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_hysteresis_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_hysteresis_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_hysteresis_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_hysteresis_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_hysteresis_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_hysteresis_model_effort = u_st_hysteresis_model_effort.real;
      offset += sizeof(this->st_hysteresis_model_effort);
        memcpy( &(this->hysteresis_model_effort[i]), &(this->st_hysteresis_model_effort), sizeof(double));
      }
      uint8_t crosstalk_model_effort_lengthT = *(inbuffer + offset++);
      if(crosstalk_model_effort_lengthT > crosstalk_model_effort_length)
        this->crosstalk_model_effort = (double*)realloc(this->crosstalk_model_effort, crosstalk_model_effort_lengthT * sizeof(double));
      offset += 3;
      crosstalk_model_effort_length = crosstalk_model_effort_lengthT;
      for( uint8_t i = 0; i < crosstalk_model_effort_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_crosstalk_model_effort;
      u_st_crosstalk_model_effort.base = 0;
      u_st_crosstalk_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_crosstalk_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_crosstalk_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_crosstalk_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_crosstalk_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_crosstalk_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_crosstalk_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_crosstalk_model_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_crosstalk_model_effort = u_st_crosstalk_model_effort.real;
      offset += sizeof(this->st_crosstalk_model_effort);
        memcpy( &(this->crosstalk_model_effort[i]), &(this->st_crosstalk_model_effort), sizeof(double));
      }
      union {
        double real;
        uint64_t base;
      } u_hystState;
      u_hystState.base = 0;
      u_hystState.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hystState.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hystState.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hystState.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_hystState.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_hystState.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_hystState.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_hystState.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->hystState = u_hystState.real;
      offset += sizeof(this->hystState);
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/SEAJointState"; };
    const char * getMD5(){ return "d36406dcbb6d860b1b39c4e28f81352b"; };

  };

}
#endif