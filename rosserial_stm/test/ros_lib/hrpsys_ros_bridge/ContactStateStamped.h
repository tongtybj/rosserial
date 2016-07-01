#ifndef _ROS_hrpsys_ros_bridge_ContactStateStamped_h
#define _ROS_hrpsys_ros_bridge_ContactStateStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "hrpsys_ros_bridge/ContactState.h"

namespace hrpsys_ros_bridge
{

  class ContactStateStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      hrpsys_ros_bridge::ContactState state;

    ContactStateStamped():
      header(),
      state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/ContactStateStamped"; };
    const char * getMD5(){ return "33b96bc9f8d60bdd8334b7300881120b"; };

  };

}
#endif