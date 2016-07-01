#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_TwoDimensionVertex_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_TwoDimensionVertex_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_TwoDimensionVertex : public ros::Msg
  {
    public:
      double pos[2];

    OpenHRP_StabilizerService_TwoDimensionVertex():
      pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 2; i++){
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 2; i++){
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
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_TwoDimensionVertex"; };
    const char * getMD5(){ return "8d9688bdfa4b2786a249fae029b876f1"; };

  };

}
#endif