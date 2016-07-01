#ifndef _ROS_docomo_perception_ImageRecognitionCandidate_h
#define _ROS_docomo_perception_ImageRecognitionCandidate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace docomo_perception
{

  class ImageRecognitionCandidate : public ros::Msg
  {
    public:
      float score;
      const char* category;
      const char* itemName;
      const char* imageUrl;

    ImageRecognitionCandidate():
      score(0),
      category(""),
      itemName(""),
      imageUrl("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_score;
      u_score.real = this->score;
      *(outbuffer + offset + 0) = (u_score.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_score.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_score.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_score.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->score);
      uint32_t length_category = strlen(this->category);
      memcpy(outbuffer + offset, &length_category, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->category, length_category);
      offset += length_category;
      uint32_t length_itemName = strlen(this->itemName);
      memcpy(outbuffer + offset, &length_itemName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->itemName, length_itemName);
      offset += length_itemName;
      uint32_t length_imageUrl = strlen(this->imageUrl);
      memcpy(outbuffer + offset, &length_imageUrl, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->imageUrl, length_imageUrl);
      offset += length_imageUrl;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_score;
      u_score.base = 0;
      u_score.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_score.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_score.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_score.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->score = u_score.real;
      offset += sizeof(this->score);
      uint32_t length_category;
      memcpy(&length_category, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_category; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_category-1]=0;
      this->category = (char *)(inbuffer + offset-1);
      offset += length_category;
      uint32_t length_itemName;
      memcpy(&length_itemName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_itemName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_itemName-1]=0;
      this->itemName = (char *)(inbuffer + offset-1);
      offset += length_itemName;
      uint32_t length_imageUrl;
      memcpy(&length_imageUrl, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_imageUrl; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_imageUrl-1]=0;
      this->imageUrl = (char *)(inbuffer + offset-1);
      offset += length_imageUrl;
     return offset;
    }

    const char * getType(){ return "docomo_perception/ImageRecognitionCandidate"; };
    const char * getMD5(){ return "fcb8bb19df6a0b4fae82e454898b2188"; };

  };

}
#endif