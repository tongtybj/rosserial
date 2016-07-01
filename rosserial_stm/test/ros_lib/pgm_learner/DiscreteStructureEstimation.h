#ifndef _ROS_SERVICE_DiscreteStructureEstimation_h
#define _ROS_SERVICE_DiscreteStructureEstimation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pgm_learner/DiscreteGraphState.h"
#include "pgm_learner/GraphStructure.h"

namespace pgm_learner
{

static const char DISCRETESTRUCTUREESTIMATION[] = "pgm_learner/DiscreteStructureEstimation";

  class DiscreteStructureEstimationRequest : public ros::Msg
  {
    public:
      uint8_t states_length;
      pgm_learner::DiscreteGraphState st_states;
      pgm_learner::DiscreteGraphState * states;
      double pvalparam;
      uint16_t indegree;

    DiscreteStructureEstimationRequest():
      states_length(0), states(NULL),
      pvalparam(0),
      indegree(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = states_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      union {
        double real;
        uint64_t base;
      } u_pvalparam;
      u_pvalparam.real = this->pvalparam;
      *(outbuffer + offset + 0) = (u_pvalparam.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pvalparam.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pvalparam.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pvalparam.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pvalparam.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pvalparam.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pvalparam.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pvalparam.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pvalparam);
      *(outbuffer + offset + 0) = (this->indegree >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->indegree >> (8 * 1)) & 0xFF;
      offset += sizeof(this->indegree);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t states_lengthT = *(inbuffer + offset++);
      if(states_lengthT > states_length)
        this->states = (pgm_learner::DiscreteGraphState*)realloc(this->states, states_lengthT * sizeof(pgm_learner::DiscreteGraphState));
      offset += 3;
      states_length = states_lengthT;
      for( uint8_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(pgm_learner::DiscreteGraphState));
      }
      union {
        double real;
        uint64_t base;
      } u_pvalparam;
      u_pvalparam.base = 0;
      u_pvalparam.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pvalparam.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pvalparam.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pvalparam.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pvalparam.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pvalparam.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pvalparam.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pvalparam.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pvalparam = u_pvalparam.real;
      offset += sizeof(this->pvalparam);
      this->indegree =  ((uint16_t) (*(inbuffer + offset)));
      this->indegree |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->indegree);
     return offset;
    }

    const char * getType(){ return DISCRETESTRUCTUREESTIMATION; };
    const char * getMD5(){ return "5895a0dcbf43af9937d20b41b960a53d"; };

  };

  class DiscreteStructureEstimationResponse : public ros::Msg
  {
    public:
      pgm_learner::GraphStructure graph;

    DiscreteStructureEstimationResponse():
      graph()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->graph.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->graph.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return DISCRETESTRUCTUREESTIMATION; };
    const char * getMD5(){ return "b84752916d49330453f083c59f6f9bc4"; };

  };

  class DiscreteStructureEstimation {
    public:
    typedef DiscreteStructureEstimationRequest Request;
    typedef DiscreteStructureEstimationResponse Response;
  };

}
#endif
