#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_objectTurnaroundDetectorParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ImpedanceControllerService_objectTurnaroundDetectorParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ImpedanceControllerService_objectTurnaroundDetectorParam : public ros::Msg
  {
    public:
      double wrench_cutoff_freq;
      double dwrench_cutoff_freq;
      double detect_ratio_thre;
      double start_ratio_thre;
      double detect_time_thre;
      double start_time_thre;
      double axis[3];
      double moment_center[3];
      int64_t detector_total_wrench;

    OpenHRP_ImpedanceControllerService_objectTurnaroundDetectorParam():
      wrench_cutoff_freq(0),
      dwrench_cutoff_freq(0),
      detect_ratio_thre(0),
      start_ratio_thre(0),
      detect_time_thre(0),
      start_time_thre(0),
      axis(),
      moment_center(),
      detector_total_wrench(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_wrench_cutoff_freq;
      u_wrench_cutoff_freq.real = this->wrench_cutoff_freq;
      *(outbuffer + offset + 0) = (u_wrench_cutoff_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wrench_cutoff_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wrench_cutoff_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wrench_cutoff_freq.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_wrench_cutoff_freq.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_wrench_cutoff_freq.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_wrench_cutoff_freq.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_wrench_cutoff_freq.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->wrench_cutoff_freq);
      union {
        double real;
        uint64_t base;
      } u_dwrench_cutoff_freq;
      u_dwrench_cutoff_freq.real = this->dwrench_cutoff_freq;
      *(outbuffer + offset + 0) = (u_dwrench_cutoff_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dwrench_cutoff_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dwrench_cutoff_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dwrench_cutoff_freq.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dwrench_cutoff_freq.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dwrench_cutoff_freq.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dwrench_cutoff_freq.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dwrench_cutoff_freq.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dwrench_cutoff_freq);
      union {
        double real;
        uint64_t base;
      } u_detect_ratio_thre;
      u_detect_ratio_thre.real = this->detect_ratio_thre;
      *(outbuffer + offset + 0) = (u_detect_ratio_thre.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detect_ratio_thre.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detect_ratio_thre.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detect_ratio_thre.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_detect_ratio_thre.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_detect_ratio_thre.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_detect_ratio_thre.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_detect_ratio_thre.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->detect_ratio_thre);
      union {
        double real;
        uint64_t base;
      } u_start_ratio_thre;
      u_start_ratio_thre.real = this->start_ratio_thre;
      *(outbuffer + offset + 0) = (u_start_ratio_thre.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_ratio_thre.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_start_ratio_thre.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_start_ratio_thre.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_start_ratio_thre.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_start_ratio_thre.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_start_ratio_thre.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_start_ratio_thre.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->start_ratio_thre);
      union {
        double real;
        uint64_t base;
      } u_detect_time_thre;
      u_detect_time_thre.real = this->detect_time_thre;
      *(outbuffer + offset + 0) = (u_detect_time_thre.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detect_time_thre.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detect_time_thre.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detect_time_thre.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_detect_time_thre.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_detect_time_thre.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_detect_time_thre.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_detect_time_thre.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->detect_time_thre);
      union {
        double real;
        uint64_t base;
      } u_start_time_thre;
      u_start_time_thre.real = this->start_time_thre;
      *(outbuffer + offset + 0) = (u_start_time_thre.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_start_time_thre.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_start_time_thre.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_start_time_thre.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_start_time_thre.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_start_time_thre.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_start_time_thre.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_start_time_thre.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->start_time_thre);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_axisi;
      u_axisi.real = this->axis[i];
      *(outbuffer + offset + 0) = (u_axisi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_axisi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_axisi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_axisi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_axisi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_axisi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_axisi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_axisi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->axis[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_moment_centeri;
      u_moment_centeri.real = this->moment_center[i];
      *(outbuffer + offset + 0) = (u_moment_centeri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_moment_centeri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_moment_centeri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_moment_centeri.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_moment_centeri.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_moment_centeri.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_moment_centeri.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_moment_centeri.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->moment_center[i]);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_detector_total_wrench;
      u_detector_total_wrench.real = this->detector_total_wrench;
      *(outbuffer + offset + 0) = (u_detector_total_wrench.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_detector_total_wrench.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_detector_total_wrench.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_detector_total_wrench.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_detector_total_wrench.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_detector_total_wrench.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_detector_total_wrench.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_detector_total_wrench.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->detector_total_wrench);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_wrench_cutoff_freq;
      u_wrench_cutoff_freq.base = 0;
      u_wrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_wrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_wrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_wrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_wrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->wrench_cutoff_freq = u_wrench_cutoff_freq.real;
      offset += sizeof(this->wrench_cutoff_freq);
      union {
        double real;
        uint64_t base;
      } u_dwrench_cutoff_freq;
      u_dwrench_cutoff_freq.base = 0;
      u_dwrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dwrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dwrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dwrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_dwrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_dwrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_dwrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_dwrench_cutoff_freq.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->dwrench_cutoff_freq = u_dwrench_cutoff_freq.real;
      offset += sizeof(this->dwrench_cutoff_freq);
      union {
        double real;
        uint64_t base;
      } u_detect_ratio_thre;
      u_detect_ratio_thre.base = 0;
      u_detect_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detect_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detect_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detect_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_detect_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_detect_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_detect_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_detect_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->detect_ratio_thre = u_detect_ratio_thre.real;
      offset += sizeof(this->detect_ratio_thre);
      union {
        double real;
        uint64_t base;
      } u_start_ratio_thre;
      u_start_ratio_thre.base = 0;
      u_start_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_start_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_start_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_start_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_start_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_start_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_start_ratio_thre.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->start_ratio_thre = u_start_ratio_thre.real;
      offset += sizeof(this->start_ratio_thre);
      union {
        double real;
        uint64_t base;
      } u_detect_time_thre;
      u_detect_time_thre.base = 0;
      u_detect_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detect_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detect_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detect_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_detect_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_detect_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_detect_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_detect_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->detect_time_thre = u_detect_time_thre.real;
      offset += sizeof(this->detect_time_thre);
      union {
        double real;
        uint64_t base;
      } u_start_time_thre;
      u_start_time_thre.base = 0;
      u_start_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_start_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_start_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_start_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_start_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_start_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_start_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_start_time_thre.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->start_time_thre = u_start_time_thre.real;
      offset += sizeof(this->start_time_thre);
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_axisi;
      u_axisi.base = 0;
      u_axisi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_axisi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_axisi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_axisi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_axisi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_axisi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_axisi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_axisi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->axis[i] = u_axisi.real;
      offset += sizeof(this->axis[i]);
      }
      for( uint8_t i = 0; i < 3; i++){
      union {
        double real;
        uint64_t base;
      } u_moment_centeri;
      u_moment_centeri.base = 0;
      u_moment_centeri.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_moment_centeri.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_moment_centeri.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_moment_centeri.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_moment_centeri.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_moment_centeri.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_moment_centeri.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_moment_centeri.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->moment_center[i] = u_moment_centeri.real;
      offset += sizeof(this->moment_center[i]);
      }
      union {
        int64_t real;
        uint64_t base;
      } u_detector_total_wrench;
      u_detector_total_wrench.base = 0;
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_detector_total_wrench.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->detector_total_wrench = u_detector_total_wrench.real;
      offset += sizeof(this->detector_total_wrench);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_objectTurnaroundDetectorParam"; };
    const char * getMD5(){ return "d15910ebf1dd211b9d41019db8254528"; };

  };

}
#endif