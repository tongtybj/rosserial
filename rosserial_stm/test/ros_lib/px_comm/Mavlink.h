#ifndef _ROS_px_comm_Mavlink_h
#define _ROS_px_comm_Mavlink_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace px_comm
{

  class Mavlink : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t len;
      uint8_t seq;
      uint8_t sysid;
      uint8_t compid;
      uint8_t msgid;
      bool fromlcm;
      uint8_t payload64_length;
      uint64_t st_payload64;
      uint64_t * payload64;

    Mavlink():
      header(),
      len(0),
      seq(0),
      sysid(0),
      compid(0),
      msgid(0),
      fromlcm(0),
      payload64_length(0), payload64(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->len >> (8 * 0)) & 0xFF;
      offset += sizeof(this->len);
      *(outbuffer + offset + 0) = (this->seq >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seq);
      *(outbuffer + offset + 0) = (this->sysid >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sysid);
      *(outbuffer + offset + 0) = (this->compid >> (8 * 0)) & 0xFF;
      offset += sizeof(this->compid);
      *(outbuffer + offset + 0) = (this->msgid >> (8 * 0)) & 0xFF;
      offset += sizeof(this->msgid);
      union {
        bool real;
        uint8_t base;
      } u_fromlcm;
      u_fromlcm.real = this->fromlcm;
      *(outbuffer + offset + 0) = (u_fromlcm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fromlcm);
      *(outbuffer + offset++) = payload64_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < payload64_length; i++){
      *(outbuffer + offset + 0) = (this->payload64[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->payload64[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->payload64[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->payload64[i] >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->payload64[i] >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->payload64[i] >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->payload64[i] >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->payload64[i] >> (8 * 7)) & 0xFF;
      offset += sizeof(this->payload64[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->len =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->len);
      this->seq =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->seq);
      this->sysid =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sysid);
      this->compid =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->compid);
      this->msgid =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->msgid);
      union {
        bool real;
        uint8_t base;
      } u_fromlcm;
      u_fromlcm.base = 0;
      u_fromlcm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fromlcm = u_fromlcm.real;
      offset += sizeof(this->fromlcm);
      uint8_t payload64_lengthT = *(inbuffer + offset++);
      if(payload64_lengthT > payload64_length)
        this->payload64 = (uint64_t*)realloc(this->payload64, payload64_lengthT * sizeof(uint64_t));
      offset += 3;
      payload64_length = payload64_lengthT;
      for( uint8_t i = 0; i < payload64_length; i++){
      this->st_payload64 =  ((uint64_t) (*(inbuffer + offset)));
      this->st_payload64 |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_payload64 |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_payload64 |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_payload64 |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->st_payload64 |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->st_payload64 |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->st_payload64 |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->st_payload64);
        memcpy( &(this->payload64[i]), &(this->st_payload64), sizeof(uint64_t));
      }
     return offset;
    }

    const char * getType(){ return "px_comm/Mavlink"; };
    const char * getMD5(){ return "3513d96e87d97146fed4643086047ddd"; };

  };

}
#endif