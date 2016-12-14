#ifndef _ROS_multisense_ros_RawCamConfig_h
#define _ROS_multisense_ros_RawCamConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multisense_ros
{

  class RawCamConfig : public ros::Msg
  {
    public:
      uint16_t width;
      uint16_t height;
      float frames_per_second;
      float gain;
      uint32_t exposure_time;
      float fx;
      float fy;
      float cx;
      float cy;
      float tx;
      float ty;
      float tz;
      float roll;
      float pitch;
      float yaw;

    RawCamConfig():
      width(0),
      height(0),
      frames_per_second(0),
      gain(0),
      exposure_time(0),
      fx(0),
      fy(0),
      cx(0),
      cy(0),
      tx(0),
      ty(0),
      tz(0),
      roll(0),
      pitch(0),
      yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_frames_per_second;
      u_frames_per_second.real = this->frames_per_second;
      *(outbuffer + offset + 0) = (u_frames_per_second.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frames_per_second.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frames_per_second.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frames_per_second.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frames_per_second);
      union {
        float real;
        uint32_t base;
      } u_gain;
      u_gain.real = this->gain;
      *(outbuffer + offset + 0) = (u_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gain.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gain);
      *(outbuffer + offset + 0) = (this->exposure_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->exposure_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->exposure_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->exposure_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exposure_time);
      union {
        float real;
        uint32_t base;
      } u_fx;
      u_fx.real = this->fx;
      *(outbuffer + offset + 0) = (u_fx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fx);
      union {
        float real;
        uint32_t base;
      } u_fy;
      u_fy.real = this->fy;
      *(outbuffer + offset + 0) = (u_fy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fy);
      union {
        float real;
        uint32_t base;
      } u_cx;
      u_cx.real = this->cx;
      *(outbuffer + offset + 0) = (u_cx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cx);
      union {
        float real;
        uint32_t base;
      } u_cy;
      u_cy.real = this->cy;
      *(outbuffer + offset + 0) = (u_cy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cy);
      union {
        float real;
        uint32_t base;
      } u_tx;
      u_tx.real = this->tx;
      *(outbuffer + offset + 0) = (u_tx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tx);
      union {
        float real;
        uint32_t base;
      } u_ty;
      u_ty.real = this->ty;
      *(outbuffer + offset + 0) = (u_ty.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ty.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ty.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ty.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ty);
      union {
        float real;
        uint32_t base;
      } u_tz;
      u_tz.real = this->tz;
      *(outbuffer + offset + 0) = (u_tz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tz);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.real = this->roll;
      *(outbuffer + offset + 0) = (u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.real = this->pitch;
      *(outbuffer + offset + 0) = (u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->width =  ((uint16_t) (*(inbuffer + offset)));
      this->width |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->width);
      this->height =  ((uint16_t) (*(inbuffer + offset)));
      this->height |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_frames_per_second;
      u_frames_per_second.base = 0;
      u_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frames_per_second = u_frames_per_second.real;
      offset += sizeof(this->frames_per_second);
      union {
        float real;
        uint32_t base;
      } u_gain;
      u_gain.base = 0;
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gain = u_gain.real;
      offset += sizeof(this->gain);
      this->exposure_time =  ((uint32_t) (*(inbuffer + offset)));
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->exposure_time);
      union {
        float real;
        uint32_t base;
      } u_fx;
      u_fx.base = 0;
      u_fx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fx = u_fx.real;
      offset += sizeof(this->fx);
      union {
        float real;
        uint32_t base;
      } u_fy;
      u_fy.base = 0;
      u_fy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fy = u_fy.real;
      offset += sizeof(this->fy);
      union {
        float real;
        uint32_t base;
      } u_cx;
      u_cx.base = 0;
      u_cx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cx = u_cx.real;
      offset += sizeof(this->cx);
      union {
        float real;
        uint32_t base;
      } u_cy;
      u_cy.base = 0;
      u_cy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cy = u_cy.real;
      offset += sizeof(this->cy);
      union {
        float real;
        uint32_t base;
      } u_tx;
      u_tx.base = 0;
      u_tx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tx = u_tx.real;
      offset += sizeof(this->tx);
      union {
        float real;
        uint32_t base;
      } u_ty;
      u_ty.base = 0;
      u_ty.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ty.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ty.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ty.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ty = u_ty.real;
      offset += sizeof(this->ty);
      union {
        float real;
        uint32_t base;
      } u_tz;
      u_tz.base = 0;
      u_tz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tz = u_tz.real;
      offset += sizeof(this->tz);
      union {
        float real;
        uint32_t base;
      } u_roll;
      u_roll.base = 0;
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->roll = u_roll.real;
      offset += sizeof(this->roll);
      union {
        float real;
        uint32_t base;
      } u_pitch;
      u_pitch.base = 0;
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pitch = u_pitch.real;
      offset += sizeof(this->pitch);
      union {
        float real;
        uint32_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
     return offset;
    }

    const char * getType(){ return "multisense_ros/RawCamConfig"; };
    const char * getMD5(){ return "cfc6caf0d17e5d50531b927f32fd6a90"; };

  };

}
#endif