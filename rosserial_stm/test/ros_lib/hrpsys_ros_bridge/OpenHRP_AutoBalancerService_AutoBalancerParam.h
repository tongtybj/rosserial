#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_AutoBalancerParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_AutoBalancerParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_IKLimbParameters.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_AutoBalancerParam : public ros::Msg
  {
    public:
      std_msgs::Float64MultiArray default_zmp_offsets;
      double move_base_gain;
      int64_t controller_mode;
      int64_t use_force_mode;
      bool graspless_manip_mode;
      const char* graspless_manip_arm;
      double graspless_manip_p_gain[3];
      double graspless_manip_reference_trans_pos[3];
      double graspless_manip_reference_trans_rot[4];
      double transition_time;
      double zmp_transition_time;
      double adjust_footstep_transition_time;
      uint8_t leg_names_length;
      char* st_leg_names;
      char* * leg_names;
      bool has_ik_failed;
      double pos_ik_thre;
      double rot_ik_thre;
      bool is_hand_fix_mode;
      uint8_t end_effector_list_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep st_end_effector_list;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep * end_effector_list;
      int64_t default_gait_type;
      uint8_t ik_limb_parameters_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters st_ik_limb_parameters;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters * ik_limb_parameters;

    OpenHRP_AutoBalancerService_AutoBalancerParam():
      default_zmp_offsets(),
      move_base_gain(0),
      controller_mode(0),
      use_force_mode(0),
      graspless_manip_mode(0),
      graspless_manip_arm(""),
      graspless_manip_p_gain(),
      graspless_manip_reference_trans_pos(),
      graspless_manip_reference_trans_rot(),
      transition_time(0),
      zmp_transition_time(0),
      adjust_footstep_transition_time(0),
      leg_names_length(0), leg_names(NULL),
      has_ik_failed(0),
      pos_ik_thre(0),
      rot_ik_thre(0),
      is_hand_fix_mode(0),
      end_effector_list_length(0), end_effector_list(NULL),
      default_gait_type(0),
      ik_limb_parameters_length(0), ik_limb_parameters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->default_zmp_offsets.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_move_base_gain;
      u_move_base_gain.real = this->move_base_gain;
      *(outbuffer + offset + 0) = (u_move_base_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_move_base_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_move_base_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_move_base_gain.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_move_base_gain.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_move_base_gain.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_move_base_gain.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_move_base_gain.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->move_base_gain);
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
        int64_t real;
        uint64_t base;
      } u_use_force_mode;
      u_use_force_mode.real = this->use_force_mode;
      *(outbuffer + offset + 0) = (u_use_force_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_use_force_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_use_force_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_use_force_mode.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_use_force_mode.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_use_force_mode.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_use_force_mode.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_use_force_mode.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->use_force_mode);
      union {
        bool real;
        uint8_t base;
      } u_graspless_manip_mode;
      u_graspless_manip_mode.real = this->graspless_manip_mode;
      *(outbuffer + offset + 0) = (u_graspless_manip_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->graspless_manip_mode);
      uint32_t length_graspless_manip_arm = strlen(this->graspless_manip_arm);
      memcpy(outbuffer + offset, &length_graspless_manip_arm, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->graspless_manip_arm, length_graspless_manip_arm);
      offset += length_graspless_manip_arm;
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_graspless_manip_p_gaini;
      u_graspless_manip_p_gaini.real = this->graspless_manip_p_gain[i];
      *(outbuffer + offset + 0) = (u_graspless_manip_p_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_graspless_manip_p_gaini.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_graspless_manip_p_gaini.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_graspless_manip_p_gaini.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_graspless_manip_p_gaini.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_graspless_manip_p_gaini.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_graspless_manip_p_gaini.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_graspless_manip_p_gaini.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->graspless_manip_p_gain[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_graspless_manip_reference_trans_posi;
      u_graspless_manip_reference_trans_posi.real = this->graspless_manip_reference_trans_pos[i];
      *(outbuffer + offset + 0) = (u_graspless_manip_reference_trans_posi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_graspless_manip_reference_trans_posi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_graspless_manip_reference_trans_posi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_graspless_manip_reference_trans_posi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_graspless_manip_reference_trans_posi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_graspless_manip_reference_trans_posi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_graspless_manip_reference_trans_posi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_graspless_manip_reference_trans_posi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->graspless_manip_reference_trans_pos[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_graspless_manip_reference_trans_roti;
      u_graspless_manip_reference_trans_roti.real = this->graspless_manip_reference_trans_rot[i];
      *(outbuffer + offset + 0) = (u_graspless_manip_reference_trans_roti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_graspless_manip_reference_trans_roti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_graspless_manip_reference_trans_roti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_graspless_manip_reference_trans_roti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_graspless_manip_reference_trans_roti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_graspless_manip_reference_trans_roti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_graspless_manip_reference_trans_roti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_graspless_manip_reference_trans_roti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->graspless_manip_reference_trans_rot[i]);
      }
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
      union {
        double real;
        uint64_t base;
      } u_zmp_transition_time;
      u_zmp_transition_time.real = this->zmp_transition_time;
      *(outbuffer + offset + 0) = (u_zmp_transition_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zmp_transition_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zmp_transition_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zmp_transition_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_zmp_transition_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_zmp_transition_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_zmp_transition_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_zmp_transition_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->zmp_transition_time);
      union {
        double real;
        uint64_t base;
      } u_adjust_footstep_transition_time;
      u_adjust_footstep_transition_time.real = this->adjust_footstep_transition_time;
      *(outbuffer + offset + 0) = (u_adjust_footstep_transition_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_adjust_footstep_transition_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_adjust_footstep_transition_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_adjust_footstep_transition_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_adjust_footstep_transition_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_adjust_footstep_transition_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_adjust_footstep_transition_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_adjust_footstep_transition_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->adjust_footstep_transition_time);
      *(outbuffer + offset++) = leg_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < leg_names_length; i++){
      uint32_t length_leg_namesi = strlen(this->leg_names[i]);
      memcpy(outbuffer + offset, &length_leg_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->leg_names[i], length_leg_namesi);
      offset += length_leg_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_has_ik_failed;
      u_has_ik_failed.real = this->has_ik_failed;
      *(outbuffer + offset + 0) = (u_has_ik_failed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_ik_failed);
      union {
        double real;
        uint64_t base;
      } u_pos_ik_thre;
      u_pos_ik_thre.real = this->pos_ik_thre;
      *(outbuffer + offset + 0) = (u_pos_ik_thre.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos_ik_thre.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos_ik_thre.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos_ik_thre.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pos_ik_thre.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pos_ik_thre.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pos_ik_thre.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pos_ik_thre.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos_ik_thre);
      union {
        double real;
        uint64_t base;
      } u_rot_ik_thre;
      u_rot_ik_thre.real = this->rot_ik_thre;
      *(outbuffer + offset + 0) = (u_rot_ik_thre.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rot_ik_thre.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rot_ik_thre.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rot_ik_thre.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rot_ik_thre.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rot_ik_thre.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rot_ik_thre.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rot_ik_thre.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rot_ik_thre);
      union {
        bool real;
        uint8_t base;
      } u_is_hand_fix_mode;
      u_is_hand_fix_mode.real = this->is_hand_fix_mode;
      *(outbuffer + offset + 0) = (u_is_hand_fix_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_hand_fix_mode);
      *(outbuffer + offset++) = end_effector_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < end_effector_list_length; i++){
      offset += this->end_effector_list[i].serialize(outbuffer + offset);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_default_gait_type;
      u_default_gait_type.real = this->default_gait_type;
      *(outbuffer + offset + 0) = (u_default_gait_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_gait_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_gait_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_gait_type.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_gait_type.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_gait_type.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_gait_type.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_gait_type.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_gait_type);
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
      offset += this->default_zmp_offsets.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_move_base_gain;
      u_move_base_gain.base = 0;
      u_move_base_gain.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_move_base_gain.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_move_base_gain.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_move_base_gain.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_move_base_gain.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_move_base_gain.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_move_base_gain.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_move_base_gain.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->move_base_gain = u_move_base_gain.real;
      offset += sizeof(this->move_base_gain);
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
        int64_t real;
        uint64_t base;
      } u_use_force_mode;
      u_use_force_mode.base = 0;
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_use_force_mode.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->use_force_mode = u_use_force_mode.real;
      offset += sizeof(this->use_force_mode);
      union {
        bool real;
        uint8_t base;
      } u_graspless_manip_mode;
      u_graspless_manip_mode.base = 0;
      u_graspless_manip_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->graspless_manip_mode = u_graspless_manip_mode.real;
      offset += sizeof(this->graspless_manip_mode);
      uint32_t length_graspless_manip_arm;
      memcpy(&length_graspless_manip_arm, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_graspless_manip_arm; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_graspless_manip_arm-1]=0;
      this->graspless_manip_arm = (char *)(inbuffer + offset-1);
      offset += length_graspless_manip_arm;
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_graspless_manip_p_gaini;
      u_graspless_manip_p_gaini.base = 0;
      u_graspless_manip_p_gaini.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_graspless_manip_p_gaini.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_graspless_manip_p_gaini.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_graspless_manip_p_gaini.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_graspless_manip_p_gaini.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_graspless_manip_p_gaini.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_graspless_manip_p_gaini.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_graspless_manip_p_gaini.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->graspless_manip_p_gain[i] = u_graspless_manip_p_gaini.real;
      offset += sizeof(this->graspless_manip_p_gain[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_graspless_manip_reference_trans_posi;
      u_graspless_manip_reference_trans_posi.base = 0;
      u_graspless_manip_reference_trans_posi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_graspless_manip_reference_trans_posi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_graspless_manip_reference_trans_posi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_graspless_manip_reference_trans_posi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_graspless_manip_reference_trans_posi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_graspless_manip_reference_trans_posi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_graspless_manip_reference_trans_posi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_graspless_manip_reference_trans_posi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->graspless_manip_reference_trans_pos[i] = u_graspless_manip_reference_trans_posi.real;
      offset += sizeof(this->graspless_manip_reference_trans_pos[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_graspless_manip_reference_trans_roti;
      u_graspless_manip_reference_trans_roti.base = 0;
      u_graspless_manip_reference_trans_roti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_graspless_manip_reference_trans_roti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_graspless_manip_reference_trans_roti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_graspless_manip_reference_trans_roti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_graspless_manip_reference_trans_roti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_graspless_manip_reference_trans_roti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_graspless_manip_reference_trans_roti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_graspless_manip_reference_trans_roti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->graspless_manip_reference_trans_rot[i] = u_graspless_manip_reference_trans_roti.real;
      offset += sizeof(this->graspless_manip_reference_trans_rot[i]);
      }
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
      union {
        double real;
        uint64_t base;
      } u_zmp_transition_time;
      u_zmp_transition_time.base = 0;
      u_zmp_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zmp_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zmp_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zmp_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_zmp_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_zmp_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_zmp_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_zmp_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->zmp_transition_time = u_zmp_transition_time.real;
      offset += sizeof(this->zmp_transition_time);
      union {
        double real;
        uint64_t base;
      } u_adjust_footstep_transition_time;
      u_adjust_footstep_transition_time.base = 0;
      u_adjust_footstep_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_adjust_footstep_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_adjust_footstep_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_adjust_footstep_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_adjust_footstep_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_adjust_footstep_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_adjust_footstep_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_adjust_footstep_transition_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->adjust_footstep_transition_time = u_adjust_footstep_transition_time.real;
      offset += sizeof(this->adjust_footstep_transition_time);
      uint8_t leg_names_lengthT = *(inbuffer + offset++);
      if(leg_names_lengthT > leg_names_length)
        this->leg_names = (char**)realloc(this->leg_names, leg_names_lengthT * sizeof(char*));
      offset += 3;
      leg_names_length = leg_names_lengthT;
      for( uint8_t i = 0; i < leg_names_length; i++){
      uint32_t length_st_leg_names;
      memcpy(&length_st_leg_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_leg_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_leg_names-1]=0;
      this->st_leg_names = (char *)(inbuffer + offset-1);
      offset += length_st_leg_names;
        memcpy( &(this->leg_names[i]), &(this->st_leg_names), sizeof(char*));
      }
      union {
        bool real;
        uint8_t base;
      } u_has_ik_failed;
      u_has_ik_failed.base = 0;
      u_has_ik_failed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_ik_failed = u_has_ik_failed.real;
      offset += sizeof(this->has_ik_failed);
      union {
        double real;
        uint64_t base;
      } u_pos_ik_thre;
      u_pos_ik_thre.base = 0;
      u_pos_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pos_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pos_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pos_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pos_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pos_ik_thre = u_pos_ik_thre.real;
      offset += sizeof(this->pos_ik_thre);
      union {
        double real;
        uint64_t base;
      } u_rot_ik_thre;
      u_rot_ik_thre.base = 0;
      u_rot_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rot_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rot_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rot_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rot_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rot_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rot_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rot_ik_thre.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rot_ik_thre = u_rot_ik_thre.real;
      offset += sizeof(this->rot_ik_thre);
      union {
        bool real;
        uint8_t base;
      } u_is_hand_fix_mode;
      u_is_hand_fix_mode.base = 0;
      u_is_hand_fix_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_hand_fix_mode = u_is_hand_fix_mode.real;
      offset += sizeof(this->is_hand_fix_mode);
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
        int64_t real;
        uint64_t base;
      } u_default_gait_type;
      u_default_gait_type.base = 0;
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_gait_type.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_gait_type = u_default_gait_type.real;
      offset += sizeof(this->default_gait_type);
      uint8_t ik_limb_parameters_lengthT = *(inbuffer + offset++);
      if(ik_limb_parameters_lengthT > ik_limb_parameters_length)
        this->ik_limb_parameters = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters*)realloc(this->ik_limb_parameters, ik_limb_parameters_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters));
      offset += 3;
      ik_limb_parameters_length = ik_limb_parameters_lengthT;
      for( uint8_t i = 0; i < ik_limb_parameters_length; i++){
      offset += this->st_ik_limb_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->ik_limb_parameters[i]), &(this->st_ik_limb_parameters), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_IKLimbParameters));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_AutoBalancerParam"; };
    const char * getMD5(){ return "22113c55a750aeb9ab0177552b9aed20"; };

  };

}
#endif