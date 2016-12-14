#ifndef _ROS_jsk_rviz_plugins_OverlayText_h
#define _ROS_jsk_rviz_plugins_OverlayText_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace jsk_rviz_plugins
{

  class OverlayText : public ros::Msg
  {
    public:
      uint8_t action;
      int32_t width;
      int32_t height;
      int32_t left;
      int32_t top;
      std_msgs::ColorRGBA bg_color;
      int32_t line_width;
      float text_size;
      const char* font;
      std_msgs::ColorRGBA fg_color;
      const char* text;
      enum { ADD =  0 };
      enum { DELETE =  1 };

    OverlayText():
      action(0),
      width(0),
      height(0),
      left(0),
      top(0),
      bg_color(),
      line_width(0),
      text_size(0),
      font(""),
      fg_color(),
      text("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->action >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        int32_t real;
        uint32_t base;
      } u_left;
      u_left.real = this->left;
      *(outbuffer + offset + 0) = (u_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left);
      union {
        int32_t real;
        uint32_t base;
      } u_top;
      u_top.real = this->top;
      *(outbuffer + offset + 0) = (u_top.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_top.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_top.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_top.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->top);
      offset += this->bg_color.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_line_width;
      u_line_width.real = this->line_width;
      *(outbuffer + offset + 0) = (u_line_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_line_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_line_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_line_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line_width);
      union {
        float real;
        uint32_t base;
      } u_text_size;
      u_text_size.real = this->text_size;
      *(outbuffer + offset + 0) = (u_text_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_text_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_text_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_text_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->text_size);
      uint32_t length_font = strlen(this->font);
      memcpy(outbuffer + offset, &length_font, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->font, length_font);
      offset += length_font;
      offset += this->fg_color.serialize(outbuffer + offset);
      uint32_t length_text = strlen(this->text);
      memcpy(outbuffer + offset, &length_text, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->action =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->action);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        int32_t real;
        uint32_t base;
      } u_left;
      u_left.base = 0;
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left = u_left.real;
      offset += sizeof(this->left);
      union {
        int32_t real;
        uint32_t base;
      } u_top;
      u_top.base = 0;
      u_top.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_top.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_top.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_top.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->top = u_top.real;
      offset += sizeof(this->top);
      offset += this->bg_color.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_line_width;
      u_line_width.base = 0;
      u_line_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_line_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_line_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_line_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->line_width = u_line_width.real;
      offset += sizeof(this->line_width);
      union {
        float real;
        uint32_t base;
      } u_text_size;
      u_text_size.base = 0;
      u_text_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_text_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_text_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_text_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->text_size = u_text_size.real;
      offset += sizeof(this->text_size);
      uint32_t length_font;
      memcpy(&length_font, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_font; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_font-1]=0;
      this->font = (char *)(inbuffer + offset-1);
      offset += length_font;
      offset += this->fg_color.deserialize(inbuffer + offset);
      uint32_t length_text;
      memcpy(&length_text, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/OverlayText"; };
    const char * getMD5(){ return "7efc1ed34881f913afcee6ba02aa1242"; };

  };

}
#endif