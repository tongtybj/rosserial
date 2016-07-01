#ifndef _ROS_hrpsys_ros_bridge_SDOPackage_Organization_h
#define _ROS_hrpsys_ros_bridge_SDOPackage_Organization_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class SDOPackage_Organization : public ros::Msg
  {
    public:

    SDOPackage_Organization()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/SDOPackage_Organization"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif