#ifndef _ROS_SERVICE_DiscreteParameterEstimation_h
#define _ROS_SERVICE_DiscreteParameterEstimation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pgm_learner/DiscreteNode.h"
#include "pgm_learner/DiscreteGraphState.h"
#include "pgm_learner/GraphStructure.h"

namespace pgm_learner
{

static const char DISCRETEPARAMETERESTIMATION[] = "pgm_learner/DiscreteParameterEstimation";

  class DiscreteParameterEstimationRequest : public ros::Msg
  {
    public:
      pgm_learner::GraphStructure graph;
      uint8_t states_length;
      pgm_learner::DiscreteGraphState st_states;
      pgm_learner::DiscreteGraphState * states;

    DiscreteParameterEstimationRequest():
      graph(),
      states_length(0), states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->graph.serialize(outbuffer + offset);
      *(outbuffer + offset++) = states_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->graph.deserialize(inbuffer + offset);
      uint8_t states_lengthT = *(inbuffer + offset++);
      if(states_lengthT > states_length)
        this->states = (pgm_learner::DiscreteGraphState*)realloc(this->states, states_lengthT * sizeof(pgm_learner::DiscreteGraphState));
      offset += 3;
      states_length = states_lengthT;
      for( uint8_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(pgm_learner::DiscreteGraphState));
      }
     return offset;
    }

    const char * getType(){ return DISCRETEPARAMETERESTIMATION; };
    const char * getMD5(){ return "a4887ac175e64291ed3c977eac937022"; };

  };

  class DiscreteParameterEstimationResponse : public ros::Msg
  {
    public:
      uint8_t nodes_length;
      pgm_learner::DiscreteNode st_nodes;
      pgm_learner::DiscreteNode * nodes;

    DiscreteParameterEstimationResponse():
      nodes_length(0), nodes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = nodes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < nodes_length; i++){
      offset += this->nodes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t nodes_lengthT = *(inbuffer + offset++);
      if(nodes_lengthT > nodes_length)
        this->nodes = (pgm_learner::DiscreteNode*)realloc(this->nodes, nodes_lengthT * sizeof(pgm_learner::DiscreteNode));
      offset += 3;
      nodes_length = nodes_lengthT;
      for( uint8_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(pgm_learner::DiscreteNode));
      }
     return offset;
    }

    const char * getType(){ return DISCRETEPARAMETERESTIMATION; };
    const char * getMD5(){ return "c8f93aadf5ce2cc57073d952e12833e1"; };

  };

  class DiscreteParameterEstimation {
    public:
    typedef DiscreteParameterEstimationRequest Request;
    typedef DiscreteParameterEstimationResponse Response;
  };

}
#endif
