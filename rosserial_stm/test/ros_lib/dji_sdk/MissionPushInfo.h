#ifndef _ROS_dji_sdk_MissionPushInfo_h
#define _ROS_dji_sdk_MissionPushInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionPushInfo : public ros::Msg
  {
    public:
      uint8_t type;
      uint8_t data_1;
      uint8_t data_2;
      uint8_t data_3;
      uint8_t data_4;
      uint8_t data_5;

    MissionPushInfo():
      type(0),
      data_1(0),
      data_2(0),
      data_3(0),
      data_4(0),
      data_5(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->data_1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_1);
      *(outbuffer + offset + 0) = (this->data_2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_2);
      *(outbuffer + offset + 0) = (this->data_3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_3);
      *(outbuffer + offset + 0) = (this->data_4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_4);
      *(outbuffer + offset + 0) = (this->data_5 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_5);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->data_1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data_1);
      this->data_2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data_2);
      this->data_3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data_3);
      this->data_4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data_4);
      this->data_5 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data_5);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionPushInfo"; };
    const char * getMD5(){ return "a520776ca6060b527ddc1be33a700532"; };

  };

}
#endif