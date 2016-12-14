#ifndef _ROS_arm_navigation_msgs_MultiDOFJointState_h
#define _ROS_arm_navigation_msgs_MultiDOFJointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "geometry_msgs/Pose.h"

namespace arm_navigation_msgs
{

  class MultiDOFJointState : public ros::Msg
  {
    public:
      ros::Time stamp;
      uint8_t joint_names_length;
      char* st_joint_names;
      char* * joint_names;
      uint8_t frame_ids_length;
      char* st_frame_ids;
      char* * frame_ids;
      uint8_t child_frame_ids_length;
      char* st_child_frame_ids;
      char* * child_frame_ids;
      uint8_t poses_length;
      geometry_msgs::Pose st_poses;
      geometry_msgs::Pose * poses;

    MultiDOFJointState():
      stamp(),
      joint_names_length(0), joint_names(NULL),
      frame_ids_length(0), frame_ids(NULL),
      child_frame_ids_length(0), child_frame_ids(NULL),
      poses_length(0), poses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      *(outbuffer + offset++) = joint_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      memcpy(outbuffer + offset, &length_joint_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset++) = frame_ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < frame_ids_length; i++){
      uint32_t length_frame_idsi = strlen(this->frame_ids[i]);
      memcpy(outbuffer + offset, &length_frame_idsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame_ids[i], length_frame_idsi);
      offset += length_frame_idsi;
      }
      *(outbuffer + offset++) = child_frame_ids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < child_frame_ids_length; i++){
      uint32_t length_child_frame_idsi = strlen(this->child_frame_ids[i]);
      memcpy(outbuffer + offset, &length_child_frame_idsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->child_frame_ids[i], length_child_frame_idsi);
      offset += length_child_frame_idsi;
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
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      uint8_t joint_names_lengthT = *(inbuffer + offset++);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      offset += 3;
      joint_names_length = joint_names_lengthT;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      memcpy(&length_st_joint_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint8_t frame_ids_lengthT = *(inbuffer + offset++);
      if(frame_ids_lengthT > frame_ids_length)
        this->frame_ids = (char**)realloc(this->frame_ids, frame_ids_lengthT * sizeof(char*));
      offset += 3;
      frame_ids_length = frame_ids_lengthT;
      for( uint8_t i = 0; i < frame_ids_length; i++){
      uint32_t length_st_frame_ids;
      memcpy(&length_st_frame_ids, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_frame_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_frame_ids-1]=0;
      this->st_frame_ids = (char *)(inbuffer + offset-1);
      offset += length_st_frame_ids;
        memcpy( &(this->frame_ids[i]), &(this->st_frame_ids), sizeof(char*));
      }
      uint8_t child_frame_ids_lengthT = *(inbuffer + offset++);
      if(child_frame_ids_lengthT > child_frame_ids_length)
        this->child_frame_ids = (char**)realloc(this->child_frame_ids, child_frame_ids_lengthT * sizeof(char*));
      offset += 3;
      child_frame_ids_length = child_frame_ids_lengthT;
      for( uint8_t i = 0; i < child_frame_ids_length; i++){
      uint32_t length_st_child_frame_ids;
      memcpy(&length_st_child_frame_ids, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_child_frame_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_child_frame_ids-1]=0;
      this->st_child_frame_ids = (char *)(inbuffer + offset-1);
      offset += length_st_child_frame_ids;
        memcpy( &(this->child_frame_ids[i]), &(this->st_child_frame_ids), sizeof(char*));
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

    const char * getType(){ return "arm_navigation_msgs/MultiDOFJointState"; };
    const char * getMD5(){ return "ddd04f13c06870db031db8d5c0a6379d"; };

  };

}
#endif