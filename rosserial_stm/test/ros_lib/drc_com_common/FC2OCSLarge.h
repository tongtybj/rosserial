#ifndef _ROS_drc_com_common_FC2OCSLarge_h
#define _ROS_drc_com_common_FC2OCSLarge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CameraInfo.h"
#include "std_msgs/Float32.h"
#include "std_msgs/UInt8.h"
#include "geometry_msgs/PoseStamped.h"
#include "jsk_recognition_msgs/TorusArray.h"
#include "visualization_msgs/MarkerArray.h"

namespace drc_com_common
{

  class FC2OCSLarge : public ros::Msg
  {
    public:
      sensor_msgs::PointCloud2 communication__point_cloud;
      sensor_msgs::PointCloud2 communication__laser_cloud;
      sensor_msgs::Image communication__image_rect_color;
      sensor_msgs::CameraInfo communication__camera_info;
      std_msgs::Float32 communication__image_width_scale;
      std_msgs::Float32 communication__image_height_scale;
      sensor_msgs::Image communication__panorama_image;
      sensor_msgs::Image communication__keyshot_image;
      std_msgs::Float32 communication__panorama_width_scale;
      std_msgs::Float32 communication__panorama_height_scale;
      std_msgs::UInt8 communication__robot_status;
      geometry_msgs::PoseStamped communication__handle_pose;
      geometry_msgs::PoseStamped communication__crank_pose;
      jsk_recognition_msgs::TorusArray communication__drive__controller__current_steering;
      visualization_msgs::MarkerArray communication__drive__recognition__predicted_path__marker;
      sensor_msgs::PointCloud2 communication__locomotion_cloud;
      sensor_msgs::PointCloud2 communication__normal_flip_cloud;
      enum { ROBOT_IDLE = 1 };
      enum { ROBOT_MOVING = 2 };

    FC2OCSLarge():
      communication__point_cloud(),
      communication__laser_cloud(),
      communication__image_rect_color(),
      communication__camera_info(),
      communication__image_width_scale(),
      communication__image_height_scale(),
      communication__panorama_image(),
      communication__keyshot_image(),
      communication__panorama_width_scale(),
      communication__panorama_height_scale(),
      communication__robot_status(),
      communication__handle_pose(),
      communication__crank_pose(),
      communication__drive__controller__current_steering(),
      communication__drive__recognition__predicted_path__marker(),
      communication__locomotion_cloud(),
      communication__normal_flip_cloud()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->communication__point_cloud.serialize(outbuffer + offset);
      offset += this->communication__laser_cloud.serialize(outbuffer + offset);
      offset += this->communication__image_rect_color.serialize(outbuffer + offset);
      offset += this->communication__camera_info.serialize(outbuffer + offset);
      offset += this->communication__image_width_scale.serialize(outbuffer + offset);
      offset += this->communication__image_height_scale.serialize(outbuffer + offset);
      offset += this->communication__panorama_image.serialize(outbuffer + offset);
      offset += this->communication__keyshot_image.serialize(outbuffer + offset);
      offset += this->communication__panorama_width_scale.serialize(outbuffer + offset);
      offset += this->communication__panorama_height_scale.serialize(outbuffer + offset);
      offset += this->communication__robot_status.serialize(outbuffer + offset);
      offset += this->communication__handle_pose.serialize(outbuffer + offset);
      offset += this->communication__crank_pose.serialize(outbuffer + offset);
      offset += this->communication__drive__controller__current_steering.serialize(outbuffer + offset);
      offset += this->communication__drive__recognition__predicted_path__marker.serialize(outbuffer + offset);
      offset += this->communication__locomotion_cloud.serialize(outbuffer + offset);
      offset += this->communication__normal_flip_cloud.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->communication__point_cloud.deserialize(inbuffer + offset);
      offset += this->communication__laser_cloud.deserialize(inbuffer + offset);
      offset += this->communication__image_rect_color.deserialize(inbuffer + offset);
      offset += this->communication__camera_info.deserialize(inbuffer + offset);
      offset += this->communication__image_width_scale.deserialize(inbuffer + offset);
      offset += this->communication__image_height_scale.deserialize(inbuffer + offset);
      offset += this->communication__panorama_image.deserialize(inbuffer + offset);
      offset += this->communication__keyshot_image.deserialize(inbuffer + offset);
      offset += this->communication__panorama_width_scale.deserialize(inbuffer + offset);
      offset += this->communication__panorama_height_scale.deserialize(inbuffer + offset);
      offset += this->communication__robot_status.deserialize(inbuffer + offset);
      offset += this->communication__handle_pose.deserialize(inbuffer + offset);
      offset += this->communication__crank_pose.deserialize(inbuffer + offset);
      offset += this->communication__drive__controller__current_steering.deserialize(inbuffer + offset);
      offset += this->communication__drive__recognition__predicted_path__marker.deserialize(inbuffer + offset);
      offset += this->communication__locomotion_cloud.deserialize(inbuffer + offset);
      offset += this->communication__normal_flip_cloud.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "drc_com_common/FC2OCSLarge"; };
    const char * getMD5(){ return "ca24e65a9f187abfa559ee94b47e212e"; };

  };

}
#endif