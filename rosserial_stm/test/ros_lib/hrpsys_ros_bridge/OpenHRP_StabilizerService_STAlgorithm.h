#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_STAlgorithm_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_STAlgorithm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_STAlgorithm : public ros::Msg
  {
    public:
      enum { TPCC = 0 };
      enum { EEFM = 1 };
      enum { EEFMQP = 2 };
      enum { EEFMQPCOP = 3 };

    OpenHRP_StabilizerService_STAlgorithm()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_STAlgorithm"; };
    const char * getMD5(){ return "7422f08fac709ca231d66587a0423ab2"; };

  };

}
#endif