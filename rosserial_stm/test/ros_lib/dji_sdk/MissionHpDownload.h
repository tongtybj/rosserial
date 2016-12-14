#ifndef _ROS_SERVICE_MissionHpDownload_h
#define _ROS_SERVICE_MissionHpDownload_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/MissionHotpointTask.h"

namespace dji_sdk
{

static const char MISSIONHPDOWNLOAD[] = "dji_sdk/MissionHpDownload";

  class MissionHpDownloadRequest : public ros::Msg
  {
    public:

    MissionHpDownloadRequest()
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

    const char * getType(){ return MISSIONHPDOWNLOAD; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class MissionHpDownloadResponse : public ros::Msg
  {
    public:
      dji_sdk::MissionHotpointTask hotpoint_task;

    MissionHpDownloadResponse():
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

    const char * getType(){ return MISSIONHPDOWNLOAD; };
    const char * getMD5(){ return "e36e66ca170c4d03ee023ad56c6bb5a0"; };

  };

  class MissionHpDownload {
    public:
    typedef MissionHpDownloadRequest Request;
    typedef MissionHpDownloadResponse Response;
  };

}
#endif
