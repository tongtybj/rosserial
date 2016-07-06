#ifndef _ROS_hrpsys_gazebo_atlas_TrianglePoints_h
#define _ROS_hrpsys_gazebo_atlas_TrianglePoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PointStamped.h"

namespace hrpsys_gazebo_atlas
{

  class TrianglePoints : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::PointStamped a;
      geometry_msgs::PointStamped b;
      geometry_msgs::PointStamped c;

    TrianglePoints():
      header(),
      a(),
      b(),
      c()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->a.serialize(outbuffer + offset);
      offset += this->b.serialize(outbuffer + offset);
      offset += this->c.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->a.deserialize(inbuffer + offset);
      offset += this->b.deserialize(inbuffer + offset);
      offset += this->c.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "hrpsys_gazebo_atlas/TrianglePoints"; };
    const char * getMD5(){ return "9f998f5f2e9c4fb9a8398f659a1f2ade"; };

  };

}
#endif