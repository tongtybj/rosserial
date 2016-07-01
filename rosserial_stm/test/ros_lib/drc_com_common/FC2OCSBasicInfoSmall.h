#ifndef _ROS_drc_com_common_FC2OCSBasicInfoSmall_h
#define _ROS_drc_com_common_FC2OCSBasicInfoSmall_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_com_common
{

  class FC2OCSBasicInfoSmall : public ros::Msg
  {
    public:
      float angles[35];
      uint8_t effort[35];
      uint8_t temperature[35];
      int8_t arm_forces[12];
      int8_t leg_forces[12];
      float odom_on_ground[6];
      float ground[6];
      float odom[6];
      float imu[4];
      uint8_t robot_state;
      uint8_t abs_diff[33];
      uint8_t vin;
      uint8_t vdd;
      uint8_t vpc;

    FC2OCSBasicInfoSmall():
      angles(),
      effort(),
      temperature(),
      arm_forces(),
      leg_forces(),
      odom_on_ground(),
      ground(),
      odom(),
      imu(),
      robot_state(0),
      abs_diff(),
      vin(0),
      vdd(0),
      vpc(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 35; i++){
      union {
        float real;
        uint32_t base;
      } u_anglesi;
      u_anglesi.real = this->angles[i];
      *(outbuffer + offset + 0) = (u_anglesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anglesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anglesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anglesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angles[i]);
      }
      for( uint8_t i = 0; i < 35; i++){
      *(outbuffer + offset + 0) = (this->effort[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->effort[i]);
      }
      for( uint8_t i = 0; i < 35; i++){
      *(outbuffer + offset + 0) = (this->temperature[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_arm_forcesi;
      u_arm_forcesi.real = this->arm_forces[i];
      *(outbuffer + offset + 0) = (u_arm_forcesi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->arm_forces[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_leg_forcesi;
      u_leg_forcesi.real = this->leg_forces[i];
      *(outbuffer + offset + 0) = (u_leg_forcesi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->leg_forces[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_odom_on_groundi;
      u_odom_on_groundi.real = this->odom_on_ground[i];
      *(outbuffer + offset + 0) = (u_odom_on_groundi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odom_on_groundi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_odom_on_groundi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_odom_on_groundi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->odom_on_ground[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_groundi;
      u_groundi.real = this->ground[i];
      *(outbuffer + offset + 0) = (u_groundi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_groundi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_groundi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_groundi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ground[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_odomi;
      u_odomi.real = this->odom[i];
      *(outbuffer + offset + 0) = (u_odomi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_odomi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_odomi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_odomi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->odom[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_imui;
      u_imui.real = this->imu[i];
      *(outbuffer + offset + 0) = (u_imui.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imui.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imui.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imui.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imu[i]);
      }
      *(outbuffer + offset + 0) = (this->robot_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->robot_state);
      for( uint8_t i = 0; i < 33; i++){
      *(outbuffer + offset + 0) = (this->abs_diff[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->abs_diff[i]);
      }
      *(outbuffer + offset + 0) = (this->vin >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vin);
      *(outbuffer + offset + 0) = (this->vdd >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vdd);
      *(outbuffer + offset + 0) = (this->vpc >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vpc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 35; i++){
      union {
        float real;
        uint32_t base;
      } u_anglesi;
      u_anglesi.base = 0;
      u_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_anglesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angles[i] = u_anglesi.real;
      offset += sizeof(this->angles[i]);
      }
      for( uint8_t i = 0; i < 35; i++){
      this->effort[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->effort[i]);
      }
      for( uint8_t i = 0; i < 35; i++){
      this->temperature[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->temperature[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_arm_forcesi;
      u_arm_forcesi.base = 0;
      u_arm_forcesi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->arm_forces[i] = u_arm_forcesi.real;
      offset += sizeof(this->arm_forces[i]);
      }
      for( uint8_t i = 0; i < 12; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_leg_forcesi;
      u_leg_forcesi.base = 0;
      u_leg_forcesi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->leg_forces[i] = u_leg_forcesi.real;
      offset += sizeof(this->leg_forces[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_odom_on_groundi;
      u_odom_on_groundi.base = 0;
      u_odom_on_groundi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odom_on_groundi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_odom_on_groundi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_odom_on_groundi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->odom_on_ground[i] = u_odom_on_groundi.real;
      offset += sizeof(this->odom_on_ground[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_groundi;
      u_groundi.base = 0;
      u_groundi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_groundi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_groundi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_groundi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ground[i] = u_groundi.real;
      offset += sizeof(this->ground[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_odomi;
      u_odomi.base = 0;
      u_odomi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_odomi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_odomi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_odomi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->odom[i] = u_odomi.real;
      offset += sizeof(this->odom[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_imui;
      u_imui.base = 0;
      u_imui.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imui.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imui.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imui.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imu[i] = u_imui.real;
      offset += sizeof(this->imu[i]);
      }
      this->robot_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->robot_state);
      for( uint8_t i = 0; i < 33; i++){
      this->abs_diff[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->abs_diff[i]);
      }
      this->vin =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vin);
      this->vdd =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vdd);
      this->vpc =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vpc);
     return offset;
    }

    const char * getType(){ return "drc_com_common/FC2OCSBasicInfoSmall"; };
    const char * getMD5(){ return "cfec9b8f076ac6926c00076ef892a6db"; };

  };

}
#endif