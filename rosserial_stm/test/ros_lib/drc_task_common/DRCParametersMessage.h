#ifndef _ROS_drc_task_common_DRCParametersMessage_h
#define _ROS_drc_task_common_DRCParametersMessage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_task_common
{

  class DRCParametersMessage : public ros::Msg
  {
    public:
      bool chest_camera_enable_auto_exposure;
      bool enable_lighting;
      bool enable_auto_exposure;
      float chest_camera_exposure;
      float lighting;
      float exposure;

    DRCParametersMessage():
      chest_camera_enable_auto_exposure(0),
      enable_lighting(0),
      enable_auto_exposure(0),
      chest_camera_exposure(0),
      lighting(0),
      exposure(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_chest_camera_enable_auto_exposure;
      u_chest_camera_enable_auto_exposure.real = this->chest_camera_enable_auto_exposure;
      *(outbuffer + offset + 0) = (u_chest_camera_enable_auto_exposure.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->chest_camera_enable_auto_exposure);
      union {
        bool real;
        uint8_t base;
      } u_enable_lighting;
      u_enable_lighting.real = this->enable_lighting;
      *(outbuffer + offset + 0) = (u_enable_lighting.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_lighting);
      union {
        bool real;
        uint8_t base;
      } u_enable_auto_exposure;
      u_enable_auto_exposure.real = this->enable_auto_exposure;
      *(outbuffer + offset + 0) = (u_enable_auto_exposure.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_auto_exposure);
      union {
        float real;
        uint32_t base;
      } u_chest_camera_exposure;
      u_chest_camera_exposure.real = this->chest_camera_exposure;
      *(outbuffer + offset + 0) = (u_chest_camera_exposure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_chest_camera_exposure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_chest_camera_exposure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_chest_camera_exposure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->chest_camera_exposure);
      union {
        float real;
        uint32_t base;
      } u_lighting;
      u_lighting.real = this->lighting;
      *(outbuffer + offset + 0) = (u_lighting.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lighting.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lighting.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lighting.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lighting);
      union {
        float real;
        uint32_t base;
      } u_exposure;
      u_exposure.real = this->exposure;
      *(outbuffer + offset + 0) = (u_exposure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exposure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exposure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exposure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exposure);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_chest_camera_enable_auto_exposure;
      u_chest_camera_enable_auto_exposure.base = 0;
      u_chest_camera_enable_auto_exposure.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->chest_camera_enable_auto_exposure = u_chest_camera_enable_auto_exposure.real;
      offset += sizeof(this->chest_camera_enable_auto_exposure);
      union {
        bool real;
        uint8_t base;
      } u_enable_lighting;
      u_enable_lighting.base = 0;
      u_enable_lighting.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_lighting = u_enable_lighting.real;
      offset += sizeof(this->enable_lighting);
      union {
        bool real;
        uint8_t base;
      } u_enable_auto_exposure;
      u_enable_auto_exposure.base = 0;
      u_enable_auto_exposure.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_auto_exposure = u_enable_auto_exposure.real;
      offset += sizeof(this->enable_auto_exposure);
      union {
        float real;
        uint32_t base;
      } u_chest_camera_exposure;
      u_chest_camera_exposure.base = 0;
      u_chest_camera_exposure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_chest_camera_exposure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_chest_camera_exposure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_chest_camera_exposure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->chest_camera_exposure = u_chest_camera_exposure.real;
      offset += sizeof(this->chest_camera_exposure);
      union {
        float real;
        uint32_t base;
      } u_lighting;
      u_lighting.base = 0;
      u_lighting.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lighting.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lighting.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lighting.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lighting = u_lighting.real;
      offset += sizeof(this->lighting);
      union {
        float real;
        uint32_t base;
      } u_exposure;
      u_exposure.base = 0;
      u_exposure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exposure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exposure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exposure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->exposure = u_exposure.real;
      offset += sizeof(this->exposure);
     return offset;
    }

    const char * getType(){ return "drc_task_common/DRCParametersMessage"; };
    const char * getMD5(){ return "aa54044f949aab82e74a57ce30b0b699"; };

  };

}
#endif