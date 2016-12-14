#ifndef _ROS_SERVICE_Knowledge_h
#define _ROS_SERVICE_Knowledge_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace docomo_perception
{

static const char KNOWLEDGE[] = "docomo_perception/Knowledge";

  class KnowledgeRequest : public ros::Msg
  {
    public:
      const char* question;

    KnowledgeRequest():
      question("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_question = strlen(this->question);
      memcpy(outbuffer + offset, &length_question, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->question, length_question);
      offset += length_question;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_question;
      memcpy(&length_question, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_question; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_question-1]=0;
      this->question = (char *)(inbuffer + offset-1);
      offset += length_question;
     return offset;
    }

    const char * getType(){ return KNOWLEDGE; };
    const char * getMD5(){ return "6f5ee90c3217a43e2ffb310aba8cde74"; };

  };

  class KnowledgeResponse : public ros::Msg
  {
    public:
      const char* answer;
      const char* answerForSpeech;

    KnowledgeResponse():
      answer(""),
      answerForSpeech("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_answer = strlen(this->answer);
      memcpy(outbuffer + offset, &length_answer, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->answer, length_answer);
      offset += length_answer;
      uint32_t length_answerForSpeech = strlen(this->answerForSpeech);
      memcpy(outbuffer + offset, &length_answerForSpeech, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->answerForSpeech, length_answerForSpeech);
      offset += length_answerForSpeech;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_answer;
      memcpy(&length_answer, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_answer; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_answer-1]=0;
      this->answer = (char *)(inbuffer + offset-1);
      offset += length_answer;
      uint32_t length_answerForSpeech;
      memcpy(&length_answerForSpeech, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_answerForSpeech; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_answerForSpeech-1]=0;
      this->answerForSpeech = (char *)(inbuffer + offset-1);
      offset += length_answerForSpeech;
     return offset;
    }

    const char * getType(){ return KNOWLEDGE; };
    const char * getMD5(){ return "e003db823ad2737f35e5510c790a607d"; };

  };

  class Knowledge {
    public:
    typedef KnowledgeRequest Request;
    typedef KnowledgeResponse Response;
  };

}
#endif
