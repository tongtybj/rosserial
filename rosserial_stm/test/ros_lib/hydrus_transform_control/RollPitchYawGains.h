#ifndef _ROS_hydrus_transform_control_RollPitchYawGains_h
#define _ROS_hydrus_transform_control_RollPitchYawGains_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hydrus_transform_control/RollPitchYawGain.h"

namespace hydrus_transform_control
{

  class RollPitchYawGains : public ros::Msg
  {
    public:
      uint8_t motors_length;
      hydrus_transform_control::RollPitchYawGain st_motors;
      hydrus_transform_control::RollPitchYawGain * motors;

    RollPitchYawGains():
      motors_length(0), motors(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = motors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motors_length; i++){
      offset += this->motors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t motors_lengthT = *(inbuffer + offset++);
      if(motors_lengthT > motors_length)
        this->motors = (hydrus_transform_control::RollPitchYawGain*)realloc(this->motors, motors_lengthT * sizeof(hydrus_transform_control::RollPitchYawGain));
      offset += 3;
      motors_length = motors_lengthT;
      for( uint8_t i = 0; i < motors_length; i++){
      offset += this->st_motors.deserialize(inbuffer + offset);
        memcpy( &(this->motors[i]), &(this->st_motors), sizeof(hydrus_transform_control::RollPitchYawGain));
      }
     return offset;
    }

    const char * getType(){ return "hydrus_transform_control/RollPitchYawGains"; };
    const char * getMD5(){ return "e02c97843dff2be50cd609663998aa9e"; };

  };

}
#endif