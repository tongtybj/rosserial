#ifndef _ROS_speech_recognition_msgs_SpeechRecognitionCandidates_h
#define _ROS_speech_recognition_msgs_SpeechRecognitionCandidates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace speech_recognition_msgs
{

  class SpeechRecognitionCandidates : public ros::Msg
  {
    public:
      uint8_t transcript_length;
      char* st_transcript;
      char* * transcript;
      uint8_t confidence_length;
      float st_confidence;
      float * confidence;

    SpeechRecognitionCandidates():
      transcript_length(0), transcript(NULL),
      confidence_length(0), confidence(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = transcript_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < transcript_length; i++){
      uint32_t length_transcripti = strlen(this->transcript[i]);
      memcpy(outbuffer + offset, &length_transcripti, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->transcript[i], length_transcripti);
      offset += length_transcripti;
      }
      *(outbuffer + offset++) = confidence_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < confidence_length; i++){
      union {
        float real;
        uint32_t base;
      } u_confidencei;
      u_confidencei.real = this->confidence[i];
      *(outbuffer + offset + 0) = (u_confidencei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidencei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidencei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidencei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t transcript_lengthT = *(inbuffer + offset++);
      if(transcript_lengthT > transcript_length)
        this->transcript = (char**)realloc(this->transcript, transcript_lengthT * sizeof(char*));
      offset += 3;
      transcript_length = transcript_lengthT;
      for( uint8_t i = 0; i < transcript_length; i++){
      uint32_t length_st_transcript;
      memcpy(&length_st_transcript, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_transcript; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_transcript-1]=0;
      this->st_transcript = (char *)(inbuffer + offset-1);
      offset += length_st_transcript;
        memcpy( &(this->transcript[i]), &(this->st_transcript), sizeof(char*));
      }
      uint8_t confidence_lengthT = *(inbuffer + offset++);
      if(confidence_lengthT > confidence_length)
        this->confidence = (float*)realloc(this->confidence, confidence_lengthT * sizeof(float));
      offset += 3;
      confidence_length = confidence_lengthT;
      for( uint8_t i = 0; i < confidence_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_confidence;
      u_st_confidence.base = 0;
      u_st_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_confidence = u_st_confidence.real;
      offset += sizeof(this->st_confidence);
        memcpy( &(this->confidence[i]), &(this->st_confidence), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "speech_recognition_msgs/SpeechRecognitionCandidates"; };
    const char * getMD5(){ return "8bf91ae2b1d4cbc38dce17013599f915"; };

  };

}
#endif