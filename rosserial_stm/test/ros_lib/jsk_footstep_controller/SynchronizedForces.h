#ifndef _ROS_jsk_footstep_controller_SynchronizedForces_h
#define _ROS_jsk_footstep_controller_SynchronizedForces_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/WrenchStamped.h"
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/PointStamped.h"

namespace jsk_footstep_controller
{

  class SynchronizedForces : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::WrenchStamped lleg_force;
      geometry_msgs::WrenchStamped rleg_force;
      sensor_msgs::JointState joint_angles;
      geometry_msgs::PointStamped zmp;

    SynchronizedForces():
      header(),
      lleg_force(),
      rleg_force(),
      joint_angles(),
      zmp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->lleg_force.serialize(outbuffer + offset);
      offset += this->rleg_force.serialize(outbuffer + offset);
      offset += this->joint_angles.serialize(outbuffer + offset);
      offset += this->zmp.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->lleg_force.deserialize(inbuffer + offset);
      offset += this->rleg_force.deserialize(inbuffer + offset);
      offset += this->joint_angles.deserialize(inbuffer + offset);
      offset += this->zmp.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_controller/SynchronizedForces"; };
    const char * getMD5(){ return "9f34791d0775ccd699ccdfdb8b823128"; };

  };

}
#endif