#ifndef _ROS_SERVICE_FilterJointTrajectoryWithConstraints_h
#define _ROS_SERVICE_FilterJointTrajectoryWithConstraints_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/Constraints.h"
#include "ros/duration.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "arm_navigation_msgs/JointLimits.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"
#include "arm_navigation_msgs/RobotState.h"

namespace arm_navigation_msgs
{

static const char FILTERJOINTTRAJECTORYWITHCONSTRAINTS[] = "arm_navigation_msgs/FilterJointTrajectoryWithConstraints";

  class FilterJointTrajectoryWithConstraintsRequest : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;
      const char* group_name;
      uint8_t limits_length;
      arm_navigation_msgs::JointLimits st_limits;
      arm_navigation_msgs::JointLimits * limits;
      arm_navigation_msgs::RobotState start_state;
      arm_navigation_msgs::Constraints path_constraints;
      arm_navigation_msgs::Constraints goal_constraints;
      ros::Duration allowed_time;

    FilterJointTrajectoryWithConstraintsRequest():
      trajectory(),
      group_name(""),
      limits_length(0), limits(NULL),
      start_state(),
      path_constraints(),
      goal_constraints(),
      allowed_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      uint32_t length_group_name = strlen(this->group_name);
      memcpy(outbuffer + offset, &length_group_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      *(outbuffer + offset++) = limits_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < limits_length; i++){
      offset += this->limits[i].serialize(outbuffer + offset);
      }
      offset += this->start_state.serialize(outbuffer + offset);
      offset += this->path_constraints.serialize(outbuffer + offset);
      offset += this->goal_constraints.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->allowed_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_time.sec);
      *(outbuffer + offset + 0) = (this->allowed_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      uint32_t length_group_name;
      memcpy(&length_group_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      uint8_t limits_lengthT = *(inbuffer + offset++);
      if(limits_lengthT > limits_length)
        this->limits = (arm_navigation_msgs::JointLimits*)realloc(this->limits, limits_lengthT * sizeof(arm_navigation_msgs::JointLimits));
      offset += 3;
      limits_length = limits_lengthT;
      for( uint8_t i = 0; i < limits_length; i++){
      offset += this->st_limits.deserialize(inbuffer + offset);
        memcpy( &(this->limits[i]), &(this->st_limits), sizeof(arm_navigation_msgs::JointLimits));
      }
      offset += this->start_state.deserialize(inbuffer + offset);
      offset += this->path_constraints.deserialize(inbuffer + offset);
      offset += this->goal_constraints.deserialize(inbuffer + offset);
      this->allowed_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->allowed_time.sec);
      this->allowed_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->allowed_time.nsec);
     return offset;
    }

    const char * getType(){ return FILTERJOINTTRAJECTORYWITHCONSTRAINTS; };
    const char * getMD5(){ return "4761ee5c109ab0a44849d5f9f4ff055c"; };

  };

  class FilterJointTrajectoryWithConstraintsResponse : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;
      arm_navigation_msgs::ArmNavigationErrorCodes error_code;

    FilterJointTrajectoryWithConstraintsResponse():
      trajectory(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FILTERJOINTTRAJECTORYWITHCONSTRAINTS; };
    const char * getMD5(){ return "b07a38e3291ec1857951df2bfd71735e"; };

  };

  class FilterJointTrajectoryWithConstraints {
    public:
    typedef FilterJointTrajectoryWithConstraintsRequest Request;
    typedef FilterJointTrajectoryWithConstraintsResponse Response;
  };

}
#endif
