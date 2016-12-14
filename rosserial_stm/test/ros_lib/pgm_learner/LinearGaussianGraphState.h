#ifndef _ROS_pgm_learner_LinearGaussianGraphState_h
#define _ROS_pgm_learner_LinearGaussianGraphState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pgm_learner/LinearGaussianNodeState.h"

namespace pgm_learner
{

  class LinearGaussianGraphState : public ros::Msg
  {
    public:
      uint8_t node_states_length;
      pgm_learner::LinearGaussianNodeState st_node_states;
      pgm_learner::LinearGaussianNodeState * node_states;

    LinearGaussianGraphState():
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
        this->node_states = (pgm_learner::LinearGaussianNodeState*)realloc(this->node_states, node_states_lengthT * sizeof(pgm_learner::LinearGaussianNodeState));
      offset += 3;
      node_states_length = node_states_lengthT;
      for( uint8_t i = 0; i < node_states_length; i++){
      offset += this->st_node_states.deserialize(inbuffer + offset);
        memcpy( &(this->node_states[i]), &(this->st_node_states), sizeof(pgm_learner::LinearGaussianNodeState));
      }
     return offset;
    }

    const char * getType(){ return "pgm_learner/LinearGaussianGraphState"; };
    const char * getMD5(){ return "f6ac09f794ac42baad4ddfb93fc0a69c"; };

  };

}
#endif