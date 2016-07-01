#ifndef _ROS_SERVICE_OpenHRP_StateHolderService_getCommand_h
#define _ROS_SERVICE_OpenHRP_StateHolderService_getCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_StateHolderService_Command.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_STATEHOLDERSERVICE_GETCOMMAND[] = "hrpsys_ros_bridge/OpenHRP_StateHolderService_getCommand";

  class OpenHRP_StateHolderService_getCommandRequest : public ros::Msg
  {
    public:

    OpenHRP_StateHolderService_getCommandRequest()
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

    const char * getType(){ return OPENHRP_STATEHOLDERSERVICE_GETCOMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StateHolderService_getCommandResponse : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_StateHolderService_Command com;

    OpenHRP_StateHolderService_getCommandResponse():
      com()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->com.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->com.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_STATEHOLDERSERVICE_GETCOMMAND; };
    const char * getMD5(){ return "82722c7e58862c8415734cb1427363c7"; };

  };

  class OpenHRP_StateHolderService_getCommand {
    public:
    typedef OpenHRP_StateHolderService_getCommandRequest Request;
    typedef OpenHRP_StateHolderService_getCommandResponse Response;
  };

}
#endif
