#ifndef _ROS_SERVICE_OpenHRP_KalmanFilterService_resetKalmanFilterState_h
#define _ROS_SERVICE_OpenHRP_KalmanFilterService_resetKalmanFilterState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_KALMANFILTERSERVICE_RESETKALMANFILTERSTATE[] = "hrpsys_ros_bridge/OpenHRP_KalmanFilterService_resetKalmanFilterState";

  class OpenHRP_KalmanFilterService_resetKalmanFilterStateRequest : public ros::Msg
  {
    public:

    OpenHRP_KalmanFilterService_resetKalmanFilterStateRequest()
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

    const char * getType(){ return OPENHRP_KALMANFILTERSERVICE_RESETKALMANFILTERSTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_KalmanFilterService_resetKalmanFilterStateResponse : public ros::Msg
  {
    public:
      bool operation_return;

    OpenHRP_KalmanFilterService_resetKalmanFilterStateResponse():
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

    const char * getType(){ return OPENHRP_KALMANFILTERSERVICE_RESETKALMANFILTERSTATE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_KalmanFilterService_resetKalmanFilterState {
    public:
    typedef OpenHRP_KalmanFilterService_resetKalmanFilterStateRequest Request;
    typedef OpenHRP_KalmanFilterService_resetKalmanFilterStateResponse Response;
  };

}
#endif
