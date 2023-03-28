#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <openpose/headers.hpp>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ai_fitness_trainer");
  ros::NodeHandle nh;
  // rest of the code
}

op::Wrapper opWrapper;
opWrapper.configure(op::WrapperStructPose{});
opWrapper.start();

cv::VideoCapture cap(0);
if (!cap.isOpened())
{
  ROS_ERROR("Failed to open camera");
  return -1;
}
while (ros::ok())
{
  cv::Mat frame;
  cap >> frame;
  op::Datum datum;
  datum.cvInputData = frame;
  opWrapper.emplaceAndPop(std::move(datum));
  // rest of the code
}
op::Array<float> poseKeypoints = datum.poseKeypoints;
// process pose keypoints to analyze form
ros::Publisher audio_pub = nh.advertise<std_msgs::String>("/audio_feedback", 10);
std_msgs::String msg;
msg.data = "Keep your back straight";
audio_pub.publish(msg);
