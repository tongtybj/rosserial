#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_clearNoWait_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_clearNoWait_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_CLEARNOWAIT[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_clearNoWait";

  class OpenHRP_SequencePlayerService_clearNoWaitRequest : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_clearNoWaitRequest()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_CLEARNOWAIT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_clearNoWaitResponse : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_clearNoWaitResponse()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_CLEARNOWAIT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_clearNoWait {
    public:
    typedef OpenHRP_SequencePlayerService_clearNoWaitRequest Request;
    typedef OpenHRP_SequencePlayerService_clearNoWaitResponse Response;
  };

}
#endif
