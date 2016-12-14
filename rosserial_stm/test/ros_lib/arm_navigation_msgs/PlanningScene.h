#ifndef _ROS_arm_navigation_msgs_PlanningScene_h
#define _ROS_arm_navigation_msgs_PlanningScene_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/RobotState.h"
#include "geometry_msgs/TransformStamped.h"
#include "arm_navigation_msgs/AllowedCollisionMatrix.h"
#include "arm_navigation_msgs/AllowedContactSpecification.h"
#include "arm_navigation_msgs/LinkPadding.h"
#include "arm_navigation_msgs/CollisionObject.h"
#include "arm_navigation_msgs/AttachedCollisionObject.h"
#include "arm_navigation_msgs/CollisionMap.h"

namespace arm_navigation_msgs
{

  class PlanningScene : public ros::Msg
  {
    public:
      arm_navigation_msgs::RobotState robot_state;
      uint8_t fixed_frame_transforms_length;
      geometry_msgs::TransformStamped st_fixed_frame_transforms;
      geometry_msgs::TransformStamped * fixed_frame_transforms;
      arm_navigation_msgs::AllowedCollisionMatrix allowed_collision_matrix;
      uint8_t allowed_contacts_length;
      arm_navigation_msgs::AllowedContactSpecification st_allowed_contacts;
      arm_navigation_msgs::AllowedContactSpecification * allowed_contacts;
      uint8_t link_padding_length;
      arm_navigation_msgs::LinkPadding st_link_padding;
      arm_navigation_msgs::LinkPadding * link_padding;
      uint8_t collision_objects_length;
      arm_navigation_msgs::CollisionObject st_collision_objects;
      arm_navigation_msgs::CollisionObject * collision_objects;
      uint8_t attached_collision_objects_length;
      arm_navigation_msgs::AttachedCollisionObject st_attached_collision_objects;
      arm_navigation_msgs::AttachedCollisionObject * attached_collision_objects;
      arm_navigation_msgs::CollisionMap collision_map;

    PlanningScene():
      robot_state(),
      fixed_frame_transforms_length(0), fixed_frame_transforms(NULL),
      allowed_collision_matrix(),
      allowed_contacts_length(0), allowed_contacts(NULL),
      link_padding_length(0), link_padding(NULL),
      collision_objects_length(0), collision_objects(NULL),
      attached_collision_objects_length(0), attached_collision_objects(NULL),
      collision_map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_state.serialize(outbuffer + offset);
      *(outbuffer + offset++) = fixed_frame_transforms_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fixed_frame_transforms_length; i++){
      offset += this->fixed_frame_transforms[i].serialize(outbuffer + offset);
      }
      offset += this->allowed_collision_matrix.serialize(outbuffer + offset);
      *(outbuffer + offset++) = allowed_contacts_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < allowed_contacts_length; i++){
      offset += this->allowed_contacts[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = link_padding_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < link_padding_length; i++){
      offset += this->link_padding[i].serialize(outbuffer + offset);
      }
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
      offset += this->collision_map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_state.deserialize(inbuffer + offset);
      uint8_t fixed_frame_transforms_lengthT = *(inbuffer + offset++);
      if(fixed_frame_transforms_lengthT > fixed_frame_transforms_length)
        this->fixed_frame_transforms = (geometry_msgs::TransformStamped*)realloc(this->fixed_frame_transforms, fixed_frame_transforms_lengthT * sizeof(geometry_msgs::TransformStamped));
      offset += 3;
      fixed_frame_transforms_length = fixed_frame_transforms_lengthT;
      for( uint8_t i = 0; i < fixed_frame_transforms_length; i++){
      offset += this->st_fixed_frame_transforms.deserialize(inbuffer + offset);
        memcpy( &(this->fixed_frame_transforms[i]), &(this->st_fixed_frame_transforms), sizeof(geometry_msgs::TransformStamped));
      }
      offset += this->allowed_collision_matrix.deserialize(inbuffer + offset);
      uint8_t allowed_contacts_lengthT = *(inbuffer + offset++);
      if(allowed_contacts_lengthT > allowed_contacts_length)
        this->allowed_contacts = (arm_navigation_msgs::AllowedContactSpecification*)realloc(this->allowed_contacts, allowed_contacts_lengthT * sizeof(arm_navigation_msgs::AllowedContactSpecification));
      offset += 3;
      allowed_contacts_length = allowed_contacts_lengthT;
      for( uint8_t i = 0; i < allowed_contacts_length; i++){
      offset += this->st_allowed_contacts.deserialize(inbuffer + offset);
        memcpy( &(this->allowed_contacts[i]), &(this->st_allowed_contacts), sizeof(arm_navigation_msgs::AllowedContactSpecification));
      }
      uint8_t link_padding_lengthT = *(inbuffer + offset++);
      if(link_padding_lengthT > link_padding_length)
        this->link_padding = (arm_navigation_msgs::LinkPadding*)realloc(this->link_padding, link_padding_lengthT * sizeof(arm_navigation_msgs::LinkPadding));
      offset += 3;
      link_padding_length = link_padding_lengthT;
      for( uint8_t i = 0; i < link_padding_length; i++){
      offset += this->st_link_padding.deserialize(inbuffer + offset);
        memcpy( &(this->link_padding[i]), &(this->st_link_padding), sizeof(arm_navigation_msgs::LinkPadding));
      }
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
      offset += this->collision_map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/PlanningScene"; };
    const char * getMD5(){ return "6d1add8ef6efdd62d194ef430abd4b75"; };

  };

}
#endif