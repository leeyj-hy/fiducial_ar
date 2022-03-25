#include "ros/ros.h"
#include <opencv2/opencv.hpp>
#include "std_msgs/Header.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include "fiducial_msgs/Fiducial.h"
#include "fiducial_msgs/FiducialArray.h"
#include "sensor_msgs/Image.h"
#include "cv_bridge/cv_bridge.h"

using namespace ros;
using namespace std;
using namespace cv;

class fiducial_ar_sub
{
private:

    ros::NodeHandle n;
    ros::Subscriber sub1;
    ros::Subscriber sub2;

    int trn_x;
    int trn_y;
    int trn_z;
    int rot_x;
    int rot_y;
    int rot_z;
    int rot_w;

public:
    void sub_node()
    {
        sub1 = n.subscribe("usb_cam/image_raw", 2, &fiducial_ar_sub::imgCallback, this);
    }

    void imgCallback()
    {

    }
};

fiducial_ar_sub::fiducial_ar_sub(/* args */)
{
}

fiducial_ar_sub::~fiducial_ar_sub()
{
}





























































// #include "ros/ros.h"
// #include <opencv2/opencv.hpp>
// #include "std_msgs/Header.h"
// #include "std_msgs/Int32.h"
// #include "std_msgs/String.h"
// #include "fiducial_msgs/Fiducial.h"
// #include "fiducial_msgs/FiducialArray.h"
// #include "sensor_msgs/Image.h"
// #include "cv_bridge/cv_bridge.h"


// using namespace ros;
// using namespace std;
// using namespace cv;


// void imgCallback(const sensor_msgs::Image::ConstPtr& msg)
// {
//     ROS_INFO("Received image with size : %i x %i ", msg -> width, msg -> height);

//     try
//     {
//         imshow("view", cv_bridge::toCvShare(msg, "bgr8") -> image);
//         waitKey(3);
//     }
//     catch(const cv_bridge::Exception& e)
//     {
//         ROS_ERROR("Could not convert from '&s' to 'bgr8 .", msg -> encoding.c_str());    
//     }
// }



// int main(int argc, char **argv)
// {
//     ros::init(argc, argv, "fiducial_ar");
//     ros::NodeHandle n;
//     cv::namedWindow("view");

//     sensor_msgs::Image msg;
//     std::cout << "Subscribing starts!" << std::endl;
//     ros::Subscriber sub = n.subscribe("usb_cam/image_raw", 2, imgCallback);
    
//     ros::spin();
//     return 0;

// }