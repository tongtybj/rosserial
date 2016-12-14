#ifndef _ROS_pgm_learner_LinearGaussianNode_h
#define _ROS_pgm_learner_LinearGaussianNode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pgm_learner
{

  class LinearGaussianNode : public ros::Msg
  {
    public:
      const char* name;
      uint8_t parents_length;
      char* st_parents;
      char* * parents;
      uint8_t children_length;
      char* st_children;
      char* * children;
      float mean;
      float variance;
      uint8_t mean_scalar_length;
      float st_mean_scalar;
      float * mean_scalar;

    LinearGaussianNode():
      name(""),
      parents_length(0), parents(NULL),
      children_length(0), children(NULL),
      mean(0),
      variance(0),
      mean_scalar_length(0), mean_scalar(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset++) = parents_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < parents_length; i++){
      uint32_t length_parentsi = strlen(this->parents[i]);
      memcpy(outbuffer + offset, &length_parentsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->parents[i], length_parentsi);
      offset += length_parentsi;
      }
      *(outbuffer + offset++) = children_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < children_length; i++){
      uint32_t length_childreni = strlen(this->children[i]);
      memcpy(outbuffer + offset, &length_childreni, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->children[i], length_childreni);
      offset += length_childreni;
      }
      union {
        float real;
        uint32_t base;
      } u_mean;
      u_mean.real = this->mean;
      *(outbuffer + offset + 0) = (u_mean.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mean.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mean.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mean.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mean);
      union {
        float real;
        uint32_t base;
      } u_variance;
      u_variance.real = this->variance;
      *(outbuffer + offset + 0) = (u_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variance);
      *(outbuffer + offset++) = mean_scalar_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < mean_scalar_length; i++){
      union {
        float real;
        uint32_t base;
      } u_mean_scalari;
      u_mean_scalari.real = this->mean_scalar[i];
      *(outbuffer + offset + 0) = (u_mean_scalari.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mean_scalari.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mean_scalari.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mean_scalari.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mean_scalar[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint8_t parents_lengthT = *(inbuffer + offset++);
      if(parents_lengthT > parents_length)
        this->parents = (char**)realloc(this->parents, parents_lengthT * sizeof(char*));
      offset += 3;
      parents_length = parents_lengthT;
      for( uint8_t i = 0; i < parents_length; i++){
      uint32_t length_st_parents;
      memcpy(&length_st_parents, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_parents; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_parents-1]=0;
      this->st_parents = (char *)(inbuffer + offset-1);
      offset += length_st_parents;
        memcpy( &(this->parents[i]), &(this->st_parents), sizeof(char*));
      }
      uint8_t children_lengthT = *(inbuffer + offset++);
      if(children_lengthT > children_length)
        this->children = (char**)realloc(this->children, children_lengthT * sizeof(char*));
      offset += 3;
      children_length = children_lengthT;
      for( uint8_t i = 0; i < children_length; i++){
      uint32_t length_st_children;
      memcpy(&length_st_children, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_children; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_children-1]=0;
      this->st_children = (char *)(inbuffer + offset-1);
      offset += length_st_children;
        memcpy( &(this->children[i]), &(this->st_children), sizeof(char*));
      }
      union {
        float real;
        uint32_t base;
      } u_mean;
      u_mean.base = 0;
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mean.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mean = u_mean.real;
      offset += sizeof(this->mean);
      union {
        float real;
        uint32_t base;
      } u_variance;
      u_variance.base = 0;
      u_variance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->variance = u_variance.real;
      offset += sizeof(this->variance);
      uint8_t mean_scalar_lengthT = *(inbuffer + offset++);
      if(mean_scalar_lengthT > mean_scalar_length)
        this->mean_scalar = (float*)realloc(this->mean_scalar, mean_scalar_lengthT * sizeof(float));
      offset += 3;
      mean_scalar_length = mean_scalar_lengthT;
      for( uint8_t i = 0; i < mean_scalar_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_mean_scalar;
      u_st_mean_scalar.base = 0;
      u_st_mean_scalar.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_mean_scalar.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_mean_scalar.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_mean_scalar.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_mean_scalar = u_st_mean_scalar.real;
      offset += sizeof(this->st_mean_scalar);
        memcpy( &(this->mean_scalar[i]), &(this->st_mean_scalar), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "pgm_learner/LinearGaussianNode"; };
    const char * getMD5(){ return "78e1d100b7497d3d3e117e9c91018b8c"; };

  };

}
#endif