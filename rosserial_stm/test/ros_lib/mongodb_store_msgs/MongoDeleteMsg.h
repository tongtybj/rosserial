#ifndef _ROS_SERVICE_MongoDeleteMsg_h
#define _ROS_SERVICE_MongoDeleteMsg_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mongodb_store_msgs
{

static const char MONGODELETEMSG[] = "mongodb_store_msgs/MongoDeleteMsg";

  class MongoDeleteMsgRequest : public ros::Msg
  {
    public:
      const char* database;
      const char* collection;
      const char* document_id;

    MongoDeleteMsgRequest():
      database(""),
      collection(""),
      document_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_database = strlen(this->database);
      memcpy(outbuffer + offset, &length_database, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->database, length_database);
      offset += length_database;
      uint32_t length_collection = strlen(this->collection);
      memcpy(outbuffer + offset, &length_collection, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->collection, length_collection);
      offset += length_collection;
      uint32_t length_document_id = strlen(this->document_id);
      memcpy(outbuffer + offset, &length_document_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->document_id, length_document_id);
      offset += length_document_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_database;
      memcpy(&length_database, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_database; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_database-1]=0;
      this->database = (char *)(inbuffer + offset-1);
      offset += length_database;
      uint32_t length_collection;
      memcpy(&length_collection, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collection; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collection-1]=0;
      this->collection = (char *)(inbuffer + offset-1);
      offset += length_collection;
      uint32_t length_document_id;
      memcpy(&length_document_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_document_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_document_id-1]=0;
      this->document_id = (char *)(inbuffer + offset-1);
      offset += length_document_id;
     return offset;
    }

    const char * getType(){ return MONGODELETEMSG; };
    const char * getMD5(){ return "8db26da88c264ed1aced8ce3427e0db0"; };

  };

  class MongoDeleteMsgResponse : public ros::Msg
  {
    public:
      bool success;

    MongoDeleteMsgResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return MONGODELETEMSG; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class MongoDeleteMsg {
    public:
    typedef MongoDeleteMsgRequest Request;
    typedef MongoDeleteMsgResponse Response;
  };

}
#endif
