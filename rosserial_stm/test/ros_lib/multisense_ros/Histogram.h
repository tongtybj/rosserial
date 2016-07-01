#ifndef _ROS_multisense_ros_Histogram_h
#define _ROS_multisense_ros_Histogram_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace multisense_ros
{

  class Histogram : public ros::Msg
  {
    public:
      int64_t frame_count;
      ros::Time time_stamp;
      uint32_t width;
      uint32_t height;
      float gain;
      float fps;
      uint32_t exposure_time;
      uint32_t channels;
      uint32_t bins;
      uint8_t data_length;
      uint32_t st_data;
      uint32_t * data;

    Histogram():
      frame_count(0),
      time_stamp(),
      width(0),
      height(0),
      gain(0),
      fps(0),
      exposure_time(0),
      channels(0),
      bins(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_frame_count;
      u_frame_count.real = this->frame_count;
      *(outbuffer + offset + 0) = (u_frame_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frame_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frame_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frame_count.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_frame_count.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_frame_count.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_frame_count.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_frame_count.base >> (8 * 7)) & 0xFF;
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
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
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
      union {
        float real;
        uint32_t base;
      } u_fps;
      u_fps.real = this->fps;
      *(outbuffer + offset + 0) = (u_fps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fps);
      *(outbuffer + offset + 0) = (this->exposure_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->exposure_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->exposure_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->exposure_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exposure_time);
      *(outbuffer + offset + 0) = (this->channels >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channels >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channels >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channels >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channels);
      *(outbuffer + offset + 0) = (this->bins >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bins >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bins >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bins >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bins);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_frame_count;
      u_frame_count.base = 0;
      u_frame_count.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frame_count.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frame_count.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frame_count.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_frame_count.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_frame_count.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_frame_count.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_frame_count.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->frame_count = u_frame_count.real;
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
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
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
      union {
        float real;
        uint32_t base;
      } u_fps;
      u_fps.base = 0;
      u_fps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fps = u_fps.real;
      offset += sizeof(this->fps);
      this->exposure_time =  ((uint32_t) (*(inbuffer + offset)));
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->exposure_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->exposure_time);
      this->channels =  ((uint32_t) (*(inbuffer + offset)));
      this->channels |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->channels |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->channels |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->channels);
      this->bins =  ((uint32_t) (*(inbuffer + offset)));
      this->bins |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->bins |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->bins |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->bins);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (uint32_t*)realloc(this->data, data_lengthT * sizeof(uint32_t));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      this->st_data =  ((uint32_t) (*(inbuffer + offset)));
      this->st_data |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_data |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_data |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "multisense_ros/Histogram"; };
    const char * getMD5(){ return "e45112edc9190cff95413a65cb22f694"; };

  };

}
#endif