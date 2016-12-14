#ifndef _ROS_arm_navigation_msgs_CollisionMap_h
#define _ROS_arm_navigation_msgs_CollisionMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "arm_navigation_msgs/OrientedBoundingBox.h"

namespace arm_navigation_msgs
{

  class CollisionMap : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t boxes_length;
      arm_navigation_msgs::OrientedBoundingBox st_boxes;
      arm_navigation_msgs::OrientedBoundingBox * boxes;

    CollisionMap():
      header(),
      boxes_length(0), boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = boxes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < boxes_length; i++){
      offset += this->boxes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t boxes_lengthT = *(inbuffer + offset++);
      if(boxes_lengthT > boxes_length)
        this->boxes = (arm_navigation_msgs::OrientedBoundingBox*)realloc(this->boxes, boxes_lengthT * sizeof(arm_navigation_msgs::OrientedBoundingBox));
      offset += 3;
      boxes_length = boxes_lengthT;
      for( uint8_t i = 0; i < boxes_length; i++){
      offset += this->st_boxes.deserialize(inbuffer + offset);
        memcpy( &(this->boxes[i]), &(this->st_boxes), sizeof(arm_navigation_msgs::OrientedBoundingBox));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/CollisionMap"; };
    const char * getMD5(){ return "18ca54db41ccebbe82f61f9801dede89"; };

  };

}
#endif