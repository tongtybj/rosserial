#ifndef _ROS_drc_com_common_HumanoidJointAngles_h
#define _ROS_drc_com_common_HumanoidJointAngles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_com_common
{

  class HumanoidJointAngles : public ros::Msg
  {
    public:
      uint8_t angles[35];
      uint8_t effort[35];

    HumanoidJointAngles():
      angles(),
      effort()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 35; i++){
      *(outbuffer + offset + 0) = (this->angles[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->angles[i]);
      }
      for( uint8_t i = 0; i < 35; i++){
      *(outbuffer + offset + 0) = (this->effort[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->effort[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 35; i++){
      this->angles[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->angles[i]);
      }
      for( uint8_t i = 0; i < 35; i++){
      this->effort[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->effort[i]);
      }
     return offset;
    }

    const char * getType(){ return "drc_com_common/HumanoidJointAngles"; };
    const char * getMD5(){ return "c8f4d0c6547e9e02ce4f4a12b1bd91a1"; };

  };

}
#endif