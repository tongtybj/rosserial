#ifndef _ROS_SERVICE_SafetyZone_h
#define _ROS_SERVICE_SafetyZone_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pal_navigation_msgs
{

static const char SAFETYZONE[] = "pal_navigation_msgs/SafetyZone";

  class SafetyZoneRequest : public ros::Msg
  {
    public:
      double distance;
      double leftAngleRad;
      double rightAngleRad;
      uint32_t sensorMask;
      enum { NO_SENSORS =  0 };
      enum { ALL_SENSORS =  127 };
      enum { FRONT_SONARS =  1 };
      enum { LEFT_SONARS =  2 };
      enum { RIGHT_SONARS =  4 };
      enum { BACK_SONARS =  8 };
      enum { TORSO_SONARS =  16 };
      enum { ONLY_SONARS =  31 };
      enum { BASE_LASER =  32 };
      enum { TORSO_LASER =  64 };
      enum { ONLY_LASERS =  96 };

    SafetyZoneRequest():
      distance(0),
      leftAngleRad(0),
      rightAngleRad(0),
      sensorMask(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_distance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_distance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_distance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_distance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->distance);
      union {
        double real;
        uint64_t base;
      } u_leftAngleRad;
      u_leftAngleRad.real = this->leftAngleRad;
      *(outbuffer + offset + 0) = (u_leftAngleRad.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftAngleRad.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftAngleRad.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftAngleRad.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_leftAngleRad.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_leftAngleRad.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_leftAngleRad.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_leftAngleRad.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->leftAngleRad);
      union {
        double real;
        uint64_t base;
      } u_rightAngleRad;
      u_rightAngleRad.real = this->rightAngleRad;
      *(outbuffer + offset + 0) = (u_rightAngleRad.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightAngleRad.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightAngleRad.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightAngleRad.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rightAngleRad.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rightAngleRad.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rightAngleRad.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rightAngleRad.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rightAngleRad);
      *(outbuffer + offset + 0) = (this->sensorMask >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensorMask >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensorMask >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensorMask >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensorMask);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_distance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
      union {
        double real;
        uint64_t base;
      } u_leftAngleRad;
      u_leftAngleRad.base = 0;
      u_leftAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_leftAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_leftAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_leftAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_leftAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->leftAngleRad = u_leftAngleRad.real;
      offset += sizeof(this->leftAngleRad);
      union {
        double real;
        uint64_t base;
      } u_rightAngleRad;
      u_rightAngleRad.base = 0;
      u_rightAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rightAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rightAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rightAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rightAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rightAngleRad = u_rightAngleRad.real;
      offset += sizeof(this->rightAngleRad);
      this->sensorMask =  ((uint32_t) (*(inbuffer + offset)));
      this->sensorMask |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sensorMask |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sensorMask |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sensorMask);
     return offset;
    }

    const char * getType(){ return SAFETYZONE; };
    const char * getMD5(){ return "269cbb74525b0bd07e71e2ec943affd4"; };

  };

  class SafetyZoneResponse : public ros::Msg
  {
    public:
      bool leftSafe;
      double leftMinDist;
      double leftMinDistAngleRad;
      bool rightSafe;
      double rightMinDist;
      double rightMinDistAngleRad;

    SafetyZoneResponse():
      leftSafe(0),
      leftMinDist(0),
      leftMinDistAngleRad(0),
      rightSafe(0),
      rightMinDist(0),
      rightMinDistAngleRad(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_leftSafe;
      u_leftSafe.real = this->leftSafe;
      *(outbuffer + offset + 0) = (u_leftSafe.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->leftSafe);
      union {
        double real;
        uint64_t base;
      } u_leftMinDist;
      u_leftMinDist.real = this->leftMinDist;
      *(outbuffer + offset + 0) = (u_leftMinDist.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftMinDist.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftMinDist.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftMinDist.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_leftMinDist.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_leftMinDist.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_leftMinDist.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_leftMinDist.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->leftMinDist);
      union {
        double real;
        uint64_t base;
      } u_leftMinDistAngleRad;
      u_leftMinDistAngleRad.real = this->leftMinDistAngleRad;
      *(outbuffer + offset + 0) = (u_leftMinDistAngleRad.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_leftMinDistAngleRad.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_leftMinDistAngleRad.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_leftMinDistAngleRad.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_leftMinDistAngleRad.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_leftMinDistAngleRad.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_leftMinDistAngleRad.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_leftMinDistAngleRad.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->leftMinDistAngleRad);
      union {
        bool real;
        uint8_t base;
      } u_rightSafe;
      u_rightSafe.real = this->rightSafe;
      *(outbuffer + offset + 0) = (u_rightSafe.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rightSafe);
      union {
        double real;
        uint64_t base;
      } u_rightMinDist;
      u_rightMinDist.real = this->rightMinDist;
      *(outbuffer + offset + 0) = (u_rightMinDist.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightMinDist.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightMinDist.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightMinDist.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rightMinDist.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rightMinDist.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rightMinDist.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rightMinDist.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rightMinDist);
      union {
        double real;
        uint64_t base;
      } u_rightMinDistAngleRad;
      u_rightMinDistAngleRad.real = this->rightMinDistAngleRad;
      *(outbuffer + offset + 0) = (u_rightMinDistAngleRad.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rightMinDistAngleRad.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rightMinDistAngleRad.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rightMinDistAngleRad.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rightMinDistAngleRad.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rightMinDistAngleRad.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rightMinDistAngleRad.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rightMinDistAngleRad.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rightMinDistAngleRad);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_leftSafe;
      u_leftSafe.base = 0;
      u_leftSafe.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->leftSafe = u_leftSafe.real;
      offset += sizeof(this->leftSafe);
      union {
        double real;
        uint64_t base;
      } u_leftMinDist;
      u_leftMinDist.base = 0;
      u_leftMinDist.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftMinDist.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftMinDist.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftMinDist.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_leftMinDist.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_leftMinDist.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_leftMinDist.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_leftMinDist.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->leftMinDist = u_leftMinDist.real;
      offset += sizeof(this->leftMinDist);
      union {
        double real;
        uint64_t base;
      } u_leftMinDistAngleRad;
      u_leftMinDistAngleRad.base = 0;
      u_leftMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_leftMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_leftMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_leftMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_leftMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_leftMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_leftMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_leftMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->leftMinDistAngleRad = u_leftMinDistAngleRad.real;
      offset += sizeof(this->leftMinDistAngleRad);
      union {
        bool real;
        uint8_t base;
      } u_rightSafe;
      u_rightSafe.base = 0;
      u_rightSafe.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rightSafe = u_rightSafe.real;
      offset += sizeof(this->rightSafe);
      union {
        double real;
        uint64_t base;
      } u_rightMinDist;
      u_rightMinDist.base = 0;
      u_rightMinDist.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightMinDist.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightMinDist.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightMinDist.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rightMinDist.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rightMinDist.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rightMinDist.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rightMinDist.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rightMinDist = u_rightMinDist.real;
      offset += sizeof(this->rightMinDist);
      union {
        double real;
        uint64_t base;
      } u_rightMinDistAngleRad;
      u_rightMinDistAngleRad.base = 0;
      u_rightMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rightMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rightMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rightMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rightMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rightMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rightMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rightMinDistAngleRad.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rightMinDistAngleRad = u_rightMinDistAngleRad.real;
      offset += sizeof(this->rightMinDistAngleRad);
     return offset;
    }

    const char * getType(){ return SAFETYZONE; };
    const char * getMD5(){ return "e2ae1feeb09d43547ad602b6e1dca6d7"; };

  };

  class SafetyZone {
    public:
    typedef SafetyZoneRequest Request;
    typedef SafetyZoneResponse Response;
  };

}
#endif
