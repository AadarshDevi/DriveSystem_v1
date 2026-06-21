//
// Created by CryosArtic on 6/20/2026.
//

#include <Arduino.h>

#include "RawMotor.h"
// todo: min&max power exception handling

// constructor
RawMotor::RawMotor(int new_pinPWM, int new_in1Pin, int new_in2Pin, int new_absMinPower, int new_absMaxPower) {
  // set pins
  pinPWM = new_pinPWM;
  in1Pin = new_in1Pin;
  in2Pin = new_in2Pin;

  pinMode(pinPWM, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  // set power
  if (new_absMinPower > new_absMaxPower) {
    log_e("Min Power > Max Power");
    absMaxPower = new_absMinPower;
    absMinPower = new_absMaxPower;
  } else {
    absMaxPower = new_absMaxPower;
    absMinPower = new_absMinPower;
  }

  power = 0;

  // set power levels
  in1Level = LOW;
  in2Level = LOW;

  // set motor dir
  RawMotor::forward();
}

void RawMotor::reverse() {
  reverseMotor = true;
  in1Level = LOW;
  in2Level = HIGH;

  // makes sure both inputs aren't high so
  // that the motor doesn't self-destruct
  if (in1Level == HIGH && in2Level == HIGH) {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
  } else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
};

void RawMotor::forward() {
  reverseMotor = false;
  in1Level = HIGH;
  in2Level = LOW;

  // makes sure both inputs aren't high so
  // that the motor doesn't self-destruct
  if (in1Level == HIGH && in2Level == HIGH) {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
  } else {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
};

void RawMotor::setMaxPower(int new_maxPower) {
  absMaxPower = new_maxPower;
  if (power > absMaxPower) {
    power = absMaxPower;
  }
};

void RawMotor::setMinPower(int new_minPower) {
  absMinPower = new_minPower;
  if (power < absMinPower) {
    power = absMinPower;
  }
};

void RawMotor::setPower(int new_power) {
  // makes sure the ower is or greater thn the min power limit
  if (new_power < 0 || new_power < absMinPower) {
    if (shutdownMotor) {
      power = 0;
    } else {
      power = absMinPower;
    }
    return;
  }

  // makes sure power doesn't exceed max limit
  if (new_power > absMaxPower) {
    if (shutdownMotor) {
      powerDown();
      power = 0;
    } else {
      power = absMaxPower;
    }
    return;
  }
  power = new_power;
};

void RawMotor::start() {
  running = true;
};

void RawMotor::stop() {
  running = false;
};

void RawMotor::run() {
  if (!running) {
    return;
  }
  analogWrite(pinPWM, power);
}

void RawMotor::shutdown(bool new_shutdownMotor) {
  shutdownMotor = new_shutdownMotor;
}

void RawMotor::debug(bool new_canDebug) {
  canDebug = new_canDebug;
}

void RawMotor::info() {
  Serial.printf("Pins:\n\tPWM > %d\n\tIN1 > %d (%d)\n\tIN2 > %d (%d)\n\n", pinPWM, in1Pin, in1Level, in2Pin, in2Level);
  Serial.printf("Power:\n\tCurrent > %d\n\tMin > %d\n\tMax > %d\n\n", power, absMinPower, absMaxPower);
  Serial.printf("Motor:\n\tRunning > %d\n\tReverse > %d\n\tShutdown > %d\n\n", running, reverseMotor, shutdownMotor);
  Serial.printf("Debug > %d\n\n", canDebug);
}

void RawMotor::monitor(int new_power) {
  Serial.printf("Input:%d Motor:%d Min:%d Max:%d\n", new_power, power, absMinPower, absMaxPower);
  // prints power to serial graph
}

void RawMotor::powerDown() {
  if (power == 0) {
    return;
  }

  for (int i = 4; i >= 0; i--) {
    power = i * 0.2 * power;
    run();
    monitor(0);
    delay(1000);
  }
}
