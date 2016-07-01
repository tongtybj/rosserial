#ifndef _ROS_SERVICE_GetIKArmPose_h
#define _ROS_SERVICE_GetIKArmPose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace drc_task_common
{

static const char GETIKARMPOSE[] = "drc_task_common/GetIKArmPose";

  class GetIKArmPoseRequest : public ros::Msg
  {
    public:

    GetIKArmPoseRequest()
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

    const char * getType(){ return GETIKARMPOSE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetIKArmPoseResponse : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped pose_stamped;

    GetIKArmPoseResponse():
      pose_stamped()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose_stamped.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose_stamped.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETIKARMPOSE; };
    const char * getMD5(){ return "a6cf8bca3220fd47abb2c1783444110d"; };

  };

  class GetIKArmPose {
    public:
    typedef GetIKArmPoseRequest Request;
    typedef GetIKArmPoseResponse Response;
  };

}
#endif
