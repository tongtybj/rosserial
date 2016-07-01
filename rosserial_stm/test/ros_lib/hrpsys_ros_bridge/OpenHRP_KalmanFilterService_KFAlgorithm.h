#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_KalmanFilterService_KFAlgorithm_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_KalmanFilterService_KFAlgorithm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_KalmanFilterService_KFAlgorithm : public ros::Msg
  {
    public:
      enum { RPYKalmanFilter = 0 };
      enum { QuaternionExtendedKalmanFilter = 1 };

    OpenHRP_KalmanFilterService_KFAlgorithm()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_KalmanFilterService_KFAlgorithm"; };
    const char * getMD5(){ return "23088f8d998cf87bbf30a92ddbf83d7e"; };

  };

}
#endif