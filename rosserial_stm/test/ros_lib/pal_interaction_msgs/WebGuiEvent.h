#ifndef _ROS_pal_interaction_msgs_WebGuiEvent_h
#define _ROS_pal_interaction_msgs_WebGuiEvent_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class WebGuiEvent : public ros::Msg
  {
    public:
      const char* name;
      const char* arg;

    WebGuiEvent():
      name(""),
      arg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_arg = strlen(this->arg);
      memcpy(outbuffer + offset, &length_arg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->arg, length_arg);
      offset += length_arg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_arg;
      memcpy(&length_arg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arg-1]=0;
      this->arg = (char *)(inbuffer + offset-1);
      offset += length_arg;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/WebGuiEvent"; };
    const char * getMD5(){ return "bd4a90be174b9e14b06cf397c1359fb1"; };

  };

}
#endif