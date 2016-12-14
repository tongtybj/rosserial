#ifndef _ROS_contact_states_observer_GraspState_h
#define _ROS_contact_states_observer_GraspState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "contact_states_observer/GraspReferenceData.h"

namespace contact_states_observer
{

  class GraspState : public ros::Msg
  {
    public:
      uint8_t check_jname_list_length;
      char* st_check_jname_list;
      char* * check_jname_list;
      uint8_t reference_datas_length;
      contact_states_observer::GraspReferenceData st_reference_datas;
      contact_states_observer::GraspReferenceData * reference_datas;
      uint8_t current_av_length;
      double st_current_av;
      double * current_av;
      const char* result;

    GraspState():
      check_jname_list_length(0), check_jname_list(NULL),
      reference_datas_length(0), reference_datas(NULL),
      current_av_length(0), current_av(NULL),
      result("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = check_jname_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < check_jname_list_length; i++){
      uint32_t length_check_jname_listi = strlen(this->check_jname_list[i]);
      memcpy(outbuffer + offset, &length_check_jname_listi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->check_jname_list[i], length_check_jname_listi);
      offset += length_check_jname_listi;
      }
      *(outbuffer + offset++) = reference_datas_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < reference_datas_length; i++){
      offset += this->reference_datas[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = current_av_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < current_av_length; i++){
      union {
        double real;
        uint64_t base;
      } u_current_avi;
      u_current_avi.real = this->current_av[i];
      *(outbuffer + offset + 0) = (u_current_avi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_avi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_avi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_avi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_current_avi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_current_avi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_current_avi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_current_avi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current_av[i]);
      }
      uint32_t length_result = strlen(this->result);
      memcpy(outbuffer + offset, &length_result, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->result, length_result);
      offset += length_result;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t check_jname_list_lengthT = *(inbuffer + offset++);
      if(check_jname_list_lengthT > check_jname_list_length)
        this->check_jname_list = (char**)realloc(this->check_jname_list, check_jname_list_lengthT * sizeof(char*));
      offset += 3;
      check_jname_list_length = check_jname_list_lengthT;
      for( uint8_t i = 0; i < check_jname_list_length; i++){
      uint32_t length_st_check_jname_list;
      memcpy(&length_st_check_jname_list, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_check_jname_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_check_jname_list-1]=0;
      this->st_check_jname_list = (char *)(inbuffer + offset-1);
      offset += length_st_check_jname_list;
        memcpy( &(this->check_jname_list[i]), &(this->st_check_jname_list), sizeof(char*));
      }
      uint8_t reference_datas_lengthT = *(inbuffer + offset++);
      if(reference_datas_lengthT > reference_datas_length)
        this->reference_datas = (contact_states_observer::GraspReferenceData*)realloc(this->reference_datas, reference_datas_lengthT * sizeof(contact_states_observer::GraspReferenceData));
      offset += 3;
      reference_datas_length = reference_datas_lengthT;
      for( uint8_t i = 0; i < reference_datas_length; i++){
      offset += this->st_reference_datas.deserialize(inbuffer + offset);
        memcpy( &(this->reference_datas[i]), &(this->st_reference_datas), sizeof(contact_states_observer::GraspReferenceData));
      }
      uint8_t current_av_lengthT = *(inbuffer + offset++);
      if(current_av_lengthT > current_av_length)
        this->current_av = (double*)realloc(this->current_av, current_av_lengthT * sizeof(double));
      offset += 3;
      current_av_length = current_av_lengthT;
      for( uint8_t i = 0; i < current_av_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_current_av;
      u_st_current_av.base = 0;
      u_st_current_av.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_current_av.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_current_av.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_current_av.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_current_av.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_current_av.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_current_av.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_current_av.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_current_av = u_st_current_av.real;
      offset += sizeof(this->st_current_av);
        memcpy( &(this->current_av[i]), &(this->st_current_av), sizeof(double));
      }
      uint32_t length_result;
      memcpy(&length_result, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result-1]=0;
      this->result = (char *)(inbuffer + offset-1);
      offset += length_result;
     return offset;
    }

    const char * getType(){ return "contact_states_observer/GraspState"; };
    const char * getMD5(){ return "0f48e0891b861234b6b9a7608d5c1572"; };

  };

}
#endif