#ifndef _ROS_SERVICE_GetWifiMap_h
#define _ROS_SERVICE_GetWifiMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "pal_wifi_localization_msgs/WifiSignalMap.h"

namespace pal_wifi_localization_msgs
{

static const char GETWIFIMAP[] = "pal_wifi_localization_msgs/GetWifiMap";

  class GetWifiMapRequest : public ros::Msg
  {
    public:

    GetWifiMapRequest()
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

    const char * getType(){ return GETWIFIMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetWifiMapResponse : public ros::Msg
  {
    public:
      pal_wifi_localization_msgs::WifiSignalMap map;

    GetWifiMapResponse():
      map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETWIFIMAP; };
    const char * getMD5(){ return "761434c3d8e8d6d04487955bd5e9d612"; };

  };

  class GetWifiMap {
    public:
    typedef GetWifiMapRequest Request;
    typedef GetWifiMapResponse Response;
  };

}
#endif
