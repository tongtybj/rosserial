#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_readDigitalInput_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_readDigitalInput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_READDIGITALINPUT[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_readDigitalInput";

  class OpenHRP_RobotHardwareService_readDigitalInputRequest : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_readDigitalInputRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_READDIGITALINPUT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_readDigitalInputResponse : public ros::Msg
  {
    public:
      bool operation_return;
      uint8_t din_length;
      uint8_t st_din;
      uint8_t * din;

    OpenHRP_RobotHardwareService_readDigitalInputResponse():
      operation_return(0),
      din_length(0), din(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      *(outbuffer + offset++) = din_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < din_length; i++){
      *(outbuffer + offset + 0) = (this->din[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->din[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
      uint8_t din_lengthT = *(inbuffer + offset++);
      if(din_lengthT > din_length)
        this->din = (uint8_t*)realloc(this->din, din_lengthT * sizeof(uint8_t));
      offset += 3;
      din_length = din_lengthT;
      for( uint8_t i = 0; i < din_length; i++){
      this->st_din =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_din);
        memcpy( &(this->din[i]), &(this->st_din), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_READDIGITALINPUT; };
    const char * getMD5(){ return "e3afb3b596ca4ee32072d4200ab0872e"; };

  };

  class OpenHRP_RobotHardwareService_readDigitalInput {
    public:
    typedef OpenHRP_RobotHardwareService_readDigitalInputRequest Request;
    typedef OpenHRP_RobotHardwareService_readDigitalInputResponse Response;
  };

}
#endif
