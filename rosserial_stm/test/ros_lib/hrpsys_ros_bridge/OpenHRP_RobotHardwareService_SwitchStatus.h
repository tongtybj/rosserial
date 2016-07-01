#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_SwitchStatus_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_SwitchStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_RobotHardwareService_SwitchStatus : public ros::Msg
  {
    public:
      enum { SWITCH_ON = 0 };
      enum { SWITCH_OFF = 1 };

    OpenHRP_RobotHardwareService_SwitchStatus()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_SwitchStatus"; };
    const char * getMD5(){ return "ec565514ef07362353c05073330e91e3"; };

  };

}
#endif