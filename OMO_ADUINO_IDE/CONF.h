#ifndef CONF_H
#define CONF_H

#include "types.h"

#define MAP_ROW 20
#define MAP_COLUMN 20

/*-------------Map Conf------------*/
#define POINT_LIST_SIZE 20
typedef float Required_Empty_Goal;
typedef uint8 Robot_to_Goal;

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

/*directions of the vacuum (heading)*/
typedef enum
{
NORTH = 1,
WEST,
SOUTH,
EAST,
INVALID_DIRECTION = 0
}Heading;

#define INVALID_ANGLE_VALUE 0
#define ALLOWED_ANGLE_ERROR 5 

typedef enum
{
	REQUEST_NONE = 0,
	REQUEST_NORTH = 2,
	REQUEST_EAST = 4,
	REQUEST_WEST = 6,
	REQUEST_SOUTH = 8
}enu_Direction_req;

/*Cell values*/
enum CELL_STATE
{
	UNCOVERED = 0,
	BUSY,
	CLEANED,
	EMPTY,
	ROBOT = 5
};

typedef enum 
{
	LEFT_SENSOR,
	RIGHT_SENSOR
}SensorID;


/*-----------Robot conf--------------*/
#define ROBOT_INIT_X		(MAP_ROW/2)
#define ROBOT_INIT_Y		(MAP_COLUMN/2)
#define ROBOT_INIT_THETA	0
#define ROBOT_WHEEL_SIZE 20//in cm
#define ROBOT_SIZE 20 //in cm
#define ROBOT_SINGLE_STEP 210


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

/*sensors view*/
typedef uint8 SensorsReadings;
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

typedef struct
{
	uint16 L_Distance;
	uint16 R_Distance;
}L_R_Dist;

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

/*Encoder*/
#define V_ENCODER_UINT8 volatile uint8
#define V_ENCODER_UINT16 volatile uint16

#endif

