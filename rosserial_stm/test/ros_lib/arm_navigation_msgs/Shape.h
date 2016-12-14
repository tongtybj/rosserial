#ifndef _ROS_arm_navigation_msgs_Shape_h
#define _ROS_arm_navigation_msgs_Shape_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace arm_navigation_msgs
{

  class Shape : public ros::Msg
  {
    public:
      int8_t type;
      uint8_t dimensions_length;
      double st_dimensions;
      double * dimensions;
      uint8_t triangles_length;
      int32_t st_triangles;
      int32_t * triangles;
      uint8_t vertices_length;
      geometry_msgs::Point st_vertices;
      geometry_msgs::Point * vertices;
      enum { SPHERE = 0 };
      enum { BOX = 1 };
      enum { CYLINDER = 2 };
      enum { MESH = 3 };

    Shape():
      type(0),
      dimensions_length(0), dimensions(NULL),
      triangles_length(0), triangles(NULL),
      vertices_length(0), vertices(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset++) = dimensions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < dimensions_length; i++){
      union {
        double real;
        uint64_t base;
      } u_dimensionsi;
      u_dimensionsi.real = this->dimensions[i];
      *(outbuffer + offset + 0) = (u_dimensionsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dimensionsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dimensionsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dimensionsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dimensionsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dimensionsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dimensionsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dimensionsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dimensions[i]);
      }
      *(outbuffer + offset++) = triangles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < triangles_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_trianglesi;
      u_trianglesi.real = this->triangles[i];
      *(outbuffer + offset + 0) = (u_trianglesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trianglesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trianglesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trianglesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->triangles[i]);
      }
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
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
      uint8_t dimensions_lengthT = *(inbuffer + offset++);
      if(dimensions_lengthT > dimensions_length)
        this->dimensions = (double*)realloc(this->dimensions, dimensions_lengthT * sizeof(double));
      offset += 3;
      dimensions_length = dimensions_lengthT;
      for( uint8_t i = 0; i < dimensions_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_dimensions;
      u_st_dimensions.base = 0;
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_dimensions = u_st_dimensions.real;
      offset += sizeof(this->st_dimensions);
        memcpy( &(this->dimensions[i]), &(this->st_dimensions), sizeof(double));
      }
      uint8_t triangles_lengthT = *(inbuffer + offset++);
      if(triangles_lengthT > triangles_length)
        this->triangles = (int32_t*)realloc(this->triangles, triangles_lengthT * sizeof(int32_t));
      offset += 3;
      triangles_length = triangles_lengthT;
      for( uint8_t i = 0; i < triangles_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_triangles;
      u_st_triangles.base = 0;
      u_st_triangles.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_triangles.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_triangles.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_triangles.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_triangles = u_st_triangles.real;
      offset += sizeof(this->st_triangles);
        memcpy( &(this->triangles[i]), &(this->st_triangles), sizeof(int32_t));
      }
      uint8_t vertices_lengthT = *(inbuffer + offset++);
      if(vertices_lengthT > vertices_length)
        this->vertices = (geometry_msgs::Point*)realloc(this->vertices, vertices_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      vertices_length = vertices_lengthT;
      for( uint8_t i = 0; i < vertices_length; i++){
      offset += this->st_vertices.deserialize(inbuffer + offset);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/Shape"; };
    const char * getMD5(){ return "59935940044147de75e7523b5d37c4d7"; };

  };

}
#endif