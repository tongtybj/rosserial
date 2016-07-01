#ifndef _ROS_pal_control_msgs_ActuatorCurrentLimit_h
#define _ROS_pal_control_msgs_ActuatorCurrentLimit_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_control_msgs
{

  class ActuatorCurrentLimit : public ros::Msg
  {
    public:
      uint8_t actuator_names_length;
      char* st_actuator_names;
      char* * actuator_names;
      uint8_t current_limits_length;
      double st_current_limits;
      double * current_limits;

    ActuatorCurrentLimit():
      actuator_names_length(0), actuator_names(NULL),
      current_limits_length(0), current_limits(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = actuator_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < actuator_names_length; i++){
      uint32_t length_actuator_namesi = strlen(this->actuator_names[i]);
      memcpy(outbuffer + offset, &length_actuator_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->actuator_names[i], length_actuator_namesi);
      offset += length_actuator_namesi;
      }
      *(outbuffer + offset++) = current_limits_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < current_limits_length; i++){
      union {
        double real;
        uint64_t base;
      } u_current_limitsi;
      u_current_limitsi.real = this->current_limits[i];
      *(outbuffer + offset + 0) = (u_current_limitsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_limitsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_limitsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_limitsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_current_limitsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_current_limitsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_current_limitsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_current_limitsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current_limits[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t actuator_names_lengthT = *(inbuffer + offset++);
      if(actuator_names_lengthT > actuator_names_length)
        this->actuator_names = (char**)realloc(this->actuator_names, actuator_names_lengthT * sizeof(char*));
      offset += 3;
      actuator_names_length = actuator_names_lengthT;
      for( uint8_t i = 0; i < actuator_names_length; i++){
      uint32_t length_st_actuator_names;
      memcpy(&length_st_actuator_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_actuator_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_actuator_names-1]=0;
      this->st_actuator_names = (char *)(inbuffer + offset-1);
      offset += length_st_actuator_names;
        memcpy( &(this->actuator_names[i]), &(this->st_actuator_names), sizeof(char*));
      }
      uint8_t current_limits_lengthT = *(inbuffer + offset++);
      if(current_limits_lengthT > current_limits_length)
        this->current_limits = (double*)realloc(this->current_limits, current_limits_lengthT * sizeof(double));
      offset += 3;
      current_limits_length = current_limits_lengthT;
      for( uint8_t i = 0; i < current_limits_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_current_limits;
      u_st_current_limits.base = 0;
      u_st_current_limits.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_current_limits.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_current_limits.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_current_limits.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_current_limits.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_current_limits.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_current_limits.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_current_limits.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_current_limits = u_st_current_limits.real;
      offset += sizeof(this->st_current_limits);
        memcpy( &(this->current_limits[i]), &(this->st_current_limits), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "pal_control_msgs/ActuatorCurrentLimit"; };
    const char * getMD5(){ return "974a1b5c83bb8df5691c27dbd5b363bc"; };

  };

}
#endif