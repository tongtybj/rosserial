#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_servo_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_servo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_SERVO[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_servo";

  class OpenHRP_RobotHardwareService_servoRequest : public ros::Msg
  {
    public:
      const char* name;
      int64_t ss;

    OpenHRP_RobotHardwareService_servoRequest():
      name(""),
      ss(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        int64_t real;
        uint64_t base;
      } u_ss;
      u_ss.real = this->ss;
      *(outbuffer + offset + 0) = (u_ss.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ss.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ss.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ss.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ss.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ss.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ss.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ss.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ss);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        int64_t real;
        uint64_t base;
      } u_ss;
      u_ss.base = 0;
      u_ss.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ss.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ss.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ss.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ss.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ss.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ss.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ss.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ss = u_ss.real;
      offset += sizeof(this->ss);
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_SERVO; };
    const char * getMD5(){ return "2574fed196440a4e87f5a9e5448d26f0"; };

  };

  class OpenHRP_RobotHardwareService_servoResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_RobotHardwareService_servoResponse():
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_SERVO; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_RobotHardwareService_servo {
    public:
    typedef OpenHRP_RobotHardwareService_servoRequest Request;
    typedef OpenHRP_RobotHardwareService_servoResponse Response;
  };

}
#endif
