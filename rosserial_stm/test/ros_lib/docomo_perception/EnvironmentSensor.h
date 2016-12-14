#ifndef _ROS_docomo_perception_EnvironmentSensor_h
#define _ROS_docomo_perception_EnvironmentSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace docomo_perception
{

  class EnvironmentSensor : public ros::Msg
  {
    public:
      const char* base_id;
      const char* name;
      const char* prefecture;
      const char* city;
      float latitude;
      float longtitude;
      float temperature;
      float precipitation;
      float uv_index;

    EnvironmentSensor():
      base_id(""),
      name(""),
      prefecture(""),
      city(""),
      latitude(0),
      longtitude(0),
      temperature(0),
      precipitation(0),
      uv_index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_base_id = strlen(this->base_id);
      memcpy(outbuffer + offset, &length_base_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->base_id, length_base_id);
      offset += length_base_id;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_prefecture = strlen(this->prefecture);
      memcpy(outbuffer + offset, &length_prefecture, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->prefecture, length_prefecture);
      offset += length_prefecture;
      uint32_t length_city = strlen(this->city);
      memcpy(outbuffer + offset, &length_city, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->city, length_city);
      offset += length_city;
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longtitude;
      u_longtitude.real = this->longtitude;
      *(outbuffer + offset + 0) = (u_longtitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longtitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longtitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longtitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longtitude);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      union {
        float real;
        uint32_t base;
      } u_precipitation;
      u_precipitation.real = this->precipitation;
      *(outbuffer + offset + 0) = (u_precipitation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_precipitation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_precipitation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_precipitation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->precipitation);
      union {
        float real;
        uint32_t base;
      } u_uv_index;
      u_uv_index.real = this->uv_index;
      *(outbuffer + offset + 0) = (u_uv_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_uv_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_uv_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_uv_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uv_index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_base_id;
      memcpy(&length_base_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_base_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_base_id-1]=0;
      this->base_id = (char *)(inbuffer + offset-1);
      offset += length_base_id;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_prefecture;
      memcpy(&length_prefecture, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_prefecture; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_prefecture-1]=0;
      this->prefecture = (char *)(inbuffer + offset-1);
      offset += length_prefecture;
      uint32_t length_city;
      memcpy(&length_city, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_city; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_city-1]=0;
      this->city = (char *)(inbuffer + offset-1);
      offset += length_city;
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longtitude;
      u_longtitude.base = 0;
      u_longtitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longtitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longtitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longtitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longtitude = u_longtitude.real;
      offset += sizeof(this->longtitude);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      union {
        float real;
        uint32_t base;
      } u_precipitation;
      u_precipitation.base = 0;
      u_precipitation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_precipitation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_precipitation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_precipitation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->precipitation = u_precipitation.real;
      offset += sizeof(this->precipitation);
      union {
        float real;
        uint32_t base;
      } u_uv_index;
      u_uv_index.base = 0;
      u_uv_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_uv_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_uv_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_uv_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->uv_index = u_uv_index.real;
      offset += sizeof(this->uv_index);
     return offset;
    }

    const char * getType(){ return "docomo_perception/EnvironmentSensor"; };
    const char * getMD5(){ return "f8a347235df821884b86bd68d981d946"; };

  };

}
#endif