#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_RobotHardwareService : public ros::Msg
  {
    public:
      enum { CALIB_STATE_MASK = 1 };
      enum { CALIB_STATE_SHIFT = 0 };
      enum { SERVO_STATE_MASK = 2 };
      enum { SERVO_STATE_SHIFT = 1 };
      enum { POWER_STATE_MASK = 4 };
      enum { POWER_STATE_SHIFT = 2 };
      enum { SERVO_ALARM_MASK = 524280 };
      enum { SERVO_ALARM_SHIFT = 3 };
      enum { DRIVER_TEMP_MASK = 4278190080 };
      enum { DRIVER_TEMP_SHIFT = 24 };

    OpenHRP_RobotHardwareService()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_RobotHardwareService"; };
    const char * getMD5(){ return "13bb76b73b9272a28354cc2f6009696a"; };

  };

}
#endif