#ifndef _ROS_pal_interaction_msgs_ASRLangModelMngmt_h
#define _ROS_pal_interaction_msgs_ASRLangModelMngmt_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_interaction_msgs
{

  class ASRLangModelMngmt : public ros::Msg
  {
    public:
      int8_t action;
      const char* modelName;
      enum { ENABLE =  1 };
      enum { DISABLE =  2 };
      enum { LOAD =  3 };
      enum { UNLOAD =  4 };

    ASRLangModelMngmt():
      action(0),
      modelName("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_modelName = strlen(this->modelName);
      memcpy(outbuffer + offset, &length_modelName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->modelName, length_modelName);
      offset += length_modelName;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->action = u_action.real;
      offset += sizeof(this->action);
      uint32_t length_modelName;
      memcpy(&length_modelName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_modelName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_modelName-1]=0;
      this->modelName = (char *)(inbuffer + offset-1);
      offset += length_modelName;
     return offset;
    }

    const char * getType(){ return "pal_interaction_msgs/ASRLangModelMngmt"; };
    const char * getMD5(){ return "b14d87d721997c14475b6bf74e854ad8"; };

  };

}
#endif