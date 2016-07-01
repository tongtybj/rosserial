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
      uint8_t data_length;
      pal_wifi_localization_msgs::WifiSignalList st_data;
      pal_wifi_localization_msgs::WifiSignalList * data;

    WifiSignalMap():
      header(),
      info(),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
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
    const char * getMD5(){ return "6971f6eed5e5f1234bdfa8a5e5b21656"; };

  };

}
#endif