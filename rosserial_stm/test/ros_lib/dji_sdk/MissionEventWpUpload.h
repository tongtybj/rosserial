#ifndef _ROS_dji_sdk_MissionEventWpUpload_h
#define _ROS_dji_sdk_MissionEventWpUpload_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class MissionEventWpUpload : public ros::Msg
  {
    public:
      uint8_t incident_type;
      uint8_t mission_valid;
      uint16_t estimated_runtime;

    MissionEventWpUpload():
      incident_type(0),
      mission_valid(0),
      estimated_runtime(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->incident_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->incident_type);
      *(outbuffer + offset + 0) = (this->mission_valid >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mission_valid);
      *(outbuffer + offset + 0) = (this->estimated_runtime >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->estimated_runtime >> (8 * 1)) & 0xFF;
      offset += sizeof(this->estimated_runtime);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->incident_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->incident_type);
      this->mission_valid =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mission_valid);
      this->estimated_runtime =  ((uint16_t) (*(inbuffer + offset)));
      this->estimated_runtime |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->estimated_runtime);
     return offset;
    }

    const char * getType(){ return "dji_sdk/MissionEventWpUpload"; };
    const char * getMD5(){ return "8bbd22d7335594c91d2500ae8d41ab36"; };

  };

}
#endif