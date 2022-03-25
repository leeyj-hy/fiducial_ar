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

    double x0;
    double y0;
    double x1;
    double y1;
    double x2;
    double y2;
    double x3;
    double y3;

    Mat image = Mat(480, 640, CV_8UC3);

public:
    fiducial_ar_sub()
    {
        sub1 = n.subscribe("/usb_cam/image_raw", 2, &fiducial_ar_sub::imgCallback, this);

        sub2 = n.subscribe("/fiducial_vertices", 2, &fiducial_ar_sub::mrkrCallback, this);
    }

    void imgCallback(const sensor_msgs::Image::ConstPtr& msg)
    {
        ROS_INFO("sub1 start");
        ROS_INFO("Received image with size : %i x %i ", msg -> width, msg -> height);

        try
        {
            image = cv_bridge::toCvShare(msg, "bgr8") -> image;
            waitKey(3);
        }
        catch(const cv_bridge::Exception& e)
        {
            ROS_ERROR("Could not convert from '&s' to 'bgr8 .", msg -> encoding.c_str());    
        }
    }

    void mrkrCallback(const fiducial_msgs::FiducialArray::ConstPtr& msg)
    {
        ROS_INFO("sub2 start");
        for(int i=0; i<msg -> fiducials.size() ; i++)
        {
        this -> x0 = msg -> fiducials[i].x0;
        this -> y0 = msg -> fiducials[i].y0;
        this -> x1 = msg -> fiducials[i].x1;
        this -> y1 = msg -> fiducials[i].y1;
        this -> x2 = msg -> fiducials[i].x2;
        this -> y2 = msg -> fiducials[i].y2;
        this -> x3 = msg -> fiducials[i].x3;
        this -> y3 = msg -> fiducials[i].y3;
        }
        ROS_INFO("sub2 end");

        img_disp();

    }

    int img_disp()
    {
        cv::line(image, Point(this->x0, this->y0), Point(this->x1, this->y1),Scalar(0,0,255), 1, 8, 0);
        cv::line(image, Point(this->x1, this->y1), Point(this->x2, this->y2),Scalar(0,0,255), 1, 8, 0);
        cv::line(image, Point(this->x2, this->y2), Point(this->x3, this->y3),Scalar(0,0,255), 1, 8, 0);
        cv::line(image, Point(this->x3, this->y3), Point(this->x0, this->y0),Scalar(0,0,255), 1, 8, 0);
        
        
        
        imshow("img", image);
        waitKey(3);
    }


};



int main(int argc, char **argv)
{
    ros::init(argc, argv, "fiducial_ar_node");
    //ROS_INFO("ar_node start!");
    fiducial_ar_sub FAS_obj;

    ros::spin();
    return 0;
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