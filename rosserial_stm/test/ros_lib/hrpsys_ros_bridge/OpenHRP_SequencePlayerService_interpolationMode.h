#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_SequencePlayerService_interpolationMode_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_SequencePlayerService_interpolationMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_SequencePlayerService_interpolationMode : public ros::Msg
  {
    public:
      enum { LINEAR = 0 };
      enum { HOFFARBIB = 1 };

    OpenHRP_SequencePlayerService_interpolationMode()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_interpolationMode"; };
    const char * getMD5(){ return "57f7f3dd41102d4164030da897386db8"; };

  };

}
#endif