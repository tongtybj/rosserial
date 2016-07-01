#ifndef _ROS_arm_navigation_msgs_CollisionObject_h
#define _ROS_arm_navigation_msgs_CollisionObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "arm_navigation_msgs/CollisionObjectOperation.h"
#include "arm_navigation_msgs/Shape.h"
#include "geometry_msgs/Pose.h"

namespace arm_navigation_msgs
{

  class CollisionObject : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* id;
      float padding;
      arm_navigation_msgs::CollisionObjectOperation operation;
      uint8_t shapes_length;
      arm_navigation_msgs::Shape st_shapes;
      arm_navigation_msgs::Shape * shapes;
      uint8_t poses_length;
      geometry_msgs::Pose st_poses;
      geometry_msgs::Pose * poses;

    CollisionObject():
      header(),
      id(""),
      padding(0),
      operation(),
      shapes_length(0), shapes(NULL),
      poses_length(0), poses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        float real;
        uint32_t base;
      } u_padding;
      u_padding.real = this->padding;
      *(outbuffer + offset + 0) = (u_padding.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_padding.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_padding.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_padding.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->padding);
      offset += this->operation.serialize(outbuffer + offset);
      *(outbuffer + offset++) = shapes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < shapes_length; i++){
      offset += this->shapes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = poses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        float real;
        uint32_t base;
      } u_padding;
      u_padding.base = 0;
      u_padding.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_padding.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_padding.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_padding.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->padding = u_padding.real;
      offset += sizeof(this->padding);
      offset += this->operation.deserialize(inbuffer + offset);
      uint8_t shapes_lengthT = *(inbuffer + offset++);
      if(shapes_lengthT > shapes_length)
        this->shapes = (arm_navigation_msgs::Shape*)realloc(this->shapes, shapes_lengthT * sizeof(arm_navigation_msgs::Shape));
      offset += 3;
      shapes_length = shapes_lengthT;
      for( uint8_t i = 0; i < shapes_length; i++){
      offset += this->st_shapes.deserialize(inbuffer + offset);
        memcpy( &(this->shapes[i]), &(this->st_shapes), sizeof(arm_navigation_msgs::Shape));
      }
      uint8_t poses_lengthT = *(inbuffer + offset++);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::Pose*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::Pose));
      offset += 3;
      poses_length = poses_lengthT;
      for( uint8_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/CollisionObject"; };
    const char * getMD5(){ return "7b972910c23ece1b873b3de0cf92ba97"; };

  };

}
#endif