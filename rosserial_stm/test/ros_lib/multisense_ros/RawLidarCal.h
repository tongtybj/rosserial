#ifndef _ROS_multisense_ros_RawLidarCal_h
#define _ROS_multisense_ros_RawLidarCal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multisense_ros
{

  class RawLidarCal : public ros::Msg
  {
    public:
      float laserToSpindle[16];
      float cameraToSpindleFixed[16];

    RawLidarCal():
      laserToSpindle(),
      cameraToSpindleFixed()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      union {
        float real;
        uint32_t base;
      } u_laserToSpindlei;
      u_laserToSpindlei.real = this->laserToSpindle[i];
      *(outbuffer + offset + 0) = (u_laserToSpindlei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_laserToSpindlei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_laserToSpindlei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_laserToSpindlei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->laserToSpindle[i]);
      }
      for( uint8_t i = 0; i < 16; i++){
      union {
        float real;
        uint32_t base;
      } u_cameraToSpindleFixedi;
      u_cameraToSpindleFixedi.real = this->cameraToSpindleFixed[i];
      *(outbuffer + offset + 0) = (u_cameraToSpindleFixedi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cameraToSpindleFixedi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cameraToSpindleFixedi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cameraToSpindleFixedi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cameraToSpindleFixed[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 16; i++){
      union {
        float real;
        uint32_t base;
      } u_laserToSpindlei;
      u_laserToSpindlei.base = 0;
      u_laserToSpindlei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_laserToSpindlei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_laserToSpindlei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_laserToSpindlei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->laserToSpindle[i] = u_laserToSpindlei.real;
      offset += sizeof(this->laserToSpindle[i]);
      }
      for( uint8_t i = 0; i < 16; i++){
      union {
        float real;
        uint32_t base;
      } u_cameraToSpindleFixedi;
      u_cameraToSpindleFixedi.base = 0;
      u_cameraToSpindleFixedi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cameraToSpindleFixedi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cameraToSpindleFixedi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cameraToSpindleFixedi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cameraToSpindleFixed[i] = u_cameraToSpindleFixedi.real;
      offset += sizeof(this->cameraToSpindleFixed[i]);
      }
     return offset;
    }

    const char * getType(){ return "multisense_ros/RawLidarCal"; };
    const char * getMD5(){ return "a40a2eda974181d5f5f21ff840e3a6ff"; };

  };

}
#endif