#include "robot_info/agv_robot_info_class.h"
#include <string>

AGVRobotInfo::AGVRobotInfo(const std::string &description, const std::string &serial,
                           const std::string &ip, const std::string &firmware, 
                           const std::string &payload, const std::string &oil_temperature,
                           const std::string &oil_tankFillLevel, const std::string &oil_pressure)
    : RobotInfo(description, serial, ip, firmware), maximum_payload(payload), hydraulicSystem(oil_temperature, oil_tankFillLevel, oil_pressure) {
    
};

void AGVRobotInfo::publish_data() {
    // Sending a new message to the base class through the topic     
    robotinfo_msgs::RobotInfo10Fields msg;    
    
    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number: " + serial_number;
    msg.data_field_03 = "ip_address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;
    msg.data_field_05 = "maximum_payload: " + maximum_payload;

    // Using composition for Hydraulic System Monitor
    msg.data_field_06 = "hydraulic_oil_temperature: " + hydraulicSystem.getHydraulicOilTemperature();
    msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulicSystem.getHydraulicOilTankFillLevel();
    msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulicSystem.getHydraulicOilPressure();

    robot_info_pub_.publish(msg);
};