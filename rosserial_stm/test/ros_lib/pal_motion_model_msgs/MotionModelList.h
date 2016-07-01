#ifndef _ROS_pal_motion_model_msgs_MotionModelList_h
#define _ROS_pal_motion_model_msgs_MotionModelList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_motion_model_msgs/MotionModel.h"

namespace pal_motion_model_msgs
{

  class MotionModelList : public ros::Msg
  {
    public:
      uint8_t models_length;
      pal_motion_model_msgs::MotionModel st_models;
      pal_motion_model_msgs::MotionModel * models;

    MotionModelList():
      models_length(0), models(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = models_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < models_length; i++){
      offset += this->models[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t models_lengthT = *(inbuffer + offset++);
      if(models_lengthT > models_length)
        this->models = (pal_motion_model_msgs::MotionModel*)realloc(this->models, models_lengthT * sizeof(pal_motion_model_msgs::MotionModel));
      offset += 3;
      models_length = models_lengthT;
      for( uint8_t i = 0; i < models_length; i++){
      offset += this->st_models.deserialize(inbuffer + offset);
        memcpy( &(this->models[i]), &(this->st_models), sizeof(pal_motion_model_msgs::MotionModel));
      }
     return offset;
    }

    const char * getType(){ return "pal_motion_model_msgs/MotionModelList"; };
    const char * getMD5(){ return "f24b8d6d6a0a1542de28f172c2da67ff"; };

  };

}
#endif