#ifndef _ROS_SERVICE_RequireLog_h
#define _ROS_SERVICE_RequireLog_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_footstep_controller
{

static const char REQUIRELOG[] = "jsk_footstep_controller/RequireLog";

  class RequireLogRequest : public ros::Msg
  {
    public:

    RequireLogRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return REQUIRELOG; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class RequireLogResponse : public ros::Msg
  {
    public:
      const char* sexp;

    RequireLogResponse():
      sexp("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_sexp = strlen(this->sexp);
      memcpy(outbuffer + offset, &length_sexp, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->sexp, length_sexp);
      offset += length_sexp;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_sexp;
      memcpy(&length_sexp, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sexp; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sexp-1]=0;
      this->sexp = (char *)(inbuffer + offset-1);
      offset += length_sexp;
     return offset;
    }

    const char * getType(){ return REQUIRELOG; };
    const char * getMD5(){ return "29db591ef5f8291f316c2b168fcbe017"; };

  };

  class RequireLog {
    public:
    typedef RequireLogRequest Request;
    typedef RequireLogResponse Response;
  };

}
#endif
