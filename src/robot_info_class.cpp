#include "robot_info/robot_info_class.h"
#include "ros/node_handle.h"

RobotInfo::RobotInfo(const std::string &description, const std::string &serial,
                     const std::string &ip, const std::string &firmware)
    : robot_description(description), serial_number(serial),
      ip_address(ip), firmware_version(firmware), nh(), robot_info_pub_(nh.advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 1000)) {

}

void RobotInfo::publish_data() {
    robotinfo_msgs::RobotInfo10Fields msg;
    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number: " + serial_number;
    msg.data_field_03 = "ip_address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;

    robot_info_pub_.publish(msg);
}