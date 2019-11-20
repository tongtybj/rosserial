#include "ros/ros.h"
#include "rosserial_arduino/Test.h"

namespace rosserial {
#include "rosserial_test/ros.h"
#include "rosserial/rosserial_arduino/Test.h"
}

#include <gtest/gtest.h>
#include "rosserial_test/fixture.h"

int rosserial_echo_count = 0;
static bool echo(rosserial_arduino::Test::Request &req, rosserial_arduino::Test::Response &res)
{
  ROS_ERROR("reveicve echo request!");
  rosserial_echo_count++;
  res.output = req.input;
  return true;
}

/**
 * Single service call from a rosserial-connected client,
 * verified from a roscpp rosservice server.
 */
TEST_F(SingleClientFixture, single_service_client) {

  rosserial::ros::ServiceClient<rosserial::rosserial_arduino::Test::Request, rosserial::rosserial_arduino::Test::Response> client_srv_client("test_srv");
  client_nh.serviceClient(client_srv_client);
  client_nh.initNode();

  // Roscpp rosservice server to do the response for the client.
  ros::ServiceServer test_service = nh.advertiseService("test_srv", &echo);

  rosserial::rosserial_arduino::Test::Request req;
  rosserial::rosserial_arduino::Test::Response res;
  char hello[13] = "hello world!";
  req.input = hello;

  for(int attempt = 0; attempt < 50; attempt++) {
    if (attempt % 10 == 0 && attempt > 0) {
      client_srv_client.call(req, res);
    }

    client_nh.spinOnce();
    if (rosserial_echo_count > 0) break;
    ros::Duration(0.1).sleep();
  }
  EXPECT_GT(rosserial_echo_count, 0);
  EXPECT_STREQ(req.input, res.output);
}

int main(int argc, char **argv){
  ros::init(argc, argv, "test_service_client");
  ros::start();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
