#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_Footstep_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_Footstep_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_Footstep : public ros::Msg
  {
    public:
      double pos[3];
      double rot[4];
      const char* leg;

    OpenHRP_AutoBalancerService_Footstep():
      pos(),
      rot(),
      leg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_posi;
      u_posi.real = this->pos[i];
      *(outbuffer + offset + 0) = (u_posi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_posi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_posi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_posi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_posi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_posi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_posi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_posi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pos[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_roti;
      u_roti.real = this->rot[i];
      *(outbuffer + offset + 0) = (u_roti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_roti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_roti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_roti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_roti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_roti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_roti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_roti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rot[i]);
      }
      uint32_t length_leg = strlen(this->leg);
      memcpy(outbuffer + offset, &length_leg, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->leg, length_leg);
      offset += length_leg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_posi;
      u_posi.base = 0;
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_posi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pos[i] = u_posi.real;
      offset += sizeof(this->pos[i]);
      }
      for( uint8_t i = 0; i < 4; i++){
      union {
        double real;
        uint64_t base;
      } u_roti;
      u_roti.base = 0;
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_roti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rot[i] = u_roti.real;
      offset += sizeof(this->rot[i]);
      }
      uint32_t length_leg;
      memcpy(&length_leg, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_leg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_leg-1]=0;
      this->leg = (char *)(inbuffer + offset-1);
      offset += length_leg;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep"; };
    const char * getMD5(){ return "f65a0e5bbf029cf10add63f7ae123997"; };

  };

}
#endif