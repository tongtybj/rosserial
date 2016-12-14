#ifndef _ROS_dji_sdk_MissionFollowmeTask_h
#define _ROS_dji_sdk_MissionFollowmeTask_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionFollowmeTask : public ros::Msg
  {
    public:
      uint8_t mode;
      uint8_t yaw_mode;
      double initial_latitude;
      double initial_longitude;
      uint16_t initial_altitude;
      uint8_t sensitivity;

    MissionFollowmeTask():
      mode(0),
      yaw_mode(0),
      initial_latitude(0),
      initial_longitude(0),
      initial_altitude(0),
      sensitivity(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      *(outbuffer + offset + 0) = (this->yaw_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->yaw_mode);
      union {
        double real;
        uint64_t base;
      } u_initial_latitude;
      u_initial_latitude.real = this->initial_latitude;
      *(outbuffer + offset + 0) = (u_initial_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_initial_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_initial_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_initial_latitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_initial_latitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_initial_latitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_initial_latitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_initial_latitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->initial_latitude);
      union {
        double real;
        uint64_t base;
      } u_initial_longitude;
      u_initial_longitude.real = this->initial_longitude;
      *(outbuffer + offset + 0) = (u_initial_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_initial_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_initial_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_initial_longitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_initial_longitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_initial_longitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_initial_longitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_initial_longitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->initial_longitude);
      *(outbuffer + offset + 0) = (this->initial_altitude >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->initial_altitude >> (8 * 1)) & 0xFF;
      offset += sizeof(this->initial_altitude);
      *(outbuffer + offset + 0) = (this->sensitivity >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensitivity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      this->yaw_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->yaw_mode);
      union {
        double real;
        uint64_t base;
      } u_initial_latitude;
      u_initial_latitude.base = 0;
      u_initial_latitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_initial_latitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_initial_latitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_initial_latitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_initial_latitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_initial_latitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_initial_latitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_initial_latitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->initial_latitude = u_initial_latitude.real;
      offset += sizeof(this->initial_latitude);
      union {
        double real;
        uint64_t base;
      } u_initial_longitude;
      u_initial_longitude.base = 0;
      u_initial_longitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_initial_longitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_initial_longitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_initial_longitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_initial_longitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_initial_longitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_initial_longitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_initial_longitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->initial_longitude = u_initial_longitude.real;
      offset += sizeof(this->initial_longitude);
      this->initial_altitude =  ((uint16_t) (*(inbuffer + offset)));
      this->initial_altitude |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->initial_altitude);
      this->sensitivity =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sensitivity);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionFollowmeTask"; };
    const char * getMD5(){ return "0b5547386d29daca9e6c32595ec4ca50"; };

  };

}
#endif