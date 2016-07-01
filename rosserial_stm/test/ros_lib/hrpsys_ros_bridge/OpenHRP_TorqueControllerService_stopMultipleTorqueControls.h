#ifndef _ROS_SERVICE_OpenHRP_TorqueControllerService_stopMultipleTorqueControls_h
#define _ROS_SERVICE_OpenHRP_TorqueControllerService_stopMultipleTorqueControls_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_TORQUECONTROLLERSERVICE_STOPMULTIPLETORQUECONTROLS[] = "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_stopMultipleTorqueControls";

  class OpenHRP_TorqueControllerService_stopMultipleTorqueControlsRequest : public ros::Msg
  {
    public:
      uint8_t jnames_length;
      char* st_jnames;
      char* * jnames;

    OpenHRP_TorqueControllerService_stopMultipleTorqueControlsRequest():
      jnames_length(0), jnames(NULL)
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
     return offset;
    }

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_STOPMULTIPLETORQUECONTROLS; };
    const char * getMD5(){ return "2ced7fdc11680dafdfdf754b59114e73"; };

  };

  class OpenHRP_TorqueControllerService_stopMultipleTorqueControlsResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_TorqueControllerService_stopMultipleTorqueControlsResponse():
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

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_STOPMULTIPLETORQUECONTROLS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_TorqueControllerService_stopMultipleTorqueControls {
    public:
    typedef OpenHRP_TorqueControllerService_stopMultipleTorqueControlsRequest Request;
    typedef OpenHRP_TorqueControllerService_stopMultipleTorqueControlsResponse Response;
  };

}
#endif
