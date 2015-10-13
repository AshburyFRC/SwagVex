#pragma config(Motor,  port4,           beltMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           shootingMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main() {
	int beltSpeed = 64;
	while (true) {
		if (vexRT[Btn5U] == 1) {
			beltSpeed++;
			} else if (vexRT[Btn5D] == 1) {
			beltSpeed--;
		}
		if (beltSpeed > 127) {
			beltSpeed = 127;
		} else if (beltSpeed < -128) {
			beltSpeed = -128;
		}
		motor[beltMotor] = beltSpeed;

		if (vexRT[Btn8U] == 1) {
			motor[shootingMotor] = 127;
			} else {
			motor[shootingMotor] = 0;
		}
		if (vexRT[Btn6U]) {
			motor[armMotor] = 127;
			} else if (vexRT[Btn6D]) {
			motor[armMotor] = -128;
			} else {
			motor[armMotor] = 0;
		}
	}
}
