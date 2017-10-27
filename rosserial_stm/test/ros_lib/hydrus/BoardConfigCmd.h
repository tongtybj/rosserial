#ifndef _ROS_hydrus_BoardConfigCmd_h
#define _ROS_hydrus_BoardConfigCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrus
{

  class BoardConfigCmd : public ros::Msg
  {
    public:
      uint8_t command;
      uint8_t data_length;
      int32_t st_data;
      int32_t * data;
      enum { SET_SLAVE_ID =  0 };
      enum { SET_IMU_SEND_FLAG =  1 };
      enum { SET_SERVO_HOMING_OFFSET =  2 };
      enum { SET_SERVO_PID_GAIN =  3 };
      enum { SET_SERVO_PROFILE_VEL =  4 };
      enum { SET_SERVO_SEND_DATA_FLAG =  5 };
      enum { SET_SERVO_CURRENT_LIMIT =  6 };

    BoardConfigCmd():
      command(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_datai;
      u_datai.real = this->data[i];
      *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_datai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_datai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_datai.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (int32_t*)realloc(this->data, data_lengthT * sizeof(int32_t));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_data;
      u_st_data.base = 0;
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_data = u_st_data.real;
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return "hydrus/BoardConfigCmd"; };
    const char * getMD5(){ return "b5313f812a584f4df9ec17f233188f3f"; };

  };

}
#endif