#ifndef _ROS_SERVICE_GoPosCommand_h
#define _ROS_SERVICE_GoPosCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace drc_task_common
{

static const char GOPOSCOMMAND[] = "drc_task_common/GoPosCommand";

  class GoPosCommandRequest : public ros::Msg
  {
    public:
      geometry_msgs::Pose goal;

    GoPosCommandRequest():
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GOPOSCOMMAND; };
    const char * getMD5(){ return "313b76aa4f010582b3257488c62ac366"; };

  };

  class GoPosCommandResponse : public ros::Msg
  {
    public:

    GoPosCommandResponse()
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

    const char * getType(){ return GOPOSCOMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GoPosCommand {
    public:
    typedef GoPosCommandRequest Request;
    typedef GoPosCommandResponse Response;
  };

}
#endif
