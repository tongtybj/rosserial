#ifndef _ROS_dji_sdk_MissionEventWpAction_h
#define _ROS_dji_sdk_MissionEventWpAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionEventWpAction : public ros::Msg
  {
    public:
      uint8_t incident_type;
      uint8_t repeat;

    MissionEventWpAction():
      incident_type(0),
      repeat(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->incident_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->incident_type);
      *(outbuffer + offset + 0) = (this->repeat >> (8 * 0)) & 0xFF;
      offset += sizeof(this->repeat);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->incident_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->incident_type);
      this->repeat =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->repeat);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionEventWpAction"; };
    const char * getMD5(){ return "feb2e4aeb62859a1aee7828f09a4a6a3"; };

  };

}
#endif