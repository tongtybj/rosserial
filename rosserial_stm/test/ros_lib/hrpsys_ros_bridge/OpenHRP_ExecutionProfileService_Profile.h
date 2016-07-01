#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_Profile_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_Profile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_ComponentProfile.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ExecutionProfileService_Profile : public ros::Msg
  {
    public:
      double max_period;
      double min_period;
      double avg_period;
      double max_process;
      uint8_t profiles_length;
      hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile st_profiles;
      hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile * profiles;
      int32_t count;
      int32_t timeover;

    OpenHRP_ExecutionProfileService_Profile():
      max_period(0),
      min_period(0),
      avg_period(0),
      max_process(0),
      profiles_length(0), profiles(NULL),
      count(0),
      timeover(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_max_period;
      u_max_period.real = this->max_period;
      *(outbuffer + offset + 0) = (u_max_period.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_period.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_period.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_period.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_period.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_period.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_period.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_period.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_period);
      union {
        double real;
        uint64_t base;
      } u_min_period;
      u_min_period.real = this->min_period;
      *(outbuffer + offset + 0) = (u_min_period.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_period.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_period.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_period.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_min_period.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_min_period.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_min_period.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_min_period.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->min_period);
      union {
        double real;
        uint64_t base;
      } u_avg_period;
      u_avg_period.real = this->avg_period;
      *(outbuffer + offset + 0) = (u_avg_period.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_avg_period.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_avg_period.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_avg_period.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_avg_period.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_avg_period.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_avg_period.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_avg_period.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->avg_period);
      union {
        double real;
        uint64_t base;
      } u_max_process;
      u_max_process.real = this->max_process;
      *(outbuffer + offset + 0) = (u_max_process.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_process.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_process.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_process.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_max_process.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_max_process.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_max_process.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_max_process.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->max_process);
      *(outbuffer + offset++) = profiles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < profiles_length; i++){
      offset += this->profiles[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_count;
      u_count.real = this->count;
      *(outbuffer + offset + 0) = (u_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count);
      union {
        int32_t real;
        uint32_t base;
      } u_timeover;
      u_timeover.real = this->timeover;
      *(outbuffer + offset + 0) = (u_timeover.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeover.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeover.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeover.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeover);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_max_period;
      u_max_period.base = 0;
      u_max_period.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_period.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_period.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_period.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_period.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_period.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_period.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_period.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_period = u_max_period.real;
      offset += sizeof(this->max_period);
      union {
        double real;
        uint64_t base;
      } u_min_period;
      u_min_period.base = 0;
      u_min_period.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_period.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_period.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_period.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_min_period.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_min_period.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_min_period.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_min_period.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->min_period = u_min_period.real;
      offset += sizeof(this->min_period);
      union {
        double real;
        uint64_t base;
      } u_avg_period;
      u_avg_period.base = 0;
      u_avg_period.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_avg_period.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_avg_period.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_avg_period.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_avg_period.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_avg_period.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_avg_period.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_avg_period.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->avg_period = u_avg_period.real;
      offset += sizeof(this->avg_period);
      union {
        double real;
        uint64_t base;
      } u_max_process;
      u_max_process.base = 0;
      u_max_process.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_process.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_process.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_process.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_max_process.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_max_process.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_max_process.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_max_process.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->max_process = u_max_process.real;
      offset += sizeof(this->max_process);
      uint8_t profiles_lengthT = *(inbuffer + offset++);
      if(profiles_lengthT > profiles_length)
        this->profiles = (hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile*)realloc(this->profiles, profiles_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile));
      offset += 3;
      profiles_length = profiles_lengthT;
      for( uint8_t i = 0; i < profiles_length; i++){
      offset += this->st_profiles.deserialize(inbuffer + offset);
        memcpy( &(this->profiles[i]), &(this->st_profiles), sizeof(hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_count;
      u_count.base = 0;
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->count = u_count.real;
      offset += sizeof(this->count);
      union {
        int32_t real;
        uint32_t base;
      } u_timeover;
      u_timeover.base = 0;
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeover = u_timeover.real;
      offset += sizeof(this->timeover);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_Profile"; };
    const char * getMD5(){ return "81d6e451dd3c3c507eb655f4a7c6fba2"; };

  };

}
#endif