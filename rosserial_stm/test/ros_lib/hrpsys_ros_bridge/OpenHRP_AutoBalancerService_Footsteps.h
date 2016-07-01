#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_Footsteps_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_Footsteps_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footstep.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_Footsteps : public ros::Msg
  {
    public:
      uint8_t fs_length;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep st_fs;
      hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep * fs;

    OpenHRP_AutoBalancerService_Footsteps():
      fs_length(0), fs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = fs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < fs_length; i++){
      offset += this->fs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t fs_lengthT = *(inbuffer + offset++);
      if(fs_lengthT > fs_length)
        this->fs = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep*)realloc(this->fs, fs_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      offset += 3;
      fs_length = fs_lengthT;
      for( uint8_t i = 0; i < fs_length; i++){
      offset += this->st_fs.deserialize(inbuffer + offset);
        memcpy( &(this->fs[i]), &(this->st_fs), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footstep));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footsteps"; };
    const char * getMD5(){ return "f85957b17cc08a30bbfab3dc61b1d556"; };

  };

}
#endif