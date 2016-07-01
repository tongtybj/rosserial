#ifndef _ROS_SERVICE_OpenHRP_OGMap3DService_getOGMap3D_h
#define _ROS_SERVICE_OpenHRP_OGMap3DService_getOGMap3D_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AABB.h"
#include "hrpsys_ros_bridge/OpenHRP_OGMap3D.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_OGMAP3DSERVICE_GETOGMAP3D[] = "hrpsys_ros_bridge/OpenHRP_OGMap3DService_getOGMap3D";

  class OpenHRP_OGMap3DService_getOGMap3DRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_AABB region;

    OpenHRP_OGMap3DService_getOGMap3DRequest():
      region()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->region.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->region.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_OGMAP3DSERVICE_GETOGMAP3D; };
    const char * getMD5(){ return "f59aa95d79e40df8d8a9abf1e22d652d"; };

  };

  class OpenHRP_OGMap3DService_getOGMap3DResponse : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_OGMap3D operation_return;

    OpenHRP_OGMap3DService_getOGMap3DResponse():
      operation_return()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->operation_return.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->operation_return.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_OGMAP3DSERVICE_GETOGMAP3D; };
    const char * getMD5(){ return "932b88704a6c2baaf995d456aed16aae"; };

  };

  class OpenHRP_OGMap3DService_getOGMap3D {
    public:
    typedef OpenHRP_OGMap3DService_getOGMap3DRequest Request;
    typedef OpenHRP_OGMap3DService_getOGMap3DResponse Response;
  };

}
#endif
