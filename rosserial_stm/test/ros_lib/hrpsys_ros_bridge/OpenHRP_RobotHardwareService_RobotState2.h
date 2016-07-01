#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_RobotState2_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_RobotHardwareService_RobotState2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Float64MultiArray.h"
#include "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_BatteryState.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_RobotHardwareService_RobotState2 : public ros::Msg
  {
    public:
      uint8_t angle_length;
      double st_angle;
      double * angle;
      uint8_t command_length;
      double st_command;
      double * command;
      uint8_t torque_length;
      double st_torque;
      double * torque;
      std_msgs::Int32MultiArray servoState;
      std_msgs::Float64MultiArray force;
      std_msgs::Float64MultiArray rateGyro;
      std_msgs::Float64MultiArray accel;
      uint8_t batteries_length;
      hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState st_batteries;
      hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState * batteries;
      double voltage;
      double current;
      uint8_t temperature_length;
      double st_temperature;
      double * temperature;

    OpenHRP_RobotHardwareService_RobotState2():
      angle_length(0), angle(NULL),
      command_length(0), command(NULL),
      torque_length(0), torque(NULL),
      servoState(),
      force(),
      rateGyro(),
      accel(),
      batteries_length(0), batteries(NULL),
      voltage(0),
      current(0),
      temperature_length(0), temperature(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = angle_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < angle_length; i++){
      union {
        double real;
        uint64_t base;
      } u_anglei;
      u_anglei.real = this->angle[i];
      *(outbuffer + offset + 0) = (u_anglei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anglei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anglei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anglei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_anglei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_anglei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_anglei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_anglei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->angle[i]);
      }
      *(outbuffer + offset++) = command_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < command_length; i++){
      union {
        double real;
        uint64_t base;
      } u_commandi;
      u_commandi.real = this->command[i];
      *(outbuffer + offset + 0) = (u_commandi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_commandi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_commandi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_commandi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_commandi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_commandi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_commandi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_commandi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->command[i]);
      }
      *(outbuffer + offset++) = torque_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < torque_length; i++){
      union {
        double real;
        uint64_t base;
      } u_torquei;
      u_torquei.real = this->torque[i];
      *(outbuffer + offset + 0) = (u_torquei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_torquei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_torquei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_torquei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_torquei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_torquei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_torquei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_torquei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->torque[i]);
      }
      offset += this->servoState.serialize(outbuffer + offset);
      offset += this->force.serialize(outbuffer + offset);
      offset += this->rateGyro.serialize(outbuffer + offset);
      offset += this->accel.serialize(outbuffer + offset);
      *(outbuffer + offset++) = batteries_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < batteries_length; i++){
      offset += this->batteries[i].serialize(outbuffer + offset);
      }
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
      *(outbuffer + offset++) = temperature_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < temperature_length; i++){
      union {
        double real;
        uint64_t base;
      } u_temperaturei;
      u_temperaturei.real = this->temperature[i];
      *(outbuffer + offset + 0) = (u_temperaturei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperaturei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperaturei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperaturei.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperaturei.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperaturei.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperaturei.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperaturei.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperature[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t angle_lengthT = *(inbuffer + offset++);
      if(angle_lengthT > angle_length)
        this->angle = (double*)realloc(this->angle, angle_lengthT * sizeof(double));
      offset += 3;
      angle_length = angle_lengthT;
      for( uint8_t i = 0; i < angle_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_angle;
      u_st_angle.base = 0;
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_angle = u_st_angle.real;
      offset += sizeof(this->st_angle);
        memcpy( &(this->angle[i]), &(this->st_angle), sizeof(double));
      }
      uint8_t command_lengthT = *(inbuffer + offset++);
      if(command_lengthT > command_length)
        this->command = (double*)realloc(this->command, command_lengthT * sizeof(double));
      offset += 3;
      command_length = command_lengthT;
      for( uint8_t i = 0; i < command_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_command;
      u_st_command.base = 0;
      u_st_command.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_command.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_command.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_command.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_command.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_command.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_command.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_command.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_command = u_st_command.real;
      offset += sizeof(this->st_command);
        memcpy( &(this->command[i]), &(this->st_command), sizeof(double));
      }
      uint8_t torque_lengthT = *(inbuffer + offset++);
      if(torque_lengthT > torque_length)
        this->torque = (double*)realloc(this->torque, torque_lengthT * sizeof(double));
      offset += 3;
      torque_length = torque_lengthT;
      for( uint8_t i = 0; i < torque_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_torque;
      u_st_torque.base = 0;
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_torque.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_torque = u_st_torque.real;
      offset += sizeof(this->st_torque);
        memcpy( &(this->torque[i]), &(this->st_torque), sizeof(double));
      }
      offset += this->servoState.deserialize(inbuffer + offset);
      offset += this->force.deserialize(inbuffer + offset);
      offset += this->rateGyro.deserialize(inbuffer + offset);
      offset += this->accel.deserialize(inbuffer + offset);
      uint8_t batteries_lengthT = *(inbuffer + offset++);
      if(batteries_lengthT > batteries_length)
        this->batteries = (hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState*)realloc(this->batteries, batteries_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState));
      offset += 3;
      batteries_length = batteries_lengthT;
      for( uint8_t i = 0; i < batteries_length; i++){
      offset += this->st_batteries.deserialize(inbuffer + offset);
        memcpy( &(this->batteries[i]), &(this->st_batteries), sizeof(hrpsys_ros_bridge::OpenHRP_RobotHardwareService_BatteryState));
      }
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
      uint8_t temperature_lengthT = *(inbuffer + offset++);
      if(temperature_lengthT > temperature_length)
        this->temperature = (double*)realloc(this->temperature, temperature_lengthT * sizeof(double));
      offset += 3;
      temperature_length = temperature_lengthT;
      for( uint8_t i = 0; i < temperature_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_temperature;
      u_st_temperature.base = 0;
      u_st_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_temperature = u_st_temperature.real;
      offset += sizeof(this->st_temperature);
        memcpy( &(this->temperature[i]), &(this->st_temperature), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_RobotState2"; };
    const char * getMD5(){ return "55bedf35a5f953cd1f113a0e7665626f"; };

  };

}
#endif