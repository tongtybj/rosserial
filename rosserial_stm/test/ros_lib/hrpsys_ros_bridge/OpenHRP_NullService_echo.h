#ifndef _ROS_SERVICE_OpenHRP_NullService_echo_h
#define _ROS_SERVICE_OpenHRP_NullService_echo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_NULLSERVICE_ECHO[] = "hrpsys_ros_bridge/OpenHRP_NullService_echo";

  class OpenHRP_NullService_echoRequest : public ros::Msg
  {
    public:
      const char* msg;

    OpenHRP_NullService_echoRequest():
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_msg = strlen(this->msg);
      memcpy(outbuffer + offset, &length_msg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_msg;
      memcpy(&length_msg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return OPENHRP_NULLSERVICE_ECHO; };
    const char * getMD5(){ return "7d96ed730776804754140b85e64c862e"; };

  };

  class OpenHRP_NullService_echoResponse : public ros::Msg
  {
    public:

    OpenHRP_NullService_echoResponse()
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

    const char * getType(){ return OPENHRP_NULLSERVICE_ECHO; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_NullService_echo {
    public:
    typedef OpenHRP_NullService_echoRequest Request;
    typedef OpenHRP_NullService_echoResponse Response;
  };

}
#endif
