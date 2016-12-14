#ifndef _ROS_pal_tablet_msgs_RobotStatus_h
#define _ROS_pal_tablet_msgs_RobotStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_tablet_msgs/FunctionalityStatus.h"

namespace pal_tablet_msgs
{

  class RobotStatus : public ros::Msg
  {
    public:
      uint8_t messages_length;
      pal_tablet_msgs::FunctionalityStatus st_messages;
      pal_tablet_msgs::FunctionalityStatus * messages;

    RobotStatus():
      messages_length(0), messages(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = messages_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < messages_length; i++){
      offset += this->messages[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t messages_lengthT = *(inbuffer + offset++);
      if(messages_lengthT > messages_length)
        this->messages = (pal_tablet_msgs::FunctionalityStatus*)realloc(this->messages, messages_lengthT * sizeof(pal_tablet_msgs::FunctionalityStatus));
      offset += 3;
      messages_length = messages_lengthT;
      for( uint8_t i = 0; i < messages_length; i++){
      offset += this->st_messages.deserialize(inbuffer + offset);
        memcpy( &(this->messages[i]), &(this->st_messages), sizeof(pal_tablet_msgs::FunctionalityStatus));
      }
     return offset;
    }

    const char * getType(){ return "pal_tablet_msgs/RobotStatus"; };
    const char * getMD5(){ return "3495bf9d81b79deaa82f3652871818c5"; };

  };

}
#endif