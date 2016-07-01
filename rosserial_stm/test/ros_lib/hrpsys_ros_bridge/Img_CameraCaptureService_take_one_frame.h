#ifndef _ROS_SERVICE_Img_CameraCaptureService_take_one_frame_h
#define _ROS_SERVICE_Img_CameraCaptureService_take_one_frame_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char IMG_CAMERACAPTURESERVICE_TAKE_ONE_FRAME[] = "hrpsys_ros_bridge/Img_CameraCaptureService_take_one_frame";

  class Img_CameraCaptureService_take_one_frameRequest : public ros::Msg
  {
    public:

    Img_CameraCaptureService_take_one_frameRequest()
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

    const char * getType(){ return IMG_CAMERACAPTURESERVICE_TAKE_ONE_FRAME; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Img_CameraCaptureService_take_one_frameResponse : public ros::Msg
  {
    public:

    Img_CameraCaptureService_take_one_frameResponse()
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

    const char * getType(){ return IMG_CAMERACAPTURESERVICE_TAKE_ONE_FRAME; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class Img_CameraCaptureService_take_one_frame {
    public:
    typedef Img_CameraCaptureService_take_one_frameRequest Request;
    typedef Img_CameraCaptureService_take_one_frameResponse Response;
  };

}
#endif
