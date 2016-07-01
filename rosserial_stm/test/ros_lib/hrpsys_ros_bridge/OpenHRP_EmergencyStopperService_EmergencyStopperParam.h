#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_EmergencyStopperService_EmergencyStopperParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_EmergencyStopperService_EmergencyStopperParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_EmergencyStopperService_EmergencyStopperParam : public ros::Msg
  {
    public:
      double default_recover_time;
      double default_retrieve_time;
      bool is_stop_mode;

    OpenHRP_EmergencyStopperService_EmergencyStopperParam():
      default_recover_time(0),
      default_retrieve_time(0),
      is_stop_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_default_recover_time;
      u_default_recover_time.real = this->default_recover_time;
      *(outbuffer + offset + 0) = (u_default_recover_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_recover_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_recover_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_recover_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_recover_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_recover_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_recover_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_recover_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_recover_time);
      union {
        double real;
        uint64_t base;
      } u_default_retrieve_time;
      u_default_retrieve_time.real = this->default_retrieve_time;
      *(outbuffer + offset + 0) = (u_default_retrieve_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_default_retrieve_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_default_retrieve_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_default_retrieve_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_default_retrieve_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_default_retrieve_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_default_retrieve_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_default_retrieve_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->default_retrieve_time);
      union {
        bool real;
        uint8_t base;
      } u_is_stop_mode;
      u_is_stop_mode.real = this->is_stop_mode;
      *(outbuffer + offset + 0) = (u_is_stop_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_stop_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_default_recover_time;
      u_default_recover_time.base = 0;
      u_default_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_recover_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_recover_time = u_default_recover_time.real;
      offset += sizeof(this->default_recover_time);
      union {
        double real;
        uint64_t base;
      } u_default_retrieve_time;
      u_default_retrieve_time.base = 0;
      u_default_retrieve_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_default_retrieve_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_default_retrieve_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_default_retrieve_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_default_retrieve_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_default_retrieve_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_default_retrieve_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_default_retrieve_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->default_retrieve_time = u_default_retrieve_time.real;
      offset += sizeof(this->default_retrieve_time);
      union {
        bool real;
        uint8_t base;
      } u_is_stop_mode;
      u_is_stop_mode.base = 0;
      u_is_stop_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_stop_mode = u_is_stop_mode.real;
      offset += sizeof(this->is_stop_mode);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_EmergencyStopperService_EmergencyStopperParam"; };
    const char * getMD5(){ return "9e7993b5ea68e78c2c5246f4a2a5f844"; };

  };

}
#endif