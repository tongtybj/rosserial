#ifndef _ROS_multisense_ros_DeviceInfo_h
#define _ROS_multisense_ros_DeviceInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multisense_ros
{

  class DeviceInfo : public ros::Msg
  {
    public:
      const char* deviceName;
      const char* buildDate;
      const char* serialNumber;
      uint32_t deviceRevision;
      uint32_t numberOfPcbs;
      uint8_t pcbSerialNumbers_length;
      uint32_t st_pcbSerialNumbers;
      uint32_t * pcbSerialNumbers;
      uint8_t pcbNames_length;
      char* st_pcbNames;
      char* * pcbNames;
      const char* imagerName;
      uint32_t imagerType;
      uint32_t imagerWidth;
      uint32_t imagerHeight;
      const char* lensName;
      uint32_t lensType;
      float nominalBaseline;
      float nominalFocalLength;
      float nominalRelativeAperture;
      uint32_t lightingType;
      uint32_t numberOfLights;
      const char* laserName;
      uint32_t laserType;
      const char* motorName;
      uint32_t motorType;
      float motorGearReduction;
      const char* apiBuildDate;
      uint16_t apiVersion;
      const char* firmwareBuildDate;
      uint16_t firmwareVersion;
      uint64_t bitstreamVersion;
      uint64_t bitstreamMagic;
      uint64_t fpgaDna;

    DeviceInfo():
      deviceName(""),
      buildDate(""),
      serialNumber(""),
      deviceRevision(0),
      numberOfPcbs(0),
      pcbSerialNumbers_length(0), pcbSerialNumbers(NULL),
      pcbNames_length(0), pcbNames(NULL),
      imagerName(""),
      imagerType(0),
      imagerWidth(0),
      imagerHeight(0),
      lensName(""),
      lensType(0),
      nominalBaseline(0),
      nominalFocalLength(0),
      nominalRelativeAperture(0),
      lightingType(0),
      numberOfLights(0),
      laserName(""),
      laserType(0),
      motorName(""),
      motorType(0),
      motorGearReduction(0),
      apiBuildDate(""),
      apiVersion(0),
      firmwareBuildDate(""),
      firmwareVersion(0),
      bitstreamVersion(0),
      bitstreamMagic(0),
      fpgaDna(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_deviceName = strlen(this->deviceName);
      memcpy(outbuffer + offset, &length_deviceName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->deviceName, length_deviceName);
      offset += length_deviceName;
      uint32_t length_buildDate = strlen(this->buildDate);
      memcpy(outbuffer + offset, &length_buildDate, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->buildDate, length_buildDate);
      offset += length_buildDate;
      uint32_t length_serialNumber = strlen(this->serialNumber);
      memcpy(outbuffer + offset, &length_serialNumber, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->serialNumber, length_serialNumber);
      offset += length_serialNumber;
      *(outbuffer + offset + 0) = (this->deviceRevision >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->deviceRevision >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->deviceRevision >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->deviceRevision >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deviceRevision);
      *(outbuffer + offset + 0) = (this->numberOfPcbs >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->numberOfPcbs >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->numberOfPcbs >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->numberOfPcbs >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numberOfPcbs);
      *(outbuffer + offset++) = pcbSerialNumbers_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pcbSerialNumbers_length; i++){
      *(outbuffer + offset + 0) = (this->pcbSerialNumbers[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pcbSerialNumbers[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pcbSerialNumbers[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pcbSerialNumbers[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pcbSerialNumbers[i]);
      }
      *(outbuffer + offset++) = pcbNames_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pcbNames_length; i++){
      uint32_t length_pcbNamesi = strlen(this->pcbNames[i]);
      memcpy(outbuffer + offset, &length_pcbNamesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->pcbNames[i], length_pcbNamesi);
      offset += length_pcbNamesi;
      }
      uint32_t length_imagerName = strlen(this->imagerName);
      memcpy(outbuffer + offset, &length_imagerName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->imagerName, length_imagerName);
      offset += length_imagerName;
      *(outbuffer + offset + 0) = (this->imagerType >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->imagerType >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->imagerType >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->imagerType >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imagerType);
      *(outbuffer + offset + 0) = (this->imagerWidth >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->imagerWidth >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->imagerWidth >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->imagerWidth >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imagerWidth);
      *(outbuffer + offset + 0) = (this->imagerHeight >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->imagerHeight >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->imagerHeight >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->imagerHeight >> (8 * 3)) & 0xFF;
      offset += sizeof(this->imagerHeight);
      uint32_t length_lensName = strlen(this->lensName);
      memcpy(outbuffer + offset, &length_lensName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->lensName, length_lensName);
      offset += length_lensName;
      *(outbuffer + offset + 0) = (this->lensType >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lensType >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lensType >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lensType >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lensType);
      union {
        float real;
        uint32_t base;
      } u_nominalBaseline;
      u_nominalBaseline.real = this->nominalBaseline;
      *(outbuffer + offset + 0) = (u_nominalBaseline.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nominalBaseline.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nominalBaseline.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nominalBaseline.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nominalBaseline);
      union {
        float real;
        uint32_t base;
      } u_nominalFocalLength;
      u_nominalFocalLength.real = this->nominalFocalLength;
      *(outbuffer + offset + 0) = (u_nominalFocalLength.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nominalFocalLength.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nominalFocalLength.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nominalFocalLength.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nominalFocalLength);
      union {
        float real;
        uint32_t base;
      } u_nominalRelativeAperture;
      u_nominalRelativeAperture.real = this->nominalRelativeAperture;
      *(outbuffer + offset + 0) = (u_nominalRelativeAperture.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nominalRelativeAperture.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nominalRelativeAperture.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nominalRelativeAperture.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nominalRelativeAperture);
      *(outbuffer + offset + 0) = (this->lightingType >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lightingType >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lightingType >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lightingType >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lightingType);
      *(outbuffer + offset + 0) = (this->numberOfLights >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->numberOfLights >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->numberOfLights >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->numberOfLights >> (8 * 3)) & 0xFF;
      offset += sizeof(this->numberOfLights);
      uint32_t length_laserName = strlen(this->laserName);
      memcpy(outbuffer + offset, &length_laserName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->laserName, length_laserName);
      offset += length_laserName;
      *(outbuffer + offset + 0) = (this->laserType >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->laserType >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->laserType >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->laserType >> (8 * 3)) & 0xFF;
      offset += sizeof(this->laserType);
      uint32_t length_motorName = strlen(this->motorName);
      memcpy(outbuffer + offset, &length_motorName, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->motorName, length_motorName);
      offset += length_motorName;
      *(outbuffer + offset + 0) = (this->motorType >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motorType >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motorType >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motorType >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motorType);
      union {
        float real;
        uint32_t base;
      } u_motorGearReduction;
      u_motorGearReduction.real = this->motorGearReduction;
      *(outbuffer + offset + 0) = (u_motorGearReduction.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motorGearReduction.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motorGearReduction.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motorGearReduction.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motorGearReduction);
      uint32_t length_apiBuildDate = strlen(this->apiBuildDate);
      memcpy(outbuffer + offset, &length_apiBuildDate, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->apiBuildDate, length_apiBuildDate);
      offset += length_apiBuildDate;
      *(outbuffer + offset + 0) = (this->apiVersion >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->apiVersion >> (8 * 1)) & 0xFF;
      offset += sizeof(this->apiVersion);
      uint32_t length_firmwareBuildDate = strlen(this->firmwareBuildDate);
      memcpy(outbuffer + offset, &length_firmwareBuildDate, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->firmwareBuildDate, length_firmwareBuildDate);
      offset += length_firmwareBuildDate;
      *(outbuffer + offset + 0) = (this->firmwareVersion >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->firmwareVersion >> (8 * 1)) & 0xFF;
      offset += sizeof(this->firmwareVersion);
      *(outbuffer + offset + 0) = (this->bitstreamVersion >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bitstreamVersion >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bitstreamVersion >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bitstreamVersion >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->bitstreamVersion >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->bitstreamVersion >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->bitstreamVersion >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->bitstreamVersion >> (8 * 7)) & 0xFF;
      offset += sizeof(this->bitstreamVersion);
      *(outbuffer + offset + 0) = (this->bitstreamMagic >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bitstreamMagic >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bitstreamMagic >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bitstreamMagic >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->bitstreamMagic >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->bitstreamMagic >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->bitstreamMagic >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->bitstreamMagic >> (8 * 7)) & 0xFF;
      offset += sizeof(this->bitstreamMagic);
      *(outbuffer + offset + 0) = (this->fpgaDna >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fpgaDna >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fpgaDna >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fpgaDna >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->fpgaDna >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->fpgaDna >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->fpgaDna >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->fpgaDna >> (8 * 7)) & 0xFF;
      offset += sizeof(this->fpgaDna);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_deviceName;
      memcpy(&length_deviceName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_deviceName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_deviceName-1]=0;
      this->deviceName = (char *)(inbuffer + offset-1);
      offset += length_deviceName;
      uint32_t length_buildDate;
      memcpy(&length_buildDate, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_buildDate; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_buildDate-1]=0;
      this->buildDate = (char *)(inbuffer + offset-1);
      offset += length_buildDate;
      uint32_t length_serialNumber;
      memcpy(&length_serialNumber, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serialNumber; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serialNumber-1]=0;
      this->serialNumber = (char *)(inbuffer + offset-1);
      offset += length_serialNumber;
      this->deviceRevision =  ((uint32_t) (*(inbuffer + offset)));
      this->deviceRevision |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->deviceRevision |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->deviceRevision |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->deviceRevision);
      this->numberOfPcbs =  ((uint32_t) (*(inbuffer + offset)));
      this->numberOfPcbs |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->numberOfPcbs |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->numberOfPcbs |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->numberOfPcbs);
      uint8_t pcbSerialNumbers_lengthT = *(inbuffer + offset++);
      if(pcbSerialNumbers_lengthT > pcbSerialNumbers_length)
        this->pcbSerialNumbers = (uint32_t*)realloc(this->pcbSerialNumbers, pcbSerialNumbers_lengthT * sizeof(uint32_t));
      offset += 3;
      pcbSerialNumbers_length = pcbSerialNumbers_lengthT;
      for( uint8_t i = 0; i < pcbSerialNumbers_length; i++){
      this->st_pcbSerialNumbers =  ((uint32_t) (*(inbuffer + offset)));
      this->st_pcbSerialNumbers |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_pcbSerialNumbers |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_pcbSerialNumbers |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_pcbSerialNumbers);
        memcpy( &(this->pcbSerialNumbers[i]), &(this->st_pcbSerialNumbers), sizeof(uint32_t));
      }
      uint8_t pcbNames_lengthT = *(inbuffer + offset++);
      if(pcbNames_lengthT > pcbNames_length)
        this->pcbNames = (char**)realloc(this->pcbNames, pcbNames_lengthT * sizeof(char*));
      offset += 3;
      pcbNames_length = pcbNames_lengthT;
      for( uint8_t i = 0; i < pcbNames_length; i++){
      uint32_t length_st_pcbNames;
      memcpy(&length_st_pcbNames, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_pcbNames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_pcbNames-1]=0;
      this->st_pcbNames = (char *)(inbuffer + offset-1);
      offset += length_st_pcbNames;
        memcpy( &(this->pcbNames[i]), &(this->st_pcbNames), sizeof(char*));
      }
      uint32_t length_imagerName;
      memcpy(&length_imagerName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_imagerName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_imagerName-1]=0;
      this->imagerName = (char *)(inbuffer + offset-1);
      offset += length_imagerName;
      this->imagerType =  ((uint32_t) (*(inbuffer + offset)));
      this->imagerType |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imagerType |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->imagerType |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->imagerType);
      this->imagerWidth =  ((uint32_t) (*(inbuffer + offset)));
      this->imagerWidth |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imagerWidth |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->imagerWidth |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->imagerWidth);
      this->imagerHeight =  ((uint32_t) (*(inbuffer + offset)));
      this->imagerHeight |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imagerHeight |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->imagerHeight |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->imagerHeight);
      uint32_t length_lensName;
      memcpy(&length_lensName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_lensName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_lensName-1]=0;
      this->lensName = (char *)(inbuffer + offset-1);
      offset += length_lensName;
      this->lensType =  ((uint32_t) (*(inbuffer + offset)));
      this->lensType |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lensType |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lensType |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lensType);
      union {
        float real;
        uint32_t base;
      } u_nominalBaseline;
      u_nominalBaseline.base = 0;
      u_nominalBaseline.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nominalBaseline.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nominalBaseline.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nominalBaseline.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nominalBaseline = u_nominalBaseline.real;
      offset += sizeof(this->nominalBaseline);
      union {
        float real;
        uint32_t base;
      } u_nominalFocalLength;
      u_nominalFocalLength.base = 0;
      u_nominalFocalLength.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nominalFocalLength.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nominalFocalLength.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nominalFocalLength.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nominalFocalLength = u_nominalFocalLength.real;
      offset += sizeof(this->nominalFocalLength);
      union {
        float real;
        uint32_t base;
      } u_nominalRelativeAperture;
      u_nominalRelativeAperture.base = 0;
      u_nominalRelativeAperture.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nominalRelativeAperture.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nominalRelativeAperture.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nominalRelativeAperture.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nominalRelativeAperture = u_nominalRelativeAperture.real;
      offset += sizeof(this->nominalRelativeAperture);
      this->lightingType =  ((uint32_t) (*(inbuffer + offset)));
      this->lightingType |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lightingType |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lightingType |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lightingType);
      this->numberOfLights =  ((uint32_t) (*(inbuffer + offset)));
      this->numberOfLights |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->numberOfLights |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->numberOfLights |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->numberOfLights);
      uint32_t length_laserName;
      memcpy(&length_laserName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_laserName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_laserName-1]=0;
      this->laserName = (char *)(inbuffer + offset-1);
      offset += length_laserName;
      this->laserType =  ((uint32_t) (*(inbuffer + offset)));
      this->laserType |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->laserType |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->laserType |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->laserType);
      uint32_t length_motorName;
      memcpy(&length_motorName, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_motorName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_motorName-1]=0;
      this->motorName = (char *)(inbuffer + offset-1);
      offset += length_motorName;
      this->motorType =  ((uint32_t) (*(inbuffer + offset)));
      this->motorType |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motorType |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->motorType |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->motorType);
      union {
        float real;
        uint32_t base;
      } u_motorGearReduction;
      u_motorGearReduction.base = 0;
      u_motorGearReduction.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motorGearReduction.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motorGearReduction.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motorGearReduction.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motorGearReduction = u_motorGearReduction.real;
      offset += sizeof(this->motorGearReduction);
      uint32_t length_apiBuildDate;
      memcpy(&length_apiBuildDate, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_apiBuildDate; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_apiBuildDate-1]=0;
      this->apiBuildDate = (char *)(inbuffer + offset-1);
      offset += length_apiBuildDate;
      this->apiVersion =  ((uint16_t) (*(inbuffer + offset)));
      this->apiVersion |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->apiVersion);
      uint32_t length_firmwareBuildDate;
      memcpy(&length_firmwareBuildDate, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmwareBuildDate; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmwareBuildDate-1]=0;
      this->firmwareBuildDate = (char *)(inbuffer + offset-1);
      offset += length_firmwareBuildDate;
      this->firmwareVersion =  ((uint16_t) (*(inbuffer + offset)));
      this->firmwareVersion |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->firmwareVersion);
      this->bitstreamVersion =  ((uint64_t) (*(inbuffer + offset)));
      this->bitstreamVersion |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->bitstreamVersion |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->bitstreamVersion |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bitstreamVersion |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->bitstreamVersion |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->bitstreamVersion |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->bitstreamVersion |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->bitstreamVersion);
      this->bitstreamMagic =  ((uint64_t) (*(inbuffer + offset)));
      this->bitstreamMagic |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->bitstreamMagic |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->bitstreamMagic |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bitstreamMagic |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->bitstreamMagic |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->bitstreamMagic |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->bitstreamMagic |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->bitstreamMagic);
      this->fpgaDna =  ((uint64_t) (*(inbuffer + offset)));
      this->fpgaDna |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->fpgaDna |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->fpgaDna |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fpgaDna |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->fpgaDna |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->fpgaDna |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->fpgaDna |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->fpgaDna);
     return offset;
    }

    const char * getType(){ return "multisense_ros/DeviceInfo"; };
    const char * getMD5(){ return "c6474ecff79a7f51e0a82ca43d0cf444"; };

  };

}
#endif