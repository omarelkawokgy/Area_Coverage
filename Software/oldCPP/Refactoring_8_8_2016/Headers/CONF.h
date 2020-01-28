#ifndef CONF_H
#define CONF_H


#define MAP_ROW 20
#define MAP_COLUMN 20

/*This area includes all standard PIN numbers needed for the project
most probably it will be included in all modules
---------------------------------------------------- - */

/*status of the slots on the map*/
#define BUSY_SLOT 0xFF
#define VACUMMED_SLOT 0xF0
#define UNDEFINED_SLOT 0x00

/*pins of the sensors*/
#define FRONT_SENSOR_INTERRUPT_NUMBER 0
#define RIGHT_SENSOR_PIN 8
#define LEFT_SENSOR_PIN 7
#define ENCODER_INTERRUPT_NUMBER 1

/*pins of the motors*/
#define RIGHT_MOTOR_POSITIVE_PIN 6
#define RIGHT_MOTOR_GROUND_PIN 5

#define LEFT_MOTOR_POSITIVE_PIN 10
#define LEFT_MOTOR_GROUND_PIN 9

#define HIGH_PWM 127
#define LOW_PWM 0

/*standard distances for empty and busy*/
#define SIZE_OF_SLOT 20

/*-------------Map Conf------------*/
#define POINT_LIST_SIZE 20

#define INVALID_RESULT 0
#define X_ROBOT_GR_X_GOAL_Y_ROBOT_GR_Y_GOAL 1
#define X_ROBOT_LES_X_GOAL_Y_ROBOT_LES_Y_GOAL 2
#define X_ROBOT_LES_X_GOAL_Y_ROBOT_GR_Y_GOAL 3
#define X_ROBOT_GR_X_GOAL_Y_ROBOT_LES_Y_GOAL 4
#define X_ROBOT_EQ_X_GOAL_Y_ROBOT_GR_Y_GOAL 5
#define X_ROBOT_EQ_X_GOAL_Y_ROBOT_LES_Y_GOAL 6
#define X_ROBOT_GR_X_GOAL_Y_ROBOT_EQ_Y_GOAL 7
#define X_ROBOT_LES_X_GOAL_Y_ROBOT_EQ_Y_GOAL 8
#define X_ROBOT_EQ_X_GOAL_Y_ROBOT_EQ_Y_GOAL 9



#define INVALID_ANGLE_VALUE 0
#define ALLOWED_ANGLE_ERROR 5 


/*-----------Robot conf--------------*/
#define ROBOT_INIT_X		(MAP_ROW/2)
#define ROBOT_INIT_Y		(MAP_COLUMN/2)
#define ROBOT_INIT_THETA	0
#define ROBOT_WHEEL_SIZE 20//in cm
#define ROBOT_SIZE 20 //in cm
#define ROBOT_SINGLE_STEP 350


/*----------Scan conf-------------*/
#define SCAN_ANGLE 30
/*for circular scans only temp. closed*/
#define FULL_SCAN_NUM (360/(SCAN_ANGLE*2))
/*scan 3 times in each block*/
#define STEP_LINEAR_SCAN 1//((int)(ROBOT_SIZE/3))
#define SCAN_0_ANGLE 0
#define SCAN_30_ANGLE 1
#define SCAN_60_ANGLE 2
#define SCAN_90_ANGLE 3
#define SCAN_120_ANGLE 4
#define SCAN_150_ANGLE 5

/*Possible values*/
#define FAILURE_READING 0

#define LEFT_BUSY_RIGHT_EMPTY 1
#define LEFT_EMPTY_RIGHT_BUSY 2
#define LEFT_BUSY_RIGHT_BUSY 3

#define LEFT_CLEANED_RIGHT_EMPTY 4
#define LEFT_EMPTY_RIGHT_CLEANED 5
#define LEFT_CLEANED_RIGHT_CLEANED 6

#define LEFT_CLEANED_RIGHT_BUSY 7
#define LEFT_BUSY_RIGHT_CLEANED 8

#define LEFT_EMPTY_RIGHT_EMPTY 9


/*--------------------MACRO CONTROLS--------------------*/
#undef ENABLE_SIMULATION
#define DEBUG
#undef RECTANGLE
#undef USING_MAP_LIBRARY
#undef WORKING_WITH_ANGLES
#undef FINISHUP_EMPTY_SLOTS
#define SINGLE_ENCODER_ROBOT
#undef GO_TO_GOAL_STRAIGHTLINES
#undef ARDUINO_HARDWARE_CONNECTED
#undef UPDATE_POINT_POSITION
#undef ENCODER_ON_INTERRUPT

/*----------------return types-------------------------*/
#define RET_NOT_OK 0
#define RET_OK 1

/*----------------Hardware configuration--------------*/

#endif

/*INTERRUPT VARIABLES*/
/*Timer interrupts*/
#define MS_SCALE 1000
#define TIME_OF_TURN_SECONDS 10
