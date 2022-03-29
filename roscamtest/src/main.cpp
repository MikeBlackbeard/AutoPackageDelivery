#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"

#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class CameraPublisher : public rclcpp::Node
{
  public:
    CameraPublisher()
    : Node("camera_node"), count_(0)
    {
        cam_publisher_ = this->create_publisher<sensor_msgs::msg::Image>("sensor_cam", 10);
        publisher_ = this->create_publisher<std_msgs::msg::String>("camera", 10);
        timer_ = this->create_wall_timer(
        500ms, std::bind(&CameraPublisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
        cv::VideoCapture cap(0);
        cv::Mat img; // << image MUST be contained here
        cap.read(img);
        cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
        
        sensor_msgs::msg::Image img_message;
                
        cv_bridge::CvImage img_bridge;
        
        sensor_msgs::msg::Image img_msg; // >> message to be sent

        std_msgs::msg::Header header;
        header.frame_id = "camera";
        header.stamp = rclcpp::Clock(RCL_ROS_TIME).now();
        img_bridge = cv_bridge::CvImage(header, sensor_msgs::image_encodings::RGB8, img);

        img_bridge.toImageMsg(img_msg); // from cv_bridge to sensor_msgs::Image
        cam_publisher_->publish(img_msg); // ros::Publisher pub_img = node.advertise<sensor_msgs::Image>("topic", queuesize);

        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr cam_publisher_;
    size_t count_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CameraPublisher>());
  rclcpp::shutdown();
  return 0;
}