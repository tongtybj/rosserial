#ifndef _ROS_SERVICE_GetMotionPlan_h
#define _ROS_SERVICE_GetMotionPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/MotionPlanRequest.h"
#include "ros/duration.h"
#include "arm_navigation_msgs/RobotTrajectory.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"
#include "arm_navigation_msgs/RobotState.h"

namespace arm_navigation_msgs
{

static const char GETMOTIONPLAN[] = "arm_navigation_msgs/GetMotionPlan";

  class GetMotionPlanRequest : public ros::Msg
  {
    public:
      arm_navigation_msgs::MotionPlanRequest motion_plan_request;

    GetMotionPlanRequest():
      motion_plan_request()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->motion_plan_request.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->motion_plan_request.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETMOTIONPLAN; };
    const char * getMD5(){ return "53194db8d1959c06cb41e066f1f6695e"; };

  };

  class GetMotionPlanResponse : public ros::Msg
  {
    public:
      arm_navigation_msgs::RobotTrajectory trajectory;
      arm_navigation_msgs::RobotState robot_state;
      ros::Duration planning_time;
      arm_navigation_msgs::ArmNavigationErrorCodes error_code;
      uint8_t trajectory_error_codes_length;
      arm_navigation_msgs::ArmNavigationErrorCodes st_trajectory_error_codes;
      arm_navigation_msgs::ArmNavigationErrorCodes * trajectory_error_codes;

    GetMotionPlanResponse():
      trajectory(),
      robot_state(),
      planning_time(),
      error_code(),
      trajectory_error_codes_length(0), trajectory_error_codes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->robot_state.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->planning_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->planning_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->planning_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->planning_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->planning_time.sec);
      *(outbuffer + offset + 0) = (this->planning_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->planning_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->planning_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->planning_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->planning_time.nsec);
      offset += this->error_code.serialize(outbuffer + offset);
      *(outbuffer + offset++) = trajectory_error_codes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < trajectory_error_codes_length; i++){
      offset += this->trajectory_error_codes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->robot_state.deserialize(inbuffer + offset);
      this->planning_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->planning_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->planning_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->planning_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->planning_time.sec);
      this->planning_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->planning_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->planning_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->planning_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->planning_time.nsec);
      offset += this->error_code.deserialize(inbuffer + offset);
      uint8_t trajectory_error_codes_lengthT = *(inbuffer + offset++);
      if(trajectory_error_codes_lengthT > trajectory_error_codes_length)
        this->trajectory_error_codes = (arm_navigation_msgs::ArmNavigationErrorCodes*)realloc(this->trajectory_error_codes, trajectory_error_codes_lengthT * sizeof(arm_navigation_msgs::ArmNavigationErrorCodes));
      offset += 3;
      trajectory_error_codes_length = trajectory_error_codes_lengthT;
      for( uint8_t i = 0; i < trajectory_error_codes_length; i++){
      offset += this->st_trajectory_error_codes.deserialize(inbuffer + offset);
        memcpy( &(this->trajectory_error_codes[i]), &(this->st_trajectory_error_codes), sizeof(arm_navigation_msgs::ArmNavigationErrorCodes));
      }
     return offset;
    }

    const char * getType(){ return GETMOTIONPLAN; };
    const char * getMD5(){ return "85e06df8040608943ed808c52d463218"; };

  };

  class GetMotionPlan {
    public:
    typedef GetMotionPlanRequest Request;
    typedef GetMotionPlanResponse Response;
  };

}
#endif
