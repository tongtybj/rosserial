#ifndef _ROS_rwt_moveit_MoveGroupPlan_h
#define _ROS_rwt_moveit_MoveGroupPlan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace rwt_moveit
{

  class MoveGroupPlan : public ros::Msg
  {
    public:
      std_msgs::Float64MultiArray start_joint;
      std_msgs::Float64MultiArray goal_joint;
      bool plan_only;
      const char* group_name;

    MoveGroupPlan():
      start_joint(),
      goal_joint(),
      plan_only(0),
      group_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->start_joint.serialize(outbuffer + offset);
      offset += this->goal_joint.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_plan_only;
      u_plan_only.real = this->plan_only;
      *(outbuffer + offset + 0) = (u_plan_only.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_only);
      uint32_t length_group_name = strlen(this->group_name);
      memcpy(outbuffer + offset, &length_group_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->start_joint.deserialize(inbuffer + offset);
      offset += this->goal_joint.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_plan_only;
      u_plan_only.base = 0;
      u_plan_only.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->plan_only = u_plan_only.real;
      offset += sizeof(this->plan_only);
      uint32_t length_group_name;
      memcpy(&length_group_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
     return offset;
    }

    const char * getType(){ return "rwt_moveit/MoveGroupPlan"; };
    const char * getMD5(){ return "065044a6e0424a9630c84678ed97a96b"; };

  };

}
#endif