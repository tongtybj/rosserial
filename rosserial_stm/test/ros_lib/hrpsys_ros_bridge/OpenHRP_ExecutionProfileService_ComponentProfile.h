#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_ComponentProfile_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_ComponentProfile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ExecutionProfileService_ComponentProfile : public ros::Msg
  {
    public:
      int32_t count;
      double max_process;
      double avg_process;

    OpenHRP_ExecutionProfileService_ComponentProfile():
      count(0),
      max_process(0),
      avg_process(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      union {
        double real;
        uint64_t base;
      } u_avg_process;
      u_avg_process.real = this->avg_process;
      *(outbuffer + offset + 0) = (u_avg_process.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_avg_process.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_avg_process.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_avg_process.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_avg_process.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_avg_process.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_avg_process.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_avg_process.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->avg_process);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      union {
        double real;
        uint64_t base;
      } u_avg_process;
      u_avg_process.base = 0;
      u_avg_process.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_avg_process.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_avg_process.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_avg_process.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_avg_process.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_avg_process.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_avg_process.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_avg_process.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->avg_process = u_avg_process.real;
      offset += sizeof(this->avg_process);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_ComponentProfile"; };
    const char * getMD5(){ return "2756437d1ed9f4a80e8165d05e369c5a"; };

  };

}
#endif