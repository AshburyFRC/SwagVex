#pragma config(Motor,  port4,           beltMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           shootingMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main() {
	int beltSpeed = 0;
	while (true) {
		if (vexRT[Btn5U] == 1) {
			beltSpeed = 64;
		} else if (vexRT[Btn5D] == 1) {
			beltSpeed = 0;
		}
		motor[beltMotor] = beltSpeed;

		if (vexRT[Btn8U] == 1) {
			motor[shootingMotor] = 127;
		} else {
			motor[shootingMotor] = 0;
		}
		if (vexRT[Btn6U]) {
			motor[armMotor] = 64;
		} else if (vexRT[Btn6D]) {
			motor[armMotor] = -64;
		} else {
			motor[armMotor] = 0;
		}
	}
}