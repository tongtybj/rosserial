#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_initializeJointAngle_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_initializeJointAngle_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_INITIALIZEJOINTANGLE[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_initializeJointAngle";

  class OpenHRP_RobotHardwareService_initializeJointAngleRequest : public ros::Msg
  {
    public:
      const char* name;
      const char* option;

    OpenHRP_RobotHardwareService_initializeJointAngleRequest():
      name(""),
      option("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_option = strlen(this->option);
      memcpy(outbuffer + offset, &length_option, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->option, length_option);
      offset += length_option;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_option;
      memcpy(&length_option, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_option; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_option-1]=0;
      this->option = (char *)(inbuffer + offset-1);
      offset += length_option;
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_INITIALIZEJOINTANGLE; };
    const char * getMD5(){ return "1f187d913a45678444274a52540c7cbb"; };

  };

  class OpenHRP_RobotHardwareService_initializeJointAngleResponse : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_initializeJointAngleResponse()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_INITIALIZEJOINTANGLE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_initializeJointAngle {
    public:
    typedef OpenHRP_RobotHardwareService_initializeJointAngleRequest Request;
    typedef OpenHRP_RobotHardwareService_initializeJointAngleResponse Response;
  };

}
#endif
