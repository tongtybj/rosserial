#ifndef _ROS_jsk_mbzirc_task1_common_FC2OCSImage_h
#define _ROS_jsk_mbzirc_task1_common_FC2OCSImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"

namespace jsk_mbzirc_task1_common
{

  class FC2OCSImage : public ros::Msg
  {
    public:
      sensor_msgs::Image camera__small_image;

    FC2OCSImage():
      camera__small_image()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->camera__small_image.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->camera__small_image.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_mbzirc_task1_common/FC2OCSImage"; };
    const char * getMD5(){ return "bbad0a487010bedbe02445573869dbb6"; };

  };

}
#endif