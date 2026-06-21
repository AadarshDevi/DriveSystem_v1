//
// Created by CryosArtic on 6/20/2026.
//

#ifndef DRIVESYSTEM_CONTROLLEDMOTOR_H
#define DRIVESYSTEM_CONTROLLEDMOTOR_H

#include "RawMotor.h"

class ControlledMotor : public RawMotor {
private:
    max_power;

public:
    ControlledMotor();
};

#endif //DRIVESYSTEM_CONTROLLEDMOTOR_H
