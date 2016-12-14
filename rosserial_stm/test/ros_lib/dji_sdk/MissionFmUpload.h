#ifndef _ROS_SERVICE_MissionFmUpload_h
#define _ROS_SERVICE_MissionFmUpload_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/MissionFollowmeTask.h"

namespace dji_sdk
{

static const char MISSIONFMUPLOAD[] = "dji_sdk/MissionFmUpload";

  class MissionFmUploadRequest : public ros::Msg
  {
    public:
      dji_sdk::MissionFollowmeTask followme_task;

    MissionFmUploadRequest():
      followme_task()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->followme_task.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->followme_task.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MISSIONFMUPLOAD; };
    const char * getMD5(){ return "9cd25f0a53a1d10e6538dd9fb391a7e8"; };

  };

  class MissionFmUploadResponse : public ros::Msg
  {
    public:
      bool result;

    MissionFmUploadResponse():
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

    const char * getType(){ return MISSIONFMUPLOAD; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class MissionFmUpload {
    public:
    typedef MissionFmUploadRequest Request;
    typedef MissionFmUploadResponse Response;
  };

}
#endif
