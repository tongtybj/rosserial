#ifndef _ROS_pal_navigation_msgs_Emergency_h
#define _ROS_pal_navigation_msgs_Emergency_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace pal_navigation_msgs
{

  class Emergency : public ros::Msg
  {
    public:
      bool data;
      bool forward;
      bool backward;
      uint8_t msgs_length;
      std_msgs::String st_msgs;
      std_msgs::String * msgs;

    Emergency():
      data(0),
      forward(0),
      backward(0),
      msgs_length(0), msgs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      union {
        bool real;
        uint8_t base;
      } u_forward;
      u_forward.real = this->forward;
      *(outbuffer + offset + 0) = (u_forward.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->forward);
      union {
        bool real;
        uint8_t base;
      } u_backward;
      u_backward.real = this->backward;
      *(outbuffer + offset + 0) = (u_backward.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->backward);
      *(outbuffer + offset++) = msgs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < msgs_length; i++){
      offset += this->msgs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data = u_data.real;
      offset += sizeof(this->data);
      union {
        bool real;
        uint8_t base;
      } u_forward;
      u_forward.base = 0;
      u_forward.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->forward = u_forward.real;
      offset += sizeof(this->forward);
      union {
        bool real;
        uint8_t base;
      } u_backward;
      u_backward.base = 0;
      u_backward.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->backward = u_backward.real;
      offset += sizeof(this->backward);
      uint8_t msgs_lengthT = *(inbuffer + offset++);
      if(msgs_lengthT > msgs_length)
        this->msgs = (std_msgs::String*)realloc(this->msgs, msgs_lengthT * sizeof(std_msgs::String));
      offset += 3;
      msgs_length = msgs_lengthT;
      for( uint8_t i = 0; i < msgs_length; i++){
      offset += this->st_msgs.deserialize(inbuffer + offset);
        memcpy( &(this->msgs[i]), &(this->st_msgs), sizeof(std_msgs::String));
      }
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/Emergency"; };
    const char * getMD5(){ return "a23e1ed551a213a5d03f1cf6db037717"; };

  };

}
#endif