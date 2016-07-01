#ifndef _ROS_hydrus_gap_passing_PlanningMode_h
#define _ROS_hydrus_gap_passing_PlanningMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus_gap_passing
{

  class PlanningMode : public ros::Msg
  {
    public:
      enum { ONLY_JOINTS_MODE =  0 };
      enum { ONLY_BASE_MODE =  1 };
      enum { JOINTS_AND_BASE_MODE =  2 };
      enum { ORIGINAL_MODE =  3 };
      enum { POSITION_MODE =  0 };
      enum { VELOCITY_MODE =  1 };

    PlanningMode()
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

    const char * getType(){ return "hydrus_gap_passing/PlanningMode"; };
    const char * getMD5(){ return "90b1437ac9dbd060b3456ccddb2441de"; };

  };

}
#endif