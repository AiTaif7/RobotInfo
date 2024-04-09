#pragma once

#include <ros/ros.h>
#include "robotinfo_msgs/RobotInfo10Fields.h"

class RobotInfo {
  protected:
    std::string robot_description;
    std::string serial_number;
    std::string ip_address;
    std::string firmware_version;

    ros::NodeHandle nh;
    ros::Publisher robot_info_pub_;

  public:
    RobotInfo(const std::string &description, const std::string &serial,
              const std::string &ip, const std::string &firmware );
    
    virtual void publish_data(); // Virtual function
};