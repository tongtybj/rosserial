#ifndef _ROS_SERVICE_OpenHRP_ServoControllerService_getDuration_h
#define _ROS_SERVICE_OpenHRP_ServoControllerService_getDuration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SERVOCONTROLLERSERVICE_GETDURATION[] = "hrpsys_ros_bridge/OpenHRP_ServoControllerService_getDuration";

  class OpenHRP_ServoControllerService_getDurationRequest : public ros::Msg
  {
    public:
      int16_t id;

    OpenHRP_ServoControllerService_getDurationRequest():
      id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id = u_id.real;
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_GETDURATION; };
    const char * getMD5(){ return "83303829ff5167a112112db2bf7b7905"; };

  };

  class OpenHRP_ServoControllerService_getDurationResponse : public ros::Msg
  {
    public:
      bool operation_return;
      double duration;

    OpenHRP_ServoControllerService_getDurationResponse():
      operation_return(0),
      duration(0)
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
      union {
        double real;
        uint64_t base;
      } u_duration;
      u_duration.real = this->duration;
      *(outbuffer + offset + 0) = (u_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duration.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_duration.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_duration.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_duration.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_duration.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->duration);
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
      union {
        double real;
        uint64_t base;
      } u_duration;
      u_duration.base = 0;
      u_duration.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duration.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duration.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duration.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_duration.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_duration.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_duration.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_duration.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->duration = u_duration.real;
      offset += sizeof(this->duration);
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_GETDURATION; };
    const char * getMD5(){ return "c5f41a8084b3515fab9cda5e64452eb1"; };

  };

  class OpenHRP_ServoControllerService_getDuration {
    public:
    typedef OpenHRP_ServoControllerService_getDurationRequest Request;
    typedef OpenHRP_ServoControllerService_getDurationResponse Response;
  };

}
#endif
