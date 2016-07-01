#ifndef _ROS_pal_navigation_msgs_NavigationStatus_h
#define _ROS_pal_navigation_msgs_NavigationStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace pal_navigation_msgs
{

  class NavigationStatus : public ros::Msg
  {
    public:
      std_msgs::String status;
      std_msgs::String msg;

    NavigationStatus():
      status(),
      msg()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      offset += this->msg.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->msg.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/NavigationStatus"; };
    const char * getMD5(){ return "37841f68121395f14fd0a4c8470eb55c"; };

  };

}
#endif