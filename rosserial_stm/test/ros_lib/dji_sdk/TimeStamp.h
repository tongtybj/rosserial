#ifndef _ROS_dji_sdk_TimeStamp_h
#define _ROS_dji_sdk_TimeStamp_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace dji_sdk
{

  class TimeStamp : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t time;
      uint32_t time_ns;
      uint8_t sync_flag;

    TimeStamp():
      header(),
      time(0),
      time_ns(0),
      sync_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time);
      *(outbuffer + offset + 0) = (this->time_ns >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_ns >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_ns >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_ns >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_ns);
      *(outbuffer + offset + 0) = (this->sync_flag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sync_flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->time =  ((uint32_t) (*(inbuffer + offset)));
      this->time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time);
      this->time_ns =  ((uint32_t) (*(inbuffer + offset)));
      this->time_ns |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_ns |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_ns |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_ns);
      this->sync_flag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sync_flag);
     return offset;
    }

    const char * getType(){ return "dji_sdk/TimeStamp"; };
    const char * getMD5(){ return "cdf94dfbb71b3e4aec0ba55884cec090"; };

  };

}
#endif