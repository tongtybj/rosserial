#ifndef _ROS_SERVICE_GetJointTrajectoryValidity_h
#define _ROS_SERVICE_GetJointTrajectoryValidity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "arm_navigation_msgs/RobotState.h"
#include "arm_navigation_msgs/Constraints.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"
#include "arm_navigation_msgs/ContactInformation.h"

namespace arm_navigation_msgs
{

static const char GETJOINTTRAJECTORYVALIDITY[] = "arm_navigation_msgs/GetJointTrajectoryValidity";

  class GetJointTrajectoryValidityRequest : public ros::Msg
  {
    public:
      trajectory_msgs::JointTrajectory trajectory;
      arm_navigation_msgs::RobotState robot_state;
      bool check_collisions;
      bool check_path_constraints;
      bool check_goal_constraints;
      bool check_joint_limits;
      bool check_full_trajectory;
      arm_navigation_msgs::Constraints path_constraints;
      arm_navigation_msgs::Constraints goal_constraints;

    GetJointTrajectoryValidityRequest():
      trajectory(),
      robot_state(),
      check_collisions(0),
      check_path_constraints(0),
      check_goal_constraints(0),
      check_joint_limits(0),
      check_full_trajectory(0),
      path_constraints(),
      goal_constraints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->robot_state.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_check_collisions;
      u_check_collisions.real = this->check_collisions;
      *(outbuffer + offset + 0) = (u_check_collisions.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_collisions);
      union {
        bool real;
        uint8_t base;
      } u_check_path_constraints;
      u_check_path_constraints.real = this->check_path_constraints;
      *(outbuffer + offset + 0) = (u_check_path_constraints.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_path_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_goal_constraints;
      u_check_goal_constraints.real = this->check_goal_constraints;
      *(outbuffer + offset + 0) = (u_check_goal_constraints.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_goal_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_joint_limits;
      u_check_joint_limits.real = this->check_joint_limits;
      *(outbuffer + offset + 0) = (u_check_joint_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_joint_limits);
      union {
        bool real;
        uint8_t base;
      } u_check_full_trajectory;
      u_check_full_trajectory.real = this->check_full_trajectory;
      *(outbuffer + offset + 0) = (u_check_full_trajectory.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_full_trajectory);
      offset += this->path_constraints.serialize(outbuffer + offset);
      offset += this->goal_constraints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->robot_state.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_check_collisions;
      u_check_collisions.base = 0;
      u_check_collisions.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_collisions = u_check_collisions.real;
      offset += sizeof(this->check_collisions);
      union {
        bool real;
        uint8_t base;
      } u_check_path_constraints;
      u_check_path_constraints.base = 0;
      u_check_path_constraints.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_path_constraints = u_check_path_constraints.real;
      offset += sizeof(this->check_path_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_goal_constraints;
      u_check_goal_constraints.base = 0;
      u_check_goal_constraints.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_goal_constraints = u_check_goal_constraints.real;
      offset += sizeof(this->check_goal_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_joint_limits;
      u_check_joint_limits.base = 0;
      u_check_joint_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_joint_limits = u_check_joint_limits.real;
      offset += sizeof(this->check_joint_limits);
      union {
        bool real;
        uint8_t base;
      } u_check_full_trajectory;
      u_check_full_trajectory.base = 0;
      u_check_full_trajectory.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_full_trajectory = u_check_full_trajectory.real;
      offset += sizeof(this->check_full_trajectory);
      offset += this->path_constraints.deserialize(inbuffer + offset);
      offset += this->goal_constraints.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETJOINTTRAJECTORYVALIDITY; };
    const char * getMD5(){ return "b177ca39d851187b0f3db37b527fd4ea"; };

  };

  class GetJointTrajectoryValidityResponse : public ros::Msg
  {
    public:
      arm_navigation_msgs::ArmNavigationErrorCodes error_code;
      uint8_t trajectory_error_codes_length;
      arm_navigation_msgs::ArmNavigationErrorCodes st_trajectory_error_codes;
      arm_navigation_msgs::ArmNavigationErrorCodes * trajectory_error_codes;
      uint8_t contacts_length;
      arm_navigation_msgs::ContactInformation st_contacts;
      arm_navigation_msgs::ContactInformation * contacts;

    GetJointTrajectoryValidityResponse():
      error_code(),
      trajectory_error_codes_length(0), trajectory_error_codes(NULL),
      contacts_length(0), contacts(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      *(outbuffer + offset++) = trajectory_error_codes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < trajectory_error_codes_length; i++){
      offset += this->trajectory_error_codes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = contacts_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < contacts_length; i++){
      offset += this->contacts[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint8_t contacts_lengthT = *(inbuffer + offset++);
      if(contacts_lengthT > contacts_length)
        this->contacts = (arm_navigation_msgs::ContactInformation*)realloc(this->contacts, contacts_lengthT * sizeof(arm_navigation_msgs::ContactInformation));
      offset += 3;
      contacts_length = contacts_lengthT;
      for( uint8_t i = 0; i < contacts_length; i++){
      offset += this->st_contacts.deserialize(inbuffer + offset);
        memcpy( &(this->contacts[i]), &(this->st_contacts), sizeof(arm_navigation_msgs::ContactInformation));
      }
     return offset;
    }

    const char * getType(){ return GETJOINTTRAJECTORYVALIDITY; };
    const char * getMD5(){ return "a739823e2969bedb7e3343a4d8c097d4"; };

  };

  class GetJointTrajectoryValidity {
    public:
    typedef GetJointTrajectoryValidityRequest Request;
    typedef GetJointTrajectoryValidityResponse Response;
  };

}
#endif
