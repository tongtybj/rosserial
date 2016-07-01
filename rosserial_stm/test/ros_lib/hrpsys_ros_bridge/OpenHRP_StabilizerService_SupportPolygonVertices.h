#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_SupportPolygonVertices_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_StabilizerService_SupportPolygonVertices_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_TwoDimensionVertex.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_StabilizerService_SupportPolygonVertices : public ros::Msg
  {
    public:
      uint8_t vertices_length;
      hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex st_vertices;
      hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex * vertices;

    OpenHRP_StabilizerService_SupportPolygonVertices():
      vertices_length(0), vertices(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = vertices_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < vertices_length; i++){
      offset += this->vertices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t vertices_lengthT = *(inbuffer + offset++);
      if(vertices_lengthT > vertices_length)
        this->vertices = (hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex*)realloc(this->vertices, vertices_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex));
      offset += 3;
      vertices_length = vertices_lengthT;
      for( uint8_t i = 0; i < vertices_length; i++){
      offset += this->st_vertices.deserialize(inbuffer + offset);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(hrpsys_ros_bridge::OpenHRP_StabilizerService_TwoDimensionVertex));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_StabilizerService_SupportPolygonVertices"; };
    const char * getMD5(){ return "cf23d460953b52e710154e7238ea2e5b"; };

  };

}
#endif