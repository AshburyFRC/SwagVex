#pragma config(Motor,  port2,           backLeftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           frontLeftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           beltMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           shootingMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           frontRightMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           backRightMotor, tmotorVex393_MC29, openLoop)

bool turn180 = false;

task findBalls {
	while (true) {
		// do stuff

		// Follow Line

		// When approached group of balls

		// Turn 180 degrees -> to movement
		if (false) { // 180 degrees
			turn180 = true;
		}

		break;
	}
}
task controlArm {
	while (true) {
		// do stuff
		break;
	}
}
task movement {
	while (true) {
		// do stuff

		// move

		// turn 180degrees
		if (turn180) {
			///
		  ///
		  ///
		  ///
			turn180 = false;
		}
		break;
	}
}
task shootingControl {
	while (true) {
		// do stuff
		break;

		// be able to shoot balls
	}
}

task main() { // this method is methodical
	startTask(findBalls);
	startTask(controlArm);
	startTask(movement);
	startTask(shootingControl);

}
