#ifndef _ROS_ml_classifiers_ClassDataPoint_h
#define _ROS_ml_classifiers_ClassDataPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ml_classifiers
{

  class ClassDataPoint : public ros::Msg
  {
    public:
      const char* target_class;
      uint8_t point_length;
      double st_point;
      double * point;

    ClassDataPoint():
      target_class(""),
      point_length(0), point(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_target_class = strlen(this->target_class);
      memcpy(outbuffer + offset, &length_target_class, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_class, length_target_class);
      offset += length_target_class;
      *(outbuffer + offset++) = point_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < point_length; i++){
      union {
        double real;
        uint64_t base;
      } u_pointi;
      u_pointi.real = this->point[i];
      *(outbuffer + offset + 0) = (u_pointi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pointi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pointi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pointi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pointi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pointi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pointi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pointi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->point[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_target_class;
      memcpy(&length_target_class, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_class; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_class-1]=0;
      this->target_class = (char *)(inbuffer + offset-1);
      offset += length_target_class;
      uint8_t point_lengthT = *(inbuffer + offset++);
      if(point_lengthT > point_length)
        this->point = (double*)realloc(this->point, point_lengthT * sizeof(double));
      offset += 3;
      point_length = point_lengthT;
      for( uint8_t i = 0; i < point_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_point;
      u_st_point.base = 0;
      u_st_point.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_point.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_point.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_point.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_point.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_point.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_point.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_point.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_point = u_st_point.real;
      offset += sizeof(this->st_point);
        memcpy( &(this->point[i]), &(this->st_point), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "ml_classifiers/ClassDataPoint"; };
    const char * getMD5(){ return "46bea2d2ef979a71ef0bfa470e5978ff"; };

  };

}
#endif