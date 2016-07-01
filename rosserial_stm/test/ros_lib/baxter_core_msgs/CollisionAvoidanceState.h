#ifndef _ROS_baxter_core_msgs_CollisionAvoidanceState_h
#define _ROS_baxter_core_msgs_CollisionAvoidanceState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace baxter_core_msgs
{

  class CollisionAvoidanceState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      bool other_arm;
      uint8_t collision_object_length;
      char* st_collision_object;
      char* * collision_object;

    CollisionAvoidanceState():
      header(),
      other_arm(0),
      collision_object_length(0), collision_object(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_other_arm;
      u_other_arm.real = this->other_arm;
      *(outbuffer + offset + 0) = (u_other_arm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->other_arm);
      *(outbuffer + offset++) = collision_object_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < collision_object_length; i++){
      uint32_t length_collision_objecti = strlen(this->collision_object[i]);
      memcpy(outbuffer + offset, &length_collision_objecti, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->collision_object[i], length_collision_objecti);
      offset += length_collision_objecti;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_other_arm;
      u_other_arm.base = 0;
      u_other_arm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->other_arm = u_other_arm.real;
      offset += sizeof(this->other_arm);
      uint8_t collision_object_lengthT = *(inbuffer + offset++);
      if(collision_object_lengthT > collision_object_length)
        this->collision_object = (char**)realloc(this->collision_object, collision_object_lengthT * sizeof(char*));
      offset += 3;
      collision_object_length = collision_object_lengthT;
      for( uint8_t i = 0; i < collision_object_length; i++){
      uint32_t length_st_collision_object;
      memcpy(&length_st_collision_object, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_collision_object; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_collision_object-1]=0;
      this->st_collision_object = (char *)(inbuffer + offset-1);
      offset += length_st_collision_object;
        memcpy( &(this->collision_object[i]), &(this->st_collision_object), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "baxter_core_msgs/CollisionAvoidanceState"; };
    const char * getMD5(){ return "30f5cb8ae019f1ffe8b599e6d2e589c7"; };

  };

}
#endif