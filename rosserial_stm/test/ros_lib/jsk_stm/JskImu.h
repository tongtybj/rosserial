#ifndef _ROS_jsk_stm_JskImu_h
#define _ROS_jsk_stm_JskImu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace jsk_stm
{

  class JskImu : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Vector3 acc_data;
      geometry_msgs::Vector3 gyro_data;
      geometry_msgs::Vector3 mag_data;
      geometry_msgs::Vector3 angles;
      float altitude;

    JskImu():
      header(),
      acc_data(),
      gyro_data(),
      mag_data(),
      angles(),
      altitude(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->acc_data.serialize(outbuffer + offset);
      offset += this->gyro_data.serialize(outbuffer + offset);
      offset += this->mag_data.serialize(outbuffer + offset);
      offset += this->angles.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->acc_data.deserialize(inbuffer + offset);
      offset += this->gyro_data.deserialize(inbuffer + offset);
      offset += this->mag_data.deserialize(inbuffer + offset);
      offset += this->angles.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
     return offset;
    }

    const char * getType(){ return "jsk_stm/JskImu"; };
    const char * getMD5(){ return "7f57c6023e82bb37e15bb91a82bffb95"; };

  };

}
#endif