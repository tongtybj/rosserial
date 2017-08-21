#ifndef _ROS_aerial_robot_base_FlatnessPid_h
#define _ROS_aerial_robot_base_FlatnessPid_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "aerial_robot_base/Pid.h"

namespace aerial_robot_base
{

  class FlatnessPid : public ros::Msg
  {
    public:
      std_msgs::Header header;
      aerial_robot_base::Pid pitch;
      aerial_robot_base::Pid roll;
      aerial_robot_base::Pid yaw;
      aerial_robot_base::Pid throttle;

    FlatnessPid():
      header(),
      pitch(),
      roll(),
      yaw(),
      throttle()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pitch.serialize(outbuffer + offset);
      offset += this->roll.serialize(outbuffer + offset);
      offset += this->yaw.serialize(outbuffer + offset);
      offset += this->throttle.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pitch.deserialize(inbuffer + offset);
      offset += this->roll.deserialize(inbuffer + offset);
      offset += this->yaw.deserialize(inbuffer + offset);
      offset += this->throttle.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "aerial_robot_base/FlatnessPid"; };
    const char * getMD5(){ return "58927c3a6b835cfa26ef78f9be9494eb"; };

  };

}
#endif