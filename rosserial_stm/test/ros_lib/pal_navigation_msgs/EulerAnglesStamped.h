#ifndef _ROS_pal_navigation_msgs_EulerAnglesStamped_h
#define _ROS_pal_navigation_msgs_EulerAnglesStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pal_navigation_msgs/EulerAngles.h"

namespace pal_navigation_msgs
{

  class EulerAnglesStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      pal_navigation_msgs::EulerAngles angles;

    EulerAnglesStamped():
      header(),
      angles()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->angles.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->angles.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/EulerAnglesStamped"; };
    const char * getMD5(){ return "08ed1513cf62c3aa9d3f21c206745853"; };

  };

}
#endif