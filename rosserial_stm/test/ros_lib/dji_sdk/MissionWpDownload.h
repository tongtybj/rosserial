#ifndef _ROS_SERVICE_MissionWpDownload_h
#define _ROS_SERVICE_MissionWpDownload_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dji_sdk/MissionWaypointTask.h"

namespace dji_sdk
{

static const char MISSIONWPDOWNLOAD[] = "dji_sdk/MissionWpDownload";

  class MissionWpDownloadRequest : public ros::Msg
  {
    public:

    MissionWpDownloadRequest()
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

    const char * getType(){ return MISSIONWPDOWNLOAD; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class MissionWpDownloadResponse : public ros::Msg
  {
    public:
      dji_sdk::MissionWaypointTask waypoint_task;

    MissionWpDownloadResponse():
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

    const char * getType(){ return MISSIONWPDOWNLOAD; };
    const char * getMD5(){ return "7c965e82a72d204e1e6d1e75389efb89"; };

  };

  class MissionWpDownload {
    public:
    typedef MissionWpDownloadRequest Request;
    typedef MissionWpDownloadResponse Response;
  };

}
#endif
