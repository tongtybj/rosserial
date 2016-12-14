#ifndef _ROS_SERVICE_GetConstraintAwarePositionIK_h
#define _ROS_SERVICE_GetConstraintAwarePositionIK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/Constraints.h"
#include "ros/duration.h"
#include "arm_navigation_msgs/RobotState.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"
#include "kinematics_msgs/PositionIKRequest.h"

namespace kinematics_msgs
{

static const char GETCONSTRAINTAWAREPOSITIONIK[] = "kinematics_msgs/GetConstraintAwarePositionIK";

  class GetConstraintAwarePositionIKRequest : public ros::Msg
  {
    public:
      kinematics_msgs::PositionIKRequest ik_request;
      arm_navigation_msgs::Constraints constraints;
      ros::Duration timeout;

    GetConstraintAwarePositionIKRequest():
      ik_request(),
      constraints(),
      timeout()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->ik_request.serialize(outbuffer + offset);
      offset += this->constraints.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->timeout.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.sec);
      *(outbuffer + offset + 0) = (this->timeout.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timeout.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timeout.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timeout.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->ik_request.deserialize(inbuffer + offset);
      offset += this->constraints.deserialize(inbuffer + offset);
      this->timeout.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.sec);
      this->timeout.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timeout.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timeout.nsec);
     return offset;
    }

    const char * getType(){ return GETCONSTRAINTAWAREPOSITIONIK; };
    const char * getMD5(){ return "3772a29c71f9b0627ec5c37e3ab80920"; };

  };

  class GetConstraintAwarePositionIKResponse : public ros::Msg
  {
    public:
      arm_navigation_msgs::RobotState solution;
      arm_navigation_msgs::ArmNavigationErrorCodes error_code;

    GetConstraintAwarePositionIKResponse():
      solution(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->solution.serialize(outbuffer + offset);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->solution.deserialize(inbuffer + offset);
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETCONSTRAINTAWAREPOSITIONIK; };
    const char * getMD5(){ return "5a8bbc4eb2775fe00cbd09858fd3dc65"; };

  };

  class GetConstraintAwarePositionIK {
    public:
    typedef GetConstraintAwarePositionIKRequest Request;
    typedef GetConstraintAwarePositionIKResponse Response;
  };

}
#endif
