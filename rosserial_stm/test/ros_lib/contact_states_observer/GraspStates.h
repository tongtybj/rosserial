#ifndef _ROS_contact_states_observer_GraspStates_h
#define _ROS_contact_states_observer_GraspStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "contact_states_observer/GraspState.h"

namespace contact_states_observer
{

  class GraspStates : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t grasp_states_length;
      contact_states_observer::GraspState st_grasp_states;
      contact_states_observer::GraspState * grasp_states;

    GraspStates():
      header(),
      grasp_states_length(0), grasp_states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = grasp_states_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < grasp_states_length; i++){
      offset += this->grasp_states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t grasp_states_lengthT = *(inbuffer + offset++);
      if(grasp_states_lengthT > grasp_states_length)
        this->grasp_states = (contact_states_observer::GraspState*)realloc(this->grasp_states, grasp_states_lengthT * sizeof(contact_states_observer::GraspState));
      offset += 3;
      grasp_states_length = grasp_states_lengthT;
      for( uint8_t i = 0; i < grasp_states_length; i++){
      offset += this->st_grasp_states.deserialize(inbuffer + offset);
        memcpy( &(this->grasp_states[i]), &(this->st_grasp_states), sizeof(contact_states_observer::GraspState));
      }
     return offset;
    }

    const char * getType(){ return "contact_states_observer/GraspStates"; };
    const char * getMD5(){ return "7839478d9d01de618b1ed88458c3c69b"; };

  };

}
#endif