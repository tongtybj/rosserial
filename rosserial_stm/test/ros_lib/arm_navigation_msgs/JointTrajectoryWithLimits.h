#ifndef _ROS_arm_navigation_msgs_JointTrajectoryWithLimits_h
#define _ROS_arm_navigation_msgs_JointTrajectoryWithLimits_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "arm_navigation_msgs/JointLimits.h"

namespace arm_navigation_msgs
{

  class JointTrajectoryWithLimits : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;
      uint8_t limits_length;
      arm_navigation_msgs::JointLimits st_limits;
      arm_navigation_msgs::JointLimits * limits;

    JointTrajectoryWithLimits():
      trajectory(),
      limits_length(0), limits(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      *(outbuffer + offset++) = limits_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < limits_length; i++){
      offset += this->limits[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      uint8_t limits_lengthT = *(inbuffer + offset++);
      if(limits_lengthT > limits_length)
        this->limits = (arm_navigation_msgs::JointLimits*)realloc(this->limits, limits_lengthT * sizeof(arm_navigation_msgs::JointLimits));
      offset += 3;
      limits_length = limits_lengthT;
      for( uint8_t i = 0; i < limits_length; i++){
      offset += this->st_limits.deserialize(inbuffer + offset);
        memcpy( &(this->limits[i]), &(this->st_limits), sizeof(arm_navigation_msgs::JointLimits));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/JointTrajectoryWithLimits"; };
    const char * getMD5(){ return "895b19c6fb0a363348299884c7a90c9d"; };

  };

}
#endif