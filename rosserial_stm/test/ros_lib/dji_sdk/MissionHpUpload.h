#ifndef _ROS_SERVICE_MissionHpUpload_h
#define _ROS_SERVICE_MissionHpUpload_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/MissionHotpointTask.h"

namespace dji_sdk
{

static const char MISSIONHPUPLOAD[] = "dji_sdk/MissionHpUpload";

  class MissionHpUploadRequest : public ros::Msg
  {
    public:
      dji_sdk::MissionHotpointTask hotpoint_task;

    MissionHpUploadRequest():
      hotpoint_task()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->hotpoint_task.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->hotpoint_task.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MISSIONHPUPLOAD; };
    const char * getMD5(){ return "e36e66ca170c4d03ee023ad56c6bb5a0"; };

  };

  class MissionHpUploadResponse : public ros::Msg
  {
    public:
      bool result;

    MissionHpUploadResponse():
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

    const char * getType(){ return MISSIONHPUPLOAD; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class MissionHpUpload {
    public:
    typedef MissionHpUploadRequest Request;
    typedef MissionHpUploadResponse Response;
  };

}
#endif
