#ifndef _ROS_SERVICE_AngleVectorCommand_h
#define _ROS_SERVICE_AngleVectorCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/UInt32.h"

namespace drc_task_common
{

static const char ANGLEVECTORCOMMAND[] = "drc_task_common/AngleVectorCommand";

  class AngleVectorCommandRequest : public ros::Msg
  {
    public:
      std_msgs::Float32MultiArray angle_vector;
      std_msgs::UInt32 interpolation_time;

    AngleVectorCommandRequest():
      angle_vector(),
      interpolation_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->angle_vector.serialize(outbuffer + offset);
      offset += this->interpolation_time.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->angle_vector.deserialize(inbuffer + offset);
      offset += this->interpolation_time.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ANGLEVECTORCOMMAND; };
    const char * getMD5(){ return "3eeeeac468b9a0feaed363aadd07d6c0"; };

  };

  class AngleVectorCommandResponse : public ros::Msg
  {
    public:

    AngleVectorCommandResponse()
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

    const char * getType(){ return ANGLEVECTORCOMMAND; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AngleVectorCommand {
    public:
    typedef AngleVectorCommandRequest Request;
    typedef AngleVectorCommandResponse Response;
  };

}
#endif
