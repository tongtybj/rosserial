#ifndef _ROS_pgm_learner_DiscreteGraphState_h
#define _ROS_pgm_learner_DiscreteGraphState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pgm_learner/DiscreteNodeState.h"

namespace pgm_learner
{

  class DiscreteGraphState : public ros::Msg
  {
    public:
      uint8_t node_states_length;
      pgm_learner::DiscreteNodeState st_node_states;
      pgm_learner::DiscreteNodeState * node_states;

    DiscreteGraphState():
      node_states_length(0), node_states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = node_states_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < node_states_length; i++){
      offset += this->node_states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t node_states_lengthT = *(inbuffer + offset++);
      if(node_states_lengthT > node_states_length)
        this->node_states = (pgm_learner::DiscreteNodeState*)realloc(this->node_states, node_states_lengthT * sizeof(pgm_learner::DiscreteNodeState));
      offset += 3;
      node_states_length = node_states_lengthT;
      for( uint8_t i = 0; i < node_states_length; i++){
      offset += this->st_node_states.deserialize(inbuffer + offset);
        memcpy( &(this->node_states[i]), &(this->st_node_states), sizeof(pgm_learner::DiscreteNodeState));
      }
     return offset;
    }

    const char * getType(){ return "pgm_learner/DiscreteGraphState"; };
    const char * getMD5(){ return "16b46dda4af848eb5f3fa69917944093"; };

  };

}
#endif