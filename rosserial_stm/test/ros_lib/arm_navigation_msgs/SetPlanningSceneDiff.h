#ifndef _ROS_SERVICE_SetPlanningSceneDiff_h
#define _ROS_SERVICE_SetPlanningSceneDiff_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/PlanningScene.h"
#include "arm_navigation_msgs/OrderedCollisionOperations.h"

namespace arm_navigation_msgs
{

static const char SETPLANNINGSCENEDIFF[] = "arm_navigation_msgs/SetPlanningSceneDiff";

  class SetPlanningSceneDiffRequest : public ros::Msg
  {
    public:
      arm_navigation_msgs::PlanningScene planning_scene_diff;
      arm_navigation_msgs::OrderedCollisionOperations operations;

    SetPlanningSceneDiffRequest():
      planning_scene_diff(),
      operations()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->planning_scene_diff.serialize(outbuffer + offset);
      offset += this->operations.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->planning_scene_diff.deserialize(inbuffer + offset);
      offset += this->operations.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETPLANNINGSCENEDIFF; };
    const char * getMD5(){ return "67ad55e9bed9c8f21dfb4b9b1ca8df7d"; };

  };

  class SetPlanningSceneDiffResponse : public ros::Msg
  {
    public:
      arm_navigation_msgs::PlanningScene planning_scene;

    SetPlanningSceneDiffResponse():
      planning_scene()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->planning_scene.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->planning_scene.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETPLANNINGSCENEDIFF; };
    const char * getMD5(){ return "285525c9abe002fbafa99af84a14b4cb"; };

  };

  class SetPlanningSceneDiff {
    public:
    typedef SetPlanningSceneDiffRequest Request;
    typedef SetPlanningSceneDiffResponse Response;
  };

}
#endif
