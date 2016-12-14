#ifndef _ROS_pal_interaction_msgs_I18nText_h
#define _ROS_pal_interaction_msgs_I18nText_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/I18nArgument.h"

namespace pal_interaction_msgs
{

  class I18nText : public ros::Msg
  {
    public:
      const char* section;
      const char* key;
      const char* lang_id;
      uint8_t arguments_length;
      pal_interaction_msgs::I18nArgument st_arguments;
      pal_interaction_msgs::I18nArgument * arguments;

    I18nText():
      section(""),
      key(""),
      lang_id(""),
      arguments_length(0), arguments(NULL)
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
      uint32_t length_lang_id = strlen(this->lang_id);
      memcpy(outbuffer + offset, &length_lang_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->lang_id, length_lang_id);
      offset += length_lang_id;
      *(outbuffer + offset++) = arguments_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < arguments_length; i++){
      offset += this->arguments[i].serialize(outbuffer + offset);
      }
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
      uint32_t length_lang_id;
      memcpy(&length_lang_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lang_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lang_id-1]=0;
      this->lang_id = (char *)(inbuffer + offset-1);
      offset += length_lang_id;
      uint8_t arguments_lengthT = *(inbuffer + offset++);
      if(arguments_lengthT > arguments_length)
        this->arguments = (pal_interaction_msgs::I18nArgument*)realloc(this->arguments, arguments_lengthT * sizeof(pal_interaction_msgs::I18nArgument));
      offset += 3;
      arguments_length = arguments_lengthT;
      for( uint8_t i = 0; i < arguments_length; i++){
      offset += this->st_arguments.deserialize(inbuffer + offset);
        memcpy( &(this->arguments[i]), &(this->st_arguments), sizeof(pal_interaction_msgs::I18nArgument));
      }
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/I18nText"; };
    const char * getMD5(){ return "855c0cd82eb6837b039ea45087975cc2"; };

  };

}
#endif