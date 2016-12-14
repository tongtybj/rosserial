#ifndef _ROS_pal_interaction_msgs_TtsMark_h
#define _ROS_pal_interaction_msgs_TtsMark_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class TtsMark : public ros::Msg
  {
    public:
      const char* id;
      uint8_t keys_length;
      char* st_keys;
      char* * keys;
      uint8_t value_length;
      char* st_value;
      char* * value;

    TtsMark():
      id(""),
      keys_length(0), keys(NULL),
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      *(outbuffer + offset++) = keys_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < keys_length; i++){
      uint32_t length_keysi = strlen(this->keys[i]);
      memcpy(outbuffer + offset, &length_keysi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->keys[i], length_keysi);
      offset += length_keysi;
      }
      *(outbuffer + offset++) = value_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < value_length; i++){
      uint32_t length_valuei = strlen(this->value[i]);
      memcpy(outbuffer + offset, &length_valuei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->value[i], length_valuei);
      offset += length_valuei;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint8_t keys_lengthT = *(inbuffer + offset++);
      if(keys_lengthT > keys_length)
        this->keys = (char**)realloc(this->keys, keys_lengthT * sizeof(char*));
      offset += 3;
      keys_length = keys_lengthT;
      for( uint8_t i = 0; i < keys_length; i++){
      uint32_t length_st_keys;
      memcpy(&length_st_keys, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_keys; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_keys-1]=0;
      this->st_keys = (char *)(inbuffer + offset-1);
      offset += length_st_keys;
        memcpy( &(this->keys[i]), &(this->st_keys), sizeof(char*));
      }
      uint8_t value_lengthT = *(inbuffer + offset++);
      if(value_lengthT > value_length)
        this->value = (char**)realloc(this->value, value_lengthT * sizeof(char*));
      offset += 3;
      value_length = value_lengthT;
      for( uint8_t i = 0; i < value_length; i++){
      uint32_t length_st_value;
      memcpy(&length_st_value, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_value-1]=0;
      this->st_value = (char *)(inbuffer + offset-1);
      offset += length_st_value;
        memcpy( &(this->value[i]), &(this->st_value), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/TtsMark"; };
    const char * getMD5(){ return "10ae9a83cac56ac1660df7e26eabeac9"; };

  };

}
#endif