#ifndef _ROS_drc_com_common_OCS2FCSmall_h
#define _ROS_drc_com_common_OCS2FCSmall_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drc_com_common
{

  class OCS2FCSmall : public ros::Msg
  {
    public:
      uint8_t type;
      uint8_t seq;
      uint8_t image_type;
      uint8_t arm_side;
      uint32_t image_roi_info[21];
      float float_params[128];
      float stand_coords[6];
      enum { IMAGE_RECT = 0 };
      enum { PANORAMA_VIEW = 1 };
      enum { UNDECIDED = 0 };
      enum { LARM = 1 };
      enum { RARM = 2 };
      enum { VALVE_CENTER_GRASP = 1 };
      enum { VALVE_EDGE_GRASP = 2 };
      enum { DOOR_PUSH = 1 };
      enum { DOOR_PULL = 2 };
      enum { DOOR_DRC_BOX2 = 1 };
      enum { DOOR_DRC_TEST = 2 };
      enum { DOOR_DRC_TEST_MIRROR = 3 };
      enum { DOOR_DRC_SAGAMI = 4 };
      enum { DOOR_DRC_SAGAMI_MIRROR = 5 };
      enum { DOOR_DRC_LASVEGAS = 6 };
      enum { DOOR_DRC_LASVEGAS_MIRROR = 7 };
      enum { GO_POS_REGION = 1 };
      enum { GO_POS_EXEC = 2 };
      enum { LOOK_AT_REGION = 3 };
      enum { VALVE_REGION = 5 };
      enum { VALVE_EXEC = 6 };
      enum { DOOR_REGION = 7 };
      enum { DOOR_EXEC = 8 };
      enum { DEBRI_LINE = 9 };
      enum { DEBRI_EXEC = 10 };
      enum { HOSE_GRASP_REGION = 11 };
      enum { HOSE_GRASP_EXEC = 12 };
      enum { HOSE_CONNECT_REGION = 13 };
      enum { HOSE_CONNECT_EXEC = 14 };
      enum { LOOK_AROUND_EXEC = 15 };
      enum { DRILL_GRASP_REGION = 16 };
      enum { DRILL_GRASP_EXEC = 17 };
      enum { DRILL_PUT_REGION = 18 };
      enum { DRILL_PUT_EXEC = 19 };
      enum { DRILL_WALL_POINTS = 20 };
      enum { DRILL_WALL_EXEC = 21 };
      enum { DRILL_BUTTON_REGION = 22 };
      enum { DRILL_BUTTON_EXEC = 23 };
      enum { DRILL_ROTATE_REGION = 24 };
      enum { DRILL_ROTATE_EXEC = 25 };
      enum { RESET_POSE = 26 };
      enum { RESET_MANIP_POSE = 27 };
      enum { HAND_RESET_POSE = 28 };
      enum { HAND_HOOK_POSE = 29 };
      enum { HAND_HOOK_AFTER_POSE = 30  };
      enum { HAND_GRASP_POSE = 31 };
      enum { HRPSYS_START_ABC = 32 };
      enum { HRPSYS_START_ST = 33 };
      enum { HRPSYS_START_IMP = 34 };
      enum { HRPSYS_START_IMP_SOFT = 49 };
      enum { HRPSYS_START_IMP_HARD = 50 };
      enum { HRPSYS_STOP_ABC = 35 };
      enum { HRPSYS_STOP_ST = 36 };
      enum { HRPSYS_STOP_IMP = 37 };
      enum { DRILL_RESET_POSE = 38 };
      enum { WATCH_DRILL_POSE = 39 };
      enum { DOOR_THROUGH_POSE = 40 };
      enum { CALIB_HAND = 51 };
      enum { ANGLE_VECTOR_SEND = 41 };
      enum { CANCEL_MOTION_NOW = 42 };
      enum { DRIVE_COMMAND = 43 };
      enum { ENABLE_OVERWRITE_HEAD_JOINT = 44 };
      enum { DISABLE_OVERWRITE_HEAD_JOINT = 45 };
      enum { LOOK_AT_PITCH_ANGLE = 46 };
      enum { LOOK_AT_YAW_ANGLE = 47 };
      enum { REACH_UNTIL_TOUCH_EXEC = 48 };
      enum { MOVE_TO_STAIR_POSE = 52 };
      enum { STAIR_FOOTSTEPS = 53 };
      enum { EXECUTE_STAIR_FOOTSTEPS = 54 };
      enum { RLEG = 55 };
      enum { LLEG = 56 };
      enum { START_IMP = 57 };
      enum { STOP_IMP = 58 };
      enum { START_IMP_WITH_PARAM = 59 };
      enum { START_GRASP = 60 };
      enum { STOP_GRASP = 61 };
      enum { PROJECT_FOOTPRINT = 62 };
      enum { EXECUTE_FOOTSTEPS = 63 };
      enum { LOOK_GROUND = 64 };
      enum { HRPSYS_RESET_FORCE_OFFSET = 66 };
      enum { REF_FORCE_ZERO = 67 };
      enum { GO_POS_ZERO = 68 };
      enum { FINISH_STAIR_POSE = 69 };
      enum { RESET_ENC_OFFSET = 70 };
      enum { DRILL_THROW = 71 };
      enum { SIMPLE_FOOTSTEP_EXEC = 72 };
      enum { EMERGENCY_POSE = 73 };

    OCS2FCSmall():
      type(0),
      seq(0),
      image_type(0),
      arm_side(0),
      image_roi_info(),
      float_params(),
      stand_coords()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->seq >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seq);
      *(outbuffer + offset + 0) = (this->image_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->image_type);
      *(outbuffer + offset + 0) = (this->arm_side >> (8 * 0)) & 0xFF;
      offset += sizeof(this->arm_side);
      for( uint8_t i = 0; i < 21; i++){
      *(outbuffer + offset + 0) = (this->image_roi_info[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->image_roi_info[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->image_roi_info[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->image_roi_info[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->image_roi_info[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      union {
        float real;
        uint32_t base;
      } u_float_paramsi;
      u_float_paramsi.real = this->float_params[i];
      *(outbuffer + offset + 0) = (u_float_paramsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_float_paramsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_float_paramsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_float_paramsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->float_params[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_stand_coordsi;
      u_stand_coordsi.real = this->stand_coords[i];
      *(outbuffer + offset + 0) = (u_stand_coordsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stand_coordsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stand_coordsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stand_coordsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stand_coords[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->seq =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->seq);
      this->image_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->image_type);
      this->arm_side =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->arm_side);
      for( uint8_t i = 0; i < 21; i++){
      this->image_roi_info[i] =  ((uint32_t) (*(inbuffer + offset)));
      this->image_roi_info[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->image_roi_info[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->image_roi_info[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->image_roi_info[i]);
      }
      for( uint8_t i = 0; i < 128; i++){
      union {
        float real;
        uint32_t base;
      } u_float_paramsi;
      u_float_paramsi.base = 0;
      u_float_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_float_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_float_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_float_paramsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->float_params[i] = u_float_paramsi.real;
      offset += sizeof(this->float_params[i]);
      }
      for( uint8_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_stand_coordsi;
      u_stand_coordsi.base = 0;
      u_stand_coordsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stand_coordsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stand_coordsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stand_coordsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stand_coords[i] = u_stand_coordsi.real;
      offset += sizeof(this->stand_coords[i]);
      }
     return offset;
    }

    const char * getType(){ return "drc_com_common/OCS2FCSmall"; };
    const char * getMD5(){ return "e36cae653e27321e3c9b87784af4c6da"; };

  };

}
#endif