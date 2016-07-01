#ifndef _ROS_drc_com_common_FC2OCSLargeReliable_h
#define _ROS_drc_com_common_FC2OCSLargeReliable_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"

namespace drc_com_common
{

  class FC2OCSLargeReliable : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 communication__locomotion_cloud;
      sensor_msgs::PointCloud2 communication__normal_flip_cloud;

    FC2OCSLargeReliable():
      communication__locomotion_cloud(),
      communication__normal_flip_cloud()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->communication__locomotion_cloud.serialize(outbuffer + offset);
      offset += this->communication__normal_flip_cloud.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->communication__locomotion_cloud.deserialize(inbuffer + offset);
      offset += this->communication__normal_flip_cloud.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "drc_com_common/FC2OCSLargeReliable"; };
    const char * getMD5(){ return "5a0d8b1e5042f7e5ca426fa579500b6d"; };

  };

}
#endif