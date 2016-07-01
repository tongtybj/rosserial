#ifndef _ROS_SERVICE_OpenHRP_TorqueFilterService_dummy_h
#define _ROS_SERVICE_OpenHRP_TorqueFilterService_dummy_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_TORQUEFILTERSERVICE_DUMMY[] = "hrpsys_ros_bridge/OpenHRP_TorqueFilterService_dummy";

  class OpenHRP_TorqueFilterService_dummyRequest : public ros::Msg
  {
    public:
      const char* msg;

    OpenHRP_TorqueFilterService_dummyRequest():
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

    const char * getType(){ return OPENHRP_TORQUEFILTERSERVICE_DUMMY; };
    const char * getMD5(){ return "7d96ed730776804754140b85e64c862e"; };

  };

  class OpenHRP_TorqueFilterService_dummyResponse : public ros::Msg
  {
    public:

    OpenHRP_TorqueFilterService_dummyResponse()
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

    const char * getType(){ return OPENHRP_TORQUEFILTERSERVICE_DUMMY; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_TorqueFilterService_dummy {
    public:
    typedef OpenHRP_TorqueFilterService_dummyRequest Request;
    typedef OpenHRP_TorqueFilterService_dummyResponse Response;
  };

}
#endif
