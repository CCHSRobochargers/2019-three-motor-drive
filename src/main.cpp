/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Right Arcade                                              */
/*    This sample allows you to control the V5 Clawbot using the right        */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RearMotor            motor         1               
// FrontRightMotor      motor         2               
// FrontLeftMotor       motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  // int deadband = 5;

  while (true) {
    float x = Controller1.Axis1.position();
    float y = Controller1.Axis2.position();
    float z_rot = Controller1.Axis4.position();

    float sqrt_3 = 1.732050807;

    float P = 0.33333333;
    
    int rearMotorSpeed = P * (z_rot + -x - y);
    int frontRightMotorSpeed = P * (z_rot + x + sqrt_3 * x - sqrt_3 * y + y) / 2;
    int frontLeftMotorSpeed = P * (z_rot - sqrt_3 * x + x + y + sqrt_3 * y) / 2;

    RearMotor.setVelocity(rearMotorSpeed, percent);
    FrontRightMotor.setVelocity(frontRightMotorSpeed, percent);
    FrontLeftMotor.setVelocity(frontLeftMotorSpeed, percent);

    // Spin both motors in the forward direction.
    RearMotor.spin(forward);
    FrontRightMotor.spin(forward);
    FrontLeftMotor.spin(forward);

    wait(25, msec);
  }
}
