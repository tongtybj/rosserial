#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_startAutoBalancer_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_startAutoBalancer_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_STARTAUTOBALANCER[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_startAutoBalancer";

  class OpenHRP_AutoBalancerService_startAutoBalancerRequest : public ros::Msg
  {
    public:
      uint8_t limbs_length;
      char* st_limbs;
      char* * limbs;

    OpenHRP_AutoBalancerService_startAutoBalancerRequest():
      limbs_length(0), limbs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = limbs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < limbs_length; i++){
      uint32_t length_limbsi = strlen(this->limbs[i]);
      memcpy(outbuffer + offset, &length_limbsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->limbs[i], length_limbsi);
      offset += length_limbsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t limbs_lengthT = *(inbuffer + offset++);
      if(limbs_lengthT > limbs_length)
        this->limbs = (char**)realloc(this->limbs, limbs_lengthT * sizeof(char*));
      offset += 3;
      limbs_length = limbs_lengthT;
      for( uint8_t i = 0; i < limbs_length; i++){
      uint32_t length_st_limbs;
      memcpy(&length_st_limbs, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_limbs; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_limbs-1]=0;
      this->st_limbs = (char *)(inbuffer + offset-1);
      offset += length_st_limbs;
        memcpy( &(this->limbs[i]), &(this->st_limbs), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_STARTAUTOBALANCER; };
    const char * getMD5(){ return "53ab9d5d128ef63573d7493afb16e721"; };

  };

  class OpenHRP_AutoBalancerService_startAutoBalancerResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_AutoBalancerService_startAutoBalancerResponse():
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

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_STARTAUTOBALANCER; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AutoBalancerService_startAutoBalancer {
    public:
    typedef OpenHRP_AutoBalancerService_startAutoBalancerRequest Request;
    typedef OpenHRP_AutoBalancerService_startAutoBalancerResponse Response;
  };

}
#endif
