#ifndef _ROS_hrpsys_ros_bridge_ContactStatesStamped_h
#define _ROS_hrpsys_ros_bridge_ContactStatesStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "hrpsys_ros_bridge/ContactStateStamped.h"

namespace hrpsys_ros_bridge
{

  class ContactStatesStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t states_length;
      hrpsys_ros_bridge::ContactStateStamped st_states;
      hrpsys_ros_bridge::ContactStateStamped * states;

    ContactStatesStamped():
      header(),
      states_length(0), states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = states_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t states_lengthT = *(inbuffer + offset++);
      if(states_lengthT > states_length)
        this->states = (hrpsys_ros_bridge::ContactStateStamped*)realloc(this->states, states_lengthT * sizeof(hrpsys_ros_bridge::ContactStateStamped));
      offset += 3;
      states_length = states_lengthT;
      for( uint8_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(hrpsys_ros_bridge::ContactStateStamped));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/ContactStatesStamped"; };
    const char * getMD5(){ return "b6742b9b07d60b922dd6c77d76e65fc7"; };

  };

}
#endif