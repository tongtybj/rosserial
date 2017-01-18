#ifndef _ROS_aerial_robot_base_Acc_h
#define _ROS_aerial_robot_base_Acc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace aerial_robot_base
{

  class Acc : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Vector3 acc_body_frame;
      geometry_msgs::Vector3 acc_world_frame;
      geometry_msgs::Vector3 acc_non_bias_world_frame;

    Acc():
      header(),
      acc_body_frame(),
      acc_world_frame(),
      acc_non_bias_world_frame()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->acc_body_frame.serialize(outbuffer + offset);
      offset += this->acc_world_frame.serialize(outbuffer + offset);
      offset += this->acc_non_bias_world_frame.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->acc_body_frame.deserialize(inbuffer + offset);
      offset += this->acc_world_frame.deserialize(inbuffer + offset);
      offset += this->acc_non_bias_world_frame.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "aerial_robot_base/Acc"; };
    const char * getMD5(){ return "cda10dc3733e23caa70166844a85cacd"; };

  };

}
#endif