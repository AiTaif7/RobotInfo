#include "robot_info/agv_robot_info_class.h"
#include <string>

AGVRobotInfo::AGVRobotInfo(const std::string &description, const std::string &serial,
                           const std::string &ip, const std::string &firmware, 
                           const std::string &payload)
    : RobotInfo(description, serial, ip, firmware), maximum_payload(payload) {
    
};

void AGVRobotInfo::publish_data() {
    // Subscribe to the base class message topic    
    robotinfo_msgs::RobotInfo10Fields msg;    
    
    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number: " + serial_number;
    msg.data_field_03 = "ip_address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;
    msg.data_field_05 = "maximum_payload: " + maximum_payload;

    robot_info_pub_.publish(msg);
};