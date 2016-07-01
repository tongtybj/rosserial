#ifndef _ROS_SERVICE_OpenHRP_CollisionDetectorService_getCollisionStatus_h
#define _ROS_SERVICE_OpenHRP_CollisionDetectorService_getCollisionStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_CollisionState.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_COLLISIONDETECTORSERVICE_GETCOLLISIONSTATUS[] = "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_getCollisionStatus";

  class OpenHRP_CollisionDetectorService_getCollisionStatusRequest : public ros::Msg
  {
    public:

    OpenHRP_CollisionDetectorService_getCollisionStatusRequest()
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

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_GETCOLLISIONSTATUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_CollisionDetectorService_getCollisionStatusResponse : public ros::Msg
  {
    public:
      bool operation_return;
      hrpsys_ros_bridge::OpenHRP_CollisionDetectorService_CollisionState cs;

    OpenHRP_CollisionDetectorService_getCollisionStatusResponse():
      operation_return(0),
      cs()
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
      offset += this->cs.serialize(outbuffer + offset);
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
      offset += this->cs.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_GETCOLLISIONSTATUS; };
    const char * getMD5(){ return "a384cba0dd381cb80953ac481633ba97"; };

  };

  class OpenHRP_CollisionDetectorService_getCollisionStatus {
    public:
    typedef OpenHRP_CollisionDetectorService_getCollisionStatusRequest Request;
    typedef OpenHRP_CollisionDetectorService_getCollisionStatusResponse Response;
  };

}
#endif
