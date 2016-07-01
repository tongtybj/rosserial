#ifndef _ROS_pgm_learner_ConditionalProbability_h
#define _ROS_pgm_learner_ConditionalProbability_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pgm_learner
{

  class ConditionalProbability : public ros::Msg
  {
    public:
      uint8_t values_length;
      char* st_values;
      char* * values;
      uint8_t probabilities_length;
      float st_probabilities;
      float * probabilities;

    ConditionalProbability():
      values_length(0), values(NULL),
      probabilities_length(0), probabilities(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < values_length; i++){
      uint32_t length_valuesi = strlen(this->values[i]);
      memcpy(outbuffer + offset, &length_valuesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->values[i], length_valuesi);
      offset += length_valuesi;
      }
      *(outbuffer + offset++) = probabilities_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < probabilities_length; i++){
      union {
        float real;
        uint32_t base;
      } u_probabilitiesi;
      u_probabilitiesi.real = this->probabilities[i];
      *(outbuffer + offset + 0) = (u_probabilitiesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_probabilitiesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_probabilitiesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_probabilitiesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->probabilities[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t values_lengthT = *(inbuffer + offset++);
      if(values_lengthT > values_length)
        this->values = (char**)realloc(this->values, values_lengthT * sizeof(char*));
      offset += 3;
      values_length = values_lengthT;
      for( uint8_t i = 0; i < values_length; i++){
      uint32_t length_st_values;
      memcpy(&length_st_values, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_values; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_values-1]=0;
      this->st_values = (char *)(inbuffer + offset-1);
      offset += length_st_values;
        memcpy( &(this->values[i]), &(this->st_values), sizeof(char*));
      }
      uint8_t probabilities_lengthT = *(inbuffer + offset++);
      if(probabilities_lengthT > probabilities_length)
        this->probabilities = (float*)realloc(this->probabilities, probabilities_lengthT * sizeof(float));
      offset += 3;
      probabilities_length = probabilities_lengthT;
      for( uint8_t i = 0; i < probabilities_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_probabilities;
      u_st_probabilities.base = 0;
      u_st_probabilities.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_probabilities.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_probabilities.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_probabilities.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_probabilities = u_st_probabilities.real;
      offset += sizeof(this->st_probabilities);
        memcpy( &(this->probabilities[i]), &(this->st_probabilities), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "pgm_learner/ConditionalProbability"; };
    const char * getMD5(){ return "232892e3b161d3aa164b36b806c0c5f8"; };

  };

}
#endif