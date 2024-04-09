#pragma once

#include "robot_info/robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"

class AGVRobotInfo : public RobotInfo {
protected:
    std::string maximum_payload;
    HydraulicSystemMonitor hydraulicSystem;

public:
    AGVRobotInfo(const std::string &description, const std::string &serial,
                 const std::string &ip, const std::string &firmware,
                 const std::string &payload, const std::string &oil_temperature,
                 const std::string &oil_tankFillLevel, const std::string &oil_pressure);

    void publish_data() override;
        
};