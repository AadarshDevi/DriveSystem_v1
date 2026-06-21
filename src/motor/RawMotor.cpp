//
// Created by CryosArtic on 6/20/2026.
//

#include "RawMotor.h"

RawMotor::RawMotor(uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2,
                   bool new_pinIN1Enabled, bool new_pinIN2Enabled,
                   bool new_reverseRotation, bool new_rotationEnabled,
                   int new_power, int new_absMinPower, int new_absMaxPower, int new_shutdownPower,
                   bool new_showDebug
) {
    pinPWM = new_pinPWM;
    pinIN1 = new_pinIN1;
    pinIN2 = new_pinIN2;

    pinIN1Enabled = new_pinIN1Enabled;
    pinIN2Enabled = new_pinIN2Enabled;

    reverseRotation = new_reverseRotation;
    rotationEnabled = new_rotationEnabled;

    power = new_power;
    absMinPower = new_absMinPower;
    absMaxPower = new_absMaxPower;
    shutdownPower = new_shutdownPower;

    enableDebug = new_showDebug;
}

RawMotor::RawMotor(
    uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2,
    int new_absMinPower, int new_absMaxPower
) : RawMotor(
    new_pinPWM, new_pinIN1, new_pinIN2,
    false, false,
    false, false,
    new_absMinPower, new_absMinPower, new_absMaxPower, new_absMinPower,
    false
) {
}

RawMotor::RawMotor(
    uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2,
    int new_power, int new_absMinPower, int new_absMaxPower, int new_shutdownPower
) : RawMotor(
    new_pinPWM, new_pinIN1, new_pinIN2,
    false, false,
    false, false,
    new_power, new_absMinPower, new_absMaxPower, new_shutdownPower,
    false
) {
}

RawMotor::RawMotor(
    uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2,
    int new_power, int new_absMinPower, int new_absMaxPower, int new_shutdownPower,
    bool new_reverseRotation
) : RawMotor(
    new_pinPWM, new_pinIN1, new_pinIN2,
    false, false,
    new_reverseRotation, false,
    new_power, new_absMinPower, new_absMaxPower, new_shutdownPower,
    false
) {
}

void RawMotor::setMotorPins(uint8_t new_pinPWM, uint8_t new_pinIN1, uint8_t new_pinIN2) {
    if (
        new_pinIN1 == new_pinIN2 ||
        new_pinPWM == new_pinIN1 ||
        new_pinPWM == new_pinIN2) {
        return;
    }
    pinPWM = new_pinPWM;
    pinIN1 = new_pinIN1;
    pinIN2 = new_pinIN2;
}

void RawMotor::setPower(int new_power) {
    if (new_power < 0 || new_power < absMinPower) {
        power = absMinPower;
        return;
    }

    // makes sure power doesn't exceed max limit
    if (new_power > absMaxPower) {
        power = absMaxPower;
        return;
    }

    power = new_power;
}

void RawMotor::setAbsMinPower(int new_absMinPower) {
    if (new_absMinPower > absMaxPower) return;
    absMinPower = new_absMinPower;
}

void RawMotor::setAbsMaxPower(int new_absMaxPower) {
    if (new_absMaxPower < absMinPower) return;
    absMaxPower = new_absMaxPower;
}

void RawMotor::setShutdownPower(int new_shutdownPower) {
    shutdownPower = new_shutdownPower;
}

void RawMotor::run() {
    // todo code
}


