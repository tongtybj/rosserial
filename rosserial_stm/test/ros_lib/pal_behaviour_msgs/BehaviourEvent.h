#ifndef _ROS_SERVICE_BehaviourEvent_h
#define _ROS_SERVICE_BehaviourEvent_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_behaviour_msgs/BehaviourArgument.h"

namespace pal_behaviour_msgs
{

static const char BEHAVIOUREVENT[] = "pal_behaviour_msgs/BehaviourEvent";

  class BehaviourEventRequest : public ros::Msg
  {
    public:
      const char* name;
      uint8_t arguments_length;
      pal_behaviour_msgs::BehaviourArgument st_arguments;
      pal_behaviour_msgs::BehaviourArgument * arguments;

    BehaviourEventRequest():
      name(""),
      arguments_length(0), arguments(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset++) = arguments_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < arguments_length; i++){
      offset += this->arguments[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint8_t arguments_lengthT = *(inbuffer + offset++);
      if(arguments_lengthT > arguments_length)
        this->arguments = (pal_behaviour_msgs::BehaviourArgument*)realloc(this->arguments, arguments_lengthT * sizeof(pal_behaviour_msgs::BehaviourArgument));
      offset += 3;
      arguments_length = arguments_lengthT;
      for( uint8_t i = 0; i < arguments_length; i++){
      offset += this->st_arguments.deserialize(inbuffer + offset);
        memcpy( &(this->arguments[i]), &(this->st_arguments), sizeof(pal_behaviour_msgs::BehaviourArgument));
      }
     return offset;
    }

    const char * getType(){ return BEHAVIOUREVENT; };
    const char * getMD5(){ return "e79d496ead939847a2522e7338b0a011"; };

  };

  class BehaviourEventResponse : public ros::Msg
  {
    public:
      const char* response;

    BehaviourEventResponse():
      response("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_response = strlen(this->response);
      memcpy(outbuffer + offset, &length_response, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->response, length_response);
      offset += length_response;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_response;
      memcpy(&length_response, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response-1]=0;
      this->response = (char *)(inbuffer + offset-1);
      offset += length_response;
     return offset;
    }

    const char * getType(){ return BEHAVIOUREVENT; };
    const char * getMD5(){ return "6de314e2dc76fbff2b6244a6ad70b68d"; };

  };

  class BehaviourEvent {
    public:
    typedef BehaviourEventRequest Request;
    typedef BehaviourEventResponse Response;
  };

}
#endif
