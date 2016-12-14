#ifndef _ROS_SERVICE_MongoUpdate_h
#define _ROS_SERVICE_MongoUpdate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mongodb_store
{

static const char MONGOUPDATE[] = "mongodb_store/MongoUpdate";

  class MongoUpdateRequest : public ros::Msg
  {
    public:
      const char* db;
      const char* collection;
      const char* query;
      const char* update;

    MongoUpdateRequest():
      db(""),
      collection(""),
      query(""),
      update("")
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
      uint32_t length_update = strlen(this->update);
      memcpy(outbuffer + offset, &length_update, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->update, length_update);
      offset += length_update;
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
      uint32_t length_update;
      memcpy(&length_update, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_update; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_update-1]=0;
      this->update = (char *)(inbuffer + offset-1);
      offset += length_update;
     return offset;
    }

    const char * getType(){ return MONGOUPDATE; };
    const char * getMD5(){ return "2b149bc6a0fea76ae96dfb48fcf24065"; };

  };

  class MongoUpdateResponse : public ros::Msg
  {
    public:
      const char* result;

    MongoUpdateResponse():
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

    const char * getType(){ return MONGOUPDATE; };
    const char * getMD5(){ return "c22f2a1ed8654a0b365f1bb3f7ff2c0f"; };

  };

  class MongoUpdate {
    public:
    typedef MongoUpdateRequest Request;
    typedef MongoUpdateResponse Response;
  };

}
#endif
