#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_KalmanFilterService_KalmanFilterParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_KalmanFilterService_KalmanFilterParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_KalmanFilterService_KalmanFilterParam : public ros::Msg
  {
    public:
      double Q_angle;
      double Q_rate;
      double R_angle;
      int64_t kf_algorithm;
      double acc_offset[3];
      double sensorRPY_offset[3];

    OpenHRP_KalmanFilterService_KalmanFilterParam():
      Q_angle(0),
      Q_rate(0),
      R_angle(0),
      kf_algorithm(0),
      acc_offset(),
      sensorRPY_offset()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_Q_angle;
      u_Q_angle.real = this->Q_angle;
      *(outbuffer + offset + 0) = (u_Q_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Q_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Q_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Q_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_Q_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_Q_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_Q_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_Q_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->Q_angle);
      union {
        double real;
        uint64_t base;
      } u_Q_rate;
      u_Q_rate.real = this->Q_rate;
      *(outbuffer + offset + 0) = (u_Q_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Q_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Q_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Q_rate.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_Q_rate.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_Q_rate.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_Q_rate.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_Q_rate.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->Q_rate);
      union {
        double real;
        uint64_t base;
      } u_R_angle;
      u_R_angle.real = this->R_angle;
      *(outbuffer + offset + 0) = (u_R_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_R_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_R_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_R_angle.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_R_angle.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_R_angle.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_R_angle.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_R_angle.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->R_angle);
      union {
        int64_t real;
        uint64_t base;
      } u_kf_algorithm;
      u_kf_algorithm.real = this->kf_algorithm;
      *(outbuffer + offset + 0) = (u_kf_algorithm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kf_algorithm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kf_algorithm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kf_algorithm.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_kf_algorithm.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_kf_algorithm.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_kf_algorithm.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_kf_algorithm.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->kf_algorithm);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_acc_offseti;
      u_acc_offseti.real = this->acc_offset[i];
      *(outbuffer + offset + 0) = (u_acc_offseti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_offseti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_acc_offseti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_acc_offseti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_acc_offseti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_acc_offseti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_acc_offseti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_acc_offseti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->acc_offset[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_sensorRPY_offseti;
      u_sensorRPY_offseti.real = this->sensorRPY_offset[i];
      *(outbuffer + offset + 0) = (u_sensorRPY_offseti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensorRPY_offseti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sensorRPY_offseti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sensorRPY_offseti.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sensorRPY_offseti.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sensorRPY_offseti.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sensorRPY_offseti.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sensorRPY_offseti.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sensorRPY_offset[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_Q_angle;
      u_Q_angle.base = 0;
      u_Q_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Q_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Q_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Q_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_Q_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_Q_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_Q_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_Q_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->Q_angle = u_Q_angle.real;
      offset += sizeof(this->Q_angle);
      union {
        double real;
        uint64_t base;
      } u_Q_rate;
      u_Q_rate.base = 0;
      u_Q_rate.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Q_rate.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Q_rate.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Q_rate.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_Q_rate.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_Q_rate.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_Q_rate.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_Q_rate.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->Q_rate = u_Q_rate.real;
      offset += sizeof(this->Q_rate);
      union {
        double real;
        uint64_t base;
      } u_R_angle;
      u_R_angle.base = 0;
      u_R_angle.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_R_angle.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_R_angle.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_R_angle.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_R_angle.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_R_angle.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_R_angle.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_R_angle.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->R_angle = u_R_angle.real;
      offset += sizeof(this->R_angle);
      union {
        int64_t real;
        uint64_t base;
      } u_kf_algorithm;
      u_kf_algorithm.base = 0;
      u_kf_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kf_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kf_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kf_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_kf_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_kf_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_kf_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_kf_algorithm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->kf_algorithm = u_kf_algorithm.real;
      offset += sizeof(this->kf_algorithm);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_acc_offseti;
      u_acc_offseti.base = 0;
      u_acc_offseti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_offseti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_acc_offseti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_acc_offseti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_acc_offseti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_acc_offseti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_acc_offseti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_acc_offseti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->acc_offset[i] = u_acc_offseti.real;
      offset += sizeof(this->acc_offset[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_sensorRPY_offseti;
      u_sensorRPY_offseti.base = 0;
      u_sensorRPY_offseti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sensorRPY_offseti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sensorRPY_offseti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sensorRPY_offseti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sensorRPY_offseti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sensorRPY_offseti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sensorRPY_offseti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sensorRPY_offseti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sensorRPY_offset[i] = u_sensorRPY_offseti.real;
      offset += sizeof(this->sensorRPY_offset[i]);
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_KalmanFilterService_KalmanFilterParam"; };
    const char * getMD5(){ return "9e2ec644e20575e0461c6b3cde1053fe"; };

  };

}
#endif