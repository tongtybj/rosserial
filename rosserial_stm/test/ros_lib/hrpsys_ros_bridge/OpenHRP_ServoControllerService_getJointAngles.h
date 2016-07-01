#ifndef _ROS_SERVICE_OpenHRP_ServoControllerService_getJointAngles_h
#define _ROS_SERVICE_OpenHRP_ServoControllerService_getJointAngles_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SERVOCONTROLLERSERVICE_GETJOINTANGLES[] = "hrpsys_ros_bridge/OpenHRP_ServoControllerService_getJointAngles";

  class OpenHRP_ServoControllerService_getJointAnglesRequest : public ros::Msg
  {
    public:

    OpenHRP_ServoControllerService_getJointAnglesRequest()
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

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_GETJOINTANGLES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ServoControllerService_getJointAnglesResponse : public ros::Msg
  {
    public:
      bool operation_return;
      uint8_t jvs_length;
      double st_jvs;
      double * jvs;

    OpenHRP_ServoControllerService_getJointAnglesResponse():
      operation_return(0),
      jvs_length(0), jvs(NULL)
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
      *(outbuffer + offset++) = jvs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < jvs_length; i++){
      union {
        double real;
        uint64_t base;
      } u_jvsi;
      u_jvsi.real = this->jvs[i];
      *(outbuffer + offset + 0) = (u_jvsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jvsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jvsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jvsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_jvsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_jvsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_jvsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_jvsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->jvs[i]);
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
      uint8_t jvs_lengthT = *(inbuffer + offset++);
      if(jvs_lengthT > jvs_length)
        this->jvs = (double*)realloc(this->jvs, jvs_lengthT * sizeof(double));
      offset += 3;
      jvs_length = jvs_lengthT;
      for( uint8_t i = 0; i < jvs_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_jvs;
      u_st_jvs.base = 0;
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_jvs.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_jvs = u_st_jvs.real;
      offset += sizeof(this->st_jvs);
        memcpy( &(this->jvs[i]), &(this->st_jvs), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_GETJOINTANGLES; };
    const char * getMD5(){ return "4fdfe079ef20ee48e9fab4471d91dd87"; };

  };

  class OpenHRP_ServoControllerService_getJointAngles {
    public:
    typedef OpenHRP_ServoControllerService_getJointAnglesRequest Request;
    typedef OpenHRP_ServoControllerService_getJointAnglesResponse Response;
  };

}
#endif
