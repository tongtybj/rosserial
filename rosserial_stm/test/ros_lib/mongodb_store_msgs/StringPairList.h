#ifndef _ROS_mongodb_store_msgs_StringPairList_h
#define _ROS_mongodb_store_msgs_StringPairList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "mongodb_store_msgs/StringPair.h"

namespace mongodb_store_msgs
{

  class StringPairList : public ros::Msg
  {
    public:
      uint8_t pairs_length;
      mongodb_store_msgs::StringPair st_pairs;
      mongodb_store_msgs::StringPair * pairs;

    StringPairList():
      pairs_length(0), pairs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = pairs_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pairs_length; i++){
      offset += this->pairs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t pairs_lengthT = *(inbuffer + offset++);
      if(pairs_lengthT > pairs_length)
        this->pairs = (mongodb_store_msgs::StringPair*)realloc(this->pairs, pairs_lengthT * sizeof(mongodb_store_msgs::StringPair));
      offset += 3;
      pairs_length = pairs_lengthT;
      for( uint8_t i = 0; i < pairs_length; i++){
      offset += this->st_pairs.deserialize(inbuffer + offset);
        memcpy( &(this->pairs[i]), &(this->st_pairs), sizeof(mongodb_store_msgs::StringPair));
      }
     return offset;
    }

    const char * getType(){ return "mongodb_store_msgs/StringPairList"; };
    const char * getMD5(){ return "50c368c0f345d8de86876a3bada40aad"; };

  };

}
#endif