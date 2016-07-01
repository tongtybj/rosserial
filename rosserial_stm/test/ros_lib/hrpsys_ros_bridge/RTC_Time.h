#ifndef _ROS_hrpsys_ros_bridge_RTC_Time_h
#define _ROS_hrpsys_ros_bridge_RTC_Time_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class RTC_Time : public ros::Msg
  {
    public:
      uint32_t sec;
      uint32_t nsec;

    RTC_Time():
      sec(0),
      nsec(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sec);
      *(outbuffer + offset + 0) = (this->nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->sec =  ((uint32_t) (*(inbuffer + offset)));
      this->sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sec);
      this->nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->nsec);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/RTC_Time"; };
    const char * getMD5(){ return "4771ad66fef816d2e4bead2f45a1cde6"; };

  };

}
#endif