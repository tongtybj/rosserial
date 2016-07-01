#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_impedanceParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_impedanceParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ImpedanceControllerService_impedanceParam : public ros::Msg
  {
    public:
      double M_p;
      double D_p;
      double K_p;
      double M_r;
      double D_r;
      double K_r;
      double force_gain[3];
      double moment_gain[3];
      double sr_gain;
      double avoid_gain;
      double reference_gain;
      double manipulability_limit;
      int64_t controller_mode;
      uint8_t ik_optional_weight_vector_length;
      double st_ik_optional_weight_vector;
      double * ik_optional_weight_vector;
      bool use_sh_base_pos_rpy;

    OpenHRP_ImpedanceControllerService_impedanceParam():
      M_p(0),
      D_p(0),
      K_p(0),
      M_r(0),
      D_r(0),
      K_r(0),
      force_gain(),
      moment_gain(),
      sr_gain(0),
      avoid_gain(0),
      reference_gain(0),
      manipulability_limit(0),
      controller_mode(0),
      ik_optional_weight_vector_length(0), ik_optional_weight_vector(NULL),
      use_sh_base_pos_rpy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_M_p;
      u_M_p.real = this->M_p;
      *(outbuffer + offset + 0) = (u_M_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_M_p.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_M_p.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_M_p.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_M_p.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_M_p.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_M_p.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_M_p.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->M_p);
      union {
        double real;
        uint64_t base;
      } u_D_p;
      u_D_p.real = this->D_p;
      *(outbuffer + offset + 0) = (u_D_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_D_p.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_D_p.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_D_p.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_D_p.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_D_p.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_D_p.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_D_p.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->D_p);
      union {
        double real;
        uint64_t base;
      } u_K_p;
      u_K_p.real = this->K_p;
      *(outbuffer + offset + 0) = (u_K_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_K_p.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_K_p.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_K_p.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_K_p.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_K_p.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_K_p.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_K_p.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->K_p);
      union {
        double real;
        uint64_t base;
      } u_M_r;
      u_M_r.real = this->M_r;
      *(outbuffer + offset + 0) = (u_M_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_M_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_M_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_M_r.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_M_r.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_M_r.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_M_r.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_M_r.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->M_r);
      union {
        double real;
        uint64_t base;
      } u_D_r;
      u_D_r.real = this->D_r;
      *(outbuffer + offset + 0) = (u_D_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_D_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_D_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_D_r.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_D_r.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_D_r.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_D_r.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_D_r.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->D_r);
      union {
        double real;
        uint64_t base;
      } u_K_r;
      u_K_r.real = this->K_r;
      *(outbuffer + offset + 0) = (u_K_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_K_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_K_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_K_r.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_K_r.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_K_r.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_K_r.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_K_r.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->K_r);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_force_gaini;
      u_force_gaini.real = this->force_gain[i];
      *(outbuffer + offset + 0) = (u_force_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_gaini.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force_gaini.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force_gaini.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_force_gaini.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_force_gaini.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_force_gaini.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_force_gaini.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->force_gain[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_moment_gaini;
      u_moment_gaini.real = this->moment_gain[i];
      *(outbuffer + offset + 0) = (u_moment_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_moment_gaini.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_moment_gaini.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_moment_gaini.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_moment_gaini.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_moment_gaini.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_moment_gaini.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_moment_gaini.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->moment_gain[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_sr_gain;
      u_sr_gain.real = this->sr_gain;
      *(outbuffer + offset + 0) = (u_sr_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sr_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sr_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sr_gain.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sr_gain.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sr_gain.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sr_gain.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sr_gain.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sr_gain);
      union {
        double real;
        uint64_t base;
      } u_avoid_gain;
      u_avoid_gain.real = this->avoid_gain;
      *(outbuffer + offset + 0) = (u_avoid_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_avoid_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_avoid_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_avoid_gain.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_avoid_gain.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_avoid_gain.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_avoid_gain.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_avoid_gain.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->avoid_gain);
      union {
        double real;
        uint64_t base;
      } u_reference_gain;
      u_reference_gain.real = this->reference_gain;
      *(outbuffer + offset + 0) = (u_reference_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_gain.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_reference_gain.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_reference_gain.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_reference_gain.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_reference_gain.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->reference_gain);
      union {
        double real;
        uint64_t base;
      } u_manipulability_limit;
      u_manipulability_limit.real = this->manipulability_limit;
      *(outbuffer + offset + 0) = (u_manipulability_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_manipulability_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_manipulability_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_manipulability_limit.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_manipulability_limit.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_manipulability_limit.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_manipulability_limit.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_manipulability_limit.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->manipulability_limit);
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
      *(outbuffer + offset++) = ik_optional_weight_vector_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ik_optional_weight_vector_length; i++){
      union {
        double real;
        uint64_t base;
      } u_ik_optional_weight_vectori;
      u_ik_optional_weight_vectori.real = this->ik_optional_weight_vector[i];
      *(outbuffer + offset + 0) = (u_ik_optional_weight_vectori.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ik_optional_weight_vectori.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ik_optional_weight_vectori.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ik_optional_weight_vectori.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ik_optional_weight_vectori.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ik_optional_weight_vectori.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ik_optional_weight_vectori.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ik_optional_weight_vectori.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ik_optional_weight_vector[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_sh_base_pos_rpy;
      u_use_sh_base_pos_rpy.real = this->use_sh_base_pos_rpy;
      *(outbuffer + offset + 0) = (u_use_sh_base_pos_rpy.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_sh_base_pos_rpy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_M_p;
      u_M_p.base = 0;
      u_M_p.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_M_p.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_M_p.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_M_p.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_M_p.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_M_p.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_M_p.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_M_p.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->M_p = u_M_p.real;
      offset += sizeof(this->M_p);
      union {
        double real;
        uint64_t base;
      } u_D_p;
      u_D_p.base = 0;
      u_D_p.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_D_p.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_D_p.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_D_p.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_D_p.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_D_p.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_D_p.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_D_p.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->D_p = u_D_p.real;
      offset += sizeof(this->D_p);
      union {
        double real;
        uint64_t base;
      } u_K_p;
      u_K_p.base = 0;
      u_K_p.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_K_p.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_K_p.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_K_p.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_K_p.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_K_p.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_K_p.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_K_p.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->K_p = u_K_p.real;
      offset += sizeof(this->K_p);
      union {
        double real;
        uint64_t base;
      } u_M_r;
      u_M_r.base = 0;
      u_M_r.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_M_r.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_M_r.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_M_r.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_M_r.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_M_r.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_M_r.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_M_r.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->M_r = u_M_r.real;
      offset += sizeof(this->M_r);
      union {
        double real;
        uint64_t base;
      } u_D_r;
      u_D_r.base = 0;
      u_D_r.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_D_r.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_D_r.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_D_r.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_D_r.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_D_r.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_D_r.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_D_r.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->D_r = u_D_r.real;
      offset += sizeof(this->D_r);
      union {
        double real;
        uint64_t base;
      } u_K_r;
      u_K_r.base = 0;
      u_K_r.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_K_r.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_K_r.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_K_r.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_K_r.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_K_r.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_K_r.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_K_r.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->K_r = u_K_r.real;
      offset += sizeof(this->K_r);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_force_gaini;
      u_force_gaini.base = 0;
      u_force_gaini.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force_gaini.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force_gaini.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force_gaini.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_force_gaini.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_force_gaini.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_force_gaini.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_force_gaini.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->force_gain[i] = u_force_gaini.real;
      offset += sizeof(this->force_gain[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_moment_gaini;
      u_moment_gaini.base = 0;
      u_moment_gaini.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_moment_gaini.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_moment_gaini.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_moment_gaini.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_moment_gaini.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_moment_gaini.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_moment_gaini.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_moment_gaini.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->moment_gain[i] = u_moment_gaini.real;
      offset += sizeof(this->moment_gain[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_sr_gain;
      u_sr_gain.base = 0;
      u_sr_gain.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sr_gain.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sr_gain.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sr_gain.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sr_gain.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sr_gain.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sr_gain.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sr_gain.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sr_gain = u_sr_gain.real;
      offset += sizeof(this->sr_gain);
      union {
        double real;
        uint64_t base;
      } u_avoid_gain;
      u_avoid_gain.base = 0;
      u_avoid_gain.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_avoid_gain.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_avoid_gain.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_avoid_gain.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_avoid_gain.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_avoid_gain.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_avoid_gain.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_avoid_gain.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->avoid_gain = u_avoid_gain.real;
      offset += sizeof(this->avoid_gain);
      union {
        double real;
        uint64_t base;
      } u_reference_gain;
      u_reference_gain.base = 0;
      u_reference_gain.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reference_gain.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reference_gain.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reference_gain.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_reference_gain.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_reference_gain.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_reference_gain.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_reference_gain.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->reference_gain = u_reference_gain.real;
      offset += sizeof(this->reference_gain);
      union {
        double real;
        uint64_t base;
      } u_manipulability_limit;
      u_manipulability_limit.base = 0;
      u_manipulability_limit.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_manipulability_limit.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_manipulability_limit.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_manipulability_limit.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_manipulability_limit.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_manipulability_limit.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_manipulability_limit.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_manipulability_limit.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->manipulability_limit = u_manipulability_limit.real;
      offset += sizeof(this->manipulability_limit);
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
      uint8_t ik_optional_weight_vector_lengthT = *(inbuffer + offset++);
      if(ik_optional_weight_vector_lengthT > ik_optional_weight_vector_length)
        this->ik_optional_weight_vector = (double*)realloc(this->ik_optional_weight_vector, ik_optional_weight_vector_lengthT * sizeof(double));
      offset += 3;
      ik_optional_weight_vector_length = ik_optional_weight_vector_lengthT;
      for( uint8_t i = 0; i < ik_optional_weight_vector_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_ik_optional_weight_vector;
      u_st_ik_optional_weight_vector.base = 0;
      u_st_ik_optional_weight_vector.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ik_optional_weight_vector.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ik_optional_weight_vector.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ik_optional_weight_vector.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_ik_optional_weight_vector.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_ik_optional_weight_vector.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_ik_optional_weight_vector.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_ik_optional_weight_vector.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_ik_optional_weight_vector = u_st_ik_optional_weight_vector.real;
      offset += sizeof(this->st_ik_optional_weight_vector);
        memcpy( &(this->ik_optional_weight_vector[i]), &(this->st_ik_optional_weight_vector), sizeof(double));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_sh_base_pos_rpy;
      u_use_sh_base_pos_rpy.base = 0;
      u_use_sh_base_pos_rpy.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_sh_base_pos_rpy = u_use_sh_base_pos_rpy.real;
      offset += sizeof(this->use_sh_base_pos_rpy);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_impedanceParam"; };
    const char * getMD5(){ return "93910157f4c229ccb0ff5677c4006630"; };

  };

}
#endif