#ifndef _ROS_kinematics_msgs_PositionIKRequest_h
#define _ROS_kinematics_msgs_PositionIKRequest_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "arm_navigation_msgs/RobotState.h"

namespace kinematics_msgs
{

  class PositionIKRequest : public ros::Msg
  {
    public:
      const char* ik_link_name;
      geometry_msgs::PoseStamped pose_stamped;
      arm_navigation_msgs::RobotState ik_seed_state;
      arm_navigation_msgs::RobotState robot_state;

    PositionIKRequest():
      ik_link_name(""),
      pose_stamped(),
      ik_seed_state(),
      robot_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_ik_link_name = strlen(this->ik_link_name);
      memcpy(outbuffer + offset, &length_ik_link_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ik_link_name, length_ik_link_name);
      offset += length_ik_link_name;
      offset += this->pose_stamped.serialize(outbuffer + offset);
      offset += this->ik_seed_state.serialize(outbuffer + offset);
      offset += this->robot_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_ik_link_name;
      memcpy(&length_ik_link_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ik_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ik_link_name-1]=0;
      this->ik_link_name = (char *)(inbuffer + offset-1);
      offset += length_ik_link_name;
      offset += this->pose_stamped.deserialize(inbuffer + offset);
      offset += this->ik_seed_state.deserialize(inbuffer + offset);
      offset += this->robot_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "kinematics_msgs/PositionIKRequest"; };
    const char * getMD5(){ return "737bb756c6253bdd460b1383d0b12dac"; };

  };

}
#endif