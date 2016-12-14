#ifndef _ROS_SERVICE_SolvePositionIK_h
#define _ROS_SERVICE_SolvePositionIK_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "sensor_msgs/JointState.h"

namespace baxter_core_msgs
{

static const char SOLVEPOSITIONIK[] = "baxter_core_msgs/SolvePositionIK";

  class SolvePositionIKRequest : public ros::Msg
  {
    public:
      uint8_t pose_stamp_length;
      geometry_msgs::PoseStamped st_pose_stamp;
      geometry_msgs::PoseStamped * pose_stamp;
      uint8_t seed_angles_length;
      sensor_msgs::JointState st_seed_angles;
      sensor_msgs::JointState * seed_angles;
      uint8_t seed_mode;
      enum { SEED_AUTO =  0 };
      enum { SEED_USER =  1 };
      enum { SEED_CURRENT =  2 };
      enum { SEED_NS_MAP =  3 };

    SolvePositionIKRequest():
      pose_stamp_length(0), pose_stamp(NULL),
      seed_angles_length(0), seed_angles(NULL),
      seed_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = pose_stamp_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pose_stamp_length; i++){
      offset += this->pose_stamp[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = seed_angles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < seed_angles_length; i++){
      offset += this->seed_angles[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->seed_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seed_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t pose_stamp_lengthT = *(inbuffer + offset++);
      if(pose_stamp_lengthT > pose_stamp_length)
        this->pose_stamp = (geometry_msgs::PoseStamped*)realloc(this->pose_stamp, pose_stamp_lengthT * sizeof(geometry_msgs::PoseStamped));
      offset += 3;
      pose_stamp_length = pose_stamp_lengthT;
      for( uint8_t i = 0; i < pose_stamp_length; i++){
      offset += this->st_pose_stamp.deserialize(inbuffer + offset);
        memcpy( &(this->pose_stamp[i]), &(this->st_pose_stamp), sizeof(geometry_msgs::PoseStamped));
      }
      uint8_t seed_angles_lengthT = *(inbuffer + offset++);
      if(seed_angles_lengthT > seed_angles_length)
        this->seed_angles = (sensor_msgs::JointState*)realloc(this->seed_angles, seed_angles_lengthT * sizeof(sensor_msgs::JointState));
      offset += 3;
      seed_angles_length = seed_angles_lengthT;
      for( uint8_t i = 0; i < seed_angles_length; i++){
      offset += this->st_seed_angles.deserialize(inbuffer + offset);
        memcpy( &(this->seed_angles[i]), &(this->st_seed_angles), sizeof(sensor_msgs::JointState));
      }
      this->seed_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->seed_mode);
     return offset;
    }

    const char * getType(){ return SOLVEPOSITIONIK; };
    const char * getMD5(){ return "2587e42983d0081d0a2288230991073b"; };

  };

  class SolvePositionIKResponse : public ros::Msg
  {
    public:
      uint8_t joints_length;
      sensor_msgs::JointState st_joints;
      sensor_msgs::JointState * joints;
      uint8_t isValid_length;
      bool st_isValid;
      bool * isValid;
      uint8_t result_type_length;
      uint8_t st_result_type;
      uint8_t * result_type;
      enum { RESULT_INVALID =  0 };

    SolvePositionIKResponse():
      joints_length(0), joints(NULL),
      isValid_length(0), isValid(NULL),
      result_type_length(0), result_type(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = joints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joints_length; i++){
      offset += this->joints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = isValid_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < isValid_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_isValidi;
      u_isValidi.real = this->isValid[i];
      *(outbuffer + offset + 0) = (u_isValidi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->isValid[i]);
      }
      *(outbuffer + offset++) = result_type_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < result_type_length; i++){
      *(outbuffer + offset + 0) = (this->result_type[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result_type[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t joints_lengthT = *(inbuffer + offset++);
      if(joints_lengthT > joints_length)
        this->joints = (sensor_msgs::JointState*)realloc(this->joints, joints_lengthT * sizeof(sensor_msgs::JointState));
      offset += 3;
      joints_length = joints_lengthT;
      for( uint8_t i = 0; i < joints_length; i++){
      offset += this->st_joints.deserialize(inbuffer + offset);
        memcpy( &(this->joints[i]), &(this->st_joints), sizeof(sensor_msgs::JointState));
      }
      uint8_t isValid_lengthT = *(inbuffer + offset++);
      if(isValid_lengthT > isValid_length)
        this->isValid = (bool*)realloc(this->isValid, isValid_lengthT * sizeof(bool));
      offset += 3;
      isValid_length = isValid_lengthT;
      for( uint8_t i = 0; i < isValid_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_isValid;
      u_st_isValid.base = 0;
      u_st_isValid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_isValid = u_st_isValid.real;
      offset += sizeof(this->st_isValid);
        memcpy( &(this->isValid[i]), &(this->st_isValid), sizeof(bool));
      }
      uint8_t result_type_lengthT = *(inbuffer + offset++);
      if(result_type_lengthT > result_type_length)
        this->result_type = (uint8_t*)realloc(this->result_type, result_type_lengthT * sizeof(uint8_t));
      offset += 3;
      result_type_length = result_type_lengthT;
      for( uint8_t i = 0; i < result_type_length; i++){
      this->st_result_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_result_type);
        memcpy( &(this->result_type[i]), &(this->st_result_type), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return SOLVEPOSITIONIK; };
    const char * getMD5(){ return "d9b0c2b3932e08421f5094cf62743b9f"; };

  };

  class SolvePositionIK {
    public:
    typedef SolvePositionIKRequest Request;
    typedef SolvePositionIKResponse Response;
  };

}
#endif
