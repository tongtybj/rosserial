#ifndef _ROS_drc_task_common_InteractiveMarkerArray_h
#define _ROS_drc_task_common_InteractiveMarkerArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "visualization_msgs/InteractiveMarker.h"

namespace drc_task_common
{

  class InteractiveMarkerArray : public ros::Msg
  {
    public:
      uint8_t int_markers_length;
      visualization_msgs::InteractiveMarker st_int_markers;
      visualization_msgs::InteractiveMarker * int_markers;

    InteractiveMarkerArray():
      int_markers_length(0), int_markers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = int_markers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < int_markers_length; i++){
      offset += this->int_markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t int_markers_lengthT = *(inbuffer + offset++);
      if(int_markers_lengthT > int_markers_length)
        this->int_markers = (visualization_msgs::InteractiveMarker*)realloc(this->int_markers, int_markers_lengthT * sizeof(visualization_msgs::InteractiveMarker));
      offset += 3;
      int_markers_length = int_markers_lengthT;
      for( uint8_t i = 0; i < int_markers_length; i++){
      offset += this->st_int_markers.deserialize(inbuffer + offset);
        memcpy( &(this->int_markers[i]), &(this->st_int_markers), sizeof(visualization_msgs::InteractiveMarker));
      }
     return offset;
    }

    const char * getType(){ return "drc_task_common/InteractiveMarkerArray"; };
    const char * getMD5(){ return "d4725d4030123369d19b9e3bd499fbc1"; };

  };

}
#endif