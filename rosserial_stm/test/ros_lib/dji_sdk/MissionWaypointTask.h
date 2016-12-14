#ifndef _ROS_dji_sdk_MissionWaypointTask_h
#define _ROS_dji_sdk_MissionWaypointTask_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/MissionWaypoint.h"

namespace dji_sdk
{

  class MissionWaypointTask : public ros::Msg
  {
    public:
      float velocity_range;
      float idle_velocity;
      uint8_t action_on_finish;
      uint8_t mission_exec_times;
      uint8_t yaw_mode;
      uint8_t trace_mode;
      uint8_t action_on_rc_lost;
      uint8_t gimbal_pitch_mode;
      uint8_t mission_waypoint_length;
      dji_sdk::MissionWaypoint st_mission_waypoint;
      dji_sdk::MissionWaypoint * mission_waypoint;

    MissionWaypointTask():
      velocity_range(0),
      idle_velocity(0),
      action_on_finish(0),
      mission_exec_times(0),
      yaw_mode(0),
      trace_mode(0),
      action_on_rc_lost(0),
      gimbal_pitch_mode(0),
      mission_waypoint_length(0), mission_waypoint(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_velocity_range;
      u_velocity_range.real = this->velocity_range;
      *(outbuffer + offset + 0) = (u_velocity_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_range);
      union {
        float real;
        uint32_t base;
      } u_idle_velocity;
      u_idle_velocity.real = this->idle_velocity;
      *(outbuffer + offset + 0) = (u_idle_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idle_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_idle_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_idle_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->idle_velocity);
      *(outbuffer + offset + 0) = (this->action_on_finish >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action_on_finish);
      *(outbuffer + offset + 0) = (this->mission_exec_times >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mission_exec_times);
      *(outbuffer + offset + 0) = (this->yaw_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yaw_mode);
      *(outbuffer + offset + 0) = (this->trace_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trace_mode);
      *(outbuffer + offset + 0) = (this->action_on_rc_lost >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action_on_rc_lost);
      *(outbuffer + offset + 0) = (this->gimbal_pitch_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gimbal_pitch_mode);
      *(outbuffer + offset++) = mission_waypoint_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < mission_waypoint_length; i++){
      offset += this->mission_waypoint[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_velocity_range;
      u_velocity_range.base = 0;
      u_velocity_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_range = u_velocity_range.real;
      offset += sizeof(this->velocity_range);
      union {
        float real;
        uint32_t base;
      } u_idle_velocity;
      u_idle_velocity.base = 0;
      u_idle_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_idle_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_idle_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_idle_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->idle_velocity = u_idle_velocity.real;
      offset += sizeof(this->idle_velocity);
      this->action_on_finish =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action_on_finish);
      this->mission_exec_times =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mission_exec_times);
      this->yaw_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->yaw_mode);
      this->trace_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->trace_mode);
      this->action_on_rc_lost =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action_on_rc_lost);
      this->gimbal_pitch_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gimbal_pitch_mode);
      uint8_t mission_waypoint_lengthT = *(inbuffer + offset++);
      if(mission_waypoint_lengthT > mission_waypoint_length)
        this->mission_waypoint = (dji_sdk::MissionWaypoint*)realloc(this->mission_waypoint, mission_waypoint_lengthT * sizeof(dji_sdk::MissionWaypoint));
      offset += 3;
      mission_waypoint_length = mission_waypoint_lengthT;
      for( uint8_t i = 0; i < mission_waypoint_length; i++){
      offset += this->st_mission_waypoint.deserialize(inbuffer + offset);
        memcpy( &(this->mission_waypoint[i]), &(this->st_mission_waypoint), sizeof(dji_sdk::MissionWaypoint));
      }
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionWaypointTask"; };
    const char * getMD5(){ return "a81a8c039337b422bde8ccc87d96c14b"; };

  };

}
#endif