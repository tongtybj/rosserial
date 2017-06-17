#ifndef _ROS_aerial_robot_msgs_RollPitchYawTerms_h
#define _ROS_aerial_robot_msgs_RollPitchYawTerms_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "aerial_robot_msgs/RollPitchYawTerm.h"

namespace aerial_robot_msgs
{

  class RollPitchYawTerms : public ros::Msg
  {
    public:
      uint8_t motors_length;
      aerial_robot_msgs::RollPitchYawTerm st_motors;
      aerial_robot_msgs::RollPitchYawTerm * motors;

    RollPitchYawTerms():
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
        this->motors = (aerial_robot_msgs::RollPitchYawTerm*)realloc(this->motors, motors_lengthT * sizeof(aerial_robot_msgs::RollPitchYawTerm));
      offset += 3;
      motors_length = motors_lengthT;
      for( uint8_t i = 0; i < motors_length; i++){
      offset += this->st_motors.deserialize(inbuffer + offset);
        memcpy( &(this->motors[i]), &(this->st_motors), sizeof(aerial_robot_msgs::RollPitchYawTerm));
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/RollPitchYawTerms"; };
    const char * getMD5(){ return "e02c97843dff2be50cd609663998aa9e"; };

  };

}
#endif