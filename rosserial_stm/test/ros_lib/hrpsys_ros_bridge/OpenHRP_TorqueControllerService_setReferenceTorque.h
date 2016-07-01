#ifndef _ROS_SERVICE_OpenHRP_TorqueControllerService_setReferenceTorque_h
#define _ROS_SERVICE_OpenHRP_TorqueControllerService_setReferenceTorque_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE[] = "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_setReferenceTorque";

  class OpenHRP_TorqueControllerService_setReferenceTorqueRequest : public ros::Msg
  {
    public:
      const char* jname;
      double tauRef;

    OpenHRP_TorqueControllerService_setReferenceTorqueRequest():
      jname(""),
      tauRef(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_jname = strlen(this->jname);
      memcpy(outbuffer + offset, &length_jname, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->jname, length_jname);
      offset += length_jname;
      union {
        double real;
        uint64_t base;
      } u_tauRef;
      u_tauRef.real = this->tauRef;
      *(outbuffer + offset + 0) = (u_tauRef.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tauRef.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tauRef.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tauRef.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tauRef.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tauRef.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tauRef.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tauRef.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tauRef);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_jname;
      memcpy(&length_jname, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_jname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_jname-1]=0;
      this->jname = (char *)(inbuffer + offset-1);
      offset += length_jname;
      union {
        double real;
        uint64_t base;
      } u_tauRef;
      u_tauRef.base = 0;
      u_tauRef.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tauRef.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tauRef.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tauRef.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tauRef.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tauRef.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tauRef.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tauRef.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->tauRef = u_tauRef.real;
      offset += sizeof(this->tauRef);
     return offset;
    }

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE; };
    const char * getMD5(){ return "1153c46acb791af55d857dbb85eb7e0a"; };

  };

  class OpenHRP_TorqueControllerService_setReferenceTorqueResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_TorqueControllerService_setReferenceTorqueResponse():
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

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_TorqueControllerService_setReferenceTorque {
    public:
    typedef OpenHRP_TorqueControllerService_setReferenceTorqueRequest Request;
    typedef OpenHRP_TorqueControllerService_setReferenceTorqueResponse Response;
  };

}
#endif
