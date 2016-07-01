#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AABB_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AABB_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/RTC_Point3D.h"
#include "hrpsys_ros_bridge/RTC_Size3D.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AABB : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::RTC_Point3D pos;
      hrpsys_ros_bridge::RTC_Size3D size;

    OpenHRP_AABB():
      pos(),
      size()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pos.serialize(outbuffer + offset);
      offset += this->size.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pos.deserialize(inbuffer + offset);
      offset += this->size.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AABB"; };
    const char * getMD5(){ return "f5aef74dcd8b839096ae85b0d193cdde"; };

  };

}
#endif