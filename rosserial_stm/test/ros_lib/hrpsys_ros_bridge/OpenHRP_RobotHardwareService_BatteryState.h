#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_BatteryState_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_BatteryState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_RobotHardwareService_BatteryState : public ros::Msg
  {
    public:
      double voltage;
      double current;
      double soc;

    OpenHRP_RobotHardwareService_BatteryState():
      voltage(0),
      current(0),
      soc(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_voltage.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_voltage.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_voltage.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_voltage.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        double real;
        uint64_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_current.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_current.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_current.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_current.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->current);
      union {
        double real;
        uint64_t base;
      } u_soc;
      u_soc.real = this->soc;
      *(outbuffer + offset + 0) = (u_soc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_soc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_soc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_soc.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_soc.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_soc.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_soc.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_soc.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->soc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_voltage.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        double real;
        uint64_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_current.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        double real;
        uint64_t base;
      } u_soc;
      u_soc.base = 0;
      u_soc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_soc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_soc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_soc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_soc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_soc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_soc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_soc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->soc = u_soc.real;
      offset += sizeof(this->soc);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_BatteryState"; };
    const char * getMD5(){ return "67871635fa0e3aafb978a788d456ea1f"; };

  };

}
#endif