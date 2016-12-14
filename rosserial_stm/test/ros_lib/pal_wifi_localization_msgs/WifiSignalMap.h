#ifndef _ROS_pal_wifi_localization_msgs_WifiSignalMap_h
#define _ROS_pal_wifi_localization_msgs_WifiSignalMap_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nav_msgs/MapMetaData.h"
#include "pal_wifi_localization_msgs/WifiSignalList.h"

namespace pal_wifi_localization_msgs
{

  class WifiSignalMap : public ros::Msg
  {
    public:
      std_msgs::Header header;
      nav_msgs::MapMetaData info;
      uint32_t sectors;
      uint8_t data_length;
      pal_wifi_localization_msgs::WifiSignalList st_data;
      pal_wifi_localization_msgs::WifiSignalList * data;

    WifiSignalMap():
      header(),
      info(),
      sectors(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->sectors >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sectors >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sectors >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sectors >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sectors);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->info.deserialize(inbuffer + offset);
      this->sectors =  ((uint32_t) (*(inbuffer + offset)));
      this->sectors |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sectors |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sectors |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sectors);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (pal_wifi_localization_msgs::WifiSignalList*)realloc(this->data, data_lengthT * sizeof(pal_wifi_localization_msgs::WifiSignalList));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(pal_wifi_localization_msgs::WifiSignalList));
      }
     return offset;
    }

    const char * getType(){ return "pal_wifi_localization_msgs/WifiSignalMap"; };
    const char * getMD5(){ return "5083f884f6a479bea709736f39c4131f"; };

  };

}
#endif