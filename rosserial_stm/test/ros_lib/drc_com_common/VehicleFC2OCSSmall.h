#ifndef _ROS_drc_com_common_VehicleFC2OCSSmall_h
#define _ROS_drc_com_common_VehicleFC2OCSSmall_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_com_common
{

  class VehicleFC2OCSSmall : public ros::Msg
  {
    public:
      float goal_handle_angle;
      float estimated_handle_angle;
      float step;
      float min_step;
      float max_step;
      float detach_step;
      float neck_y_angle;
      float neck_p_angle;
      bool real;
      uint8_t handle_mode;
      uint8_t accel_mode;
      uint8_t neck_mode;
      bool initialize_response;
      bool grasp_response;
      bool release_response;
      bool correct_response;
      bool resume_response;
      bool approach_handle_response;
      bool approach_accel_response;
      bool reach_arm_response;
      bool reach_leg_response;
      bool egress_response;
      bool set_max_step_response;
      bool set_min_step_response;
      bool set_detach_step_response;
      bool overwrite_handle_angle_response;
      bool set_real_response;
      bool set_handle_mode_response;
      bool set_accel_mode_response;
      bool set_neck_mode_response;
      float obstacle_length;

    VehicleFC2OCSSmall():
      goal_handle_angle(0),
      estimated_handle_angle(0),
      step(0),
      min_step(0),
      max_step(0),
      detach_step(0),
      neck_y_angle(0),
      neck_p_angle(0),
      real(0),
      handle_mode(0),
      accel_mode(0),
      neck_mode(0),
      initialize_response(0),
      grasp_response(0),
      release_response(0),
      correct_response(0),
      resume_response(0),
      approach_handle_response(0),
      approach_accel_response(0),
      reach_arm_response(0),
      reach_leg_response(0),
      egress_response(0),
      set_max_step_response(0),
      set_min_step_response(0),
      set_detach_step_response(0),
      overwrite_handle_angle_response(0),
      set_real_response(0),
      set_handle_mode_response(0),
      set_accel_mode_response(0),
      set_neck_mode_response(0),
      obstacle_length(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_goal_handle_angle;
      u_goal_handle_angle.real = this->goal_handle_angle;
      *(outbuffer + offset + 0) = (u_goal_handle_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_goal_handle_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_goal_handle_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_goal_handle_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->goal_handle_angle);
      union {
        float real;
        uint32_t base;
      } u_estimated_handle_angle;
      u_estimated_handle_angle.real = this->estimated_handle_angle;
      *(outbuffer + offset + 0) = (u_estimated_handle_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_estimated_handle_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_estimated_handle_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_estimated_handle_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->estimated_handle_angle);
      union {
        float real;
        uint32_t base;
      } u_step;
      u_step.real = this->step;
      *(outbuffer + offset + 0) = (u_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->step);
      union {
        float real;
        uint32_t base;
      } u_min_step;
      u_min_step.real = this->min_step;
      *(outbuffer + offset + 0) = (u_min_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_step.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_step);
      union {
        float real;
        uint32_t base;
      } u_max_step;
      u_max_step.real = this->max_step;
      *(outbuffer + offset + 0) = (u_max_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_step.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_step);
      union {
        float real;
        uint32_t base;
      } u_detach_step;
      u_detach_step.real = this->detach_step;
      *(outbuffer + offset + 0) = (u_detach_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detach_step.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detach_step.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detach_step.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detach_step);
      union {
        float real;
        uint32_t base;
      } u_neck_y_angle;
      u_neck_y_angle.real = this->neck_y_angle;
      *(outbuffer + offset + 0) = (u_neck_y_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neck_y_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neck_y_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neck_y_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neck_y_angle);
      union {
        float real;
        uint32_t base;
      } u_neck_p_angle;
      u_neck_p_angle.real = this->neck_p_angle;
      *(outbuffer + offset + 0) = (u_neck_p_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neck_p_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neck_p_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neck_p_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neck_p_angle);
      union {
        bool real;
        uint8_t base;
      } u_real;
      u_real.real = this->real;
      *(outbuffer + offset + 0) = (u_real.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->real);
      *(outbuffer + offset + 0) = (this->handle_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->handle_mode);
      *(outbuffer + offset + 0) = (this->accel_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->accel_mode);
      *(outbuffer + offset + 0) = (this->neck_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->neck_mode);
      union {
        bool real;
        uint8_t base;
      } u_initialize_response;
      u_initialize_response.real = this->initialize_response;
      *(outbuffer + offset + 0) = (u_initialize_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->initialize_response);
      union {
        bool real;
        uint8_t base;
      } u_grasp_response;
      u_grasp_response.real = this->grasp_response;
      *(outbuffer + offset + 0) = (u_grasp_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->grasp_response);
      union {
        bool real;
        uint8_t base;
      } u_release_response;
      u_release_response.real = this->release_response;
      *(outbuffer + offset + 0) = (u_release_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->release_response);
      union {
        bool real;
        uint8_t base;
      } u_correct_response;
      u_correct_response.real = this->correct_response;
      *(outbuffer + offset + 0) = (u_correct_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->correct_response);
      union {
        bool real;
        uint8_t base;
      } u_resume_response;
      u_resume_response.real = this->resume_response;
      *(outbuffer + offset + 0) = (u_resume_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->resume_response);
      union {
        bool real;
        uint8_t base;
      } u_approach_handle_response;
      u_approach_handle_response.real = this->approach_handle_response;
      *(outbuffer + offset + 0) = (u_approach_handle_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->approach_handle_response);
      union {
        bool real;
        uint8_t base;
      } u_approach_accel_response;
      u_approach_accel_response.real = this->approach_accel_response;
      *(outbuffer + offset + 0) = (u_approach_accel_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->approach_accel_response);
      union {
        bool real;
        uint8_t base;
      } u_reach_arm_response;
      u_reach_arm_response.real = this->reach_arm_response;
      *(outbuffer + offset + 0) = (u_reach_arm_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reach_arm_response);
      union {
        bool real;
        uint8_t base;
      } u_reach_leg_response;
      u_reach_leg_response.real = this->reach_leg_response;
      *(outbuffer + offset + 0) = (u_reach_leg_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reach_leg_response);
      union {
        bool real;
        uint8_t base;
      } u_egress_response;
      u_egress_response.real = this->egress_response;
      *(outbuffer + offset + 0) = (u_egress_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->egress_response);
      union {
        bool real;
        uint8_t base;
      } u_set_max_step_response;
      u_set_max_step_response.real = this->set_max_step_response;
      *(outbuffer + offset + 0) = (u_set_max_step_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_max_step_response);
      union {
        bool real;
        uint8_t base;
      } u_set_min_step_response;
      u_set_min_step_response.real = this->set_min_step_response;
      *(outbuffer + offset + 0) = (u_set_min_step_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_min_step_response);
      union {
        bool real;
        uint8_t base;
      } u_set_detach_step_response;
      u_set_detach_step_response.real = this->set_detach_step_response;
      *(outbuffer + offset + 0) = (u_set_detach_step_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_detach_step_response);
      union {
        bool real;
        uint8_t base;
      } u_overwrite_handle_angle_response;
      u_overwrite_handle_angle_response.real = this->overwrite_handle_angle_response;
      *(outbuffer + offset + 0) = (u_overwrite_handle_angle_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->overwrite_handle_angle_response);
      union {
        bool real;
        uint8_t base;
      } u_set_real_response;
      u_set_real_response.real = this->set_real_response;
      *(outbuffer + offset + 0) = (u_set_real_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_real_response);
      union {
        bool real;
        uint8_t base;
      } u_set_handle_mode_response;
      u_set_handle_mode_response.real = this->set_handle_mode_response;
      *(outbuffer + offset + 0) = (u_set_handle_mode_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_handle_mode_response);
      union {
        bool real;
        uint8_t base;
      } u_set_accel_mode_response;
      u_set_accel_mode_response.real = this->set_accel_mode_response;
      *(outbuffer + offset + 0) = (u_set_accel_mode_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_accel_mode_response);
      union {
        bool real;
        uint8_t base;
      } u_set_neck_mode_response;
      u_set_neck_mode_response.real = this->set_neck_mode_response;
      *(outbuffer + offset + 0) = (u_set_neck_mode_response.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_neck_mode_response);
      union {
        float real;
        uint32_t base;
      } u_obstacle_length;
      u_obstacle_length.real = this->obstacle_length;
      *(outbuffer + offset + 0) = (u_obstacle_length.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obstacle_length.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obstacle_length.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obstacle_length.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obstacle_length);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_goal_handle_angle;
      u_goal_handle_angle.base = 0;
      u_goal_handle_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_goal_handle_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_goal_handle_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_goal_handle_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->goal_handle_angle = u_goal_handle_angle.real;
      offset += sizeof(this->goal_handle_angle);
      union {
        float real;
        uint32_t base;
      } u_estimated_handle_angle;
      u_estimated_handle_angle.base = 0;
      u_estimated_handle_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_estimated_handle_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_estimated_handle_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_estimated_handle_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->estimated_handle_angle = u_estimated_handle_angle.real;
      offset += sizeof(this->estimated_handle_angle);
      union {
        float real;
        uint32_t base;
      } u_step;
      u_step.base = 0;
      u_step.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->step = u_step.real;
      offset += sizeof(this->step);
      union {
        float real;
        uint32_t base;
      } u_min_step;
      u_min_step.base = 0;
      u_min_step.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_step.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_step.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_step.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_step = u_min_step.real;
      offset += sizeof(this->min_step);
      union {
        float real;
        uint32_t base;
      } u_max_step;
      u_max_step.base = 0;
      u_max_step.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_step.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_step.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_step.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_step = u_max_step.real;
      offset += sizeof(this->max_step);
      union {
        float real;
        uint32_t base;
      } u_detach_step;
      u_detach_step.base = 0;
      u_detach_step.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detach_step.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detach_step.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detach_step.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->detach_step = u_detach_step.real;
      offset += sizeof(this->detach_step);
      union {
        float real;
        uint32_t base;
      } u_neck_y_angle;
      u_neck_y_angle.base = 0;
      u_neck_y_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_neck_y_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_neck_y_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_neck_y_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->neck_y_angle = u_neck_y_angle.real;
      offset += sizeof(this->neck_y_angle);
      union {
        float real;
        uint32_t base;
      } u_neck_p_angle;
      u_neck_p_angle.base = 0;
      u_neck_p_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_neck_p_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_neck_p_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_neck_p_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->neck_p_angle = u_neck_p_angle.real;
      offset += sizeof(this->neck_p_angle);
      union {
        bool real;
        uint8_t base;
      } u_real;
      u_real.base = 0;
      u_real.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->real = u_real.real;
      offset += sizeof(this->real);
      this->handle_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->handle_mode);
      this->accel_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->accel_mode);
      this->neck_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->neck_mode);
      union {
        bool real;
        uint8_t base;
      } u_initialize_response;
      u_initialize_response.base = 0;
      u_initialize_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->initialize_response = u_initialize_response.real;
      offset += sizeof(this->initialize_response);
      union {
        bool real;
        uint8_t base;
      } u_grasp_response;
      u_grasp_response.base = 0;
      u_grasp_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->grasp_response = u_grasp_response.real;
      offset += sizeof(this->grasp_response);
      union {
        bool real;
        uint8_t base;
      } u_release_response;
      u_release_response.base = 0;
      u_release_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->release_response = u_release_response.real;
      offset += sizeof(this->release_response);
      union {
        bool real;
        uint8_t base;
      } u_correct_response;
      u_correct_response.base = 0;
      u_correct_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->correct_response = u_correct_response.real;
      offset += sizeof(this->correct_response);
      union {
        bool real;
        uint8_t base;
      } u_resume_response;
      u_resume_response.base = 0;
      u_resume_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->resume_response = u_resume_response.real;
      offset += sizeof(this->resume_response);
      union {
        bool real;
        uint8_t base;
      } u_approach_handle_response;
      u_approach_handle_response.base = 0;
      u_approach_handle_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->approach_handle_response = u_approach_handle_response.real;
      offset += sizeof(this->approach_handle_response);
      union {
        bool real;
        uint8_t base;
      } u_approach_accel_response;
      u_approach_accel_response.base = 0;
      u_approach_accel_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->approach_accel_response = u_approach_accel_response.real;
      offset += sizeof(this->approach_accel_response);
      union {
        bool real;
        uint8_t base;
      } u_reach_arm_response;
      u_reach_arm_response.base = 0;
      u_reach_arm_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reach_arm_response = u_reach_arm_response.real;
      offset += sizeof(this->reach_arm_response);
      union {
        bool real;
        uint8_t base;
      } u_reach_leg_response;
      u_reach_leg_response.base = 0;
      u_reach_leg_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reach_leg_response = u_reach_leg_response.real;
      offset += sizeof(this->reach_leg_response);
      union {
        bool real;
        uint8_t base;
      } u_egress_response;
      u_egress_response.base = 0;
      u_egress_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->egress_response = u_egress_response.real;
      offset += sizeof(this->egress_response);
      union {
        bool real;
        uint8_t base;
      } u_set_max_step_response;
      u_set_max_step_response.base = 0;
      u_set_max_step_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_max_step_response = u_set_max_step_response.real;
      offset += sizeof(this->set_max_step_response);
      union {
        bool real;
        uint8_t base;
      } u_set_min_step_response;
      u_set_min_step_response.base = 0;
      u_set_min_step_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_min_step_response = u_set_min_step_response.real;
      offset += sizeof(this->set_min_step_response);
      union {
        bool real;
        uint8_t base;
      } u_set_detach_step_response;
      u_set_detach_step_response.base = 0;
      u_set_detach_step_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_detach_step_response = u_set_detach_step_response.real;
      offset += sizeof(this->set_detach_step_response);
      union {
        bool real;
        uint8_t base;
      } u_overwrite_handle_angle_response;
      u_overwrite_handle_angle_response.base = 0;
      u_overwrite_handle_angle_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->overwrite_handle_angle_response = u_overwrite_handle_angle_response.real;
      offset += sizeof(this->overwrite_handle_angle_response);
      union {
        bool real;
        uint8_t base;
      } u_set_real_response;
      u_set_real_response.base = 0;
      u_set_real_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_real_response = u_set_real_response.real;
      offset += sizeof(this->set_real_response);
      union {
        bool real;
        uint8_t base;
      } u_set_handle_mode_response;
      u_set_handle_mode_response.base = 0;
      u_set_handle_mode_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_handle_mode_response = u_set_handle_mode_response.real;
      offset += sizeof(this->set_handle_mode_response);
      union {
        bool real;
        uint8_t base;
      } u_set_accel_mode_response;
      u_set_accel_mode_response.base = 0;
      u_set_accel_mode_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_accel_mode_response = u_set_accel_mode_response.real;
      offset += sizeof(this->set_accel_mode_response);
      union {
        bool real;
        uint8_t base;
      } u_set_neck_mode_response;
      u_set_neck_mode_response.base = 0;
      u_set_neck_mode_response.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_neck_mode_response = u_set_neck_mode_response.real;
      offset += sizeof(this->set_neck_mode_response);
      union {
        float real;
        uint32_t base;
      } u_obstacle_length;
      u_obstacle_length.base = 0;
      u_obstacle_length.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obstacle_length.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obstacle_length.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obstacle_length.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obstacle_length = u_obstacle_length.real;
      offset += sizeof(this->obstacle_length);
     return offset;
    }

    const char * getType(){ return "drc_com_common/VehicleFC2OCSSmall"; };
    const char * getMD5(){ return "5fbd8465b764b214db7f5adbd315da4b"; };

  };

}
#endif