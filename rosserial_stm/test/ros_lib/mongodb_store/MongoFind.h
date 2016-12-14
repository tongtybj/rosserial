#ifndef _ROS_SERVICE_MongoFind_h
#define _ROS_SERVICE_MongoFind_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mongodb_store
{

static const char MONGOFIND[] = "mongodb_store/MongoFind";

  class MongoFindRequest : public ros::Msg
  {
    public:
      const char* db;
      const char* collection;
      const char* query;

    MongoFindRequest():
      db(""),
      collection(""),
      query("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_db = strlen(this->db);
      memcpy(outbuffer + offset, &length_db, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->db, length_db);
      offset += length_db;
      uint32_t length_collection = strlen(this->collection);
      memcpy(outbuffer + offset, &length_collection, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->collection, length_collection);
      offset += length_collection;
      uint32_t length_query = strlen(this->query);
      memcpy(outbuffer + offset, &length_query, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->query, length_query);
      offset += length_query;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_db;
      memcpy(&length_db, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_db; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_db-1]=0;
      this->db = (char *)(inbuffer + offset-1);
      offset += length_db;
      uint32_t length_collection;
      memcpy(&length_collection, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collection; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collection-1]=0;
      this->collection = (char *)(inbuffer + offset-1);
      offset += length_collection;
      uint32_t length_query;
      memcpy(&length_query, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_query; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_query-1]=0;
      this->query = (char *)(inbuffer + offset-1);
      offset += length_query;
     return offset;
    }

    const char * getType(){ return MONGOFIND; };
    const char * getMD5(){ return "bfbcacecc78c9fa4f520fc6e13cbb788"; };

  };

  class MongoFindResponse : public ros::Msg
  {
    public:
      const char* result;

    MongoFindResponse():
      result("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_result = strlen(this->result);
      memcpy(outbuffer + offset, &length_result, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result, length_result);
      offset += length_result;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_result;
      memcpy(&length_result, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result-1]=0;
      this->result = (char *)(inbuffer + offset-1);
      offset += length_result;
     return offset;
    }

    const char * getType(){ return MONGOFIND; };
    const char * getMD5(){ return "c22f2a1ed8654a0b365f1bb3f7ff2c0f"; };

  };

  class MongoFind {
    public:
    typedef MongoFindRequest Request;
    typedef MongoFindResponse Response;
  };

}
#endif
