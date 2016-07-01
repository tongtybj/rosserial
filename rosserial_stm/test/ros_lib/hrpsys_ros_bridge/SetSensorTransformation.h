#ifndef _ROS_SERVICE_SetSensorTransformation_h
#define _ROS_SERVICE_SetSensorTransformation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"

namespace hrpsys_ros_bridge
{

static const char SETSENSORTRANSFORMATION[] = "hrpsys_ros_bridge/SetSensorTransformation";

  class SetSensorTransformationRequest : public ros::Msg
  {
    public:
      const char* sensor_name;
      geometry_msgs::Transform transform;

    SetSensorTransformationRequest():
      sensor_name(""),
      transform()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_sensor_name = strlen(this->sensor_name);
      memcpy(outbuffer + offset, &length_sensor_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->sensor_name, length_sensor_name);
      offset += length_sensor_name;
      offset += this->transform.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_sensor_name;
      memcpy(&length_sensor_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sensor_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sensor_name-1]=0;
      this->sensor_name = (char *)(inbuffer + offset-1);
      offset += length_sensor_name;
      offset += this->transform.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SETSENSORTRANSFORMATION; };
    const char * getMD5(){ return "b3d733501ce08d744a516c35334de78e"; };

  };

  class SetSensorTransformationResponse : public ros::Msg
  {
    public:

    SetSensorTransformationResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETSENSORTRANSFORMATION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetSensorTransformation {
    public:
    typedef SetSensorTransformationRequest Request;
    typedef SetSensorTransformationResponse Response;
  };

}
#endif
