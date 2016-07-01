#ifndef _ROS_SERVICE_OpenHRP_ServoControllerService_setJointAngle_h
#define _ROS_SERVICE_OpenHRP_ServoControllerService_setJointAngle_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SERVOCONTROLLERSERVICE_SETJOINTANGLE[] = "hrpsys_ros_bridge/OpenHRP_ServoControllerService_setJointAngle";

  class OpenHRP_ServoControllerService_setJointAngleRequest : public ros::Msg
  {
    public:
      int16_t id;
      double jv;
      double tm;

    OpenHRP_ServoControllerService_setJointAngleRequest():
      id(0),
      jv(0),
      tm(0)
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
      union {
        double real;
        uint64_t base;
      } u_jv;
      u_jv.real = this->jv;
      *(outbuffer + offset + 0) = (u_jv.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jv.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jv.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jv.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_jv.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_jv.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_jv.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_jv.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->jv);
      union {
        double real;
        uint64_t base;
      } u_tm;
      u_tm.real = this->tm;
      *(outbuffer + offset + 0) = (u_tm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tm.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tm.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tm.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tm.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tm.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tm);
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
      union {
        double real;
        uint64_t base;
      } u_jv;
      u_jv.base = 0;
      u_jv.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_jv.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_jv.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_jv.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_jv.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_jv.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_jv.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_jv.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->jv = u_jv.real;
      offset += sizeof(this->jv);
      union {
        double real;
        uint64_t base;
      } u_tm;
      u_tm.base = 0;
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->tm = u_tm.real;
      offset += sizeof(this->tm);
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_SETJOINTANGLE; };
    const char * getMD5(){ return "49959ccee40754b8f131a67ee1efa315"; };

  };

  class OpenHRP_ServoControllerService_setJointAngleResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_ServoControllerService_setJointAngleResponse():
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

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_SETJOINTANGLE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ServoControllerService_setJointAngle {
    public:
    typedef OpenHRP_ServoControllerService_setJointAngleRequest Request;
    typedef OpenHRP_ServoControllerService_setJointAngleResponse Response;
  };

}
#endif
