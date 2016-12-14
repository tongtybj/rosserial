#ifndef _ROS_multisense_ros_RawCamData_h
#define _ROS_multisense_ros_RawCamData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace multisense_ros
{

  class RawCamData : public ros::Msg
  {
    public:
      float frames_per_second;
      float gain;
      uint32_t exposure_time;
      uint32_t frame_count;
      ros::Time time_stamp;
      uint32_t angle;
      uint16_t width;
      uint16_t height;
      uint8_t gray_scale_image_length;
      uint8_t st_gray_scale_image;
      uint8_t * gray_scale_image;
      uint8_t disparity_image_length;
      uint16_t st_disparity_image;
      uint16_t * disparity_image;

    RawCamData():
      frames_per_second(0),
      gain(0),
      exposure_time(0),
      frame_count(0),
      time_stamp(),
      angle(0),
      width(0),
      height(0),
      gray_scale_image_length(0), gray_scale_image(NULL),
      disparity_image_length(0), disparity_image(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_frames_per_second;
      u_frames_per_second.real = this->frames_per_second;
      *(outbuffer + offset + 0) = (u_frames_per_second.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frames_per_second.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frames_per_second.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frames_per_second.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frames_per_second);
      union {
        float real;
        uint32_t base;
      } u_gain;
      u_gain.real = this->gain;
      *(outbuffer + offset + 0) = (u_gain.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gain.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gain.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gain.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gain);
      *(outbuffer + offset + 0) = (this->exposure_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->exposure_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->exposure_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->exposure_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exposure_time);
      *(outbuffer + offset + 0) = (this->frame_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frame_count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frame_count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frame_count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frame_count);
      *(outbuffer + offset + 0) = (this->time_stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_stamp.sec);
      *(outbuffer + offset + 0) = (this->time_stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_stamp.nsec);
      *(outbuffer + offset + 0) = (this->angle >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angle >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->angle >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->angle >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset++) = gray_scale_image_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < gray_scale_image_length; i++){
      *(outbuffer + offset + 0) = (this->gray_scale_image[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gray_scale_image[i]);
      }
      *(outbuffer + offset++) = disparity_image_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < disparity_image_length; i++){
      *(outbuffer + offset + 0) = (this->disparity_image[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->disparity_image[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->disparity_image[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_frames_per_second;
      u_frames_per_second.base = 0;
      u_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frames_per_second = u_frames_per_second.real;
      offset += sizeof(this->frames_per_second);
      union {
        float real;
        uint32_t base;
      } u_gain;
      u_gain.base = 0;
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gain.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gain = u_gain.real;
      offset += sizeof(this->gain);
      this->exposure_time =  ((uint32_t) (*(inbuffer + offset)));
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->exposure_time);
      this->frame_count =  ((uint32_t) (*(inbuffer + offset)));
      this->frame_count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->frame_count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->frame_count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->frame_count);
      this->time_stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_stamp.sec);
      this->time_stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_stamp.nsec);
      this->angle =  ((uint32_t) (*(inbuffer + offset)));
      this->angle |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->angle |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->angle |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->angle);
      this->width =  ((uint16_t) (*(inbuffer + offset)));
      this->width |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->width);
      this->height =  ((uint16_t) (*(inbuffer + offset)));
      this->height |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->height);
      uint8_t gray_scale_image_lengthT = *(inbuffer + offset++);
      if(gray_scale_image_lengthT > gray_scale_image_length)
        this->gray_scale_image = (uint8_t*)realloc(this->gray_scale_image, gray_scale_image_lengthT * sizeof(uint8_t));
      offset += 3;
      gray_scale_image_length = gray_scale_image_lengthT;
      for( uint8_t i = 0; i < gray_scale_image_length; i++){
      this->st_gray_scale_image =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_gray_scale_image);
        memcpy( &(this->gray_scale_image[i]), &(this->st_gray_scale_image), sizeof(uint8_t));
      }
      uint8_t disparity_image_lengthT = *(inbuffer + offset++);
      if(disparity_image_lengthT > disparity_image_length)
        this->disparity_image = (uint16_t*)realloc(this->disparity_image, disparity_image_lengthT * sizeof(uint16_t));
      offset += 3;
      disparity_image_length = disparity_image_lengthT;
      for( uint8_t i = 0; i < disparity_image_length; i++){
      this->st_disparity_image =  ((uint16_t) (*(inbuffer + offset)));
      this->st_disparity_image |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_disparity_image);
        memcpy( &(this->disparity_image[i]), &(this->st_disparity_image), sizeof(uint16_t));
      }
     return offset;
    }

    const char * getType(){ return "multisense_ros/RawCamData"; };
    const char * getMD5(){ return "5088c19778d4fa49ece5e07c0880c7e3"; };

  };

}
#endif