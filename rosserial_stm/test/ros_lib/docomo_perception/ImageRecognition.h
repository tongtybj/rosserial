#ifndef _ROS_SERVICE_ImageRecognition_h
#define _ROS_SERVICE_ImageRecognition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "docomo_perception/ImageRecognitionCandidate.h"

namespace docomo_perception
{

static const char IMAGERECOGNITION[] = "docomo_perception/ImageRecognition";

  class ImageRecognitionRequest : public ros::Msg
  {
    public:
      uint8_t type;
      sensor_msgs::Image image;
      uint16_t numOfCandidates;
      enum { ALL = 0 };
      enum { BOOK = 1 };
      enum { CD = 2 };
      enum { DVD = 3 };
      enum { GAME = 4 };
      enum { SOFTWARE = 5 };
      enum { FOOD = 6 };

    ImageRecognitionRequest():
      type(0),
      image(),
      numOfCandidates(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      offset += this->image.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->numOfCandidates >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->numOfCandidates >> (8 * 1)) & 0xFF;
      offset += sizeof(this->numOfCandidates);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      offset += this->image.deserialize(inbuffer + offset);
      this->numOfCandidates =  ((uint16_t) (*(inbuffer + offset)));
      this->numOfCandidates |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->numOfCandidates);
     return offset;
    }

    const char * getType(){ return IMAGERECOGNITION; };
    const char * getMD5(){ return "b8b7c3ad04b2d8121330a18e0d831730"; };

  };

  class ImageRecognitionResponse : public ros::Msg
  {
    public:
      uint8_t candidates_length;
      docomo_perception::ImageRecognitionCandidate st_candidates;
      docomo_perception::ImageRecognitionCandidate * candidates;

    ImageRecognitionResponse():
      candidates_length(0), candidates(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = candidates_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < candidates_length; i++){
      offset += this->candidates[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t candidates_lengthT = *(inbuffer + offset++);
      if(candidates_lengthT > candidates_length)
        this->candidates = (docomo_perception::ImageRecognitionCandidate*)realloc(this->candidates, candidates_lengthT * sizeof(docomo_perception::ImageRecognitionCandidate));
      offset += 3;
      candidates_length = candidates_lengthT;
      for( uint8_t i = 0; i < candidates_length; i++){
      offset += this->st_candidates.deserialize(inbuffer + offset);
        memcpy( &(this->candidates[i]), &(this->st_candidates), sizeof(docomo_perception::ImageRecognitionCandidate));
      }
     return offset;
    }

    const char * getType(){ return IMAGERECOGNITION; };
    const char * getMD5(){ return "3e1066ece8a34b267d9c3ea4ec5849a3"; };

  };

  class ImageRecognition {
    public:
    typedef ImageRecognitionRequest Request;
    typedef ImageRecognitionResponse Response;
  };

}
#endif
