#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setMaxIKError_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setMaxIKError_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKERROR[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setMaxIKError";

  class OpenHRP_SequencePlayerService_setMaxIKErrorRequest : public ros::Msg
  {
    public:
      double pos;
      double rot;

    OpenHRP_SequencePlayerService_setMaxIKErrorRequest():
      pos(0),
      rot(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_pos;
      u_pos.real = this->pos;
      *(outbuffer + offset + 0) = (u_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pos.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pos.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pos.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pos.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos);
      union {
        double real;
        uint64_t base;
      } u_rot;
      u_rot.real = this->rot;
      *(outbuffer + offset + 0) = (u_rot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rot.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rot.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rot.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rot.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rot.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rot);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_pos;
      u_pos.base = 0;
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pos.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pos = u_pos.real;
      offset += sizeof(this->pos);
      union {
        double real;
        uint64_t base;
      } u_rot;
      u_rot.base = 0;
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rot.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rot = u_rot.real;
      offset += sizeof(this->rot);
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKERROR; };
    const char * getMD5(){ return "3c6bfe875826b548627fa31630e69ef4"; };

  };

  class OpenHRP_SequencePlayerService_setMaxIKErrorResponse : public ros::Msg
  {
    public:

    OpenHRP_SequencePlayerService_setMaxIKErrorResponse()
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETMAXIKERROR; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_SequencePlayerService_setMaxIKError {
    public:
    typedef OpenHRP_SequencePlayerService_setMaxIKErrorRequest Request;
    typedef OpenHRP_SequencePlayerService_setMaxIKErrorResponse Response;
  };

}
#endif
