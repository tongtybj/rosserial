#ifndef _ROS_SERVICE_OpenHRP_KalmanFilterService_setKalmanFilterParam_h
#define _ROS_SERVICE_OpenHRP_KalmanFilterService_setKalmanFilterParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_KalmanFilterService_KalmanFilterParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_KALMANFILTERSERVICE_SETKALMANFILTERPARAM[] = "hrpsys_ros_bridge/OpenHRP_KalmanFilterService_setKalmanFilterParam";

  class OpenHRP_KalmanFilterService_setKalmanFilterParamRequest : public ros::Msg
  {
    public:
      hrpsys_ros_bridge::OpenHRP_KalmanFilterService_KalmanFilterParam i_param;

    OpenHRP_KalmanFilterService_setKalmanFilterParamRequest():
      i_param()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->i_param.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_KALMANFILTERSERVICE_SETKALMANFILTERPARAM; };
    const char * getMD5(){ return "c8821040797ee7bc4fd42747b0b39708"; };

  };

  class OpenHRP_KalmanFilterService_setKalmanFilterParamResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_KalmanFilterService_setKalmanFilterParamResponse():
      operation_return(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_KALMANFILTERSERVICE_SETKALMANFILTERPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_KalmanFilterService_setKalmanFilterParam {
    public:
    typedef OpenHRP_KalmanFilterService_setKalmanFilterParamRequest Request;
    typedef OpenHRP_KalmanFilterService_setKalmanFilterParamResponse Response;
  };

}
#endif
