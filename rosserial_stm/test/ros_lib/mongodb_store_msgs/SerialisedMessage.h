#ifndef _ROS_mongodb_store_msgs_SerialisedMessage_h
#define _ROS_mongodb_store_msgs_SerialisedMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mongodb_store_msgs
{

  class SerialisedMessage : public ros::Msg
  {
    public:
      const char* type;
      uint8_t msg_length;
      uint8_t st_msg;
      uint8_t * msg;

    SerialisedMessage():
      type(""),
      msg_length(0), msg(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset++) = msg_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < msg_length; i++){
      *(outbuffer + offset + 0) = (this->msg[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msg[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint8_t msg_lengthT = *(inbuffer + offset++);
      if(msg_lengthT > msg_length)
        this->msg = (uint8_t*)realloc(this->msg, msg_lengthT * sizeof(uint8_t));
      offset += 3;
      msg_length = msg_lengthT;
      for( uint8_t i = 0; i < msg_length; i++){
      this->st_msg =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_msg);
        memcpy( &(this->msg[i]), &(this->st_msg), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "mongodb_store_msgs/SerialisedMessage"; };
    const char * getMD5(){ return "42f77e70b6ff70f99d1597d836874cfc"; };

  };

}
#endif