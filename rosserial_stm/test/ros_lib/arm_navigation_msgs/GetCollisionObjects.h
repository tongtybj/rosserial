#ifndef _ROS_SERVICE_GetCollisionObjects_h
#define _ROS_SERVICE_GetCollisionObjects_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/CollisionMap.h"
#include "arm_navigation_msgs/CollisionObject.h"
#include "arm_navigation_msgs/AttachedCollisionObject.h"

namespace arm_navigation_msgs
{

static const char GETCOLLISIONOBJECTS[] = "arm_navigation_msgs/GetCollisionObjects";

  class GetCollisionObjectsRequest : public ros::Msg
  {
    public:
      bool include_points;

    GetCollisionObjectsRequest():
      include_points(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_include_points;
      u_include_points.real = this->include_points;
      *(outbuffer + offset + 0) = (u_include_points.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->include_points);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_include_points;
      u_include_points.base = 0;
      u_include_points.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->include_points = u_include_points.real;
      offset += sizeof(this->include_points);
     return offset;
    }

    const char * getType(){ return GETCOLLISIONOBJECTS; };
    const char * getMD5(){ return "3ae7288b23c84452d229e442c1673708"; };

  };

  class GetCollisionObjectsResponse : public ros::Msg
  {
    public:
      arm_navigation_msgs::CollisionMap points;
      uint8_t collision_objects_length;
      arm_navigation_msgs::CollisionObject st_collision_objects;
      arm_navigation_msgs::CollisionObject * collision_objects;
      uint8_t attached_collision_objects_length;
      arm_navigation_msgs::AttachedCollisionObject st_attached_collision_objects;
      arm_navigation_msgs::AttachedCollisionObject * attached_collision_objects;

    GetCollisionObjectsResponse():
      points(),
      collision_objects_length(0), collision_objects(NULL),
      attached_collision_objects_length(0), attached_collision_objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->points.serialize(outbuffer + offset);
      *(outbuffer + offset++) = collision_objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < collision_objects_length; i++){
      offset += this->collision_objects[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = attached_collision_objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < attached_collision_objects_length; i++){
      offset += this->attached_collision_objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->points.deserialize(inbuffer + offset);
      uint8_t collision_objects_lengthT = *(inbuffer + offset++);
      if(collision_objects_lengthT > collision_objects_length)
        this->collision_objects = (arm_navigation_msgs::CollisionObject*)realloc(this->collision_objects, collision_objects_lengthT * sizeof(arm_navigation_msgs::CollisionObject));
      offset += 3;
      collision_objects_length = collision_objects_lengthT;
      for( uint8_t i = 0; i < collision_objects_length; i++){
      offset += this->st_collision_objects.deserialize(inbuffer + offset);
        memcpy( &(this->collision_objects[i]), &(this->st_collision_objects), sizeof(arm_navigation_msgs::CollisionObject));
      }
      uint8_t attached_collision_objects_lengthT = *(inbuffer + offset++);
      if(attached_collision_objects_lengthT > attached_collision_objects_length)
        this->attached_collision_objects = (arm_navigation_msgs::AttachedCollisionObject*)realloc(this->attached_collision_objects, attached_collision_objects_lengthT * sizeof(arm_navigation_msgs::AttachedCollisionObject));
      offset += 3;
      attached_collision_objects_length = attached_collision_objects_lengthT;
      for( uint8_t i = 0; i < attached_collision_objects_length; i++){
      offset += this->st_attached_collision_objects.deserialize(inbuffer + offset);
        memcpy( &(this->attached_collision_objects[i]), &(this->st_attached_collision_objects), sizeof(arm_navigation_msgs::AttachedCollisionObject));
      }
     return offset;
    }

    const char * getType(){ return GETCOLLISIONOBJECTS; };
    const char * getMD5(){ return "c361b849f4eb74ea667a930b0b9dc801"; };

  };

  class GetCollisionObjects {
    public:
    typedef GetCollisionObjectsRequest Request;
    typedef GetCollisionObjectsResponse Response;
  };

}
#endif
