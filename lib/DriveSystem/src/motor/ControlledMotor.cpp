//
// Created by CryosArtic on 6/20/2026.
//

#include "../../include/motor/ControlledMotor.h"

ControlledMotor::ControlledMotor(
    uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2,
    bool new_pinIN1Enabled, bool new_pinIN2Enabled,
    bool new_reverseRotation, bool new_rotationEnabled,
    int new_power, int new_absMinPower, int new_absMaxPower,
    int new_minPower, int new_maxPower,
    int new_shutdownPower, int new_targetPower,
    bool new_showDebug
) : RawMotor(
    new_pinPWM, new_pinIN1, new_pinIN2,
    new_pinIN1Enabled, new_pinIN2Enabled,
    new_reverseRotation, new_rotationEnabled,
    new_power, new_absMinPower, new_absMaxPower, new_shutdownPower,
    new_showDebug
) {
    minPower = new_minPower;
    maxPower = new_maxPower;
    targetPower = new_targetPower;
}

ControlledMotor::ControlledMotor(
    uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2,
    int new_power, int new_absMinPower, int new_absMaxPower,
    int new_minPower, int new_maxPower,
    int new_shutdownPower, int new_targetPower
) : ControlledMotor(
    new_pinPWM, new_pinIN1, new_pinIN2,
    false, false,
    false, false,
    new_power, new_absMinPower, new_absMaxPower,
    new_minPower, new_maxPower,
    new_shutdownPower, new_targetPower,
    false
) {
}

void ControlledMotor::setMaxPower(int new_maxPower) {
    if (new_maxPower > absMaxPower) {
        maxPower = absMaxPower;
    } else if (new_maxPower < absMinPower) {
        maxPower = absMinPower;
    } else {
        maxPower = new_maxPower;
    }
}

void ControlledMotor::setMinPower(int new_minPower) {
    if (new_minPower < absMinPower) {
        minPower = absMinPower;
    } else if (new_minPower > absMaxPower) {
        minPower = absMaxPower;
    } else {
        minPower = new_minPower;
    }
}

void ControlledMotor::setTargetPower(int new_targetPower) {
    if (new_targetPower > maxPower) {
        targetPower = maxPower;
    } else if (new_targetPower < minPower) {
        targetPower = minPower;
    } else {
        targetPower = new_targetPower;
    }
}

void ControlledMotor::process() {
    // todo code
}

