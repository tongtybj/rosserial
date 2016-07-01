#ifndef _ROS_SERVICE_OpenHRP_ForwardKinematicsService_selectBaseLink_h
#define _ROS_SERVICE_OpenHRP_ForwardKinematicsService_selectBaseLink_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_FORWARDKINEMATICSSERVICE_SELECTBASELINK[] = "hrpsys_ros_bridge/OpenHRP_ForwardKinematicsService_selectBaseLink";

  class OpenHRP_ForwardKinematicsService_selectBaseLinkRequest : public ros::Msg
  {
    public:
      const char* linkname;

    OpenHRP_ForwardKinematicsService_selectBaseLinkRequest():
      linkname("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_linkname = strlen(this->linkname);
      memcpy(outbuffer + offset, &length_linkname, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->linkname, length_linkname);
      offset += length_linkname;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_linkname;
      memcpy(&length_linkname, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_linkname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_linkname-1]=0;
      this->linkname = (char *)(inbuffer + offset-1);
      offset += length_linkname;
     return offset;
    }

    const char * getType(){ return OPENHRP_FORWARDKINEMATICSSERVICE_SELECTBASELINK; };
    const char * getMD5(){ return "7213c5067047d83d5fa0345c656d2dd8"; };

  };

  class OpenHRP_ForwardKinematicsService_selectBaseLinkResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_ForwardKinematicsService_selectBaseLinkResponse():
      operation_return(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_FORWARDKINEMATICSSERVICE_SELECTBASELINK; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ForwardKinematicsService_selectBaseLink {
    public:
    typedef OpenHRP_ForwardKinematicsService_selectBaseLinkRequest Request;
    typedef OpenHRP_ForwardKinematicsService_selectBaseLinkResponse Response;
  };

}
#endif
