#ifndef _ROS_pal_interaction_msgs_ASRSrvResponse_h
#define _ROS_pal_interaction_msgs_ASRSrvResponse_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_interaction_msgs/ASRStatus.h"

namespace pal_interaction_msgs
{

  class ASRSrvResponse : public ros::Msg
  {
    public:
      pal_interaction_msgs::ASRStatus status;
      const char* error_msg;
      const char* warn_msg;

    ASRSrvResponse():
      status(),
      error_msg(""),
      warn_msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      uint32_t length_error_msg = strlen(this->error_msg);
      memcpy(outbuffer + offset, &length_error_msg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_msg, length_error_msg);
      offset += length_error_msg;
      uint32_t length_warn_msg = strlen(this->warn_msg);
      memcpy(outbuffer + offset, &length_warn_msg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->warn_msg, length_warn_msg);
      offset += length_warn_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
      uint32_t length_error_msg;
      memcpy(&length_error_msg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_msg-1]=0;
      this->error_msg = (char *)(inbuffer + offset-1);
      offset += length_error_msg;
      uint32_t length_warn_msg;
      memcpy(&length_warn_msg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_warn_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_warn_msg-1]=0;
      this->warn_msg = (char *)(inbuffer + offset-1);
      offset += length_warn_msg;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRSrvResponse"; };
    const char * getMD5(){ return "ae96a6a28fb96b873d0b448b3cf2c80c"; };

  };

}
#endif