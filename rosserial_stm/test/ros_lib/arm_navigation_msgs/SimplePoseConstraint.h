#ifndef _ROS_arm_navigation_msgs_SimplePoseConstraint_h
#define _ROS_arm_navigation_msgs_SimplePoseConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Point.h"

namespace arm_navigation_msgs
{

  class SimplePoseConstraint : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* link_name;
      geometry_msgs::Pose pose;
      geometry_msgs::Point absolute_position_tolerance;
      double absolute_roll_tolerance;
      double absolute_yaw_tolerance;
      double absolute_pitch_tolerance;
      int32_t orientation_constraint_type;
      enum { HEADER_FRAME = 0 };
      enum { LINK_FRAME = 1 };

    SimplePoseConstraint():
      header(),
      link_name(""),
      pose(),
      absolute_position_tolerance(),
      absolute_roll_tolerance(0),
      absolute_yaw_tolerance(0),
      absolute_pitch_tolerance(0),
      orientation_constraint_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_link_name = strlen(this->link_name);
      memcpy(outbuffer + offset, &length_link_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->absolute_position_tolerance.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_absolute_roll_tolerance;
      u_absolute_roll_tolerance.real = this->absolute_roll_tolerance;
      *(outbuffer + offset + 0) = (u_absolute_roll_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_absolute_roll_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_absolute_roll_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_absolute_roll_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_absolute_roll_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_absolute_roll_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_absolute_roll_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_absolute_roll_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->absolute_roll_tolerance);
      union {
        double real;
        uint64_t base;
      } u_absolute_yaw_tolerance;
      u_absolute_yaw_tolerance.real = this->absolute_yaw_tolerance;
      *(outbuffer + offset + 0) = (u_absolute_yaw_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_absolute_yaw_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_absolute_yaw_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_absolute_yaw_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_absolute_yaw_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_absolute_yaw_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_absolute_yaw_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_absolute_yaw_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->absolute_yaw_tolerance);
      union {
        double real;
        uint64_t base;
      } u_absolute_pitch_tolerance;
      u_absolute_pitch_tolerance.real = this->absolute_pitch_tolerance;
      *(outbuffer + offset + 0) = (u_absolute_pitch_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_absolute_pitch_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_absolute_pitch_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_absolute_pitch_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_absolute_pitch_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_absolute_pitch_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_absolute_pitch_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_absolute_pitch_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->absolute_pitch_tolerance);
      union {
        int32_t real;
        uint32_t base;
      } u_orientation_constraint_type;
      u_orientation_constraint_type.real = this->orientation_constraint_type;
      *(outbuffer + offset + 0) = (u_orientation_constraint_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orientation_constraint_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orientation_constraint_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orientation_constraint_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientation_constraint_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_link_name;
      memcpy(&length_link_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->absolute_position_tolerance.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_absolute_roll_tolerance;
      u_absolute_roll_tolerance.base = 0;
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->absolute_roll_tolerance = u_absolute_roll_tolerance.real;
      offset += sizeof(this->absolute_roll_tolerance);
      union {
        double real;
        uint64_t base;
      } u_absolute_yaw_tolerance;
      u_absolute_yaw_tolerance.base = 0;
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->absolute_yaw_tolerance = u_absolute_yaw_tolerance.real;
      offset += sizeof(this->absolute_yaw_tolerance);
      union {
        double real;
        uint64_t base;
      } u_absolute_pitch_tolerance;
      u_absolute_pitch_tolerance.base = 0;
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->absolute_pitch_tolerance = u_absolute_pitch_tolerance.real;
      offset += sizeof(this->absolute_pitch_tolerance);
      union {
        int32_t real;
        uint32_t base;
      } u_orientation_constraint_type;
      u_orientation_constraint_type.base = 0;
      u_orientation_constraint_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_orientation_constraint_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_orientation_constraint_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_orientation_constraint_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->orientation_constraint_type = u_orientation_constraint_type.real;
      offset += sizeof(this->orientation_constraint_type);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/SimplePoseConstraint"; };
    const char * getMD5(){ return "3483d830eb84ecd3059741fd417b30da"; };

  };

}
#endif