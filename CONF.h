#ifndef CONF_H
#define CONF_H

#include "types.h"

#define MAP_ROW 40
#define MAP_COLUMN 40

/*-------------Map Conf------------*/
#define POINT_LIST_SIZE 20
typedef float Required_Empty_Goal;

/*directions of the vacuum (heading)*/
typedef enum
{
NORTH = 1,
WEST,
SOUTH,
EAST,
INVALID_DIRECTION = 0
}Heading;

/*values of directions*/
#define NORTH_VALUE 102
#define WEST_VALUE 219
#define SOUTH_VALUE 281
#define EAST_VALUE 333
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
#define ROBOT_WHEEL_SIZE 5//in cm
#define ROBOT_SIZE 20 //in cm

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
#define LEFT_EMPTY_RIGHT_EMPTY 0

#define LEFT_BUSY_RIGHT_EMPTY 1
#define LEFT_EMPTY_RIGHT_BUSY 2
#define LEFT_BUSY_RIGHT_BUSY 3

#define LEFT_CLEANED_RIGHT_EMPTY 4
#define LEFT_EMPTY_RIGHT_CLEANED 5
#define LEFT_CLEANED_RIGHT_CLEANED 6

#define LEFT_CLEANED_RIGHT_BUSY 7
#define LEFT_BUSY_RIGHT_CLEANED 8

#define FAILURE_READING 9

typedef struct
{
	uint16 L_Distance;
	uint16 R_Distance;
}L_R_Dist;

/*--------------------MACRO CONTROLS--------------------*/
#define ENABLE_SIMULATION
#undef DEBUG
#undef RECTANGLE
#undef USING_MAP_LIBRARY

/*----------------return types-------------------------*/
#define RET_NOT_OK 0
#define RET_OK 1

#endif

