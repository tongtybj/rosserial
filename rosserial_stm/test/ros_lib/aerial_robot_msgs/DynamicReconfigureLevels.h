#ifndef _ROS_aerial_robot_msgs_DynamicReconfigureLevels_h
#define _ROS_aerial_robot_msgs_DynamicReconfigureLevels_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_msgs
{

  class DynamicReconfigureLevels : public ros::Msg
  {
    public:
      enum { RECONFIGURE_KALMAN_FILTER_FLAG =  0 };
      enum { RECONFIGURE_INPUT_SIGMA =  1 };
      enum { RECONFIGURE_BIAS_SIGMA =  2 };
      enum { RECONFIGURE_MEASURE_SIGMA =  3 };
      enum { RECONFIGURE_CONTROL_FLAG =  0 };
      enum { RECONFIGURE_P_GAIN =  1 };
      enum { RECONFIGURE_I_GAIN =  2 };
      enum { RECONFIGURE_D_GAIN =  3 };
      enum { RECONFIGURE_I_GAIN_HOVER =  4 };
      enum { RECONFIGURE_LIMIT =  5 };
      enum { RECONFIGURE_P_LIMIT =  6 };
      enum { RECONFIGURE_I_LIMIT =  7 };
      enum { RECONFIGURE_D_LIMIT =  8 };

    DynamicReconfigureLevels()
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

    const char * getType(){ return "aerial_robot_msgs/DynamicReconfigureLevels"; };
    const char * getMD5(){ return "939baaf5d10962a54b176302be23217e"; };

  };

}
#endif