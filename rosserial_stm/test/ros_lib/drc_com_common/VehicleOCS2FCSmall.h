#ifndef _ROS_drc_com_common_VehicleOCS2FCSmall_h
#define _ROS_drc_com_common_VehicleOCS2FCSmall_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_com_common
{

  class VehicleOCS2FCSmall : public ros::Msg
  {
    public:
      bool execute_flag;
      float handle_cmd;
      float accel_cmd;
      float brake_cmd;
      float neck_y_cmd;
      float neck_p_cmd;
      bool initialize_request;
      bool grasp_request;
      bool release_request;
      bool correct_request;
      bool resume_request;
      bool approach_handle_request;
      bool approach_accel_request;
      bool reach_arm_request;
      bool reach_leg_request;
      bool egress_request;
      bool set_max_step_request;
      float set_max_step_request_value;
      bool set_min_step_request;
      float set_min_step_request_value;
      bool set_detach_step_request;
      float set_detach_step_request_value;
      bool overwrite_handle_angle_request;
      float overwrite_handle_angle_request_value;
      bool set_real_request;
      uint8_t set_real_request_value;
      bool set_handle_mode_request;
      uint8_t set_handle_mode_request_value;
      bool set_accel_mode_request;
      uint8_t set_accel_mode_request_value;
      bool set_neck_mode_request;
      uint8_t set_neck_mode_request_value;

    VehicleOCS2FCSmall():
      execute_flag(0),
      handle_cmd(0),
      accel_cmd(0),
      brake_cmd(0),
      neck_y_cmd(0),
      neck_p_cmd(0),
      initialize_request(0),
      grasp_request(0),
      release_request(0),
      correct_request(0),
      resume_request(0),
      approach_handle_request(0),
      approach_accel_request(0),
      reach_arm_request(0),
      reach_leg_request(0),
      egress_request(0),
      set_max_step_request(0),
      set_max_step_request_value(0),
      set_min_step_request(0),
      set_min_step_request_value(0),
      set_detach_step_request(0),
      set_detach_step_request_value(0),
      overwrite_handle_angle_request(0),
      overwrite_handle_angle_request_value(0),
      set_real_request(0),
      set_real_request_value(0),
      set_handle_mode_request(0),
      set_handle_mode_request_value(0),
      set_accel_mode_request(0),
      set_accel_mode_request_value(0),
      set_neck_mode_request(0),
      set_neck_mode_request_value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_execute_flag;
      u_execute_flag.real = this->execute_flag;
      *(outbuffer + offset + 0) = (u_execute_flag.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->execute_flag);
      union {
        float real;
        uint32_t base;
      } u_handle_cmd;
      u_handle_cmd.real = this->handle_cmd;
      *(outbuffer + offset + 0) = (u_handle_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_handle_cmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_handle_cmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_handle_cmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->handle_cmd);
      union {
        float real;
        uint32_t base;
      } u_accel_cmd;
      u_accel_cmd.real = this->accel_cmd;
      *(outbuffer + offset + 0) = (u_accel_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accel_cmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accel_cmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accel_cmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accel_cmd);
      union {
        float real;
        uint32_t base;
      } u_brake_cmd;
      u_brake_cmd.real = this->brake_cmd;
      *(outbuffer + offset + 0) = (u_brake_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_brake_cmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_brake_cmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_brake_cmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->brake_cmd);
      union {
        float real;
        uint32_t base;
      } u_neck_y_cmd;
      u_neck_y_cmd.real = this->neck_y_cmd;
      *(outbuffer + offset + 0) = (u_neck_y_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neck_y_cmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neck_y_cmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neck_y_cmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neck_y_cmd);
      union {
        float real;
        uint32_t base;
      } u_neck_p_cmd;
      u_neck_p_cmd.real = this->neck_p_cmd;
      *(outbuffer + offset + 0) = (u_neck_p_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neck_p_cmd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neck_p_cmd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neck_p_cmd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neck_p_cmd);
      union {
        bool real;
        uint8_t base;
      } u_initialize_request;
      u_initialize_request.real = this->initialize_request;
      *(outbuffer + offset + 0) = (u_initialize_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->initialize_request);
      union {
        bool real;
        uint8_t base;
      } u_grasp_request;
      u_grasp_request.real = this->grasp_request;
      *(outbuffer + offset + 0) = (u_grasp_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grasp_request);
      union {
        bool real;
        uint8_t base;
      } u_release_request;
      u_release_request.real = this->release_request;
      *(outbuffer + offset + 0) = (u_release_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->release_request);
      union {
        bool real;
        uint8_t base;
      } u_correct_request;
      u_correct_request.real = this->correct_request;
      *(outbuffer + offset + 0) = (u_correct_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->correct_request);
      union {
        bool real;
        uint8_t base;
      } u_resume_request;
      u_resume_request.real = this->resume_request;
      *(outbuffer + offset + 0) = (u_resume_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->resume_request);
      union {
        bool real;
        uint8_t base;
      } u_approach_handle_request;
      u_approach_handle_request.real = this->approach_handle_request;
      *(outbuffer + offset + 0) = (u_approach_handle_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->approach_handle_request);
      union {
        bool real;
        uint8_t base;
      } u_approach_accel_request;
      u_approach_accel_request.real = this->approach_accel_request;
      *(outbuffer + offset + 0) = (u_approach_accel_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->approach_accel_request);
      union {
        bool real;
        uint8_t base;
      } u_reach_arm_request;
      u_reach_arm_request.real = this->reach_arm_request;
      *(outbuffer + offset + 0) = (u_reach_arm_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reach_arm_request);
      union {
        bool real;
        uint8_t base;
      } u_reach_leg_request;
      u_reach_leg_request.real = this->reach_leg_request;
      *(outbuffer + offset + 0) = (u_reach_leg_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reach_leg_request);
      union {
        bool real;
        uint8_t base;
      } u_egress_request;
      u_egress_request.real = this->egress_request;
      *(outbuffer + offset + 0) = (u_egress_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->egress_request);
      union {
        bool real;
        uint8_t base;
      } u_set_max_step_request;
      u_set_max_step_request.real = this->set_max_step_request;
      *(outbuffer + offset + 0) = (u_set_max_step_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_max_step_request);
      union {
        float real;
        uint32_t base;
      } u_set_max_step_request_value;
      u_set_max_step_request_value.real = this->set_max_step_request_value;
      *(outbuffer + offset + 0) = (u_set_max_step_request_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_max_step_request_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_max_step_request_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_max_step_request_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_max_step_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_min_step_request;
      u_set_min_step_request.real = this->set_min_step_request;
      *(outbuffer + offset + 0) = (u_set_min_step_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_min_step_request);
      union {
        float real;
        uint32_t base;
      } u_set_min_step_request_value;
      u_set_min_step_request_value.real = this->set_min_step_request_value;
      *(outbuffer + offset + 0) = (u_set_min_step_request_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_min_step_request_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_min_step_request_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_min_step_request_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_min_step_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_detach_step_request;
      u_set_detach_step_request.real = this->set_detach_step_request;
      *(outbuffer + offset + 0) = (u_set_detach_step_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_detach_step_request);
      union {
        float real;
        uint32_t base;
      } u_set_detach_step_request_value;
      u_set_detach_step_request_value.real = this->set_detach_step_request_value;
      *(outbuffer + offset + 0) = (u_set_detach_step_request_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_set_detach_step_request_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_set_detach_step_request_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_set_detach_step_request_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->set_detach_step_request_value);
      union {
        bool real;
        uint8_t base;
      } u_overwrite_handle_angle_request;
      u_overwrite_handle_angle_request.real = this->overwrite_handle_angle_request;
      *(outbuffer + offset + 0) = (u_overwrite_handle_angle_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->overwrite_handle_angle_request);
      union {
        float real;
        uint32_t base;
      } u_overwrite_handle_angle_request_value;
      u_overwrite_handle_angle_request_value.real = this->overwrite_handle_angle_request_value;
      *(outbuffer + offset + 0) = (u_overwrite_handle_angle_request_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_overwrite_handle_angle_request_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_overwrite_handle_angle_request_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_overwrite_handle_angle_request_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->overwrite_handle_angle_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_real_request;
      u_set_real_request.real = this->set_real_request;
      *(outbuffer + offset + 0) = (u_set_real_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_real_request);
      *(outbuffer + offset + 0) = (this->set_real_request_value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_real_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_handle_mode_request;
      u_set_handle_mode_request.real = this->set_handle_mode_request;
      *(outbuffer + offset + 0) = (u_set_handle_mode_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_handle_mode_request);
      *(outbuffer + offset + 0) = (this->set_handle_mode_request_value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_handle_mode_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_accel_mode_request;
      u_set_accel_mode_request.real = this->set_accel_mode_request;
      *(outbuffer + offset + 0) = (u_set_accel_mode_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_accel_mode_request);
      *(outbuffer + offset + 0) = (this->set_accel_mode_request_value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_accel_mode_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_neck_mode_request;
      u_set_neck_mode_request.real = this->set_neck_mode_request;
      *(outbuffer + offset + 0) = (u_set_neck_mode_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_neck_mode_request);
      *(outbuffer + offset + 0) = (this->set_neck_mode_request_value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_neck_mode_request_value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_execute_flag;
      u_execute_flag.base = 0;
      u_execute_flag.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->execute_flag = u_execute_flag.real;
      offset += sizeof(this->execute_flag);
      union {
        float real;
        uint32_t base;
      } u_handle_cmd;
      u_handle_cmd.base = 0;
      u_handle_cmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_handle_cmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_handle_cmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_handle_cmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->handle_cmd = u_handle_cmd.real;
      offset += sizeof(this->handle_cmd);
      union {
        float real;
        uint32_t base;
      } u_accel_cmd;
      u_accel_cmd.base = 0;
      u_accel_cmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accel_cmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accel_cmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accel_cmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accel_cmd = u_accel_cmd.real;
      offset += sizeof(this->accel_cmd);
      union {
        float real;
        uint32_t base;
      } u_brake_cmd;
      u_brake_cmd.base = 0;
      u_brake_cmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_brake_cmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_brake_cmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_brake_cmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->brake_cmd = u_brake_cmd.real;
      offset += sizeof(this->brake_cmd);
      union {
        float real;
        uint32_t base;
      } u_neck_y_cmd;
      u_neck_y_cmd.base = 0;
      u_neck_y_cmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_neck_y_cmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_neck_y_cmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_neck_y_cmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->neck_y_cmd = u_neck_y_cmd.real;
      offset += sizeof(this->neck_y_cmd);
      union {
        float real;
        uint32_t base;
      } u_neck_p_cmd;
      u_neck_p_cmd.base = 0;
      u_neck_p_cmd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_neck_p_cmd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_neck_p_cmd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_neck_p_cmd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->neck_p_cmd = u_neck_p_cmd.real;
      offset += sizeof(this->neck_p_cmd);
      union {
        bool real;
        uint8_t base;
      } u_initialize_request;
      u_initialize_request.base = 0;
      u_initialize_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->initialize_request = u_initialize_request.real;
      offset += sizeof(this->initialize_request);
      union {
        bool real;
        uint8_t base;
      } u_grasp_request;
      u_grasp_request.base = 0;
      u_grasp_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->grasp_request = u_grasp_request.real;
      offset += sizeof(this->grasp_request);
      union {
        bool real;
        uint8_t base;
      } u_release_request;
      u_release_request.base = 0;
      u_release_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->release_request = u_release_request.real;
      offset += sizeof(this->release_request);
      union {
        bool real;
        uint8_t base;
      } u_correct_request;
      u_correct_request.base = 0;
      u_correct_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->correct_request = u_correct_request.real;
      offset += sizeof(this->correct_request);
      union {
        bool real;
        uint8_t base;
      } u_resume_request;
      u_resume_request.base = 0;
      u_resume_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->resume_request = u_resume_request.real;
      offset += sizeof(this->resume_request);
      union {
        bool real;
        uint8_t base;
      } u_approach_handle_request;
      u_approach_handle_request.base = 0;
      u_approach_handle_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->approach_handle_request = u_approach_handle_request.real;
      offset += sizeof(this->approach_handle_request);
      union {
        bool real;
        uint8_t base;
      } u_approach_accel_request;
      u_approach_accel_request.base = 0;
      u_approach_accel_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->approach_accel_request = u_approach_accel_request.real;
      offset += sizeof(this->approach_accel_request);
      union {
        bool real;
        uint8_t base;
      } u_reach_arm_request;
      u_reach_arm_request.base = 0;
      u_reach_arm_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reach_arm_request = u_reach_arm_request.real;
      offset += sizeof(this->reach_arm_request);
      union {
        bool real;
        uint8_t base;
      } u_reach_leg_request;
      u_reach_leg_request.base = 0;
      u_reach_leg_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reach_leg_request = u_reach_leg_request.real;
      offset += sizeof(this->reach_leg_request);
      union {
        bool real;
        uint8_t base;
      } u_egress_request;
      u_egress_request.base = 0;
      u_egress_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->egress_request = u_egress_request.real;
      offset += sizeof(this->egress_request);
      union {
        bool real;
        uint8_t base;
      } u_set_max_step_request;
      u_set_max_step_request.base = 0;
      u_set_max_step_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_max_step_request = u_set_max_step_request.real;
      offset += sizeof(this->set_max_step_request);
      union {
        float real;
        uint32_t base;
      } u_set_max_step_request_value;
      u_set_max_step_request_value.base = 0;
      u_set_max_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_max_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_max_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_max_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_max_step_request_value = u_set_max_step_request_value.real;
      offset += sizeof(this->set_max_step_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_min_step_request;
      u_set_min_step_request.base = 0;
      u_set_min_step_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_min_step_request = u_set_min_step_request.real;
      offset += sizeof(this->set_min_step_request);
      union {
        float real;
        uint32_t base;
      } u_set_min_step_request_value;
      u_set_min_step_request_value.base = 0;
      u_set_min_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_min_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_min_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_min_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_min_step_request_value = u_set_min_step_request_value.real;
      offset += sizeof(this->set_min_step_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_detach_step_request;
      u_set_detach_step_request.base = 0;
      u_set_detach_step_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_detach_step_request = u_set_detach_step_request.real;
      offset += sizeof(this->set_detach_step_request);
      union {
        float real;
        uint32_t base;
      } u_set_detach_step_request_value;
      u_set_detach_step_request_value.base = 0;
      u_set_detach_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_set_detach_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_set_detach_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_set_detach_step_request_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->set_detach_step_request_value = u_set_detach_step_request_value.real;
      offset += sizeof(this->set_detach_step_request_value);
      union {
        bool real;
        uint8_t base;
      } u_overwrite_handle_angle_request;
      u_overwrite_handle_angle_request.base = 0;
      u_overwrite_handle_angle_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->overwrite_handle_angle_request = u_overwrite_handle_angle_request.real;
      offset += sizeof(this->overwrite_handle_angle_request);
      union {
        float real;
        uint32_t base;
      } u_overwrite_handle_angle_request_value;
      u_overwrite_handle_angle_request_value.base = 0;
      u_overwrite_handle_angle_request_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_overwrite_handle_angle_request_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_overwrite_handle_angle_request_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_overwrite_handle_angle_request_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->overwrite_handle_angle_request_value = u_overwrite_handle_angle_request_value.real;
      offset += sizeof(this->overwrite_handle_angle_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_real_request;
      u_set_real_request.base = 0;
      u_set_real_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_real_request = u_set_real_request.real;
      offset += sizeof(this->set_real_request);
      this->set_real_request_value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->set_real_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_handle_mode_request;
      u_set_handle_mode_request.base = 0;
      u_set_handle_mode_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_handle_mode_request = u_set_handle_mode_request.real;
      offset += sizeof(this->set_handle_mode_request);
      this->set_handle_mode_request_value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->set_handle_mode_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_accel_mode_request;
      u_set_accel_mode_request.base = 0;
      u_set_accel_mode_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_accel_mode_request = u_set_accel_mode_request.real;
      offset += sizeof(this->set_accel_mode_request);
      this->set_accel_mode_request_value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->set_accel_mode_request_value);
      union {
        bool real;
        uint8_t base;
      } u_set_neck_mode_request;
      u_set_neck_mode_request.base = 0;
      u_set_neck_mode_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_neck_mode_request = u_set_neck_mode_request.real;
      offset += sizeof(this->set_neck_mode_request);
      this->set_neck_mode_request_value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->set_neck_mode_request_value);
     return offset;
    }

    const char * getType(){ return "drc_com_common/VehicleOCS2FCSmall"; };
    const char * getMD5(){ return "3e244f4faa43509b8aaeb56d6ffe8792"; };

  };

}
#endif