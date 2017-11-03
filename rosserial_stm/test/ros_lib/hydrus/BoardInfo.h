#ifndef _ROS_hydrus_BoardInfo_h
#define _ROS_hydrus_BoardInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hydrus/ServoInfo.h"

namespace hydrus
{

  class BoardInfo : public ros::Msg
  {
    public:
      uint8_t slave_id;
      uint8_t imu_send_data_flag;
      uint8_t servos_length;
      hydrus::ServoInfo st_servos;
      hydrus::ServoInfo * servos;

    BoardInfo():
      slave_id(0),
      imu_send_data_flag(0),
      servos_length(0), servos(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->slave_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->slave_id);
      *(outbuffer + offset + 0) = (this->imu_send_data_flag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->imu_send_data_flag);
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
      this->slave_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->slave_id);
      this->imu_send_data_flag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->imu_send_data_flag);
      uint8_t servos_lengthT = *(inbuffer + offset++);
      if(servos_lengthT > servos_length)
        this->servos = (hydrus::ServoInfo*)realloc(this->servos, servos_lengthT * sizeof(hydrus::ServoInfo));
      offset += 3;
      servos_length = servos_lengthT;
      for( uint8_t i = 0; i < servos_length; i++){
      offset += this->st_servos.deserialize(inbuffer + offset);
        memcpy( &(this->servos[i]), &(this->st_servos), sizeof(hydrus::ServoInfo));
      }
     return offset;
    }

    const char * getType(){ return "hydrus/BoardInfo"; };
    const char * getMD5(){ return "708e0e388afb111a2b0b76f6a0528c18"; };

  };

}
#endif