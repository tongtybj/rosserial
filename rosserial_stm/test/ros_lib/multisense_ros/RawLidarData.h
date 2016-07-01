#ifndef _ROS_multisense_ros_RawLidarData_h
#define _ROS_multisense_ros_RawLidarData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace multisense_ros
{

  class RawLidarData : public ros::Msg
  {
    public:
      uint32_t scan_count;
      ros::Time time_start;
      ros::Time time_end;
      int32_t angle_start;
      int32_t angle_end;
      uint8_t distance_length;
      uint32_t st_distance;
      uint32_t * distance;
      uint8_t intensity_length;
      uint32_t st_intensity;
      uint32_t * intensity;

    RawLidarData():
      scan_count(0),
      time_start(),
      time_end(),
      angle_start(0),
      angle_end(0),
      distance_length(0), distance(NULL),
      intensity_length(0), intensity(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->scan_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->scan_count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->scan_count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->scan_count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_count);
      *(outbuffer + offset + 0) = (this->time_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_start.sec);
      *(outbuffer + offset + 0) = (this->time_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_start.nsec);
      *(outbuffer + offset + 0) = (this->time_end.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_end.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_end.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_end.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_end.sec);
      *(outbuffer + offset + 0) = (this->time_end.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_end.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_end.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_end.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_end.nsec);
      union {
        int32_t real;
        uint32_t base;
      } u_angle_start;
      u_angle_start.real = this->angle_start;
      *(outbuffer + offset + 0) = (u_angle_start.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_start.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_start.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_start.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_start);
      union {
        int32_t real;
        uint32_t base;
      } u_angle_end;
      u_angle_end.real = this->angle_end;
      *(outbuffer + offset + 0) = (u_angle_end.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_end.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_end.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_end.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_end);
      *(outbuffer + offset++) = distance_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < distance_length; i++){
      *(outbuffer + offset + 0) = (this->distance[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->distance[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->distance[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->distance[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance[i]);
      }
      *(outbuffer + offset++) = intensity_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < intensity_length; i++){
      *(outbuffer + offset + 0) = (this->intensity[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->intensity[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->intensity[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->intensity[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensity[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->scan_count =  ((uint32_t) (*(inbuffer + offset)));
      this->scan_count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->scan_count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->scan_count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->scan_count);
      this->time_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_start.sec);
      this->time_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_start.nsec);
      this->time_end.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_end.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_end.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_end.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_end.sec);
      this->time_end.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_end.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_end.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_end.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_end.nsec);
      union {
        int32_t real;
        uint32_t base;
      } u_angle_start;
      u_angle_start.base = 0;
      u_angle_start.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_start.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_start.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_start.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_start = u_angle_start.real;
      offset += sizeof(this->angle_start);
      union {
        int32_t real;
        uint32_t base;
      } u_angle_end;
      u_angle_end.base = 0;
      u_angle_end.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_end.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_end.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_end.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_end = u_angle_end.real;
      offset += sizeof(this->angle_end);
      uint8_t distance_lengthT = *(inbuffer + offset++);
      if(distance_lengthT > distance_length)
        this->distance = (uint32_t*)realloc(this->distance, distance_lengthT * sizeof(uint32_t));
      offset += 3;
      distance_length = distance_lengthT;
      for( uint8_t i = 0; i < distance_length; i++){
      this->st_distance =  ((uint32_t) (*(inbuffer + offset)));
      this->st_distance |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_distance |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_distance |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_distance);
        memcpy( &(this->distance[i]), &(this->st_distance), sizeof(uint32_t));
      }
      uint8_t intensity_lengthT = *(inbuffer + offset++);
      if(intensity_lengthT > intensity_length)
        this->intensity = (uint32_t*)realloc(this->intensity, intensity_lengthT * sizeof(uint32_t));
      offset += 3;
      intensity_length = intensity_lengthT;
      for( uint8_t i = 0; i < intensity_length; i++){
      this->st_intensity =  ((uint32_t) (*(inbuffer + offset)));
      this->st_intensity |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_intensity |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_intensity |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_intensity);
        memcpy( &(this->intensity[i]), &(this->st_intensity), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "multisense_ros/RawLidarData"; };
    const char * getMD5(){ return "c6ed0471015a3cddab804db8e53836c1"; };

  };

}
#endif