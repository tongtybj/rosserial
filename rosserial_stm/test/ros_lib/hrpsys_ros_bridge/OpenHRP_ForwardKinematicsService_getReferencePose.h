#ifndef _ROS_SERVICE_OpenHRP_ForwardKinematicsService_getReferencePose_h
#define _ROS_SERVICE_OpenHRP_ForwardKinematicsService_getReferencePose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/RTC_TimedDoubleSeq.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_FORWARDKINEMATICSSERVICE_GETREFERENCEPOSE[] = "hrpsys_ros_bridge/OpenHRP_ForwardKinematicsService_getReferencePose";

  class OpenHRP_ForwardKinematicsService_getReferencePoseRequest : public ros::Msg
  {
    public:
      const char* linkname;

    OpenHRP_ForwardKinematicsService_getReferencePoseRequest():
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

    const char * getType(){ return OPENHRP_FORWARDKINEMATICSSERVICE_GETREFERENCEPOSE; };
    const char * getMD5(){ return "7213c5067047d83d5fa0345c656d2dd8"; };

  };

  class OpenHRP_ForwardKinematicsService_getReferencePoseResponse : public ros::Msg
  {
    public:
      bool operation_return;
      hrpsys_ros_bridge::RTC_TimedDoubleSeq pose;

    OpenHRP_ForwardKinematicsService_getReferencePoseResponse():
      operation_return(0),
      pose()
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
      offset += this->pose.serialize(outbuffer + offset);
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
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_FORWARDKINEMATICSSERVICE_GETREFERENCEPOSE; };
    const char * getMD5(){ return "2cd858035ca2d85ca617a7702e7d64b8"; };

  };

  class OpenHRP_ForwardKinematicsService_getReferencePose {
    public:
    typedef OpenHRP_ForwardKinematicsService_getReferencePoseRequest Request;
    typedef OpenHRP_ForwardKinematicsService_getReferencePoseResponse Response;
  };

}
#endif
