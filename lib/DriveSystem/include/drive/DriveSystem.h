// //
// // Created by CryosArtic on 6/27/2026.
// //
//
// #ifndef DRIVESYSTEM_DRIVESYSTEM_H
// #define DRIVESYSTEM_DRIVESYSTEM_H
// #include <vector>
//
// #include "motor/RawMotor.h"
// #include "../board/Microcontroller.h"
// #include "comms/CommunicationNetwork.h"
//
// class DriveSystem {
// protected:
//     std::vector<RawMotor> leftMotors;
//     std::vector<RawMotor> rightMotors;
//     std::vector<int> leftPowerLevels;
//     std::vector<int> rightPowerLevels;
//     Microcontroller microcontroller;
//     CommunicationNetwork communicationNetwork;
//
// public:
//     virtual ~DriveSystem() = default; // deconstructor
//
//     DriveSystem(Microcontroller new_microcontroller, CommunicationNetwork new_communicationNetwork);
//
//     virtual void rotateLeft(float new_angle);
//
//     virtual void drive(float new_distance);
//
//     virtual void setPower(int new_power);
//
//     virtual void setPower(std::vector<int> new_powers);
//
//     virtual std::vector<std::vector<int> > getPower() {
//         return {leftPowerLevels, rightPowerLevels};
//     }
//
//     void setMotors(const std::vector<std::vector<RawMotor> > &motors);
// };
//
//
// #endif //DRIVESYSTEM_DRIVESYSTEM_H
