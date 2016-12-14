#ifndef _ROS_pddl_msgs_PDDLAction_h
#define _ROS_pddl_msgs_PDDLAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pddl_msgs
{

  class PDDLAction : public ros::Msg
  {
    public:
      const char* name;
      const char* parameters;
      const char* precondition;
      const char* effect;
      const char* on_condition;
      const char* action_duration;

    PDDLAction():
      name(""),
      parameters(""),
      precondition(""),
      effect(""),
      on_condition(""),
      action_duration("")
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
      uint32_t length_parameters = strlen(this->parameters);
      memcpy(outbuffer + offset, &length_parameters, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->parameters, length_parameters);
      offset += length_parameters;
      uint32_t length_precondition = strlen(this->precondition);
      memcpy(outbuffer + offset, &length_precondition, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->precondition, length_precondition);
      offset += length_precondition;
      uint32_t length_effect = strlen(this->effect);
      memcpy(outbuffer + offset, &length_effect, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->effect, length_effect);
      offset += length_effect;
      uint32_t length_on_condition = strlen(this->on_condition);
      memcpy(outbuffer + offset, &length_on_condition, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->on_condition, length_on_condition);
      offset += length_on_condition;
      uint32_t length_action_duration = strlen(this->action_duration);
      memcpy(outbuffer + offset, &length_action_duration, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->action_duration, length_action_duration);
      offset += length_action_duration;
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
      uint32_t length_parameters;
      memcpy(&length_parameters, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameters; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameters-1]=0;
      this->parameters = (char *)(inbuffer + offset-1);
      offset += length_parameters;
      uint32_t length_precondition;
      memcpy(&length_precondition, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_precondition; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_precondition-1]=0;
      this->precondition = (char *)(inbuffer + offset-1);
      offset += length_precondition;
      uint32_t length_effect;
      memcpy(&length_effect, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_effect; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_effect-1]=0;
      this->effect = (char *)(inbuffer + offset-1);
      offset += length_effect;
      uint32_t length_on_condition;
      memcpy(&length_on_condition, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_on_condition; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_on_condition-1]=0;
      this->on_condition = (char *)(inbuffer + offset-1);
      offset += length_on_condition;
      uint32_t length_action_duration;
      memcpy(&length_action_duration, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_action_duration; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_action_duration-1]=0;
      this->action_duration = (char *)(inbuffer + offset-1);
      offset += length_action_duration;
     return offset;
    }

    const char * getType(){ return "pddl_msgs/PDDLAction"; };
    const char * getMD5(){ return "b7889bb912b39c8d55cfbda20fd28a0a"; };

  };

}
#endif