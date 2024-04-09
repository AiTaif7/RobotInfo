#pragma once

#include <ros/ros.h>
#include "robotinfo_msgs/RobotInfo10Fields.h"


class HydraulicSystemMonitor {
protected:
    std::string hydraulic_oil_temperature;
    std::string hydraulic_oil_tank_fill_level;
    std::string hydraulic_oil_pressure;

public:
    HydraulicSystemMonitor(const std::string &oil_temperature, const std::string &oil_tankFillLevel,
                           const std::string &oil_pressure);
    
    std::string getHydraulicOilTemperature() const ;
    std::string getHydraulicOilTankFillLevel() const ;
    std::string getHydraulicOilPressure() const;
    
};