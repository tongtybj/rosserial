#ifndef _ROS_SERVICE_LinearGaussianParameterEstimation_h
#define _ROS_SERVICE_LinearGaussianParameterEstimation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pgm_learner/LinearGaussianGraphState.h"
#include "pgm_learner/GraphStructure.h"
#include "pgm_learner/LinearGaussianNode.h"

namespace pgm_learner
{

static const char LINEARGAUSSIANPARAMETERESTIMATION[] = "pgm_learner/LinearGaussianParameterEstimation";

  class LinearGaussianParameterEstimationRequest : public ros::Msg
  {
    public:
      pgm_learner::GraphStructure graph;
      uint8_t states_length;
      pgm_learner::LinearGaussianGraphState st_states;
      pgm_learner::LinearGaussianGraphState * states;

    LinearGaussianParameterEstimationRequest():
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
        this->states = (pgm_learner::LinearGaussianGraphState*)realloc(this->states, states_lengthT * sizeof(pgm_learner::LinearGaussianGraphState));
      offset += 3;
      states_length = states_lengthT;
      for( uint8_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(pgm_learner::LinearGaussianGraphState));
      }
     return offset;
    }

    const char * getType(){ return LINEARGAUSSIANPARAMETERESTIMATION; };
    const char * getMD5(){ return "8c1ba4d6cf70003845d5e35223229532"; };

  };

  class LinearGaussianParameterEstimationResponse : public ros::Msg
  {
    public:
      uint8_t nodes_length;
      pgm_learner::LinearGaussianNode st_nodes;
      pgm_learner::LinearGaussianNode * nodes;

    LinearGaussianParameterEstimationResponse():
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
        this->nodes = (pgm_learner::LinearGaussianNode*)realloc(this->nodes, nodes_lengthT * sizeof(pgm_learner::LinearGaussianNode));
      offset += 3;
      nodes_length = nodes_lengthT;
      for( uint8_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(pgm_learner::LinearGaussianNode));
      }
     return offset;
    }

    const char * getType(){ return LINEARGAUSSIANPARAMETERESTIMATION; };
    const char * getMD5(){ return "f083fa6aa9eee204da186b10e3de3230"; };

  };

  class LinearGaussianParameterEstimation {
    public:
    typedef LinearGaussianParameterEstimationRequest Request;
    typedef LinearGaussianParameterEstimationResponse Response;
  };

}
#endif
