#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_waitInterpolation_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_waitInterpolation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_WAITINTERPOLATION[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_waitInterpolation";

  class OpenHRP_SequencePlayerService_waitInterpolationRequest : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_waitInterpolationRequest()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_WAITINTERPOLATION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_waitInterpolationResponse : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_waitInterpolationResponse()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_WAITINTERPOLATION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_waitInterpolation {
    public:
    typedef OpenHRP_SequencePlayerService_waitInterpolationRequest Request;
    typedef OpenHRP_SequencePlayerService_waitInterpolationResponse Response;
  };

}
#endif
