#ifndef _ROS_monocam_settler_ConfigGoal_h
#define _ROS_monocam_settler_ConfigGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace monocam_settler
{

  class ConfigGoal : public ros::Msg
  {
    public:
      double tolerance;
      uint8_t ignore_failures;
      ros::Duration max_step;
      uint32_t cache_size;

    ConfigGoal():
      tolerance(0),
      ignore_failures(0),
      max_step(),
      cache_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_tolerance;
      u_tolerance.real = this->tolerance;
      *(outbuffer + offset + 0) = (u_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tolerance);
      *(outbuffer + offset + 0) = (this->ignore_failures >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ignore_failures);
      *(outbuffer + offset + 0) = (this->max_step.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_step.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_step.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_step.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_step.sec);
      *(outbuffer + offset + 0) = (this->max_step.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_step.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_step.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_step.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_step.nsec);
      *(outbuffer + offset + 0) = (this->cache_size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cache_size >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cache_size >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cache_size >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cache_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_tolerance;
      u_tolerance.base = 0;
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->tolerance = u_tolerance.real;
      offset += sizeof(this->tolerance);
      this->ignore_failures =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ignore_failures);
      this->max_step.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_step.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_step.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_step.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_step.sec);
      this->max_step.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->max_step.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_step.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_step.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_step.nsec);
      this->cache_size =  ((uint32_t) (*(inbuffer + offset)));
      this->cache_size |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cache_size |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->cache_size |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->cache_size);
     return offset;
    }

    const char * getType(){ return "monocam_settler/ConfigGoal"; };
    const char * getMD5(){ return "f2b47726560448f0dada94e01ba65594"; };

  };

}
#endif