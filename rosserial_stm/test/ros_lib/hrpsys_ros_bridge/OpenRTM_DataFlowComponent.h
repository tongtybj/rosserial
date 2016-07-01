#ifndef _ROS_hrpsys_ros_bridge_OpenRTM_DataFlowComponent_h
#define _ROS_hrpsys_ros_bridge_OpenRTM_DataFlowComponent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenRTM_DataFlowComponent : public ros::Msg
  {
    public:

    OpenRTM_DataFlowComponent()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenRTM_DataFlowComponent"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif