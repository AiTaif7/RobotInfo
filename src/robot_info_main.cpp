#include <ros/ros.h>
#include "robot_info/robot_info_class.h"

int main(int argc, char** argv) {
    ros::init(argc, argv, "robot_info_node");

    ROS_INFO("Node is online and running...");

    // Create an instance of RobotInfo objenct with all required information
    RobotInfo robotInfo("Blue_42", "B-17242", "181.214.151.129", "3.1.4" );

    ros::Rate loop_rate(10); // 10 Hz
    
    while (ros::ok()) {
        robotInfo.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }    
    return 0;
};