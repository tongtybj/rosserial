#ifndef _ROS_arm_navigation_msgs_MotionPlanRequest_h
#define _ROS_arm_navigation_msgs_MotionPlanRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/WorkspaceParameters.h"
#include "arm_navigation_msgs/RobotState.h"
#include "arm_navigation_msgs/Constraints.h"
#include "ros/duration.h"

namespace arm_navigation_msgs
{

  class MotionPlanRequest : public ros::Msg
  {
    public:
      arm_navigation_msgs::WorkspaceParameters workspace_parameters;
      arm_navigation_msgs::RobotState start_state;
      arm_navigation_msgs::Constraints goal_constraints;
      arm_navigation_msgs::Constraints path_constraints;
      const char* planner_id;
      const char* group_name;
      int32_t num_planning_attempts;
      ros::Duration allowed_planning_time;
      ros::Duration expected_path_duration;
      ros::Duration expected_path_dt;

    MotionPlanRequest():
      workspace_parameters(),
      start_state(),
      goal_constraints(),
      path_constraints(),
      planner_id(""),
      group_name(""),
      num_planning_attempts(0),
      allowed_planning_time(),
      expected_path_duration(),
      expected_path_dt()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->workspace_parameters.serialize(outbuffer + offset);
      offset += this->start_state.serialize(outbuffer + offset);
      offset += this->goal_constraints.serialize(outbuffer + offset);
      offset += this->path_constraints.serialize(outbuffer + offset);
      uint32_t length_planner_id = strlen(this->planner_id);
      memcpy(outbuffer + offset, &length_planner_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->planner_id, length_planner_id);
      offset += length_planner_id;
      uint32_t length_group_name = strlen(this->group_name);
      memcpy(outbuffer + offset, &length_group_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      union {
        int32_t real;
        uint32_t base;
      } u_num_planning_attempts;
      u_num_planning_attempts.real = this->num_planning_attempts;
      *(outbuffer + offset + 0) = (u_num_planning_attempts.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_planning_attempts.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_planning_attempts.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_planning_attempts.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_planning_attempts);
      *(outbuffer + offset + 0) = (this->allowed_planning_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_planning_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_planning_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_planning_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_planning_time.sec);
      *(outbuffer + offset + 0) = (this->allowed_planning_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_planning_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_planning_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_planning_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_planning_time.nsec);
      *(outbuffer + offset + 0) = (this->expected_path_duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->expected_path_duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->expected_path_duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->expected_path_duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->expected_path_duration.sec);
      *(outbuffer + offset + 0) = (this->expected_path_duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->expected_path_duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->expected_path_duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->expected_path_duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->expected_path_duration.nsec);
      *(outbuffer + offset + 0) = (this->expected_path_dt.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->expected_path_dt.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->expected_path_dt.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->expected_path_dt.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->expected_path_dt.sec);
      *(outbuffer + offset + 0) = (this->expected_path_dt.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->expected_path_dt.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->expected_path_dt.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->expected_path_dt.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->expected_path_dt.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->workspace_parameters.deserialize(inbuffer + offset);
      offset += this->start_state.deserialize(inbuffer + offset);
      offset += this->goal_constraints.deserialize(inbuffer + offset);
      offset += this->path_constraints.deserialize(inbuffer + offset);
      uint32_t length_planner_id;
      memcpy(&length_planner_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_id-1]=0;
      this->planner_id = (char *)(inbuffer + offset-1);
      offset += length_planner_id;
      uint32_t length_group_name;
      memcpy(&length_group_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      union {
        int32_t real;
        uint32_t base;
      } u_num_planning_attempts;
      u_num_planning_attempts.base = 0;
      u_num_planning_attempts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_planning_attempts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_planning_attempts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_planning_attempts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->num_planning_attempts = u_num_planning_attempts.real;
      offset += sizeof(this->num_planning_attempts);
      this->allowed_planning_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->allowed_planning_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->allowed_planning_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->allowed_planning_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->allowed_planning_time.sec);
      this->allowed_planning_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->allowed_planning_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->allowed_planning_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->allowed_planning_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->allowed_planning_time.nsec);
      this->expected_path_duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->expected_path_duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->expected_path_duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->expected_path_duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->expected_path_duration.sec);
      this->expected_path_duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->expected_path_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->expected_path_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->expected_path_duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->expected_path_duration.nsec);
      this->expected_path_dt.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->expected_path_dt.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->expected_path_dt.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->expected_path_dt.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->expected_path_dt.sec);
      this->expected_path_dt.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->expected_path_dt.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->expected_path_dt.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->expected_path_dt.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->expected_path_dt.nsec);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MotionPlanRequest"; };
    const char * getMD5(){ return "75408e881303c6ad5069bd5df65ecb00"; };

  };

}
#endif