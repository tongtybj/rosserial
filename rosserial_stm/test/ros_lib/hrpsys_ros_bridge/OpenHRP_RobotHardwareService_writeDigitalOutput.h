#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_writeDigitalOutput_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_writeDigitalOutput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_WRITEDIGITALOUTPUT[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_writeDigitalOutput";

  class OpenHRP_RobotHardwareService_writeDigitalOutputRequest : public ros::Msg
  {
    public:
      uint8_t dout_length;
      uint8_t st_dout;
      uint8_t * dout;

    OpenHRP_RobotHardwareService_writeDigitalOutputRequest():
      dout_length(0), dout(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = dout_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < dout_length; i++){
      *(outbuffer + offset + 0) = (this->dout[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dout[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t dout_lengthT = *(inbuffer + offset++);
      if(dout_lengthT > dout_length)
        this->dout = (uint8_t*)realloc(this->dout, dout_lengthT * sizeof(uint8_t));
      offset += 3;
      dout_length = dout_lengthT;
      for( uint8_t i = 0; i < dout_length; i++){
      this->st_dout =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_dout);
        memcpy( &(this->dout[i]), &(this->st_dout), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_WRITEDIGITALOUTPUT; };
    const char * getMD5(){ return "9048f01466a2c607fe6214787058b321"; };

  };

  class OpenHRP_RobotHardwareService_writeDigitalOutputResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_RobotHardwareService_writeDigitalOutputResponse():
      operation_return(0)
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
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_WRITEDIGITALOUTPUT; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_RobotHardwareService_writeDigitalOutput {
    public:
    typedef OpenHRP_RobotHardwareService_writeDigitalOutputRequest Request;
    typedef OpenHRP_RobotHardwareService_writeDigitalOutputResponse Response;
  };

}
#endif
