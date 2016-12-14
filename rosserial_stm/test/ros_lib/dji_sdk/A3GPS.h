#ifndef _ROS_dji_sdk_A3GPS_h
#define _ROS_dji_sdk_A3GPS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class A3GPS : public ros::Msg
  {
    public:
      uint32_t date;
      uint32_t time;
      int32_t longitude;
      int32_t latitude;
      int32_t height_above_sea;
      float velocity_north;
      float velocity_east;
      float velocity_ground;

    A3GPS():
      date(0),
      time(0),
      longitude(0),
      latitude(0),
      height_above_sea(0),
      velocity_north(0),
      velocity_east(0),
      velocity_ground(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->date >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->date >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->date >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->date >> (8 * 3)) & 0xFF;
      offset += sizeof(this->date);
      *(outbuffer + offset + 0) = (this->time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time);
      union {
        int32_t real;
        uint32_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        int32_t real;
        uint32_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        int32_t real;
        uint32_t base;
      } u_height_above_sea;
      u_height_above_sea.real = this->height_above_sea;
      *(outbuffer + offset + 0) = (u_height_above_sea.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height_above_sea.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height_above_sea.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height_above_sea.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height_above_sea);
      union {
        float real;
        uint32_t base;
      } u_velocity_north;
      u_velocity_north.real = this->velocity_north;
      *(outbuffer + offset + 0) = (u_velocity_north.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_north.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_north.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_north.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_north);
      union {
        float real;
        uint32_t base;
      } u_velocity_east;
      u_velocity_east.real = this->velocity_east;
      *(outbuffer + offset + 0) = (u_velocity_east.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_east.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_east.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_east.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_east);
      union {
        float real;
        uint32_t base;
      } u_velocity_ground;
      u_velocity_ground.real = this->velocity_ground;
      *(outbuffer + offset + 0) = (u_velocity_ground.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_ground.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_ground.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_ground.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_ground);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->date =  ((uint32_t) (*(inbuffer + offset)));
      this->date |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->date |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->date |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->date);
      this->time =  ((uint32_t) (*(inbuffer + offset)));
      this->time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time);
      union {
        int32_t real;
        uint32_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        int32_t real;
        uint32_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        int32_t real;
        uint32_t base;
      } u_height_above_sea;
      u_height_above_sea.base = 0;
      u_height_above_sea.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height_above_sea.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height_above_sea.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height_above_sea.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height_above_sea = u_height_above_sea.real;
      offset += sizeof(this->height_above_sea);
      union {
        float real;
        uint32_t base;
      } u_velocity_north;
      u_velocity_north.base = 0;
      u_velocity_north.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_north.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_north.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_north.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_north = u_velocity_north.real;
      offset += sizeof(this->velocity_north);
      union {
        float real;
        uint32_t base;
      } u_velocity_east;
      u_velocity_east.base = 0;
      u_velocity_east.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_east.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_east.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_east.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_east = u_velocity_east.real;
      offset += sizeof(this->velocity_east);
      union {
        float real;
        uint32_t base;
      } u_velocity_ground;
      u_velocity_ground.base = 0;
      u_velocity_ground.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_ground.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_ground.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_ground.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_ground = u_velocity_ground.real;
      offset += sizeof(this->velocity_ground);
     return offset;
    }

    const char * getType(){ return "dji_sdk/A3GPS"; };
    const char * getMD5(){ return "11eb94934f90318efef991e43caf4ed1"; };

  };

}
#endif