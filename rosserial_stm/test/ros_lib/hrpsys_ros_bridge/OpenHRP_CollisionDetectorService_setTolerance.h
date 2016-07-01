#ifndef _ROS_SERVICE_OpenHRP_CollisionDetectorService_setTolerance_h
#define _ROS_SERVICE_OpenHRP_CollisionDetectorService_setTolerance_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE[] = "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_setTolerance";

  class OpenHRP_CollisionDetectorService_setToleranceRequest : public ros::Msg
  {
    public:
      const char* link_pair_name;
      double tolerance;

    OpenHRP_CollisionDetectorService_setToleranceRequest():
      link_pair_name(""),
      tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_pair_name = strlen(this->link_pair_name);
      memcpy(outbuffer + offset, &length_link_pair_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_pair_name, length_link_pair_name);
      offset += length_link_pair_name;
      union {
        double real;
        uint64_t base;
      } u_tolerance;
      u_tolerance.real = this->tolerance;
      *(outbuffer + offset + 0) = (u_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_link_pair_name;
      memcpy(&length_link_pair_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_pair_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_pair_name-1]=0;
      this->link_pair_name = (char *)(inbuffer + offset-1);
      offset += length_link_pair_name;
      union {
        double real;
        uint64_t base;
      } u_tolerance;
      u_tolerance.base = 0;
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->tolerance = u_tolerance.real;
      offset += sizeof(this->tolerance);
     return offset;
    }

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE; };
    const char * getMD5(){ return "454672d6fa714d34c7d2963712d4bbe5"; };

  };

  class OpenHRP_CollisionDetectorService_setToleranceResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_CollisionDetectorService_setToleranceResponse():
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

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_CollisionDetectorService_setTolerance {
    public:
    typedef OpenHRP_CollisionDetectorService_setToleranceRequest Request;
    typedef OpenHRP_CollisionDetectorService_setToleranceResponse Response;
  };

}
#endif
