#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_getStatus_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_getStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_RobotState.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_GETSTATUS[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_getStatus";

  class OpenHRP_RobotHardwareService_getStatusRequest : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_getStatusRequest()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_GETSTATUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_getStatusResponse : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_RobotHardwareService_RobotState rs;

    OpenHRP_RobotHardwareService_getStatusResponse():
      rs()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->rs.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->rs.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_GETSTATUS; };
    const char * getMD5(){ return "3a64c95b4bc8a08e004a7311af9c3ea1"; };

  };

  class OpenHRP_RobotHardwareService_getStatus {
    public:
    typedef OpenHRP_RobotHardwareService_getStatusRequest Request;
    typedef OpenHRP_RobotHardwareService_getStatusResponse Response;
  };

}
#endif
