#ifndef _ROS_SERVICE_Img_CameraCaptureService_start_continuous_h
#define _ROS_SERVICE_Img_CameraCaptureService_start_continuous_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char IMG_CAMERACAPTURESERVICE_START_CONTINUOUS[] = "hrpsys_ros_bridge/Img_CameraCaptureService_start_continuous";

  class Img_CameraCaptureService_start_continuousRequest : public ros::Msg
  {
    public:

    Img_CameraCaptureService_start_continuousRequest()
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

    const char * getType(){ return IMG_CAMERACAPTURESERVICE_START_CONTINUOUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Img_CameraCaptureService_start_continuousResponse : public ros::Msg
  {
    public:

    Img_CameraCaptureService_start_continuousResponse()
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

    const char * getType(){ return IMG_CAMERACAPTURESERVICE_START_CONTINUOUS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Img_CameraCaptureService_start_continuous {
    public:
    typedef Img_CameraCaptureService_start_continuousRequest Request;
    typedef Img_CameraCaptureService_start_continuousResponse Response;
  };

}
#endif
