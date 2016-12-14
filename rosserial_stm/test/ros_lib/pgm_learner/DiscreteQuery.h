#ifndef _ROS_SERVICE_DiscreteQuery_h
#define _ROS_SERVICE_DiscreteQuery_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pgm_learner/DiscreteNode.h"
#include "pgm_learner/DiscreteNodeState.h"

namespace pgm_learner
{

static const char DISCRETEQUERY[] = "pgm_learner/DiscreteQuery";

  class DiscreteQueryRequest : public ros::Msg
  {
    public:
      uint8_t nodes_length;
      pgm_learner::DiscreteNode st_nodes;
      pgm_learner::DiscreteNode * nodes;
      uint8_t evidence_length;
      pgm_learner::DiscreteNodeState st_evidence;
      pgm_learner::DiscreteNodeState * evidence;
      uint8_t query_length;
      char* st_query;
      char* * query;

    DiscreteQueryRequest():
      nodes_length(0), nodes(NULL),
      evidence_length(0), evidence(NULL),
      query_length(0), query(NULL)
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
      *(outbuffer + offset++) = evidence_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < evidence_length; i++){
      offset += this->evidence[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = query_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < query_length; i++){
      uint32_t length_queryi = strlen(this->query[i]);
      memcpy(outbuffer + offset, &length_queryi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->query[i], length_queryi);
      offset += length_queryi;
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
      uint8_t evidence_lengthT = *(inbuffer + offset++);
      if(evidence_lengthT > evidence_length)
        this->evidence = (pgm_learner::DiscreteNodeState*)realloc(this->evidence, evidence_lengthT * sizeof(pgm_learner::DiscreteNodeState));
      offset += 3;
      evidence_length = evidence_lengthT;
      for( uint8_t i = 0; i < evidence_length; i++){
      offset += this->st_evidence.deserialize(inbuffer + offset);
        memcpy( &(this->evidence[i]), &(this->st_evidence), sizeof(pgm_learner::DiscreteNodeState));
      }
      uint8_t query_lengthT = *(inbuffer + offset++);
      if(query_lengthT > query_length)
        this->query = (char**)realloc(this->query, query_lengthT * sizeof(char*));
      offset += 3;
      query_length = query_lengthT;
      for( uint8_t i = 0; i < query_length; i++){
      uint32_t length_st_query;
      memcpy(&length_st_query, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_query; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_query-1]=0;
      this->st_query = (char *)(inbuffer + offset-1);
      offset += length_st_query;
        memcpy( &(this->query[i]), &(this->st_query), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return DISCRETEQUERY; };
    const char * getMD5(){ return "ed89305a3a26318e54824e9039449857"; };

  };

  class DiscreteQueryResponse : public ros::Msg
  {
    public:
      uint8_t nodes_length;
      pgm_learner::DiscreteNode st_nodes;
      pgm_learner::DiscreteNode * nodes;

    DiscreteQueryResponse():
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

    const char * getType(){ return DISCRETEQUERY; };
    const char * getMD5(){ return "c8f93aadf5ce2cc57073d952e12833e1"; };

  };

  class DiscreteQuery {
    public:
    typedef DiscreteQueryRequest Request;
    typedef DiscreteQueryResponse Response;
  };

}
#endif
