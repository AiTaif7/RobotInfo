#include "robot_info/hydraulic_system_monitor.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"

HydraulicSystemMonitor::HydraulicSystemMonitor(const std::string &oil_temperature, const std::string &oil_tankFillLevel, const std::string &oil_pressure)
        : hydraulic_oil_temperature(oil_temperature), 
          hydraulic_oil_tank_fill_level(oil_tankFillLevel), 
          hydraulic_oil_pressure(oil_pressure) {
};

std::string HydraulicSystemMonitor::getHydraulicOilTemperature() const {
    return hydraulic_oil_temperature;
};

std::string HydraulicSystemMonitor::getHydraulicOilTankFillLevel() const {
    return hydraulic_oil_tank_fill_level;
};

std::string HydraulicSystemMonitor::getHydraulicOilPressure() const {
    return hydraulic_oil_pressure;
};