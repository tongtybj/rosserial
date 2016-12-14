#ifndef _ROS_pal_vision_msgs_HogDetection_h
#define _ROS_pal_vision_msgs_HogDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_vision_msgs/Rectangle.h"
#include "geometry_msgs/Vector3.h"
#include "std_msgs/ColorRGBA.h"

namespace pal_vision_msgs
{

  class HogDetection : public ros::Msg
  {
    public:
      pal_vision_msgs::Rectangle imageBoundingBox;
      geometry_msgs::Vector3 direction;
      uint8_t hog_length;
      float st_hog;
      float * hog;
      std_msgs::ColorRGBA principalEigenVectorRGB;
      uint8_t rgbClusterCenters_length;
      std_msgs::ColorRGBA st_rgbClusterCenters;
      std_msgs::ColorRGBA * rgbClusterCenters;
      uint8_t rgbDescriptor1_length;
      uint32_t st_rgbDescriptor1;
      uint32_t * rgbDescriptor1;
      uint8_t rgbDescriptor2_length;
      uint32_t st_rgbDescriptor2;
      uint32_t * rgbDescriptor2;

    HogDetection():
      imageBoundingBox(),
      direction(),
      hog_length(0), hog(NULL),
      principalEigenVectorRGB(),
      rgbClusterCenters_length(0), rgbClusterCenters(NULL),
      rgbDescriptor1_length(0), rgbDescriptor1(NULL),
      rgbDescriptor2_length(0), rgbDescriptor2(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->imageBoundingBox.serialize(outbuffer + offset);
      offset += this->direction.serialize(outbuffer + offset);
      *(outbuffer + offset++) = hog_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < hog_length; i++){
      union {
        float real;
        uint32_t base;
      } u_hogi;
      u_hogi.real = this->hog[i];
      *(outbuffer + offset + 0) = (u_hogi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hogi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hogi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hogi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hog[i]);
      }
      offset += this->principalEigenVectorRGB.serialize(outbuffer + offset);
      *(outbuffer + offset++) = rgbClusterCenters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rgbClusterCenters_length; i++){
      offset += this->rgbClusterCenters[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = rgbDescriptor1_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rgbDescriptor1_length; i++){
      *(outbuffer + offset + 0) = (this->rgbDescriptor1[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rgbDescriptor1[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rgbDescriptor1[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rgbDescriptor1[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rgbDescriptor1[i]);
      }
      *(outbuffer + offset++) = rgbDescriptor2_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < rgbDescriptor2_length; i++){
      *(outbuffer + offset + 0) = (this->rgbDescriptor2[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rgbDescriptor2[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rgbDescriptor2[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rgbDescriptor2[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rgbDescriptor2[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->imageBoundingBox.deserialize(inbuffer + offset);
      offset += this->direction.deserialize(inbuffer + offset);
      uint8_t hog_lengthT = *(inbuffer + offset++);
      if(hog_lengthT > hog_length)
        this->hog = (float*)realloc(this->hog, hog_lengthT * sizeof(float));
      offset += 3;
      hog_length = hog_lengthT;
      for( uint8_t i = 0; i < hog_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_hog;
      u_st_hog.base = 0;
      u_st_hog.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_hog.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_hog.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_hog.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_hog = u_st_hog.real;
      offset += sizeof(this->st_hog);
        memcpy( &(this->hog[i]), &(this->st_hog), sizeof(float));
      }
      offset += this->principalEigenVectorRGB.deserialize(inbuffer + offset);
      uint8_t rgbClusterCenters_lengthT = *(inbuffer + offset++);
      if(rgbClusterCenters_lengthT > rgbClusterCenters_length)
        this->rgbClusterCenters = (std_msgs::ColorRGBA*)realloc(this->rgbClusterCenters, rgbClusterCenters_lengthT * sizeof(std_msgs::ColorRGBA));
      offset += 3;
      rgbClusterCenters_length = rgbClusterCenters_lengthT;
      for( uint8_t i = 0; i < rgbClusterCenters_length; i++){
      offset += this->st_rgbClusterCenters.deserialize(inbuffer + offset);
        memcpy( &(this->rgbClusterCenters[i]), &(this->st_rgbClusterCenters), sizeof(std_msgs::ColorRGBA));
      }
      uint8_t rgbDescriptor1_lengthT = *(inbuffer + offset++);
      if(rgbDescriptor1_lengthT > rgbDescriptor1_length)
        this->rgbDescriptor1 = (uint32_t*)realloc(this->rgbDescriptor1, rgbDescriptor1_lengthT * sizeof(uint32_t));
      offset += 3;
      rgbDescriptor1_length = rgbDescriptor1_lengthT;
      for( uint8_t i = 0; i < rgbDescriptor1_length; i++){
      this->st_rgbDescriptor1 =  ((uint32_t) (*(inbuffer + offset)));
      this->st_rgbDescriptor1 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_rgbDescriptor1 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_rgbDescriptor1 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_rgbDescriptor1);
        memcpy( &(this->rgbDescriptor1[i]), &(this->st_rgbDescriptor1), sizeof(uint32_t));
      }
      uint8_t rgbDescriptor2_lengthT = *(inbuffer + offset++);
      if(rgbDescriptor2_lengthT > rgbDescriptor2_length)
        this->rgbDescriptor2 = (uint32_t*)realloc(this->rgbDescriptor2, rgbDescriptor2_lengthT * sizeof(uint32_t));
      offset += 3;
      rgbDescriptor2_length = rgbDescriptor2_lengthT;
      for( uint8_t i = 0; i < rgbDescriptor2_length; i++){
      this->st_rgbDescriptor2 =  ((uint32_t) (*(inbuffer + offset)));
      this->st_rgbDescriptor2 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_rgbDescriptor2 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_rgbDescriptor2 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_rgbDescriptor2);
        memcpy( &(this->rgbDescriptor2[i]), &(this->st_rgbDescriptor2), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "pal_vision_msgs/HogDetection"; };
    const char * getMD5(){ return "33e1731149b6e078eff6e4b55c75f260"; };

  };

}
#endif