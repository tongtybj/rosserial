#ifndef _ROS_dji_sdk_A3RTK_h
#define _ROS_dji_sdk_A3RTK_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class A3RTK : public ros::Msg
  {
    public:
      uint32_t date;
      uint32_t time;
      double longitude_RTK;
      double latitude_RTK;
      float height_above_sea_RTK;
      float velocity_north;
      float velocity_east;
      float velocity_ground;
      int16_t yaw;
      uint8_t position_flag;
      uint8_t yaw_flag;

    A3RTK():
      date(0),
      time(0),
      longitude_RTK(0),
      latitude_RTK(0),
      height_above_sea_RTK(0),
      velocity_north(0),
      velocity_east(0),
      velocity_ground(0),
      yaw(0),
      position_flag(0),
      yaw_flag(0)
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
        double real;
        uint64_t base;
      } u_longitude_RTK;
      u_longitude_RTK.real = this->longitude_RTK;
      *(outbuffer + offset + 0) = (u_longitude_RTK.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude_RTK.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude_RTK.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude_RTK.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitude_RTK.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitude_RTK.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitude_RTK.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitude_RTK.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitude_RTK);
      union {
        double real;
        uint64_t base;
      } u_latitude_RTK;
      u_latitude_RTK.real = this->latitude_RTK;
      *(outbuffer + offset + 0) = (u_latitude_RTK.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude_RTK.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude_RTK.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude_RTK.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_latitude_RTK.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_latitude_RTK.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_latitude_RTK.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_latitude_RTK.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->latitude_RTK);
      union {
        float real;
        uint32_t base;
      } u_height_above_sea_RTK;
      u_height_above_sea_RTK.real = this->height_above_sea_RTK;
      *(outbuffer + offset + 0) = (u_height_above_sea_RTK.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height_above_sea_RTK.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height_above_sea_RTK.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height_above_sea_RTK.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height_above_sea_RTK);
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
      union {
        int16_t real;
        uint16_t base;
      } u_yaw;
      u_yaw.real = this->yaw;
      *(outbuffer + offset + 0) = (u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw);
      *(outbuffer + offset + 0) = (this->position_flag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->position_flag);
      *(outbuffer + offset + 0) = (this->yaw_flag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yaw_flag);
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
        double real;
        uint64_t base;
      } u_longitude_RTK;
      u_longitude_RTK.base = 0;
      u_longitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitude_RTK = u_longitude_RTK.real;
      offset += sizeof(this->longitude_RTK);
      union {
        double real;
        uint64_t base;
      } u_latitude_RTK;
      u_latitude_RTK.base = 0;
      u_latitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_latitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_latitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_latitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_latitude_RTK.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->latitude_RTK = u_latitude_RTK.real;
      offset += sizeof(this->latitude_RTK);
      union {
        float real;
        uint32_t base;
      } u_height_above_sea_RTK;
      u_height_above_sea_RTK.base = 0;
      u_height_above_sea_RTK.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height_above_sea_RTK.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height_above_sea_RTK.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height_above_sea_RTK.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height_above_sea_RTK = u_height_above_sea_RTK.real;
      offset += sizeof(this->height_above_sea_RTK);
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
      union {
        int16_t real;
        uint16_t base;
      } u_yaw;
      u_yaw.base = 0;
      u_yaw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->yaw = u_yaw.real;
      offset += sizeof(this->yaw);
      this->position_flag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->position_flag);
      this->yaw_flag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->yaw_flag);
     return offset;
    }

    const char * getType(){ return "dji_sdk/A3RTK"; };
    const char * getMD5(){ return "2f1a4c1310d587c3f79f00f74019a0be"; };

  };

}
#endif