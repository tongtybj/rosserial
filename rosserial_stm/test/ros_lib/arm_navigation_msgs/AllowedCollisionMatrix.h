#ifndef _ROS_arm_navigation_msgs_AllowedCollisionMatrix_h
#define _ROS_arm_navigation_msgs_AllowedCollisionMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/AllowedCollisionEntry.h"

namespace arm_navigation_msgs
{

  class AllowedCollisionMatrix : public ros::Msg
  {
    public:
      uint8_t link_names_length;
      char* st_link_names;
      char* * link_names;
      uint8_t entries_length;
      arm_navigation_msgs::AllowedCollisionEntry st_entries;
      arm_navigation_msgs::AllowedCollisionEntry * entries;

    AllowedCollisionMatrix():
      link_names_length(0), link_names(NULL),
      entries_length(0), entries(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = link_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < link_names_length; i++){
      uint32_t length_link_namesi = strlen(this->link_names[i]);
      memcpy(outbuffer + offset, &length_link_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_names[i], length_link_namesi);
      offset += length_link_namesi;
      }
      *(outbuffer + offset++) = entries_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < entries_length; i++){
      offset += this->entries[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t link_names_lengthT = *(inbuffer + offset++);
      if(link_names_lengthT > link_names_length)
        this->link_names = (char**)realloc(this->link_names, link_names_lengthT * sizeof(char*));
      offset += 3;
      link_names_length = link_names_lengthT;
      for( uint8_t i = 0; i < link_names_length; i++){
      uint32_t length_st_link_names;
      memcpy(&length_st_link_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_link_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_link_names-1]=0;
      this->st_link_names = (char *)(inbuffer + offset-1);
      offset += length_st_link_names;
        memcpy( &(this->link_names[i]), &(this->st_link_names), sizeof(char*));
      }
      uint8_t entries_lengthT = *(inbuffer + offset++);
      if(entries_lengthT > entries_length)
        this->entries = (arm_navigation_msgs::AllowedCollisionEntry*)realloc(this->entries, entries_lengthT * sizeof(arm_navigation_msgs::AllowedCollisionEntry));
      offset += 3;
      entries_length = entries_lengthT;
      for( uint8_t i = 0; i < entries_length; i++){
      offset += this->st_entries.deserialize(inbuffer + offset);
        memcpy( &(this->entries[i]), &(this->st_entries), sizeof(arm_navigation_msgs::AllowedCollisionEntry));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/AllowedCollisionMatrix"; };
    const char * getMD5(){ return "c5785d58d2d0b6270738f65222dbec5d"; };

  };

}
#endif