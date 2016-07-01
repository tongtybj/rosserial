#ifndef _ROS_leap_motion_leapros_h
#define _ROS_leap_motion_leapros_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"

namespace leap_motion
{

  class leapros : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Vector3 direction;
      geometry_msgs::Vector3 normal;
      geometry_msgs::Point palmpos;
      geometry_msgs::Vector3 ypr;
      geometry_msgs::Point thumb_metacarpal;
      geometry_msgs::Point thumb_proximal;
      geometry_msgs::Point thumb_intermediate;
      geometry_msgs::Point thumb_distal;
      geometry_msgs::Point thumb_tip;
      geometry_msgs::Point index_metacarpal;
      geometry_msgs::Point index_proximal;
      geometry_msgs::Point index_intermediate;
      geometry_msgs::Point index_distal;
      geometry_msgs::Point index_tip;
      geometry_msgs::Point middle_metacarpal;
      geometry_msgs::Point middle_proximal;
      geometry_msgs::Point middle_intermediate;
      geometry_msgs::Point middle_distal;
      geometry_msgs::Point middle_tip;
      geometry_msgs::Point ring_metacarpal;
      geometry_msgs::Point ring_proximal;
      geometry_msgs::Point ring_intermediate;
      geometry_msgs::Point ring_distal;
      geometry_msgs::Point ring_tip;
      geometry_msgs::Point pinky_metacarpal;
      geometry_msgs::Point pinky_proximal;
      geometry_msgs::Point pinky_intermediate;
      geometry_msgs::Point pinky_distal;
      geometry_msgs::Point pinky_tip;

    leapros():
      header(),
      direction(),
      normal(),
      palmpos(),
      ypr(),
      thumb_metacarpal(),
      thumb_proximal(),
      thumb_intermediate(),
      thumb_distal(),
      thumb_tip(),
      index_metacarpal(),
      index_proximal(),
      index_intermediate(),
      index_distal(),
      index_tip(),
      middle_metacarpal(),
      middle_proximal(),
      middle_intermediate(),
      middle_distal(),
      middle_tip(),
      ring_metacarpal(),
      ring_proximal(),
      ring_intermediate(),
      ring_distal(),
      ring_tip(),
      pinky_metacarpal(),
      pinky_proximal(),
      pinky_intermediate(),
      pinky_distal(),
      pinky_tip()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->direction.serialize(outbuffer + offset);
      offset += this->normal.serialize(outbuffer + offset);
      offset += this->palmpos.serialize(outbuffer + offset);
      offset += this->ypr.serialize(outbuffer + offset);
      offset += this->thumb_metacarpal.serialize(outbuffer + offset);
      offset += this->thumb_proximal.serialize(outbuffer + offset);
      offset += this->thumb_intermediate.serialize(outbuffer + offset);
      offset += this->thumb_distal.serialize(outbuffer + offset);
      offset += this->thumb_tip.serialize(outbuffer + offset);
      offset += this->index_metacarpal.serialize(outbuffer + offset);
      offset += this->index_proximal.serialize(outbuffer + offset);
      offset += this->index_intermediate.serialize(outbuffer + offset);
      offset += this->index_distal.serialize(outbuffer + offset);
      offset += this->index_tip.serialize(outbuffer + offset);
      offset += this->middle_metacarpal.serialize(outbuffer + offset);
      offset += this->middle_proximal.serialize(outbuffer + offset);
      offset += this->middle_intermediate.serialize(outbuffer + offset);
      offset += this->middle_distal.serialize(outbuffer + offset);
      offset += this->middle_tip.serialize(outbuffer + offset);
      offset += this->ring_metacarpal.serialize(outbuffer + offset);
      offset += this->ring_proximal.serialize(outbuffer + offset);
      offset += this->ring_intermediate.serialize(outbuffer + offset);
      offset += this->ring_distal.serialize(outbuffer + offset);
      offset += this->ring_tip.serialize(outbuffer + offset);
      offset += this->pinky_metacarpal.serialize(outbuffer + offset);
      offset += this->pinky_proximal.serialize(outbuffer + offset);
      offset += this->pinky_intermediate.serialize(outbuffer + offset);
      offset += this->pinky_distal.serialize(outbuffer + offset);
      offset += this->pinky_tip.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->direction.deserialize(inbuffer + offset);
      offset += this->normal.deserialize(inbuffer + offset);
      offset += this->palmpos.deserialize(inbuffer + offset);
      offset += this->ypr.deserialize(inbuffer + offset);
      offset += this->thumb_metacarpal.deserialize(inbuffer + offset);
      offset += this->thumb_proximal.deserialize(inbuffer + offset);
      offset += this->thumb_intermediate.deserialize(inbuffer + offset);
      offset += this->thumb_distal.deserialize(inbuffer + offset);
      offset += this->thumb_tip.deserialize(inbuffer + offset);
      offset += this->index_metacarpal.deserialize(inbuffer + offset);
      offset += this->index_proximal.deserialize(inbuffer + offset);
      offset += this->index_intermediate.deserialize(inbuffer + offset);
      offset += this->index_distal.deserialize(inbuffer + offset);
      offset += this->index_tip.deserialize(inbuffer + offset);
      offset += this->middle_metacarpal.deserialize(inbuffer + offset);
      offset += this->middle_proximal.deserialize(inbuffer + offset);
      offset += this->middle_intermediate.deserialize(inbuffer + offset);
      offset += this->middle_distal.deserialize(inbuffer + offset);
      offset += this->middle_tip.deserialize(inbuffer + offset);
      offset += this->ring_metacarpal.deserialize(inbuffer + offset);
      offset += this->ring_proximal.deserialize(inbuffer + offset);
      offset += this->ring_intermediate.deserialize(inbuffer + offset);
      offset += this->ring_distal.deserialize(inbuffer + offset);
      offset += this->ring_tip.deserialize(inbuffer + offset);
      offset += this->pinky_metacarpal.deserialize(inbuffer + offset);
      offset += this->pinky_proximal.deserialize(inbuffer + offset);
      offset += this->pinky_intermediate.deserialize(inbuffer + offset);
      offset += this->pinky_distal.deserialize(inbuffer + offset);
      offset += this->pinky_tip.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "leap_motion/leapros"; };
    const char * getMD5(){ return "e37447f7532c765d6c587f418fd5dd03"; };

  };

}
#endif