#ifndef _ROS_SERVICE_TextToSpeechService_h
#define _ROS_SERVICE_TextToSpeechService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "docomo_perception/TextToSpeech.h"

namespace docomo_perception
{

static const char TEXTTOSPEECHSERVICE[] = "docomo_perception/TextToSpeechService";

  class TextToSpeechServiceRequest : public ros::Msg
  {
    public:
      docomo_perception::TextToSpeech speech;

    TextToSpeechServiceRequest():
      speech()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->speech.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->speech.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return TEXTTOSPEECHSERVICE; };
    const char * getMD5(){ return "7ff9763714fee9fd01080423325a7405"; };

  };

  class TextToSpeechServiceResponse : public ros::Msg
  {
    public:

    TextToSpeechServiceResponse()
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

    const char * getType(){ return TEXTTOSPEECHSERVICE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class TextToSpeechService {
    public:
    typedef TextToSpeechServiceRequest Request;
    typedef TextToSpeechServiceResponse Response;
  };

}
#endif
