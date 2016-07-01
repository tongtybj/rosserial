#ifndef _ROS_jsk_demo_common_EventHeader_h
#define _ROS_jsk_demo_common_EventHeader_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_demo_common
{

  class EventHeader : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* context;

    EventHeader():
      header(),
      context("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_context = strlen(this->context);
      memcpy(outbuffer + offset, &length_context, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->context, length_context);
      offset += length_context;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_context;
      memcpy(&length_context, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_context; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_context-1]=0;
      this->context = (char *)(inbuffer + offset-1);
      offset += length_context;
     return offset;
    }

    const char * getType(){ return "jsk_demo_common/EventHeader"; };
    const char * getMD5(){ return "392c38aad1c641fe5594f5a232a5c427"; };

  };

}
#endif