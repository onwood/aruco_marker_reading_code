#include "ros/ros.h"
#include "visualization_msgs/Marker.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>


void msgCallback(const visualization_msgs::Marker::ConstPtr&msg)
{   
    
	int id = msg->id;
    double point_x = msg->pose.position.x;
	double point_y = msg->pose.position.y;
    double point_z = msg->pose.position.z;
    double ori_x = msg->pose.orientation.x;
    double ori_y = msg->pose.orientation.y;
    double ori_z = msg->pose.orientation.z;
    double ori_w = msg->pose.orientation.w;

    double roll, pitch, yaw;

    // struct Quaternion {
    //     double w, x, y, z;
    //     Quaternion(double _a, double _b, double _c, double _d) : w(_a), x(_b), y(_c), z(_d){};
    // };

    // struct EulerAngles {
    //     float roll, pitch, yaw;
    // };

    // EulerAngles ToEulerAngles(Quaternion q(ori_w, ori_x, ori_y, ori_z)) {
    //     EulerAngles angles;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (ori_w * ori_x + ori_y * ori_z);
    double cosr_cosp = 1 - 2 * (ori_x * ori_x + ori_y * ori_y);
    roll = atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (ori_w * ori_y - ori_z * ori_x);
    if (abs(sinp) >= 1)
        pitch = copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        pitch = asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (ori_w * ori_z + ori_x * ori_y);
    double cosy_cosp = 1 - 2 * (ori_y * ori_y + ori_z * ori_z);
    yaw = atan2(siny_cosp, cosy_cosp);

        // return angles;
    // }

    ROS_INFO("id = %d", id);
    ROS_INFO("point_x = %f", point_x);
    ROS_INFO("point_y = %f", point_y);
    ROS_INFO("point_z = %f", point_z);
    ROS_INFO("ori_x = %f", ori_x);
    ROS_INFO("ori_y = %f", ori_y);
    ROS_INFO("ori_z = %f", ori_z);
    ROS_INFO("ori_w = %f", ori_w);

    ROS_INFO("roll = %f", roll);
    ROS_INFO("pitch = %f", pitch);
    ROS_INFO("yaw = %f", yaw);

    if (point_x > 0)
    {
        ROS_INFO("turn right");
    }
    else
    {
        ROS_INFO("turn left");
    }
    if (point_z > 0)
    {
        ROS_INFO("Go foward");
    }
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"save_marker");
	
	ros::NodeHandle nh;
	
	ros::Subscriber sub = nh.subscribe("/aruco_single/marker",10,msgCallback);	

	ros::spin();

	return 0;
	
}
