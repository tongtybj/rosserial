#ifndef _ROS_SERVICE_ICPService_h
#define _ROS_SERVICE_ICPService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "jsk_recognition_msgs/BoundingBox.h"
#include "sensor_msgs/PointCloud2.h"
#include "jsk_interactive_marker/MarkerDimensions.h"

namespace drc_task_common
{

static const char ICPSERVICE[] = "drc_task_common/ICPService";

  class ICPServiceRequest : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 points;
      jsk_recognition_msgs::BoundingBox box;

    ICPServiceRequest():
      points(),
      box()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->points.serialize(outbuffer + offset);
      offset += this->box.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->points.deserialize(inbuffer + offset);
      offset += this->box.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ICPSERVICE; };
    const char * getMD5(){ return "998bc619e2a100205a68611df7199672"; };

  };

  class ICPServiceResponse : public ros::Msg
  {
    public:
      jsk_interactive_marker::MarkerDimensions dim;
      geometry_msgs::PoseStamped pose_stamped;

    ICPServiceResponse():
      dim(),
      pose_stamped()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->dim.serialize(outbuffer + offset);
      offset += this->pose_stamped.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->dim.deserialize(inbuffer + offset);
      offset += this->pose_stamped.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ICPSERVICE; };
    const char * getMD5(){ return "19de98aa62eebdda34281b3f4b84486d"; };

  };

  class ICPService {
    public:
    typedef ICPServiceRequest Request;
    typedef ICPServiceResponse Response;
  };

}
#endif
