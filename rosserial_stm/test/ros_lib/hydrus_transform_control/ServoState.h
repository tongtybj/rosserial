#ifndef _ROS_hydrus_transform_control_ServoState_h
#define _ROS_hydrus_transform_control_ServoState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace hydrus_transform_control
{

  class ServoState : public ros::Msg
  {
    public:
      ros::Time stamp;
      uint16_t angle[6];
      uint8_t temp[6];
      uint8_t load[6];
      uint8_t moving[6];
      uint8_t error[6];

    ServoState():
      stamp(),
      angle(),
      temp(),
      load(),
      moving(),
      error()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      for( uint8_t i = 0; i < 6; i++){
      *(outbuffer + offset + 0) = (this->angle[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angle[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->angle[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      *(outbuffer + offset + 0) = (this->temp[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temp[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      *(outbuffer + offset + 0) = (this->load[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->load[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      *(outbuffer + offset + 0) = (this->moving[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->moving[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      *(outbuffer + offset + 0) = (this->error[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      for( uint8_t i = 0; i < 6; i++){
      this->angle[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->angle[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->angle[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      this->temp[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->temp[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      this->load[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->load[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      this->moving[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->moving[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      this->error[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error[i]);
      }
     return offset;
    }

    const char * getType(){ return "hydrus_transform_control/ServoState"; };
    const char * getMD5(){ return "4144a415eba7b462db72a4cb1f55de6f"; };

  };

}
#endif