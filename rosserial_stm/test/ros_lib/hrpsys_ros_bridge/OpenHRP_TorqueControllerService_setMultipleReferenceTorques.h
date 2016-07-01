#ifndef _ROS_SERVICE_OpenHRP_TorqueControllerService_setMultipleReferenceTorques_h
#define _ROS_SERVICE_OpenHRP_TorqueControllerService_setMultipleReferenceTorques_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_TORQUECONTROLLERSERVICE_SETMULTIPLEREFERENCETORQUES[] = "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_setMultipleReferenceTorques";

  class OpenHRP_TorqueControllerService_setMultipleReferenceTorquesRequest : public ros::Msg
  {
    public:
      uint8_t jnames_length;
      char* st_jnames;
      char* * jnames;
      uint8_t tauRefs_length;
      double st_tauRefs;
      double * tauRefs;

    OpenHRP_TorqueControllerService_setMultipleReferenceTorquesRequest():
      jnames_length(0), jnames(NULL),
      tauRefs_length(0), tauRefs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = jnames_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < jnames_length; i++){
      uint32_t length_jnamesi = strlen(this->jnames[i]);
      memcpy(outbuffer + offset, &length_jnamesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->jnames[i], length_jnamesi);
      offset += length_jnamesi;
      }
      *(outbuffer + offset++) = tauRefs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tauRefs_length; i++){
      union {
        double real;
        uint64_t base;
      } u_tauRefsi;
      u_tauRefsi.real = this->tauRefs[i];
      *(outbuffer + offset + 0) = (u_tauRefsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tauRefsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tauRefsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tauRefsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tauRefsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tauRefsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tauRefsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tauRefsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tauRefs[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t jnames_lengthT = *(inbuffer + offset++);
      if(jnames_lengthT > jnames_length)
        this->jnames = (char**)realloc(this->jnames, jnames_lengthT * sizeof(char*));
      offset += 3;
      jnames_length = jnames_lengthT;
      for( uint8_t i = 0; i < jnames_length; i++){
      uint32_t length_st_jnames;
      memcpy(&length_st_jnames, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_jnames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_jnames-1]=0;
      this->st_jnames = (char *)(inbuffer + offset-1);
      offset += length_st_jnames;
        memcpy( &(this->jnames[i]), &(this->st_jnames), sizeof(char*));
      }
      uint8_t tauRefs_lengthT = *(inbuffer + offset++);
      if(tauRefs_lengthT > tauRefs_length)
        this->tauRefs = (double*)realloc(this->tauRefs, tauRefs_lengthT * sizeof(double));
      offset += 3;
      tauRefs_length = tauRefs_lengthT;
      for( uint8_t i = 0; i < tauRefs_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_tauRefs;
      u_st_tauRefs.base = 0;
      u_st_tauRefs.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_tauRefs.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_tauRefs.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_tauRefs.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_tauRefs.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_tauRefs.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_tauRefs.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_tauRefs.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_tauRefs = u_st_tauRefs.real;
      offset += sizeof(this->st_tauRefs);
        memcpy( &(this->tauRefs[i]), &(this->st_tauRefs), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_SETMULTIPLEREFERENCETORQUES; };
    const char * getMD5(){ return "37e34055da81c1698ecfaa548536e25a"; };

  };

  class OpenHRP_TorqueControllerService_setMultipleReferenceTorquesResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_TorqueControllerService_setMultipleReferenceTorquesResponse():
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

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_SETMULTIPLEREFERENCETORQUES; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_TorqueControllerService_setMultipleReferenceTorques {
    public:
    typedef OpenHRP_TorqueControllerService_setMultipleReferenceTorquesRequest Request;
    typedef OpenHRP_TorqueControllerService_setMultipleReferenceTorquesResponse Response;
  };

}
#endif
