#ifndef _ROS_hydrus_transform_control_PMatrixPseudoInverseUnit_h
#define _ROS_hydrus_transform_control_PMatrixPseudoInverseUnit_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus_transform_control
{

  class PMatrixPseudoInverseUnit : public ros::Msg
  {
    public:
      int16_t r;
      int16_t p;
      int16_t y;

    PMatrixPseudoInverseUnit():
      r(0),
      p(0),
      y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_r;
      u_r.real = this->r;
      *(outbuffer + offset + 0) = (u_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->r);
      union {
        int16_t real;
        uint16_t base;
      } u_p;
      u_p.real = this->p;
      *(outbuffer + offset + 0) = (u_p.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_p.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->p);
      union {
        int16_t real;
        uint16_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_r;
      u_r.base = 0;
      u_r.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->r = u_r.real;
      offset += sizeof(this->r);
      union {
        int16_t real;
        uint16_t base;
      } u_p;
      u_p.base = 0;
      u_p.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_p.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->p = u_p.real;
      offset += sizeof(this->p);
      union {
        int16_t real;
        uint16_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->y = u_y.real;
      offset += sizeof(this->y);
     return offset;
    }

    const char * getType(){ return "hydrus_transform_control/PMatrixPseudoInverseUnit"; };
    const char * getMD5(){ return "e6b0d87fcb05dfbea906fb98758f7fec"; };

  };

}
#endif