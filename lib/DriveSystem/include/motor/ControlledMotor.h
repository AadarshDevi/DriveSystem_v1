//
// Created by CryosArtic on 6/20/2026.
//

#ifndef DRIVESYSTEM_CONTROLLEDMOTOR_H
#define DRIVESYSTEM_CONTROLLEDMOTOR_H

#include "RawMotor.h"

class ControlledMotor : public RawMotor {
protected:
    int minPower;
    int maxPower;
    int targetPower;

public:
    ControlledMotor(
        uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2,
        bool new_pinIN1Enabled, bool new_pinIN2Enabled,
        bool new_reverseRotation, bool new_rotationEnabled,
        int new_power, int new_absMinPower, int new_absMaxPower,
        int new_minPower, int new_maxPower,
        int new_shutdownPower, int new_targetPower,
        bool new_showDebug
    );

    ControlledMotor(
        uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2,
        int new_power, int new_absMinPower, int new_absMaxPower,
        int new_minPower, int new_maxPower,
        int new_shutdownPower, int new_targetPower
    );

    void setMinPower(int new_minPower);

    void setMaxPower(int new_maxPower);

    int getMinPower() const { return minPower; }

    int getMaxPower() const { return maxPower; }

    void setTargetPower(int new_targetPower);

    int getTargetPower() const { return targetPower; }

    /**
     * PID controlling the motor's power to reach targetPower
     */
    void process();
};

#endif
