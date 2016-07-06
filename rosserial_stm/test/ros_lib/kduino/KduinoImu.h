#ifndef _ROS_kduino_KduinoImu_h
#define _ROS_kduino_KduinoImu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace kduino
{

  class KduinoImu : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int16_t accData[3];
      int16_t gyroData[3];
      int16_t magData[3];
      float angle[3];
      float altitude;
      float baroPressure;
      float baroTemperature;

    KduinoImu():
      header(),
      accData(),
      gyroData(),
      magData(),
      angle(),
      altitude(0),
      baroPressure(0),
      baroTemperature(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_accDatai;
      u_accDatai.real = this->accData[i];
      *(outbuffer + offset + 0) = (u_accDatai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accDatai.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->accData[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_gyroDatai;
      u_gyroDatai.real = this->gyroData[i];
      *(outbuffer + offset + 0) = (u_gyroDatai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyroDatai.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyroData[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_magDatai;
      u_magDatai.real = this->magData[i];
      *(outbuffer + offset + 0) = (u_magDatai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magDatai.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->magData[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_anglei;
      u_anglei.real = this->angle[i];
      *(outbuffer + offset + 0) = (u_anglei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anglei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anglei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anglei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_baroPressure;
      u_baroPressure.real = this->baroPressure;
      *(outbuffer + offset + 0) = (u_baroPressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_baroPressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_baroPressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_baroPressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->baroPressure);
      union {
        float real;
        uint32_t base;
      } u_baroTemperature;
      u_baroTemperature.real = this->baroTemperature;
      *(outbuffer + offset + 0) = (u_baroTemperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_baroTemperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_baroTemperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_baroTemperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->baroTemperature);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_accDatai;
      u_accDatai.base = 0;
      u_accDatai.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accDatai.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->accData[i] = u_accDatai.real;
      offset += sizeof(this->accData[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_gyroDatai;
      u_gyroDatai.base = 0;
      u_gyroDatai.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyroDatai.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyroData[i] = u_gyroDatai.real;
      offset += sizeof(this->gyroData[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_magDatai;
      u_magDatai.base = 0;
      u_magDatai.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magDatai.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->magData[i] = u_magDatai.real;
      offset += sizeof(this->magData[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_anglei;
      u_anglei.base = 0;
      u_anglei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_anglei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_anglei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_anglei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle[i] = u_anglei.real;
      offset += sizeof(this->angle[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_baroPressure;
      u_baroPressure.base = 0;
      u_baroPressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_baroPressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_baroPressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_baroPressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->baroPressure = u_baroPressure.real;
      offset += sizeof(this->baroPressure);
      union {
        float real;
        uint32_t base;
      } u_baroTemperature;
      u_baroTemperature.base = 0;
      u_baroTemperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_baroTemperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_baroTemperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_baroTemperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->baroTemperature = u_baroTemperature.real;
      offset += sizeof(this->baroTemperature);
     return offset;
    }

    const char * getType(){ return "kduino/KduinoImu"; };
    const char * getMD5(){ return "a2caa3265265e853c7ad71e9b269bba8"; };

  };

}
#endif