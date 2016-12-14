#ifndef _ROS_jsk_mbzirc_task1_common_OCS2FCImage_h
#define _ROS_jsk_mbzirc_task1_common_OCS2FCImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"

namespace jsk_mbzirc_task1_common
{

  class OCS2FCImage : public ros::Msg
  {
    public:
      geometry_msgs::PolygonStamped camera__small_image__screenrectangle;

    OCS2FCImage():
      camera__small_image__screenrectangle()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->camera__small_image__screenrectangle.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->camera__small_image__screenrectangle.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_mbzirc_task1_common/OCS2FCImage"; };
    const char * getMD5(){ return "cdbd19f0d8aabbf8aaa6caf74384d6c2"; };

  };

}
#endif