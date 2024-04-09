#pragma once

#include "robot_info/robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/node_handle.h"

class AGVRobotInfo : public RobotInfo {
protected:
    std::string maximum_payload;
    ros::Publisher agv_robot_info_pub_;

public:
    AGVRobotInfo(const std::string &description, const std::string &serial,
                 const std::string &ip, const std::string &firmware,
                 const std::string &payload);

    void publish_data() override;

};