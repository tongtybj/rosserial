#ifndef _ROS_pal_interaction_msgs_ASRStatus_h
#define _ROS_pal_interaction_msgs_ASRStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/AudioDeviceDescription.h"

namespace pal_interaction_msgs
{

  class ASRStatus : public ros::Msg
  {
    public:
      bool active;
      const char* language;
      const char* enabled_grammar;
      const char* acoustic_env;
      pal_interaction_msgs::AudioDeviceDescription device;

    ASRStatus():
      active(0),
      language(""),
      enabled_grammar(""),
      acoustic_env(""),
      device()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.real = this->active;
      *(outbuffer + offset + 0) = (u_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active);
      uint32_t length_language = strlen(this->language);
      memcpy(outbuffer + offset, &length_language, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->language, length_language);
      offset += length_language;
      uint32_t length_enabled_grammar = strlen(this->enabled_grammar);
      memcpy(outbuffer + offset, &length_enabled_grammar, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->enabled_grammar, length_enabled_grammar);
      offset += length_enabled_grammar;
      uint32_t length_acoustic_env = strlen(this->acoustic_env);
      memcpy(outbuffer + offset, &length_acoustic_env, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->acoustic_env, length_acoustic_env);
      offset += length_acoustic_env;
      offset += this->device.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_active;
      u_active.base = 0;
      u_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->active = u_active.real;
      offset += sizeof(this->active);
      uint32_t length_language;
      memcpy(&length_language, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_language; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_language-1]=0;
      this->language = (char *)(inbuffer + offset-1);
      offset += length_language;
      uint32_t length_enabled_grammar;
      memcpy(&length_enabled_grammar, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_enabled_grammar; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_enabled_grammar-1]=0;
      this->enabled_grammar = (char *)(inbuffer + offset-1);
      offset += length_enabled_grammar;
      uint32_t length_acoustic_env;
      memcpy(&length_acoustic_env, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_acoustic_env; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_acoustic_env-1]=0;
      this->acoustic_env = (char *)(inbuffer + offset-1);
      offset += length_acoustic_env;
      offset += this->device.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRStatus"; };
    const char * getMD5(){ return "b05e32d6465a052804ec3f6d853dbe61"; };

  };

}
#endif