#ifndef _ROS_contact_states_observer_GraspReferenceData_h
#define _ROS_contact_states_observer_GraspReferenceData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace contact_states_observer
{

  class GraspReferenceData : public ros::Msg
  {
    public:
      const char* name;
      uint8_t av_length;
      double st_av;
      double * av;

    GraspReferenceData():
      name(""),
      av_length(0), av(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset++) = av_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < av_length; i++){
      union {
        double real;
        uint64_t base;
      } u_avi;
      u_avi.real = this->av[i];
      *(outbuffer + offset + 0) = (u_avi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_avi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_avi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_avi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_avi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_avi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_avi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_avi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->av[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint8_t av_lengthT = *(inbuffer + offset++);
      if(av_lengthT > av_length)
        this->av = (double*)realloc(this->av, av_lengthT * sizeof(double));
      offset += 3;
      av_length = av_lengthT;
      for( uint8_t i = 0; i < av_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_av;
      u_st_av.base = 0;
      u_st_av.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_av.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_av.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_av.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_av.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_av.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_av.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_av.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_av = u_st_av.real;
      offset += sizeof(this->st_av);
        memcpy( &(this->av[i]), &(this->st_av), sizeof(double));
      }
     return offset;
    }

    const char * getType(){ return "contact_states_observer/GraspReferenceData"; };
    const char * getMD5(){ return "42ebda9900cd534e5ac93b2d87081425"; };

  };

}
#endif