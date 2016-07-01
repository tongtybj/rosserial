#ifndef _ROS_SERVICE_OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParams_h
#define _ROS_SERVICE_OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParams_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_REMOVEFORCESENSORLINKOFFSETSERVICE_DUMPFORCEMOMENTOFFSETPARAMS[] = "hrpsys_ros_bridge/OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParams";

  class OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParamsRequest : public ros::Msg
  {
    public:
      const char* filename;

    OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParamsRequest():
      filename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_filename = strlen(this->filename);
      memcpy(outbuffer + offset, &length_filename, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->filename, length_filename);
      offset += length_filename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_filename;
      memcpy(&length_filename, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filename-1]=0;
      this->filename = (char *)(inbuffer + offset-1);
      offset += length_filename;
     return offset;
    }

    const char * getType(){ return OPENHRP_REMOVEFORCESENSORLINKOFFSETSERVICE_DUMPFORCEMOMENTOFFSETPARAMS; };
    const char * getMD5(){ return "030824f52a0628ead956fb9d67e66ae9"; };

  };

  class OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParamsResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParamsResponse():
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

    const char * getType(){ return OPENHRP_REMOVEFORCESENSORLINKOFFSETSERVICE_DUMPFORCEMOMENTOFFSETPARAMS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParams {
    public:
    typedef OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParamsRequest Request;
    typedef OpenHRP_RemoveForceSensorLinkOffsetService_dumpForceMomentOffsetParamsResponse Response;
  };

}
#endif
