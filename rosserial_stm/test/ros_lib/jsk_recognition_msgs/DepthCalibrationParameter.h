#ifndef _ROS_jsk_recognition_msgs_DepthCalibrationParameter_h
#define _ROS_jsk_recognition_msgs_DepthCalibrationParameter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_recognition_msgs
{

  class DepthCalibrationParameter : public ros::Msg
  {
    public:
      uint8_t coefficients2_length;
      double st_coefficients2;
      double * coefficients2;
      uint8_t coefficients1_length;
      double st_coefficients1;
      double * coefficients1;
      uint8_t coefficients0_length;
      double st_coefficients0;
      double * coefficients0;
      bool use_abs;

    DepthCalibrationParameter():
      coefficients2_length(0), coefficients2(NULL),
      coefficients1_length(0), coefficients1(NULL),
      coefficients0_length(0), coefficients0(NULL),
      use_abs(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = coefficients2_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < coefficients2_length; i++){
      union {
        double real;
        uint64_t base;
      } u_coefficients2i;
      u_coefficients2i.real = this->coefficients2[i];
      *(outbuffer + offset + 0) = (u_coefficients2i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coefficients2i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coefficients2i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coefficients2i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_coefficients2i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_coefficients2i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_coefficients2i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_coefficients2i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->coefficients2[i]);
      }
      *(outbuffer + offset++) = coefficients1_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < coefficients1_length; i++){
      union {
        double real;
        uint64_t base;
      } u_coefficients1i;
      u_coefficients1i.real = this->coefficients1[i];
      *(outbuffer + offset + 0) = (u_coefficients1i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coefficients1i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coefficients1i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coefficients1i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_coefficients1i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_coefficients1i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_coefficients1i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_coefficients1i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->coefficients1[i]);
      }
      *(outbuffer + offset++) = coefficients0_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < coefficients0_length; i++){
      union {
        double real;
        uint64_t base;
      } u_coefficients0i;
      u_coefficients0i.real = this->coefficients0[i];
      *(outbuffer + offset + 0) = (u_coefficients0i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coefficients0i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coefficients0i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coefficients0i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_coefficients0i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_coefficients0i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_coefficients0i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_coefficients0i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->coefficients0[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_use_abs;
      u_use_abs.real = this->use_abs;
      *(outbuffer + offset + 0) = (u_use_abs.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_abs);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t coefficients2_lengthT = *(inbuffer + offset++);
      if(coefficients2_lengthT > coefficients2_length)
        this->coefficients2 = (double*)realloc(this->coefficients2, coefficients2_lengthT * sizeof(double));
      offset += 3;
      coefficients2_length = coefficients2_lengthT;
      for( uint8_t i = 0; i < coefficients2_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_coefficients2;
      u_st_coefficients2.base = 0;
      u_st_coefficients2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_coefficients2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_coefficients2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_coefficients2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_coefficients2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_coefficients2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_coefficients2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_coefficients2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_coefficients2 = u_st_coefficients2.real;
      offset += sizeof(this->st_coefficients2);
        memcpy( &(this->coefficients2[i]), &(this->st_coefficients2), sizeof(double));
      }
      uint8_t coefficients1_lengthT = *(inbuffer + offset++);
      if(coefficients1_lengthT > coefficients1_length)
        this->coefficients1 = (double*)realloc(this->coefficients1, coefficients1_lengthT * sizeof(double));
      offset += 3;
      coefficients1_length = coefficients1_lengthT;
      for( uint8_t i = 0; i < coefficients1_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_coefficients1;
      u_st_coefficients1.base = 0;
      u_st_coefficients1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_coefficients1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_coefficients1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_coefficients1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_coefficients1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_coefficients1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_coefficients1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_coefficients1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_coefficients1 = u_st_coefficients1.real;
      offset += sizeof(this->st_coefficients1);
        memcpy( &(this->coefficients1[i]), &(this->st_coefficients1), sizeof(double));
      }
      uint8_t coefficients0_lengthT = *(inbuffer + offset++);
      if(coefficients0_lengthT > coefficients0_length)
        this->coefficients0 = (double*)realloc(this->coefficients0, coefficients0_lengthT * sizeof(double));
      offset += 3;
      coefficients0_length = coefficients0_lengthT;
      for( uint8_t i = 0; i < coefficients0_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_coefficients0;
      u_st_coefficients0.base = 0;
      u_st_coefficients0.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_coefficients0.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_coefficients0.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_coefficients0.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_coefficients0.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_coefficients0.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_coefficients0.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_coefficients0.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_coefficients0 = u_st_coefficients0.real;
      offset += sizeof(this->st_coefficients0);
        memcpy( &(this->coefficients0[i]), &(this->st_coefficients0), sizeof(double));
      }
      union {
        bool real;
        uint8_t base;
      } u_use_abs;
      u_use_abs.base = 0;
      u_use_abs.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_abs = u_use_abs.real;
      offset += sizeof(this->use_abs);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/DepthCalibrationParameter"; };
    const char * getMD5(){ return "d8318983ee0a76ad66ecf4b504350888"; };

  };

}
#endif