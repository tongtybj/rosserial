#ifndef _ROS_pgm_learner_GraphStructure_h
#define _ROS_pgm_learner_GraphStructure_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pgm_learner/GraphEdge.h"

namespace pgm_learner
{

  class GraphStructure : public ros::Msg
  {
    public:
      uint8_t nodes_length;
      char* st_nodes;
      char* * nodes;
      uint8_t edges_length;
      pgm_learner::GraphEdge st_edges;
      pgm_learner::GraphEdge * edges;

    GraphStructure():
      nodes_length(0), nodes(NULL),
      edges_length(0), edges(NULL)
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
      uint32_t length_nodesi = strlen(this->nodes[i]);
      memcpy(outbuffer + offset, &length_nodesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->nodes[i], length_nodesi);
      offset += length_nodesi;
      }
      *(outbuffer + offset++) = edges_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < edges_length; i++){
      offset += this->edges[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t nodes_lengthT = *(inbuffer + offset++);
      if(nodes_lengthT > nodes_length)
        this->nodes = (char**)realloc(this->nodes, nodes_lengthT * sizeof(char*));
      offset += 3;
      nodes_length = nodes_lengthT;
      for( uint8_t i = 0; i < nodes_length; i++){
      uint32_t length_st_nodes;
      memcpy(&length_st_nodes, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_nodes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_nodes-1]=0;
      this->st_nodes = (char *)(inbuffer + offset-1);
      offset += length_st_nodes;
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(char*));
      }
      uint8_t edges_lengthT = *(inbuffer + offset++);
      if(edges_lengthT > edges_length)
        this->edges = (pgm_learner::GraphEdge*)realloc(this->edges, edges_lengthT * sizeof(pgm_learner::GraphEdge));
      offset += 3;
      edges_length = edges_lengthT;
      for( uint8_t i = 0; i < edges_length; i++){
      offset += this->st_edges.deserialize(inbuffer + offset);
        memcpy( &(this->edges[i]), &(this->st_edges), sizeof(pgm_learner::GraphEdge));
      }
     return offset;
    }

    const char * getType(){ return "pgm_learner/GraphStructure"; };
    const char * getMD5(){ return "304d6cd63065185c359cebaf1ff017e9"; };

  };

}
#endif