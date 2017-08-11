#ifndef _ROS_aerial_robot_base_FlightNav_h
#define _ROS_aerial_robot_base_FlightNav_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace aerial_robot_base
{

  class FlightNav : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t control_frame;
      uint8_t target;
      uint8_t pos_xy_nav_mode;
      float target_pos_x;
      float target_vel_x;
      float target_acc_x;
      float target_pos_y;
      float target_vel_y;
      float target_acc_y;
      uint8_t psi_nav_mode;
      float target_vel_psi;
      float target_psi;
      uint8_t pos_z_nav_mode;
      float target_pos_z;
      float target_pos_diff_z;
      enum { NO_NAVIGATION =  0 };
      enum { VEL_MODE =  1 };
      enum { POS_MODE =  2 };
      enum { ACC_MODE =  3 };
      enum { WORLD_FRAME =  0 };
      enum { LOCAL_FRAME =  1 };
      enum { BASELINK =  0 };
      enum { COG =  1 };

    FlightNav():
      header(),
      control_frame(0),
      target(0),
      pos_xy_nav_mode(0),
      target_pos_x(0),
      target_vel_x(0),
      target_acc_x(0),
      target_pos_y(0),
      target_vel_y(0),
      target_acc_y(0),
      psi_nav_mode(0),
      target_vel_psi(0),
      target_psi(0),
      pos_z_nav_mode(0),
      target_pos_z(0),
      target_pos_diff_z(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->control_frame >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_frame);
      *(outbuffer + offset + 0) = (this->target >> (8 * 0)) & 0xFF;
      offset += sizeof(this->target);
      *(outbuffer + offset + 0) = (this->pos_xy_nav_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pos_xy_nav_mode);
      union {
        float real;
        uint32_t base;
      } u_target_pos_x;
      u_target_pos_x.real = this->target_pos_x;
      *(outbuffer + offset + 0) = (u_target_pos_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_pos_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_pos_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_pos_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_pos_x);
      union {
        float real;
        uint32_t base;
      } u_target_vel_x;
      u_target_vel_x.real = this->target_vel_x;
      *(outbuffer + offset + 0) = (u_target_vel_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_vel_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_vel_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_vel_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_vel_x);
      union {
        float real;
        uint32_t base;
      } u_target_acc_x;
      u_target_acc_x.real = this->target_acc_x;
      *(outbuffer + offset + 0) = (u_target_acc_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_acc_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_acc_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_acc_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_acc_x);
      union {
        float real;
        uint32_t base;
      } u_target_pos_y;
      u_target_pos_y.real = this->target_pos_y;
      *(outbuffer + offset + 0) = (u_target_pos_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_pos_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_pos_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_pos_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_pos_y);
      union {
        float real;
        uint32_t base;
      } u_target_vel_y;
      u_target_vel_y.real = this->target_vel_y;
      *(outbuffer + offset + 0) = (u_target_vel_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_vel_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_vel_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_vel_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_vel_y);
      union {
        float real;
        uint32_t base;
      } u_target_acc_y;
      u_target_acc_y.real = this->target_acc_y;
      *(outbuffer + offset + 0) = (u_target_acc_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_acc_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_acc_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_acc_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_acc_y);
      *(outbuffer + offset + 0) = (this->psi_nav_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->psi_nav_mode);
      union {
        float real;
        uint32_t base;
      } u_target_vel_psi;
      u_target_vel_psi.real = this->target_vel_psi;
      *(outbuffer + offset + 0) = (u_target_vel_psi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_vel_psi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_vel_psi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_vel_psi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_vel_psi);
      union {
        float real;
        uint32_t base;
      } u_target_psi;
      u_target_psi.real = this->target_psi;
      *(outbuffer + offset + 0) = (u_target_psi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_psi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_psi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_psi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_psi);
      *(outbuffer + offset + 0) = (this->pos_z_nav_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pos_z_nav_mode);
      union {
        float real;
        uint32_t base;
      } u_target_pos_z;
      u_target_pos_z.real = this->target_pos_z;
      *(outbuffer + offset + 0) = (u_target_pos_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_pos_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_pos_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_pos_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_pos_z);
      union {
        float real;
        uint32_t base;
      } u_target_pos_diff_z;
      u_target_pos_diff_z.real = this->target_pos_diff_z;
      *(outbuffer + offset + 0) = (u_target_pos_diff_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_pos_diff_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_target_pos_diff_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_target_pos_diff_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_pos_diff_z);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->control_frame =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_frame);
      this->target =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->target);
      this->pos_xy_nav_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pos_xy_nav_mode);
      union {
        float real;
        uint32_t base;
      } u_target_pos_x;
      u_target_pos_x.base = 0;
      u_target_pos_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_pos_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_pos_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_pos_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_pos_x = u_target_pos_x.real;
      offset += sizeof(this->target_pos_x);
      union {
        float real;
        uint32_t base;
      } u_target_vel_x;
      u_target_vel_x.base = 0;
      u_target_vel_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_vel_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_vel_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_vel_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_vel_x = u_target_vel_x.real;
      offset += sizeof(this->target_vel_x);
      union {
        float real;
        uint32_t base;
      } u_target_acc_x;
      u_target_acc_x.base = 0;
      u_target_acc_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_acc_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_acc_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_acc_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_acc_x = u_target_acc_x.real;
      offset += sizeof(this->target_acc_x);
      union {
        float real;
        uint32_t base;
      } u_target_pos_y;
      u_target_pos_y.base = 0;
      u_target_pos_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_pos_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_pos_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_pos_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_pos_y = u_target_pos_y.real;
      offset += sizeof(this->target_pos_y);
      union {
        float real;
        uint32_t base;
      } u_target_vel_y;
      u_target_vel_y.base = 0;
      u_target_vel_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_vel_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_vel_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_vel_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_vel_y = u_target_vel_y.real;
      offset += sizeof(this->target_vel_y);
      union {
        float real;
        uint32_t base;
      } u_target_acc_y;
      u_target_acc_y.base = 0;
      u_target_acc_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_acc_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_acc_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_acc_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_acc_y = u_target_acc_y.real;
      offset += sizeof(this->target_acc_y);
      this->psi_nav_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->psi_nav_mode);
      union {
        float real;
        uint32_t base;
      } u_target_vel_psi;
      u_target_vel_psi.base = 0;
      u_target_vel_psi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_vel_psi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_vel_psi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_vel_psi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_vel_psi = u_target_vel_psi.real;
      offset += sizeof(this->target_vel_psi);
      union {
        float real;
        uint32_t base;
      } u_target_psi;
      u_target_psi.base = 0;
      u_target_psi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_psi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_psi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_psi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_psi = u_target_psi.real;
      offset += sizeof(this->target_psi);
      this->pos_z_nav_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pos_z_nav_mode);
      union {
        float real;
        uint32_t base;
      } u_target_pos_z;
      u_target_pos_z.base = 0;
      u_target_pos_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_pos_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_pos_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_pos_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_pos_z = u_target_pos_z.real;
      offset += sizeof(this->target_pos_z);
      union {
        float real;
        uint32_t base;
      } u_target_pos_diff_z;
      u_target_pos_diff_z.base = 0;
      u_target_pos_diff_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_pos_diff_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_target_pos_diff_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_target_pos_diff_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->target_pos_diff_z = u_target_pos_diff_z.real;
      offset += sizeof(this->target_pos_diff_z);
     return offset;
    }

    const char * getType(){ return "aerial_robot_base/FlightNav"; };
    const char * getMD5(){ return "747ed9b839be4ff9f5f3fb3dfae5d932"; };

  };

}
#endif