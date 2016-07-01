#ifndef _ROS_SERVICE_GetIKArm_h
#define _ROS_SERVICE_GetIKArm_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_task_common
{

static const char GETIKARM[] = "drc_task_common/GetIKArm";

  class GetIKArmRequest : public ros::Msg
  {
    public:

    GetIKArmRequest()
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

    const char * getType(){ return GETIKARM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetIKArmResponse : public ros::Msg
  {
    public:
      const char* ik_arm;

    GetIKArmResponse():
      ik_arm("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_ik_arm = strlen(this->ik_arm);
      memcpy(outbuffer + offset, &length_ik_arm, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ik_arm, length_ik_arm);
      offset += length_ik_arm;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_ik_arm;
      memcpy(&length_ik_arm, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ik_arm; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ik_arm-1]=0;
      this->ik_arm = (char *)(inbuffer + offset-1);
      offset += length_ik_arm;
     return offset;
    }

    const char * getType(){ return GETIKARM; };
    const char * getMD5(){ return "b1c755116494fb8a892ad484f1cb289d"; };

  };

  class GetIKArm {
    public:
    typedef GetIKArmRequest Request;
    typedef GetIKArmResponse Response;
  };

}
#endif
