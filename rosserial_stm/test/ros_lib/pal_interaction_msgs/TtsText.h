#ifndef _ROS_pal_interaction_msgs_TtsText_h
#define _ROS_pal_interaction_msgs_TtsText_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class TtsText : public ros::Msg
  {
    public:
      const char* text;
      const char* lang_id;

    TtsText():
      text(""),
      lang_id("")
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
      uint32_t length_lang_id = strlen(this->lang_id);
      memcpy(outbuffer + offset, &length_lang_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->lang_id, length_lang_id);
      offset += length_lang_id;
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
      uint32_t length_lang_id;
      memcpy(&length_lang_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lang_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lang_id-1]=0;
      this->lang_id = (char *)(inbuffer + offset-1);
      offset += length_lang_id;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/TtsText"; };
    const char * getMD5(){ return "a42001bb3ccbf1a914b618f34087dc37"; };

  };

}
#endif