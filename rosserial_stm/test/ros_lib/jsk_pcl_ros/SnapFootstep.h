#ifndef _ROS_SERVICE_SnapFootstep_h
#define _ROS_SERVICE_SnapFootstep_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/FootstepArray.h"

namespace jsk_pcl_ros
{

static const char SNAPFOOTSTEP[] = "jsk_pcl_ros/SnapFootstep";

  class SnapFootstepRequest : public ros::Msg
  {
    public:
      jsk_footstep_msgs::FootstepArray input;

    SnapFootstepRequest():
      input()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->input.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->input.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SNAPFOOTSTEP; };
    const char * getMD5(){ return "dc2018060e7c3bfcb9de24e7c9deb38e"; };

  };

  class SnapFootstepResponse : public ros::Msg
  {
    public:
      jsk_footstep_msgs::FootstepArray output;

    SnapFootstepResponse():
      output()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->output.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->output.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SNAPFOOTSTEP; };
    const char * getMD5(){ return "1c7ba73355dc7d7b5f68ebb3f619151c"; };

  };

  class SnapFootstep {
    public:
    typedef SnapFootstepRequest Request;
    typedef SnapFootstepResponse Response;
  };

}
#endif
