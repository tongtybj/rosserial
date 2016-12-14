#ifndef _ROS_arm_navigation_msgs_MoveArmStatistics_h
#define _ROS_arm_navigation_msgs_MoveArmStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"

namespace arm_navigation_msgs
{

  class MoveArmStatistics : public ros::Msg
  {
    public:
      int32_t request_id;
      const char* result;
      arm_navigation_msgs::ArmNavigationErrorCodes error_code;
      double planning_time;
      double smoothing_time;
      double ik_time;
      double time_to_execution;
      double time_to_result;
      bool preempted;
      double num_replans;
      double trajectory_duration;
      const char* planner_service_name;

    MoveArmStatistics():
      request_id(0),
      result(""),
      error_code(),
      planning_time(0),
      smoothing_time(0),
      ik_time(0),
      time_to_execution(0),
      time_to_result(0),
      preempted(0),
      num_replans(0),
      trajectory_duration(0),
      planner_service_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_request_id;
      u_request_id.real = this->request_id;
      *(outbuffer + offset + 0) = (u_request_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_request_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_request_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_request_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->request_id);
      uint32_t length_result = strlen(this->result);
      memcpy(outbuffer + offset, &length_result, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result, length_result);
      offset += length_result;
      offset += this->error_code.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_planning_time;
      u_planning_time.real = this->planning_time;
      *(outbuffer + offset + 0) = (u_planning_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_planning_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_planning_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_planning_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_planning_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_planning_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_planning_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_planning_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->planning_time);
      union {
        double real;
        uint64_t base;
      } u_smoothing_time;
      u_smoothing_time.real = this->smoothing_time;
      *(outbuffer + offset + 0) = (u_smoothing_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_smoothing_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_smoothing_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_smoothing_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_smoothing_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_smoothing_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_smoothing_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_smoothing_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->smoothing_time);
      union {
        double real;
        uint64_t base;
      } u_ik_time;
      u_ik_time.real = this->ik_time;
      *(outbuffer + offset + 0) = (u_ik_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ik_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ik_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ik_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ik_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ik_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ik_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ik_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ik_time);
      union {
        double real;
        uint64_t base;
      } u_time_to_execution;
      u_time_to_execution.real = this->time_to_execution;
      *(outbuffer + offset + 0) = (u_time_to_execution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_to_execution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_to_execution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_to_execution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_time_to_execution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_time_to_execution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_time_to_execution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_time_to_execution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->time_to_execution);
      union {
        double real;
        uint64_t base;
      } u_time_to_result;
      u_time_to_result.real = this->time_to_result;
      *(outbuffer + offset + 0) = (u_time_to_result.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_to_result.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_to_result.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_to_result.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_time_to_result.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_time_to_result.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_time_to_result.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_time_to_result.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->time_to_result);
      union {
        bool real;
        uint8_t base;
      } u_preempted;
      u_preempted.real = this->preempted;
      *(outbuffer + offset + 0) = (u_preempted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->preempted);
      union {
        double real;
        uint64_t base;
      } u_num_replans;
      u_num_replans.real = this->num_replans;
      *(outbuffer + offset + 0) = (u_num_replans.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_num_replans.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_num_replans.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_num_replans.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_num_replans.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_num_replans.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_num_replans.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_num_replans.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->num_replans);
      union {
        double real;
        uint64_t base;
      } u_trajectory_duration;
      u_trajectory_duration.real = this->trajectory_duration;
      *(outbuffer + offset + 0) = (u_trajectory_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trajectory_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trajectory_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trajectory_duration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_trajectory_duration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_trajectory_duration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_trajectory_duration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_trajectory_duration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->trajectory_duration);
      uint32_t length_planner_service_name = strlen(this->planner_service_name);
      memcpy(outbuffer + offset, &length_planner_service_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->planner_service_name, length_planner_service_name);
      offset += length_planner_service_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_request_id;
      u_request_id.base = 0;
      u_request_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_request_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_request_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_request_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->request_id = u_request_id.real;
      offset += sizeof(this->request_id);
      uint32_t length_result;
      memcpy(&length_result, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result-1]=0;
      this->result = (char *)(inbuffer + offset-1);
      offset += length_result;
      offset += this->error_code.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_planning_time;
      u_planning_time.base = 0;
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->planning_time = u_planning_time.real;
      offset += sizeof(this->planning_time);
      union {
        double real;
        uint64_t base;
      } u_smoothing_time;
      u_smoothing_time.base = 0;
      u_smoothing_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_smoothing_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_smoothing_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_smoothing_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_smoothing_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_smoothing_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_smoothing_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_smoothing_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->smoothing_time = u_smoothing_time.real;
      offset += sizeof(this->smoothing_time);
      union {
        double real;
        uint64_t base;
      } u_ik_time;
      u_ik_time.base = 0;
      u_ik_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ik_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ik_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ik_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ik_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ik_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ik_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ik_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ik_time = u_ik_time.real;
      offset += sizeof(this->ik_time);
      union {
        double real;
        uint64_t base;
      } u_time_to_execution;
      u_time_to_execution.base = 0;
      u_time_to_execution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_to_execution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_to_execution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_to_execution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_time_to_execution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_time_to_execution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_time_to_execution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_time_to_execution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->time_to_execution = u_time_to_execution.real;
      offset += sizeof(this->time_to_execution);
      union {
        double real;
        uint64_t base;
      } u_time_to_result;
      u_time_to_result.base = 0;
      u_time_to_result.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_to_result.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_to_result.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_to_result.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_time_to_result.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_time_to_result.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_time_to_result.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_time_to_result.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->time_to_result = u_time_to_result.real;
      offset += sizeof(this->time_to_result);
      union {
        bool real;
        uint8_t base;
      } u_preempted;
      u_preempted.base = 0;
      u_preempted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->preempted = u_preempted.real;
      offset += sizeof(this->preempted);
      union {
        double real;
        uint64_t base;
      } u_num_replans;
      u_num_replans.base = 0;
      u_num_replans.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_num_replans.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_num_replans.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_num_replans.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_num_replans.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_num_replans.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_num_replans.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_num_replans.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->num_replans = u_num_replans.real;
      offset += sizeof(this->num_replans);
      union {
        double real;
        uint64_t base;
      } u_trajectory_duration;
      u_trajectory_duration.base = 0;
      u_trajectory_duration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_trajectory_duration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_trajectory_duration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_trajectory_duration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_trajectory_duration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_trajectory_duration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_trajectory_duration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_trajectory_duration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->trajectory_duration = u_trajectory_duration.real;
      offset += sizeof(this->trajectory_duration);
      uint32_t length_planner_service_name;
      memcpy(&length_planner_service_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_service_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_service_name-1]=0;
      this->planner_service_name = (char *)(inbuffer + offset-1);
      offset += length_planner_service_name;
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MoveArmStatistics"; };
    const char * getMD5(){ return "d83dee1348791a0d1414257b41bc161f"; };

  };

}
#endif