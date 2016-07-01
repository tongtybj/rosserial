#ifndef _ROS_SERVICE_OpenHRP_ForwardKinematicsService_getRelativeCurrentPosition_h
#define _ROS_SERVICE_OpenHRP_ForwardKinematicsService_getRelativeCurrentPosition_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_FORWARDKINEMATICSSERVICE_GETRELATIVECURRENTPOSITION[] = "hrpsys_ros_bridge/OpenHRP_ForwardKinematicsService_getRelativeCurrentPosition";

  class OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionRequest : public ros::Msg
  {
    public:
      const char* linknameFrom;
      const char* linknameTo;
      double target[3];

    OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionRequest():
      linknameFrom(""),
      linknameTo(""),
      target()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_linknameFrom = strlen(this->linknameFrom);
      memcpy(outbuffer + offset, &length_linknameFrom, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->linknameFrom, length_linknameFrom);
      offset += length_linknameFrom;
      uint32_t length_linknameTo = strlen(this->linknameTo);
      memcpy(outbuffer + offset, &length_linknameTo, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->linknameTo, length_linknameTo);
      offset += length_linknameTo;
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_targeti;
      u_targeti.real = this->target[i];
      *(outbuffer + offset + 0) = (u_targeti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_targeti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_targeti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_targeti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_targeti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_targeti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_targeti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_targeti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->target[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_linknameFrom;
      memcpy(&length_linknameFrom, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_linknameFrom; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_linknameFrom-1]=0;
      this->linknameFrom = (char *)(inbuffer + offset-1);
      offset += length_linknameFrom;
      uint32_t length_linknameTo;
      memcpy(&length_linknameTo, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_linknameTo; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_linknameTo-1]=0;
      this->linknameTo = (char *)(inbuffer + offset-1);
      offset += length_linknameTo;
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_targeti;
      u_targeti.base = 0;
      u_targeti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_targeti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_targeti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_targeti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_targeti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_targeti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_targeti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_targeti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->target[i] = u_targeti.real;
      offset += sizeof(this->target[i]);
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_FORWARDKINEMATICSSERVICE_GETRELATIVECURRENTPOSITION; };
    const char * getMD5(){ return "71ffb77f9db3e6c43c01ee2e02a001f0"; };

  };

  class OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionResponse : public ros::Msg
  {
    public:
      bool operation_return;
      double result[3];

    OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionResponse():
      operation_return(0),
      result()
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
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_resulti;
      u_resulti.real = this->result[i];
      *(outbuffer + offset + 0) = (u_resulti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resulti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resulti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resulti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_resulti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_resulti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_resulti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_resulti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->result[i]);
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
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_resulti;
      u_resulti.base = 0;
      u_resulti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resulti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resulti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resulti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_resulti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_resulti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_resulti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_resulti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->result[i] = u_resulti.real;
      offset += sizeof(this->result[i]);
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_FORWARDKINEMATICSSERVICE_GETRELATIVECURRENTPOSITION; };
    const char * getMD5(){ return "8c1d08e4e27c952291446d526b735f1d"; };

  };

  class OpenHRP_ForwardKinematicsService_getRelativeCurrentPosition {
    public:
    typedef OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionRequest Request;
    typedef OpenHRP_ForwardKinematicsService_getRelativeCurrentPositionResponse Response;
  };

}
#endif
