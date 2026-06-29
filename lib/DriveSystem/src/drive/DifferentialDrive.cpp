// //
// // Created by CryosArtic on 6/26/2026.
// //
//
// #include "../../include/drive/DifferentialDrive.h"
//
// DifferentialDrive::DifferentialDrive(Microcontroller new_microcontroller, Communication new_comms)
//     : DriveSystem(new_microcontroller) {
//     switch (new_microcontroller) {
//         case Microcontroller::ESP32_WROVER_E:
//             // 4 motors
//             break;
//         case Microcontroller::ESP32_WROOM_32UE:
//             // 4 motors
//             break;
//         case Microcontroller::ARDUINO_UNO_Q:
//             // 2 motors
//             break;
//         case Microcontroller::ARDUINO_UNO_R3:
//             // 2 motors
//             break;
//         case Microcontroller::RASPBERRY_PI_PICO_2_W:
//             // 2 motors
//             break;
//         case Microcontroller::RASPBERRY_PI_PICO_W:
//             // 2 motors
//             break;
//     }
// }
//
//
// // DifferentialDrive::DifferentialDrive(
// //     std::vector<std::vector<int> > new_pinInput, std::vector<int> new_powerInput,
// //     int new_minPower, int new_maxPower, int new_shutdownPower
// // ) {
// //     if (new_pinInput.size() / 2 != 0) {
// //         throw new std::invalid_argument("There cannot be odd number of motors.");
// //     }
// //
// //     for (std::vector<int> pin: new_pinInput) {
// //         if (pin.size() != 3) {
// //             throw new std::invalid_argument("There must be 3 motor pins");
// //         }
// //     }
// //
// //     if (new_powerInput.size() > new_pinInput.size()) {
// //         throw new std::invalid_argument("There are more power input than motors");
// //     }
// //     if (new_powerInput.size() < new_pinInput.size()) {
// //         throw new std::invalid_argument("There are less power input than motors");
// //     }
// //
// //     if (new_minPower > new_maxPower) {
// //         throw new std::invalid_argument("Min motor power cannot be greater than max motor power");
// //     }
// //     if (new_shutdownPower > new_minPower) {
// //         throw new std::invalid_argument("Motor's shutdown power cannot be more than min motor power");
// //     }
// // }
// //
// // DifferentialDrive::DifferentialDrive(
// //     std::vector<std::vector<int> > new_pinInput, int new_power,
// //     int new_minPower, int new_maxPower, int new_shutdownPower
// // ) {
// // }
// //
// // DifferentialDrive::DifferentialDrive(
// //     std::vector<std::vector<int> > new_pinInput,
// //     std::vector<int> new_powerInput, int new_powerRangeInput[3]
// // ) {
// // }
// //
// // DifferentialDrive::DifferentialDrive(
// //     std::vector<std::vector<int> > new_pinInput, int new_power, int new_powerRangeInput[3]
// // ) {
// // }
//
// // static std::vector<std::vector<int> > DifferentialDrive::setupPins(std::vector<std::vector<int> > new_powerInput) {
// //     if (!(new_powerInput % 2 == 0)) {
// //         throw std::invalid_argument("Uneven Motor Count");
// //     }
// //     for (int i = 0; i < new_powerInput.size(); i++) {
// //         std::vector<int> motorPins = new_powerInput[i];
// //         if (motorPins.size() != 3) {
// //             throw std::invalid_argument("Motor Pin Count is not 3");
// //         }
// //     }
// //     return new_powerInput;
// // };
