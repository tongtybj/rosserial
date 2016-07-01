#ifndef _ROS_jsk_footstep_controller_FootCoordsLowLevelInfo_h
#define _ROS_jsk_footstep_controller_FootCoordsLowLevelInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_footstep_controller
{

  class FootCoordsLowLevelInfo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      double raw_lleg_force;
      double raw_rleg_force;
      double filtered_lleg_force;
      double filtered_rleg_force;
      double threshold;

    FootCoordsLowLevelInfo():
      header(),
      raw_lleg_force(0),
      raw_rleg_force(0),
      filtered_lleg_force(0),
      filtered_rleg_force(0),
      threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_raw_lleg_force;
      u_raw_lleg_force.real = this->raw_lleg_force;
      *(outbuffer + offset + 0) = (u_raw_lleg_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_lleg_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_lleg_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_lleg_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_raw_lleg_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_raw_lleg_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_raw_lleg_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_raw_lleg_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->raw_lleg_force);
      union {
        double real;
        uint64_t base;
      } u_raw_rleg_force;
      u_raw_rleg_force.real = this->raw_rleg_force;
      *(outbuffer + offset + 0) = (u_raw_rleg_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_rleg_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_rleg_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_rleg_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_raw_rleg_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_raw_rleg_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_raw_rleg_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_raw_rleg_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->raw_rleg_force);
      union {
        double real;
        uint64_t base;
      } u_filtered_lleg_force;
      u_filtered_lleg_force.real = this->filtered_lleg_force;
      *(outbuffer + offset + 0) = (u_filtered_lleg_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_lleg_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_lleg_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_lleg_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_lleg_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_lleg_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_lleg_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_lleg_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_lleg_force);
      union {
        double real;
        uint64_t base;
      } u_filtered_rleg_force;
      u_filtered_rleg_force.real = this->filtered_rleg_force;
      *(outbuffer + offset + 0) = (u_filtered_rleg_force.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_filtered_rleg_force.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_filtered_rleg_force.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_filtered_rleg_force.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_filtered_rleg_force.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_filtered_rleg_force.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_filtered_rleg_force.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_filtered_rleg_force.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->filtered_rleg_force);
      union {
        double real;
        uint64_t base;
      } u_threshold;
      u_threshold.real = this->threshold;
      *(outbuffer + offset + 0) = (u_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_threshold.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_threshold.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_threshold.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_threshold.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_threshold.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_raw_lleg_force;
      u_raw_lleg_force.base = 0;
      u_raw_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_raw_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_raw_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_raw_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_raw_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->raw_lleg_force = u_raw_lleg_force.real;
      offset += sizeof(this->raw_lleg_force);
      union {
        double real;
        uint64_t base;
      } u_raw_rleg_force;
      u_raw_rleg_force.base = 0;
      u_raw_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_raw_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_raw_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_raw_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_raw_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->raw_rleg_force = u_raw_rleg_force.real;
      offset += sizeof(this->raw_rleg_force);
      union {
        double real;
        uint64_t base;
      } u_filtered_lleg_force;
      u_filtered_lleg_force.base = 0;
      u_filtered_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_lleg_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_lleg_force = u_filtered_lleg_force.real;
      offset += sizeof(this->filtered_lleg_force);
      union {
        double real;
        uint64_t base;
      } u_filtered_rleg_force;
      u_filtered_rleg_force.base = 0;
      u_filtered_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_filtered_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_filtered_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_filtered_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_filtered_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_filtered_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_filtered_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_filtered_rleg_force.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->filtered_rleg_force = u_filtered_rleg_force.real;
      offset += sizeof(this->filtered_rleg_force);
      union {
        double real;
        uint64_t base;
      } u_threshold;
      u_threshold.base = 0;
      u_threshold.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_threshold.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_threshold.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_threshold.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_threshold.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_threshold.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_threshold.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_threshold.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->threshold = u_threshold.real;
      offset += sizeof(this->threshold);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_controller/FootCoordsLowLevelInfo"; };
    const char * getMD5(){ return "f03f7aaafde613e7d2247f1ee6314403"; };

  };

}
#endif