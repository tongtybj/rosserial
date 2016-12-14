#ifndef _ROS_multisense_ros_StampedPps_h
#define _ROS_multisense_ros_StampedPps_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace multisense_ros
{

  class StampedPps : public ros::Msg
  {
    public:
      ros::Time data;
      ros::Time host_time;

    StampedPps():
      data(),
      host_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data.sec);
      *(outbuffer + offset + 0) = (this->data.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data.nsec);
      *(outbuffer + offset + 0) = (this->host_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->host_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->host_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->host_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->host_time.sec);
      *(outbuffer + offset + 0) = (this->host_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->host_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->host_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->host_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->host_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->data.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data.sec);
      this->data.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data.nsec);
      this->host_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->host_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->host_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->host_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->host_time.sec);
      this->host_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->host_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->host_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->host_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->host_time.nsec);
     return offset;
    }

    const char * getType(){ return "multisense_ros/StampedPps"; };
    const char * getMD5(){ return "ee2f8d6ea6dc30440398fb554199fa0d"; };

  };

}
#endif