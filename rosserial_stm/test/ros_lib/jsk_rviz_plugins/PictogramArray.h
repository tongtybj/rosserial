#ifndef _ROS_jsk_rviz_plugins_PictogramArray_h
#define _ROS_jsk_rviz_plugins_PictogramArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_rviz_plugins/Pictogram.h"

namespace jsk_rviz_plugins
{

  class PictogramArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t pictograms_length;
      jsk_rviz_plugins::Pictogram st_pictograms;
      jsk_rviz_plugins::Pictogram * pictograms;

    PictogramArray():
      header(),
      pictograms_length(0), pictograms(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = pictograms_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < pictograms_length; i++){
      offset += this->pictograms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t pictograms_lengthT = *(inbuffer + offset++);
      if(pictograms_lengthT > pictograms_length)
        this->pictograms = (jsk_rviz_plugins::Pictogram*)realloc(this->pictograms, pictograms_lengthT * sizeof(jsk_rviz_plugins::Pictogram));
      offset += 3;
      pictograms_length = pictograms_lengthT;
      for( uint8_t i = 0; i < pictograms_length; i++){
      offset += this->st_pictograms.deserialize(inbuffer + offset);
        memcpy( &(this->pictograms[i]), &(this->st_pictograms), sizeof(jsk_rviz_plugins::Pictogram));
      }
     return offset;
    }

    const char * getType(){ return "jsk_rviz_plugins/PictogramArray"; };
    const char * getMD5(){ return "bfdafbfcdf121aed91dae673b47ae3fe"; };

  };

}
#endif