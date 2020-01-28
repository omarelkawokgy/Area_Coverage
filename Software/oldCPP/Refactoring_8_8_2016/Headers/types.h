#ifndef TYPES_FILE
#define TYPES_FILE

/*---------Included files-----------*/
#include <Arduino.h>

/*---------------------TYPES--------------------------*/

#define TRUE 1
#define FALSE 0

#define UINT_SNA 0

/*------------Macro functions definition-------------*/
#define VAR(type, Name_of_Module) type
#define P2VAR(type, Name_of_Module) type*
#define CONSTVAR(type, Name_of_Module) const type
#define P2CONSTVAR(type, Name_of_Module) const type*
#define CONSTP2VAR(type, Name_of_Module) type* const

/*-----------------Type definitions------------------*/
typedef unsigned char uint8;
typedef uint8 Boolean;
typedef uint8 return_type;
typedef uint8 PointStatus;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned int uint32;
typedef signed int int32;
typedef unsigned long uint64;
typedef signed long int64;
typedef float fint32;

typedef struct
{
	uint8 X_Column;
	uint8 Y_Row;
}Coordinates;

typedef float Required_Empty_Goal;
typedef uint8 Robot_to_Goal;

/*Encoder*/
#define V_ENCODER_UINT8 volatile uint8
#define V_ENCODER_UINT16 volatile uint16

/*----------------OBJD TYPES----------------*/
typedef Coordinates PointPos;

typedef struct
{
	PointPos start;
	PointPos end;
}StraightLinePos;
#if 0
typedef struct
{
	Point L_Point;
	Point R_Point;
}L_R_Points;
#endif
/*-------------Robot types---------------*/
#if 0 
typedef struct
{
	uint8 Direction;
	uint16 Target;
}Heading;
#endif

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

/*directions of the vacuum (heading)*/
typedef enum
{
	NORTH = 1,
	WEST,
	SOUTH,
	EAST,
	INVALID_DIRECTION = 0
}Heading;

typedef struct
{
	uint16 L_Distance;
	uint16 R_Distance;
}L_R_Dist;

/*sensors view*/
typedef uint8 SensorsReadings;

typedef struct
{
	uint8 X_pos;
	uint8 Y_pos;
	uint16 theta;
}RobotPos;

#if 0
typedef struct
{
	fint32 X_Dist;
	fint32 Y_Dist;
}RectSize;
#endif

/*-----------------Global Variables------------------*/
//uint8 isrFrontSensorFlag;
#endif
