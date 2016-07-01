#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_clear_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_clear_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_CLEAR[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_clear";

  class OpenHRP_SequencePlayerService_clearRequest : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_clearRequest()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_CLEAR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_clearResponse : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_clearResponse()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_CLEAR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_clear {
    public:
    typedef OpenHRP_SequencePlayerService_clearRequest Request;
    typedef OpenHRP_SequencePlayerService_clearResponse Response;
  };

}
#endif
