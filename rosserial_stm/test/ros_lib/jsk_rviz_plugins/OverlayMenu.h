#ifndef _ROS_jsk_rviz_plugins_OverlayMenu_h
#define _ROS_jsk_rviz_plugins_OverlayMenu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_rviz_plugins
{

  class OverlayMenu : public ros::Msg
  {
    public:
      int32_t action;
      uint32_t current_index;
      uint8_t menus_length;
      char* st_menus;
      char* * menus;
      const char* title;
      enum { ACTION_SELECT = 0 };
      enum { ACTION_CLOSE = 1 };

    OverlayMenu():
      action(0),
      current_index(0),
      menus_length(0), menus(NULL),
      title("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action);
      *(outbuffer + offset + 0) = (this->current_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_index);
      *(outbuffer + offset++) = menus_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < menus_length; i++){
      uint32_t length_menusi = strlen(this->menus[i]);
      memcpy(outbuffer + offset, &length_menusi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->menus[i], length_menusi);
      offset += length_menusi;
      }
      uint32_t length_title = strlen(this->title);
      memcpy(outbuffer + offset, &length_title, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->title, length_title);
      offset += length_title;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action = u_action.real;
      offset += sizeof(this->action);
      this->current_index =  ((uint32_t) (*(inbuffer + offset)));
      this->current_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_index);
      uint8_t menus_lengthT = *(inbuffer + offset++);
      if(menus_lengthT > menus_length)
        this->menus = (char**)realloc(this->menus, menus_lengthT * sizeof(char*));
      offset += 3;
      menus_length = menus_lengthT;
      for( uint8_t i = 0; i < menus_length; i++){
      uint32_t length_st_menus;
      memcpy(&length_st_menus, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_menus; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_menus-1]=0;
      this->st_menus = (char *)(inbuffer + offset-1);
      offset += length_st_menus;
        memcpy( &(this->menus[i]), &(this->st_menus), sizeof(char*));
      }
      uint32_t length_title;
      memcpy(&length_title, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_title; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_title-1]=0;
      this->title = (char *)(inbuffer + offset-1);
      offset += length_title;
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/OverlayMenu"; };
    const char * getMD5(){ return "fed3c7e9788f7ee37908107a2597b619"; };

  };

}
#endif