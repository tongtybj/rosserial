#ifndef _ROS_SERVICE_OpenHRP_KalmanFilterService_getKalmanFilterParam_h
#define _ROS_SERVICE_OpenHRP_KalmanFilterService_getKalmanFilterParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_KalmanFilterService_KalmanFilterParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_KALMANFILTERSERVICE_GETKALMANFILTERPARAM[] = "hrpsys_ros_bridge/OpenHRP_KalmanFilterService_getKalmanFilterParam";

  class OpenHRP_KalmanFilterService_getKalmanFilterParamRequest : public ros::Msg
  {
    public:

    OpenHRP_KalmanFilterService_getKalmanFilterParamRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return OPENHRP_KALMANFILTERSERVICE_GETKALMANFILTERPARAM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_KalmanFilterService_getKalmanFilterParamResponse : public ros::Msg
  {
    public:
      bool operation_return;
      hrpsys_ros_bridge::OpenHRP_KalmanFilterService_KalmanFilterParam i_param;

    OpenHRP_KalmanFilterService_getKalmanFilterParamResponse():
      operation_return(0),
      i_param()
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
      offset += this->i_param.serialize(outbuffer + offset);
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
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_KALMANFILTERSERVICE_GETKALMANFILTERPARAM; };
    const char * getMD5(){ return "bb4aaa30d6176e86c92801a029613710"; };

  };

  class OpenHRP_KalmanFilterService_getKalmanFilterParam {
    public:
    typedef OpenHRP_KalmanFilterService_getKalmanFilterParamRequest Request;
    typedef OpenHRP_KalmanFilterService_getKalmanFilterParamResponse Response;
  };

}
#endif
