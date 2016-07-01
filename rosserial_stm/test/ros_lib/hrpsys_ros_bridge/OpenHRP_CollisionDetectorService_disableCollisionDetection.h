#ifndef _ROS_SERVICE_OpenHRP_CollisionDetectorService_disableCollisionDetection_h
#define _ROS_SERVICE_OpenHRP_CollisionDetectorService_disableCollisionDetection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_COLLISIONDETECTORSERVICE_DISABLECOLLISIONDETECTION[] = "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_disableCollisionDetection";

  class OpenHRP_CollisionDetectorService_disableCollisionDetectionRequest : public ros::Msg
  {
    public:

    OpenHRP_CollisionDetectorService_disableCollisionDetectionRequest()
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

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_DISABLECOLLISIONDETECTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_CollisionDetectorService_disableCollisionDetectionResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_CollisionDetectorService_disableCollisionDetectionResponse():
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

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_DISABLECOLLISIONDETECTION; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_CollisionDetectorService_disableCollisionDetection {
    public:
    typedef OpenHRP_CollisionDetectorService_disableCollisionDetectionRequest Request;
    typedef OpenHRP_CollisionDetectorService_disableCollisionDetectionResponse Response;
  };

}
#endif
