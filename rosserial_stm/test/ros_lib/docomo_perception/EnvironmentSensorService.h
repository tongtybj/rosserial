#ifndef _ROS_SERVICE_EnvironmentSensorService_h
#define _ROS_SERVICE_EnvironmentSensorService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "docomo_perception/EnvironmentSensor.h"

namespace docomo_perception
{

static const char ENVIRONMENTSENSORSERVICE[] = "docomo_perception/EnvironmentSensorService";

  class EnvironmentSensorServiceRequest : public ros::Msg
  {
    public:
      uint8_t base_id_length;
      char* st_base_id;
      char* * base_id;
      float latitude;
      float longtitude;
      float range;

    EnvironmentSensorServiceRequest():
      base_id_length(0), base_id(NULL),
      latitude(0),
      longtitude(0),
      range(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = base_id_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < base_id_length; i++){
      uint32_t length_base_idi = strlen(this->base_id[i]);
      memcpy(outbuffer + offset, &length_base_idi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->base_id[i], length_base_idi);
      offset += length_base_idi;
      }
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
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t base_id_lengthT = *(inbuffer + offset++);
      if(base_id_lengthT > base_id_length)
        this->base_id = (char**)realloc(this->base_id, base_id_lengthT * sizeof(char*));
      offset += 3;
      base_id_length = base_id_lengthT;
      for( uint8_t i = 0; i < base_id_length; i++){
      uint32_t length_st_base_id;
      memcpy(&length_st_base_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_base_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_base_id-1]=0;
      this->st_base_id = (char *)(inbuffer + offset-1);
      offset += length_st_base_id;
        memcpy( &(this->base_id[i]), &(this->st_base_id), sizeof(char*));
      }
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
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range = u_range.real;
      offset += sizeof(this->range);
     return offset;
    }

    const char * getType(){ return ENVIRONMENTSENSORSERVICE; };
    const char * getMD5(){ return "2105b305a00250e9bdb37a23dd72657f"; };

  };

  class EnvironmentSensorServiceResponse : public ros::Msg
  {
    public:
      uint8_t data_length;
      docomo_perception::EnvironmentSensor st_data;
      docomo_perception::EnvironmentSensor * data;

    EnvironmentSensorServiceResponse():
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (docomo_perception::EnvironmentSensor*)realloc(this->data, data_lengthT * sizeof(docomo_perception::EnvironmentSensor));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(docomo_perception::EnvironmentSensor));
      }
     return offset;
    }

    const char * getType(){ return ENVIRONMENTSENSORSERVICE; };
    const char * getMD5(){ return "0853ca911db00f293de5723a2f3dbbaa"; };

  };

  class EnvironmentSensorService {
    public:
    typedef EnvironmentSensorServiceRequest Request;
    typedef EnvironmentSensorServiceResponse Response;
  };

}
#endif
