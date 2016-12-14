#ifndef _ROS_pal_detection_msgs_RecognizedActions_h
#define _ROS_pal_detection_msgs_RecognizedActions_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pal_detection_msgs
{

  class RecognizedActions : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t action_name_length;
      char* st_action_name;
      char* * action_name;
      uint8_t u_length;
      int64_t st_u;
      int64_t * u;
      uint8_t v_length;
      int64_t st_v;
      int64_t * v;

    RecognizedActions():
      header(),
      action_name_length(0), action_name(NULL),
      u_length(0), u(NULL),
      v_length(0), v(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = action_name_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < action_name_length; i++){
      uint32_t length_action_namei = strlen(this->action_name[i]);
      memcpy(outbuffer + offset, &length_action_namei, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->action_name[i], length_action_namei);
      offset += length_action_namei;
      }
      *(outbuffer + offset++) = u_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < u_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_ui;
      u_ui.real = this->u[i];
      *(outbuffer + offset + 0) = (u_ui.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ui.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ui.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ui.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ui.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ui.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ui.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ui.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->u[i]);
      }
      *(outbuffer + offset++) = v_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < v_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_vi;
      u_vi.real = this->v[i];
      *(outbuffer + offset + 0) = (u_vi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_vi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_vi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_vi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_vi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->v[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t action_name_lengthT = *(inbuffer + offset++);
      if(action_name_lengthT > action_name_length)
        this->action_name = (char**)realloc(this->action_name, action_name_lengthT * sizeof(char*));
      offset += 3;
      action_name_length = action_name_lengthT;
      for( uint8_t i = 0; i < action_name_length; i++){
      uint32_t length_st_action_name;
      memcpy(&length_st_action_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_action_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_action_name-1]=0;
      this->st_action_name = (char *)(inbuffer + offset-1);
      offset += length_st_action_name;
        memcpy( &(this->action_name[i]), &(this->st_action_name), sizeof(char*));
      }
      uint8_t u_lengthT = *(inbuffer + offset++);
      if(u_lengthT > u_length)
        this->u = (int64_t*)realloc(this->u, u_lengthT * sizeof(int64_t));
      offset += 3;
      u_length = u_lengthT;
      for( uint8_t i = 0; i < u_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_u;
      u_st_u.base = 0;
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_u.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_u = u_st_u.real;
      offset += sizeof(this->st_u);
        memcpy( &(this->u[i]), &(this->st_u), sizeof(int64_t));
      }
      uint8_t v_lengthT = *(inbuffer + offset++);
      if(v_lengthT > v_length)
        this->v = (int64_t*)realloc(this->v, v_lengthT * sizeof(int64_t));
      offset += 3;
      v_length = v_lengthT;
      for( uint8_t i = 0; i < v_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_v;
      u_st_v.base = 0;
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_v.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_v = u_st_v.real;
      offset += sizeof(this->st_v);
        memcpy( &(this->v[i]), &(this->st_v), sizeof(int64_t));
      }
     return offset;
    }

    const char * getType(){ return "pal_detection_msgs/RecognizedActions"; };
    const char * getMD5(){ return "e6c6e85fc615700151c9f88b60277903"; };

  };

}
#endif