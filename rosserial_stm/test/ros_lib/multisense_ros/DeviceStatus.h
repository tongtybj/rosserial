#ifndef _ROS_multisense_ros_DeviceStatus_h
#define _ROS_multisense_ros_DeviceStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace multisense_ros
{

  class DeviceStatus : public ros::Msg
  {
    public:
      ros::Time time;
      ros::Time uptime;
      bool systemOk;
      bool laserOk;
      bool laserMotorOk;
      bool camerasOk;
      bool imuOk;
      bool externalLedsOk;
      bool processingPipelineOk;
      float powerSupplyTemp;
      float fpgaTemp;
      float leftImagerTemp;
      float rightImagerTemp;
      float inputVoltage;
      float inputCurrent;
      float fpgaPower;
      float logicPower;
      float imagerPower;

    DeviceStatus():
      time(),
      uptime(),
      systemOk(0),
      laserOk(0),
      laserMotorOk(0),
      camerasOk(0),
      imuOk(0),
      externalLedsOk(0),
      processingPipelineOk(0),
      powerSupplyTemp(0),
      fpgaTemp(0),
      leftImagerTemp(0),
      rightImagerTemp(0),
      inputVoltage(0),
      inputCurrent(0),
      fpgaPower(0),
      logicPower(0),
      imagerPower(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.sec);
      *(outbuffer + offset + 0) = (this->time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time.nsec);
      *(outbuffer + offset + 0) = (this->uptime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uptime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uptime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uptime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uptime.sec);
      *(outbuffer + offset + 0) = (this->uptime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uptime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uptime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uptime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uptime.nsec);
      union {
        bool real;
        uint8_t base;
      } u_systemOk;
      u_systemOk.real = this->systemOk;
      *(outbuffer + offset + 0) = (u_systemOk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->systemOk);
      union {
        bool real;
        uint8_t base;
      } u_laserOk;
      u_laserOk.real = this->laserOk;
      *(outbuffer + offset + 0) = (u_laserOk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->laserOk);
      union {
        bool real;
        uint8_t base;
      } u_laserMotorOk;
      u_laserMotorOk.real = this->laserMotorOk;
      *(outbuffer + offset + 0) = (u_laserMotorOk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->laserMotorOk);
      union {
        bool real;
        uint8_t base;
      } u_camerasOk;
      u_camerasOk.real = this->camerasOk;
      *(outbuffer + offset + 0) = (u_camerasOk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->camerasOk);
      union {
        bool real;
        uint8_t base;
      } u_imuOk;
      u_imuOk.real = this->imuOk;
      *(outbuffer + offset + 0) = (u_imuOk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->imuOk);
      union {
        bool real;
        uint8_t base;
      } u_externalLedsOk;
      u_externalLedsOk.real = this->externalLedsOk;
      *(outbuffer + offset + 0) = (u_externalLedsOk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->externalLedsOk);
      union {
        bool real;
        uint8_t base;
      } u_processingPipelineOk;
      u_processingPipelineOk.real = this->processingPipelineOk;
      *(outbuffer + offset + 0) = (u_processingPipelineOk.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->processingPipelineOk);
      union {
        float real;
        uint32_t base;
      } u_powerSupplyTemp;
      u_powerSupplyTemp.real = this->powerSupplyTemp;
      *(outbuffer + offset + 0) = (u_powerSupplyTemp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_powerSupplyTemp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_powerSupplyTemp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_powerSupplyTemp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->powerSupplyTemp);
      union {
        float real;
        uint32_t base;
      } u_fpgaTemp;
      u_fpgaTemp.real = this->fpgaTemp;
      *(outbuffer + offset + 0) = (u_fpgaTemp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fpgaTemp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fpgaTemp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fpgaTemp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fpgaTemp);
      union {
        float real;
        uint32_t base;
      } u_leftImagerTemp;
      u_leftImagerTemp.real = this->leftImagerTemp;
      *(outbuffer + offset + 0) = (u_leftImagerTemp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftImagerTemp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftImagerTemp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftImagerTemp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->leftImagerTemp);
      union {
        float real;
        uint32_t base;
      } u_rightImagerTemp;
      u_rightImagerTemp.real = this->rightImagerTemp;
      *(outbuffer + offset + 0) = (u_rightImagerTemp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightImagerTemp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightImagerTemp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightImagerTemp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rightImagerTemp);
      union {
        float real;
        uint32_t base;
      } u_inputVoltage;
      u_inputVoltage.real = this->inputVoltage;
      *(outbuffer + offset + 0) = (u_inputVoltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inputVoltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_inputVoltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_inputVoltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inputVoltage);
      union {
        float real;
        uint32_t base;
      } u_inputCurrent;
      u_inputCurrent.real = this->inputCurrent;
      *(outbuffer + offset + 0) = (u_inputCurrent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inputCurrent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_inputCurrent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_inputCurrent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inputCurrent);
      union {
        float real;
        uint32_t base;
      } u_fpgaPower;
      u_fpgaPower.real = this->fpgaPower;
      *(outbuffer + offset + 0) = (u_fpgaPower.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fpgaPower.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fpgaPower.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fpgaPower.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fpgaPower);
      union {
        float real;
        uint32_t base;
      } u_logicPower;
      u_logicPower.real = this->logicPower;
      *(outbuffer + offset + 0) = (u_logicPower.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_logicPower.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_logicPower.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_logicPower.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->logicPower);
      union {
        float real;
        uint32_t base;
      } u_imagerPower;
      u_imagerPower.real = this->imagerPower;
      *(outbuffer + offset + 0) = (u_imagerPower.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imagerPower.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_imagerPower.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_imagerPower.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imagerPower);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.sec);
      this->time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time.nsec);
      this->uptime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->uptime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uptime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uptime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uptime.sec);
      this->uptime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->uptime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->uptime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->uptime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->uptime.nsec);
      union {
        bool real;
        uint8_t base;
      } u_systemOk;
      u_systemOk.base = 0;
      u_systemOk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->systemOk = u_systemOk.real;
      offset += sizeof(this->systemOk);
      union {
        bool real;
        uint8_t base;
      } u_laserOk;
      u_laserOk.base = 0;
      u_laserOk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->laserOk = u_laserOk.real;
      offset += sizeof(this->laserOk);
      union {
        bool real;
        uint8_t base;
      } u_laserMotorOk;
      u_laserMotorOk.base = 0;
      u_laserMotorOk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->laserMotorOk = u_laserMotorOk.real;
      offset += sizeof(this->laserMotorOk);
      union {
        bool real;
        uint8_t base;
      } u_camerasOk;
      u_camerasOk.base = 0;
      u_camerasOk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->camerasOk = u_camerasOk.real;
      offset += sizeof(this->camerasOk);
      union {
        bool real;
        uint8_t base;
      } u_imuOk;
      u_imuOk.base = 0;
      u_imuOk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->imuOk = u_imuOk.real;
      offset += sizeof(this->imuOk);
      union {
        bool real;
        uint8_t base;
      } u_externalLedsOk;
      u_externalLedsOk.base = 0;
      u_externalLedsOk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->externalLedsOk = u_externalLedsOk.real;
      offset += sizeof(this->externalLedsOk);
      union {
        bool real;
        uint8_t base;
      } u_processingPipelineOk;
      u_processingPipelineOk.base = 0;
      u_processingPipelineOk.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->processingPipelineOk = u_processingPipelineOk.real;
      offset += sizeof(this->processingPipelineOk);
      union {
        float real;
        uint32_t base;
      } u_powerSupplyTemp;
      u_powerSupplyTemp.base = 0;
      u_powerSupplyTemp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_powerSupplyTemp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_powerSupplyTemp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_powerSupplyTemp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->powerSupplyTemp = u_powerSupplyTemp.real;
      offset += sizeof(this->powerSupplyTemp);
      union {
        float real;
        uint32_t base;
      } u_fpgaTemp;
      u_fpgaTemp.base = 0;
      u_fpgaTemp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fpgaTemp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fpgaTemp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fpgaTemp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fpgaTemp = u_fpgaTemp.real;
      offset += sizeof(this->fpgaTemp);
      union {
        float real;
        uint32_t base;
      } u_leftImagerTemp;
      u_leftImagerTemp.base = 0;
      u_leftImagerTemp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftImagerTemp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftImagerTemp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftImagerTemp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->leftImagerTemp = u_leftImagerTemp.real;
      offset += sizeof(this->leftImagerTemp);
      union {
        float real;
        uint32_t base;
      } u_rightImagerTemp;
      u_rightImagerTemp.base = 0;
      u_rightImagerTemp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightImagerTemp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightImagerTemp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightImagerTemp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rightImagerTemp = u_rightImagerTemp.real;
      offset += sizeof(this->rightImagerTemp);
      union {
        float real;
        uint32_t base;
      } u_inputVoltage;
      u_inputVoltage.base = 0;
      u_inputVoltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inputVoltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_inputVoltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_inputVoltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->inputVoltage = u_inputVoltage.real;
      offset += sizeof(this->inputVoltage);
      union {
        float real;
        uint32_t base;
      } u_inputCurrent;
      u_inputCurrent.base = 0;
      u_inputCurrent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inputCurrent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_inputCurrent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_inputCurrent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->inputCurrent = u_inputCurrent.real;
      offset += sizeof(this->inputCurrent);
      union {
        float real;
        uint32_t base;
      } u_fpgaPower;
      u_fpgaPower.base = 0;
      u_fpgaPower.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fpgaPower.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fpgaPower.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fpgaPower.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fpgaPower = u_fpgaPower.real;
      offset += sizeof(this->fpgaPower);
      union {
        float real;
        uint32_t base;
      } u_logicPower;
      u_logicPower.base = 0;
      u_logicPower.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_logicPower.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_logicPower.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_logicPower.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->logicPower = u_logicPower.real;
      offset += sizeof(this->logicPower);
      union {
        float real;
        uint32_t base;
      } u_imagerPower;
      u_imagerPower.base = 0;
      u_imagerPower.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imagerPower.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_imagerPower.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_imagerPower.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->imagerPower = u_imagerPower.real;
      offset += sizeof(this->imagerPower);
     return offset;
    }

    const char * getType(){ return "multisense_ros/DeviceStatus"; };
    const char * getMD5(){ return "2114c900161a6607a8d4a04b3cecd16b"; };

  };

}
#endif