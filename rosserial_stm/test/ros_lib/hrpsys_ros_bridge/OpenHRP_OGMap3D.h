#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_OGMap3D_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_OGMap3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/RTC_Point3D.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_OGMap3D : public ros::Msg
  {
    public:
      double resolution;
      hrpsys_ros_bridge::RTC_Point3D pos;
      int16_t nx;
      int16_t ny;
      int16_t nz;
      uint8_t cells_length;
      uint8_t st_cells;
      uint8_t * cells;

    OpenHRP_OGMap3D():
      resolution(0),
      pos(),
      nx(0),
      ny(0),
      nz(0),
      cells_length(0), cells(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_resolution.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_resolution.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_resolution.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_resolution.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->resolution);
      offset += this->pos.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_nx;
      u_nx.real = this->nx;
      *(outbuffer + offset + 0) = (u_nx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nx.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->nx);
      union {
        int16_t real;
        uint16_t base;
      } u_ny;
      u_ny.real = this->ny;
      *(outbuffer + offset + 0) = (u_ny.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ny.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ny);
      union {
        int16_t real;
        uint16_t base;
      } u_nz;
      u_nz.real = this->nz;
      *(outbuffer + offset + 0) = (u_nz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nz.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->nz);
      *(outbuffer + offset++) = cells_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cells_length; i++){
      *(outbuffer + offset + 0) = (this->cells[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cells[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_resolution.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      offset += this->pos.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_nx;
      u_nx.base = 0;
      u_nx.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nx.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->nx = u_nx.real;
      offset += sizeof(this->nx);
      union {
        int16_t real;
        uint16_t base;
      } u_ny;
      u_ny.base = 0;
      u_ny.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ny.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ny = u_ny.real;
      offset += sizeof(this->ny);
      union {
        int16_t real;
        uint16_t base;
      } u_nz;
      u_nz.base = 0;
      u_nz.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nz.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->nz = u_nz.real;
      offset += sizeof(this->nz);
      uint8_t cells_lengthT = *(inbuffer + offset++);
      if(cells_lengthT > cells_length)
        this->cells = (uint8_t*)realloc(this->cells, cells_lengthT * sizeof(uint8_t));
      offset += 3;
      cells_length = cells_lengthT;
      for( uint8_t i = 0; i < cells_length; i++){
      this->st_cells =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_cells);
        memcpy( &(this->cells[i]), &(this->st_cells), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_OGMap3D"; };
    const char * getMD5(){ return "41db76e604ab520cf21a65c1085e2476"; };

  };

}
#endif