#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_calibrateInertiaSensor_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_calibrateInertiaSensor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_CALIBRATEINERTIASENSOR[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_calibrateInertiaSensor";

  class OpenHRP_RobotHardwareService_calibrateInertiaSensorRequest : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_calibrateInertiaSensorRequest()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_CALIBRATEINERTIASENSOR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_calibrateInertiaSensorResponse : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_calibrateInertiaSensorResponse()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_CALIBRATEINERTIASENSOR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_calibrateInertiaSensor {
    public:
    typedef OpenHRP_RobotHardwareService_calibrateInertiaSensorRequest Request;
    typedef OpenHRP_RobotHardwareService_calibrateInertiaSensorResponse Response;
  };

}
#endif
