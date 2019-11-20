#include "ros/ros.h"
#include "std_srvs/Empty.h"

namespace rosserial {
#include "rosserial_test/ros.h"
#include "rosserial/std_srvs/Empty.h"
}

#include <gtest/gtest.h>
#include "rosserial_test/fixture.h"

int rosserial_empty_call_count = 0;
static bool empty(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res)
{
  ROS_ERROR("reveicve empty request!");
  rosserial_empty_call_count++;
  return true;
}

/**
 * Single service call from a rosserial-connected client,
 * verified from a roscpp rosservice server.
 */
TEST_F(SingleClientFixture, single_service_client2) {

  rosserial::ros::ServiceClient<rosserial::std_srvs::Empty::Request, rosserial::std_srvs::Empty::Response> client_srv_client2("test_srv2");
  client_nh.serviceClient(client_srv_client2);
  client_nh.initNode();

  // Roscpp rosservice server to do the response for the client.
  ros::ServiceServer test_service2 = nh.advertiseService("test_srv2", &empty);

  rosserial::std_srvs::Empty::Request req;
  rosserial::std_srvs::Empty::Response res;

  for(int attempt = 0; attempt < 50; attempt++) {
    if (attempt % 10 == 0 && attempt > 0) {
      client_srv_client2.call(req, res);
    }

    client_nh.spinOnce();
    if (rosserial_empty_call_count > 0) break;
    ros::Duration(0.1).sleep();
  }
  EXPECT_GT(rosserial_empty_call_count, 0);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "test_service_client");
  ros::start();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
