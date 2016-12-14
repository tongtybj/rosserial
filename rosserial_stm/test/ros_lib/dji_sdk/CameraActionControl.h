#ifndef _ROS_SERVICE_CameraActionControl_h
#define _ROS_SERVICE_CameraActionControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

static const char CAMERAACTIONCONTROL[] = "dji_sdk/CameraActionControl";

  class CameraActionControlRequest : public ros::Msg
  {
    public:
      uint8_t camera_action;

    CameraActionControlRequest():
      camera_action(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->camera_action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->camera_action);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->camera_action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->camera_action);
     return offset;
    }

    const char * getType(){ return CAMERAACTIONCONTROL; };
    const char * getMD5(){ return "a4ed1822b47772deebd56bdca0095874"; };

  };

  class CameraActionControlResponse : public ros::Msg
  {
    public:
      bool result;

    CameraActionControlResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return CAMERAACTIONCONTROL; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class CameraActionControl {
    public:
    typedef CameraActionControlRequest Request;
    typedef CameraActionControlResponse Response;
  };

}
#endif
