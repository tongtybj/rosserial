#ifndef _ROS_arm_navigation_msgs_OrderedCollisionOperations_h
#define _ROS_arm_navigation_msgs_OrderedCollisionOperations_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/CollisionOperation.h"

namespace arm_navigation_msgs
{

  class OrderedCollisionOperations : public ros::Msg
  {
    public:
      uint8_t collision_operations_length;
      arm_navigation_msgs::CollisionOperation st_collision_operations;
      arm_navigation_msgs::CollisionOperation * collision_operations;

    OrderedCollisionOperations():
      collision_operations_length(0), collision_operations(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = collision_operations_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < collision_operations_length; i++){
      offset += this->collision_operations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t collision_operations_lengthT = *(inbuffer + offset++);
      if(collision_operations_lengthT > collision_operations_length)
        this->collision_operations = (arm_navigation_msgs::CollisionOperation*)realloc(this->collision_operations, collision_operations_lengthT * sizeof(arm_navigation_msgs::CollisionOperation));
      offset += 3;
      collision_operations_length = collision_operations_lengthT;
      for( uint8_t i = 0; i < collision_operations_length; i++){
      offset += this->st_collision_operations.deserialize(inbuffer + offset);
        memcpy( &(this->collision_operations[i]), &(this->st_collision_operations), sizeof(arm_navigation_msgs::CollisionOperation));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/OrderedCollisionOperations"; };
    const char * getMD5(){ return "f171f973b185d4d0121795080114026a"; };

  };

}
#endif