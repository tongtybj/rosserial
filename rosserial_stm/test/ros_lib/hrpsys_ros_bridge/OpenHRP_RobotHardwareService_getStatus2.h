#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_getStatus2_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_getStatus2_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_RobotState2.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_GETSTATUS2[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_getStatus2";

  class OpenHRP_RobotHardwareService_getStatus2Request : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_getStatus2Request()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_GETSTATUS2; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_getStatus2Response : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_RobotHardwareService_RobotState2 rs;

    OpenHRP_RobotHardwareService_getStatus2Response():
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_GETSTATUS2; };
    const char * getMD5(){ return "bd0e2ea5e292124095d8b69ec2baf944"; };

  };

  class OpenHRP_RobotHardwareService_getStatus2 {
    public:
    typedef OpenHRP_RobotHardwareService_getStatus2Request Request;
    typedef OpenHRP_RobotHardwareService_getStatus2Response Response;
  };

}
#endif
