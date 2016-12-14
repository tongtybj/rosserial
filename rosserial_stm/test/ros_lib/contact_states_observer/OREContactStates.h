#ifndef _ROS_contact_states_observer_OREContactStates_h
#define _ROS_contact_states_observer_OREContactStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "contact_states_observer/OREContactState.h"

namespace contact_states_observer
{

  class OREContactStates : public ros::Msg
  {
    public:
      uint8_t contact_states_length;
      contact_states_observer::OREContactState st_contact_states;
      contact_states_observer::OREContactState * contact_states;

    OREContactStates():
      contact_states_length(0), contact_states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = contact_states_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < contact_states_length; i++){
      offset += this->contact_states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t contact_states_lengthT = *(inbuffer + offset++);
      if(contact_states_lengthT > contact_states_length)
        this->contact_states = (contact_states_observer::OREContactState*)realloc(this->contact_states, contact_states_lengthT * sizeof(contact_states_observer::OREContactState));
      offset += 3;
      contact_states_length = contact_states_lengthT;
      for( uint8_t i = 0; i < contact_states_length; i++){
      offset += this->st_contact_states.deserialize(inbuffer + offset);
        memcpy( &(this->contact_states[i]), &(this->st_contact_states), sizeof(contact_states_observer::OREContactState));
      }
     return offset;
    }

    const char * getType(){ return "contact_states_observer/OREContactStates"; };
    const char * getMD5(){ return "a8112ce7bf8a647bdb7f974b91f39304"; };

  };

}
#endif