#ifndef _ROS_SERVICE_SentenseUnderstanding_h
#define _ROS_SERVICE_SentenseUnderstanding_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace docomo_perception
{

static const char SENTENSEUNDERSTANDING[] = "docomo_perception/SentenseUnderstanding";

  class SentenseUnderstandingRequest : public ros::Msg
  {
    public:
      const char* text;

    SentenseUnderstandingRequest():
      text("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_text = strlen(this->text);
      memcpy(outbuffer + offset, &length_text, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_text;
      memcpy(&length_text, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
     return offset;
    }

    const char * getType(){ return SENTENSEUNDERSTANDING; };
    const char * getMD5(){ return "74697ed3d931f6eede8bf3a8dfeca160"; };

  };

  class SentenseUnderstandingResponse : public ros::Msg
  {
    public:
      const char* revisedText;
      uint8_t words_length;
      char* st_words;
      char* * words;
      const char* command;
      uint8_t args_length;
      char* st_args;
      char* * args;
      uint8_t extractedWords_length;
      char* st_extractedWords;
      char* * extractedWords;

    SentenseUnderstandingResponse():
      revisedText(""),
      words_length(0), words(NULL),
      command(""),
      args_length(0), args(NULL),
      extractedWords_length(0), extractedWords(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_revisedText = strlen(this->revisedText);
      memcpy(outbuffer + offset, &length_revisedText, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->revisedText, length_revisedText);
      offset += length_revisedText;
      *(outbuffer + offset++) = words_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < words_length; i++){
      uint32_t length_wordsi = strlen(this->words[i]);
      memcpy(outbuffer + offset, &length_wordsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->words[i], length_wordsi);
      offset += length_wordsi;
      }
      uint32_t length_command = strlen(this->command);
      memcpy(outbuffer + offset, &length_command, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->command, length_command);
      offset += length_command;
      *(outbuffer + offset++) = args_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < args_length; i++){
      uint32_t length_argsi = strlen(this->args[i]);
      memcpy(outbuffer + offset, &length_argsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->args[i], length_argsi);
      offset += length_argsi;
      }
      *(outbuffer + offset++) = extractedWords_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < extractedWords_length; i++){
      uint32_t length_extractedWordsi = strlen(this->extractedWords[i]);
      memcpy(outbuffer + offset, &length_extractedWordsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->extractedWords[i], length_extractedWordsi);
      offset += length_extractedWordsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_revisedText;
      memcpy(&length_revisedText, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_revisedText; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_revisedText-1]=0;
      this->revisedText = (char *)(inbuffer + offset-1);
      offset += length_revisedText;
      uint8_t words_lengthT = *(inbuffer + offset++);
      if(words_lengthT > words_length)
        this->words = (char**)realloc(this->words, words_lengthT * sizeof(char*));
      offset += 3;
      words_length = words_lengthT;
      for( uint8_t i = 0; i < words_length; i++){
      uint32_t length_st_words;
      memcpy(&length_st_words, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_words; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_words-1]=0;
      this->st_words = (char *)(inbuffer + offset-1);
      offset += length_st_words;
        memcpy( &(this->words[i]), &(this->st_words), sizeof(char*));
      }
      uint32_t length_command;
      memcpy(&length_command, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
      uint8_t args_lengthT = *(inbuffer + offset++);
      if(args_lengthT > args_length)
        this->args = (char**)realloc(this->args, args_lengthT * sizeof(char*));
      offset += 3;
      args_length = args_lengthT;
      for( uint8_t i = 0; i < args_length; i++){
      uint32_t length_st_args;
      memcpy(&length_st_args, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_args; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_args-1]=0;
      this->st_args = (char *)(inbuffer + offset-1);
      offset += length_st_args;
        memcpy( &(this->args[i]), &(this->st_args), sizeof(char*));
      }
      uint8_t extractedWords_lengthT = *(inbuffer + offset++);
      if(extractedWords_lengthT > extractedWords_length)
        this->extractedWords = (char**)realloc(this->extractedWords, extractedWords_lengthT * sizeof(char*));
      offset += 3;
      extractedWords_length = extractedWords_lengthT;
      for( uint8_t i = 0; i < extractedWords_length; i++){
      uint32_t length_st_extractedWords;
      memcpy(&length_st_extractedWords, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_extractedWords; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_extractedWords-1]=0;
      this->st_extractedWords = (char *)(inbuffer + offset-1);
      offset += length_st_extractedWords;
        memcpy( &(this->extractedWords[i]), &(this->st_extractedWords), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return SENTENSEUNDERSTANDING; };
    const char * getMD5(){ return "8fd1e96b0f0897aec9ceeecdd14978ea"; };

  };

  class SentenseUnderstanding {
    public:
    typedef SentenseUnderstandingRequest Request;
    typedef SentenseUnderstandingResponse Response;
  };

}
#endif
