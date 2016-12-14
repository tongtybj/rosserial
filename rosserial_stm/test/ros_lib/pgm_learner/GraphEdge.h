#ifndef _ROS_pgm_learner_GraphEdge_h
#define _ROS_pgm_learner_GraphEdge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pgm_learner
{

  class GraphEdge : public ros::Msg
  {
    public:
      const char* node_from;
      const char* node_to;

    GraphEdge():
      node_from(""),
      node_to("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_node_from = strlen(this->node_from);
      memcpy(outbuffer + offset, &length_node_from, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->node_from, length_node_from);
      offset += length_node_from;
      uint32_t length_node_to = strlen(this->node_to);
      memcpy(outbuffer + offset, &length_node_to, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->node_to, length_node_to);
      offset += length_node_to;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_node_from;
      memcpy(&length_node_from, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node_from; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node_from-1]=0;
      this->node_from = (char *)(inbuffer + offset-1);
      offset += length_node_from;
      uint32_t length_node_to;
      memcpy(&length_node_to, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node_to; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node_to-1]=0;
      this->node_to = (char *)(inbuffer + offset-1);
      offset += length_node_to;
     return offset;
    }

    const char * getType(){ return "pgm_learner/GraphEdge"; };
    const char * getMD5(){ return "0e8438c5349fda07e98ac2a93db05307"; };

  };

}
#endif