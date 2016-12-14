#ifndef _ROS_SERVICE_MissionWpUpload_h
#define _ROS_SERVICE_MissionWpUpload_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/MissionWaypointTask.h"

namespace dji_sdk
{

static const char MISSIONWPUPLOAD[] = "dji_sdk/MissionWpUpload";

  class MissionWpUploadRequest : public ros::Msg
  {
    public:
      dji_sdk::MissionWaypointTask waypoint_task;

    MissionWpUploadRequest():
      waypoint_task()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->waypoint_task.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->waypoint_task.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return MISSIONWPUPLOAD; };
    const char * getMD5(){ return "7c965e82a72d204e1e6d1e75389efb89"; };

  };

  class MissionWpUploadResponse : public ros::Msg
  {
    public:
      bool result;

    MissionWpUploadResponse():
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

    const char * getType(){ return MISSIONWPUPLOAD; };
    const char * getMD5(){ return "eb13ac1f1354ccecb7941ee8fa2192e8"; };

  };

  class MissionWpUpload {
    public:
    typedef MissionWpUploadRequest Request;
    typedef MissionWpUploadResponse Response;
  };

}
#endif
