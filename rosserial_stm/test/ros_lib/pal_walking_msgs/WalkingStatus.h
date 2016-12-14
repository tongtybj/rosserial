#ifndef _ROS_pal_walking_msgs_WalkingStatus_h
#define _ROS_pal_walking_msgs_WalkingStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace pal_walking_msgs
{

  class WalkingStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose hip_reference_pose;
      geometry_msgs::Pose foot_reference_pose[2];
      geometry_msgs::Point zmp_reference;

    WalkingStatus():
      header(),
      hip_reference_pose(),
      foot_reference_pose(),
      zmp_reference()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->hip_reference_pose.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 2; i++){
      offset += this->foot_reference_pose[i].serialize(outbuffer + offset);
      }
      offset += this->zmp_reference.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->hip_reference_pose.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 2; i++){
      offset += this->foot_reference_pose[i].deserialize(inbuffer + offset);
      }
      offset += this->zmp_reference.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_walking_msgs/WalkingStatus"; };
    const char * getMD5(){ return "86de80b808fb27b3f11d218fa8d1c16e"; };

  };

}
#endif