#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam : public ros::Msg
  {
    public:
      double force_offset[3];
      double moment_offset[3];
      double link_offset_centroid[3];
      double link_offset_mass;

    OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam():
      force_offset(),
      moment_offset(),
      link_offset_centroid(),
      link_offset_mass(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_force_offseti;
      u_force_offseti.real = this->force_offset[i];
      *(outbuffer + offset + 0) = (u_force_offseti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_force_offseti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_force_offseti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_force_offseti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_force_offseti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_force_offseti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_force_offseti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_force_offseti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->force_offset[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_moment_offseti;
      u_moment_offseti.real = this->moment_offset[i];
      *(outbuffer + offset + 0) = (u_moment_offseti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_moment_offseti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_moment_offseti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_moment_offseti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_moment_offseti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_moment_offseti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_moment_offseti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_moment_offseti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->moment_offset[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_link_offset_centroidi;
      u_link_offset_centroidi.real = this->link_offset_centroid[i];
      *(outbuffer + offset + 0) = (u_link_offset_centroidi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_link_offset_centroidi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_link_offset_centroidi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_link_offset_centroidi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_link_offset_centroidi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_link_offset_centroidi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_link_offset_centroidi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_link_offset_centroidi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->link_offset_centroid[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_link_offset_mass;
      u_link_offset_mass.real = this->link_offset_mass;
      *(outbuffer + offset + 0) = (u_link_offset_mass.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_link_offset_mass.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_link_offset_mass.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_link_offset_mass.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_link_offset_mass.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_link_offset_mass.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_link_offset_mass.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_link_offset_mass.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->link_offset_mass);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_force_offseti;
      u_force_offseti.base = 0;
      u_force_offseti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_force_offseti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_force_offseti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_force_offseti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_force_offseti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_force_offseti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_force_offseti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_force_offseti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->force_offset[i] = u_force_offseti.real;
      offset += sizeof(this->force_offset[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_moment_offseti;
      u_moment_offseti.base = 0;
      u_moment_offseti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_moment_offseti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_moment_offseti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_moment_offseti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_moment_offseti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_moment_offseti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_moment_offseti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_moment_offseti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->moment_offset[i] = u_moment_offseti.real;
      offset += sizeof(this->moment_offset[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_link_offset_centroidi;
      u_link_offset_centroidi.base = 0;
      u_link_offset_centroidi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_link_offset_centroidi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_link_offset_centroidi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_link_offset_centroidi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_link_offset_centroidi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_link_offset_centroidi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_link_offset_centroidi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_link_offset_centroidi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->link_offset_centroid[i] = u_link_offset_centroidi.real;
      offset += sizeof(this->link_offset_centroid[i]);
      }
      union {
        double real;
        uint64_t base;
      } u_link_offset_mass;
      u_link_offset_mass.base = 0;
      u_link_offset_mass.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_link_offset_mass.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_link_offset_mass.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_link_offset_mass.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_link_offset_mass.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_link_offset_mass.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_link_offset_mass.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_link_offset_mass.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->link_offset_mass = u_link_offset_mass.real;
      offset += sizeof(this->link_offset_mass);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_RemoveForceSensorLinkOffsetService_forcemomentOffsetParam"; };
    const char * getMD5(){ return "65a8bdda0c275a081765814539fb2401"; };

  };

}
#endif