#ifndef _ROS_multisense_ros_RawCamCal_h
#define _ROS_multisense_ros_RawCamCal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multisense_ros
{

  class RawCamCal : public ros::Msg
  {
    public:
      float left_M[9];
      float left_D[8];
      float left_R[9];
      float left_P[12];
      float right_M[9];
      float right_D[8];
      float right_R[9];
      float right_P[12];

    RawCamCal():
      left_M(),
      left_D(),
      left_R(),
      left_P(),
      right_M(),
      right_D(),
      right_R(),
      right_P()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_left_Mi;
      u_left_Mi.real = this->left_M[i];
      *(outbuffer + offset + 0) = (u_left_Mi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_Mi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_Mi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_Mi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_M[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        float real;
        uint32_t base;
      } u_left_Di;
      u_left_Di.real = this->left_D[i];
      *(outbuffer + offset + 0) = (u_left_Di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_Di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_Di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_Di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_D[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_left_Ri;
      u_left_Ri.real = this->left_R[i];
      *(outbuffer + offset + 0) = (u_left_Ri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_Ri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_Ri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_Ri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_R[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      union {
        float real;
        uint32_t base;
      } u_left_Pi;
      u_left_Pi.real = this->left_P[i];
      *(outbuffer + offset + 0) = (u_left_Pi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_Pi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_Pi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_Pi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_P[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_right_Mi;
      u_right_Mi.real = this->right_M[i];
      *(outbuffer + offset + 0) = (u_right_Mi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_Mi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_Mi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_Mi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_M[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        float real;
        uint32_t base;
      } u_right_Di;
      u_right_Di.real = this->right_D[i];
      *(outbuffer + offset + 0) = (u_right_Di.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_Di.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_Di.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_Di.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_D[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_right_Ri;
      u_right_Ri.real = this->right_R[i];
      *(outbuffer + offset + 0) = (u_right_Ri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_Ri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_Ri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_Ri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_R[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      union {
        float real;
        uint32_t base;
      } u_right_Pi;
      u_right_Pi.real = this->right_P[i];
      *(outbuffer + offset + 0) = (u_right_Pi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_Pi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_Pi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_Pi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_P[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_left_Mi;
      u_left_Mi.base = 0;
      u_left_Mi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_Mi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_Mi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_Mi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_M[i] = u_left_Mi.real;
      offset += sizeof(this->left_M[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        float real;
        uint32_t base;
      } u_left_Di;
      u_left_Di.base = 0;
      u_left_Di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_Di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_Di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_Di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_D[i] = u_left_Di.real;
      offset += sizeof(this->left_D[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_left_Ri;
      u_left_Ri.base = 0;
      u_left_Ri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_Ri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_Ri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_Ri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_R[i] = u_left_Ri.real;
      offset += sizeof(this->left_R[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      union {
        float real;
        uint32_t base;
      } u_left_Pi;
      u_left_Pi.base = 0;
      u_left_Pi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_Pi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_Pi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_Pi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_P[i] = u_left_Pi.real;
      offset += sizeof(this->left_P[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_right_Mi;
      u_right_Mi.base = 0;
      u_right_Mi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_Mi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_Mi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_Mi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_M[i] = u_right_Mi.real;
      offset += sizeof(this->right_M[i]);
      }
      for( uint8_t i = 0; i < 8; i++){
      union {
        float real;
        uint32_t base;
      } u_right_Di;
      u_right_Di.base = 0;
      u_right_Di.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_Di.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_Di.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_Di.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_D[i] = u_right_Di.real;
      offset += sizeof(this->right_D[i]);
      }
      for( uint8_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_right_Ri;
      u_right_Ri.base = 0;
      u_right_Ri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_Ri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_Ri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_Ri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_R[i] = u_right_Ri.real;
      offset += sizeof(this->right_R[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      union {
        float real;
        uint32_t base;
      } u_right_Pi;
      u_right_Pi.base = 0;
      u_right_Pi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_Pi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_Pi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_Pi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_P[i] = u_right_Pi.real;
      offset += sizeof(this->right_P[i]);
      }
     return offset;
    }

    const char * getType(){ return "multisense_ros/RawCamCal"; };
    const char * getMD5(){ return "1b8c86de8eb033489e8e49fb5532702e"; };

  };

}
#endif