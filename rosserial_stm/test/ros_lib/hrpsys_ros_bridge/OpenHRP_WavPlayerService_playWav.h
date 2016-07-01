#ifndef _ROS_SERVICE_OpenHRP_WavPlayerService_playWav_h
#define _ROS_SERVICE_OpenHRP_WavPlayerService_playWav_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_WAVPLAYERSERVICE_PLAYWAV[] = "hrpsys_ros_bridge/OpenHRP_WavPlayerService_playWav";

  class OpenHRP_WavPlayerService_playWavRequest : public ros::Msg
  {
    public:
      const char* wavfile;

    OpenHRP_WavPlayerService_playWavRequest():
      wavfile("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_wavfile = strlen(this->wavfile);
      memcpy(outbuffer + offset, &length_wavfile, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->wavfile, length_wavfile);
      offset += length_wavfile;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_wavfile;
      memcpy(&length_wavfile, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_wavfile; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_wavfile-1]=0;
      this->wavfile = (char *)(inbuffer + offset-1);
      offset += length_wavfile;
     return offset;
    }

    const char * getType(){ return OPENHRP_WAVPLAYERSERVICE_PLAYWAV; };
    const char * getMD5(){ return "3c03a46ac8d83fddf8339342640a60df"; };

  };

  class OpenHRP_WavPlayerService_playWavResponse : public ros::Msg
  {
    public:

    OpenHRP_WavPlayerService_playWavResponse()
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

    const char * getType(){ return OPENHRP_WAVPLAYERSERVICE_PLAYWAV; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_WavPlayerService_playWav {
    public:
    typedef OpenHRP_WavPlayerService_playWavRequest Request;
    typedef OpenHRP_WavPlayerService_playWavResponse Response;
  };

}
#endif
