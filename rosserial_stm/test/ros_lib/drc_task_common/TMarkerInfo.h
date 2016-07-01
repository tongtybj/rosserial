#ifndef _ROS_drc_task_common_TMarkerInfo_h
#define _ROS_drc_task_common_TMarkerInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "jsk_interactive_marker/MarkerDimensions.h"

namespace drc_task_common
{

  class TMarkerInfo : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped marker_pose_stamped;
      jsk_interactive_marker::MarkerDimensions marker_dim;

    TMarkerInfo():
      marker_pose_stamped(),
      marker_dim()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->marker_pose_stamped.serialize(outbuffer + offset);
      offset += this->marker_dim.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->marker_pose_stamped.deserialize(inbuffer + offset);
      offset += this->marker_dim.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "drc_task_common/TMarkerInfo"; };
    const char * getMD5(){ return "0d8c4d70036546b1a908419bb824cc6a"; };

  };

}
#endif