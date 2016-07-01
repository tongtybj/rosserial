#ifndef _ROS_pal_motion_model_msgs_MotionModelMap_h
#define _ROS_pal_motion_model_msgs_MotionModelMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nav_msgs/MapMetaData.h"
#include "pal_motion_model_msgs/MotionModelList.h"

namespace pal_motion_model_msgs
{

  class MotionModelMap : public ros::Msg
  {
    public:
      std_msgs::Header header;
      nav_msgs::MapMetaData info;
      uint8_t data_length;
      pal_motion_model_msgs::MotionModelList st_data;
      pal_motion_model_msgs::MotionModelList * data;

    MotionModelMap():
      header(),
      info(),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
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
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->info.deserialize(inbuffer + offset);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (pal_motion_model_msgs::MotionModelList*)realloc(this->data, data_lengthT * sizeof(pal_motion_model_msgs::MotionModelList));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(pal_motion_model_msgs::MotionModelList));
      }
     return offset;
    }

    const char * getType(){ return "pal_motion_model_msgs/MotionModelMap"; };
    const char * getMD5(){ return "b6bcccd2088596e98ba83bc65b2b504e"; };

  };

}
#endif