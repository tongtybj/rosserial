#ifndef _ROS_drc_com_common_FC2OCSSmall_h
#define _ROS_drc_com_common_FC2OCSSmall_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_com_common
{

  class FC2OCSSmall : public ros::Msg
  {
    public:
      uint8_t type;
      uint8_t seq;
      int32_t int_params[21];
      float params[50];
      bool success;
      enum { REPORT = 0 };
      enum { GO_POS_POSE = 1 };
      enum { GO_POS_FINISHED = 2 };
      enum { LOOK_AT_FINISHED = 4 };
      enum { VALVE_POSE = 5 };
      enum { VALVE_FINISHED = 6 };
      enum { DOOR_POSE = 7 };
      enum { DOOR_FINISHED = 8 };
      enum { DEBRI_POSE = 9 };
      enum { DEBRI_FINISHED = 10 };
      enum { HOSE_GRASP_POSE = 11 };
      enum { HOSE_GRASP_FINISHED = 12 };
      enum { HOSE_CONNECT_POSE = 13 };
      enum { HOSE_CONNECT_FINISHED = 14 };
      enum { LOOK_AROUND_FINISHED = 15 };
      enum { DRILL_GRASP_POSE = 16 };
      enum { DRILL_GRASP_FINISHED = 17 };
      enum { DRILL_PUT_POSE = 18 };
      enum { DRILL_PUT_FINISHED = 19 };
      enum { DRILL_WALL_POSE = 21 };
      enum { DRILL_WALL_FINISHED = 22 };
      enum { DRILL_BUTTON_POSE = 23 };
      enum { DRILL_BUTTON_FINISHED = 24 };
      enum { DRILL_ROTATE_POSE = 25 };
      enum { DRILL_ROTATE_FINISHED = 26 };
      enum { ANGLE_VECTOR_FINISHED = 27 };
      enum { RVIZ_MENU_FINISHED = 28 };
      enum { REACH_UNTIL_TOUCH_FINISHED = 29 };
      enum { RECOGNITION_FAILED = 20 };
      enum { PROJECTED_FOOTSTEP = 30 };
      enum { LOOK_GROUND_FINISHED = 31 };
      enum { EXECUTE_FOOTSTEPS_FINISHED = 32 };
      enum { FOOTSTEP_PLANNING_RESULT = 33 };
      enum { FOOTSTEP_PLANNING_FAILED = 34 };

    FC2OCSSmall():
      type(0),
      seq(0),
      int_params(),
      params(),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->seq >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seq);
      for( uint8_t i = 0; i < 21; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_int_paramsi;
      u_int_paramsi.real = this->int_params[i];
      *(outbuffer + offset + 0) = (u_int_paramsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_int_paramsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_int_paramsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_int_paramsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->int_params[i]);
      }
      for( uint8_t i = 0; i < 50; i++){
      union {
        float real;
        uint32_t base;
      } u_paramsi;
      u_paramsi.real = this->params[i];
      *(outbuffer + offset + 0) = (u_paramsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_paramsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_paramsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_paramsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->params[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->seq =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->seq);
      for( uint8_t i = 0; i < 21; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_int_paramsi;
      u_int_paramsi.base = 0;
      u_int_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_int_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_int_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_int_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->int_params[i] = u_int_paramsi.real;
      offset += sizeof(this->int_params[i]);
      }
      for( uint8_t i = 0; i < 50; i++){
      union {
        float real;
        uint32_t base;
      } u_paramsi;
      u_paramsi.base = 0;
      u_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->params[i] = u_paramsi.real;
      offset += sizeof(this->params[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return "drc_com_common/FC2OCSSmall"; };
    const char * getMD5(){ return "58c832cf93d3845374b0694949f65efd"; };

  };

}
#endif