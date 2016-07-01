#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StateHolderService_Command_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StateHolderService_Command_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StateHolderService_Command : public ros::Msg
  {
    public:
      uint8_t jointRefs_length;
      double st_jointRefs;
      double * jointRefs;
      uint8_t baseTransform_length;
      double st_baseTransform;
      double * baseTransform;
      uint8_t zmp_length;
      double st_zmp;
      double * zmp;

    OpenHRP_StateHolderService_Command():
      jointRefs_length(0), jointRefs(NULL),
      baseTransform_length(0), baseTransform(NULL),
      zmp_length(0), zmp(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = jointRefs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < jointRefs_length; i++){
      union {
        double real;
        uint64_t base;
      } u_jointRefsi;
      u_jointRefsi.real = this->jointRefs[i];
      *(outbuffer + offset + 0) = (u_jointRefsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_jointRefsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_jointRefsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_jointRefsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_jointRefsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_jointRefsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_jointRefsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_jointRefsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->jointRefs[i]);
      }
      *(outbuffer + offset++) = baseTransform_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < baseTransform_length; i++){
      union {
        double real;
        uint64_t base;
      } u_baseTransformi;
      u_baseTransformi.real = this->baseTransform[i];
      *(outbuffer + offset + 0) = (u_baseTransformi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_baseTransformi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_baseTransformi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_baseTransformi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_baseTransformi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_baseTransformi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_baseTransformi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_baseTransformi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->baseTransform[i]);
      }
      *(outbuffer + offset++) = zmp_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < zmp_length; i++){
      union {
        double real;
        uint64_t base;
      } u_zmpi;
      u_zmpi.real = this->zmp[i];
      *(outbuffer + offset + 0) = (u_zmpi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zmpi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zmpi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zmpi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_zmpi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_zmpi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_zmpi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_zmpi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->zmp[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t jointRefs_lengthT = *(inbuffer + offset++);
      if(jointRefs_lengthT > jointRefs_length)
        this->jointRefs = (double*)realloc(this->jointRefs, jointRefs_lengthT * sizeof(double));
      offset += 3;
      jointRefs_length = jointRefs_lengthT;
      for( uint8_t i = 0; i < jointRefs_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_jointRefs;
      u_st_jointRefs.base = 0;
      u_st_jointRefs.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_jointRefs.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_jointRefs.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_jointRefs.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_jointRefs.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_jointRefs.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_jointRefs.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_jointRefs.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_jointRefs = u_st_jointRefs.real;
      offset += sizeof(this->st_jointRefs);
        memcpy( &(this->jointRefs[i]), &(this->st_jointRefs), sizeof(double));
      }
      uint8_t baseTransform_lengthT = *(inbuffer + offset++);
      if(baseTransform_lengthT > baseTransform_length)
        this->baseTransform = (double*)realloc(this->baseTransform, baseTransform_lengthT * sizeof(double));
      offset += 3;
      baseTransform_length = baseTransform_lengthT;
      for( uint8_t i = 0; i < baseTransform_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_baseTransform;
      u_st_baseTransform.base = 0;
      u_st_baseTransform.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_baseTransform.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_baseTransform.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_baseTransform.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_baseTransform.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_baseTransform.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_baseTransform.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_baseTransform.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_baseTransform = u_st_baseTransform.real;
      offset += sizeof(this->st_baseTransform);
        memcpy( &(this->baseTransform[i]), &(this->st_baseTransform), sizeof(double));
      }
      uint8_t zmp_lengthT = *(inbuffer + offset++);
      if(zmp_lengthT > zmp_length)
        this->zmp = (double*)realloc(this->zmp, zmp_lengthT * sizeof(double));
      offset += 3;
      zmp_length = zmp_lengthT;
      for( uint8_t i = 0; i < zmp_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_zmp;
      u_st_zmp.base = 0;
      u_st_zmp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_zmp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_zmp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_zmp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_zmp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_zmp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_zmp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_zmp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_zmp = u_st_zmp.real;
      offset += sizeof(this->st_zmp);
        memcpy( &(this->zmp[i]), &(this->st_zmp), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StateHolderService_Command"; };
    const char * getMD5(){ return "c456a517c9c8704b756ab8fb10b08d6d"; };

  };

}
#endif