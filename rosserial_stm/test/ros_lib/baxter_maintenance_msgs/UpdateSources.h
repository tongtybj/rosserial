#ifndef _ROS_baxter_maintenance_msgs_UpdateSources_h
#define _ROS_baxter_maintenance_msgs_UpdateSources_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "baxter_maintenance_msgs/UpdateSource.h"

namespace baxter_maintenance_msgs
{

  class UpdateSources : public ros::Msg
  {
    public:
      const char* uuid;
      uint8_t sources_length;
      baxter_maintenance_msgs::UpdateSource st_sources;
      baxter_maintenance_msgs::UpdateSource * sources;

    UpdateSources():
      uuid(""),
      sources_length(0), sources(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_uuid = strlen(this->uuid);
      memcpy(outbuffer + offset, &length_uuid, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->uuid, length_uuid);
      offset += length_uuid;
      *(outbuffer + offset++) = sources_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < sources_length; i++){
      offset += this->sources[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_uuid;
      memcpy(&length_uuid, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_uuid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_uuid-1]=0;
      this->uuid = (char *)(inbuffer + offset-1);
      offset += length_uuid;
      uint8_t sources_lengthT = *(inbuffer + offset++);
      if(sources_lengthT > sources_length)
        this->sources = (baxter_maintenance_msgs::UpdateSource*)realloc(this->sources, sources_lengthT * sizeof(baxter_maintenance_msgs::UpdateSource));
      offset += 3;
      sources_length = sources_lengthT;
      for( uint8_t i = 0; i < sources_length; i++){
      offset += this->st_sources.deserialize(inbuffer + offset);
        memcpy( &(this->sources[i]), &(this->st_sources), sizeof(baxter_maintenance_msgs::UpdateSource));
      }
     return offset;
    }

    const char * getType(){ return "baxter_maintenance_msgs/UpdateSources"; };
    const char * getMD5(){ return "b3b428bf55e80e83d378830c33b3405b"; };

  };

}
#endif