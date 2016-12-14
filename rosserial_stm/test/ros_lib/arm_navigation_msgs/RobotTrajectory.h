#ifndef _ROS_arm_navigation_msgs_RobotTrajectory_h
#define _ROS_arm_navigation_msgs_RobotTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "arm_navigation_msgs/MultiDOFJointTrajectory.h"

namespace arm_navigation_msgs
{

  class RobotTrajectory : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory joint_trajectory;
      arm_navigation_msgs::MultiDOFJointTrajectory multi_dof_joint_trajectory;

    RobotTrajectory():
      joint_trajectory(),
      multi_dof_joint_trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_trajectory.serialize(outbuffer + offset);
      offset += this->multi_dof_joint_trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_trajectory.deserialize(inbuffer + offset);
      offset += this->multi_dof_joint_trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/RobotTrajectory"; };
    const char * getMD5(){ return "bd2e7835f85bfed0c64e924cbafef1d1"; };

  };

}
#endif