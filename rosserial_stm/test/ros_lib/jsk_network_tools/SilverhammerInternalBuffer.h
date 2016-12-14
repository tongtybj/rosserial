#ifndef _ROS_jsk_network_tools_SilverhammerInternalBuffer_h
#define _ROS_jsk_network_tools_SilverhammerInternalBuffer_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_network_tools
{

  class SilverhammerInternalBuffer : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t seq_id;
      uint8_t data_length;
      uint8_t st_data;
      uint8_t * data;

    SilverhammerInternalBuffer():
      header(),
      seq_id(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->seq_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seq_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seq_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seq_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->seq_id);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->seq_id =  ((uint32_t) (*(inbuffer + offset)));
      this->seq_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seq_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seq_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->seq_id);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (uint8_t*)realloc(this->data, data_lengthT * sizeof(uint8_t));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      this->st_data =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "jsk_network_tools/SilverhammerInternalBuffer"; };
    const char * getMD5(){ return "b0224c297e0e2b6e1ac36f4f9188136f"; };

  };

}
#endif