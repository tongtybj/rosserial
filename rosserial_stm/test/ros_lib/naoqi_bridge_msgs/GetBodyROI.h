#ifndef _ROS_SERVICE_GetBodyROI_h
#define _ROS_SERVICE_GetBodyROI_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "naoqi_bridge_msgs/BodyROI.h"

namespace naoqi_bridge_msgs
{

static const char GETBODYROI[] = "naoqi_bridge_msgs/GetBodyROI";

  class GetBodyROIRequest : public ros::Msg
  {
    public:

    GetBodyROIRequest()
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

    const char * getType(){ return GETBODYROI; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetBodyROIResponse : public ros::Msg
  {
    public:
      uint8_t bodies_length;
      naoqi_bridge_msgs::BodyROI st_bodies;
      naoqi_bridge_msgs::BodyROI * bodies;

    GetBodyROIResponse():
      bodies_length(0), bodies(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = bodies_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < bodies_length; i++){
      offset += this->bodies[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t bodies_lengthT = *(inbuffer + offset++);
      if(bodies_lengthT > bodies_length)
        this->bodies = (naoqi_bridge_msgs::BodyROI*)realloc(this->bodies, bodies_lengthT * sizeof(naoqi_bridge_msgs::BodyROI));
      offset += 3;
      bodies_length = bodies_lengthT;
      for( uint8_t i = 0; i < bodies_length; i++){
      offset += this->st_bodies.deserialize(inbuffer + offset);
        memcpy( &(this->bodies[i]), &(this->st_bodies), sizeof(naoqi_bridge_msgs::BodyROI));
      }
     return offset;
    }

    const char * getType(){ return GETBODYROI; };
    const char * getMD5(){ return "ecc2963facbb989a955948135b6e21fd"; };

  };

  class GetBodyROI {
    public:
    typedef GetBodyROIRequest Request;
    typedef GetBodyROIResponse Response;
  };

}
#endif
