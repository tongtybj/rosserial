#ifndef _ROS_SERVICE_StartTracking_h
#define _ROS_SERVICE_StartTracking_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace image_processing
{

static const char STARTTRACKING[] = "image_processing/StartTracking";

  class StartTrackingRequest : public ros::Msg
  {
    public:
      bool tracking_req;

    StartTrackingRequest():
      tracking_req(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_tracking_req;
      u_tracking_req.real = this->tracking_req;
      *(outbuffer + offset + 0) = (u_tracking_req.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking_req);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_tracking_req;
      u_tracking_req.base = 0;
      u_tracking_req.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tracking_req = u_tracking_req.real;
      offset += sizeof(this->tracking_req);
     return offset;
    }

    const char * getType(){ return STARTTRACKING; };
    const char * getMD5(){ return "308c13392d1c1193c8bb381852bb99bb"; };

  };

  class StartTrackingResponse : public ros::Msg
  {
    public:
      bool tracking_res;

    StartTrackingResponse():
      tracking_res(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_tracking_res;
      u_tracking_res.real = this->tracking_res;
      *(outbuffer + offset + 0) = (u_tracking_res.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking_res);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_tracking_res;
      u_tracking_res.base = 0;
      u_tracking_res.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tracking_res = u_tracking_res.real;
      offset += sizeof(this->tracking_res);
     return offset;
    }

    const char * getType(){ return STARTTRACKING; };
    const char * getMD5(){ return "bd2542e2f15a79712b2248ee7dc49042"; };

  };

  class StartTracking {
    public:
    typedef StartTrackingRequest Request;
    typedef StartTrackingResponse Response;
  };

}
#endif
