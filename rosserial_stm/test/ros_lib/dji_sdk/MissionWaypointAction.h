#ifndef _ROS_dji_sdk_MissionWaypointAction_h
#define _ROS_dji_sdk_MissionWaypointAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionWaypointAction : public ros::Msg
  {
    public:
      uint8_t action_repeat;
      uint8_t command_list[15];
      int16_t command_parameter[15];

    MissionWaypointAction():
      action_repeat(0),
      command_list(),
      command_parameter()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->action_repeat >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action_repeat);
      for( uint8_t i = 0; i < 15; i++){
      *(outbuffer + offset + 0) = (this->command_list[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command_list[i]);
      }
      for( uint8_t i = 0; i < 15; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_command_parameteri;
      u_command_parameteri.real = this->command_parameter[i];
      *(outbuffer + offset + 0) = (u_command_parameteri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command_parameteri.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->command_parameter[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->action_repeat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action_repeat);
      for( uint8_t i = 0; i < 15; i++){
      this->command_list[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command_list[i]);
      }
      for( uint8_t i = 0; i < 15; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_command_parameteri;
      u_command_parameteri.base = 0;
      u_command_parameteri.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command_parameteri.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->command_parameter[i] = u_command_parameteri.real;
      offset += sizeof(this->command_parameter[i]);
      }
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionWaypointAction"; };
    const char * getMD5(){ return "dc8a44f81cb941d4399400060a0a73d6"; };

  };

}
#endif