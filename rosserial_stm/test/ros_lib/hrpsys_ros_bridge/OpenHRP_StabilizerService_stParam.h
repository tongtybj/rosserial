#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_stParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_stParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_SupportPolygonVertices.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_IKLimbParameters.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_stParam : public ros::Msg
  {
    public:
      double k_tpcc_p[2];
      double k_tpcc_x[2];
      double k_brot_p[2];
      double k_brot_tc[2];
      double eefm_k1[2];
      double eefm_k2[2];
      double eefm_k3[2];
      double eefm_zmp_delay_time_const[2];
      double eefm_ref_zmp_aux[2];
      std_msgs::Float64MultiArray eefm_rot_damping_gain;
      std_msgs::Float64MultiArray eefm_rot_time_const;
      std_msgs::Float64MultiArray eefm_pos_damping_gain;
      std_msgs::Float64MultiArray eefm_pos_time_const_support;
      std_msgs::Float64MultiArray eefm_swing_rot_spring_gain;
      std_msgs::Float64MultiArray eefm_swing_rot_time_const;
      std_msgs::Float64MultiArray eefm_swing_pos_spring_gain;
      std_msgs::Float64MultiArray eefm_swing_pos_time_const;
      std_msgs::Float64MultiArray eefm_ee_moment_limit;
      uint8_t eefm_pos_compensation_limit_length;
      double st_eefm_pos_compensation_limit;
      double * eefm_pos_compensation_limit;
      uint8_t eefm_rot_compensation_limit_length;
      double st_eefm_rot_compensation_limit;
      double * eefm_rot_compensation_limit;
      double eefm_pos_time_const_swing;
      double eefm_pos_transition_time;
      double eefm_pos_margin_time;
      double eefm_leg_inside_margin;
      double eefm_leg_outside_margin;
      double eefm_leg_front_margin;
      double eefm_leg_rear_margin;
      double eefm_body_attitude_control_gain[2];
      double eefm_body_attitude_control_time_const[2];
      double eefm_cogvel_cutoff_freq;
      double eefm_wrench_alpha_blending;
      double eefm_alpha_cutoff_freq;
      double eefm_gravitational_acceleration;
      double eefm_ee_pos_error_p_gain;
      double eefm_ee_rot_error_p_gain;
      double eefm_ee_error_cutoff_freq;
      uint8_t eefm_support_polygon_vertices_sequence_length;
      hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices st_eefm_support_polygon_vertices_sequence;
      hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices * eefm_support_polygon_vertices_sequence;
      bool eefm_use_force_difference_control;
      int64_t st_algorithm;
      int64_t controller_mode;
      double transition_time;
      uint8_t is_ik_enable_length;
      bool st_is_ik_enable;
      bool * is_ik_enable;
      uint8_t is_feedback_control_enable_length;
      bool st_is_feedback_control_enable;
      bool * is_feedback_control_enable;
      uint8_t is_zmp_calc_enable_length;
      bool st_is_zmp_calc_enable;
      bool * is_zmp_calc_enable;
      double cop_check_margin;
      double cp_check_margin[4];
      double tilt_margin[2];
      double ref_capture_point[2];
      double act_capture_point[2];
      double contact_decision_threshold;
      std_msgs::Float64MultiArray foot_origin_offset;
      int64_t emergency_check_mode;
      uint8_t end_effector_list_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep st_end_effector_list;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep * end_effector_list;
      bool is_estop_while_walking;
      uint8_t ik_limb_parameters_length;
      hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters st_ik_limb_parameters;
      hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters * ik_limb_parameters;

    OpenHRP_StabilizerService_stParam():
      k_tpcc_p(),
      k_tpcc_x(),
      k_brot_p(),
      k_brot_tc(),
      eefm_k1(),
      eefm_k2(),
      eefm_k3(),
      eefm_zmp_delay_time_const(),
      eefm_ref_zmp_aux(),
      eefm_rot_damping_gain(),
      eefm_rot_time_const(),
      eefm_pos_damping_gain(),
      eefm_pos_time_const_support(),
      eefm_swing_rot_spring_gain(),
      eefm_swing_rot_time_const(),
      eefm_swing_pos_spring_gain(),
      eefm_swing_pos_time_const(),
      eefm_ee_moment_limit(),
      eefm_pos_compensation_limit_length(0), eefm_pos_compensation_limit(NULL),
      eefm_rot_compensation_limit_length(0), eefm_rot_compensation_limit(NULL),
      eefm_pos_time_const_swing(0),
      eefm_pos_transition_time(0),
      eefm_pos_margin_time(0),
      eefm_leg_inside_margin(0),
      eefm_leg_outside_margin(0),
      eefm_leg_front_margin(0),
      eefm_leg_rear_margin(0),
      eefm_body_attitude_control_gain(),
      eefm_body_attitude_control_time_const(),
      eefm_cogvel_cutoff_freq(0),
      eefm_wrench_alpha_blending(0),
      eefm_alpha_cutoff_freq(0),
      eefm_gravitational_acceleration(0),
      eefm_ee_pos_error_p_gain(0),
      eefm_ee_rot_error_p_gain(0),
      eefm_ee_error_cutoff_freq(0),
      eefm_support_polygon_vertices_sequence_length(0), eefm_support_polygon_vertices_sequence(NULL),
      eefm_use_force_difference_control(0),
      st_algorithm(0),
      controller_mode(0),
      transition_time(0),
      is_ik_enable_length(0), is_ik_enable(NULL),
      is_feedback_control_enable_length(0), is_feedback_control_enable(NULL),
      is_zmp_calc_enable_length(0), is_zmp_calc_enable(NULL),
      cop_check_margin(0),
      cp_check_margin(),
      tilt_margin(),
      ref_capture_point(),
      act_capture_point(),
      contact_decision_threshold(0),
      foot_origin_offset(),
      emergency_check_mode(0),
      end_effector_list_length(0), end_effector_list(NULL),
      is_estop_while_walking(0),
      ik_limb_parameters_length(0), ik_limb_parameters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_k_tpcc_pi;
      u_k_tpcc_pi.real = this->k_tpcc_p[i];
      *(outbuffer + offset + 0) = (u_k_tpcc_pi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_tpcc_pi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_k_tpcc_pi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_k_tpcc_pi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_k_tpcc_pi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_k_tpcc_pi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_k_tpcc_pi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_k_tpcc_pi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->k_tpcc_p[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_k_tpcc_xi;
      u_k_tpcc_xi.real = this->k_tpcc_x[i];
      *(outbuffer + offset + 0) = (u_k_tpcc_xi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_tpcc_xi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_k_tpcc_xi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_k_tpcc_xi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_k_tpcc_xi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_k_tpcc_xi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_k_tpcc_xi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_k_tpcc_xi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->k_tpcc_x[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_k_brot_pi;
      u_k_brot_pi.real = this->k_brot_p[i];
      *(outbuffer + offset + 0) = (u_k_brot_pi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_brot_pi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_k_brot_pi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_k_brot_pi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_k_brot_pi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_k_brot_pi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_k_brot_pi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_k_brot_pi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->k_brot_p[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_k_brot_tci;
      u_k_brot_tci.real = this->k_brot_tc[i];
      *(outbuffer + offset + 0) = (u_k_brot_tci.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_k_brot_tci.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_k_brot_tci.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_k_brot_tci.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_k_brot_tci.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_k_brot_tci.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_k_brot_tci.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_k_brot_tci.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->k_brot_tc[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_k1i;
      u_eefm_k1i.real = this->eefm_k1[i];
      *(outbuffer + offset + 0) = (u_eefm_k1i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_k1i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_k1i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_k1i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_k1i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_k1i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_k1i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_k1i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_k1[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_k2i;
      u_eefm_k2i.real = this->eefm_k2[i];
      *(outbuffer + offset + 0) = (u_eefm_k2i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_k2i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_k2i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_k2i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_k2i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_k2i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_k2i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_k2i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_k2[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_k3i;
      u_eefm_k3i.real = this->eefm_k3[i];
      *(outbuffer + offset + 0) = (u_eefm_k3i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_k3i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_k3i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_k3i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_k3i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_k3i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_k3i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_k3i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_k3[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_zmp_delay_time_consti;
      u_eefm_zmp_delay_time_consti.real = this->eefm_zmp_delay_time_const[i];
      *(outbuffer + offset + 0) = (u_eefm_zmp_delay_time_consti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_zmp_delay_time_consti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_zmp_delay_time_consti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_zmp_delay_time_consti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_zmp_delay_time_consti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_zmp_delay_time_consti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_zmp_delay_time_consti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_zmp_delay_time_consti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_zmp_delay_time_const[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_ref_zmp_auxi;
      u_eefm_ref_zmp_auxi.real = this->eefm_ref_zmp_aux[i];
      *(outbuffer + offset + 0) = (u_eefm_ref_zmp_auxi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_ref_zmp_auxi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_ref_zmp_auxi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_ref_zmp_auxi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_ref_zmp_auxi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_ref_zmp_auxi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_ref_zmp_auxi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_ref_zmp_auxi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_ref_zmp_aux[i]);
      }
      offset += this->eefm_rot_damping_gain.serialize(outbuffer + offset);
      offset += this->eefm_rot_time_const.serialize(outbuffer + offset);
      offset += this->eefm_pos_damping_gain.serialize(outbuffer + offset);
      offset += this->eefm_pos_time_const_support.serialize(outbuffer + offset);
      offset += this->eefm_swing_rot_spring_gain.serialize(outbuffer + offset);
      offset += this->eefm_swing_rot_time_const.serialize(outbuffer + offset);
      offset += this->eefm_swing_pos_spring_gain.serialize(outbuffer + offset);
      offset += this->eefm_swing_pos_time_const.serialize(outbuffer + offset);
      offset += this->eefm_ee_moment_limit.serialize(outbuffer + offset);
      *(outbuffer + offset++) = eefm_pos_compensation_limit_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < eefm_pos_compensation_limit_length; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_pos_compensation_limiti;
      u_eefm_pos_compensation_limiti.real = this->eefm_pos_compensation_limit[i];
      *(outbuffer + offset + 0) = (u_eefm_pos_compensation_limiti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_pos_compensation_limiti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_pos_compensation_limiti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_pos_compensation_limiti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_pos_compensation_limiti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_pos_compensation_limiti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_pos_compensation_limiti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_pos_compensation_limiti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_pos_compensation_limit[i]);
      }
      *(outbuffer + offset++) = eefm_rot_compensation_limit_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < eefm_rot_compensation_limit_length; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_rot_compensation_limiti;
      u_eefm_rot_compensation_limiti.real = this->eefm_rot_compensation_limit[i];
      *(outbuffer + offset + 0) = (u_eefm_rot_compensation_limiti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_rot_compensation_limiti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_rot_compensation_limiti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_rot_compensation_limiti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_rot_compensation_limiti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_rot_compensation_limiti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_rot_compensation_limiti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_rot_compensation_limiti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_rot_compensation_limit[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_eefm_pos_time_const_swing;
      u_eefm_pos_time_const_swing.real = this->eefm_pos_time_const_swing;
      *(outbuffer + offset + 0) = (u_eefm_pos_time_const_swing.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_pos_time_const_swing.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_pos_time_const_swing.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_pos_time_const_swing.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_pos_time_const_swing.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_pos_time_const_swing.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_pos_time_const_swing.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_pos_time_const_swing.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_pos_time_const_swing);
      union {
        double real;
        uint64_t base;
      } u_eefm_pos_transition_time;
      u_eefm_pos_transition_time.real = this->eefm_pos_transition_time;
      *(outbuffer + offset + 0) = (u_eefm_pos_transition_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_pos_transition_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_pos_transition_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_pos_transition_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_pos_transition_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_pos_transition_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_pos_transition_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_pos_transition_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_pos_transition_time);
      union {
        double real;
        uint64_t base;
      } u_eefm_pos_margin_time;
      u_eefm_pos_margin_time.real = this->eefm_pos_margin_time;
      *(outbuffer + offset + 0) = (u_eefm_pos_margin_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_pos_margin_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_pos_margin_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_pos_margin_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_pos_margin_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_pos_margin_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_pos_margin_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_pos_margin_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_pos_margin_time);
      union {
        double real;
        uint64_t base;
      } u_eefm_leg_inside_margin;
      u_eefm_leg_inside_margin.real = this->eefm_leg_inside_margin;
      *(outbuffer + offset + 0) = (u_eefm_leg_inside_margin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_leg_inside_margin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_leg_inside_margin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_leg_inside_margin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_leg_inside_margin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_leg_inside_margin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_leg_inside_margin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_leg_inside_margin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_leg_inside_margin);
      union {
        double real;
        uint64_t base;
      } u_eefm_leg_outside_margin;
      u_eefm_leg_outside_margin.real = this->eefm_leg_outside_margin;
      *(outbuffer + offset + 0) = (u_eefm_leg_outside_margin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_leg_outside_margin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_leg_outside_margin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_leg_outside_margin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_leg_outside_margin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_leg_outside_margin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_leg_outside_margin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_leg_outside_margin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_leg_outside_margin);
      union {
        double real;
        uint64_t base;
      } u_eefm_leg_front_margin;
      u_eefm_leg_front_margin.real = this->eefm_leg_front_margin;
      *(outbuffer + offset + 0) = (u_eefm_leg_front_margin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_leg_front_margin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_leg_front_margin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_leg_front_margin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_leg_front_margin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_leg_front_margin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_leg_front_margin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_leg_front_margin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_leg_front_margin);
      union {
        double real;
        uint64_t base;
      } u_eefm_leg_rear_margin;
      u_eefm_leg_rear_margin.real = this->eefm_leg_rear_margin;
      *(outbuffer + offset + 0) = (u_eefm_leg_rear_margin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_leg_rear_margin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_leg_rear_margin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_leg_rear_margin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_leg_rear_margin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_leg_rear_margin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_leg_rear_margin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_leg_rear_margin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_leg_rear_margin);
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_body_attitude_control_gaini;
      u_eefm_body_attitude_control_gaini.real = this->eefm_body_attitude_control_gain[i];
      *(outbuffer + offset + 0) = (u_eefm_body_attitude_control_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_body_attitude_control_gaini.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_body_attitude_control_gaini.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_body_attitude_control_gaini.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_body_attitude_control_gaini.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_body_attitude_control_gaini.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_body_attitude_control_gaini.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_body_attitude_control_gaini.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_body_attitude_control_gain[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_body_attitude_control_time_consti;
      u_eefm_body_attitude_control_time_consti.real = this->eefm_body_attitude_control_time_const[i];
      *(outbuffer + offset + 0) = (u_eefm_body_attitude_control_time_consti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_body_attitude_control_time_consti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_body_attitude_control_time_consti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_body_attitude_control_time_consti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_body_attitude_control_time_consti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_body_attitude_control_time_consti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_body_attitude_control_time_consti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_body_attitude_control_time_consti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_body_attitude_control_time_const[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_eefm_cogvel_cutoff_freq;
      u_eefm_cogvel_cutoff_freq.real = this->eefm_cogvel_cutoff_freq;
      *(outbuffer + offset + 0) = (u_eefm_cogvel_cutoff_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_cogvel_cutoff_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_cogvel_cutoff_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_cogvel_cutoff_freq.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_cogvel_cutoff_freq.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_cogvel_cutoff_freq.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_cogvel_cutoff_freq.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_cogvel_cutoff_freq.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_cogvel_cutoff_freq);
      union {
        double real;
        uint64_t base;
      } u_eefm_wrench_alpha_blending;
      u_eefm_wrench_alpha_blending.real = this->eefm_wrench_alpha_blending;
      *(outbuffer + offset + 0) = (u_eefm_wrench_alpha_blending.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_wrench_alpha_blending.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_wrench_alpha_blending.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_wrench_alpha_blending.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_wrench_alpha_blending.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_wrench_alpha_blending.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_wrench_alpha_blending.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_wrench_alpha_blending.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_wrench_alpha_blending);
      union {
        double real;
        uint64_t base;
      } u_eefm_alpha_cutoff_freq;
      u_eefm_alpha_cutoff_freq.real = this->eefm_alpha_cutoff_freq;
      *(outbuffer + offset + 0) = (u_eefm_alpha_cutoff_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_alpha_cutoff_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_alpha_cutoff_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_alpha_cutoff_freq.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_alpha_cutoff_freq.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_alpha_cutoff_freq.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_alpha_cutoff_freq.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_alpha_cutoff_freq.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_alpha_cutoff_freq);
      union {
        double real;
        uint64_t base;
      } u_eefm_gravitational_acceleration;
      u_eefm_gravitational_acceleration.real = this->eefm_gravitational_acceleration;
      *(outbuffer + offset + 0) = (u_eefm_gravitational_acceleration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_gravitational_acceleration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_gravitational_acceleration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_gravitational_acceleration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_gravitational_acceleration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_gravitational_acceleration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_gravitational_acceleration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_gravitational_acceleration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_gravitational_acceleration);
      union {
        double real;
        uint64_t base;
      } u_eefm_ee_pos_error_p_gain;
      u_eefm_ee_pos_error_p_gain.real = this->eefm_ee_pos_error_p_gain;
      *(outbuffer + offset + 0) = (u_eefm_ee_pos_error_p_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_ee_pos_error_p_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_ee_pos_error_p_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_ee_pos_error_p_gain.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_ee_pos_error_p_gain.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_ee_pos_error_p_gain.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_ee_pos_error_p_gain.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_ee_pos_error_p_gain.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_ee_pos_error_p_gain);
      union {
        double real;
        uint64_t base;
      } u_eefm_ee_rot_error_p_gain;
      u_eefm_ee_rot_error_p_gain.real = this->eefm_ee_rot_error_p_gain;
      *(outbuffer + offset + 0) = (u_eefm_ee_rot_error_p_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_ee_rot_error_p_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_ee_rot_error_p_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_ee_rot_error_p_gain.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_ee_rot_error_p_gain.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_ee_rot_error_p_gain.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_ee_rot_error_p_gain.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_ee_rot_error_p_gain.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_ee_rot_error_p_gain);
      union {
        double real;
        uint64_t base;
      } u_eefm_ee_error_cutoff_freq;
      u_eefm_ee_error_cutoff_freq.real = this->eefm_ee_error_cutoff_freq;
      *(outbuffer + offset + 0) = (u_eefm_ee_error_cutoff_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_eefm_ee_error_cutoff_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_eefm_ee_error_cutoff_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_eefm_ee_error_cutoff_freq.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_eefm_ee_error_cutoff_freq.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_eefm_ee_error_cutoff_freq.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_eefm_ee_error_cutoff_freq.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_eefm_ee_error_cutoff_freq.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->eefm_ee_error_cutoff_freq);
      *(outbuffer + offset++) = eefm_support_polygon_vertices_sequence_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < eefm_support_polygon_vertices_sequence_length; i++){
      offset += this->eefm_support_polygon_vertices_sequence[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_eefm_use_force_difference_control;
      u_eefm_use_force_difference_control.real = this->eefm_use_force_difference_control;
      *(outbuffer + offset + 0) = (u_eefm_use_force_difference_control.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->eefm_use_force_difference_control);
      union {
        int64_t real;
        uint64_t base;
      } u_st_algorithm;
      u_st_algorithm.real = this->st_algorithm;
      *(outbuffer + offset + 0) = (u_st_algorithm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_st_algorithm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_st_algorithm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_st_algorithm.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_st_algorithm.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_st_algorithm.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_st_algorithm.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_st_algorithm.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->st_algorithm);
      union {
        int64_t real;
        uint64_t base;
      } u_controller_mode;
      u_controller_mode.real = this->controller_mode;
      *(outbuffer + offset + 0) = (u_controller_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_controller_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_controller_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_controller_mode.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_controller_mode.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_controller_mode.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_controller_mode.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_controller_mode.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->controller_mode);
      union {
        double real;
        uint64_t base;
      } u_transition_time;
      u_transition_time.real = this->transition_time;
      *(outbuffer + offset + 0) = (u_transition_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transition_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transition_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transition_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_transition_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_transition_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_transition_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_transition_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->transition_time);
      *(outbuffer + offset++) = is_ik_enable_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < is_ik_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_is_ik_enablei;
      u_is_ik_enablei.real = this->is_ik_enable[i];
      *(outbuffer + offset + 0) = (u_is_ik_enablei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_ik_enable[i]);
      }
      *(outbuffer + offset++) = is_feedback_control_enable_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < is_feedback_control_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_is_feedback_control_enablei;
      u_is_feedback_control_enablei.real = this->is_feedback_control_enable[i];
      *(outbuffer + offset + 0) = (u_is_feedback_control_enablei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_feedback_control_enable[i]);
      }
      *(outbuffer + offset++) = is_zmp_calc_enable_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < is_zmp_calc_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_is_zmp_calc_enablei;
      u_is_zmp_calc_enablei.real = this->is_zmp_calc_enable[i];
      *(outbuffer + offset + 0) = (u_is_zmp_calc_enablei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_zmp_calc_enable[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_cop_check_margin;
      u_cop_check_margin.real = this->cop_check_margin;
      *(outbuffer + offset + 0) = (u_cop_check_margin.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cop_check_margin.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cop_check_margin.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cop_check_margin.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cop_check_margin.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cop_check_margin.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cop_check_margin.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cop_check_margin.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cop_check_margin);
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_cp_check_margini;
      u_cp_check_margini.real = this->cp_check_margin[i];
      *(outbuffer + offset + 0) = (u_cp_check_margini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cp_check_margini.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cp_check_margini.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cp_check_margini.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cp_check_margini.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cp_check_margini.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cp_check_margini.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cp_check_margini.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cp_check_margin[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_tilt_margini;
      u_tilt_margini.real = this->tilt_margin[i];
      *(outbuffer + offset + 0) = (u_tilt_margini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tilt_margini.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tilt_margini.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tilt_margini.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tilt_margini.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tilt_margini.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tilt_margini.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tilt_margini.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tilt_margin[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_ref_capture_pointi;
      u_ref_capture_pointi.real = this->ref_capture_point[i];
      *(outbuffer + offset + 0) = (u_ref_capture_pointi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ref_capture_pointi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ref_capture_pointi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ref_capture_pointi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ref_capture_pointi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ref_capture_pointi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ref_capture_pointi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ref_capture_pointi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ref_capture_point[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_act_capture_pointi;
      u_act_capture_pointi.real = this->act_capture_point[i];
      *(outbuffer + offset + 0) = (u_act_capture_pointi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_act_capture_pointi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_act_capture_pointi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_act_capture_pointi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_act_capture_pointi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_act_capture_pointi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_act_capture_pointi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_act_capture_pointi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->act_capture_point[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_contact_decision_threshold;
      u_contact_decision_threshold.real = this->contact_decision_threshold;
      *(outbuffer + offset + 0) = (u_contact_decision_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_contact_decision_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_contact_decision_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_contact_decision_threshold.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_contact_decision_threshold.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_contact_decision_threshold.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_contact_decision_threshold.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_contact_decision_threshold.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->contact_decision_threshold);
      offset += this->foot_origin_offset.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_emergency_check_mode;
      u_emergency_check_mode.real = this->emergency_check_mode;
      *(outbuffer + offset + 0) = (u_emergency_check_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_emergency_check_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_emergency_check_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_emergency_check_mode.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_emergency_check_mode.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_emergency_check_mode.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_emergency_check_mode.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_emergency_check_mode.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->emergency_check_mode);
      *(outbuffer + offset++) = end_effector_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < end_effector_list_length; i++){
      offset += this->end_effector_list[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_is_estop_while_walking;
      u_is_estop_while_walking.real = this->is_estop_while_walking;
      *(outbuffer + offset + 0) = (u_is_estop_while_walking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_estop_while_walking);
      *(outbuffer + offset++) = ik_limb_parameters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ik_limb_parameters_length; i++){
      offset += this->ik_limb_parameters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_k_tpcc_pi;
      u_k_tpcc_pi.base = 0;
      u_k_tpcc_pi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_tpcc_pi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_k_tpcc_pi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_k_tpcc_pi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_k_tpcc_pi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_k_tpcc_pi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_k_tpcc_pi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_k_tpcc_pi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->k_tpcc_p[i] = u_k_tpcc_pi.real;
      offset += sizeof(this->k_tpcc_p[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_k_tpcc_xi;
      u_k_tpcc_xi.base = 0;
      u_k_tpcc_xi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_tpcc_xi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_k_tpcc_xi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_k_tpcc_xi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_k_tpcc_xi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_k_tpcc_xi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_k_tpcc_xi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_k_tpcc_xi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->k_tpcc_x[i] = u_k_tpcc_xi.real;
      offset += sizeof(this->k_tpcc_x[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_k_brot_pi;
      u_k_brot_pi.base = 0;
      u_k_brot_pi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_brot_pi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_k_brot_pi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_k_brot_pi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_k_brot_pi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_k_brot_pi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_k_brot_pi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_k_brot_pi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->k_brot_p[i] = u_k_brot_pi.real;
      offset += sizeof(this->k_brot_p[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_k_brot_tci;
      u_k_brot_tci.base = 0;
      u_k_brot_tci.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_k_brot_tci.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_k_brot_tci.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_k_brot_tci.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_k_brot_tci.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_k_brot_tci.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_k_brot_tci.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_k_brot_tci.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->k_brot_tc[i] = u_k_brot_tci.real;
      offset += sizeof(this->k_brot_tc[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_k1i;
      u_eefm_k1i.base = 0;
      u_eefm_k1i.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_k1i.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_k1i.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_k1i.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_k1i.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_k1i.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_k1i.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_k1i.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_k1[i] = u_eefm_k1i.real;
      offset += sizeof(this->eefm_k1[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_k2i;
      u_eefm_k2i.base = 0;
      u_eefm_k2i.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_k2i.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_k2i.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_k2i.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_k2i.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_k2i.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_k2i.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_k2i.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_k2[i] = u_eefm_k2i.real;
      offset += sizeof(this->eefm_k2[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_k3i;
      u_eefm_k3i.base = 0;
      u_eefm_k3i.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_k3i.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_k3i.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_k3i.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_k3i.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_k3i.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_k3i.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_k3i.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_k3[i] = u_eefm_k3i.real;
      offset += sizeof(this->eefm_k3[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_zmp_delay_time_consti;
      u_eefm_zmp_delay_time_consti.base = 0;
      u_eefm_zmp_delay_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_zmp_delay_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_zmp_delay_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_zmp_delay_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_zmp_delay_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_zmp_delay_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_zmp_delay_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_zmp_delay_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_zmp_delay_time_const[i] = u_eefm_zmp_delay_time_consti.real;
      offset += sizeof(this->eefm_zmp_delay_time_const[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_ref_zmp_auxi;
      u_eefm_ref_zmp_auxi.base = 0;
      u_eefm_ref_zmp_auxi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_ref_zmp_auxi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_ref_zmp_auxi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_ref_zmp_auxi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_ref_zmp_auxi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_ref_zmp_auxi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_ref_zmp_auxi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_ref_zmp_auxi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_ref_zmp_aux[i] = u_eefm_ref_zmp_auxi.real;
      offset += sizeof(this->eefm_ref_zmp_aux[i]);
      }
      offset += this->eefm_rot_damping_gain.deserialize(inbuffer + offset);
      offset += this->eefm_rot_time_const.deserialize(inbuffer + offset);
      offset += this->eefm_pos_damping_gain.deserialize(inbuffer + offset);
      offset += this->eefm_pos_time_const_support.deserialize(inbuffer + offset);
      offset += this->eefm_swing_rot_spring_gain.deserialize(inbuffer + offset);
      offset += this->eefm_swing_rot_time_const.deserialize(inbuffer + offset);
      offset += this->eefm_swing_pos_spring_gain.deserialize(inbuffer + offset);
      offset += this->eefm_swing_pos_time_const.deserialize(inbuffer + offset);
      offset += this->eefm_ee_moment_limit.deserialize(inbuffer + offset);
      uint8_t eefm_pos_compensation_limit_lengthT = *(inbuffer + offset++);
      if(eefm_pos_compensation_limit_lengthT > eefm_pos_compensation_limit_length)
        this->eefm_pos_compensation_limit = (double*)realloc(this->eefm_pos_compensation_limit, eefm_pos_compensation_limit_lengthT * sizeof(double));
      offset += 3;
      eefm_pos_compensation_limit_length = eefm_pos_compensation_limit_lengthT;
      for( uint8_t i = 0; i < eefm_pos_compensation_limit_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_eefm_pos_compensation_limit;
      u_st_eefm_pos_compensation_limit.base = 0;
      u_st_eefm_pos_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_eefm_pos_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_eefm_pos_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_eefm_pos_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_eefm_pos_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_eefm_pos_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_eefm_pos_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_eefm_pos_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_eefm_pos_compensation_limit = u_st_eefm_pos_compensation_limit.real;
      offset += sizeof(this->st_eefm_pos_compensation_limit);
        memcpy( &(this->eefm_pos_compensation_limit[i]), &(this->st_eefm_pos_compensation_limit), sizeof(double));
      }
      uint8_t eefm_rot_compensation_limit_lengthT = *(inbuffer + offset++);
      if(eefm_rot_compensation_limit_lengthT > eefm_rot_compensation_limit_length)
        this->eefm_rot_compensation_limit = (double*)realloc(this->eefm_rot_compensation_limit, eefm_rot_compensation_limit_lengthT * sizeof(double));
      offset += 3;
      eefm_rot_compensation_limit_length = eefm_rot_compensation_limit_lengthT;
      for( uint8_t i = 0; i < eefm_rot_compensation_limit_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_eefm_rot_compensation_limit;
      u_st_eefm_rot_compensation_limit.base = 0;
      u_st_eefm_rot_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_eefm_rot_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_eefm_rot_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_eefm_rot_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_eefm_rot_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_eefm_rot_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_eefm_rot_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_eefm_rot_compensation_limit.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_eefm_rot_compensation_limit = u_st_eefm_rot_compensation_limit.real;
      offset += sizeof(this->st_eefm_rot_compensation_limit);
        memcpy( &(this->eefm_rot_compensation_limit[i]), &(this->st_eefm_rot_compensation_limit), sizeof(double));
      }
      union {
        double real;
        uint64_t base;
      } u_eefm_pos_time_const_swing;
      u_eefm_pos_time_const_swing.base = 0;
      u_eefm_pos_time_const_swing.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_pos_time_const_swing.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_pos_time_const_swing.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_pos_time_const_swing.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_pos_time_const_swing.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_pos_time_const_swing.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_pos_time_const_swing.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_pos_time_const_swing.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_pos_time_const_swing = u_eefm_pos_time_const_swing.real;
      offset += sizeof(this->eefm_pos_time_const_swing);
      union {
        double real;
        uint64_t base;
      } u_eefm_pos_transition_time;
      u_eefm_pos_transition_time.base = 0;
      u_eefm_pos_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_pos_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_pos_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_pos_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_pos_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_pos_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_pos_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_pos_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_pos_transition_time = u_eefm_pos_transition_time.real;
      offset += sizeof(this->eefm_pos_transition_time);
      union {
        double real;
        uint64_t base;
      } u_eefm_pos_margin_time;
      u_eefm_pos_margin_time.base = 0;
      u_eefm_pos_margin_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_pos_margin_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_pos_margin_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_pos_margin_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_pos_margin_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_pos_margin_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_pos_margin_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_pos_margin_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_pos_margin_time = u_eefm_pos_margin_time.real;
      offset += sizeof(this->eefm_pos_margin_time);
      union {
        double real;
        uint64_t base;
      } u_eefm_leg_inside_margin;
      u_eefm_leg_inside_margin.base = 0;
      u_eefm_leg_inside_margin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_leg_inside_margin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_leg_inside_margin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_leg_inside_margin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_leg_inside_margin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_leg_inside_margin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_leg_inside_margin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_leg_inside_margin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_leg_inside_margin = u_eefm_leg_inside_margin.real;
      offset += sizeof(this->eefm_leg_inside_margin);
      union {
        double real;
        uint64_t base;
      } u_eefm_leg_outside_margin;
      u_eefm_leg_outside_margin.base = 0;
      u_eefm_leg_outside_margin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_leg_outside_margin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_leg_outside_margin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_leg_outside_margin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_leg_outside_margin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_leg_outside_margin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_leg_outside_margin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_leg_outside_margin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_leg_outside_margin = u_eefm_leg_outside_margin.real;
      offset += sizeof(this->eefm_leg_outside_margin);
      union {
        double real;
        uint64_t base;
      } u_eefm_leg_front_margin;
      u_eefm_leg_front_margin.base = 0;
      u_eefm_leg_front_margin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_leg_front_margin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_leg_front_margin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_leg_front_margin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_leg_front_margin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_leg_front_margin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_leg_front_margin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_leg_front_margin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_leg_front_margin = u_eefm_leg_front_margin.real;
      offset += sizeof(this->eefm_leg_front_margin);
      union {
        double real;
        uint64_t base;
      } u_eefm_leg_rear_margin;
      u_eefm_leg_rear_margin.base = 0;
      u_eefm_leg_rear_margin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_leg_rear_margin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_leg_rear_margin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_leg_rear_margin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_leg_rear_margin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_leg_rear_margin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_leg_rear_margin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_leg_rear_margin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_leg_rear_margin = u_eefm_leg_rear_margin.real;
      offset += sizeof(this->eefm_leg_rear_margin);
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_body_attitude_control_gaini;
      u_eefm_body_attitude_control_gaini.base = 0;
      u_eefm_body_attitude_control_gaini.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_body_attitude_control_gaini.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_body_attitude_control_gaini.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_body_attitude_control_gaini.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_body_attitude_control_gaini.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_body_attitude_control_gaini.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_body_attitude_control_gaini.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_body_attitude_control_gaini.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_body_attitude_control_gain[i] = u_eefm_body_attitude_control_gaini.real;
      offset += sizeof(this->eefm_body_attitude_control_gain[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_eefm_body_attitude_control_time_consti;
      u_eefm_body_attitude_control_time_consti.base = 0;
      u_eefm_body_attitude_control_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_body_attitude_control_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_body_attitude_control_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_body_attitude_control_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_body_attitude_control_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_body_attitude_control_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_body_attitude_control_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_body_attitude_control_time_consti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_body_attitude_control_time_const[i] = u_eefm_body_attitude_control_time_consti.real;
      offset += sizeof(this->eefm_body_attitude_control_time_const[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_eefm_cogvel_cutoff_freq;
      u_eefm_cogvel_cutoff_freq.base = 0;
      u_eefm_cogvel_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_cogvel_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_cogvel_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_cogvel_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_cogvel_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_cogvel_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_cogvel_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_cogvel_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_cogvel_cutoff_freq = u_eefm_cogvel_cutoff_freq.real;
      offset += sizeof(this->eefm_cogvel_cutoff_freq);
      union {
        double real;
        uint64_t base;
      } u_eefm_wrench_alpha_blending;
      u_eefm_wrench_alpha_blending.base = 0;
      u_eefm_wrench_alpha_blending.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_wrench_alpha_blending.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_wrench_alpha_blending.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_wrench_alpha_blending.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_wrench_alpha_blending.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_wrench_alpha_blending.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_wrench_alpha_blending.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_wrench_alpha_blending.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_wrench_alpha_blending = u_eefm_wrench_alpha_blending.real;
      offset += sizeof(this->eefm_wrench_alpha_blending);
      union {
        double real;
        uint64_t base;
      } u_eefm_alpha_cutoff_freq;
      u_eefm_alpha_cutoff_freq.base = 0;
      u_eefm_alpha_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_alpha_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_alpha_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_alpha_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_alpha_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_alpha_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_alpha_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_alpha_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_alpha_cutoff_freq = u_eefm_alpha_cutoff_freq.real;
      offset += sizeof(this->eefm_alpha_cutoff_freq);
      union {
        double real;
        uint64_t base;
      } u_eefm_gravitational_acceleration;
      u_eefm_gravitational_acceleration.base = 0;
      u_eefm_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_gravitational_acceleration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_gravitational_acceleration = u_eefm_gravitational_acceleration.real;
      offset += sizeof(this->eefm_gravitational_acceleration);
      union {
        double real;
        uint64_t base;
      } u_eefm_ee_pos_error_p_gain;
      u_eefm_ee_pos_error_p_gain.base = 0;
      u_eefm_ee_pos_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_ee_pos_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_ee_pos_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_ee_pos_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_ee_pos_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_ee_pos_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_ee_pos_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_ee_pos_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_ee_pos_error_p_gain = u_eefm_ee_pos_error_p_gain.real;
      offset += sizeof(this->eefm_ee_pos_error_p_gain);
      union {
        double real;
        uint64_t base;
      } u_eefm_ee_rot_error_p_gain;
      u_eefm_ee_rot_error_p_gain.base = 0;
      u_eefm_ee_rot_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_ee_rot_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_ee_rot_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_ee_rot_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_ee_rot_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_ee_rot_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_ee_rot_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_ee_rot_error_p_gain.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_ee_rot_error_p_gain = u_eefm_ee_rot_error_p_gain.real;
      offset += sizeof(this->eefm_ee_rot_error_p_gain);
      union {
        double real;
        uint64_t base;
      } u_eefm_ee_error_cutoff_freq;
      u_eefm_ee_error_cutoff_freq.base = 0;
      u_eefm_ee_error_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_eefm_ee_error_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_eefm_ee_error_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_eefm_ee_error_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_eefm_ee_error_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_eefm_ee_error_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_eefm_ee_error_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_eefm_ee_error_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->eefm_ee_error_cutoff_freq = u_eefm_ee_error_cutoff_freq.real;
      offset += sizeof(this->eefm_ee_error_cutoff_freq);
      uint8_t eefm_support_polygon_vertices_sequence_lengthT = *(inbuffer + offset++);
      if(eefm_support_polygon_vertices_sequence_lengthT > eefm_support_polygon_vertices_sequence_length)
        this->eefm_support_polygon_vertices_sequence = (hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices*)realloc(this->eefm_support_polygon_vertices_sequence, eefm_support_polygon_vertices_sequence_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices));
      offset += 3;
      eefm_support_polygon_vertices_sequence_length = eefm_support_polygon_vertices_sequence_lengthT;
      for( uint8_t i = 0; i < eefm_support_polygon_vertices_sequence_length; i++){
      offset += this->st_eefm_support_polygon_vertices_sequence.deserialize(inbuffer + offset);
        memcpy( &(this->eefm_support_polygon_vertices_sequence[i]), &(this->st_eefm_support_polygon_vertices_sequence), sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_SupportPolygonVertices));
      }
      union {
        bool real;
        uint8_t base;
      } u_eefm_use_force_difference_control;
      u_eefm_use_force_difference_control.base = 0;
      u_eefm_use_force_difference_control.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->eefm_use_force_difference_control = u_eefm_use_force_difference_control.real;
      offset += sizeof(this->eefm_use_force_difference_control);
      union {
        int64_t real;
        uint64_t base;
      } u_st_algorithm;
      u_st_algorithm.base = 0;
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_algorithm = u_st_algorithm.real;
      offset += sizeof(this->st_algorithm);
      union {
        int64_t real;
        uint64_t base;
      } u_controller_mode;
      u_controller_mode.base = 0;
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_controller_mode.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->controller_mode = u_controller_mode.real;
      offset += sizeof(this->controller_mode);
      union {
        double real;
        uint64_t base;
      } u_transition_time;
      u_transition_time.base = 0;
      u_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->transition_time = u_transition_time.real;
      offset += sizeof(this->transition_time);
      uint8_t is_ik_enable_lengthT = *(inbuffer + offset++);
      if(is_ik_enable_lengthT > is_ik_enable_length)
        this->is_ik_enable = (bool*)realloc(this->is_ik_enable, is_ik_enable_lengthT * sizeof(bool));
      offset += 3;
      is_ik_enable_length = is_ik_enable_lengthT;
      for( uint8_t i = 0; i < is_ik_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_is_ik_enable;
      u_st_is_ik_enable.base = 0;
      u_st_is_ik_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_is_ik_enable = u_st_is_ik_enable.real;
      offset += sizeof(this->st_is_ik_enable);
        memcpy( &(this->is_ik_enable[i]), &(this->st_is_ik_enable), sizeof(bool));
      }
      uint8_t is_feedback_control_enable_lengthT = *(inbuffer + offset++);
      if(is_feedback_control_enable_lengthT > is_feedback_control_enable_length)
        this->is_feedback_control_enable = (bool*)realloc(this->is_feedback_control_enable, is_feedback_control_enable_lengthT * sizeof(bool));
      offset += 3;
      is_feedback_control_enable_length = is_feedback_control_enable_lengthT;
      for( uint8_t i = 0; i < is_feedback_control_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_is_feedback_control_enable;
      u_st_is_feedback_control_enable.base = 0;
      u_st_is_feedback_control_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_is_feedback_control_enable = u_st_is_feedback_control_enable.real;
      offset += sizeof(this->st_is_feedback_control_enable);
        memcpy( &(this->is_feedback_control_enable[i]), &(this->st_is_feedback_control_enable), sizeof(bool));
      }
      uint8_t is_zmp_calc_enable_lengthT = *(inbuffer + offset++);
      if(is_zmp_calc_enable_lengthT > is_zmp_calc_enable_length)
        this->is_zmp_calc_enable = (bool*)realloc(this->is_zmp_calc_enable, is_zmp_calc_enable_lengthT * sizeof(bool));
      offset += 3;
      is_zmp_calc_enable_length = is_zmp_calc_enable_lengthT;
      for( uint8_t i = 0; i < is_zmp_calc_enable_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_is_zmp_calc_enable;
      u_st_is_zmp_calc_enable.base = 0;
      u_st_is_zmp_calc_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_is_zmp_calc_enable = u_st_is_zmp_calc_enable.real;
      offset += sizeof(this->st_is_zmp_calc_enable);
        memcpy( &(this->is_zmp_calc_enable[i]), &(this->st_is_zmp_calc_enable), sizeof(bool));
      }
      union {
        double real;
        uint64_t base;
      } u_cop_check_margin;
      u_cop_check_margin.base = 0;
      u_cop_check_margin.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cop_check_margin.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cop_check_margin.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cop_check_margin.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_cop_check_margin.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_cop_check_margin.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_cop_check_margin.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_cop_check_margin.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->cop_check_margin = u_cop_check_margin.real;
      offset += sizeof(this->cop_check_margin);
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_cp_check_margini;
      u_cp_check_margini.base = 0;
      u_cp_check_margini.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cp_check_margini.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cp_check_margini.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cp_check_margini.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_cp_check_margini.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_cp_check_margini.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_cp_check_margini.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_cp_check_margini.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->cp_check_margin[i] = u_cp_check_margini.real;
      offset += sizeof(this->cp_check_margin[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_tilt_margini;
      u_tilt_margini.base = 0;
      u_tilt_margini.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tilt_margini.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tilt_margini.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tilt_margini.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tilt_margini.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tilt_margini.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tilt_margini.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tilt_margini.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->tilt_margin[i] = u_tilt_margini.real;
      offset += sizeof(this->tilt_margin[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_ref_capture_pointi;
      u_ref_capture_pointi.base = 0;
      u_ref_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ref_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ref_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ref_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ref_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ref_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ref_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ref_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ref_capture_point[i] = u_ref_capture_pointi.real;
      offset += sizeof(this->ref_capture_point[i]);
      }
      for( uint8_t i = 0; i < 2; i++){
      union {
        double real;
        uint64_t base;
      } u_act_capture_pointi;
      u_act_capture_pointi.base = 0;
      u_act_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_act_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_act_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_act_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_act_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_act_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_act_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_act_capture_pointi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->act_capture_point[i] = u_act_capture_pointi.real;
      offset += sizeof(this->act_capture_point[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_contact_decision_threshold;
      u_contact_decision_threshold.base = 0;
      u_contact_decision_threshold.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_contact_decision_threshold.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_contact_decision_threshold.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_contact_decision_threshold.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_contact_decision_threshold.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_contact_decision_threshold.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_contact_decision_threshold.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_contact_decision_threshold.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->contact_decision_threshold = u_contact_decision_threshold.real;
      offset += sizeof(this->contact_decision_threshold);
      offset += this->foot_origin_offset.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_emergency_check_mode;
      u_emergency_check_mode.base = 0;
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_emergency_check_mode.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->emergency_check_mode = u_emergency_check_mode.real;
      offset += sizeof(this->emergency_check_mode);
      uint8_t end_effector_list_lengthT = *(inbuffer + offset++);
      if(end_effector_list_lengthT > end_effector_list_length)
        this->end_effector_list = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep*)realloc(this->end_effector_list, end_effector_list_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      offset += 3;
      end_effector_list_length = end_effector_list_lengthT;
      for( uint8_t i = 0; i < end_effector_list_length; i++){
      offset += this->st_end_effector_list.deserialize(inbuffer + offset);
        memcpy( &(this->end_effector_list[i]), &(this->st_end_effector_list), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      }
      union {
        bool real;
        uint8_t base;
      } u_is_estop_while_walking;
      u_is_estop_while_walking.base = 0;
      u_is_estop_while_walking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_estop_while_walking = u_is_estop_while_walking.real;
      offset += sizeof(this->is_estop_while_walking);
      uint8_t ik_limb_parameters_lengthT = *(inbuffer + offset++);
      if(ik_limb_parameters_lengthT > ik_limb_parameters_length)
        this->ik_limb_parameters = (hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters*)realloc(this->ik_limb_parameters, ik_limb_parameters_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters));
      offset += 3;
      ik_limb_parameters_length = ik_limb_parameters_lengthT;
      for( uint8_t i = 0; i < ik_limb_parameters_length; i++){
      offset += this->st_ik_limb_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->ik_limb_parameters[i]), &(this->st_ik_limb_parameters), sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_IKLimbParameters));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_stParam"; };
    const char * getMD5(){ return "b5cf362eaf5467e99dedab2bdf981cf3"; };

  };

}
#endif