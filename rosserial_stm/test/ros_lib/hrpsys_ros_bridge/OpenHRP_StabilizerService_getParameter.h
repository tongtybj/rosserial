#ifndef _ROS_SERVICE_OpenHRP_StabilizerService_getParameter_h
#define _ROS_SERVICE_OpenHRP_StabilizerService_getParameter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_stParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_STABILIZERSERVICE_GETPARAMETER[] = "hrpsys_ros_bridge/OpenHRP_StabilizerService_getParameter";

  class OpenHRP_StabilizerService_getParameterRequest : public ros::Msg
  {
    public:

    OpenHRP_StabilizerService_getParameterRequest()
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

    const char * getType(){ return OPENHRP_STABILIZERSERVICE_GETPARAMETER; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_StabilizerService_getParameterResponse : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_StabilizerService_stParam i_param;

    OpenHRP_StabilizerService_getParameterResponse():
      i_param()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->i_param.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_STABILIZERSERVICE_GETPARAMETER; };
    const char * getMD5(){ return "0c562f17b742292c8667c61957ccea2f"; };

  };

  class OpenHRP_StabilizerService_getParameter {
    public:
    typedef OpenHRP_StabilizerService_getParameterRequest Request;
    typedef OpenHRP_StabilizerService_getParameterResponse Response;
  };

}
#endif
