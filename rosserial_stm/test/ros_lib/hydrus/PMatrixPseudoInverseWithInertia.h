#ifndef _ROS_hydrus_PMatrixPseudoInverseWithInertia_h
#define _ROS_hydrus_PMatrixPseudoInverseWithInertia_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hydrus/PMatrixPseudoInverseUnit.h"

namespace hydrus
{

  class PMatrixPseudoInverseWithInertia : public ros::Msg
  {
    public:
      uint8_t pseudo_inverse_length;
      hydrus::PMatrixPseudoInverseUnit st_pseudo_inverse;
      hydrus::PMatrixPseudoInverseUnit * pseudo_inverse;
      int16_t inertia[6];

    PMatrixPseudoInverseWithInertia():
      pseudo_inverse_length(0), pseudo_inverse(NULL),
      inertia()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = pseudo_inverse_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pseudo_inverse_length; i++){
      offset += this->pseudo_inverse[i].serialize(outbuffer + offset);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_inertiai;
      u_inertiai.real = this->inertia[i];
      *(outbuffer + offset + 0) = (u_inertiai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inertiai.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->inertia[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t pseudo_inverse_lengthT = *(inbuffer + offset++);
      if(pseudo_inverse_lengthT > pseudo_inverse_length)
        this->pseudo_inverse = (hydrus::PMatrixPseudoInverseUnit*)realloc(this->pseudo_inverse, pseudo_inverse_lengthT * sizeof(hydrus::PMatrixPseudoInverseUnit));
      offset += 3;
      pseudo_inverse_length = pseudo_inverse_lengthT;
      for( uint8_t i = 0; i < pseudo_inverse_length; i++){
      offset += this->st_pseudo_inverse.deserialize(inbuffer + offset);
        memcpy( &(this->pseudo_inverse[i]), &(this->st_pseudo_inverse), sizeof(hydrus::PMatrixPseudoInverseUnit));
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_inertiai;
      u_inertiai.base = 0;
      u_inertiai.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inertiai.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->inertia[i] = u_inertiai.real;
      offset += sizeof(this->inertia[i]);
      }
     return offset;
    }

    const char * getType(){ return "hydrus/PMatrixPseudoInverseWithInertia"; };
    const char * getMD5(){ return "e67a441fd1d34930b8789fd5b10a7fe7"; };

  };

}
#endif