#ifndef _ROS_aerial_robot_msgs_MotorInfo_h
#define _ROS_aerial_robot_msgs_MotorInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace aerial_robot_msgs
{

  class MotorInfo : public ros::Msg
  {
    public:
      float voltage;
      float polynominal[5];
      enum { SQRT_MODE =  0 };
      enum { POLYNOMINAL_MODE =  1 };

    MotorInfo():
      voltage(0),
      polynominal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      for( uint8_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_polynominali;
      u_polynominali.real = this->polynominal[i];
      *(outbuffer + offset + 0) = (u_polynominali.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_polynominali.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_polynominali.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_polynominali.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->polynominal[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      for( uint8_t i = 0; i < 5; i++){
      union {
        float real;
        uint32_t base;
      } u_polynominali;
      u_polynominali.base = 0;
      u_polynominali.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_polynominali.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_polynominali.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_polynominali.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->polynominal[i] = u_polynominali.real;
      offset += sizeof(this->polynominal[i]);
      }
     return offset;
    }

    const char * getType(){ return "aerial_robot_msgs/MotorInfo"; };
    const char * getMD5(){ return "7971ab19b3b338702f75846ee7d1e8f2"; };

  };

}
#endif