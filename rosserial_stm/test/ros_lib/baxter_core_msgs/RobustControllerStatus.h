#ifndef _ROS_baxter_core_msgs_RobustControllerStatus_h
#define _ROS_baxter_core_msgs_RobustControllerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace baxter_core_msgs
{

  class RobustControllerStatus : public ros::Msg
  {
    public:
      bool isEnabled;
      int32_t complete;
      const char* controlUid;
      bool timedOut;
      uint8_t errorCodes_length;
      char* st_errorCodes;
      char* * errorCodes;
      uint8_t labels_length;
      char* st_labels;
      char* * labels;
      enum { NOT_COMPLETE =  0 };
      enum { COMPLETE_W_FAILURE =  1 };
      enum { COMPLETE_W_SUCCESS =  2 };

    RobustControllerStatus():
      isEnabled(0),
      complete(0),
      controlUid(""),
      timedOut(0),
      errorCodes_length(0), errorCodes(NULL),
      labels_length(0), labels(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isEnabled;
      u_isEnabled.real = this->isEnabled;
      *(outbuffer + offset + 0) = (u_isEnabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isEnabled);
      union {
        int32_t real;
        uint32_t base;
      } u_complete;
      u_complete.real = this->complete;
      *(outbuffer + offset + 0) = (u_complete.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_complete.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_complete.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_complete.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->complete);
      uint32_t length_controlUid = strlen(this->controlUid);
      memcpy(outbuffer + offset, &length_controlUid, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->controlUid, length_controlUid);
      offset += length_controlUid;
      union {
        bool real;
        uint8_t base;
      } u_timedOut;
      u_timedOut.real = this->timedOut;
      *(outbuffer + offset + 0) = (u_timedOut.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->timedOut);
      *(outbuffer + offset++) = errorCodes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < errorCodes_length; i++){
      uint32_t length_errorCodesi = strlen(this->errorCodes[i]);
      memcpy(outbuffer + offset, &length_errorCodesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->errorCodes[i], length_errorCodesi);
      offset += length_errorCodesi;
      }
      *(outbuffer + offset++) = labels_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < labels_length; i++){
      uint32_t length_labelsi = strlen(this->labels[i]);
      memcpy(outbuffer + offset, &length_labelsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->labels[i], length_labelsi);
      offset += length_labelsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_isEnabled;
      u_isEnabled.base = 0;
      u_isEnabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->isEnabled = u_isEnabled.real;
      offset += sizeof(this->isEnabled);
      union {
        int32_t real;
        uint32_t base;
      } u_complete;
      u_complete.base = 0;
      u_complete.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_complete.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_complete.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_complete.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->complete = u_complete.real;
      offset += sizeof(this->complete);
      uint32_t length_controlUid;
      memcpy(&length_controlUid, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_controlUid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_controlUid-1]=0;
      this->controlUid = (char *)(inbuffer + offset-1);
      offset += length_controlUid;
      union {
        bool real;
        uint8_t base;
      } u_timedOut;
      u_timedOut.base = 0;
      u_timedOut.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->timedOut = u_timedOut.real;
      offset += sizeof(this->timedOut);
      uint8_t errorCodes_lengthT = *(inbuffer + offset++);
      if(errorCodes_lengthT > errorCodes_length)
        this->errorCodes = (char**)realloc(this->errorCodes, errorCodes_lengthT * sizeof(char*));
      offset += 3;
      errorCodes_length = errorCodes_lengthT;
      for( uint8_t i = 0; i < errorCodes_length; i++){
      uint32_t length_st_errorCodes;
      memcpy(&length_st_errorCodes, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_errorCodes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_errorCodes-1]=0;
      this->st_errorCodes = (char *)(inbuffer + offset-1);
      offset += length_st_errorCodes;
        memcpy( &(this->errorCodes[i]), &(this->st_errorCodes), sizeof(char*));
      }
      uint8_t labels_lengthT = *(inbuffer + offset++);
      if(labels_lengthT > labels_length)
        this->labels = (char**)realloc(this->labels, labels_lengthT * sizeof(char*));
      offset += 3;
      labels_length = labels_lengthT;
      for( uint8_t i = 0; i < labels_length; i++){
      uint32_t length_st_labels;
      memcpy(&length_st_labels, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_labels; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_labels-1]=0;
      this->st_labels = (char *)(inbuffer + offset-1);
      offset += length_st_labels;
        memcpy( &(this->labels[i]), &(this->st_labels), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/RobustControllerStatus"; };
    const char * getMD5(){ return "2f15441b7285d915e7e59d3618e173f2"; };

  };

}
#endif