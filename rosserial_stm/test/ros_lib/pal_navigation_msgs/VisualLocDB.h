#ifndef _ROS_pal_navigation_msgs_VisualLocDB_h
#define _ROS_pal_navigation_msgs_VisualLocDB_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class VisualLocDB : public ros::Msg
  {
    public:
      uint8_t documents_length;
      uint8_t st_documents;
      uint8_t * documents;
      uint8_t tree_length;
      uint8_t st_tree;
      uint8_t * tree;
      uint8_t weights_length;
      uint8_t st_weights;
      uint8_t * weights;

    VisualLocDB():
      documents_length(0), documents(NULL),
      tree_length(0), tree(NULL),
      weights_length(0), weights(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = documents_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < documents_length; i++){
      *(outbuffer + offset + 0) = (this->documents[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->documents[i]);
      }
      *(outbuffer + offset++) = tree_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tree_length; i++){
      *(outbuffer + offset + 0) = (this->tree[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tree[i]);
      }
      *(outbuffer + offset++) = weights_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < weights_length; i++){
      *(outbuffer + offset + 0) = (this->weights[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->weights[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t documents_lengthT = *(inbuffer + offset++);
      if(documents_lengthT > documents_length)
        this->documents = (uint8_t*)realloc(this->documents, documents_lengthT * sizeof(uint8_t));
      offset += 3;
      documents_length = documents_lengthT;
      for( uint8_t i = 0; i < documents_length; i++){
      this->st_documents =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_documents);
        memcpy( &(this->documents[i]), &(this->st_documents), sizeof(uint8_t));
      }
      uint8_t tree_lengthT = *(inbuffer + offset++);
      if(tree_lengthT > tree_length)
        this->tree = (uint8_t*)realloc(this->tree, tree_lengthT * sizeof(uint8_t));
      offset += 3;
      tree_length = tree_lengthT;
      for( uint8_t i = 0; i < tree_length; i++){
      this->st_tree =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_tree);
        memcpy( &(this->tree[i]), &(this->st_tree), sizeof(uint8_t));
      }
      uint8_t weights_lengthT = *(inbuffer + offset++);
      if(weights_lengthT > weights_length)
        this->weights = (uint8_t*)realloc(this->weights, weights_lengthT * sizeof(uint8_t));
      offset += 3;
      weights_length = weights_lengthT;
      for( uint8_t i = 0; i < weights_length; i++){
      this->st_weights =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_weights);
        memcpy( &(this->weights[i]), &(this->st_weights), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/VisualLocDB"; };
    const char * getMD5(){ return "ecd1514e0345ae95252fcd0c3269725c"; };

  };

}
#endif