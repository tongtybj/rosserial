#ifndef _ROS_SERVICE_OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetection_h
#define _ROS_SERVICE_OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_IMPEDANCECONTROLLERSERVICE_STARTOBJECTTURNAROUNDDETECTION[] = "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetection";

  class OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetectionRequest : public ros::Msg
  {
    public:
      double i_ref_diff_wrench;
      double i_max_time;
      uint8_t i_ee_names_length;
      char* st_i_ee_names;
      char* * i_ee_names;

    OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetectionRequest():
      i_ref_diff_wrench(0),
      i_max_time(0),
      i_ee_names_length(0), i_ee_names(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_i_ref_diff_wrench;
      u_i_ref_diff_wrench.real = this->i_ref_diff_wrench;
      *(outbuffer + offset + 0) = (u_i_ref_diff_wrench.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i_ref_diff_wrench.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i_ref_diff_wrench.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i_ref_diff_wrench.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_i_ref_diff_wrench.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_i_ref_diff_wrench.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_i_ref_diff_wrench.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_i_ref_diff_wrench.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->i_ref_diff_wrench);
      union {
        double real;
        uint64_t base;
      } u_i_max_time;
      u_i_max_time.real = this->i_max_time;
      *(outbuffer + offset + 0) = (u_i_max_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i_max_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i_max_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i_max_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_i_max_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_i_max_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_i_max_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_i_max_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->i_max_time);
      *(outbuffer + offset++) = i_ee_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < i_ee_names_length; i++){
      uint32_t length_i_ee_namesi = strlen(this->i_ee_names[i]);
      memcpy(outbuffer + offset, &length_i_ee_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->i_ee_names[i], length_i_ee_namesi);
      offset += length_i_ee_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_i_ref_diff_wrench;
      u_i_ref_diff_wrench.base = 0;
      u_i_ref_diff_wrench.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i_ref_diff_wrench.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i_ref_diff_wrench.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i_ref_diff_wrench.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_i_ref_diff_wrench.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_i_ref_diff_wrench.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_i_ref_diff_wrench.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_i_ref_diff_wrench.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->i_ref_diff_wrench = u_i_ref_diff_wrench.real;
      offset += sizeof(this->i_ref_diff_wrench);
      union {
        double real;
        uint64_t base;
      } u_i_max_time;
      u_i_max_time.base = 0;
      u_i_max_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i_max_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i_max_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i_max_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_i_max_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_i_max_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_i_max_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_i_max_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->i_max_time = u_i_max_time.real;
      offset += sizeof(this->i_max_time);
      uint8_t i_ee_names_lengthT = *(inbuffer + offset++);
      if(i_ee_names_lengthT > i_ee_names_length)
        this->i_ee_names = (char**)realloc(this->i_ee_names, i_ee_names_lengthT * sizeof(char*));
      offset += 3;
      i_ee_names_length = i_ee_names_lengthT;
      for( uint8_t i = 0; i < i_ee_names_length; i++){
      uint32_t length_st_i_ee_names;
      memcpy(&length_st_i_ee_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_i_ee_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_i_ee_names-1]=0;
      this->st_i_ee_names = (char *)(inbuffer + offset-1);
      offset += length_st_i_ee_names;
        memcpy( &(this->i_ee_names[i]), &(this->st_i_ee_names), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_STARTOBJECTTURNAROUNDDETECTION; };
    const char * getMD5(){ return "41330c5a4dc330b9b74e53118398a4db"; };

  };

  class OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetectionResponse : public ros::Msg
  {
    public:

    OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetectionResponse()
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

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_STARTOBJECTTURNAROUNDDETECTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetection {
    public:
    typedef OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetectionRequest Request;
    typedef OpenHRP_ImpedanceControllerService_startObjectTurnaroundDetectionResponse Response;
  };

}
#endif
