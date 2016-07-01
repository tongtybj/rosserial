#ifndef _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroup_h
#define _ROS_SERVICE_OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroup_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCEOFGROUP[] = "hrpsys_ros_bridge/OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroup";

  class OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroupRequest : public ros::Msg
  {
    public:
      const char* gname;
      std_msgs::Float64MultiArray jvss;
      uint8_t tms_length;
      double st_tms;
      double * tms;

    OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroupRequest():
      gname(""),
      jvss(),
      tms_length(0), tms(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_gname = strlen(this->gname);
      memcpy(outbuffer + offset, &length_gname, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->gname, length_gname);
      offset += length_gname;
      offset += this->jvss.serialize(outbuffer + offset);
      *(outbuffer + offset++) = tms_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tms_length; i++){
      union {
        double real;
        uint64_t base;
      } u_tmsi;
      u_tmsi.real = this->tms[i];
      *(outbuffer + offset + 0) = (u_tmsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tmsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tmsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tmsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tmsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tmsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tmsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tmsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tms[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_gname;
      memcpy(&length_gname, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gname-1]=0;
      this->gname = (char *)(inbuffer + offset-1);
      offset += length_gname;
      offset += this->jvss.deserialize(inbuffer + offset);
      uint8_t tms_lengthT = *(inbuffer + offset++);
      if(tms_lengthT > tms_length)
        this->tms = (double*)realloc(this->tms, tms_lengthT * sizeof(double));
      offset += 3;
      tms_length = tms_lengthT;
      for( uint8_t i = 0; i < tms_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_tms;
      u_st_tms.base = 0;
      u_st_tms.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_tms.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_tms.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_tms.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_tms.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_tms.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_tms.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_tms.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_tms = u_st_tms.real;
      offset += sizeof(this->st_tms);
        memcpy( &(this->tms[i]), &(this->st_tms), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCEOFGROUP; };
    const char * getMD5(){ return "1eb0879162771349efde28e721199e66"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroupResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroupResponse():
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

    const char * getType(){ return OPENHRP_SEQUENCEPLAYERSERVICE_SETJOINTANGLESSEQUENCEOFGROUP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroup {
    public:
    typedef OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroupRequest Request;
    typedef OpenHRP_SequencePlayerService_setJointAnglesSequenceOfGroupResponse Response;
  };

}
#endif
