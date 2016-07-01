#ifndef _ROS_SERVICE_SyncCommand_h
#define _ROS_SERVICE_SyncCommand_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_gazebo_msgs/RobotState.h"
#include "hrpsys_gazebo_msgs/JointCommand.h"

namespace hrpsys_gazebo_msgs
{

static const char SYNCCOMMAND[] = "hrpsys_gazebo_msgs/SyncCommand";

  class SyncCommandRequest : public ros::Msg
  {
    public:
      hrpsys_gazebo_msgs::JointCommand joint_command;

    SyncCommandRequest():
      joint_command()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_command.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_command.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SYNCCOMMAND; };
    const char * getMD5(){ return "5d5a4324d44110530d7e01a9925c5c0f"; };

  };

  class SyncCommandResponse : public ros::Msg
  {
    public:
      hrpsys_gazebo_msgs::RobotState robot_state;

    SyncCommandResponse():
      robot_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SYNCCOMMAND; };
    const char * getMD5(){ return "495f1e8a77b19483d126883e45476195"; };

  };

  class SyncCommand {
    public:
    typedef SyncCommandRequest Request;
    typedef SyncCommandResponse Response;
  };

}
#endif
