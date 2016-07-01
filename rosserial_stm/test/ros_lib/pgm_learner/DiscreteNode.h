#ifndef _ROS_pgm_learner_DiscreteNode_h
#define _ROS_pgm_learner_DiscreteNode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pgm_learner/ConditionalProbability.h"

namespace pgm_learner
{

  class DiscreteNode : public ros::Msg
  {
    public:
      const char* name;
      uint8_t outcomes_length;
      char* st_outcomes;
      char* * outcomes;
      uint8_t parents_length;
      char* st_parents;
      char* * parents;
      uint8_t children_length;
      char* st_children;
      char* * children;
      uint8_t CPT_length;
      pgm_learner::ConditionalProbability st_CPT;
      pgm_learner::ConditionalProbability * CPT;

    DiscreteNode():
      name(""),
      outcomes_length(0), outcomes(NULL),
      parents_length(0), parents(NULL),
      children_length(0), children(NULL),
      CPT_length(0), CPT(NULL)
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
      *(outbuffer + offset++) = outcomes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < outcomes_length; i++){
      uint32_t length_outcomesi = strlen(this->outcomes[i]);
      memcpy(outbuffer + offset, &length_outcomesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->outcomes[i], length_outcomesi);
      offset += length_outcomesi;
      }
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
      *(outbuffer + offset++) = CPT_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < CPT_length; i++){
      offset += this->CPT[i].serialize(outbuffer + offset);
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
      uint8_t outcomes_lengthT = *(inbuffer + offset++);
      if(outcomes_lengthT > outcomes_length)
        this->outcomes = (char**)realloc(this->outcomes, outcomes_lengthT * sizeof(char*));
      offset += 3;
      outcomes_length = outcomes_lengthT;
      for( uint8_t i = 0; i < outcomes_length; i++){
      uint32_t length_st_outcomes;
      memcpy(&length_st_outcomes, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_outcomes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_outcomes-1]=0;
      this->st_outcomes = (char *)(inbuffer + offset-1);
      offset += length_st_outcomes;
        memcpy( &(this->outcomes[i]), &(this->st_outcomes), sizeof(char*));
      }
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
      uint8_t CPT_lengthT = *(inbuffer + offset++);
      if(CPT_lengthT > CPT_length)
        this->CPT = (pgm_learner::ConditionalProbability*)realloc(this->CPT, CPT_lengthT * sizeof(pgm_learner::ConditionalProbability));
      offset += 3;
      CPT_length = CPT_lengthT;
      for( uint8_t i = 0; i < CPT_length; i++){
      offset += this->st_CPT.deserialize(inbuffer + offset);
        memcpy( &(this->CPT[i]), &(this->st_CPT), sizeof(pgm_learner::ConditionalProbability));
      }
     return offset;
    }

    const char * getType(){ return "pgm_learner/DiscreteNode"; };
    const char * getMD5(){ return "4342c6b20fde889181ce34955023e453"; };

  };

}
#endif