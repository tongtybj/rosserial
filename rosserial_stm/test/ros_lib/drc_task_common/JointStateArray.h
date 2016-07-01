#ifndef _ROS_drc_task_common_JointStateArray_h
#define _ROS_drc_task_common_JointStateArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"

namespace drc_task_common
{

  class JointStateArray : public ros::Msg
  {
    public:
      int64_t step_time;
      uint8_t joint_state_array_length;
      sensor_msgs::JointState st_joint_state_array;
      sensor_msgs::JointState * joint_state_array;

    JointStateArray():
      step_time(0),
      joint_state_array_length(0), joint_state_array(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_step_time;
      u_step_time.real = this->step_time;
      *(outbuffer + offset + 0) = (u_step_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_step_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_step_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_step_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_step_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_step_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_step_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_step_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->step_time);
      *(outbuffer + offset++) = joint_state_array_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_state_array_length; i++){
      offset += this->joint_state_array[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_step_time;
      u_step_time.base = 0;
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_step_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->step_time = u_step_time.real;
      offset += sizeof(this->step_time);
      uint8_t joint_state_array_lengthT = *(inbuffer + offset++);
      if(joint_state_array_lengthT > joint_state_array_length)
        this->joint_state_array = (sensor_msgs::JointState*)realloc(this->joint_state_array, joint_state_array_lengthT * sizeof(sensor_msgs::JointState));
      offset += 3;
      joint_state_array_length = joint_state_array_lengthT;
      for( uint8_t i = 0; i < joint_state_array_length; i++){
      offset += this->st_joint_state_array.deserialize(inbuffer + offset);
        memcpy( &(this->joint_state_array[i]), &(this->st_joint_state_array), sizeof(sensor_msgs::JointState));
      }
     return offset;
    }

    const char * getType(){ return "drc_task_common/JointStateArray"; };
    const char * getMD5(){ return "438bb63ce9a3705838a1a0eda29c9a8b"; };

  };

}
#endif