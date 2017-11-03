#ifndef _ROS_hydrus_ServoStates_h
#define _ROS_hydrus_ServoStates_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "hydrus/ServoState.h"

namespace hydrus
{

  class ServoStates : public ros::Msg
  {
    public:
      ros::Time stamp;
      uint8_t servos_length;
      hydrus::ServoState st_servos;
      hydrus::ServoState * servos;

    ServoStates():
      stamp(),
      servos_length(0), servos(NULL)
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
      *(outbuffer + offset++) = servos_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < servos_length; i++){
      offset += this->servos[i].serialize(outbuffer + offset);
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
      uint8_t servos_lengthT = *(inbuffer + offset++);
      if(servos_lengthT > servos_length)
        this->servos = (hydrus::ServoState*)realloc(this->servos, servos_lengthT * sizeof(hydrus::ServoState));
      offset += 3;
      servos_length = servos_lengthT;
      for( uint8_t i = 0; i < servos_length; i++){
      offset += this->st_servos.deserialize(inbuffer + offset);
        memcpy( &(this->servos[i]), &(this->st_servos), sizeof(hydrus::ServoState));
      }
     return offset;
    }

    const char * getType(){ return "hydrus/ServoStates"; };
    const char * getMD5(){ return "6d1b17de249ae8c57df97782f91fe8e0"; };

  };

}
#endif