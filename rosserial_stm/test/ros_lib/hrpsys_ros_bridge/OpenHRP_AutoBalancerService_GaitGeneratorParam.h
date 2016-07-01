#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_GaitGeneratorParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_GaitGeneratorParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_GaitGeneratorParam : public ros::Msg
  {
    public:
      double default_step_time;
      double default_step_height;
      double default_double_support_ratio;
      double default_double_support_ratio_before;
      double default_double_support_ratio_after;
      double default_double_support_static_ratio;
      double default_double_support_static_ratio_before;
      double default_double_support_static_ratio_after;
      double default_double_support_ratio_swing_before;
      double default_double_support_ratio_swing_after;
      double stride_parameter[4];
      int64_t default_orbit_type;
      double swing_trajectory_delay_time_offset;
      double swing_trajectory_final_distance_weight;
      double stair_trajectory_way_point_offset[3];
      double cycloid_delay_kick_point_offset[3];
      double gravitational_acceleration;
      double toe_pos_offset_x;
      double heel_pos_offset_x;
      double toe_zmp_offset_x;
      double heel_zmp_offset_x;
      double toe_angle;
      double heel_angle;
      uint8_t toe_heel_phase_ratio_length;
      double st_toe_heel_phase_ratio;
      double * toe_heel_phase_ratio;
      bool use_toe_joint;
      bool use_toe_heel_transition;
      double zmp_weight_map[4];
      std_msgs::Float64MultiArray leg_default_translate_pos;
      int32_t optional_go_pos_finalize_footstep_num;
      int32_t overwritable_footstep_index_offset;

    OpenHRP_AutoBalancerService_GaitGeneratorParam():
      default_step_time(0),
      default_step_height(0),
      default_double_support_ratio(0),
      default_double_support_ratio_before(0),
      default_double_support_ratio_after(0),
      default_double_support_static_ratio(0),
      default_double_support_static_ratio_before(0),
      default_double_support_static_ratio_after(0),
      default_double_support_ratio_swing_before(0),
      default_double_support_ratio_swing_after(0),
      stride_parameter(),
      default_orbit_type(0),
      swing_trajectory_delay_time_offset(0),
      swing_trajectory_final_distance_weight(0),
      stair_trajectory_way_point_offset(),
      cycloid_delay_kick_point_offset(),
      gravitational_acceleration(0),
      toe_pos_offset_x(0),
      heel_pos_offset_x(0),
      toe_zmp_offset_x(0),
      heel_zmp_offset_x(0),
      toe_angle(0),
      heel_angle(0),
      toe_heel_phase_ratio_length(0), toe_heel_phase_ratio(NULL),
      use_toe_joint(0),
      use_toe_heel_transition(0),
      zmp_weight_map(),
      leg_default_translate_pos(),
      optional_go_pos_finalize_footstep_num(0),
      overwritable_footstep_index_offset(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_default_step_time;
      u_default_step_time.real = this->default_step_time;
      *(outbuffer + offset + 0) = (u_default_step_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_step_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_step_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_step_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_step_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_step_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_step_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_step_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_step_time);
      union {
        double real;
        uint64_t base;
      } u_default_step_height;
      u_default_step_height.real = this->default_step_height;
      *(outbuffer + offset + 0) = (u_default_step_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_step_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_step_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_step_height.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_step_height.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_step_height.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_step_height.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_step_height.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_step_height);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio;
      u_default_double_support_ratio.real = this->default_double_support_ratio;
      *(outbuffer + offset + 0) = (u_default_double_support_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_double_support_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_double_support_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_double_support_ratio.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_double_support_ratio.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_double_support_ratio.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_double_support_ratio.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_double_support_ratio.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_double_support_ratio);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio_before;
      u_default_double_support_ratio_before.real = this->default_double_support_ratio_before;
      *(outbuffer + offset + 0) = (u_default_double_support_ratio_before.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_double_support_ratio_before.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_double_support_ratio_before.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_double_support_ratio_before.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_double_support_ratio_before.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_double_support_ratio_before.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_double_support_ratio_before.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_double_support_ratio_before.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_double_support_ratio_before);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio_after;
      u_default_double_support_ratio_after.real = this->default_double_support_ratio_after;
      *(outbuffer + offset + 0) = (u_default_double_support_ratio_after.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_double_support_ratio_after.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_double_support_ratio_after.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_double_support_ratio_after.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_double_support_ratio_after.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_double_support_ratio_after.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_double_support_ratio_after.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_double_support_ratio_after.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_double_support_ratio_after);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_static_ratio;
      u_default_double_support_static_ratio.real = this->default_double_support_static_ratio;
      *(outbuffer + offset + 0) = (u_default_double_support_static_ratio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_double_support_static_ratio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_double_support_static_ratio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_double_support_static_ratio.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_double_support_static_ratio.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_double_support_static_ratio.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_double_support_static_ratio.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_double_support_static_ratio.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_double_support_static_ratio);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_static_ratio_before;
      u_default_double_support_static_ratio_before.real = this->default_double_support_static_ratio_before;
      *(outbuffer + offset + 0) = (u_default_double_support_static_ratio_before.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_double_support_static_ratio_before.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_double_support_static_ratio_before.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_double_support_static_ratio_before.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_double_support_static_ratio_before.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_double_support_static_ratio_before.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_double_support_static_ratio_before.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_double_support_static_ratio_before.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_double_support_static_ratio_before);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_static_ratio_after;
      u_default_double_support_static_ratio_after.real = this->default_double_support_static_ratio_after;
      *(outbuffer + offset + 0) = (u_default_double_support_static_ratio_after.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_double_support_static_ratio_after.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_double_support_static_ratio_after.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_double_support_static_ratio_after.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_double_support_static_ratio_after.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_double_support_static_ratio_after.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_double_support_static_ratio_after.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_double_support_static_ratio_after.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_double_support_static_ratio_after);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio_swing_before;
      u_default_double_support_ratio_swing_before.real = this->default_double_support_ratio_swing_before;
      *(outbuffer + offset + 0) = (u_default_double_support_ratio_swing_before.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_double_support_ratio_swing_before.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_double_support_ratio_swing_before.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_double_support_ratio_swing_before.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_double_support_ratio_swing_before.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_double_support_ratio_swing_before.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_double_support_ratio_swing_before.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_double_support_ratio_swing_before.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_double_support_ratio_swing_before);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio_swing_after;
      u_default_double_support_ratio_swing_after.real = this->default_double_support_ratio_swing_after;
      *(outbuffer + offset + 0) = (u_default_double_support_ratio_swing_after.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_double_support_ratio_swing_after.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_double_support_ratio_swing_after.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_double_support_ratio_swing_after.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_double_support_ratio_swing_after.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_double_support_ratio_swing_after.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_double_support_ratio_swing_after.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_double_support_ratio_swing_after.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_double_support_ratio_swing_after);
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_stride_parameteri;
      u_stride_parameteri.real = this->stride_parameter[i];
      *(outbuffer + offset + 0) = (u_stride_parameteri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stride_parameteri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stride_parameteri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stride_parameteri.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_stride_parameteri.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_stride_parameteri.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_stride_parameteri.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_stride_parameteri.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->stride_parameter[i]);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_default_orbit_type;
      u_default_orbit_type.real = this->default_orbit_type;
      *(outbuffer + offset + 0) = (u_default_orbit_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_orbit_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_orbit_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_orbit_type.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_orbit_type.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_orbit_type.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_orbit_type.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_orbit_type.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_orbit_type);
      union {
        double real;
        uint64_t base;
      } u_swing_trajectory_delay_time_offset;
      u_swing_trajectory_delay_time_offset.real = this->swing_trajectory_delay_time_offset;
      *(outbuffer + offset + 0) = (u_swing_trajectory_delay_time_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_swing_trajectory_delay_time_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_swing_trajectory_delay_time_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_swing_trajectory_delay_time_offset.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_swing_trajectory_delay_time_offset.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_swing_trajectory_delay_time_offset.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_swing_trajectory_delay_time_offset.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_swing_trajectory_delay_time_offset.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->swing_trajectory_delay_time_offset);
      union {
        double real;
        uint64_t base;
      } u_swing_trajectory_final_distance_weight;
      u_swing_trajectory_final_distance_weight.real = this->swing_trajectory_final_distance_weight;
      *(outbuffer + offset + 0) = (u_swing_trajectory_final_distance_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_swing_trajectory_final_distance_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_swing_trajectory_final_distance_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_swing_trajectory_final_distance_weight.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_swing_trajectory_final_distance_weight.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_swing_trajectory_final_distance_weight.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_swing_trajectory_final_distance_weight.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_swing_trajectory_final_distance_weight.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->swing_trajectory_final_distance_weight);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_stair_trajectory_way_point_offseti;
      u_stair_trajectory_way_point_offseti.real = this->stair_trajectory_way_point_offset[i];
      *(outbuffer + offset + 0) = (u_stair_trajectory_way_point_offseti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stair_trajectory_way_point_offseti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stair_trajectory_way_point_offseti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stair_trajectory_way_point_offseti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_stair_trajectory_way_point_offseti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_stair_trajectory_way_point_offseti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_stair_trajectory_way_point_offseti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_stair_trajectory_way_point_offseti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->stair_trajectory_way_point_offset[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_cycloid_delay_kick_point_offseti;
      u_cycloid_delay_kick_point_offseti.real = this->cycloid_delay_kick_point_offset[i];
      *(outbuffer + offset + 0) = (u_cycloid_delay_kick_point_offseti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cycloid_delay_kick_point_offseti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cycloid_delay_kick_point_offseti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cycloid_delay_kick_point_offseti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cycloid_delay_kick_point_offseti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cycloid_delay_kick_point_offseti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cycloid_delay_kick_point_offseti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cycloid_delay_kick_point_offseti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cycloid_delay_kick_point_offset[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_gravitational_acceleration;
      u_gravitational_acceleration.real = this->gravitational_acceleration;
      *(outbuffer + offset + 0) = (u_gravitational_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gravitational_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gravitational_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gravitational_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_gravitational_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_gravitational_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_gravitational_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_gravitational_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->gravitational_acceleration);
      union {
        double real;
        uint64_t base;
      } u_toe_pos_offset_x;
      u_toe_pos_offset_x.real = this->toe_pos_offset_x;
      *(outbuffer + offset + 0) = (u_toe_pos_offset_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_toe_pos_offset_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_toe_pos_offset_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_toe_pos_offset_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_toe_pos_offset_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_toe_pos_offset_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_toe_pos_offset_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_toe_pos_offset_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->toe_pos_offset_x);
      union {
        double real;
        uint64_t base;
      } u_heel_pos_offset_x;
      u_heel_pos_offset_x.real = this->heel_pos_offset_x;
      *(outbuffer + offset + 0) = (u_heel_pos_offset_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heel_pos_offset_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heel_pos_offset_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heel_pos_offset_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heel_pos_offset_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heel_pos_offset_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heel_pos_offset_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heel_pos_offset_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heel_pos_offset_x);
      union {
        double real;
        uint64_t base;
      } u_toe_zmp_offset_x;
      u_toe_zmp_offset_x.real = this->toe_zmp_offset_x;
      *(outbuffer + offset + 0) = (u_toe_zmp_offset_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_toe_zmp_offset_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_toe_zmp_offset_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_toe_zmp_offset_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_toe_zmp_offset_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_toe_zmp_offset_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_toe_zmp_offset_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_toe_zmp_offset_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->toe_zmp_offset_x);
      union {
        double real;
        uint64_t base;
      } u_heel_zmp_offset_x;
      u_heel_zmp_offset_x.real = this->heel_zmp_offset_x;
      *(outbuffer + offset + 0) = (u_heel_zmp_offset_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heel_zmp_offset_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heel_zmp_offset_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heel_zmp_offset_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heel_zmp_offset_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heel_zmp_offset_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heel_zmp_offset_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heel_zmp_offset_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heel_zmp_offset_x);
      union {
        double real;
        uint64_t base;
      } u_toe_angle;
      u_toe_angle.real = this->toe_angle;
      *(outbuffer + offset + 0) = (u_toe_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_toe_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_toe_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_toe_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_toe_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_toe_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_toe_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_toe_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->toe_angle);
      union {
        double real;
        uint64_t base;
      } u_heel_angle;
      u_heel_angle.real = this->heel_angle;
      *(outbuffer + offset + 0) = (u_heel_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_heel_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_heel_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_heel_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_heel_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_heel_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_heel_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_heel_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->heel_angle);
      *(outbuffer + offset++) = toe_heel_phase_ratio_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < toe_heel_phase_ratio_length; i++){
      union {
        double real;
        uint64_t base;
      } u_toe_heel_phase_ratioi;
      u_toe_heel_phase_ratioi.real = this->toe_heel_phase_ratio[i];
      *(outbuffer + offset + 0) = (u_toe_heel_phase_ratioi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_toe_heel_phase_ratioi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_toe_heel_phase_ratioi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_toe_heel_phase_ratioi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_toe_heel_phase_ratioi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_toe_heel_phase_ratioi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_toe_heel_phase_ratioi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_toe_heel_phase_ratioi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->toe_heel_phase_ratio[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_toe_joint;
      u_use_toe_joint.real = this->use_toe_joint;
      *(outbuffer + offset + 0) = (u_use_toe_joint.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_toe_joint);
      union {
        bool real;
        uint8_t base;
      } u_use_toe_heel_transition;
      u_use_toe_heel_transition.real = this->use_toe_heel_transition;
      *(outbuffer + offset + 0) = (u_use_toe_heel_transition.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_toe_heel_transition);
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_zmp_weight_mapi;
      u_zmp_weight_mapi.real = this->zmp_weight_map[i];
      *(outbuffer + offset + 0) = (u_zmp_weight_mapi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zmp_weight_mapi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zmp_weight_mapi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zmp_weight_mapi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_zmp_weight_mapi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_zmp_weight_mapi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_zmp_weight_mapi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_zmp_weight_mapi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->zmp_weight_map[i]);
      }
      offset += this->leg_default_translate_pos.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_optional_go_pos_finalize_footstep_num;
      u_optional_go_pos_finalize_footstep_num.real = this->optional_go_pos_finalize_footstep_num;
      *(outbuffer + offset + 0) = (u_optional_go_pos_finalize_footstep_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_optional_go_pos_finalize_footstep_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_optional_go_pos_finalize_footstep_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_optional_go_pos_finalize_footstep_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->optional_go_pos_finalize_footstep_num);
      union {
        int32_t real;
        uint32_t base;
      } u_overwritable_footstep_index_offset;
      u_overwritable_footstep_index_offset.real = this->overwritable_footstep_index_offset;
      *(outbuffer + offset + 0) = (u_overwritable_footstep_index_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_overwritable_footstep_index_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_overwritable_footstep_index_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_overwritable_footstep_index_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->overwritable_footstep_index_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_default_step_time;
      u_default_step_time.base = 0;
      u_default_step_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_step_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_step_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_step_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_step_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_step_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_step_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_step_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_step_time = u_default_step_time.real;
      offset += sizeof(this->default_step_time);
      union {
        double real;
        uint64_t base;
      } u_default_step_height;
      u_default_step_height.base = 0;
      u_default_step_height.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_step_height.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_step_height.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_step_height.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_step_height.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_step_height.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_step_height.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_step_height.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_step_height = u_default_step_height.real;
      offset += sizeof(this->default_step_height);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio;
      u_default_double_support_ratio.base = 0;
      u_default_double_support_ratio.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_double_support_ratio.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_double_support_ratio.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_double_support_ratio.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_double_support_ratio.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_double_support_ratio.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_double_support_ratio.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_double_support_ratio.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_double_support_ratio = u_default_double_support_ratio.real;
      offset += sizeof(this->default_double_support_ratio);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio_before;
      u_default_double_support_ratio_before.base = 0;
      u_default_double_support_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_double_support_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_double_support_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_double_support_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_double_support_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_double_support_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_double_support_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_double_support_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_double_support_ratio_before = u_default_double_support_ratio_before.real;
      offset += sizeof(this->default_double_support_ratio_before);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio_after;
      u_default_double_support_ratio_after.base = 0;
      u_default_double_support_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_double_support_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_double_support_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_double_support_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_double_support_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_double_support_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_double_support_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_double_support_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_double_support_ratio_after = u_default_double_support_ratio_after.real;
      offset += sizeof(this->default_double_support_ratio_after);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_static_ratio;
      u_default_double_support_static_ratio.base = 0;
      u_default_double_support_static_ratio.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_double_support_static_ratio.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_double_support_static_ratio.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_double_support_static_ratio.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_double_support_static_ratio.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_double_support_static_ratio.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_double_support_static_ratio.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_double_support_static_ratio.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_double_support_static_ratio = u_default_double_support_static_ratio.real;
      offset += sizeof(this->default_double_support_static_ratio);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_static_ratio_before;
      u_default_double_support_static_ratio_before.base = 0;
      u_default_double_support_static_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_double_support_static_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_double_support_static_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_double_support_static_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_double_support_static_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_double_support_static_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_double_support_static_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_double_support_static_ratio_before.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_double_support_static_ratio_before = u_default_double_support_static_ratio_before.real;
      offset += sizeof(this->default_double_support_static_ratio_before);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_static_ratio_after;
      u_default_double_support_static_ratio_after.base = 0;
      u_default_double_support_static_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_double_support_static_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_double_support_static_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_double_support_static_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_double_support_static_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_double_support_static_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_double_support_static_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_double_support_static_ratio_after.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_double_support_static_ratio_after = u_default_double_support_static_ratio_after.real;
      offset += sizeof(this->default_double_support_static_ratio_after);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio_swing_before;
      u_default_double_support_ratio_swing_before.base = 0;
      u_default_double_support_ratio_swing_before.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_double_support_ratio_swing_before.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_double_support_ratio_swing_before.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_double_support_ratio_swing_before.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_double_support_ratio_swing_before.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_double_support_ratio_swing_before.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_double_support_ratio_swing_before.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_double_support_ratio_swing_before.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_double_support_ratio_swing_before = u_default_double_support_ratio_swing_before.real;
      offset += sizeof(this->default_double_support_ratio_swing_before);
      union {
        double real;
        uint64_t base;
      } u_default_double_support_ratio_swing_after;
      u_default_double_support_ratio_swing_after.base = 0;
      u_default_double_support_ratio_swing_after.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_double_support_ratio_swing_after.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_double_support_ratio_swing_after.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_double_support_ratio_swing_after.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_double_support_ratio_swing_after.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_double_support_ratio_swing_after.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_double_support_ratio_swing_after.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_double_support_ratio_swing_after.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_double_support_ratio_swing_after = u_default_double_support_ratio_swing_after.real;
      offset += sizeof(this->default_double_support_ratio_swing_after);
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_stride_parameteri;
      u_stride_parameteri.base = 0;
      u_stride_parameteri.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stride_parameteri.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stride_parameteri.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stride_parameteri.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_stride_parameteri.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_stride_parameteri.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_stride_parameteri.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_stride_parameteri.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->stride_parameter[i] = u_stride_parameteri.real;
      offset += sizeof(this->stride_parameter[i]);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_default_orbit_type;
      u_default_orbit_type.base = 0;
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_orbit_type.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_orbit_type = u_default_orbit_type.real;
      offset += sizeof(this->default_orbit_type);
      union {
        double real;
        uint64_t base;
      } u_swing_trajectory_delay_time_offset;
      u_swing_trajectory_delay_time_offset.base = 0;
      u_swing_trajectory_delay_time_offset.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_swing_trajectory_delay_time_offset.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_swing_trajectory_delay_time_offset.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_swing_trajectory_delay_time_offset.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_swing_trajectory_delay_time_offset.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_swing_trajectory_delay_time_offset.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_swing_trajectory_delay_time_offset.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_swing_trajectory_delay_time_offset.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->swing_trajectory_delay_time_offset = u_swing_trajectory_delay_time_offset.real;
      offset += sizeof(this->swing_trajectory_delay_time_offset);
      union {
        double real;
        uint64_t base;
      } u_swing_trajectory_final_distance_weight;
      u_swing_trajectory_final_distance_weight.base = 0;
      u_swing_trajectory_final_distance_weight.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_swing_trajectory_final_distance_weight.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_swing_trajectory_final_distance_weight.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_swing_trajectory_final_distance_weight.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_swing_trajectory_final_distance_weight.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_swing_trajectory_final_distance_weight.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_swing_trajectory_final_distance_weight.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_swing_trajectory_final_distance_weight.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->swing_trajectory_final_distance_weight = u_swing_trajectory_final_distance_weight.real;
      offset += sizeof(this->swing_trajectory_final_distance_weight);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_stair_trajectory_way_point_offseti;
      u_stair_trajectory_way_point_offseti.base = 0;
      u_stair_trajectory_way_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stair_trajectory_way_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stair_trajectory_way_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stair_trajectory_way_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_stair_trajectory_way_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_stair_trajectory_way_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_stair_trajectory_way_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_stair_trajectory_way_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->stair_trajectory_way_point_offset[i] = u_stair_trajectory_way_point_offseti.real;
      offset += sizeof(this->stair_trajectory_way_point_offset[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_cycloid_delay_kick_point_offseti;
      u_cycloid_delay_kick_point_offseti.base = 0;
      u_cycloid_delay_kick_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cycloid_delay_kick_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cycloid_delay_kick_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cycloid_delay_kick_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_cycloid_delay_kick_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_cycloid_delay_kick_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_cycloid_delay_kick_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_cycloid_delay_kick_point_offseti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->cycloid_delay_kick_point_offset[i] = u_cycloid_delay_kick_point_offseti.real;
      offset += sizeof(this->cycloid_delay_kick_point_offset[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_gravitational_acceleration;
      u_gravitational_acceleration.base = 0;
      u_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->gravitational_acceleration = u_gravitational_acceleration.real;
      offset += sizeof(this->gravitational_acceleration);
      union {
        double real;
        uint64_t base;
      } u_toe_pos_offset_x;
      u_toe_pos_offset_x.base = 0;
      u_toe_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_toe_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_toe_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_toe_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_toe_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_toe_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_toe_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_toe_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->toe_pos_offset_x = u_toe_pos_offset_x.real;
      offset += sizeof(this->toe_pos_offset_x);
      union {
        double real;
        uint64_t base;
      } u_heel_pos_offset_x;
      u_heel_pos_offset_x.base = 0;
      u_heel_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heel_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heel_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heel_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heel_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heel_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heel_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heel_pos_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heel_pos_offset_x = u_heel_pos_offset_x.real;
      offset += sizeof(this->heel_pos_offset_x);
      union {
        double real;
        uint64_t base;
      } u_toe_zmp_offset_x;
      u_toe_zmp_offset_x.base = 0;
      u_toe_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_toe_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_toe_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_toe_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_toe_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_toe_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_toe_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_toe_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->toe_zmp_offset_x = u_toe_zmp_offset_x.real;
      offset += sizeof(this->toe_zmp_offset_x);
      union {
        double real;
        uint64_t base;
      } u_heel_zmp_offset_x;
      u_heel_zmp_offset_x.base = 0;
      u_heel_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heel_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heel_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heel_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heel_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heel_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heel_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heel_zmp_offset_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heel_zmp_offset_x = u_heel_zmp_offset_x.real;
      offset += sizeof(this->heel_zmp_offset_x);
      union {
        double real;
        uint64_t base;
      } u_toe_angle;
      u_toe_angle.base = 0;
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_toe_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->toe_angle = u_toe_angle.real;
      offset += sizeof(this->toe_angle);
      union {
        double real;
        uint64_t base;
      } u_heel_angle;
      u_heel_angle.base = 0;
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_heel_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->heel_angle = u_heel_angle.real;
      offset += sizeof(this->heel_angle);
      uint8_t toe_heel_phase_ratio_lengthT = *(inbuffer + offset++);
      if(toe_heel_phase_ratio_lengthT > toe_heel_phase_ratio_length)
        this->toe_heel_phase_ratio = (double*)realloc(this->toe_heel_phase_ratio, toe_heel_phase_ratio_lengthT * sizeof(double));
      offset += 3;
      toe_heel_phase_ratio_length = toe_heel_phase_ratio_lengthT;
      for( uint8_t i = 0; i < toe_heel_phase_ratio_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_toe_heel_phase_ratio;
      u_st_toe_heel_phase_ratio.base = 0;
      u_st_toe_heel_phase_ratio.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_toe_heel_phase_ratio.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_toe_heel_phase_ratio.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_toe_heel_phase_ratio.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_toe_heel_phase_ratio.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_toe_heel_phase_ratio.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_toe_heel_phase_ratio.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_toe_heel_phase_ratio.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_toe_heel_phase_ratio = u_st_toe_heel_phase_ratio.real;
      offset += sizeof(this->st_toe_heel_phase_ratio);
        memcpy( &(this->toe_heel_phase_ratio[i]), &(this->st_toe_heel_phase_ratio), sizeof(double));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_toe_joint;
      u_use_toe_joint.base = 0;
      u_use_toe_joint.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_toe_joint = u_use_toe_joint.real;
      offset += sizeof(this->use_toe_joint);
      union {
        bool real;
        uint8_t base;
      } u_use_toe_heel_transition;
      u_use_toe_heel_transition.base = 0;
      u_use_toe_heel_transition.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_toe_heel_transition = u_use_toe_heel_transition.real;
      offset += sizeof(this->use_toe_heel_transition);
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_zmp_weight_mapi;
      u_zmp_weight_mapi.base = 0;
      u_zmp_weight_mapi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zmp_weight_mapi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zmp_weight_mapi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zmp_weight_mapi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_zmp_weight_mapi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_zmp_weight_mapi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_zmp_weight_mapi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_zmp_weight_mapi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->zmp_weight_map[i] = u_zmp_weight_mapi.real;
      offset += sizeof(this->zmp_weight_map[i]);
      }
      offset += this->leg_default_translate_pos.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_optional_go_pos_finalize_footstep_num;
      u_optional_go_pos_finalize_footstep_num.base = 0;
      u_optional_go_pos_finalize_footstep_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_optional_go_pos_finalize_footstep_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_optional_go_pos_finalize_footstep_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_optional_go_pos_finalize_footstep_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->optional_go_pos_finalize_footstep_num = u_optional_go_pos_finalize_footstep_num.real;
      offset += sizeof(this->optional_go_pos_finalize_footstep_num);
      union {
        int32_t real;
        uint32_t base;
      } u_overwritable_footstep_index_offset;
      u_overwritable_footstep_index_offset.base = 0;
      u_overwritable_footstep_index_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_overwritable_footstep_index_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_overwritable_footstep_index_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_overwritable_footstep_index_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->overwritable_footstep_index_offset = u_overwritable_footstep_index_offset.real;
      offset += sizeof(this->overwritable_footstep_index_offset);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_GaitGeneratorParam"; };
    const char * getMD5(){ return "ca699d530dda28890de99b67f2d3d408"; };

  };

}
#endif