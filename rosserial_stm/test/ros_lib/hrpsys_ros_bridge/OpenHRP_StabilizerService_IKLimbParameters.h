#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_IKLimbParameters_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_IKLimbParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_IKLimbParameters : public ros::Msg
  {
    public:
      uint8_t ik_optional_weight_vector_length;
      double st_ik_optional_weight_vector;
      double * ik_optional_weight_vector;
      double sr_gain;
      double avoid_gain;
      double reference_gain;
      double manipulability_limit;

    OpenHRP_StabilizerService_IKLimbParameters():
      ik_optional_weight_vector_length(0), ik_optional_weight_vector(NULL),
      sr_gain(0),
      avoid_gain(0),
      reference_gain(0),
      manipulability_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_IKLimbParameters"; };
    const char * getMD5(){ return "970ca9b7a300937198127b6ecce51930"; };

  };

}
#endif