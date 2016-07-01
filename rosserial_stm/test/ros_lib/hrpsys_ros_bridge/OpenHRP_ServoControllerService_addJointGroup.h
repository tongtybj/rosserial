#ifndef _ROS_SERVICE_OpenHRP_ServoControllerService_addJointGroup_h
#define _ROS_SERVICE_OpenHRP_ServoControllerService_addJointGroup_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_SERVOCONTROLLERSERVICE_ADDJOINTGROUP[] = "hrpsys_ros_bridge/OpenHRP_ServoControllerService_addJointGroup";

  class OpenHRP_ServoControllerService_addJointGroupRequest : public ros::Msg
  {
    public:
      const char* gname;
      uint8_t ids_length;
      int16_t st_ids;
      int16_t * ids;

    OpenHRP_ServoControllerService_addJointGroupRequest():
      gname(""),
      ids_length(0), ids(NULL)
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
      *(outbuffer + offset++) = ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < ids_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_idsi;
      u_idsi.real = this->ids[i];
      *(outbuffer + offset + 0) = (u_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_idsi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ids[i]);
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
      uint8_t ids_lengthT = *(inbuffer + offset++);
      if(ids_lengthT > ids_length)
        this->ids = (int16_t*)realloc(this->ids, ids_lengthT * sizeof(int16_t));
      offset += 3;
      ids_length = ids_lengthT;
      for( uint8_t i = 0; i < ids_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_ids;
      u_st_ids.base = 0;
      u_st_ids.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ids.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_ids = u_st_ids.real;
      offset += sizeof(this->st_ids);
        memcpy( &(this->ids[i]), &(this->st_ids), sizeof(int16_t));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_ADDJOINTGROUP; };
    const char * getMD5(){ return "3de7728686c0c6a2587262232f49a155"; };

  };

  class OpenHRP_ServoControllerService_addJointGroupResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_ServoControllerService_addJointGroupResponse():
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

    const char * getType(){ return OPENHRP_SERVOCONTROLLERSERVICE_ADDJOINTGROUP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ServoControllerService_addJointGroup {
    public:
    typedef OpenHRP_ServoControllerService_addJointGroupRequest Request;
    typedef OpenHRP_ServoControllerService_addJointGroupResponse Response;
  };

}
#endif
