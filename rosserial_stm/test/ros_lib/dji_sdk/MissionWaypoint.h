#ifndef _ROS_dji_sdk_MissionWaypoint_h
#define _ROS_dji_sdk_MissionWaypoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/MissionWaypointAction.h"

namespace dji_sdk
{

  class MissionWaypoint : public ros::Msg
  {
    public:
      double latitude;
      double longitude;
      float altitude;
      float damping_distance;
      int16_t target_yaw;
      int16_t target_gimbal_pitch;
      uint8_t turn_mode;
      uint8_t has_action;
      uint16_t action_time_limit;
      dji_sdk::MissionWaypointAction waypoint_action;

    MissionWaypoint():
      latitude(0),
      longitude(0),
      altitude(0),
      damping_distance(0),
      target_yaw(0),
      target_gimbal_pitch(0),
      turn_mode(0),
      has_action(0),
      action_time_limit(0),
      waypoint_action()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_latitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_latitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_latitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_latitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_damping_distance;
      u_damping_distance.real = this->damping_distance;
      *(outbuffer + offset + 0) = (u_damping_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_damping_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_damping_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_damping_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->damping_distance);
      union {
        int16_t real;
        uint16_t base;
      } u_target_yaw;
      u_target_yaw.real = this->target_yaw;
      *(outbuffer + offset + 0) = (u_target_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_yaw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->target_yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_target_gimbal_pitch;
      u_target_gimbal_pitch.real = this->target_gimbal_pitch;
      *(outbuffer + offset + 0) = (u_target_gimbal_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_target_gimbal_pitch.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->target_gimbal_pitch);
      *(outbuffer + offset + 0) = (this->turn_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn_mode);
      *(outbuffer + offset + 0) = (this->has_action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_action);
      *(outbuffer + offset + 0) = (this->action_time_limit >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->action_time_limit >> (8 * 1)) & 0xFF;
      offset += sizeof(this->action_time_limit);
      offset += this->waypoint_action.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_damping_distance;
      u_damping_distance.base = 0;
      u_damping_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_damping_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_damping_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_damping_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->damping_distance = u_damping_distance.real;
      offset += sizeof(this->damping_distance);
      union {
        int16_t real;
        uint16_t base;
      } u_target_yaw;
      u_target_yaw.base = 0;
      u_target_yaw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_yaw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->target_yaw = u_target_yaw.real;
      offset += sizeof(this->target_yaw);
      union {
        int16_t real;
        uint16_t base;
      } u_target_gimbal_pitch;
      u_target_gimbal_pitch.base = 0;
      u_target_gimbal_pitch.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_target_gimbal_pitch.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->target_gimbal_pitch = u_target_gimbal_pitch.real;
      offset += sizeof(this->target_gimbal_pitch);
      this->turn_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->turn_mode);
      this->has_action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->has_action);
      this->action_time_limit =  ((uint16_t) (*(inbuffer + offset)));
      this->action_time_limit |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->action_time_limit);
      offset += this->waypoint_action.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionWaypoint"; };
    const char * getMD5(){ return "d321a17884980812391aa8e2850409e4"; };

  };

}
#endif