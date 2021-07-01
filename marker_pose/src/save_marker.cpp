#include "ros/ros.h"
#include "visualization_msgs/Marker.h"

void msgCallback(const visualization_msgs::Marker::ConstPtr&msg)
{
	int id = msg->id;
    float point_x = msg->pose.position.x;
	float point_y = msg->pose.position.y;
    float point_z = msg->pose.position.z;
    float ori_x = msg->pose.orientation.x;
    float ori_y = msg->pose.orientation.y;
    float ori_z = msg->pose.orientation.z;
    float ori_w = msg->pose.orientation.w;

    ROS_INFO("id = %d", id);
    ROS_INFO("point_x = %f", point_x);
    ROS_INFO("point_y = %f", point_y);
    ROS_INFO("point_z = %f", point_z);
    ROS_INFO("ori_x = %f", ori_x);
    ROS_INFO("ori_y = %f", ori_y);
    ROS_INFO("ori_z = %f", ori_z);
    ROS_INFO("ori_w = %f", ori_w);
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"save_marker");
	
	ros::NodeHandle nh;
	
	ros::Subscriber sub = nh.subscribe("/aruco_single/marker",10,msgCallback);	

	ros::spin();

	return 0;
	
}
