#ifndef _ROS_hydrus_transform_control_RollPitchYawGain_h
#define _ROS_hydrus_transform_control_RollPitchYawGain_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus_transform_control
{

  class RollPitchYawGain : public ros::Msg
  {
    public:
      int16_t roll_p_gain[6];
      int16_t roll_i_gain[6];
      int16_t roll_d_gain[6];
      int16_t pitch_p_gain[6];
      int16_t pitch_i_gain[6];
      int16_t pitch_d_gain[6];
      int16_t yaw_d_gain[6];

    RollPitchYawGain():
      roll_p_gain(),
      roll_i_gain(),
      roll_d_gain(),
      pitch_p_gain(),
      pitch_i_gain(),
      pitch_d_gain(),
      yaw_d_gain()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_roll_p_gaini;
      u_roll_p_gaini.real = this->roll_p_gain[i];
      *(outbuffer + offset + 0) = (u_roll_p_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_p_gaini.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll_p_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_roll_i_gaini;
      u_roll_i_gaini.real = this->roll_i_gain[i];
      *(outbuffer + offset + 0) = (u_roll_i_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_i_gaini.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll_i_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_roll_d_gaini;
      u_roll_d_gaini.real = this->roll_d_gain[i];
      *(outbuffer + offset + 0) = (u_roll_d_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll_d_gaini.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->roll_d_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_p_gaini;
      u_pitch_p_gaini.real = this->pitch_p_gain[i];
      *(outbuffer + offset + 0) = (u_pitch_p_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_p_gaini.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch_p_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_i_gaini;
      u_pitch_i_gaini.real = this->pitch_i_gain[i];
      *(outbuffer + offset + 0) = (u_pitch_i_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_i_gaini.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch_i_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_d_gaini;
      u_pitch_d_gaini.real = this->pitch_d_gain[i];
      *(outbuffer + offset + 0) = (u_pitch_d_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch_d_gaini.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pitch_d_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_d_gaini;
      u_yaw_d_gaini.real = this->yaw_d_gain[i];
      *(outbuffer + offset + 0) = (u_yaw_d_gaini.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_d_gaini.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_d_gain[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_roll_p_gaini;
      u_roll_p_gaini.base = 0;
      u_roll_p_gaini.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_p_gaini.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll_p_gain[i] = u_roll_p_gaini.real;
      offset += sizeof(this->roll_p_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_roll_i_gaini;
      u_roll_i_gaini.base = 0;
      u_roll_i_gaini.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_i_gaini.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll_i_gain[i] = u_roll_i_gaini.real;
      offset += sizeof(this->roll_i_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_roll_d_gaini;
      u_roll_d_gaini.base = 0;
      u_roll_d_gaini.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll_d_gaini.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->roll_d_gain[i] = u_roll_d_gaini.real;
      offset += sizeof(this->roll_d_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_p_gaini;
      u_pitch_p_gaini.base = 0;
      u_pitch_p_gaini.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_p_gaini.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch_p_gain[i] = u_pitch_p_gaini.real;
      offset += sizeof(this->pitch_p_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_i_gaini;
      u_pitch_i_gaini.base = 0;
      u_pitch_i_gaini.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_i_gaini.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch_i_gain[i] = u_pitch_i_gaini.real;
      offset += sizeof(this->pitch_i_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pitch_d_gaini;
      u_pitch_d_gaini.base = 0;
      u_pitch_d_gaini.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch_d_gaini.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pitch_d_gain[i] = u_pitch_d_gaini.real;
      offset += sizeof(this->pitch_d_gain[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_yaw_d_gaini;
      u_yaw_d_gaini.base = 0;
      u_yaw_d_gaini.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_d_gaini.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw_d_gain[i] = u_yaw_d_gaini.real;
      offset += sizeof(this->yaw_d_gain[i]);
      }
     return offset;
    }

    const char * getType(){ return "hydrus_transform_control/RollPitchYawGain"; };
    const char * getMD5(){ return "5d4527b390baee83b5733c8e324a3aca"; };

  };

}
#endif