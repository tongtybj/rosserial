#ifndef _ROS_pal_detection_msgs_RotatedDetection2d_h
#define _ROS_pal_detection_msgs_RotatedDetection2d_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_detection_msgs
{

  class RotatedDetection2d : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t x_length;
      int64_t st_x;
      int64_t * x;
      uint8_t y_length;
      int64_t st_y;
      int64_t * y;

    RotatedDetection2d():
      header(),
      x_length(0), x(NULL),
      y_length(0), y(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = x_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < x_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_xi;
      u_xi.real = this->x[i];
      *(outbuffer + offset + 0) = (u_xi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_xi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_xi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_xi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_xi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_xi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_xi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_xi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x[i]);
      }
      *(outbuffer + offset++) = y_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < y_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_yi;
      u_yi.real = this->y[i];
      *(outbuffer + offset + 0) = (u_yi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_yi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_yi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_yi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_yi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t x_lengthT = *(inbuffer + offset++);
      if(x_lengthT > x_length)
        this->x = (int64_t*)realloc(this->x, x_lengthT * sizeof(int64_t));
      offset += 3;
      x_length = x_lengthT;
      for( uint8_t i = 0; i < x_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_x;
      u_st_x.base = 0;
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_x = u_st_x.real;
      offset += sizeof(this->st_x);
        memcpy( &(this->x[i]), &(this->st_x), sizeof(int64_t));
      }
      uint8_t y_lengthT = *(inbuffer + offset++);
      if(y_lengthT > y_length)
        this->y = (int64_t*)realloc(this->y, y_lengthT * sizeof(int64_t));
      offset += 3;
      y_length = y_lengthT;
      for( uint8_t i = 0; i < y_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_y;
      u_st_y.base = 0;
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_y = u_st_y.real;
      offset += sizeof(this->st_y);
        memcpy( &(this->y[i]), &(this->st_y), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/RotatedDetection2d"; };
    const char * getMD5(){ return "1696e52e0f42b73a9168aef8ceb90f0e"; };

  };

}
#endif