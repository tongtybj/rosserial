#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setMaxIKIteration_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setMaxIKIteration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKITERATION[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setMaxIKIteration";

  class OpenHRP_SequencePlayerService_setMaxIKIterationRequest : public ros::Msg
  {
    public:
      int16_t max_iteration;

    OpenHRP_SequencePlayerService_setMaxIKIterationRequest():
      max_iteration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_max_iteration;
      u_max_iteration.real = this->max_iteration;
      *(outbuffer + offset + 0) = (u_max_iteration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_iteration.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->max_iteration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_max_iteration;
      u_max_iteration.base = 0;
      u_max_iteration.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_iteration.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_iteration = u_max_iteration.real;
      offset += sizeof(this->max_iteration);
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKITERATION; };
    const char * getMD5(){ return "3c2cc5038ed4a8361abaa66282d47ea2"; };

  };

  class OpenHRP_SequencePlayerService_setMaxIKIterationResponse : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_setMaxIKIterationResponse()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKITERATION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_setMaxIKIteration {
    public:
    typedef OpenHRP_SequencePlayerService_setMaxIKIterationRequest Request;
    typedef OpenHRP_SequencePlayerService_setMaxIKIterationResponse Response;
  };

}
#endif
