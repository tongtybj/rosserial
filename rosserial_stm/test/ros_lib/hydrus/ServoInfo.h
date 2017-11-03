#ifndef _ROS_hydrus_ServoInfo_h
#define _ROS_hydrus_ServoInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus
{

  class ServoInfo : public ros::Msg
  {
    public:
      uint8_t id;
      uint16_t p_gain;
      uint16_t i_gain;
      uint16_t d_gain;
      uint16_t profile_velocity;
      uint16_t current_limit;
      uint8_t send_data_flag;

    ServoInfo():
      id(0),
      p_gain(0),
      i_gain(0),
      d_gain(0),
      profile_velocity(0),
      current_limit(0),
      send_data_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->p_gain >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->p_gain >> (8 * 1)) & 0xFF;
      offset += sizeof(this->p_gain);
      *(outbuffer + offset + 0) = (this->i_gain >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->i_gain >> (8 * 1)) & 0xFF;
      offset += sizeof(this->i_gain);
      *(outbuffer + offset + 0) = (this->d_gain >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->d_gain >> (8 * 1)) & 0xFF;
      offset += sizeof(this->d_gain);
      *(outbuffer + offset + 0) = (this->profile_velocity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->profile_velocity >> (8 * 1)) & 0xFF;
      offset += sizeof(this->profile_velocity);
      *(outbuffer + offset + 0) = (this->current_limit >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_limit >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current_limit);
      *(outbuffer + offset + 0) = (this->send_data_flag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->send_data_flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->p_gain =  ((uint16_t) (*(inbuffer + offset)));
      this->p_gain |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->p_gain);
      this->i_gain =  ((uint16_t) (*(inbuffer + offset)));
      this->i_gain |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->i_gain);
      this->d_gain =  ((uint16_t) (*(inbuffer + offset)));
      this->d_gain |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->d_gain);
      this->profile_velocity =  ((uint16_t) (*(inbuffer + offset)));
      this->profile_velocity |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->profile_velocity);
      this->current_limit =  ((uint16_t) (*(inbuffer + offset)));
      this->current_limit |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current_limit);
      this->send_data_flag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->send_data_flag);
     return offset;
    }

    const char * getType(){ return "hydrus/ServoInfo"; };
    const char * getMD5(){ return "21668015db58f1904477ca53012db120"; };

  };

}
#endif