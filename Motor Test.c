
#pragma config(Sensor, dgtl1,  feedbackEncoder, sensorQuadEncoder)
#pragma config(Motor,  port2,  testMotor,     tmotorVex393_MC29, openLoop)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                     - Test Motor Functionality -                                   *|
|*                                Written in ROBOTC 4.56 for the VEX CORTEX                           *|
|*                                                                                                    *|
|*  AUTHOR: Mahesh Chugani                                                                            *|
|*  DATE CREATED: Nov 24, 2017                                                                        *|
|*  STATUS: beginning, IN PROGRESS, working, enhancements                                             *|
|*                                                                                                    *|
|*  MODIFIED BY: 	(enter your name here if you modify the file)																				*|
|*                                                                                                    *|
|*																					DESCRIPTION																								*|
|*                                                                                                    *|
|*  This program tests a motor at various power levels, in both forward & reverse directions.         *|
|*  The user should use the RobotC datalogger (in the debugger) to record & save (1) the motor power  *|
|*  and (2) the encoder values, to a *.csv file. This file is then uploaded into a LabVIEW program    *|
|* (Read RobotC MotorTest Datalog File.vi) for analysis and display.                                  *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  The Test Motor is connected to Motor Port 2 of Cortex.                                      *|
|*                                                                                                    *|
|*    2)  Encoder that is being used for feedback should be cleared __each time__ before it starts    *|
|*        counting by using "SensorValue[feedbackEncoder] = 0;".                                      *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [	Description]                    *|
|*    Motor   - Port 2    testMotor          	VEX 3-wire module     	Test Motor                      *|
|*    Digital - Port 1,2  feedbackEncoder    	VEX Shaft Encoder     	Connected to Test Motor         *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |++++++++++++++++++++++++++++++++++++++++++++

/* ************ Record Data for 5 rotations ************ */
void recordData( )
{
	// clear Encoder
	SensorValue[feedbackEncoder] = 0;

  // Wait for 5 rotations = 1800 counts on Encoder (1 rotation = 360 counts)
	while(SensorValue[feedbackEncoder] < 1800)
  {
    //	do nothing while datalogger is recording data.
  }
}

task main()
{
	// Define power levels at which to test motor. Power values range from -127 to +127

	int noPower = 0;                    // 0% power
	int quarterPower = 32;              // 25% power
	int halfPower = 64;                 // 50% power
	int threeFourthsPower = 96;         // 75% power
	int fullPower = 127;                // 100% power

	wait1Msec(2000);                    // 2 second delay before starting

	datalogClear();                     // clear the datalog for recording

	/* ----------   Test motor rotation in one direction (clockwise or anticlockwise) ----------*/

	motor[testMotor] = noPower;           // start with motor stopped
	wait1Msec(1000);                      // rest period to make sure motor is stopped

	motor[testMotor] = quarterPower;      // run motor at 25% power
	recordData();

	motor[testMotor] = halfPower;         // run motor at 50% power
	recordData();

	motor[testMotor] = threeFourthsPower; // run motor 75% power
	recordData();

	motor[testMotor] = fullPower;         // give motor 100% power
	recordData();

	/* --------   Test motor rotation in opposite direction (antilockwise or clockwise) --------*/

	motor[testMotor] = noPower;           // stop the motor
	wait1Msec(1000);                      // rest period to make sure motor is stopped

	motor[testMotor] = -quarterPower;      // run motor at 25% power
	recordData();

	motor[testMotor] = -halfPower;         // run motor at 50% power
	recordData();

	motor[testMotor] = -threeFourthsPower; // run motor 75% power
	recordData();

	motor[testMotor] = -fullPower;         // give motor 100% power
	recordData();

}

//++++++++++++++++++++++++++++++++++++ END OF MOTOR TEST PROGRAM  ++++++++++++++++++++++++++++++++++
