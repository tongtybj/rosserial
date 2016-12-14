#ifndef _ROS_arm_navigation_msgs_AllowedContactSpecification_h
#define _ROS_arm_navigation_msgs_AllowedContactSpecification_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/Shape.h"
#include "geometry_msgs/PoseStamped.h"

namespace arm_navigation_msgs
{

  class AllowedContactSpecification : public ros::Msg
  {
    public:
      const char* name;
      arm_navigation_msgs::Shape shape;
      geometry_msgs::PoseStamped pose_stamped;
      uint8_t link_names_length;
      char* st_link_names;
      char* * link_names;
      double penetration_depth;

    AllowedContactSpecification():
      name(""),
      shape(),
      pose_stamped(),
      link_names_length(0), link_names(NULL),
      penetration_depth(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->shape.serialize(outbuffer + offset);
      offset += this->pose_stamped.serialize(outbuffer + offset);
      *(outbuffer + offset++) = link_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < link_names_length; i++){
      uint32_t length_link_namesi = strlen(this->link_names[i]);
      memcpy(outbuffer + offset, &length_link_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_names[i], length_link_namesi);
      offset += length_link_namesi;
      }
      union {
        double real;
        uint64_t base;
      } u_penetration_depth;
      u_penetration_depth.real = this->penetration_depth;
      *(outbuffer + offset + 0) = (u_penetration_depth.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_penetration_depth.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_penetration_depth.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_penetration_depth.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_penetration_depth.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_penetration_depth.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_penetration_depth.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_penetration_depth.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->penetration_depth);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->shape.deserialize(inbuffer + offset);
      offset += this->pose_stamped.deserialize(inbuffer + offset);
      uint8_t link_names_lengthT = *(inbuffer + offset++);
      if(link_names_lengthT > link_names_length)
        this->link_names = (char**)realloc(this->link_names, link_names_lengthT * sizeof(char*));
      offset += 3;
      link_names_length = link_names_lengthT;
      for( uint8_t i = 0; i < link_names_length; i++){
      uint32_t length_st_link_names;
      memcpy(&length_st_link_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_link_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_link_names-1]=0;
      this->st_link_names = (char *)(inbuffer + offset-1);
      offset += length_st_link_names;
        memcpy( &(this->link_names[i]), &(this->st_link_names), sizeof(char*));
      }
      union {
        double real;
        uint64_t base;
      } u_penetration_depth;
      u_penetration_depth.base = 0;
      u_penetration_depth.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_penetration_depth.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_penetration_depth.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_penetration_depth.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_penetration_depth.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_penetration_depth.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_penetration_depth.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_penetration_depth.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->penetration_depth = u_penetration_depth.real;
      offset += sizeof(this->penetration_depth);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/AllowedContactSpecification"; };
    const char * getMD5(){ return "81f9b47ac49a467ae008d3d9485628a3"; };

  };

}
#endif