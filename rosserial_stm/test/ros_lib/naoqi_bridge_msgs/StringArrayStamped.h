#ifndef _ROS_naoqi_bridge_msgs_StringArrayStamped_h
#define _ROS_naoqi_bridge_msgs_StringArrayStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace naoqi_bridge_msgs
{

  class StringArrayStamped : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t data_length;
      char* st_data;
      char* * data;

    StringArrayStamped():
      header(),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      uint32_t length_datai = strlen(this->data[i]);
      memcpy(outbuffer + offset, &length_datai, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->data[i], length_datai);
      offset += length_datai;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (char**)realloc(this->data, data_lengthT * sizeof(char*));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      uint32_t length_st_data;
      memcpy(&length_st_data, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_data; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_data-1]=0;
      this->st_data = (char *)(inbuffer + offset-1);
      offset += length_st_data;
        memcpy( &(this->data[i]), &(this->st_data), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "naoqi_bridge_msgs/StringArrayStamped"; };
    const char * getMD5(){ return "17b6e4aa81015d95bcd2b08039bd6bda"; };

  };

}
#endif