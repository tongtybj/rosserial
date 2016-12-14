#ifndef _ROS_dji_sdk_FlightControlInfo_h
#define _ROS_dji_sdk_FlightControlInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dji_sdk
{

  class FlightControlInfo : public ros::Msg
  {
    public:
      uint8_t control_mode;
      uint8_t cur_ctrl_dev_in_navi_mode;
      uint8_t serial_req_status;
      uint8_t virtual_rc_status;

    FlightControlInfo():
      control_mode(0),
      cur_ctrl_dev_in_navi_mode(0),
      serial_req_status(0),
      virtual_rc_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->control_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_mode);
      *(outbuffer + offset + 0) = (this->cur_ctrl_dev_in_navi_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cur_ctrl_dev_in_navi_mode);
      *(outbuffer + offset + 0) = (this->serial_req_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->serial_req_status);
      *(outbuffer + offset + 0) = (this->virtual_rc_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->virtual_rc_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->control_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_mode);
      this->cur_ctrl_dev_in_navi_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cur_ctrl_dev_in_navi_mode);
      this->serial_req_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->serial_req_status);
      this->virtual_rc_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->virtual_rc_status);
     return offset;
    }

    const char * getType(){ return "dji_sdk/FlightControlInfo"; };
    const char * getMD5(){ return "943648dc47db23e3c3071c5427b1db2b"; };

  };

}
#endif