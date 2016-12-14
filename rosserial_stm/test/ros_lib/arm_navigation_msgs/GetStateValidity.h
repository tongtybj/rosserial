#ifndef _ROS_SERVICE_GetStateValidity_h
#define _ROS_SERVICE_GetStateValidity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/RobotState.h"
#include "arm_navigation_msgs/Constraints.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"
#include "arm_navigation_msgs/ContactInformation.h"

namespace arm_navigation_msgs
{

static const char GETSTATEVALIDITY[] = "arm_navigation_msgs/GetStateValidity";

  class GetStateValidityRequest : public ros::Msg
  {
    public:
      arm_navigation_msgs::RobotState robot_state;
      bool check_collisions;
      bool check_path_constraints;
      bool check_goal_constraints;
      bool check_joint_limits;
      const char* group_name;
      arm_navigation_msgs::Constraints path_constraints;
      arm_navigation_msgs::Constraints goal_constraints;

    GetStateValidityRequest():
      robot_state(),
      check_collisions(0),
      check_path_constraints(0),
      check_goal_constraints(0),
      check_joint_limits(0),
      group_name(""),
      path_constraints(),
      goal_constraints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_state.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_check_collisions;
      u_check_collisions.real = this->check_collisions;
      *(outbuffer + offset + 0) = (u_check_collisions.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_collisions);
      union {
        bool real;
        uint8_t base;
      } u_check_path_constraints;
      u_check_path_constraints.real = this->check_path_constraints;
      *(outbuffer + offset + 0) = (u_check_path_constraints.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_path_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_goal_constraints;
      u_check_goal_constraints.real = this->check_goal_constraints;
      *(outbuffer + offset + 0) = (u_check_goal_constraints.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_goal_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_joint_limits;
      u_check_joint_limits.real = this->check_joint_limits;
      *(outbuffer + offset + 0) = (u_check_joint_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_joint_limits);
      uint32_t length_group_name = strlen(this->group_name);
      memcpy(outbuffer + offset, &length_group_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      offset += this->path_constraints.serialize(outbuffer + offset);
      offset += this->goal_constraints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_state.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_check_collisions;
      u_check_collisions.base = 0;
      u_check_collisions.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_collisions = u_check_collisions.real;
      offset += sizeof(this->check_collisions);
      union {
        bool real;
        uint8_t base;
      } u_check_path_constraints;
      u_check_path_constraints.base = 0;
      u_check_path_constraints.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_path_constraints = u_check_path_constraints.real;
      offset += sizeof(this->check_path_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_goal_constraints;
      u_check_goal_constraints.base = 0;
      u_check_goal_constraints.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_goal_constraints = u_check_goal_constraints.real;
      offset += sizeof(this->check_goal_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_joint_limits;
      u_check_joint_limits.base = 0;
      u_check_joint_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_joint_limits = u_check_joint_limits.real;
      offset += sizeof(this->check_joint_limits);
      uint32_t length_group_name;
      memcpy(&length_group_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
      offset += this->path_constraints.deserialize(inbuffer + offset);
      offset += this->goal_constraints.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETSTATEVALIDITY; };
    const char * getMD5(){ return "fe05d730cc03ecb8a8dff34774a12c59"; };

  };

  class GetStateValidityResponse : public ros::Msg
  {
    public:
      arm_navigation_msgs::ArmNavigationErrorCodes error_code;
      uint8_t contacts_length;
      arm_navigation_msgs::ContactInformation st_contacts;
      arm_navigation_msgs::ContactInformation * contacts;

    GetStateValidityResponse():
      error_code(),
      contacts_length(0), contacts(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      *(outbuffer + offset++) = contacts_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < contacts_length; i++){
      offset += this->contacts[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->error_code.deserialize(inbuffer + offset);
      uint8_t contacts_lengthT = *(inbuffer + offset++);
      if(contacts_lengthT > contacts_length)
        this->contacts = (arm_navigation_msgs::ContactInformation*)realloc(this->contacts, contacts_lengthT * sizeof(arm_navigation_msgs::ContactInformation));
      offset += 3;
      contacts_length = contacts_lengthT;
      for( uint8_t i = 0; i < contacts_length; i++){
      offset += this->st_contacts.deserialize(inbuffer + offset);
        memcpy( &(this->contacts[i]), &(this->st_contacts), sizeof(arm_navigation_msgs::ContactInformation));
      }
     return offset;
    }

    const char * getType(){ return GETSTATEVALIDITY; };
    const char * getMD5(){ return "3229301226a0605e3ffc9dfdaeac662f"; };

  };

  class GetStateValidity {
    public:
    typedef GetStateValidityRequest Request;
    typedef GetStateValidityResponse Response;
  };

}
#endif
