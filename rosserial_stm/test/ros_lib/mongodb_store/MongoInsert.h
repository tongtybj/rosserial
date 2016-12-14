#ifndef _ROS_SERVICE_MongoInsert_h
#define _ROS_SERVICE_MongoInsert_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mongodb_store
{

static const char MONGOINSERT[] = "mongodb_store/MongoInsert";

  class MongoInsertRequest : public ros::Msg
  {
    public:
      const char* db;
      const char* collection;
      const char* document;

    MongoInsertRequest():
      db(""),
      collection(""),
      document("")
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
      uint32_t length_document = strlen(this->document);
      memcpy(outbuffer + offset, &length_document, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->document, length_document);
      offset += length_document;
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
      uint32_t length_document;
      memcpy(&length_document, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_document; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_document-1]=0;
      this->document = (char *)(inbuffer + offset-1);
      offset += length_document;
     return offset;
    }

    const char * getType(){ return MONGOINSERT; };
    const char * getMD5(){ return "370f65c72e031302f4aca6bcf64817f9"; };

  };

  class MongoInsertResponse : public ros::Msg
  {
    public:
      const char* result;

    MongoInsertResponse():
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

    const char * getType(){ return MONGOINSERT; };
    const char * getMD5(){ return "c22f2a1ed8654a0b365f1bb3f7ff2c0f"; };

  };

  class MongoInsert {
    public:
    typedef MongoInsertRequest Request;
    typedef MongoInsertResponse Response;
  };

}
#endif
