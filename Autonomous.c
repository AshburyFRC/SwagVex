#pragma config(Motor,  port2,           backLeftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           frontLeftMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           frontRightMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           backRightMotor, tmotorVex393_MC29, openLoop)
#pragma config(Sensor, dgtl8, sonarSensor, sensorSONAR_cm)


task main() {

	int speed;
	int sonar_value;
	int distance = 25;
	while (true) {
		sonar_value = SensorValue(sonarSensor);
		displayLCDPos(0,0);
		displayNextLCDString("Sonar: ");
		displayNextLCDNumber(sonar_value);

		if (sonar_value < 0) {
			speed = 127;
			} else {
			speed = (sonar_value - distance)^2;
		}

		clearLCDLine(1);
		displayLCDPos(1,0);
		displayNextLCDString("Speed: ");
		displayNextLCDNumber(speed);

		motor[frontLeftMotor] = speed;
		motor[frontRightMotor] = speed;
		motor[backLeftMotor] = speed;
		motor[backRightMotor] = speed;

		wait1Msec(100);
	}


}
