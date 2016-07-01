#ifndef _ROS_SERVICE_RvizMenuCall_h
#define _ROS_SERVICE_RvizMenuCall_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_task_common
{

static const char RVIZMENUCALL[] = "drc_task_common/RvizMenuCall";

  class RvizMenuCallRequest : public ros::Msg
  {
    public:
      const char* title;
      uint8_t menu_list_length;
      char* st_menu_list;
      char* * menu_list;
      float variable_max;
      float variable_min;
      float variable;
      bool boolean;

    RvizMenuCallRequest():
      title(""),
      menu_list_length(0), menu_list(NULL),
      variable_max(0),
      variable_min(0),
      variable(0),
      boolean(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_title = strlen(this->title);
      memcpy(outbuffer + offset, &length_title, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->title, length_title);
      offset += length_title;
      *(outbuffer + offset++) = menu_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < menu_list_length; i++){
      uint32_t length_menu_listi = strlen(this->menu_list[i]);
      memcpy(outbuffer + offset, &length_menu_listi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->menu_list[i], length_menu_listi);
      offset += length_menu_listi;
      }
      union {
        float real;
        uint32_t base;
      } u_variable_max;
      u_variable_max.real = this->variable_max;
      *(outbuffer + offset + 0) = (u_variable_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variable_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variable_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variable_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variable_max);
      union {
        float real;
        uint32_t base;
      } u_variable_min;
      u_variable_min.real = this->variable_min;
      *(outbuffer + offset + 0) = (u_variable_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variable_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variable_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variable_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variable_min);
      union {
        float real;
        uint32_t base;
      } u_variable;
      u_variable.real = this->variable;
      *(outbuffer + offset + 0) = (u_variable.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variable.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variable.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variable.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variable);
      union {
        bool real;
        uint8_t base;
      } u_boolean;
      u_boolean.real = this->boolean;
      *(outbuffer + offset + 0) = (u_boolean.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->boolean);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_title;
      memcpy(&length_title, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_title; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_title-1]=0;
      this->title = (char *)(inbuffer + offset-1);
      offset += length_title;
      uint8_t menu_list_lengthT = *(inbuffer + offset++);
      if(menu_list_lengthT > menu_list_length)
        this->menu_list = (char**)realloc(this->menu_list, menu_list_lengthT * sizeof(char*));
      offset += 3;
      menu_list_length = menu_list_lengthT;
      for( uint8_t i = 0; i < menu_list_length; i++){
      uint32_t length_st_menu_list;
      memcpy(&length_st_menu_list, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_menu_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_menu_list-1]=0;
      this->st_menu_list = (char *)(inbuffer + offset-1);
      offset += length_st_menu_list;
        memcpy( &(this->menu_list[i]), &(this->st_menu_list), sizeof(char*));
      }
      union {
        float real;
        uint32_t base;
      } u_variable_max;
      u_variable_max.base = 0;
      u_variable_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variable_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variable_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variable_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->variable_max = u_variable_max.real;
      offset += sizeof(this->variable_max);
      union {
        float real;
        uint32_t base;
      } u_variable_min;
      u_variable_min.base = 0;
      u_variable_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variable_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variable_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variable_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->variable_min = u_variable_min.real;
      offset += sizeof(this->variable_min);
      union {
        float real;
        uint32_t base;
      } u_variable;
      u_variable.base = 0;
      u_variable.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variable.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variable.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variable.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->variable = u_variable.real;
      offset += sizeof(this->variable);
      union {
        bool real;
        uint8_t base;
      } u_boolean;
      u_boolean.base = 0;
      u_boolean.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->boolean = u_boolean.real;
      offset += sizeof(this->boolean);
     return offset;
    }

    const char * getType(){ return RVIZMENUCALL; };
    const char * getMD5(){ return "d2aac6e16e4948957d13de9e9a58d2e2"; };

  };

  class RvizMenuCallResponse : public ros::Msg
  {
    public:
      int32_t index;
      float variable_ret;
      bool boolean_ret;

    RvizMenuCallResponse():
      index(0),
      variable_ret(0),
      boolean_ret(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      union {
        float real;
        uint32_t base;
      } u_variable_ret;
      u_variable_ret.real = this->variable_ret;
      *(outbuffer + offset + 0) = (u_variable_ret.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variable_ret.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variable_ret.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variable_ret.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->variable_ret);
      union {
        bool real;
        uint8_t base;
      } u_boolean_ret;
      u_boolean_ret.real = this->boolean_ret;
      *(outbuffer + offset + 0) = (u_boolean_ret.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->boolean_ret);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->index = u_index.real;
      offset += sizeof(this->index);
      union {
        float real;
        uint32_t base;
      } u_variable_ret;
      u_variable_ret.base = 0;
      u_variable_ret.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variable_ret.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variable_ret.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variable_ret.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->variable_ret = u_variable_ret.real;
      offset += sizeof(this->variable_ret);
      union {
        bool real;
        uint8_t base;
      } u_boolean_ret;
      u_boolean_ret.base = 0;
      u_boolean_ret.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->boolean_ret = u_boolean_ret.real;
      offset += sizeof(this->boolean_ret);
     return offset;
    }

    const char * getType(){ return RVIZMENUCALL; };
    const char * getMD5(){ return "220abe505a53762b4ce7fd82ca0c5d4c"; };

  };

  class RvizMenuCall {
    public:
    typedef RvizMenuCallRequest Request;
    typedef RvizMenuCallResponse Response;
  };

}
#endif
