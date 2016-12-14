#ifndef _ROS_baxter_core_msgs_EndEffectorProperties_h
#define _ROS_baxter_core_msgs_EndEffectorProperties_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace baxter_core_msgs
{

  class EndEffectorProperties : public ros::Msg
  {
    public:
      uint32_t id;
      uint8_t ui_type;
      const char* manufacturer;
      const char* product;
      const char* serial_number;
      const char* hardware_rev;
      const char* firmware_rev;
      const char* firmware_date;
      bool has_calibration;
      bool controls_grip;
      bool senses_grip;
      bool reverses_grip;
      bool controls_force;
      bool senses_force;
      bool controls_position;
      bool senses_position;
      const char* properties;
      enum { NO_GRIPPER =  0 };
      enum { SUCTION_CUP_GRIPPER =  1 };
      enum { ELECTRIC_GRIPPER =  2 };
      enum { PASSIVE_GRIPPER =  3 };

    EndEffectorProperties():
      id(0),
      ui_type(0),
      manufacturer(""),
      product(""),
      serial_number(""),
      hardware_rev(""),
      firmware_rev(""),
      firmware_date(""),
      has_calibration(0),
      controls_grip(0),
      senses_grip(0),
      reverses_grip(0),
      controls_force(0),
      senses_force(0),
      controls_position(0),
      senses_position(0),
      properties("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->ui_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ui_type);
      uint32_t length_manufacturer = strlen(this->manufacturer);
      memcpy(outbuffer + offset, &length_manufacturer, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->manufacturer, length_manufacturer);
      offset += length_manufacturer;
      uint32_t length_product = strlen(this->product);
      memcpy(outbuffer + offset, &length_product, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->product, length_product);
      offset += length_product;
      uint32_t length_serial_number = strlen(this->serial_number);
      memcpy(outbuffer + offset, &length_serial_number, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->serial_number, length_serial_number);
      offset += length_serial_number;
      uint32_t length_hardware_rev = strlen(this->hardware_rev);
      memcpy(outbuffer + offset, &length_hardware_rev, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->hardware_rev, length_hardware_rev);
      offset += length_hardware_rev;
      uint32_t length_firmware_rev = strlen(this->firmware_rev);
      memcpy(outbuffer + offset, &length_firmware_rev, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->firmware_rev, length_firmware_rev);
      offset += length_firmware_rev;
      uint32_t length_firmware_date = strlen(this->firmware_date);
      memcpy(outbuffer + offset, &length_firmware_date, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->firmware_date, length_firmware_date);
      offset += length_firmware_date;
      union {
        bool real;
        uint8_t base;
      } u_has_calibration;
      u_has_calibration.real = this->has_calibration;
      *(outbuffer + offset + 0) = (u_has_calibration.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_calibration);
      union {
        bool real;
        uint8_t base;
      } u_controls_grip;
      u_controls_grip.real = this->controls_grip;
      *(outbuffer + offset + 0) = (u_controls_grip.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->controls_grip);
      union {
        bool real;
        uint8_t base;
      } u_senses_grip;
      u_senses_grip.real = this->senses_grip;
      *(outbuffer + offset + 0) = (u_senses_grip.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->senses_grip);
      union {
        bool real;
        uint8_t base;
      } u_reverses_grip;
      u_reverses_grip.real = this->reverses_grip;
      *(outbuffer + offset + 0) = (u_reverses_grip.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->reverses_grip);
      union {
        bool real;
        uint8_t base;
      } u_controls_force;
      u_controls_force.real = this->controls_force;
      *(outbuffer + offset + 0) = (u_controls_force.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->controls_force);
      union {
        bool real;
        uint8_t base;
      } u_senses_force;
      u_senses_force.real = this->senses_force;
      *(outbuffer + offset + 0) = (u_senses_force.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->senses_force);
      union {
        bool real;
        uint8_t base;
      } u_controls_position;
      u_controls_position.real = this->controls_position;
      *(outbuffer + offset + 0) = (u_controls_position.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->controls_position);
      union {
        bool real;
        uint8_t base;
      } u_senses_position;
      u_senses_position.real = this->senses_position;
      *(outbuffer + offset + 0) = (u_senses_position.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->senses_position);
      uint32_t length_properties = strlen(this->properties);
      memcpy(outbuffer + offset, &length_properties, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->properties, length_properties);
      offset += length_properties;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->ui_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ui_type);
      uint32_t length_manufacturer;
      memcpy(&length_manufacturer, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_manufacturer; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_manufacturer-1]=0;
      this->manufacturer = (char *)(inbuffer + offset-1);
      offset += length_manufacturer;
      uint32_t length_product;
      memcpy(&length_product, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_product; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_product-1]=0;
      this->product = (char *)(inbuffer + offset-1);
      offset += length_product;
      uint32_t length_serial_number;
      memcpy(&length_serial_number, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serial_number-1]=0;
      this->serial_number = (char *)(inbuffer + offset-1);
      offset += length_serial_number;
      uint32_t length_hardware_rev;
      memcpy(&length_hardware_rev, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware_rev; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware_rev-1]=0;
      this->hardware_rev = (char *)(inbuffer + offset-1);
      offset += length_hardware_rev;
      uint32_t length_firmware_rev;
      memcpy(&length_firmware_rev, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmware_rev; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmware_rev-1]=0;
      this->firmware_rev = (char *)(inbuffer + offset-1);
      offset += length_firmware_rev;
      uint32_t length_firmware_date;
      memcpy(&length_firmware_date, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmware_date; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmware_date-1]=0;
      this->firmware_date = (char *)(inbuffer + offset-1);
      offset += length_firmware_date;
      union {
        bool real;
        uint8_t base;
      } u_has_calibration;
      u_has_calibration.base = 0;
      u_has_calibration.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_calibration = u_has_calibration.real;
      offset += sizeof(this->has_calibration);
      union {
        bool real;
        uint8_t base;
      } u_controls_grip;
      u_controls_grip.base = 0;
      u_controls_grip.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->controls_grip = u_controls_grip.real;
      offset += sizeof(this->controls_grip);
      union {
        bool real;
        uint8_t base;
      } u_senses_grip;
      u_senses_grip.base = 0;
      u_senses_grip.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->senses_grip = u_senses_grip.real;
      offset += sizeof(this->senses_grip);
      union {
        bool real;
        uint8_t base;
      } u_reverses_grip;
      u_reverses_grip.base = 0;
      u_reverses_grip.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->reverses_grip = u_reverses_grip.real;
      offset += sizeof(this->reverses_grip);
      union {
        bool real;
        uint8_t base;
      } u_controls_force;
      u_controls_force.base = 0;
      u_controls_force.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->controls_force = u_controls_force.real;
      offset += sizeof(this->controls_force);
      union {
        bool real;
        uint8_t base;
      } u_senses_force;
      u_senses_force.base = 0;
      u_senses_force.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->senses_force = u_senses_force.real;
      offset += sizeof(this->senses_force);
      union {
        bool real;
        uint8_t base;
      } u_controls_position;
      u_controls_position.base = 0;
      u_controls_position.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->controls_position = u_controls_position.real;
      offset += sizeof(this->controls_position);
      union {
        bool real;
        uint8_t base;
      } u_senses_position;
      u_senses_position.base = 0;
      u_senses_position.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->senses_position = u_senses_position.real;
      offset += sizeof(this->senses_position);
      uint32_t length_properties;
      memcpy(&length_properties, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_properties; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_properties-1]=0;
      this->properties = (char *)(inbuffer + offset-1);
      offset += length_properties;
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/EndEffectorProperties"; };
    const char * getMD5(){ return "21b83773ab9a35216d11e427573c76cc"; };

  };

}
#endif