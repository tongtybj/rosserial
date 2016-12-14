#ifndef _ROS_pal_navigation_msgs_EulerAngles_h
#define _ROS_pal_navigation_msgs_EulerAngles_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

  class EulerAngles : public ros::Msg
  {
    public:
      const char* sequence;
      bool angles_in_degrees;
      double ai;
      double aj;
      double ak;

    EulerAngles():
      sequence(""),
      angles_in_degrees(0),
      ai(0),
      aj(0),
      ak(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_sequence = strlen(this->sequence);
      memcpy(outbuffer + offset, &length_sequence, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->sequence, length_sequence);
      offset += length_sequence;
      union {
        bool real;
        uint8_t base;
      } u_angles_in_degrees;
      u_angles_in_degrees.real = this->angles_in_degrees;
      *(outbuffer + offset + 0) = (u_angles_in_degrees.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->angles_in_degrees);
      union {
        double real;
        uint64_t base;
      } u_ai;
      u_ai.real = this->ai;
      *(outbuffer + offset + 0) = (u_ai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ai.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ai.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ai.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ai.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ai.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ai);
      union {
        double real;
        uint64_t base;
      } u_aj;
      u_aj.real = this->aj;
      *(outbuffer + offset + 0) = (u_aj.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_aj.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_aj.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_aj.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_aj.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_aj.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_aj.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_aj.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->aj);
      union {
        double real;
        uint64_t base;
      } u_ak;
      u_ak.real = this->ak;
      *(outbuffer + offset + 0) = (u_ak.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ak.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ak.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ak.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ak.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ak.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ak.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ak.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ak);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_sequence;
      memcpy(&length_sequence, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sequence; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sequence-1]=0;
      this->sequence = (char *)(inbuffer + offset-1);
      offset += length_sequence;
      union {
        bool real;
        uint8_t base;
      } u_angles_in_degrees;
      u_angles_in_degrees.base = 0;
      u_angles_in_degrees.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->angles_in_degrees = u_angles_in_degrees.real;
      offset += sizeof(this->angles_in_degrees);
      union {
        double real;
        uint64_t base;
      } u_ai;
      u_ai.base = 0;
      u_ai.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ai.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ai.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ai.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ai.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ai.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ai.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ai.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ai = u_ai.real;
      offset += sizeof(this->ai);
      union {
        double real;
        uint64_t base;
      } u_aj;
      u_aj.base = 0;
      u_aj.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_aj.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_aj.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_aj.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_aj.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_aj.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_aj.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_aj.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->aj = u_aj.real;
      offset += sizeof(this->aj);
      union {
        double real;
        uint64_t base;
      } u_ak;
      u_ak.base = 0;
      u_ak.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ak.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ak.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ak.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_ak.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_ak.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_ak.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_ak.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->ak = u_ak.real;
      offset += sizeof(this->ak);
     return offset;
    }

    const char * getType(){ return "pal_navigation_msgs/EulerAngles"; };
    const char * getMD5(){ return "b41bea25ef0825fa6d2799746a51460f"; };

  };

}
#endif