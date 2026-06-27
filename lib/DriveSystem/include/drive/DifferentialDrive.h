//
// Created by CryosArtic on 6/26/2026.
//

#ifndef DRIVESYSTEM_DIFFERENTIALDRIVE_H
#define DRIVESYSTEM_DIFFERENTIALDRIVE_H

#include <vector>
#include "motor/RawMotor.h"

class DifferentialDrive {
private:
    std::vector<RawMotor> motors;
    std::vector<int> powerLevels;

public:
    DifferentialDrive(
        std::vector<std::vector<int> > new_pinInput, std::vector<int> new_powerInput,
        int new_minPower, int new_maxPower, int new_shutdownPower
    );

    DifferentialDrive(
        std::vector<std::vector<int> > new_pinInput, int new_power,
        int new_minPower, int new_maxPower, int new_shutdownPower
    );

    DifferentialDrive(
        std::vector<std::vector<int> > new_pinInput,
        std::vector<int> new_powerInput, int new_powerRangeInput[3]
    );

    DifferentialDrive(
        std::vector<std::vector<int> > new_pinInput, int new_power, int new_powerRangeInput[3]
    );

    void drive();

    void rotate();

    void setPower(int new_power);

    void setPower(std::vector<int> new_powerInput);

    std::vector<int> getPower() { return powerLevels; }

    static std::vector<RawMotor> setupPins(std::vector<std::vector<int> > new_pinInput);
};


#endif //DRIVESYSTEM_DIFFERENTIALDRIVE_H
