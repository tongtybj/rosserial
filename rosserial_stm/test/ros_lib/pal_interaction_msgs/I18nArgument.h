#ifndef _ROS_pal_interaction_msgs_I18nArgument_h
#define _ROS_pal_interaction_msgs_I18nArgument_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class I18nArgument : public ros::Msg
  {
    public:
      const char* section;
      const char* key;
      const char* expanded;

    I18nArgument():
      section(""),
      key(""),
      expanded("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_section = strlen(this->section);
      memcpy(outbuffer + offset, &length_section, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->section, length_section);
      offset += length_section;
      uint32_t length_key = strlen(this->key);
      memcpy(outbuffer + offset, &length_key, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->key, length_key);
      offset += length_key;
      uint32_t length_expanded = strlen(this->expanded);
      memcpy(outbuffer + offset, &length_expanded, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->expanded, length_expanded);
      offset += length_expanded;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_section;
      memcpy(&length_section, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_section; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_section-1]=0;
      this->section = (char *)(inbuffer + offset-1);
      offset += length_section;
      uint32_t length_key;
      memcpy(&length_key, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key-1]=0;
      this->key = (char *)(inbuffer + offset-1);
      offset += length_key;
      uint32_t length_expanded;
      memcpy(&length_expanded, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_expanded; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_expanded-1]=0;
      this->expanded = (char *)(inbuffer + offset-1);
      offset += length_expanded;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/I18nArgument"; };
    const char * getMD5(){ return "5c584e5b757794e1616ca51692089746"; };

  };

}
#endif