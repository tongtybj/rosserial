#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_TorqueControllerService_torqueControllerParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_TorqueControllerService_torqueControllerParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_TorqueControllerService_torqueControllerParam : public ros::Msg
  {
    public:
      double tc;
      double ke;
      double kd;
      double ki;
      double alpha;
      double beta;

    OpenHRP_TorqueControllerService_torqueControllerParam():
      tc(0),
      ke(0),
      kd(0),
      ki(0),
      alpha(0),
      beta(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_tc;
      u_tc.real = this->tc;
      *(outbuffer + offset + 0) = (u_tc.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tc.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tc.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tc.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_tc.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_tc.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_tc.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_tc.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->tc);
      union {
        double real;
        uint64_t base;
      } u_ke;
      u_ke.real = this->ke;
      *(outbuffer + offset + 0) = (u_ke.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ke.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ke.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ke.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ke.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ke.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ke.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ke.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ke);
      union {
        double real;
        uint64_t base;
      } u_kd;
      u_kd.real = this->kd;
      *(outbuffer + offset + 0) = (u_kd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_kd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_kd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_kd.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_kd.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_kd.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_kd.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_kd.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->kd);
      union {
        double real;
        uint64_t base;
      } u_ki;
      u_ki.real = this->ki;
      *(outbuffer + offset + 0) = (u_ki.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ki.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ki.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ki.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ki.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ki.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ki.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ki.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ki);
      union {
        double real;
        uint64_t base;
      } u_alpha;
      u_alpha.real = this->alpha;
      *(outbuffer + offset + 0) = (u_alpha.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alpha.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alpha.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alpha.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_alpha.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_alpha.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_alpha.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_alpha.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->alpha);
      union {
        double real;
        uint64_t base;
      } u_beta;
      u_beta.real = this->beta;
      *(outbuffer + offset + 0) = (u_beta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_beta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_beta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_beta.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_beta.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_beta.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_beta.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_beta.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->beta);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_tc;
      u_tc.base = 0;
      u_tc.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tc.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tc.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tc.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_tc.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_tc.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_tc.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_tc.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->tc = u_tc.real;
      offset += sizeof(this->tc);
      union {
        double real;
        uint64_t base;
      } u_ke;
      u_ke.base = 0;
      u_ke.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ke.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ke.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ke.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ke.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ke.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ke.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ke.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ke = u_ke.real;
      offset += sizeof(this->ke);
      union {
        double real;
        uint64_t base;
      } u_kd;
      u_kd.base = 0;
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_kd.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->kd = u_kd.real;
      offset += sizeof(this->kd);
      union {
        double real;
        uint64_t base;
      } u_ki;
      u_ki.base = 0;
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ki.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ki = u_ki.real;
      offset += sizeof(this->ki);
      union {
        double real;
        uint64_t base;
      } u_alpha;
      u_alpha.base = 0;
      u_alpha.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alpha.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alpha.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alpha.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_alpha.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_alpha.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_alpha.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_alpha.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->alpha = u_alpha.real;
      offset += sizeof(this->alpha);
      union {
        double real;
        uint64_t base;
      } u_beta;
      u_beta.base = 0;
      u_beta.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_beta.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_beta.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_beta.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_beta.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_beta.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_beta.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_beta.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->beta = u_beta.real;
      offset += sizeof(this->beta);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_torqueControllerParam"; };
    const char * getMD5(){ return "418bfbbaca8a066928344703def43b7f"; };

  };

}
#endif