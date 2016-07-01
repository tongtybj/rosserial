#ifndef _ROS_SERVICE_Query_h
#define _ROS_SERVICE_Query_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "bayesian_belief_networks/Observation.h"
#include "bayesian_belief_networks/Result.h"

namespace bayesian_belief_networks
{

static const char QUERY[] = "bayesian_belief_networks/Query";

  class QueryRequest : public ros::Msg
  {
    public:
      uint8_t query_length;
      bayesian_belief_networks::Observation st_query;
      bayesian_belief_networks::Observation * query;

    QueryRequest():
      query_length(0), query(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = query_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < query_length; i++){
      offset += this->query[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t query_lengthT = *(inbuffer + offset++);
      if(query_lengthT > query_length)
        this->query = (bayesian_belief_networks::Observation*)realloc(this->query, query_lengthT * sizeof(bayesian_belief_networks::Observation));
      offset += 3;
      query_length = query_lengthT;
      for( uint8_t i = 0; i < query_length; i++){
      offset += this->st_query.deserialize(inbuffer + offset);
        memcpy( &(this->query[i]), &(this->st_query), sizeof(bayesian_belief_networks::Observation));
      }
     return offset;
    }

    const char * getType(){ return QUERY; };
    const char * getMD5(){ return "c82ad1bda0500c7fa7fed33d8deb2a3f"; };

  };

  class QueryResponse : public ros::Msg
  {
    public:
      uint8_t results_length;
      bayesian_belief_networks::Result st_results;
      bayesian_belief_networks::Result * results;

    QueryResponse():
      results_length(0), results(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = results_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < results_length; i++){
      offset += this->results[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t results_lengthT = *(inbuffer + offset++);
      if(results_lengthT > results_length)
        this->results = (bayesian_belief_networks::Result*)realloc(this->results, results_lengthT * sizeof(bayesian_belief_networks::Result));
      offset += 3;
      results_length = results_lengthT;
      for( uint8_t i = 0; i < results_length; i++){
      offset += this->st_results.deserialize(inbuffer + offset);
        memcpy( &(this->results[i]), &(this->st_results), sizeof(bayesian_belief_networks::Result));
      }
     return offset;
    }

    const char * getType(){ return QUERY; };
    const char * getMD5(){ return "f41c31876c3be91ef922fc26aa614079"; };

  };

  class Query {
    public:
    typedef QueryRequest Request;
    typedef QueryResponse Response;
  };

}
#endif
