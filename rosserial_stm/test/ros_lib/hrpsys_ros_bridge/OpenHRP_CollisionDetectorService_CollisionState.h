#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_CollisionDetectorService_CollisionState_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_CollisionDetectorService_CollisionState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_CollisionDetectorService_CollisionState : public ros::Msg
  {
    public:
      double time;
      double computation_time;
      bool safe_posture;
      double recover_time;
      int16_t loop_for_check;
      uint8_t angle_length;
      double st_angle;
      double * angle;
      uint8_t collide_length;
      bool st_collide;
      bool * collide;
      std_msgs::Float64MultiArray lines;

    OpenHRP_CollisionDetectorService_CollisionState():
      time(0),
      computation_time(0),
      safe_posture(0),
      recover_time(0),
      loop_for_check(0),
      angle_length(0), angle(NULL),
      collide_length(0), collide(NULL),
      lines()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_time;
      u_time.real = this->time;
      *(outbuffer + offset + 0) = (u_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->time);
      union {
        double real;
        uint64_t base;
      } u_computation_time;
      u_computation_time.real = this->computation_time;
      *(outbuffer + offset + 0) = (u_computation_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_computation_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_computation_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_computation_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_computation_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_computation_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_computation_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_computation_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->computation_time);
      union {
        bool real;
        uint8_t base;
      } u_safe_posture;
      u_safe_posture.real = this->safe_posture;
      *(outbuffer + offset + 0) = (u_safe_posture.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->safe_posture);
      union {
        double real;
        uint64_t base;
      } u_recover_time;
      u_recover_time.real = this->recover_time;
      *(outbuffer + offset + 0) = (u_recover_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_recover_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_recover_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_recover_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_recover_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_recover_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_recover_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_recover_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->recover_time);
      union {
        int16_t real;
        uint16_t base;
      } u_loop_for_check;
      u_loop_for_check.real = this->loop_for_check;
      *(outbuffer + offset + 0) = (u_loop_for_check.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_loop_for_check.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->loop_for_check);
      *(outbuffer + offset++) = angle_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < angle_length; i++){
      union {
        double real;
        uint64_t base;
      } u_anglei;
      u_anglei.real = this->angle[i];
      *(outbuffer + offset + 0) = (u_anglei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anglei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anglei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anglei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_anglei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_anglei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_anglei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_anglei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->angle[i]);
      }
      *(outbuffer + offset++) = collide_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < collide_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_collidei;
      u_collidei.real = this->collide[i];
      *(outbuffer + offset + 0) = (u_collidei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->collide[i]);
      }
      offset += this->lines.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_time;
      u_time.base = 0;
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->time = u_time.real;
      offset += sizeof(this->time);
      union {
        double real;
        uint64_t base;
      } u_computation_time;
      u_computation_time.base = 0;
      u_computation_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_computation_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_computation_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_computation_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_computation_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_computation_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_computation_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_computation_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->computation_time = u_computation_time.real;
      offset += sizeof(this->computation_time);
      union {
        bool real;
        uint8_t base;
      } u_safe_posture;
      u_safe_posture.base = 0;
      u_safe_posture.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->safe_posture = u_safe_posture.real;
      offset += sizeof(this->safe_posture);
      union {
        double real;
        uint64_t base;
      } u_recover_time;
      u_recover_time.base = 0;
      u_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->recover_time = u_recover_time.real;
      offset += sizeof(this->recover_time);
      union {
        int16_t real;
        uint16_t base;
      } u_loop_for_check;
      u_loop_for_check.base = 0;
      u_loop_for_check.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_loop_for_check.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->loop_for_check = u_loop_for_check.real;
      offset += sizeof(this->loop_for_check);
      uint8_t angle_lengthT = *(inbuffer + offset++);
      if(angle_lengthT > angle_length)
        this->angle = (double*)realloc(this->angle, angle_lengthT * sizeof(double));
      offset += 3;
      angle_length = angle_lengthT;
      for( uint8_t i = 0; i < angle_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_angle;
      u_st_angle.base = 0;
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_angle = u_st_angle.real;
      offset += sizeof(this->st_angle);
        memcpy( &(this->angle[i]), &(this->st_angle), sizeof(double));
      }
      uint8_t collide_lengthT = *(inbuffer + offset++);
      if(collide_lengthT > collide_length)
        this->collide = (bool*)realloc(this->collide, collide_lengthT * sizeof(bool));
      offset += 3;
      collide_length = collide_lengthT;
      for( uint8_t i = 0; i < collide_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_collide;
      u_st_collide.base = 0;
      u_st_collide.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_collide = u_st_collide.real;
      offset += sizeof(this->st_collide);
        memcpy( &(this->collide[i]), &(this->st_collide), sizeof(bool));
      }
      offset += this->lines.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_CollisionState"; };
    const char * getMD5(){ return "99964cb468a99e4b69081e04306b420c"; };

  };

}
#endif