#pragma config(Motor,  port2,           backLeftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           frontLeftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           frontRightMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           backRightMotor, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main() {
	while (true) {
		int x  = vexRT[Ch1];   // Right Joystick X value
		int y = vexRT[Ch3];   // Left Joystick Y value

		if (abs(x) < 10) {
			x = 0;
		}
		if (abs(y) < 10) {
			y = 0;
		}

		int speed = y;

		int differential = x;

		int right = speed + differential;
		int left = speed - differential;

		if (right > 127) {
			right = 127;
		}
		if (right < -128) {
			right = -128;
		}
		if (left > 127) {
			left = 127;
		}
		if (left < -128) {
			left = -128;
		}

		int frontLeft = left;
		int frontRight = right;
		int backLeft = left;
		int backRight = right;

		int mech = vexRT[Ch4];  // Left Joystick X value
		if (abs(mech) < 10) {
			mech = 0;
		}

		frontLeft += mech;
		frontRight += mech;

		backLeft -= mech;
		backRight -= mech;

		if (frontLeft < -128) {
			frontLeft = -128;
		}
		if (frontRight < -128) {
			frontRight = -128;
		}
		if (backLeft < -128) {
			backLeft = -128;
		}
		if (backRight < -128) {
			backRight = -128;
		}
		if (frontLeft > 127) {
			frontLeft = 127;
		}
		if (frontRight > 127) {
			frontRight = 127;
		}
		if (backLeft > 127) {
			backLeft = 127;
		}
		if (backRight > 127) {
			backRight = 127;
		}
		int timeToRotate = 1000;

		if (vexRT[Btn8L] == 1) {
			motor[frontLeftMotor] = -128;
			motor[backLeftMotor] = -128;
			motor[frontRightMotor] = 127;
			motor[backRightMotor] = 127;
			wait1Msec(timeToRotate);
			motor[frontLeftMotor] = 0;
			motor[backLeftMotor] = 0;
			motor[frontRightMotor] = 0;
			motor[backRightMotor] = 0;
			} else if (vexRT[Btn8R] == 1) {
			motor[frontLeftMotor] = 127;
			motor[backLeftMotor] = 127;
			motor[frontRightMotor] = -128;
			motor[backRightMotor] = -128;
			wait1Msec(timeToRotate);
			motor[frontLeftMotor] = 0;
			motor[backLeftMotor] = 0;
			motor[frontRightMotor] = 0;
			motor[backRightMotor] = 0;
			} else if (vexRT[Btn8D] == 1) {
			motor[frontLeftMotor] = 127;
			motor[backLeftMotor] = 127;
			motor[frontRightMotor] = -128;
			motor[backRightMotor] = -128;
			wait1Msec(timeToRotate*2);
			motor[frontLeftMotor] = 0;
			motor[backLeftMotor] = 0;
			motor[frontRightMotor] = 0;
			motor[backRightMotor] = 0;
		}

		// TO STABALIZE
		// FRONT LEFT AND BACK RIGHT GO FORWARDS
		// BACK LEFT AND FRONT RIGHT GO BACKWARDS
		if (x == 0 && y == 0 && mech == 0) {
			frontLeft = 10;
			frontRight = -10;
			backLeft = -10;
			backRight = 10;
		}


		motor[frontLeftMotor] = frontLeft;
		motor[backLeftMotor] = backLeft;
		motor[frontRightMotor] = frontRight;
		motor[backRightMotor] = backRight;

	}
}
