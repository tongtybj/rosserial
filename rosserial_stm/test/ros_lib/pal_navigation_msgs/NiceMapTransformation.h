#ifndef _ROS_pal_navigation_msgs_NiceMapTransformation_h
#define _ROS_pal_navigation_msgs_NiceMapTransformation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class NiceMapTransformation : public ros::Msg
  {
    public:
      double x;
      double y;
      double rotYawRad;
      double scale;

    NiceMapTransformation():
      x(0),
      y(0),
      rotYawRad(0),
      scale(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_rotYawRad;
      u_rotYawRad.real = this->rotYawRad;
      *(outbuffer + offset + 0) = (u_rotYawRad.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotYawRad.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rotYawRad.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rotYawRad.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rotYawRad.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rotYawRad.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rotYawRad.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rotYawRad.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rotYawRad);
      union {
        double real;
        uint64_t base;
      } u_scale;
      u_scale.real = this->scale;
      *(outbuffer + offset + 0) = (u_scale.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scale.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scale.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scale.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_scale.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_scale.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_scale.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_scale.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->scale);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_rotYawRad;
      u_rotYawRad.base = 0;
      u_rotYawRad.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotYawRad.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rotYawRad.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rotYawRad.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rotYawRad.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rotYawRad.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rotYawRad.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rotYawRad.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rotYawRad = u_rotYawRad.real;
      offset += sizeof(this->rotYawRad);
      union {
        double real;
        uint64_t base;
      } u_scale;
      u_scale.base = 0;
      u_scale.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scale.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scale.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scale.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_scale.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_scale.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_scale.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_scale.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->scale = u_scale.real;
      offset += sizeof(this->scale);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/NiceMapTransformation"; };
    const char * getMD5(){ return "af4c7e65074d9c380c082e0485e8868c"; };

  };

}
#endif